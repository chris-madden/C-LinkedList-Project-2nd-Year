//Christy Madden - 17/3/15

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//Preprocessor Directives
#include <stdlib.h>
#include <stdio.h>
#include "Functions.h"


void main()
{

	//Struct pointer of type employee
	//Initially there aren't any nodes
	//Points to start of the listj
	struct employee *headPtr = NULL;

	
	//Will keep giving you menu options until 0 is entered
	do
	{

		menu();

		if (userChoice >= 0 && userChoice <= 6)
		{
			//Switch statment to direct user to their choice
			switch (userChoice)
			{

			case 1:
				//printf("Insert Add employee function ");
				addEmployee(&headPtr);//Pass in the address of headPtr
				break;

			case 2:
				//printf("Insert Display employee details function ");
				displayEmployees(headPtr);
				break;

			case 3:
				printf("Insert Update employee function");
				break;

			case 4:
				//printf("Insert Delete employee function ");
				//Check if list is empty and print out error message
				if (headPtr == NULL)
				{

					printf("List is empty\n");

				}
				else//Enter ID number to delete and search for it
				{
					printf("Enter ID to you want to delete\n");
					scanf("%d", &deleteNumber);

					deleteEmployee(&headPtr, deleteNumber);
				}	
				break;

			case 5:
				printf("Insert Display all employees by department function ");
				break;

			case 6:
				printf("Insert Display employee report function ");
				break;

			default:
				break;
			}//End switch statement

		}
		else
		{

			printf("\nInvalid number entered\n\n");

		}

	} while (userChoice != 0);
	
	printf("\n\n\n");

	system("pause");

}//End main function

void menu()
{
	
	//Prompt to enter option
	printf("Enter your option\n\n");

	//Options for user
	printf("0: Quit\n1: Add Employee\n2: Display employee details\n3: Update employee\n4: Delete employee\n5: Display all employees by department\n6: Display employee report\n\n");

	//Flush buffer before next input
	fflush(stdin);

	//Take in user choice
	scanf("%d", &userChoice);

}//End menu function


//Create pointer which points to address of headPtr
void addEmployee(struct employee **headPtr)
{

	struct employee *newNodePtr;//Pointer to a new node

	struct employee *previousPtr;//Points to previous node in the list

	struct employee *currentPtr;//Points to current node in the list

	newNodePtr = (struct employee*)malloc(sizeof(struct employee));//Creates a new node

	if (newNodePtr != NULL)//Once there is space available
	{

		printf("Enter your id number\n");
		scanf("%d", &newNodePtr->id);

		newNodePtr->nextPtr = NULL;//This node is last in list, currently doesn't link to another node

		previousPtr = NULL;//previousPtr doesn't point to anything

		currentPtr = *headPtr;//currentPtr ponits to begining of list


		//First time around currentPtr will be NULL
		while (currentPtr != NULL && newNodePtr->id > currentPtr->id)
		{

			previousPtr = currentPtr;

			currentPtr = currentPtr->nextPtr;

		}//End while

		//If there is no linked list already
		if (previousPtr == NULL)
		{

			newNodePtr->nextPtr = *headPtr;//newNodePtr's nextPtr points to head(start of the linked list)

			*headPtr = newNodePtr;//headPtr points to newNodePtr

		}//End nested if
		else//Put newNodePtr in correct position
		{
			previousPtr->nextPtr = newNodePtr;//previousPtr nextPtr points to newNodePtr

			newNodePtr->nextPtr = currentPtr;//Point newNodePtr to currentPointer
		}

	}//End if
	else
	{
		printf("Nothing was added");
	}

}//End addEmloyees

void displayEmployees(struct employee *currentPtr)
{

	if (currentPtr == NULL)
	{

		printf("List is empty\n\n");

	}
	else
	{

		printf("Employee List\n");

		while (currentPtr != NULL)
		{

			printf("%d \n\n", currentPtr->id);

			currentPtr = currentPtr->nextPtr;

		}

		//printf("NULL\n\n");

	}//End else
}//End displayEmployee

//Pass in address of headPtr and ID number of employee to delete
void deleteEmployee(struct employee **headPtr, int deleteNumber)
{

	struct employee *previousPtr = NULL;//Points to previous node in the list

	struct employee *currentPtr = NULL;//Points to current node in the list

	struct employee *tempPtr;//Points to a temporary pointer 

	//Check if deleteNumber is equal to id in headPtr
	if (deleteNumber == (*headPtr)->id)
	{

		tempPtr = *headPtr;//store headPtr node in tempPtr node

		*headPtr = (*headPtr)->nextPtr;//headPtr will point to second node in the list

		free(tempPtr);//Free up this memory (delete node)

	}
	else
	{

		previousPtr = *headPtr;//prevoiusPtr stores address to headPtr

		currentPtr = (*headPtr)->nextPtr;//CurrentPtr stores address of nextPtr
	}

	//Loop through nodes to find correct id number
	while (currentPtr != NULL && currentPtr->id != deleteNumber)
	{

		previousPtr = currentPtr;//currentPtr is asssigned to previousPtr as currentPtr did not have correct value

		currentPtr = currentPtr->nextPtr;//Moves currentPtr on to next node

	}//End while

	//Found node and delete it
	if (currentPtr != NULL)
	{

		tempPtr = currentPtr;//Assign current to the tempPtr node

		previousPtr->nextPtr = currentPtr->nextPtr;//Assigning currentPtr's nextPtr to previousPtr's nextPtr links the list together after deleting node at currentPtr

		free(tempPtr);//Free up this memory (delete node)

	}//End if

	//Print error message if ID can't be found
	if (currentPtr == NULL)
	{

		printf("ID number is not in the list\n\n");

	}

}//End deleteEmployee