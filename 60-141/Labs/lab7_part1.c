#include <stdio.h>
int AtoI ( const char * ); //Convert string to int
int StrCmp ( const char *, const char * ); //Compare one string with another
char * StrCpy ( char * , const char * ); //Copy one string into another
char * StrCat ( char * , const char * ); //Add one string onto the end of the other
char * StrChr ( char *, int ); //Search a string for a given char value

int main(void)
{
	char s1[20],s2[20],ch,temp[20];
	printf("Enter a String to Convert to Int: ");
	scanf("%s",s1);
	printf("\tAtoI(%s) = %d\n",s1,AtoI(s1));
	
	printf("Enter Two Strings: \n\t");
	scanf("%s",s1);
	StrCpy(temp, s1);
	scanf("%s",s2);
	printf("\tStrCmp(%s,%s) = %d\n",s1,s2,StrCmp(s1,s2));
	printf("\tStrCpy(%s,%s) => s1 = ",s1,s2);
	printf("%s\n",StrCpy(s1,s2));

	StrCpy(s1, temp);
	
	printf("\tStrCat(%s,%s) => s1 = ",s1,s2);
	printf("%s\n",StrCat(s1,s2));
	StrCpy(s1, temp);
	printf("\nEnter A Search char for '%s': \n\t",s1);
	scanf("\n%c",&ch);
	if (StrChr(s1,ch)==NULL) printf("\t%c is not in ", ch);
	else printf("\t%c is in ", ch);
	printf("'%s'\n", s1);
}
/*
	Objective: Objective of this function is to convert a given string 
		to a interger value 
	Input: A pointer pointed to a string
	Ouput: The given string represented in int form
*/
int AtoI ( const char * str )
{
	int c, sign, offset, n;
	for (c = 0; str[c] != '\0'; c++) {
	  n = n * 10 + str[c] - '0';
	}
	 
	if (sign == -1) {
	  n = -n;
	}
	 
	return n;
}
/*
	Objective: Objective of this function is to compare the first string given
		with the second string and return a value >0 if first>second, 0 if they are 
		equivalent and <0 otherwise
	Input: two pointers pointed to char arrays (string)
	Ouput: The output is a number >0 / <0 / or =0, based on the lexical relation of S1 vs S2
*/
int StrCmp ( const char * str1, const char * str2 )
{
	int r=0;
	while(*(str1+r)==*(str2+r))
	{
		if ((*(str1+r)=='\0')&&(*(str2+r)=='\0'))
			return 0;
		else if ((*(str1+r)=='\0')||(*(str2+r)=='\0'))
			return *(str1+r)-*(str2+r);
		r++;
	}
	return *(str1+r)-*(str2+r);
}
/*
	Objective: Objective of this function is to copy a source string pointer and place 
		all its contents in a given destination string
	Input: two pointers pointed to char arrays (string)
	Ouput: the destination pointer will contain the same contents as the source pointer char. 
*/
char * StrCpy ( char * destination, const char * source )
{
	int r=0;
	while(*(source+r)!='\0')
	{
		*(destination+r) = *(source+r);
		r++;
	}
	*(destination+r)='\0';
	return destination;
}
char * StrCat ( char * destination, const char * source )
{
	int r=0,c=0;
	while (*(destination+r)!='\0')
	{
		r++;
	}
	while (*(source+c)!='\0')
	{
		*(destination+r)=*(source+c);
		c++;
		r++;
	}
	*(destination+r)='\0';
	return destination;
}
/*
	Objective: Objective of this function is to search a string for a given charecter value
	Input: A pointers pointed to a char array (string) and a int value representing the charecter being searched
	Ouput: the destination of the first character found in string pointer will be returned
*/
char * StrChr ( char * str, int character )
{
	int r=0;
	while ((*(str+r)!=character)&&(*(str+r)!='\0')) r++;
	if (*(str+r)==character) return str+r;
	else return NULL;
}
