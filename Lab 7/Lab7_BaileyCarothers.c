#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Name: Bailey Carothers
Section: 502
Purpose of Program:
Execute a list of tasks required by Lab 7

Function main begins program execution
*/

void print_memory();
void sum_of_matrices();
void palindrome_checker();

int main(void) 
{
	printf("Here is the output from the first function:\n");
	print_memory();
	printf("Here is the output from the second function:\n");
	sum_of_matrices();
	printf("Here is the output from the third function:\n");
	palindrome_checker();

	return 0;
}

void print_memory()
{
	//Initialize variables and pointers
	double d, *x = &d;
	int i, *y = &i;
	char c, *z = &c;

	//Assign values
	d = 6.9;
	i = 69;
	c = 'X';

	// print address, value, and memory of each variable and pointer 
	printf("The value of double d is %.2f, the address is located at %p, and the memory allocated is %p.\n", d, &d, sizeof(d));
	printf("The value of pointer *x is %p, the address is located at %p, and the memory allocated is %p.\n", x, x, sizeof(x));
	printf("The value of int i is %d, the address is located at %p, and the memory allocated is %p.\n", i, &i, sizeof(i));
	printf("The value of pointer *y is %p, the address is located at %p, and the memory allocated is %p.\n", y, y, sizeof(y));
	printf("The value of char c is %c, the address is located at %p, and the memory allocated is %p.\n", c, &c, sizeof(c));
	printf("The value of pointer *z is %p, the address is located at %p, and the memory allocated is %p.\n", z, z, sizeof(z));
}

void sum_of_matrices()
{
// initialize variables
	int rows,columns;

// prompt and collect user input to initialize matrices 
	printf("Enter the number of rows and columns: \n");
	scanf("%d %d", &rows, &columns);
	int matrix1[rows][columns],matrix2[rows][columns],matrixSum[rows][columns];
	printf("Enter the first matrix (one number at a time):\n");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				scanf("%d",(*(matrix1+i)+j));
			}
		}

	printf("\nEnter the second matrix (one number at a time):\n");
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			scanf("%d",(*(matrix2+i)+j));
		}
	}

// add matrices 
printf("\nAddition Matrix:\n");
	for(int i=0;i<rows;i++)
	{ 
		for(int j=0;j<columns;j++)
		{
			*(*(matrixSum+i)+j)=*(*(matrix1+i)+j)+ *(*(matrix2+i)+j);
		printf("%d ",*(*(matrixSum+i)+j));	
		}
	printf("\n");
}	
}

void palindrome_checker()
{
	//Have to declare the array for the sentence before entering it
	char sentence[100], ch;
	int i = 0;
	char buffer; //Added this in later to troubleshoot

	// collect user input
	printf("Enter a message: \n");
	scanf("%c",&buffer);
	//Was having issues with scanf reading leftover input from last function
	scanf("%[^\n]", &sentence);
	printf("You entered:  %s.\n", sentence);

	//Ends when user hits enter
	while(ch != '\n') 
	{

	// reading ints one by one using getchar
		ch = getchar();

	//checking the if charater is only albhabets
		if(isalpha(ch))
		{
			sentence[i] = tolower(ch);
			// use an int to keep track of the array value
			i++;  
		}
  	}

  	//Add a null character
	sentence[i] = '\0'; 
	int isPalindrome = 1; //Initialize isPalindrome to 1
	int k=i; //initialize int k to whatever the last loop set i to

	//Time to check if it is a palindrome
	for(int j=0;j<k;j++)
	{
   //We check by comparing the first and last char
   //and slowly work our way to the middle of the sentence
		if(sentence[++j] != sentence[--k])
   		{
			//If we find a letter that prevents palindrome
   			//Set isPalindrome to 0 and exit loop
       		isPalindrome = 0;
       		break;
       	}
       	else
       	{
       		isPalindrome = 1;
       	}
   	}
//print results
if(isPalindrome==1)
	printf("This is a palindrome.\n");
else
    printf("This is not a palindrome.\n");
}