#ifndef STRUCTS_H
#define STRUCTS_H

#include "structs.h"

#endif

int generate_random_variability(int repeat_attempts, int builder_variability, int robot_variability);

std::string process_order(std::string project_data);

void print_args(int argc, char **argv);

bool check_format(int correct_num, char *data_line_to_check);

std::vector<std::string> destructure_data_from_file(char *file_name);

std::vector<Customer> customer_orders = make_orders(order_data);
std::vector<Part> parts = make_parts(parts_data);
std::vector<Builder> make_builders(std::vector<std::string> &builder_data);

void print_all_builders(std::vector<Builder> builders);
