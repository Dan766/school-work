#include <stdio.h>
#include <string.h>
struct word 
{
	char Word[21];
	int Length;
}WordList[20]; //Define WordList[20] as type struct word

//Main function
int main()
{
	char temp[20]; //Temp storage for holding word when sorting
	char myString[] = "the cat in the hat jumped over the lazy fox";
	char *token;
	int r=0,c,d,N=0;
	token = strtok(myString, " "); //Splits string based on spaces
	printf("\nUNSORTED LIST:");
	while (token!=NULL) //Breaks string until string is empty
	{
		strcpy(WordList[r].Word,token); //Copies the token into wordlist
		WordList[r].Length = strlen(token); //gets length and places in wordlist
		printf("\n\t%s",WordList[r].Word);
		token=strtok(NULL, " "); //Splits string again using spaces
		r++;
	}
	N=r; 
	for(c=0;c<N-1;c++) //Bubble Sorting
	{
		for (d=0;d<N-c-1;d++)
		{
			if (0>strcmp(WordList[d+1].Word,WordList[d].Word))
			{
				strcpy(temp,WordList[d].Word);					//Perform
				strcpy(WordList[d].Word,WordList[d+1].Word);	//Swap
				strcpy(WordList[d+1].Word,temp);				//Operation
			}
		}
	}
	printf("\n\nSORTED LIST:");
	for(r=0;r<=N;r++) // Prints the Sorted List
	{
		printf("\n\t%s",WordList[r].Word);
	}
}