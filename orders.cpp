#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "orders.h"
// Below is for header file before they're moved:

int main(int argc, char **argv)
{
	// 1. Get cli args - three files
	// - ./RAT Customers.txt Parts.txt Builders.txt Output-file
	// code:Part name:Minimum:Maximum:Complexity
	//
/*	
	std::cout << argc << " Args given" << std::endl;
	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << std::endl;
*/

	print_args(argc, argv);

	char *customers_orders_filename = argv[1];

        destructure_data_from_file(customers_orders_filename);

	return 0;


	//    1. Check files were imported without error
	//    2. Check file content means format requirements
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
}
