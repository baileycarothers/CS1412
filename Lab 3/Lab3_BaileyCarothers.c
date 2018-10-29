#include <stdio.h>
#include <math.h>

/*
Name: Bailey Carothers
Section: 002
Purpose of Program:
Execute a list of tasks required by Lab 3

Function main begins program execution
*/

int main (void){
	int userNum1, userNum2, userNum3, userNum4, userNum5, userGrade, count; //Declare our ints for the program

	//Find the number of digits in a given number
	printf("Please input a number of up to 4 digits: ");
	scanf("%d", &userNum1);

	while(userNum1 != 0) //Check if userNum is = 0
	{
		userNum1 = userNum1 / 10; //Divide the number by 10
		++count; //Keep count of digits
	}
	printf("Number of digits is: %d\n", count); //Print digits to user


	//Find the largest of four numbers entered by the user
	printf("Please enter four numbers separated by spaces: ");
	scanf("%d%d%d%d", &userNum2, &userNum3, &userNum4, &userNum5);
	//Compare each number to the first number
	//If number is larger it replaces the first number
	//At the end we will print out the first number which will have been replaced by any larger numbers
	if (userNum3 > userNum2)
		userNum2 = userNum3;
	if (userNum4 > userNum2)
		userNum2 = userNum4;
	if (userNum5 > userNum2)
		userNum2 = userNum5;
	printf("The largest of the numbers you entered is %d\n", userNum2); //Tell the user the result

	//Give the user their letter grade using a switch statement
	printf("Please enter a number to find out the corresponding letter grade: ");
	scanf("%d", &userGrade);

	switch (userGrade/10) { //Divide it by 10 to find the case number
		case 10:
		case 9: printf("You made an A!\n");
			break;
		case 8: printf("You made a B!\n");
			break;
		case 7: printf("You only made a C.\n");
			break;
		case 6: printf("You made a D.\n");
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0: printf("You received an F.\n");
			break;
		default: printf("Invalid grade entered.\n"); //If number is too high or negative print an error
			break;
	}

	return 0;
}