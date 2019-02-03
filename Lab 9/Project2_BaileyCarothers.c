#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: Bailey Carothers
Section: 502
Purpose of Program:
Execute a list of tasks required by Lab 8, Project 2

ATM Menu

Function main begins program execution
*/

int main(void)
{
	//Time to declare some variables
	//MyAccount stores balance; deposit/withdrawalAmount are used in the switch statement
	float MyAccount = 1000.00, depositAmount, withdrawalAmount;
	//Store our password incase the user wants to update it
	int Password = 12345678;
	//Chars for use in the program
	char userInput, keyPress;


	//While loop to continue the program until the user exits
	while (userInput != '5')
	{
		//Print the menu
		printf("1) Check Balance\n");
		printf("2) Make a Deposit\n");
		printf("3) Make a Withdrawal\n");
		printf("4) Change Password\n");
		printf("5) Exit\n");
		printf("Please enter a number from 1 to 5 to select a menu item: ");

		//Use getchar to assign user input
		userInput = getchar();
		//Print users selection back to them
		printf("You entered ");
		putchar(userInput);
		printf("\n");

		//Switch statement based on user input
		//Originally forgot to encase with ' characters
		//Every case gets a break statement
		switch(userInput)
		{
			case '1' :
				printf("Execute check balance\n");
				printf("Balance is $%.2f\n", MyAccount);
				printf("Press any key to continue...\n");
				getchar();
				getchar();
				break;
			case '2' :
				printf("Execute make a deposit\n");
				printf("Enter an amount to deposit: ");
				scanf("%f", &depositAmount);
				MyAccount = MyAccount + depositAmount;
				printf("New Balance is $%.2f\n", MyAccount);
				printf("Press any key to continue...\n");
				getchar();
				getchar();
				break;
			case '3' :
				printf("Execute make a withdawal.\n");
				printf("Enter an amount to withdraw: ");
				scanf("%f", &withdrawalAmount);
				MyAccount = MyAccount - withdrawalAmount;
				printf("New balance is $%.2f\n", MyAccount);
				printf("Press any key to continue...\n");
				getchar();
				getchar();
				break;
			case '4' :
				printf("Execute change password.\n");
				printf("Enter new password: ");
				scanf("%d", &Password);
				printf("New password is %d\n", Password);
				printf("Press any key to continue...\n");
				getchar();
				getchar();
				break;
			case '5' :
				printf("Successfully logged out of your account.\n");
				printf("Have a nice day!\n");
				break;
			default  :
				printf("Invalid key entered, try again.\n");
				break;
		}
	}
	return 0;
}