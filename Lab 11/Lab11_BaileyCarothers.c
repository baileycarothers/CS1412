#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Name: Bailey Carothers
Section: 502
Purpose of Program:
Execute a list of tasks required by Lab 11

Function main begins program execution
*/

//Defining a struct for the file
struct student
{
	char firstName[20], lastName[20];
	int studentID;
};

int main(void)
{
	//Int for declaring an array of students
	int numStudents;

	//Declaring a file pointer to open our file with
	FILE *fileptr;

	//Opens data.txt or creates it if it doesnt exist
	fileptr = fopen("data.txt", "w");

	//Prompt user for number of students
	printf("How many students will you enter into the file? ");
	scanf("%d", &numStudents);

	//Declare an array to parse through
	struct student studentArr[numStudents];

	//For loop to populate our file
	for(int i=0; i < numStudents; i++)
	{
		printf("Enter the Student ID for student #%d ", i+1);
		scanf("%d", &studentArr[i].studentID);
		//Empty getchar to flush the newline character
		getchar();
		//Write user input to file
		fprintf(fileptr, "%d\r\n", studentArr[i].studentID);

		printf("Enter the student's first name: ");
		gets(studentArr[i].firstName);
		//Write user input to file
		fprintf(fileptr, "%s\r\n", studentArr[i].firstName);

		printf("Enter the students last name: ");
		gets(studentArr[i].lastName);
		//Write user input to file
		fprintf(fileptr, "%s\r\n", studentArr[i].lastName);
	}

	//We have to close and reopen the file to get back
	//To the first line of it for counting
	fclose(fileptr);
	fileptr = fopen("data.txt", "r");

	//Declare ints and initialize to 0 for counting
	int lines = 0, words = 0, characters = 0;
	char c;

	//While loop that iterates through file
	//And adds to the total count while it goes
	while((c = fgetc(fileptr)) != EOF)
	{
		characters++;

		if (c == '\n' || c == '\0')
			lines++;

		if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
			words++;
	}

	//Print file statistics back to the user
	printf("The file has %d lines, %d words, and %d characters", lines, words, characters);

	//Always close the file when done
	fclose(fileptr);

	return 0;
}
