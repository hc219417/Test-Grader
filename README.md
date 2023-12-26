# Test-Grader
**Objective:** use strings, files, and command line arguments

You are asked to grade a multiple-choice test for a class. The students’ answers are stored in a file. Each student record in the file includes a student name and the test answers given by the student. A blank space indicates that the student did not answer the question. For example, the following line represents a student’s record.

`George Bush cCDdaab ccaADdc`

In the above sample input, George Bush did not answer question 8. The test answer key is entered in the first line of the input file (`ACDBCBDCCACDACC`).

Write a C++ program that determines the scores and letter grade of students’ multiple-choice tests. The number of test questions must be determined by reading the answer key string at the beginning of the input file. You may assume that there are no more than 100 students. Generate the report shown in the sample output and store it in an output file.

**Output the following:**

- A grade report for each student exactly as it appears in the sample output below. Replace a missing answer with a '-'.
- The test average and letter grade.
- **(Extra Credit)**: The names and averages of all the students with the highest grades. No hints will be given for the extra credit.

Your program must use command line arguments (see below) to get the input and the output file names. Exit the program with an error message if any of the files fail to open or the user enters the wrong number of arguments. The program can be run using the following command:

`./a.out tests.txt output.txt`

If your file name contains spaces surround the file name with double quotes as in:

`./a.out "input file name.txt" "output file name.txt"`

The following should produce an error and exit the program:

`./a.out tests.txt`

`./a.out tests.txt output.txt output2.txt`

`./a.out`

**Required Functions:**

- Write a function that grades a single student score and returns the score.
- Write a function that returns a letter grade for a score.
- Write a function that outputs a single student’s report to the screen.

**Parsing command line arguments**

In C++ you can input data (strings) into your program on the command line (command line arguments). You can capture these data by adding two parameters to your main program as follows:

`int main (int argc, char *argv[])`

`argc` (argument count): stores the number of arguments on the line, including the name of the program

`argv` (argument vector): is an array that stores all the strings entered at the command line including the program name

For example, executing the command:

`./a.out quiz1.txt "output file.txt"`

Assigns:

`argc = 3`

`argv[0] will be assigned the string "./a.out"`

`argv[1] will be assigned the string "quiz1.txt"`

`argv[2] will be assigned the string "output file.txt"`
