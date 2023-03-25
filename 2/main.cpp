#include "student.hpp"

int main(void)
{
	int i;
	student_t *students[MAX_STUDENTS];

	for (i = 0; i < MAX_STUDENTS; i++)
	{
		students[i] = NULL;
	}
	
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		cout << "Student " << i + 1 << endl;
		students[i] = getData();
	}

	for (i = 0; i < MAX_STUDENTS; i++)
	{
		cout << "|---------------------------------------|" << endl;
		cout << "|\t\tStudent " << i + 1 << "\t\t|" << endl;
		cout << "|---------------------------------------|" << endl;
		printStudent(students[i]);
	}
	
	cout << "The class mean is: " << classMean(students) << endl;
	cout << "The standard deviation is: " << standardDeviation(students) << endl;
	cout << "The lowest mark is: " << lowestMarks(students) << endl;
	cout << "The highest mark is: " << highestMarks(students) << endl;
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		deleteStudent(students[i]);
	}
	return (0);
}

