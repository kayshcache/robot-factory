#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>

#include "prototypes1.h"

int get_random_in_range(int min, int max)
{
	return 0;
}

void process_order(Customer order)
{
	std::string cust = order.customer_name;
	std::string proj = order.project_name;
	std::string prts = order.robot_parts;
	std::string bldr = order.assigned_builder.name;
	int complexity = order.robot_complexity;
	int variability = order.robot_variability;

	std::cout << "Customer Name: " << cust << " - ";
	std::cout << "Project: " << proj << " - ";
	std::cout << "Parts: " << prts << " - ";
	std::cout << "Complex: " << complexity << " - ";
	std::cout << "Variability: " << variability << " - ";
	std::cout << "Builder: " << bldr << "." << std::endl;
	
}

int main(int argc, char **argv)
{
	// - ./RAT Customers.txt Parts.txt Builders.txt Output-file
	// code:Part name:Minimum:Maximum:Complexity

	// print_args(argc, argv);

	// for (auto cod : customer_order_data)
	//	std::cout << cod << std::endl;
	// for (auto pd : parts_data)
	//	std::cout << pd << std::endl;

	/* GET RAW DATA FROM FILES */
	std::vector<std::string> customer_order_data = destructure_data_from_file(argv[1]);
	std::vector<std::string> parts_data = destructure_data_from_file(argv[2]);
	std::vector<std::string> builder_data = destructure_data_from_file(argv[3]);
	
	/* ORGANIZE DATA INTO VECTORS OF STRUCTS */
	std::vector<Builder> builders = make_builders(builder_data);
	std::vector<Customer> customer_orders = make_orders(customer_order_data, builders);
	std::vector<Part> parts = make_parts(parts_data);

	/* PROCESS ORDERS */
	for (Customer order : customer_orders) {
		process_order(order);
	}


	// print_all_builders(builders);

	
	//    3. Go to 2 or report error to stdout and abort
	// 2. stdout >> Print-out the contents of three input files
	
	// 3. Process customer order in the order given in the file
	//    for each customer_order
	//      - std::cout << customer name << order name << builder name << std::endl;
	//      - std::cout << build_attempt_status << std::endl; // success or fail
	//
	//      1. assign random builder
	//      2. calculate "robot_complexity" (if robot_complexity >= 100 { robot_complexity = 100 })
	//      3. calculate "robot_variability"
	//      4. attempt build (random_value = builder_variability and (standard deviation === robot_variability))
	//
	//      int attempts = 0;
	//
	//      while (attempts < 3) {
	//      // function to generation the variablity
	//           int build_variability = generate_random_variability(
	//              attempts,
	//              builder_variability,
	//              robot_variability
	//           );
	//
	//           if (build_variability >= robot_complexity) {
	//                   build_attempt_status = success;
	//                   break / return value;
	//           } else {
	//                   build_attempt_status = fail;
	//                   repeat_attempts ++;
	//                   continue;
	//           }
	//      }
	//      5. Save customer_order build report to temporary Out-file content 'struct'
	// 4. Print stdout << Output-file full report
	//
	// Input: Three arguments txt files
	// Output: Output-file contains order-details alphabetically by customer name
	//   - clear report of build plan
	//     1. Customer name
	//     2. Project name
	//     3. Builder name
	//     4. Distribution parameters (what are they???)
	//     5. Overall robot complexity
	//   - multiple attempt report
	//
	// Parts Calculation:
	// - all parts[ (part_qty * part_complexity), ... ] + (CONST_COMPLEXITY = 20)
	//
	// Variability Calculation:
	// - all_parts_qty + builder_variability + (CONST_VARIABILITY = 5)
	//
	// 

	return 0;
}
