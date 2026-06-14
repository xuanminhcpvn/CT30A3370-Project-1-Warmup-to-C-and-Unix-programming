# CT30A3370-Project-1-Warmup-to-C-and-Unix-programming
## Introduction
This project implement a simple program called reverse that either read file contents or user input in reverse order using doubly linked list structure to read from the tail to the head of the list.
## Point proposal
-Everything submitted compiles and works at least on some level. (Required, 1 points)

-The documentation is appropriate, correct and the repository is available (Required, 0 point)

-The documentation is detailed, and the provided source code is reasonably well commented. (1 point)

-all additional assumptions (1 point) and errors mentioned are addressed (2 points)

**TOTAL:= 5**
## Installation instruction
```bash
Requirement
   * Best run on Linux only, not sure how will this be working in WSL or MacOS.
   * Unit tests also best run on Linux/WSL (MacOS does not work so well with CUnit)
 ```

```bash
## Preinstallation:
(For CUnit tests): sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev 
(For valgrind + gcc compiler): sudo apt-get update && sudo apt-get install build-essential valgrind 
## To run program:
git clone https://github.com/xuanminhcpvn/CT30A3370-Project-1-Warmup-to-C-and-Unix-programming
* If runtime environment is Windows, do this in repository where WSL is remotely connected
make
* Different ways to run (First option will require to follow additional command prompts):
./reverse 
./reverse input.txt
./reverse input.txt output.txt
```
## ERRORS and ASSUMPTIONS
* For ./reverse input.txt output.txt input can't be same
* The length of a input line can be very long and would not break the program
* Same with file length
* File access errors are handled
* Malloc fails are addressed for every malloc() even for getline() that also use malloc() internally
* The program prevents from inputting too many arguments (more than 3 including the executable file
* Error messages matches the required format
### Usage of input and output text files

> **NOTE!** To prevent any issue, text files (for instance `*.txt`) have to be on the **main level** (same level where for instance `Makefile` is).

### Useful Make command

```bash)
make clean         # Remove miscellaneous, executable and debug files (in this project they are mostly all .txt files)
make valgrind      # Perform memory leaks check

## To compile tests
make test_reverse
./test_reverse
```
# Project folder structure
* ./src contains all source code and header files
* ./tests contains all CUnit-tests (we only have 1 Test Suite/Group so no further instruction)
```
├──Makefile
├──README.md
├──src
|    ├── main.c
|    ├── reverse.c
|    ├── reverse.h
├──tests
|    ├──test_reverse.c
```
#
