struct Builder {
	// TODO:
	//   - No more than 5 builders in one run
	//   - Check format
	std::string name;
	int ability;
	int variability;
};

struct Customer {
	// TODO:
	//   - Check format,
	//   - No more than 10 orders in one run
	// example: Carly:Ettin:ABCCCCE
	std::string customer_name;
	std::string project_name;
	std::string robot_parts;
	Builder assigned_builder;
	int robot_complexity;
	int robot_variability;
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
