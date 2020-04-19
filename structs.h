struct Customer {
	// TODO:
	//   - Check format,
	//   - No more than 10 orders in one run
	// example: Carly:Ettin:ABCCCCE
	// format: (cstring)customer-name:(cstring)project-name:(cstring)robot-parts
	const char *customer_name;
	const char *project_name;
	const char *robot_parts;
};

struct Part {
	// No format checking required
	// example data: A:Head:1:2:15.
	// format: (char)identifier:(cstring)part-name:(int)min-required:(int)max-able:(int)part-complexity
	char id;
	const char *part_name;
	int min_required;
	int max_possible;
	int complexity;
};
struct Builder {
	// TODO:
	//   - No more than 5 builders in one run
	//   - Check format
	std::string name;
	int ability;
	int variability;
};

