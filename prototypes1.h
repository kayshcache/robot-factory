#ifndef STRUCTS_H
#define STRUCTS_H

#include "structs.h"

#endif

int generate_random_variability(int repeat_attempts, int builder_variability, int robot_variability);

std::string process_order(std::string project_data);

void print_args(int argc, char **argv);
void process_files(char **argv);

bool check_format(int correct_num, char *data_line_to_check);

std::vector<std::string> destructure_data_from_file(char *file_name);

std::vector<Customer> make_orders(std::vector<std::string> &order_data, std::vector<Builder> builders);
std::vector<Part> make_parts(std::vector<std::string> &parts_data);
std::vector<Builder> make_builders(std::vector<std::string> &builder_data);

// void print_all_customers(std::vector<Customer> customers);
// void print_all_parts(std::vector<Part> parts);
void print_all_builders(std::vector<Builder> builders);
