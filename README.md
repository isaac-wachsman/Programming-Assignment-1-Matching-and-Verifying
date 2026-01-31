# Programming Assignment 1 - Verifying and Matching

**Isaac Wachsman (UFID: 28099694)**

**Aarav Bejjinki (UFID: 40331589)** 

## Project Structure Overview

- **src/main.cpp**: main driver - options for parsing text  file input or randomly generated preference lists.
- **src/matcher.cpp**: uses the Gale-Shapley algorithm to generate a stable matching for the preference lists provided.
- **src/verifier.cpp**: verifies that a proposed solution is both a valid matching and stable.
- **src/parser.cpp**: parses text files to obtain preference lists for verifier and matcher.
- **src/random_input.cpp**: generates random preference lists for a given n (# of hospitals).
  
- **tests/inputN.txt**: the Nth input file
- **tests/outputN.txt**: the Nth output file

- **data/running_time_matching.png** : Graph of input size vs running time for matching.
- **data/running_time_verifying.png** : Graph of input size vs running time for verifying.


## Compilation and Execution Instructions (Matcher)

1. Navigate to a folder of your choice on your terminal and run `git clone https://github.com/isaac-wachsman/Programming-Assignment-1-Matching-and-Verifying.git` to clone the repository to the folder.

2. Run `cd src` to navigate to the src directory.

3. Run `g++ -o main main.cpp matcher.cpp parser.cpp random_input.cpp` to compile the matching program.

4. Run `./main` to run the main program with random preference lists. You will be prompted to provide a positive integer n, after which the program will generate random preference lists of length n.

5. Run `./main ../tests/inputN.txt` where N = 1, 2, or 3 to run Gale-Shapley algorithm on preference lists stored in text files. `../tests/inputN.txt` may be replaced with the path (relative to src) to any valid input text file.

## Compilation and Execution Instruction (Verifier)

1. Complete steps 1 and 2 from the previous section if not done already.
2. Run `g++ -o verify verifier.cpp parser.cpp` to compile the verifier.
3. Run `./verify ../tests/inputN.txt` where N = 1, 2, or 3 to get the preference lists stored in text files. `../tests/inputN.txt` may be replaced with the path (relative to src) to any valid input text file.
4. The program will prompt you to enter n positive integers via the command line. The ith (1-index) integer you provide is the hospital number that student i is matched with in your proposed matching.

## Input / Output

If random preference list mode is being used for the matcher, the only thing the user needs to provide is a valid positive integer.

If preference lists are coming from a text file for both matcher and verifier, the input is expected to be in the form:

```
3
1 2 3
2 3 1
2 1 3
2 1 3
1 2 3
1 2 3
```
The first line contains a single positive integer, n. The following 2*n lines each contain a permutation of the integers 1 through n with a single space between each one.

**NOTE:** Input files that do not match this specified format will result in undefined behavior.


The matcher output is printed in the terminal in the form:
```
4 1
2 2
3 3
1 4
```
with the line ``i j`` meaning that hospital i is matched with student j. The number of lines is equal to the number of hospitals/students used.

For the verifier, the terminal output is VALID STABLE if the matching is valid and stable. The verifier will print INVALID if the proposed matching is invalid or UNSTABLE if the matching is valid but unstable. An error message will be provided explaining why the matching is invalid or unstable.


![Matcher Graph](data/running_time_matching.png)

![Verifier Graph](data/running_time_verifying.png)
