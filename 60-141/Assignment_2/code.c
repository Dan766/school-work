#include <stdio.h>
#define final_path 'X'	 	//Final solution path
#define possible_path '/'	//Propossible/mid-generation pathways in Maze
#define open_path '0'		//Open pathways in Maze
#define maze_r 12			//Maze rows
#define maze_c 12			//Maze Columns 
void findStart(char [maze_r][maze_c], int []);		//function used to find the starting coords of the maze
void mazeTraversal(char[maze_r][maze_c],char[maze_r][maze_c], int [], char); //Function used to follow the given path generated in generatepath()
int generatepath(char[maze_r][maze_c],int [], char);	//Function used to generate a path through the maze
int backtrack(char[maze_r][maze_c], int [], char);	//Function used to 'backtrack' out of a corner when stuck
int validMove(char[maze_r][maze_c],int[]);			//Function used to find how many valid moved, if any, can be made from a given pos
int coordsAreEdge(int []);						//Function used to see if a given pos is the exit 
void printMaze(char[maze_r][maze_c]);					//Function used to print the maze
//Main function
int main (void)
{
	int r,c,pos[2]={0,0};
	char dir='N', path[maze_r][maze_c], maze[maze_r][maze_c]={
			   {'1','1','1','1','1','1','1','1','1','1','1','1'},
			   {'1','0','0','0','1','0','0','0','0','0','0','1'},
			   {'0','0','1','0','1','0','1','1','1','1','0','1'},
			   {'1','1','1','0','1','0','0','0','0','1','0','1'},
			   {'1','0','0','0','0','1','1','1','0','1','0','0'},
			   {'1','1','1','1','0','1','0','1','0','1','0','1'},
			   {'1','0','0','1','0','1','0','1','0','1','0','1'},
			   {'1','1','0','1','0','1','0','1','0','1','0','1'},
			   {'1','0','0','0','0','0','0','0','0','1','0','1'},
			   {'1','1','1','1','1','1','0','1','1','1','0','1'},
			   {'1','0','0','0','0','0','0','1','0','0','0','1'},
			   {'1','1','1','1','1','1','1','1','1','1','1','1'} };
	//Generates a second maze called 'path' used to generate a path
	for (r=0;r<maze_r;r++){
		for(c=0;c<maze_c;c++)
			path[r][c]= maze[r][c]; }
	//Welcomes user and tells them what the 0's 1's and X's mean
	printf("\nWelcome to Maze Traversal: Assignment 2\n");
	printf("\nTip:\n");
	printf("\t'1' = Wall     \n");
	printf("\t'0' = Open Path \n");
	printf("\t'X' = Your Location   \n\n");
	//Finds starting coords and generates a path to the exit
	findStart(maze,pos);	
	generatepath(path,pos,dir);
	//Finds starting coords again and follows the path already generated to the exit
	findStart(maze,pos);	
	mazeTraversal(maze,path,pos,dir);
	//Prints the maze solution in a easy to read form
	printf("Maze Solution:\n");
	printMaze(maze);
}
/*
	Objective: The Objective of the find start function is to find and return the 
		starting coords of maze by looking along the first column for a open space
		('0' AKA open_path)
	Input: Input of this function is a 1D int array called pos[] and char maze[][]
		int pos[]
			-> A 1D int array representing the current x,y position in the maze
		char maze[maze_r][maze_c]
			-> maze function is used to hold the final maze solution path 
	Output: The output of the function is the x,y position of the maze entrance.
*/
void findStart(char maze[maze_r][maze_c],int pos[])
{
	int new;
	pos[0]=0;
	//Looks along the first column for a '0' aka open_path
	for(pos[1]=0;pos[1]<maze_r;pos[1]++)
	{
		if (maze[pos[1]] [pos[0]]==open_path)
		{
			return;
		}
		else
			pos[1]+=1;
	}
		
}
/*
	Objective: The Objective of the generatepath function is to generate a path going from the
		start of the maze to the exit and represent it used '/' chars AKA possible_path
	Input: Input of this function is a 1D int array called pos[] the char path[][] array 
			as well as char dir
		int pos[]
			-> A 1D int array representing the current x,y position in the maze
		char path[maze_r][maze_c]
			-> path array is used to hold the proposed solution path for the maze function
		char dir
			-> dir will hold the current direction of travel. ie 'N'
	Output: The Output of this function is the solution for the proposed path of the solution
			given in the path[][] array. The path is shown using '/' AKA possible_path
*/
int generatepath(char path[maze_r][maze_c],int pos[], char dir)
{
	int r,c,ran;
	path[pos[1]] [pos[0]] = possible_path;
	if (coordsAreEdge(pos)) //Function exits if the exit is found
		return 0;
	switch (dir)
	{
		case 'N':
			if(path[pos[1]-1][pos[0]]==open_path) //If you can go North, position is moved
				pos[1]-=1;
			else
				dir='S';
			break;
		case 'E':
			if (path[pos[1]][pos[0]+1]==open_path) //If you can go East, position is moved
				pos[0]+=1;
			else
				dir='W';
			break;
		case 'S':
			if (path[pos[1]+1][pos[0]]==open_path) //If you can go South, position is moved
				pos[1]+=1;
			else
				dir='E';
			break;
		case 'W':
			if (path[pos[1]][pos[0]-1]==open_path) //If you can go West, position is moved
				pos[0]-=1;
			else
				dir='N';
			break;
	}
	//If you get stuck in a corner, then backtrack function will move you back to an intersection
	//and then try a different random direction
	if (validMove(path,pos)==0)
	{
		backtrack(path,pos,dir);
		ran =(rand()%4);
		if (ran==1)
			dir='N';
		else if (ran==2)
			dir='S';
		else if (ran==3)
			dir='W';
		else 
			dir='E';
	}
	generatepath(path,pos,dir); //Makes the recursive call
}
/*
	Objective: The Objective of the mazeTraversal function is to follow the path
		from the enterence of the maze located in the char maze[][] function to the
		exit of the maze using a pre generated path given in the char path[][] array
		and display the current move as traversal is processing. 
	Input: Input of this function is a 1D int array called pos[] the char path[][] array 
			the char maze[][] as well as char dir
		int pos[]
			-> A 1D int array representing the current x,y position in the maze
		char path[maze_r][maze_c]
			-> path array is used to hold the proposed solution path for the maze function
		char maze[maze_r][maze_c]
			-> maze function is used to hold the final maze solution path 
		char dir
			-> dir will hold the current direction of travel. ie 'N'
	Output: The Output of this function is the maze solution given in the char maze[][] array
			the solution path is shown using 'X' AKA final_path
*/
void mazeTraversal(char maze[maze_r][maze_c],char path[maze_r][maze_c],int pos[], char dir)
{
	if (coordsAreEdge(pos)) //If the exit is found the function will exit and print the maze one last time
		return;
	switch (dir)
	{
		case 'N':
			if(path[pos[1]-1][pos[0]]==possible_path) //If you can go North, position is moved
			{
				pos[1]-=1;
				printMaze(maze);
			}
			else
				dir='S';
			break;
		case 'E':
			if (path[pos[1]][pos[0]+1]==possible_path) //If you can go East, position is moved
			{
				pos[0]+=1;
				printMaze(maze);
			}
			else
				dir='W';
			break;
		case 'S':
			if (path[pos[1]+1][pos[0]]==possible_path) //If you can go South, position is moved
			{
				pos[1]+=1;
				printMaze(maze);
			}
			else
				dir='E';
			break;
		case 'W':
			if (path[pos[1]][pos[0]-1]==possible_path) //If you can go West, position is moved
			{
				pos[0]-=1;
				printMaze(maze);
			}
			else
				dir='N';
			break;
	}
	path[pos[1]][pos[0]] = final_path; //Places a 'X' aka final_path
	maze[pos[1]][pos[0]] = final_path; // on the current x,y of path and maze
	mazeTraversal(maze,path,pos,dir); //Makes recursive call
}
/*
	Objective: The Objective of the validMove function is to find how many possible 
		directions you can go from a given x,y position and return that number. 
		1 means that there is only one possible path, 0 means you are stuck in a corner
		and 2 means you are at an interection. 
	Input: Input of this function is a 1D int array called pos[] and the the char
			path[][] array 
		int pos[]
			-> A 1D int array representing the current x,y position in the maze
		char path[maze_r][maze_c]
			-> path array is used to hold the proposed solution path for the maze function
	Output: The Output of this function is a interger number representing the # of possible
			pathways that can be travelled. 0 means none, 1 is 1 and 2 means there are multiple. 
*/
int validMove(char path[maze_r][maze_c],int pos[])
{
	int c;
	c=0;
	if (coordsAreEdge(pos)) return 1; //If the next move is at edge then return valid move
	if (path[pos[1]-1][pos[0]]==open_path) c+=1; //For each possible move
	if (path[pos[1]+1][pos[0]]==open_path) c+=1; //		that can be made, add
	if (path[pos[1]][pos[0]-1]==open_path) c+=1; //	 	one to the counter
	if (path[pos[1]][pos[0]+1]==open_path) c+=1; //	 	called c
	if (c==0) return 0; 	//return 0 if no direction is valid
	else if (c==1) return 1;//return 1 if only 1 direction is valid	
	else return 2;			//return 2 if multiple moves are valid (intersection)
}
/*
	Objective: The Objective of the backtrack function is to 'backtrack' the path array
			to an intersection from a given position whenever said position hits a dead end. 
	Input: Input of this function is a 1D int array called pos[], the path[][] array
		as well as a char array called 'dir' which holds the current direction
		int pos[]
			-> A 1D int array representing the current x,y position in the maze
		char path[maze_r][maze_c]
			-> path array is used to hold the proposed solution path for the maze function
		char dir
			-> the current direction ie. 'N' 
	Output: The Output of this function is a modified version of the 'path' array.
			It will erase all 'possible_path' chars from each location started from 
			the current position going back to the nearest intersection
		char path[maze_r][maze_c]
			-> path array is used to hold the proposed solution path for the maze function
*/
int backtrack(char path[maze_r][maze_c],int pos[], char dir)
{
	switch(dir)
	{
		case 'N':
			if(path[pos[1]-1][pos[0]]==possible_path) //If you can go North, position is moved
				pos[1]-=1;
			else
				dir='E';
			break;
		case 'E':
			if (path[pos[1]][pos[0]+1]==possible_path) //If you can go East, position is moved
				pos[0]+=1;
			else
				dir='S';
			break;
		case 'S':
			if (path[pos[1]+1][pos[0]]==possible_path) //If you can go South, position is moved
				pos[1]+=1;
			else
				dir='W';
			break;
		case 'W':
			if (path[pos[1]][pos[0]-1]==possible_path) //If you can go West, position is moved
				pos[0]-=1;
			else
				dir='N';
			break;
	}
	//If we ger back to multiple valid moves (intersection), exit
	if (validMove(path,pos)==2)
		return 0;
	path[pos[1]][pos[0]] = open_path; //Resets each 'possible_path' with a 'open_path'
	backtrack(path,pos,dir);	//recursive call
}
/*
	Objective: The Objective of the coordsAreEdge function is to return
		True if a given x,y coordinate corresponds to the edge of a given
		maze (meaning you have reached the end) or return False otherwize
	Input: Input of this function is a 1D int array called pos[]
		int pos[]
			-> A 1D int array representing the current x,y position in the maze
	Output: The Output of this function is a booleon True or False depentent
			on whether the current position is at the edge or not via return 0 or return 1; 
	
*/
int coordsAreEdge(int pos[])
{
	if ((pos[1]==maze_r-1)||(pos[0]==maze_c-1))
		return 1;
	return 0;
}
/*
	Objective: The Objective of the printMaze function is to print
		a given 2D char array as well as accept a keystrock via a
		getchar() statement in order to pause the program following
		each print.
	Input: Input of this function is a maze_r by maze_c char array (2D)
			The other input is the getchar() function which accepts a keystroke
		char maze[maze_r][maze_c]
			-> A 2D charecter array which represents the maze being solved
		getchar()
			-> this will pause the program awaiting the user to hit enter on the keyboard
	Output: The Output of this function is the maze array printed in a 
			proper format into the console. 
		char maze[maze_r][maze_c]
			-> A 2D charecter array which represents the maze being solved
*/
void printMaze(char maze[maze_r][maze_c])
{
	int r,c;
	//Prints the maze
	for (r=0;r<maze_r;r++)
	{
		printf("\t");
		for (c=0;c<maze_c;c++)
		{
			printf("%c ",maze[r][c]);
		}
		printf("\n");
	}
	printf("\nHit return to continue: ");
	getchar();
	printf("\n");
}
