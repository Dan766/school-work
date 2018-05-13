#include <stdio.h>
#include <ctype.h>
#include <string.h>
void ParseSentence(char [80]); //breaks apart string
int main()
{
	char buffer1[80] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','.'};
	char Text[90];
	fgets(buffer1, 80, stdin);
	ParseSentence(buffer1);
	
	
}

/*
	Objective: Objective of this function is to split appart all words of a given string
		supplied to the function into different strings based on some given deliminators
	Input: A 2D char array representing a string
	Ouput: The given char array split into its individual words
*/
void ParseSentence(char str[80])
{
	char *p; //The pointer used for the words
	char *del = ","; //The deliminators used to split the words
	p = strtok(str, del);
	while(p!=NULL) //The string will be split until its empty
	{
		printf("%s\n",p);
		p = strtok(NULL,del);
	}
}
