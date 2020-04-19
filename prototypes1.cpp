#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <typeinfo> // typeid
#include <exception> // exception
#include <cerrno> // errno, perror
#include "structs.h"

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

/* * * *
 *
 * Data Handlers
 *
 * $ ./rorders Customers.txt Parts.txt Builders.txt
 *
 */

Customer create_customer_order(std::string customer_line)
{
	// Input: type-string that is 1 line = 1 customer order data
	// Output: type-Customer struct holding all the data
	int token_number = 3;
	const char *customer_name;
	const char *proj_name;
	const char *parts;

	Customer new_customer = {customer_name, proj_name, parts};
	
	return new_customer;
}

Part create_part(std::string part_line)
{
	// Input: type-string this is 1 line of data describing a part
	// Output: type-Part struct described 1 whole part
	int token_number = 5;
	char id;
	const char *part_name;
	int min_required;
	int max_possible;
	int complexity;

	Part new_part = {id, part_name, min_required, max_possible, complexity};

	return new_part;
}

// Move above later
bool check_format(int correct_num, char *data_line_to_check)
{
	// Check the number of data points is correct
	// Builders and customers have three, parts have five data points
	
	char data_in_check[100];
	strcpy (data_in_check, data_line_to_check);
	char *token = std::strtok(data_in_check, ":.");

	int token_acc = -1;

	while (token != 0) {
		token_acc++;
		token = std::strtok(NULL, ":.");
	}

	// Error and exit if any data point is incorrect
	return correct_num == token_acc ? true : false;
}

bool check_valid_builder(Builder &builder_to_check)
{
	bool is_valid_data;
	try {
		std::string name = builder_to_check.name;
		int abil = builder_to_check.ability;
		int vari = builder_to_check.variability;

		if (0 < abil < 100)
			throw std::exception();

		if (0 < vari < 10)
			throw std::exception();

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	builder_to_check.name;
	builder_to_check.ability;
	builder_to_check.variability;

	return is_valid_data;
}

Customer create_customer_order(std::string &customer_order_line)
{
}

Part create_part(std::string &part_line)
{
}

Builder create_builder(std::string &builder_line)
{
	Builder new_builder;
	char data_line[100];
	strcpy (data_line, builder_line.c_str());

	check_format(3, data_line);

	// Destructure into tokens and assign to struct
	char *token = std::strtok(data_line, ":.");
	new_builder.name = token;

	token = std::strtok(NULL, ":.");
	new_builder.ability = std::atoi(token);

	token = std::strtok(NULL, ":.");
	new_builder.variability = std::atoi(token);

	check_valid_builder(new_builder);

	return new_builder;
}

// FILE HANDLERS
std::ifstream open_file(char *file_name)
{
	std::ifstream input_file;
	input_file.open(file_name);

	// Check for error on open file
	if (!input_file) {
		std::cerr << "Error opening file - ";
		perror(file_name);
	}

	return input_file;
}

std::vector<std::string> destructure_data_from_file(char *file_name)
{
	std::ifstream file = open_file(file_name);
	std::string current_line;
	std::vector<std::string> file_data;

	while (file.good() && getline(file, current_line)) {
		if (file.fail()) {
			file.clear();
			file.ignore(100, '\n');
			break;
		}
		file_data.push_back(current_line);

	}

	file.close();
	return file_data;
}

std::vector<Builder> make_builders(std::vector<std::string> &builder_data)
{
	std::cout << "BUILDER DETAILS" << std::endl;
	std::vector<Builder> builders;
	for (auto data : builder_data) {
		builders.push_back(create_builder(data));
	}
	return builders;
}

void print_builder(Builder b)
{
	std::cout << "Name: " << b.name;
        std::cout << " - Ability: " << b.ability;
	std::cout << " - Variability: " << b.variability << std::endl;
}

void print_all_builders(std::vector<Builder> builders)
{	
	for (auto b : builders)
		print_builder(b);
}
// ********  IGNORE - MERELY NOTES
//
//
//
//
//      DEMONSTRATION OF decltype(f())
//	std::string x = "00000";
//	decltype(create_builder(x)) first_b = builders[1];
//	std::cout << first_b.name << std::endl;
	
