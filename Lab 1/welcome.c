#include <stdio.h>

/*
Name: Bailey Carothers
Section: 002
Purpose of Program:
This program is a demo program to understand the basics of how to create a c file, edit it, save it, compile it, and execute it

Function main begins program execution
*/

int main(void)
{
	int ID = 4518;
	float shipweight = 25.625f;

	//Display the string
	printf("Welcome to C\n");

	//Display contents of variables
	printf("The ID of the item is %d\n", ID);
	printf("The shipping weight of the item is %.03f\n", shipweight);

	//We have to return
	return 0;

} //End main function