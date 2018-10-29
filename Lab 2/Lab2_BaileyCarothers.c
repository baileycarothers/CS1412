#include <stdio.h>
#include <math.h>

/*
Name: Bailey Carothers
Section: 002
Purpose of Program:
Execute a list of tasks required by Lab 2

Function main begins program execution
*/

int main (void){
	//These integers are used throughout the program to get user input and make calculations
	int userInput1, userInput2, userInput3, sum, remainder;
	float radius, area, perimeter, pi = 3.14; //These floats are used to find the dimensions of a circle
	int age, experience, projects; //These ints are for determining if the user qualifies for the job
	char userChar; //User inputs character to find its ASCII value

	//Request two integers and add them together
	printf("Please enter two integers separated by a space: ");
	scanf("%d%d", &userInput1, &userInput2); //Read two ints from user
	sum = userInput2 + userInput1; //Add the two ints together
	printf("The sum of the two numbers you entered is %d\n", sum);

	//Find area and perimeter of a circle
	printf("Input the radius of a circle to calculate its area and perimeter: ");
	scanf("%f", &radius); //Reads radius from user
	area = pi * pow(radius, 2); //Calculate area
	perimeter = 2 * pi * radius; //Calculate perimeter
	printf("The radius is %0.1f, the area is %0.1f, and the perimeter is %0.1f.\n", radius, area, perimeter);

	//Output the ASCII value of any character entered
	printf("Enter any character to see the ASCII value: ");
	scanf(" %c", &userChar); //Scans in user character
	printf("The ASCII character for '%c' is %d\n", userChar, userChar); //Prints out ASCII value for user char

	//Find out whether a number is even or odd
	printf("Please input a number to find out if it is even or odd: ");
	scanf(" %d", &userInput3); //Reads in user int
	remainder = userInput3 % 2; //Divides user int by 2 to check for a remainder
	if(remainder == 1) //If there is a remainder of 1, the number is odd
		printf("The number %d is odd.\n", userInput3);
	else //If there is no remainder the number is even
		printf("The number %d is even.\n", userInput3);

	//Compare two numbers to find out which is greater
	printf("Please enter two numbers separated by a space to find out which is greater: ");
	scanf("%d%d", &userInput1, &userInput2); //Read in two user integers
	if(userInput1 > userInput2) //Compare the integers and output the result
		printf("The number %d is greater than %d\n", userInput1, userInput2);
	else
		printf("The number %d is greater than %d\n", userInput2, userInput1);

	//Find out if the user is qualified for the job
	printf("Please input your age: ");
	scanf("%d", &age); //Reads in user age as int
	printf("Please input how many years of experience you have: ");
	scanf("%d", &experience); //Reads in user experience as int
	printf("Please enter the number of projects you have worked on: ");
	scanf("%d", &projects); //Reads in user projects as int
	if((age >= 18) && (experience >= 3) && (projects >= 5)) //Checks if user meets all qualifications
		printf("You are qualified for the job!\n");
	else //If user does not meet qualifications
		printf("You are not qualified for this job.\n");

	return 0;
}
