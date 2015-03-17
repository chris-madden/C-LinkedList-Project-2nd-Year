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
	//Pointer variable points no where
	headPtr = NULL;

	
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
				addEmployee();
				break;

			case 2:
				//printf("Insert Display employee details function ");
				displayEmployees();
				break;

			case 3:
				printf("Insert Update employee function");
				break;

			case 4:
				printf("Insert Delete employee function ");
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

}

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

//Passed in address on headPtr from MAIN
void addEmployee()
{

	//Creating a new node
	struct employee *newNodePtr;

	//Assign memory to newPtr
	//Typecasting it means it points to the beginning address of the node
	//otherwise it would return a void pointer
	newNodePtr = (struct employee*)malloc(sizeof(struct employee));

	//Prompts user to enter an ID number
	printf("\n\nEnter an ID number\n");
	scanf("%d", &newNodePtr->id);

	//Set the nextPtr to NULL so it's not pointing to anything
	//This then makes the current node the last node
	newNodePtr->nextPtr = NULL;

	//Here you can put in an if statement checking if headPtr is = NULL
	if (headPtr != NULL)
	{

		//Build link to node which points to NULL
		newNodePtr->nextPtr = headPtr;
		
	}
	
	//This puts newNodePtr at the start of the linked list
	headPtr = newNodePtr;
	

	//newPtr->nextPtr = *startPtr;

	/*
	//User will enter a number to stop being asked to enter empoyee details
	int userContinue = 1;

	while (userContinue != 0)
	{

		//Allocate memory for new node, will be the size of struct which is renamed Employee
		currentPtr = malloc(sizeof(Employee));

		fflush(stdin);

		//Prompts user to enter an ID number
		printf("\n\nEnter an ID number\n");
		scanf("%d", &currentPtr->id);

		fflush(stdin);

		printf("Enter your name\n");
		scanf("%s", &currentPtr->name);

		fflush(stdin);

		printf("Enter your address\n");
		scanf("%s", &currentPtr->address);

		fflush(stdin);

		printf("Enter your department\n");
		scanf("%s", &currentPtr->department);

		fflush(stdin);

		printf("Enter date in format(dd/mm/yyyy)\n");
		scanf("%d%d%d", &currentPtr->employeeDate.day, &currentPtr->employeeDate.month, &currentPtr->employeeDate.year);

		fflush(stdin);

		printf("Enter your salary\n");
		scanf("%lf", &currentPtr->annualSalary);

		fflush(stdin);

		printf("Enter your email\n");
		scanf("%s", &currentPtr->email);

		if (headPtr = NULL)
		{

			//Need to put current pointer on the first or the last node
			//Adds to start of list
			headPtr = currentPtr;

		}
		else
		{
			//adds to end of list
			tailPtr = currentPtr;

			//Need to put current pointer on the first or the last node
			//This stops the linklist from ending  
			tailPtr->nextPtr = currentPtr;

		}

		//adds to end of list
		tailPtr = currentPtr;

		//Setting nextPtr to NULL so node does not link to another node 
		tailPtr->nextPtr = NULL;

		//Prints out the value of the date variable in the structure
		printf("\nNumber entered is %d\n", currentPtr->id);
		printf("\Name entered is %s\n", currentPtr->name);
		printf("\Address entered is %s\n", currentPtr->address);
		printf("\Department entered is %s\n", currentPtr->department);
		printf("\Date entered is %d/%d/%d\n", currentPtr->employeeDate.day, currentPtr->employeeDate.month, currentPtr->employeeDate.year);
		printf("\Salary entered is %.2lf\n", currentPtr->annualSalary);
		printf("\Email entered is %s\n", currentPtr->email);

		//Ask user if they want to add another employee
		printf("\n\nDo you want to add another employee?\n0: No\n1: Yes\n");
		scanf("%d", &userContinue);

		if (userContinue == 0)
		{

			menu();

		}
		
	}*/
	
}//End addEmployee function

void displayEmployees()
{

	struct employee *temp = headPtr;

	// This while loop will traverse the LinkedList using the next pointer and print out the 'data'
	while (temp != NULL)
	{

		// Print the data for the temp node
		printf("Id: %d\n", temp->id);

		// Sets the value of temp to the next node
		temp = temp->nextPtr;

	}


}//End displayEmployees function