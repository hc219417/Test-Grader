/**
 *   @file: test-grader.cc
 * @author: Hannah Culver
 *   @date: October 17, 2021
 *  @brief: homework 5 (objectives: use strings, files, and command line arguments)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

/**
 * studentScore - grades a single student's test
 * @param answers student answers
 * @param test_key test answers
 * @return the student's score
 */
double studentScore (string answers, string test_key);

/**
 * letterGrade - letter grade for a score
 * @param score the student's score
 * @return the corresponding letter grade
 */
char letterGrade (double score);

/**
 * studentReport - outputs a single student's report to the screen
 * @param none
 * @return the student's report
 */
void studentReport(const char *argv[]);

int main(int argc, const char *argv[]) {

    if (argc != 3) //check for argument count, must equal 3 (./a.exe, input text file, and output text file)
	{
		cout << "Error: invalid command line argument" << endl;
		exit(0);
	}
	else
	{
		studentReport(argv); //send argument vector (whatever was entered at the command line) to studentReport function
	}

	return 0;
}/// main

double studentScore(string answers, string test_key)
{
	int total_questions = test_key.length(); //number of questions on the test
	double correct_count = 0;
	for (int i = 0; i < total_questions; i++)
	{
		if (answers[i] == test_key[i]) //compare the elements in each array one at a time
		{
			correct_count++; //up the count if there is a match (correct answer)
		}
	}
	double score = (correct_count / total_questions) * 100;
	return score;
}

char letterGrade(double score)
{
	char grade;
	if (score <= 100 && score >= 90)
	{
		grade = 'A';
	}
	else if (score < 90 && score >= 80)
	{
		grade = 'B';
	}
	else if (score < 80 && score >= 70)
	{
		grade = 'C';
	}
	else if (score < 70 && score >= 60)
	{
		grade = 'D';
	}
	else if (score < 60 && score >= 0)
	{
		grade = 'F';
	}
	return grade;
}

void studentReport(const char *argv[])
{
    ifstream inStream;
	inStream.open(argv[1]); //open argv[1] (tests.txt)
	if (inStream.fail())
	{
		cout << "Error: file not found" << endl;
		exit(0);
	}

    string test_key;
    getline(inStream,test_key);
    int number_of_questions = test_key.length();
   
    for (int i = 0; i < number_of_questions; i++)
    {
        test_key[i] = tolower(test_key[i]); //convert everything to lowercase (personal preference - easier on the eyes)
    }

	ofstream outStream;
	outStream.open(argv[2]); //open argv[2] (output.txt)
	if (outStream.fail())
	{
		cout << "Error: failed to create file" << endl;
		exit(0);
	}
	
	string first_name;
	string last_name;
	string answers;

	int student_count = 0;
	double total_score = 0;
	
	inStream >> first_name >> last_name; //read the first and last name
    inStream.ignore(); //ignore the following space

	while (getline(inStream,answers)) //getline up to answers
	{
		outStream << last_name << ", " << first_name << endl;
		outStream << "-----------------------------------------------------" << endl;
		outStream << "Answers, correct answers in parenthesis" << endl;
		outStream << endl;

		for (int i = 0; i < number_of_questions; i++)
		{
			if (answers[i] == ' ') //if there is a space
			{
				answers[i] = '-'; //replace it with a dash
			}
			answers[i] = tolower(answers[i]); //again, convert to lowercase
		}

        for (int i = 0; i < number_of_questions; i++)
        {
            outStream << setw(2) << i + 1 << ": " << answers[i] << "(" << test_key[i] << ") ";
            if ((i + 1) % 5 == 0)
            {
                outStream << endl; //start a new line every 5 questions
            }
        }

		outStream << endl;
		outStream << "Score: " << fixed << setprecision(1) << studentScore(answers,test_key) << " " << letterGrade(studentScore(answers,test_key)) << endl;
		outStream << "-----------------------------------------------------" << endl;
		outStream << endl;

		student_count++; //up the count each time a single student report is finished
		total_score += studentScore(answers,test_key); //add the score of each student to the total score

		inStream >> first_name >> last_name; //read the next first and last name
    	inStream.ignore(); //ignore the following space
	}

	double class_average = total_score / student_count;
	outStream << "-----------------------------------------------------" << endl;
	outStream << "Class average: " << fixed << setprecision(1) << class_average << " " << letterGrade(class_average) << endl;
	outStream << "-----------------------------------------------------" << endl;
	
	inStream.close();
	outStream.close();
}