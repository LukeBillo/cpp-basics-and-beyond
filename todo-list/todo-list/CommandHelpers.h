#pragma once

#include <vector>
#include <sstream>

const int AddCommandParts = 3;
const int WriteCommandParts = 2;
const int ReadCommandParts = 2;

const std::string PrintCommand = "print";
const std::string AddCommand = "add";
const std::string WriteCommand = "write";
const std::string ReadCommand = "read";

std::vector<std::string> SplitByWhitespace(std::string command)
{
	std::stringstream stream(command);
	std::string split;
	char whitespace = ' ';

	std::vector<std::string> splitStrings = std::vector<std::string>();

	while (std::getline(stream, split, whitespace)) {
		splitStrings.push_back(split);
	}

	return splitStrings;
}

bool DoesCommandStartWith(std::string command, std::string expectedStart) {
	std::string startOfCommand = command.substr(0, expectedStart.length());
	return startOfCommand == expectedStart;
}

bool IsKnownCommand(std::string command) {
	return
		DoesCommandStartWith(command, PrintCommand) ||
		DoesCommandStartWith(command, AddCommand) ||
		DoesCommandStartWith(command, WriteCommand) ||
		DoesCommandStartWith(command, ReadCommand);
}

bool IsValidPrintCommand(std::string command) {
	return command == PrintCommand;
}

bool IsValidAddCommand(std::string command) {
	if (!DoesCommandStartWith(command, AddCommand)) {
		return false;
	}

	std::vector<std::string> splitCommandPieces = SplitByWhitespace(command);
	return splitCommandPieces.size() == AddCommandParts;
}

bool IsValidWriteCommand(std::string command) {
	if (!DoesCommandStartWith(command, WriteCommand)) {
		return false;
	}

	std::vector<std::string> splitCommandPieces = SplitByWhitespace(command);
	return splitCommandPieces.size() == WriteCommandParts;
}

bool IsValidReadCommand(std::string command) {
	if (!DoesCommandStartWith(command, WriteCommand)) {
		return false;
	}

	std::vector<std::string> splitCommandPieces = SplitByWhitespace(command);
	return splitCommandPieces.size() == ReadCommandParts;
}