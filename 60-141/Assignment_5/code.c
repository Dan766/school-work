//Daniel Fontana: Assignment 5
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
//Structure which stores course info for each student
struct CourseInfo{
	int courseID;
	char courseName[30];
};
//Structure which stores strudent infomation
struct studentInfo{
	int studentID;
	char First[20];
	char Last[25];
	int Courses;
	struct CourseInfo courseinfo[10];
	struct studentInfo *next; //Pointer used to link nodes of our linked list together
};
typedef struct studentInfo item; //Creates an alias for struct studentInfo called 'item'
item *head=NULL; //Sets our head pointer to NULL (not pointing to anything)
void loadStudentInfo();		//Function that reads existing data from file and 'loads' it into the linked list
void displayStudentInfo();	//Function that prints the contents of the linked list (student info)
void addStudent();			//Function which adds a node to the sorted linked list containing a new student's info  
void searchStudentName();	//Function used for searching for a specific student based on student ID
void saveStudentInfo();		//Function which saves the contents of the linked list to a text file (opposite of loadStudentInfo)
void deleteStudentInfo();	//Function which deletes a given student based on ID
void EXIT();				//Function will save student data to File and print an exit message
//item searchStudentID(int);	//Function will search student ID's using a bubble sort algoritm 
int main() //Main logic function
{
	char choice='W';
	loadStudentInfo(); //Loads student data from text file
	while (toupper(choice) != 'Q') //Loops until user quits
	{
		// Prints a selection menu onto the screen
		printf("\nAssignment 5");
		printf("\nChoose an option\n");
		printf("\tA. Add Student\n"); 
		printf("\tB. Delete Student\n");
		printf("\tC. Search Student\n");
		printf("\tD. Display Students\n");
		printf("\tE. Save Student Info\n");
		printf("\tQ. Quit\n");
		scanf("%s",&choice);
		printf("\n");
		switch (toupper(choice))
		{
		//If the A option is chosen then the addStudent function will run
		case 'A':
			addStudent();
			break;
		//If the B option is chosen then the deleteStudentInfo function will run
		case 'B':
			deleteStudentInfo();
			break;
		//If the C option is chosen then the Search function will run
		case 'C':
			searchStudentName();
			break;
		//If the D option is chosen then the print info function will run
		case 'D':
			displayStudentInfo();
			break;
		//If the E option is chosen then the save function will run
		case 'E':
			saveStudentInfo();
			break;
		//If user types 'q' than the programs exits
		case 'Q':
			EXIT();
			break;
		//If none of the above values are entered than an prompt appears telling user the char is invalid
		default:	
			printf("INVALID OPTION!");
			break;
		}
	}
	return 0; //Program End
}
/*
	Objective: The objective of the searchStudentName function is to search the linked list for
			a given student name. 
	Input: The input in this function is a given name which the user will enter
	Output: The output in this function is a prompt either showing the user the student info with
			a matching name or an error saying the entered name is not in the list. 
*/
void searchStudentName()
{
	int found=0,r;
	char name[20];
	item *temp;
	temp = head;
	printf("What is the last name of the student? ");
	scanf("%s", name);
	name[0]=toupper(name[0]);
	while(temp) //Loops untill temp is NULL
	{
		//If the last name matches one in the linked list, print the given student data
		if (strcmp(name,temp->Last)==0) 
		{
			found=1;
			printf("%d\n", temp->studentID);
			printf("%s\n", temp->First);
			printf("%s\n", temp->Last);
			printf("%d\n", temp->Courses);
			for(r=0;r<(temp->Courses);r++)
				printf("%s %d\n", temp->courseinfo[r].courseName,temp->courseinfo[r].courseID);
		}
		temp=temp->next; //move the node up in the linked list
	}
	if (found==0) printf("\nNo Matches Found\n"); //Print error if no match was found
	return; //Function END
}
/*
	Objective: The objective of the deleteStudentInfo function is to delete the node from the linked list
			which matches a given ID which the user enters.
	Input: The input of this function is a ID which the user wishes to delete
	Output: The output of this function is either an error saying a student with the entered ID does not Exist or
			the matching data set with the given ID.
*/
void deleteStudentInfo()
{
	int id=0,T=0;
	item *right=head,*left=head;
	printf("Enter a ID to delete: ");
	scanf("%d", &id);
	while(right!=NULL) //Loop until right is NULL
	{
		if(right->studentID==id) //If id is equal to right's ID, we remove right from the link and delete it
		{
			left->next=right->next;
			if (right==head) head=head->next;
			printf("\nStudent Removed\n");
			free(right); //Frees the memory space where right was stored
			break;
		}
		left=right; //set left to the existing node
		right=right->next; //move the node up in the linked list
	}
	if (right==NULL) printf("\nNo such ID exist\n"); //Print error if no match was found
	return; //Function End
}
/*
	Objective: The objective of the addStudent function is to add a new student data
			set into the correct location of the sorted linked list, based in ID.
	Input: The input of this function is all of the information about the student to be added
	Output: The output is the new, modified, linked list which will have another student added to
			it in sorted order. 
*/
void addStudent()
{
	int r=0,id;
	item *curr = (item *)malloc(sizeof(item)); //Allocate memory space form curr
	//Gets new student data
	printf("Adding new Student");
	printf("\nStudentID: ");
	scanf("%d",&curr->studentID);
	while(!searchStudentID(curr->studentID))
	{
		printf("That ID already exists!");
		printf("\nStudentID: ");
		scanf("%d",&curr->studentID);
	}
	printf("First Name: ");
	scanf("%s", curr->First);
	curr->First[0] = toupper(curr->First[0]); //Makes first letter uppercase
	printf("Last Name: ");
	scanf("%s", curr->Last);
	curr->Last[0] = toupper(curr->Last[0]); //Makes first letter uppercase
	printf("Number of Courses: ");
	scanf("%d", &curr->Courses);
	//Gets course data
	for(r=0;r<(curr->Courses);r++)
	{
		printf("Course ID: ");
		scanf("%d",&curr->courseinfo[r].courseID);
		printf("Couse Name: ");
		scanf("%s",curr->courseinfo[r].courseName);
	}
	item *right=head,*left=head; //Creats a left and right node
	//If current student ID is less then head node, we set current node to the head; 
	if (right->studentID>curr->studentID) 
	{
		curr->next=right;
		head=curr;
		return; 				//Curr placed at FRONT
	}
	while(right) //While right is not NULL
	{
		//if current ID is in between left and right nodes, we can place current in between.
		if (right->studentID>curr->studentID)
		{
			curr->next=right;
			left->next=curr;
			return; 			//Curr placed in MIDDLE
		}
		left=right;
		right=right->next;
	}
	//sets current node to the last node of the link
	curr->next=NULL;
	left->next=curr;
	return; 					//Curr placed at END
}
/*
	Objective: The objective of this function is to check if a given student ID exists
			int the linked list and return a true value if not and false if it does
	Input: The input of this function is a given id used to search the linked list
	Output: The return value is either true or false depending on whether the id is in the linked list
*/
int searchStudentID(int id)
{
	item *temp=head;
	while (temp)
	{
		if (temp->studentID>id) break; //ID cannot be in list
		if (temp->studentID==id) return 0; //ID is in the list
		temp=temp->next;
	}
	return 1; //ID is not in list
}
/*
	Objective: The objective of the loadStudetInfo function is to load all the existing
			student info from the text file and place it into a linked list; 
	Input: The input of this function is a text file containing student information
	Output: The output of this function is a linked list containing all of the data from the text file.
*/
void loadStudentInfo()
{
	int r;
	item *curr;
	FILE *FP;
	curr=(item*)malloc(sizeof(item)); //Allocates mem space for curr node
	FP = fopen("studentList.txt","r");
	while(0<fscanf(FP,"%d", &curr->studentID)) //Scans until studentID is a char (***) 
	{
		fscanf(FP,"%s", curr->First);
		fscanf(FP,"%s", curr->Last);
		fscanf(FP,"%d", &curr->Courses);
		for(r=0;r<(curr->Courses);r++)
			fscanf(FP,"%s %d", curr->courseinfo[r].courseName,&curr->courseinfo[r].courseID);
		if (head==NULL) //If head is NULL, then set the current node to be head
		{
			curr->next = NULL;
			head = curr;
		}
		else //Else, the list is not empty, thus add at correct location
		{
			item *temp;
			temp=head;
			while(temp->next) temp=temp->next;
			curr->next=NULL;
			temp->next = curr;
		}
		curr=(item*)malloc(sizeof(item)); //Allocate mem space for curr node
	}
	curr = head;
	fclose(FP); //Close the FILE
}
/*
	Objective: The objective of the saveStudentInfo function is to save all of the studentData stored in
			the linked list in a text file. 
	Input: The input of this function is a linked list containing all of the student data
	Output: The output of this function is a text file containing all of the data which was stored in the linked list
*/
void saveStudentInfo()
{
	int r;
	item *curr=head;
	FILE *FP;
	FP = fopen("studentList.txt","w"); //Open file for writing
	while(curr) //Save up to the end of link
	{
		fprintf(FP,"%d\n", curr->studentID);
		fprintf(FP,"%s\n", curr->First);
		fprintf(FP,"%s\n", curr->Last);
		fprintf(FP,"%d\n", curr->Courses);
		for(r=0;r<(curr->Courses);r++)
			fprintf(FP,"%s %d\n", curr->courseinfo[r].courseName,curr->courseinfo[r].courseID);
		curr=curr->next; //Go to next node
	}	
	fprintf(FP,"***"); //Print our File delimiter
	fclose(FP); //Close File
}
/*
	Objective: The objective of this function is to print all of the data stored in the linked list
			on the screen in a neat format.
	Input: The input of this function is a linked list containing all of the student data
	Output: The output of this function is the data stored in the linked list outputted to the screen
*/
void displayStudentInfo()
{
	int r=0,c=1;
	item *curr = head;
	while(curr) //Loop until end of link
	{
		printf("\nStudent %d:\n",c);
		printf("%d\n", curr->studentID);
		printf("%s\n", curr->First);
		printf("%s\n", curr->Last);
		printf("%d\n", curr->Courses);
		for(r=0;r<(curr->Courses);r++)
			printf("%s %d\n", curr->courseinfo[r].courseName,curr->courseinfo[r].courseID);
		curr=curr->next;
		c++;
	}
}
/*
	Objective: The objective of the exit function is to save the student data
			upon exiting the program
	Input: The input of this function is a linked list containing student data
	Output: The output of this function is a file containing all the student data
*/
void EXIT()
{
	saveStudentInfo();
	printf("Student List Saved Successfully\n");
	printf("Bye!\n");
}
