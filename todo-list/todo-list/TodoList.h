#pragma once

#include <iostream>
#include <vector>

#include "TodoItem.h"

class TodoList
{
public:
	TodoList();
	~TodoList() {}

	void Print();
	void Add(TodoItem item);
	void WriteToFile(std::string filePath);
	void ReadFromFile(std::string filePath);

	const std::vector<TodoItem>& GetItems() const;

private:
	std::vector<TodoItem> _items;
};

