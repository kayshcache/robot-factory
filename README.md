# Learning C++ Project 1
## Robot Factory
### Overview
This project is implemented using procedural programming. The overall program follows the processing of customer orders for robots from a robot construction company : RAT (Robots As Toys).
## General code notes
Your app is organised into:
1. A driver file containing your main() function.
2. A header file containing the prototypes for the functions you write.
3. An implementation file containing the implementations of your functions.
No classes or function templates are used. It does not leak memory.
The main() function makes it clear what is going on. Other than the initial command line input, the program runs without user output.
## Run structure
Once compiled into the executable RAT, it runs as follows:
```bash
$ ./RAT Customers.txt Parts.txt Builders.txt Output-file
```
The expected structure of the input data files is given in the next section.
When RAT reads from the data files it reports on the data read in. We see a list of customers, a list of parts, and a list of builders; all showing the correctly partitioned input data. This report goes to standard out, not to Output-file. Output-file is used to report on results.

The customer orders in the customers file are processed in the order they are given.

The file Output-file is ordered by customer and contains a clear report on the build plan, success or otherwise in the multiple attempts, as necessary.

When each customer is started it reports to standard out the customer name, the name of the order they are intending to build, and the builder assigned. It also reports to standard out when a build succeeds or fails. The process below explains how multiple builds may be attempted, and those are reported on.

The process involved in managing a customer order is as follows:
* A given customer is randomly allocated a builder who is constructing the robot.
* The overall robot complexity is determined as 20 plus the sum of the part complexities. For example:
```raw
Sally:Snake:AEEEEEE.
Overall robot complexity = 20+15 + 6 * 2 = 47
```
If the complexity is greater than 100, it is changed to exactly 100.

- The overall robot variability is determined as 5 plus the number of parts plus the variability of the builder. For example
```raw
Sally:Snake:AEEEEEE.
Reliable Rover:70:1.
Overall robot variability = 5 + 7 + 1 = 13.
```
The customer name, project name, builder name, and the distribution parameters are reported to the Output-file. The overall robot complexity is reported too.
- The builder attempts to build the robot. Generate a random value from a normal distribution with mean equal to the builder’s ability and standard deviation equal to the overall robot variability just calculated.
  - If the random value is greater than or equal to the overall robot complexity, the build is successful.
  - If the random value is less than the overall robot complexity, the build fails.
- If the build succeeds it moves on to the next customer.
- If the build fails, the builder will re-attempt the build twice. For each re-attempt, a random value is generated from the same distribution as before, but for the first re-attempt 5 is added and for the second re-attempt 10 added.
- After three fails in total it moves to the next customer regardless of the result.
- The random value and success status for each attempt is reported to the Output-file.
## Inputs
Three data files are needed for each run of the program. The general syntax of those files is described here.

The three data files are as follows, with the colons used to separate fields and the full stop to end the line.

1. `Customers.txt:` No more than 10 entries.
`Customer name:Project name:List of parts.`
Example:
```txt
Carly:Cat:ABCCCCE.
Dodgy Dan:Dog:BCACECC.
Ernie:Ettin:AABCCDD.
Sally:Snake:AEEEEEE.
```
The Customer name is the name of the entity that submitted the order. It is a non-empty string of printable characters that may include spaces.

The Project name is chosen by the customer and is supposed to represent the type of robot to be built. Like the Customer name it is a non-empty string of printable characters that may include spaces.

The List of parts contains a list of letters with each letter corresponding to a part in the parts file. They do not need to be in alphabetical order. There shouldn’t be more than 10 parts for any order.

2. `Parts.txt:` This file corresponds to a publicly available catalogue for RAT so the content will be as provided here. The input validity is not verified but it does check if the file is present.
```txt
Part code:Part name:Minimum:Maximum:Complexity.
A:Head:1:2:15.
B:Torso:0:6:5.
C:Leg:0:4:6.
D:Arm:0:4:8.
E:Tail:0:6:2.
```
The part code is a single capital letter. The minimum and maximum are limits on the number of that part type that is in proposed build. The complexity is used to determine how difficult a build will be depending on the parts added.

3. `Builders.txt:` No more than 5 entries
```txt
Name:Ability:Variability.
Example:
Reliable Rover:70:1.
Sloppy Simon:20:4.
Technical Tom:90:3.
```
Enjoy.
