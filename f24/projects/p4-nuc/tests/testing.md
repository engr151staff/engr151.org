# Testing Plan

## Part 1 (30 Points)
Test that student file `radionuc.hpp` produces the same output when run by `testRadionuc.cpp`. Correct output is given in `testRadionucOutput.txt`.

```bash
# Compile program
g++ -Wall -Werror testRadionuc.cpp -o testRadionuc.exe
# Run program and store output
./testRadionuc.exe > student_output_part1.txt
# Check correctness
diff testRadionucOutput.txt student_output_part1.txt 
```

## Part 2 (10 Points)
```bash
# Compile
g++ -Wall -Werror testHeaders.cpp -o testheaders.exe
# Run, expected output is nothing
./testheaders.exe
```
## Part 3 (60 Points)
```bash
# Compile
g++ -Wall -Werror tcGenerator.cpp -o tcgen.exe
```
### Input Validation Testing (20 Points)
#### Check too many arguments (5 Points)
```bash
./tcgen 1 2 3
# Expect "Incorrect number of command line arguments."
```
#### Check too few arguments (5 Points)
```bash
./tcgen 1
# Expect "Incorrect number of command line arguments."
```
#### Check invalid population size (5 Points)
```bash
./tcgen 999 100
# Expect "Invalid initial Mo-99 population."
```
#### Check invalid simulation length (5 Points)
```bash
./tcgen 1000000 501
# Expect "Invalid simulation length."
```
### Simulation Testing (40 Points)
#### Case 1 (10 Points)
Initial population: 10000

Simulation Length (hrs): 50

Correct Outputs: output_tcgen_1e4_50.txt

```bash
./tcgen.exe 10000 50 > student_output_part3_1e4_50.txt
diff student_output_part3_1e4_50.txt output_tcgen_1e4_50.txt
```
#### Case 2 (10 Points)
Initial population: 1000000

Simulation Length (hrs): 50

Correct Outputs: output_tcgen_1e6_50.txt
```bash
./tcgen.exe 1000000 50 > student_output_part3_1e6_50.txt
diff student_output_part3_1e6_50.txt output_tcgen_1e6_50.txt
```
#### Case 3 (10 Points)
Initial population: 1000000

Simulation Length (hrs): 75

Correct Outputs: output_tcgen_1e6_75.txt
```bash
./tcgen.exe 1000000 75 > student_output_part3_1e6_75.txt
diff student_output_part3_1e6_75.txt output_tcgen_1e6_75.txt
```
#### Case 4 (10 Points)
Initial population: 1000000

Simulation Length (hrs): 100

Correct Outputs: output_tcgen_1e6_100.txt
```bash
./tcgen.exe 1000000 100 > student_output_part3_1e6_100.txt
diff student_output_part3_1e6_100.txt output_tcgen_1e6_100.txt