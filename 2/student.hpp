#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

#define MAX_STUDENTS 10

typedef struct student 
{
	string regno;
	int courseid;
	string firstname;
	string surname;
	string address;
	char **unitsRegistered;
	int *unitsMarks;
}student_t;

student_t *getData(void);
char **getUnitsRegistered(int n);
void printStudent(student_t *std);
int *getMarks(int n);
void deleteStudent(student_t *std);
float computeMean(student_t *std);
char computeGrade(float marks);
float classMean(student_t *std[]);
float standardDeviation(student_t *std[]);
float computeD(student_t *std, float mean);
float lowestMarks(student_t *std[]);
float highestMarks(student_t *std[]);


#endif

