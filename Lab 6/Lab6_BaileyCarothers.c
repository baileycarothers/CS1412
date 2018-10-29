#include <stdio.h>

/*
Name: Bailey Carothers
Section: 002
Purpose of Program:
Execute a list of tasks required by Lab 6

Function main begins program execution
*/


//Time to declare some functions
void swap(int *a, int *b);
void selection_sort(int userNumbers[], int maxIndex);
int factorial(int num);

int main(void)
{
	int a,b,numElements,n,sum = 0; //Declaring ints for use in the program

	//Program 1
	//Prompt the user for two variables to be swapped
	printf("Please enter two numbers to be swapped: ");
	scanf("%d%d", &a,&b);
	printf("The two numbers you entered are a = %d and b = %d\n", a,b);
	swap(&a,&b); //Pass the variables through our function
	printf("After swapping the variable values we have a = %d and b = %d\n", a,b);

	//Call by value does not modify the integer within the main function 
	//only within the function that is called
	//Call by reference updates the variables within the main function
	//From the function that was called
	//Technically C does not support call by reference
	//only call by pointer

	//Program 2
	printf("Please enter the number of integers you would like sorted: ");
	scanf("%d", &numElements); //Scan in a size for the array
	int userNumbers[numElements]; //Declare our array

	printf("Please enter the numbers for the array: "); //Populate the array
	for(int i=0;i<numElements;i++)
		scanf("%d", &userNumbers[i]);

	printf("You entered the following array: "); //Print the array back to the user
	for(int i=0;i<numElements;i++)
		printf("%d ", userNumbers[i]);
	printf("\n"); //Newline for cleanliness

	selection_sort(userNumbers, numElements); //Pass the array through our function

	printf("After sorting the array we have: "); //Print the sorted array back to the user
	for(int i=0;i<numElements;i++)
		printf("%d ", userNumbers[i]);
	printf("\n");


	//Program 3
	//Write a function to find the factorial of a number
	//and divide the factorial by the number
	printf("Please enter the number to find the sum of its series: ");
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		int temp = (factorial(i)/i);
		sum += temp;
	}
	printf("The sum is %d", sum);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void selection_sort(int userNumbers[], int maxIndex)
{
	int n, temp, maxNum = 0, maxNumIndex, numberFound = 0;
	n = maxIndex;

	
	for(int i=0;i<n;i++)
	{
		if(userNumbers[i] > maxNum)
		{
			maxNumIndex = i;
			maxNum = userNumbers[i];
			numberFound = 1;
		}
	}
	if(numberFound == 1)
	{
		temp = userNumbers[n];
		userNumbers[n] = maxNum;
		userNumbers[maxNumIndex] = temp;
	}	
	


	/*
	for(int i=0;i<=n;i++)
	{
		if(userNumbers[i] > userNumbers[n])
		{
			temp = userNumbers[i];
			userNumbers[i] = userNumbers[n];
			userNumbers[n] = temp;
			//swap(&userNumbers[i], &userNumbers[n]);
		}
	}
	*/
	n = n - 1;
	if (n == 0)
		return;
	else
		return selection_sort(userNumbers, n);	
}

int factorial(int num)
{
	if(num<1)
		return 1;
	else
		return num * factorial(num -1);
}