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
#include <random>
#include <functional>
#include "structs.h"

int gen_rand_int_range(int min, int max)
{
	static std::default_random_engine random_generator;
	static std::uniform_int_distribution<int> uniform(min, max);
	return uniform(random_generator);
}

int gen_norm(int mean, int stddev)
{
	std::default_random_engine random_generator;
	std::normal_distribution<double> normal(mean, stddev);
	return lround(normal(random_generator));
}

/* CHECKERS
 *
 *
 *
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
*/


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

bool check_valid_robot(int heads, int torsos, int legs, int arms, int tails)
{
	if ((heads + torsos + legs + arms + tails) > 10)
		return false;
	if (heads < 1 || heads > 2)
		return false;
	if (torsos > 6)
		return false;
	if (legs > 4)
		return false;
	if (arms > 4)
		return false;
	if (tails > 6)
		return false;
	return true;
}

/* * * * 
 * Calculate attributes
 *
 * */
int calculate_robot_complexity(std::string robot_parts)
{
	int complexity = 20;
	int heads = 0;
	int torsos = 0;
	int legs = 0;
	int robot_arms = 0;
	int tails = 0;

	for (char part_code : robot_parts) {
		switch (part_code) {
		case 'A': // Head:1:2:15
			heads++;
			complexity += 15;
			break;
		case 'B': // Torso:0:6:5
			torsos++;
			complexity += 5;
			break;
		case 'C': // Leg:0:4:6
			legs++;
			complexity += 6;
			break;
		case 'D': // Arm:0:4:8
			robot_arms++;
			complexity += 8;
			break;
		case 'E': // Tail:0:6:2
			tails++;
			complexity += 2;
			break;
		default:
			std::cerr << "No part like that!" << std::endl;
		}
	}

	bool is_valid_robot = check_valid_robot(heads, torsos, legs, robot_arms, tails);

	return complexity > 100 ? 100 : complexity;
}

/* * * *
 * Data Handlers
 *
 */
Customer create_customer_order(std::string customer_order_line, Builder builder)
{
	Customer new_order;
	new_order.assigned_builder = builder;

	// Line of tokenize by delimiters ':' and '.'
	char data_line[100];
	strcpy (data_line, customer_order_line.c_str());
	// check_format
	char *token = std::strtok(data_line, ":.");
	new_order.customer_name = token;
	token = std::strtok(NULL, ":.");
	new_order.project_name = token;
	token = std::strtok(NULL, ":.");
	new_order.robot_parts = token;

	new_order.robot_complexity = calculate_robot_complexity(new_order.robot_parts);
	new_order.robot_variability = 5 + new_order.robot_parts.length() + builder.variability; // = stddev

	// int build_likelihood = gen_norm(builder.ability, new_order.robot_variability);
	// std::cout << "Build likelihood: " << build_likelihood << std::endl;

	// bool build_status;
	// if (build_likelihood >= new_order.robot_complexity)
	//	build_status = 1;

	return new_order;
}

Part create_part(std::string &part_line)
{
	Part new_part;
	char data_line[100];
	strcpy (data_line, part_line.c_str());
	// check_format(type, data_line);
	char *token = std::strtok(data_line, ":.");
	new_part.id = *token;
	token = std::strtok(NULL, ":.");
	new_part.part_name = token;
	token = std::strtok(NULL, ":.");
	new_part.min_required = std::atoi(token);
	token = std::strtok(NULL, ":.");
	new_part.max_possible = std::atoi(token);
	token = std::strtok(NULL, ":.");
	new_part.complexity = std::atoi(token);
	return new_part;
}

Builder create_builder(std::string &builder_line)
{
	Builder new_builder;
	char data_line[100];
	strcpy (data_line, builder_line.c_str());
	// check_format(3, data_line);
	char *token = std::strtok(data_line, ":."); // Destructure into tokens and assign to struct
	new_builder.name = token;
	token = std::strtok(NULL, ":.");
	new_builder.ability = std::atoi(token);
	token = std::strtok(NULL, ":.");
	new_builder.variability = std::atoi(token);
	// check_valid_builder(new_builder);
	return new_builder;
}

/* * * *
 * Create Vectors for the 3 types and fills them
 * input: vector<string>
 * output: vector<Builder || Customer || Part>
 * 
 * */
std::vector<Builder> make_builders(std::vector<std::string> &builder_data)
{
	// std::cout << "BUILDER DETAILS" << std::endl;
	std::vector<Builder> builders;
	for (auto data : builder_data) {
		builders.push_back(create_builder(data));
	}
	return builders;
}

std::vector<Customer> make_orders(std::vector<std::string> &order_data, std::vector<Builder> builders)
{
	// std::cout << "CUSTOMER ORDERS" << std::endl;
	std::vector<Customer> orders;
	for (auto data : order_data) {
		int rbi = gen_rand_int_range(0, builders.size());
		// std::cout << "Random index assigning builder: " << rbi << std::endl;
		orders.push_back(create_customer_order(data, builders[rbi]));
	}
	return orders;
}

std::vector<Part> make_parts(std::vector<std::string> &parts_data)
{
	// std::cout << "PARTS READY" << std::endl;
	std::vector<Part> parts;
	for (auto data : parts_data) {
		parts.push_back(create_part(data));
	}
	return parts;
}

/* * * *
 * PRINTERS 
 *
 */
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

void print_args(int argc, char **argv)
{
	std::cout << argc << " Args given" << std::endl;
	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << std::endl;
}

/* * * *
 * FILE HANDLERS 
 *
 * */

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

