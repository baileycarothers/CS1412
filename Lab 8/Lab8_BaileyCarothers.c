/*
Name: Bailey Carothers
Section: 502
Purpose of Program:
Execute a list of tasks required by Lab 7

Function main begins program execution
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letter_types();
void word_sizes();
void word_sort();

int main(void)
{
	printf("Here is the output from our first function:\n");
	letter_types();
	printf("Here is the output from our second function:\n");
	word_sizes();
	printf("Here is the output from our third function:\n");
	word_sort();
}

void letter_types()
{
	char string[100];
	int numConsonants = 0, numVowels = 0, i = 0;
	printf("Enter a word: ");
	gets(string);

	char *y = string;
	while(*y != '\0')
	{
		if(*y == 'a' || *y == 'e' || *y == 'i' || *y == 'o' || *y == 'u' || *y == 'A' || *y == 'E' || *y == 'I' || *y == 'O' || *y == 'U')  
		{
  			numVowels++;  	
 		}
  		else
    		numConsonants++;
    	y++;
	}



	printf("There are %d consonants and %d vowels in the word '%s'.\n", numConsonants, numVowels, string);
}

void word_sizes()
{
	//Initialize variables at the beginning
	int i = 0, j = 0, k = 0, a, minIndex = 0, maxIndex = 0, max = 0, min = 0;
    char userSentence[100] = {0}, string[100][100] = {0}, c;

    //Ask user to input sentence and store it
    printf("Enter a sentence: ");
    gets(userSentence);

    //Use a while loop to split the sentence 
    while(userSentence[k] != '\0')
    {
        //Set j = 0 so it is always 0 when loop begins
        j = 0;

        //Find spaces and null characters
        while(userSentence[k] != ' '&&userSentence[k] != '\0')
        {
            string[i][j] = userSentence[k];
            k++;
            j++;
        }

        string[i][j] = '\0';
        i++;
        if(userSentence[k] != '\0')
        {
            k++;
        }
    }

    //More variables
    int len = i;
    max = strlen(string[0]);
    min = strlen(string[0]);

    // after splitting the string, get the length of the string and find the index with max length and index with min length
    for(i = 0; i < len; i++)
    {
       a = strlen(string[i]);
       if(a>max)
        {
            max = a;
            maxIndex = i;
        }
        if(a<min)
        {
            min = a;
            minIndex = i;
        }
    }   

  //Display results  
  printf("The largest word is '%s'.\n",string[maxIndex]);
  printf("The smallest word is '%s'.\n", string[minIndex]);
 
}

void word_sort()
{
	// initialize variables 
	char userNames[20][5], tname[10][8], temp[10];
    int i, j, n = 5;

	printf("Enter 5 names: ");
 		//Use for loop to enter and another one to sort names 
        for (i = 0; i < n; i++) 
        {
            scanf("%s", userNames[i]);
            strcpy(tname[i], userNames[i]);
        }
 
        for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(userNames[i], userNames[j]) > 0) 
                {
                    strcpy(temp, userNames[i]);
                    strcpy(userNames[i], userNames[j]);
                    strcpy(userNames[j], temp);
                }
            }
        }

        // print results 
        printf("Entered   |   Sorted\n");
        printf("-----------------------\n");
        for (i = 0; i < n; i++) 
        {
        	// iterates through userNamess to print them in a vertical list to make a chart 
            printf("%s\t\t%s\n", tname[i], userNames[i]);
        }	
}