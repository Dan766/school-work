#include <stdio.h>
#include <ctype.h>
void wordAnalysis(char [10][80], int); //Finds number of times each word appears
void letterAnalysis(char [10][80],int); //Funds number of times each letter appears
int wordLengthAnalysis(char [10][80],int,int); //Finds number of times words of each length appear
int main (void)
{
	char Text[10][80];  //Array that holds our text
	int n,r=0,times;
	scanf("%d\n", &n);
	while (r<n) //Scans each line of text into the Text array
	{
		fgets(Text[r], sizeof(Text[r]), stdin);
		r++;
	}
	//Finds number of times each letter appears and prints within function
	letterAnalysis(Text,n); 
	//Feeds each possible word length into the wordlength function
	printf("\nWord Length Analysis\n");
	for(r=1;r<=20;r++)
	{
		times = wordLengthAnalysis(Text,n,r);
		if (times==1) printf("%d word of length %d\n",times,r);
		else if (times>1)printf("%d words of length %d\n",times,r);
	}
	//Finds out how many times each word appears in text
	printf("\nWord Analysis\n");
	wordAnalysis(Text,n);
	return 0; //End of Function
}
/*
	Objective: The Objective of the word length function is to find the number
		of words of a given length within some text, when given said length and
		text as input, and returns the number of words. 
	Input: This function takes a 2D char array containing several lines of
		text as well as a int value representing the number of lines in the text (array)
		It also will take a given int value representing the length the function should search for
	Output: Output of this function is the number of times words of the given length
		appear in the text. 
*/
int wordLengthAnalysis(char T[10][80],int N,int length)
{
	int r, c, space1=0,space2=0,total=0;
	for (r=0;r<N;r++) //Rows
	{
		for (c=0;c<80;c++) //Columns (letters)
		{
			if ((T[r][c]=='\0')||(T[r][c]=='\n')||(isspace(T[r][c]))) //If we find a space or end of line 
			{
				space1=space2;
				space2=c;
				if ((space1==0)&&(space2==length)) total+=1; //If we are at the start of a line and space2 == Length total++
				else if((space2-space1-1==length)&&(space1!=0)) total+=1; //If we are not at start of a line check if the word is correctly spaced
			}
			if ((T[r][c]=='\0')||(T[r][c]=='\n')) break; //If we are at the end of text line break and move down a line
		}
		space2=0; //Reset the space variables
	}
	return total; //Returns the total words of given length to main
}
/*
	Objective: The Objective of the word Analysis function is
		to find and print the total number of times each word within a given
		text appears. It will produce output in a table format. 
	Input: This function takes a 2D char array containing several lines of
		text as well as a int value representing the number of lines in the text (array)
	Output: Output of this function is the number of times each value appears 
		within the text given in a table format
*/
void wordAnalysis(char T[10][80],int N)
{
	int r, c,times=1,q,count=0,count2=0;
	char word[20],let,word_list[50][20];
	for (r=0;r<N;r++) //Rows (lines)
	{
		for (c=0;c<80;c++) //Columns (letters)
		{
			//Find a word
			let = T[r][c];
			if ((!isspace(let))&&(T[r][c]!='\n')&&(T[r][c]!='\0')) //If we are not at a space, newline, or delininator Then we have a char
			{
				word[count]=let;
				count+=1;
			}
			else
			{
				for (q=0;q<count;q++) word_list[count2][q] = word[q]; //Add word to word_list
				word_list[count2][count] = '\0'; //Set end of word to \0 ( inator) 
				count2+=1;	//Resets word counter (Row)
				count=0;	//Resets the letter count (Column)	
			}
			if (T[r][c]=='\0') break;
		}
	}
	//Searches the array of words to see how many times each appears
	for (q=0;q<count2;q++) //Word being searched
	{
		if (word_list[q][0] == '\0') q++; //If the word is empty (already exists) dont search and move to next one
		for (r=q+1;r<count2;r++) //Word being checked 
		{
			for(c=0;c<20;c++) //Columns (letters) 
			{
				
				if ((word_list[r][c]=='\0')&&(word_list[q][c]=='\0'))  //If both reach end at the same time, they are identical
				{
					word_list[r][0] = '\0'; //Make the word found empty
					times+=1; //Increase counter if search key is found
					break;
				}
				else if ((word_list[r][c]=='\0')||(word_list[q][c]=='\0')) break; //If one reached end before the other, it is invalid
				else if (word_list[r][c] != word_list[q][c]) break; //If one char is not identical is is invalid
			}
		}
		printf("\"%s\"\tappeared %d time\n", word_list[q], times); //Prints in table format
		times=1; //rese times counter
	}
	return; //End of function
}
/*
	Objective: The Objective of the letter Analysis function is
		to find out how many times each letter appears in several lines
		of text given in a char array and output that data into a chart format
	Input: This function takes a 2D char array containing several lines of
		text as well as a int value representing the number of lines in the text (array)
	Output: Output of this function is the number of times each value appears 
		within the text given in a table format
*/
void letterAnalysis(char T[10][80], int N)
{
	int r, c, letters[28];
	char let;
	for (r=0;r<26;r++) letters[r] = 0;
	for (r=0;r<N;r++) //Row (line)
	{
		for (c=0;c<80;c++) //Letter (column)
		{
			let = T[r][c];
			if ((T[r][c]=='\0')||(T[r][c]=='\n')) break; //If the line is done break
			else if (isalpha(let)>0) letters[tolower(let)-'a'] += 1;
		}
	}
	printf("\nTotal Letter Counts\n");
	for (c=0;c<26;c++)
	{
		let = c + 'a'; //increases the value of c by 'a' so that it will now represent the given letter in ascii 
		printf("%c: %2d\n", let, letters[c]); //Prints the # of times each letter shows
 	}	
	return;//End of function
}
