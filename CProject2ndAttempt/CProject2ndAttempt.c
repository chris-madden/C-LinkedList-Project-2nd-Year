//Christy Madden - 17/3/15

/*
=============================================================NOTES================================================================

------------------------1. When wrong details enterd in addEmployee it still saves in a list and needs to be deleted--------------

------------------------2. Salary needs to be entered and so too does email-------------------------------------------------------
*/

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
	int tempNumber, validationNum, correctUserCoice;
	
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
				printf("Enter your id number\nMust be between 1 and 10,000\n\n");
				scanf("%d", &tempNumber);

				//Checks ID entered is a number bewteen 1 and 10000
				if (tempNumber >= 0 && tempNumber <= 10000)
				{

					//Will check if number is unique or not
					validationNum = uniqueIDSearch(headPtr, tempNumber);

				}
				else
				{

					//Error Message
					printf("Incorrect ID start again\n\n");
					break;

				}//End else

				//If ID is unique
				if (validationNum != NULL)
				{

					//Pass ID into addEmployee function
					addEmployee(&headPtr, validationNum);//Pass in the address of headPtr

				}//End if
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
//PASS IN TEMP_NUMBER
void addEmployee(struct employee **headPtr, int validationNum)
{

	struct employee *newNodePtr;//Pointer to a new node

	struct employee *previousPtr;//Points to previous node in the list

	struct employee *currentPtr;//Points to current node in the list

	int dayChecker, monthChecker, yearChecker;//Variables for day and month validation

	newNodePtr = (struct employee*)malloc(sizeof(struct employee));//Creates a new node

		if (newNodePtr != NULL)//Once there is space available
		{
			
			newNodePtr->id = validationNum;//Assign unique user entered number to id of newNodePtr

			//Prompt user for details
			printf("Enter your name\n");
			scanf("%s", newNodePtr->name);

			printf("Enter your address\n");
			scanf("%s", newNodePtr->address);

			printf("Enter your department\n");
			scanf("%s", newNodePtr->department);

//===========================DATE VALIDATION NOT WORKING PROPERLY================================================
			//Will check a correct day was entered
			dayChecker = date();

			//addEmployee function gets recalled
			if (dayChecker == NULL)
			{
				
				printf("Invalid date\nMust be from 1 to 31\n\n");
				//dayChecker = date();

			}
			else if (dayChecker <= 29)
			{

				newNodePtr->employeeDate.day = dayChecker;

				printf("Select your month\n");
				printf("1: Jan\n2: Feb\n3: Mar\n4: April\n5: May\n6: June\n7: July\n8: Aug\n9: Sep\n10: Oct\n11: Nov\n12: Dec\n");
				scanf("%d", &monthChecker);

				switch (monthChecker)
				{

				case 1: 
					newNodePtr->employeeDate.month = 1;
					break;
				case 2:
					newNodePtr->employeeDate.month = 2;
					break;
				case 3:
					newNodePtr->employeeDate.month = 3;
					break;
				case 4:
					newNodePtr->employeeDate.month = 4;
					break;
				case 5:
					newNodePtr->employeeDate.month = 5;
					break;
				case 6:
					newNodePtr->employeeDate.month = 6;
					break;
				case 7:
					newNodePtr->employeeDate.month = 7;
					break;
				case 8:
					newNodePtr->employeeDate.month = 8;
					break;
				case 9:
					newNodePtr->employeeDate.month = 9;
					break;
				case 10:
					newNodePtr->employeeDate.month = 10;
					break;
				case 11:
					newNodePtr->employeeDate.month = 11;
					break;
				case 12:
					newNodePtr->employeeDate.month = 12;
					break;
				default:
					printf("Invalid date\nMust be from 1 to 12\n\n");
					break;
				}//End switch

			}
			else if (dayChecker == 30)
			{

				newNodePtr->employeeDate.day = dayChecker;

				printf("Select your month\n");
				printf("1: Jan\n2: Mar\n3: April\n4: May\n5: June\n6: July\n7: Aug\n8: Sep\n9: Oct\n10: Nov\n11: Dec");
				scanf("%d", &monthChecker);

				switch (monthChecker)
				{

				case 1:
					newNodePtr->employeeDate.month = 1;
					break;
				case 2:
					newNodePtr->employeeDate.month = 3;
					break;
				case 3:
					newNodePtr->employeeDate.month = 4;
					break;
				case 4:
					newNodePtr->employeeDate.month = 5;
					break;
				case 5:
					newNodePtr->employeeDate.month = 6;
					break;
				case 6:
					newNodePtr->employeeDate.month = 7;
					break;
				case 7:
					newNodePtr->employeeDate.month = 8;
					break;
				case 8:
					newNodePtr->employeeDate.month = 9;
					break;
				case 9:
					newNodePtr->employeeDate.month = 10;
					break;
				case 10:
					newNodePtr->employeeDate.month = 11;
					break;
				case 11:
					newNodePtr->employeeDate.month = 12;
					break;
				default:
					printf("Invalid date\nMust be from 1 to 12\n\n");
					break;
				}//End switch

			}//End else if
			else
			{

				newNodePtr->employeeDate.day = dayChecker;

				printf("Select your month\n");
				printf("1: Jan\n2: Mar\n3: May\n4: July\n5: Aug\n6: Oct\n7: Dec");
				scanf("%d", &monthChecker);

				switch (monthChecker)
				{

				case 1:
					newNodePtr->employeeDate.month = 1;//Jan
					break;
				case 2:
					newNodePtr->employeeDate.month = 3;//March
					break;
				case 3:
					newNodePtr->employeeDate.month = 5;//May
					break;
				case 4:
					newNodePtr->employeeDate.month = 7;//July
					break;
				case 5:
					newNodePtr->employeeDate.month = 8;//Aug
					break;
				case 6:
					newNodePtr->employeeDate.month = 10;//Oct
					break;
				case 7:
					newNodePtr->employeeDate.month = 12;//Dec
					break;
				default:
					printf("Invalid date\nMust be from 1 to 7\n\n");
					break;
				}//End switch

			}//End else
			
			printf("Enter year in format yyyy\n");
			scanf("%d", &yearChecker);

			if (yearChecker >= 1900 && yearChecker <= 2015)
			{

				newNodePtr->employeeDate.year = yearChecker;

			}
			else
			{

				printf("Invalid date\nMust be from 1900 to 2015\n");

			}
//=============================================================================================================
			//scanf("%d", &newNodePtr->employeeDate.day);




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

			//Print employee details
			printf("\nID: %d \n", currentPtr->id);
			printf("Name: %s \n", currentPtr->name);
			printf("Address: %s\n", currentPtr->address);
			printf("Department: %s\n", currentPtr->department);
			printf("Day: %d\n", currentPtr->employeeDate.day);
			printf("Month: %d\n", currentPtr->employeeDate.month);
			printf("Year: %d\n", currentPtr->employeeDate.year);

			printf("\n\n");

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

//----------------Error message was printing all the time even though delete function was working fine----------------------------------------------------------

	/*
	else//(currentPtr == NULL)//Print error message if ID can't be found
	{

		printf("ID number is not in the list\n\n");

	}
	*/

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
}//End deleteEmployee

//Pass in headPtr as it's the start of the list
int uniqueIDSearch(struct employee *headPtr, int searchNumber)
{
	//Loop if headPtr is not null
	while (headPtr != NULL)
	{
		//Compare the user entered number with id's already in list
		if (searchNumber == headPtr->id)
		{
			printf("Sorry ID already taken, please enter a new number\n\n");
			return NULL;

		}//End if

		headPtr = headPtr->nextPtr;//Move to next node

	}//End while

	return searchNumber;

}//End uniqueIDSearch

int date()
{

	int day;

	//Flush buffer before next input
	fflush(stdin);

	printf("Enter date\n\nDay First\n");
	scanf("%d", &day);

	if (day > 0 && day <= 31)
	{

		return day;

	}

	return NULL;

}//End date function






