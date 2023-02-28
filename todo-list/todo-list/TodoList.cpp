#pragma once

#include "TodoList.h"

TodoList::TodoList()
{
	this->_items = std::vector<TodoItem>();
}

void TodoList::Print()
{
	if (this->_items.empty()) {
		std::cout << "The to-do list is empty" << std::endl;
		return;
	}

	for (int i = 0; i < this->_items.size(); i++) {
		TodoItem item = this->_items[i];
		
		std::cout << "----" << std::endl;
		std::cout << "Index: " << i << std::endl;
		std::cout << "Name: " << item.Name << std::endl;
		std::cout << "Estimated time: " << item.EstimatedHoursToComplete << " hours" << std::endl;
	}
}

void TodoList::Add(TodoItem item)
{
	this->_items.push_back(item);
}

void TodoList::WriteToFile(std::string filePath)
{
}

void TodoList::ReadFromFile(std::string filePath)
{
}

const std::vector<TodoItem>& TodoList::GetItems() const
{
	return this->_items;
}
