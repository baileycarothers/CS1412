#include <stdio.h>
#include <string.h>

/*
Name: Bailey Carothers
Section: 002
Purpose of Program:
Execute a list of tasks required by Lab 5

Function main begins program execution
*/

int main()
{
	int arraySize, tempNum, mathArray[5], targetSum; //Ints for use throughout the program
	char tempChar, sentence[50]; //Array to hold sentence

	//Program 1: Sort an array in ascending order
	printf("Please enter the number of elements in the array: ");
	scanf("%d", &arraySize);
	int userArray[arraySize]; //Create an array the size specified by the user
	printf("Please enter %d numbers for your array: ", arraySize);
	for(int i = 0; i < arraySize; i++)
		scanf("%d", &userArray[i]); //Scan the correct number of digits into the array

	for(int j=0; j < arraySize; j++) //For loop for the first element to be compared
	{
		for(int k=0; k < arraySize; k++) //For loop for the second element to be compared
		{
			if(userArray[j] < userArray[k]) //Compare two elements
			{
				tempNum = userArray[j]; //Swap numbers around if needed
				userArray[j] = userArray[k];
				userArray[k] = tempNum;
			}
		}
	}

	printf("The numbers in ascending order are: "); //Print the reordered array back out to the user
	for(int i=0; i < arraySize; i++)
		printf("%d ", userArray[i]);


	//Program 2: Find numbers in array that add up to target sum
	printf("\nPlease enter 5 numbers for your array: "); //Prompt user for 5 numbers to populate the array
	for(int i=0;i<5;i++)
		scanf("%d", &mathArray[i]);
	printf("\nPlease enter the target sum: "); //Ask user for target sum to check for
	scanf("%d", &targetSum);

	for(int i=0;i<5;i++) //For loop for the first element to be compared
	{
		for(int j=i+1;j<5;j++) //For loop for the second element to be compared
		{
			if(mathArray[i] + mathArray[j] == targetSum) //Add two elements and compare them to the target sum
				printf("The target index is a[%d]=%d and b[%d]=%d\n", i, mathArray[i], j, mathArray[j]); //Print if it matches
		}
	}


	//Program 3: Reverse the words in a sentence, leave punctuation at the end
	/*
	printf("\nPlease enter a sentence to be reversed: "); //Enter sentence into char array
	scanf("%s", &sentence);

	int length = strlen(sentence);

	for(int i=length -1; i >=0; i--)
	{
		if (sentence[i] == ' ')
		{
			sentence[i] = '\0';

			printf("%s ", &(sentence[i]) + 1);
		}
	}

	printf("%s", sentence);
	*/

	//Attempting to print the array only prints the first word back
	//printf("%s", sentence);

	/* This code causes a core dump
	char test[] = "hello there";
	for(int i=0;i<2;i++)
		printf("%s", test[i]);
	*/

	/*
	Program needs to read characters until it comes to a space
	Store words into second array backwards
	Print second array
	*/

	return 0;
}
