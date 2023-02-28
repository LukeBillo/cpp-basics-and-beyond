#pragma once

#include <string>

struct TodoItem {
	std::string Name;
	int EstimatedHoursToComplete;

	TodoItem(std::string name, int estimatedHoursToComplete) {
		Name = name;
		EstimatedHoursToComplete = estimatedHoursToComplete;
	}
};