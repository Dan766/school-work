#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
void printListRR(Student *List);
void searchList(Student *List);

int main() {
    int choice = 0;
    Student *SLIST = NULL;
    choice = getChoice();
    while(choice >= 0) {
        switch(choice) {
            case 0 : printf("Bye...\n"); exit(0);
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }
    if(SLIST) free(SLIST);
    return 0;
}
int getChoice() {
    int choice = 0;
    printf("\n\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}
/*
	Objective: The objective of this function is to print a given linked list
			in reverse order using recurision. 
*/
void printListRR(Student *list)
{
	if(list==NULL) return;
	printListRR(list->next);
	printf("\n%d %s", list->ID, list->name);
}
/*
	Objective: The objective of the searchList function is to search a given linked
			list for a given student id and return any student data stored in the linked
			list that has the given id. 
*/
void searchList(Student *list)
{
	int id,found=0;
	printf("Enter an ID to search: ");
	scanf("%d", &id);
	while(list)
	{
		if (list->ID==id) //If a match is found we print the data 
		{
			printf("\n%d %s", list->ID, list->name);
			found++;
		}
		list=list->next;
	}
	if (found==0) printf("\nID \"%d\" not found", id);
	return; //Function End
}
/*
	Objective: The objective of printList is to print the contents of a 
			given linked list. 
*/
void printList(Student *list)
{
	if (list==NULL) printf("No items in list\n");
	printf("Student List");
	while(list)
	{
		printf("\n%d %s", list->ID, list->name);
		list=list->next;
	}
	return; //Function End
}
/*
	Objective: The objective of the addtolist function is to add a data structure
			to the begining of a given linked list. 
*/
Student *addToList(Student *list)
{
	Student *newlist;
	newlist=(Student*)malloc(sizeof(Student)); //Allocates data for the new list
	printf("\nEnter A Student ID: ");
	scanf("%d",&newlist->ID);
	printf("\nEnter a Student Name: ");
	scanf("%s",newlist->name);
	//if(list==NULL) //If the list is empty we use list as a terminator
	//{
	//	newlist->next=NULL;
	//	return newlist;
	//}
	//If the list is not empty add newlist to end of list and move terminator
	Student *temp;
	temp=list; //Our temperary value used for returning the start of the list
	while(list->next) list=list->next; //Finds the end
	newlist->next=NULL; //Moves terminator
	list->next=newlist; //'links' the new list
	return temp; //Returns new list
}