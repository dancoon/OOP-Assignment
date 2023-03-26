#include "student.hpp"

student_t *getData(void)
{
	int n;
	char f[255], s[255], a[255];
	student_t *std = new student_t;

	cout << "Enter student's regNo: ";
	cin >> std->regno;
	cout << "Enter course id: ";
	cin >> std->courseid;
	cout << "Enter student's firstname:";
	cin >> std->firstname;
	cout << "Enter student's surname: ";
	cin >> std->surname;
	cout << "Enter student's email address: ";
	cin >> std->address;
	cout << "Enter number of units registered: ";
	cin >> n;
	std->unitsRegistered = getUnitsRegistered(n);
	std->unitsMarks = getMarks(n);

	return (std);
}

char **getUnitsRegistered(int n)
{
	int i;
	char u[255];
	char **unit = new char*[++n];
	
	for (i = 0; i < n - 1; i++)
	{
		cout << "Enter unit " << i + 1 << ": ";
		cin >>u;
		unit[i] = strdup(u);
	}
	unit[n - 1] = NULL;
	return (unit);
}

int *getMarks(int n)
{
	int i;
	int *marks = new int[++n];

	for (i = 0; i < n - 1; i++)
	{
		cout << "Enter marks for unit " << i + 1 << " : ";
		cin >> marks[i];
	}
	marks[n - 1] = -1;
	return (marks);
}

void printStudent(student_t *std)
{
	int i = 0;
	float marks;

	cout << "| Student's RegNo is: " << std->regno << endl;
	cout << "| Student's fullname is: " << std->firstname << " " << std->surname << endl;
	cout << "| Student's address is: " << std->address << endl;
	cout << "| Students units:" << endl;

	while (std->unitsRegistered[i])
	{
		cout << "|\tUnit " << i + 1 << " " << std->unitsRegistered[i] << endl;
		i++;
	}

	i = 0;
	
	while (std->unitsRegistered[i])
	{
		cout << "| Marks for unit " << std->unitsRegistered[i] << " is: " << std->unitsMarks[i] << endl;
		i++;
	}
	marks = computeMean(std);
	cout << "| Average marks: " << marks << endl;
	cout << "| Grade is: " << computeGrade(marks) << endl; 
	cout << "|" << endl;
}

void deleteStudent(student_t *std)
{
	int i;
	
	delete[] std->unitsMarks;

	i = 0;    
	while (std->unitsRegistered[i])
	{
		free(std->unitsRegistered[i]);
		i++;
	}

	delete[] std->unitsRegistered;
	delete std;
}

float computeMean(student_t *std)
{
	int sum, i;
	
	sum = 0;
	i = 0;
	while (std->unitsMarks[i] != -1)
	{
		sum += std->unitsMarks[i];
		i++;
	}
	return (sum / i);
}

char computeGrade(float marks)
{
	if (marks >= 70)
		return 'A';
	else if (marks >= 60)
		return 'B';
	else if (marks >= 50)
		return 'C';
	else if (marks >= 40)
		return 'D';
	else
		return 'F';
}

float classMean(student_t *std[])
{
	int i;
	float sum = 0;

	for (i = 0; i < MAX_STUDENTS; i++)
	{
		sum += computeMean(std[i]);
	}
	return (sum / MAX_STUDENTS);
}

float standardDeviation(student_t *std[])
{
	int i;
	float mean, sumD = 0, sd, root, dev;

	mean = classMean(std);
	for (i = 0; i < MAX_STUDENTS; i++)
	{
		dev = computeD(std[i], mean);
		sumD += dev;
	}
	root = sumD / MAX_STUDENTS;
	sd = sqrt(root);

	return (sd);
}

float highestMarks(student_t *std[])
{
	int i;
	float mark, max = computeMean(std[0]);

	for (i = 1; i < MAX_STUDENTS; i++)
	{
		mark = computeMean(std[i]);
		if (mark > max)
			max = mark;
	}
	return max;
}

float lowestMarks(student_t *std[])
{
	int i;
	float mark, min = computeMean(std[0]);
	
	for (i = 1; i < MAX_STUDENTS; i++)
	{
		mark = computeMean(std[i]);
		if (mark < min)
			min = mark;
	}
	return min;
}

float computeD(student_t *std, float mean)
{
	float x, d, avg;
	
	avg = computeMean(std);
	x = avg - mean;
	d = pow(x, 2);
	return (d);
}
