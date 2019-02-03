#include <stdio.h>
#include <string.h>

/*
Name: Bailey Carothers
Section: 502
Purpose of Program:
Execute a list of tasks required by Lab 10

Function main begins program execution
*/

//Defining a struct for Program 1
struct Faculty
{
	int rollNum;
	char firstName[15];
	char lastName[15];
	char department[15];
	char address[50];
	long long int phoneNum;
} Faculty1;
//At the end we initialize Faculty1 for use in Program 1

//Defining a struct for Program 2
struct student
{
	char name[20];
	int rollNum;
	float grade1, grade2, grade3;
} best;
//At the end we initialize best for use in Program 2

//Defining a struct for Program 3
struct complex
{
	float real;
	float imag;
} num1, num2, sum;
//At the end we initialize num1, num2, and sum for use in Program 3

//Initializing functions for use in main
void program1();
void program2();
void program3();

//Main function just calls each individual program for ease of troubleshooting
int main(void)
{
	printf("Here is the output for Program 1:\n");
	program1();

	printf("Here is the output for the Program 2:\n");
	program2();

	printf("Here is the output for Program 3:\n");
	program3();

	return 0;
}

void program1()
{
	//Prompt the user to input information
	printf("Please enter the following information for the staff member.\n");
	printf("Roll Number: ");
	scanf("%d", &Faculty1.rollNum);
	//Empty getchar to flush out the leftover \0 character from user entry
	getchar();

	//Prompt for first/last name and department
	//Use gets to assign the string entered to the correct part of the struct
	printf("First Name: ");
	gets(Faculty1.firstName);

	printf("Last Name: ");
	gets(Faculty1.lastName);

	printf("Department: ");
	gets(Faculty1.department);

	//Back to scanf to enter in the long long int phone number
	printf("Contact Number: ");
	scanf("%d", &Faculty1.phoneNum);

	//Time to print it back out to the user
	//Use printf for numbers and puts for strings
	printf("******************************\n");
	printf("Roll Number: %d\n", Faculty1.rollNum);
	printf("First Name: ");
	puts(Faculty1.firstName);
	printf("Last Name: ");
	puts(Faculty1.lastName);
	printf("Department: ");
	puts(Faculty1.department);
	printf("Contact Number: %d\n", Faculty1.phoneNum);

	return;
}

void program2()
{
	//Initialize all variables needed in the program
	int numStudents, grade1Roll, grade2Roll, grade3Roll;
	float gradeSum, grade1High = 0, grade2High = 0, grade3High = 0, highestSum;
	char grade1Student[20], grade2Student[20], grade3Student[20], highestStudent[20];

	//Prompt user for number of students to be entered
	printf("Enter how many students: ");
	scanf("%d", &numStudents);

	//getchar to flush newline char from previous line
	getchar();

	//Declare an array of structs of the type 'student'
	struct student studentArr[numStudents];

	for(int i=0; i < numStudents; i++)
	{
		//Initialize tempSum inside the for loop
		//This way it is reset to 0 every loop iteration
		int tempSum = 0;

		//Prompt user for info to populate struct inside of array
		//Use gets for strings and scanf for numbers
		printf("Enter name of student: ");
		gets(studentArr[i].name);
		printf("Enter roll number of student: ");
		scanf("%d", &studentArr[i].rollNum);
		printf("Enter student's grade for test 1: ");
		scanf("%f", &studentArr[i].grade1);
		printf("Enter student's grade for test 2: ");
		scanf("%f", &studentArr[i].grade2);
		printf("Enter student's grade for test 3: ");
		scanf("%f", &studentArr[i].grade3);
		getchar();

		//If loops to compare the data we just entered with the highest grade
		//That has been entered so far
		//If its true then it overwrites the previous data
		//Use strcpy to copy the student name from the struct array into the char array
		if(studentArr[i].grade1 > grade1High)
		{
			grade1Roll = studentArr[i].rollNum;
			grade1High = studentArr[i].grade1;
			strcpy(grade1Student, studentArr[i].name);
		}
		if(studentArr[i].grade2 > grade2High)
		{
			grade2Roll = studentArr[i].rollNum;
			grade2High = studentArr[i].grade2;
			strcpy(grade2Student, studentArr[i].name);
		}
		if(studentArr[i].grade3 > grade3High)
		{
			grade3Roll = studentArr[i].rollNum;
			grade3High = studentArr[i].grade3;
			strcpy(grade3Student, studentArr[i].name);
		}

		//Add the students grade together into a temp variable
		tempSum = studentArr[i].grade1 + studentArr[i].grade2 + studentArr[i].grade3;

		//Compare our temp value to the highest grade recorded
		//Overwrite if higher
		if(tempSum > highestSum)
		{
			highestSum = tempSum;
			strcpy(highestStudent, studentArr[i].name);
		}
	}

	//Iterate through the struct array and output each students name, roll #, and total grade
	for(int i=0; i < numStudents; i++)
	{
		gradeSum = studentArr[i].grade1 + studentArr[i].grade2 + studentArr[i].grade3;
		printf("Total grade obtained by student %s is %.1f.\n", studentArr[i].name, gradeSum);
	}

	//Output the name and roll # of the student that got the highest grade on each test
	printf("Student %s (Roll #%d) got the highest grade on test 1 with a %.1f\n", grade1Student, grade1Roll, grade1High);
	printf("Student %s (Roll #%d) got the highest grade on test 2 with a %.1f\n", grade2Student, grade2Roll, grade2High);
	printf("Student %s (Roll #%d) got the highest grade on test 3 with a %.1f\n", grade3Student, grade3Roll, grade3High);

	//Output the name of the student who got the highest grade
	//And what that grade is
	printf("Student %s got the total highest grade with %.1f\n", highestStudent, highestSum);

	return;
}

void program3()
{
	//Prompt user to enter numbers
	printf("For 1st complex number\n");
	printf("Enter real and imaginary part respectively:");

	//Read floats entered into struct num1
	scanf("%f %f", &num1.real, &num1.imag);

	printf("For 2nd complex number\n");
	printf("Enter real and imaginary part respectively:");
	//Read floats entered into struct num2
	scanf("%f %f", &num2.real, &num2.imag);

	//Populate our struct sum with data from num1 and num2
	sum.real = num1.real + num2.real;
	sum.imag = num1.imag + num2.imag;

	//Print the sum of num1 and num2 back to the user
	//by using our struct sum
	printf("Sum = %.2f + %.2fi", sum.real, sum.imag);

	return;
}