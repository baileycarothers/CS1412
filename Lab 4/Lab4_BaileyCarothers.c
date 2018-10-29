#include <stdio.h>
#include <math.h>

/*
Name: Bailey Carothers
Section: 002
Purpose of Program:
Execute a list of tasks required by Lab 4

Function main begins program execution
*/

int main()
{
	int userRows, x, numDays, startingDay, totalDays, fibNum, num1 = 0, num2 = 1, sum, numTemp;

	//Print a triangle of 5 rows, 1st row has 1 star, 2nd row has 2 etc...
	for(int i = 1; i < 6; i++) //For loop that prints 5 rows
	{
		for(int j = 0; j < i; j++) //For loop that prints number of stars equal to the row number
			printf("*");
		printf("\n"); //Newline for next row of pyramid
	}

	//Ask user for number of rows, then print a pyramid
	printf("Please enter the number of rows for your pyramid: ");
	scanf("%d", &userRows);
	x = userRows; //int to subtract from while we count down rows printed

	for (int row = 1; row <= userRows; row++)
	{
		for (int i = 1; i < x; i++) //Print spaces inverse to number of rows left to print
			printf(" ");
		x--; //Subtract number of rows left to print

		for (int j = 0; j < row; j++) //Print stars equal to row number
			printf("* ");

		printf("\n"); //Start a newline for the next row
	}

	//Print a calendar for the user
	printf("Enter the number of days in month: ");
	scanf("%d", &numDays);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &startingDay);

	if(numDays > 0) //Make sure the user entered a valid number of days
	{
		printf("Sun\tMon\tTues\tWed\tThurs\tFri\tSat\n");
		for(int i = 1; i < startingDay; i++) //For loop to start calendar on correct day
		{
			printf("\t"); //Print a tab for every space before the first day
			numTemp = i; //Store number of tabs we added for math later
		}
		for(int j = 1; j <= numDays; j++) //J will store the number of the day we are on
		{
			totalDays = j + numTemp - 1; //Calculate the total number of tabs and days we have printed
			if(totalDays % 7 == 0) //If total days is divisible by 7, start a new line
				printf("\n");
			printf("%d\t", j); //Print the day
		}
	}
	else
		printf("Please enter a valid number of days."); //Default condition if user enters 0 or invalid number
	printf("\n");

	//Print a Fibonacci series
	printf("How many numbers would you like to have in the Fibonacci series? ");
	scanf("%d", &fibNum);

	printf("0 1 ");
	for(int i = 2; i < fibNum; i++) //We already printed the first 2 numers so i = 2
	{
		sum = num1 + num2; //Calculate the next number
		printf("%d ", sum); //Print the new number
		num1 = num2; //Set up numbers for next calculation if loop iterates again
		num2 = sum;
	}

	return 0;
}