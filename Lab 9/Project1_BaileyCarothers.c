#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
/*
Name: Bailey Carothers
Section: 502
Purpose of Program:
Execute a list of tasks required by Lab 8, Project 1

Cryptography

Function main begins program execution
*/

void encrypt_and_sort(int numStrings);

int main()
{
	//Declare int for number of arrays we will need
	//And other variables for use in main
	int numStrings, stringsEntered = 0;
	printf("How many strings will you encrypt? ");
	scanf("%d", &numStrings);
	getchar();

	//Call our function to populate, encrypt, and sort arrays
	encrypt_and_sort(numStrings);

	return 0;
}



void encrypt_and_sort(int numStrings)
{
	//User user input to declare 2D array
	char messages[numStrings][MAX_LENGTH];
	char choice, message[100], *newMessage;

	//Arrays for even and odd
	char firstPart[50], secondPart[50];
	newMessage = "";
	memset(firstPart, 0, sizeof(firstPart));
	memset(secondPart, 0, sizeof(secondPart));

	//How many strings we have taken so far
	int stringCount = 0;
	do {
		//Do-while loop because we always want to take the input at least once
		//Prompt and scan in user string using gets
    	printf("Enter a string: ");
    	gets(message);

    	//Declare variables and set to 0
    	int j = 0, k = 0;

    	// Go through and sort out the elements by index
    	for(int i = 0; i < strlen(message); i++) {
    	  //Even numbers into array
    	  if (((i + 1) % 2) == 0) {
    	    firstPart[j] = message[i];
    	    j++;
    	  }
    	  //Odd numbers into array
    	  else {
    	    secondPart[k] = message[i];
    	    k++;
    	  }
    	}

    firstPart[k+1] = '\0';
    secondPart[j+1] = '\0';

    //Set our integers = to 0 again
    k = 0;
    j = 0;

    //Print the encrypted message back to the user
    newMessage = strcat(firstPart, secondPart);
    printf("Your encrypted message is: %s\n", newMessage);
    strcpy(messages[stringCount], newMessage);

    //Increment our stringCount variable
    stringCount++;
    //Make newMessage blank again
    newMessage = "";
    memset(firstPart, 0, sizeof(firstPart));
    memset(secondPart, 0, sizeof(secondPart));


    //Find out if user is done entering strings
    printf("Would you like to continue (Y/N) ? ");
    scanf("%c", &choice);
    getchar();
  } while(choice == 'Y' || choice == 'y');

  // Go through the saved strings and decode in place
  for(int pos = 0; pos < stringCount; pos++){
    char *oddChars = (char *)malloc(sizeof(char) * strlen(messages[pos]));
    char *evenChars = (char *)malloc(sizeof(char) * strlen(messages[pos]));

    //Even characters
    for(int sop = 0; sop < (strlen(messages[pos]) / 2); sop++) {
      evenChars[sop] = messages[pos][sop];
    }

    //Odd characters
    int temp = 0;
    for(int sop = (strlen(messages[pos]) / 2); sop < strlen(messages[pos]); sop++) {
      oddChars[temp] = messages[pos][sop];
      temp++;
    }

    //Declare an array for our decrypted strings and another temp int
    char decrypted[MAX_LENGTH];
    int temp_2 = 0;

    //Decrypt messages
    for(int i = 0; i < strlen(oddChars); i++) {
      decrypted[temp_2] = oddChars[i];
      temp_2++;
      decrypted[temp_2] = evenChars[i];
      temp_2++;
    }
    decrypted[temp_2 + 1] = '\0';
    strcpy(messages[pos], decrypted);
  }

  //Declare a temp array for use when sorting
  char temp[MAX_LENGTH];

  //Time to sort strings
  for (int j=0; j<numStrings-1; j++) {
    for (int i=j+1; i<numStrings; i++) {
      if (strcmp(messages[j], messages[i]) > 0) {
        strcpy(temp, messages[j]);
        strcpy(messages[j], messages[i]);
        strcpy(messages[i], temp);
      }
    }
  }

  //Print original arrays back to the users sorted alphabetically
  printf("Here are your original strings sorted in alphabetical order:\n");
  for(int i = 0; i < numStrings; i++)
    printf("%s\n", messages[i]);
	
	return;
}