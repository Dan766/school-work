#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for course information
struct CourseInfo {
    int courseID;
    char courseName[50];
    char courseCode[12];
    char Term[6];
};
typedef struct CourseInfo courseinfo_t; //Gives our structure a alias to make it easier to reference

int loadCourseInfo(courseinfo_t *course); //reads course info and stores in structure
void allupper(courseinfo_t *course,int); //Makes all chars in a string uppercase 
void displayCourseInfo(courseinfo_t *course, int); //prints all course information in table
void searchCourseInfo(courseinfo_t *course, int); //used for search structures 
void addCourseInfo(courseinfo_t *course, int *); //Used to add a new course entry to structures
//Main function
int main (void)
{
	int Entries; //The number of courses entered
	courseinfo_t course[30]; //creates a array of type Courseintfo_t
	char choice;
	
	Entries=loadCourseInfo(course); //Reads our data from text file
	freopen("/dev/tty", "r", stdin); //Turns off input redirection so user can input data

	while (toupper(choice) != 'Q') //Loops until user quits
	{
		// Prints a selection menu onto the screen
		printf("\nCourses Program: Assignment 4");
		printf("\nChoose an option\n");
		printf("\tA. Add Course\n"); 
		printf("\tB. Display Courses\n");
		printf("\tC. Search Courses\n");
		printf("\tQ. Quit\n");
		scanf("%s",&choice);
		printf("\n");
		switch (toupper(choice))
		{
		//If the E option is chosen then the AddCourse function will run
		case 'A':
			printf("\tAddCourse\n\t========");
			addCourseInfo(course, &Entries);
			break;
		//If the E option is chosen then the DisplayCourseInfo function will run
		case 'B':
			printf("\tDisplayCourses\n\t===========");
			displayCourseInfo(course, Entries);
			break;
		//If the E option is chosen then the Search function will run
		case 'C':
			printf("\tSearch\n\t==========");
			searchCourseInfo(course, Entries);
			break;
		//If user types 'q' than the programs exits
		case 'Q':
			printf("Have a nice day!\n");
			break;
		//If non of the above values are entered than an prompt appears telling user the char is invalid
		default:	
			printf("INVALID OPTION!");
			break;
		}
	}
	return 0; //Program End
}
/*
	Objective: This objective of this function is to make all courseName
		char values of a given structure uppercase. 
	Input: A pointer to a given array of structs 
	Output: The inputted array of char values in uppercase only
*/
void allupper(courseinfo_t *course,int id)
{
	int r=0;
	for (r=0;course[id-1].courseName[r]!='\0';r++)
	{
		course[id-1].courseName[r] = toupper(course[id-1].courseName[r]);
	}
	return;
}
/*
	Objective: This objective of this function is search a array of structures
		representing course info looking for courses which match a given course ID
		or Name. 
	Input: A pointer to a given array of Structures, and the total number of courses
	Output: The output is either the course information of courses which match the 
		search key, or an error stating that the search key does not exist in the course info
*/
void searchCourseInfo(courseinfo_t *course,int total)
{
	int r, id=7,found;
	char name[20],ch='a';
	Fail: //If entry was invalid rety:
	printf("\nEnter '0' to search by Course ID or '1' to search by Course Name: ");
	scanf("%d", &id);
	if (id==0) //Search ID
	{
		printf("\nEnter a Course ID to search: ");
		scanf("%d", &id);
		for(r=0;r<total;r++)
		{
			if (course[r].courseID==id) {
				printf("\n\tID  Course\t  Code\t\tTerm\n");
				printf("\t%d   %-14s%-14s%-10s\n",course[r].courseID,course[r].courseName,course[r].courseCode,course[r].Term); //Print info in Table Format
				found=1;
			}
		}
		if (!found) printf("\tNo Courses with that ID exist\n");
	}
	else if (id==1) //Search Course Name
	{
		printf("\nEnter a Course Name to search: ");
		scanf("%s", name);
		for (r=0;name[r]!='\0';r++) name[r] = toupper(name[r]);
		for(r=0;r<total;r++)
		{
			if (0==strcmp(course[r].courseName,name)) {
				printf("\n\tID  Course\t  Code\t\tTerm\n");
				printf("\t%d   %-14s%-14s%-10s\n",course[r].courseID,course[r].courseName,course[r].courseCode,course[r].Term); //Print Info in table format
				found=1;
			}
		}
		if (!found) printf("\tNo Courses with that Name exist\n");	
	}
	else 
	{
		printf("INVALID ENTRY");
		goto Fail; //If entry invalid return to top
	}
	return;
}
/*
	Objective: This objective of this function is access a array of structures
		representing course info and add a new course element to the array.
	Input: A pointer to a given array of Structures, and the total number of courses
	Output: The output is the modified array of structures now containing the added course info
*/
void addCourseInfo(courseinfo_t *course,int *total)
{
	int r=0;
	printf("\nNew couse ID is %d:", *total+1);
	printf("\n\tEnter a	new Course Name: ");
	scanf("%s", course[*total].courseName);
	allupper(course, *total+1); //Puts coursename in uppercase
	printf("\n\tEnter a new Course Code(****-***-**): ");
	scanf("%11s", course[*total].courseCode);
	printf("\n\tEnter a new Course Term(MonthYear): ");
	scanf("%5s", course[*total].Term);
	course[*total].courseID = *total+1;
	*total+=1;
	return; //Functio End
}
/*
	Objective: This objective of this function is to print all course information 
		found in the course array structure
	Input: A pointer to a given array of Structures, and the total number of courses
	Output: The output is all the course information outputed in a table format
*/
void displayCourseInfo(courseinfo_t *course,int total)
{
	int r;
	printf("\nID  Course\t  Code\t\tTerm\n");//Print header
	for (r=0;r<total;r++)
	{
		printf("%d   %-14s%-14s%-10s\n",course[r].courseID,course[r].courseName,course[r].courseCode,course[r].Term); //Print data in table format
	}
	return; //Function End
}
/*
	Objective: This objective of this function is to read information from a file through
		input redirection and place all the found data into a array of structures 
	Input: A pointer to a given array of Structures
	Output: The output is the array of structures filled with all the info read from the file. 
*/
int loadCourseInfo(courseinfo_t *course)
{
	int r=0,c;
	char *t,info[100],temp[20];
	for(r=0;r<4;r++){
		//puts all of the given input line into the info array
		scanf("%s",info);
		//Scans for CourseName
		t = strtok(info, ","); 
		strcpy(course[r].courseName,t);
		allupper(course, r+1); //Changes all course Name chars to Uppercase
		t = strtok(NULL, ","); 
		//Scans for courseCode
		strcpy(course[r].courseCode,t);
		t = strtok(NULL, ","); 
		strcat(course[r].courseCode,t);	
		t = strtok(NULL, ","); 
		strcat(course[r].courseCode,"-");
		strcat(course[r].courseCode,t);	
		t = strtok(NULL, ","); 
		strcat(course[r].courseCode,"-");
		strcat(course[r].courseCode,t);
		//Scans Term 
		t = strtok(NULL, ","); 
		strcpy(course[r].Term,t);
		t = strtok(NULL, ","); 
		strcat(course[r].Term,t);
		//CourseID		
		course[r].courseID = r+1; 
	}
	return 4; //Returns the number of inputs
}
