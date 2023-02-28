#include <iostream>
#include <vector>

#include "TodoList.h"
#include "CommandHelpers.h"

void DisplayHelp() {
	std::cout << "Commands: " << std::endl;
	std::cout << "print - displays all to-do list items" << std::endl;
	std::cout << "add <name> <hours-to-complete> - adds a to-do list item" << std::endl;
	std::cout << "write <path> - writes the to-do list to the given path" << std::endl;
	std::cout << "read <path> - reads the to-do list from the given path, discarding the current to-do list" << std::endl;

}

void DisplayWelcome() {
	std::cout << "Welcome to the To-Do List application." << std::endl;

	DisplayHelp();
}

int main()
{
	bool isRunning = true;
	TodoList todoList = TodoList();

	DisplayWelcome();

	while (isRunning) {
		std::string command = "";
		std::getline(std::cin, command);

		if (!IsKnownCommand(command)) {
			std::cout << "That wasn't a recognized command. Please try again." << std::endl;
			continue;
		}

		if (IsValidPrintCommand(command)) {
			todoList.Print();
			continue;
		}

		if (IsValidAddCommand(command)) {
			std::vector<std::string> commandParts = SplitByWhitespace(command);

			std::string name = commandParts[1];
			int timeInHours = std::stoi(commandParts[2]);

			todoList.Add(TodoItem(name, timeInHours));
			continue;
		}

		if (IsValidWriteCommand(command)) {
			std::vector<std::string> commandParts = SplitByWhitespace(command);
			std::string filePath = commandParts[1];

			todoList.WriteToFile(filePath);
			continue;
		}

		if (IsValidReadCommand(command)) {
			std::vector<std::string> commandParts = SplitByWhitespace(command);
			std::string filePath = commandParts[1];

			todoList.ReadFromFile(filePath);
			continue;
		}

		std::cout << "Looks like your syntax isn't quite right. Check command usage below, and try again." << std::endl;
		DisplayHelp();
	}
}