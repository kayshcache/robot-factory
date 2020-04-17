#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

int exit_with_error()
{
	return -1;
}

// Helper functions for finding a random_variability number for the build
int generate_random_variability(int repeat_attempts, int builder_variability, int robot_variability)
{
	int random_variability;

	random_variability = 45; // stubbed data

        // multiply repeat_attempts by 5
	if (repeat_attempts)
		return random_variability + repeat_attempts*5;

	return random_variability;
}

// Better to receive a struct or other complex datastructure TODO
std::string process_order(std::string project_data)
{
	std::cout << project_data << std::endl;
	return project_data;
}

void print_args(int argc, char **argv)
{
	std::cout << argc << " Args given" << std::endl;
	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << std::endl;
}

// FILE HANDLERS
std::ifstream open_file(char *file_name)
{
	std::ifstream input_file;
	input_file.open(file_name);

	// Check for error on open file
	if (!input_file) {
		std::cerr << "Error opening : " << file_name << std::endl;
		exit_with_error();
	}
	int input;
	return input_file;
}

struct Builder {
	char *name;
	int ability;
	int variability;
};

Builder create_builder(std::string &builder_line)
{
	int len = builder_line.length()-1;
	char data[len];
	strncpy (data, builder_line.c_str(), len);

	char *detail = std::strtok(data, ":.");
	while (detail != 0) {
		std::cout << detail << std::endl;
		detail = std::strtok(NULL, ":.");
	}
	char name[] = "cccccc";
	int ability;
	int variability;
	Builder builder1 = {name, ability, variability};

	// std::cout << builder1.name << std::endl;
	return builder1;
}

void destructure_data_from_file(char *file_name)
{
	std::ifstream file = open_file(file_name);
	std::string current_line;

	while (file.good() && getline(file, current_line)) {
		if (file.fail()) {
			file.clear();
			file.ignore(100, '\n');
			break;
		}
		create_builder(current_line);
	}
}
