//Christy Madden - 17/3/15

/*
=============================================================NOTES================================================================

------------------------1. When wrong details enterd in addEmployee it still saves in a list and needs to be deleted--------------

------------------------2. A lot of validation needed in addEmployee--------------------------------------------------------------

------------------------3. Update Employees section done but no validation on new data entered------------------------------------

------------------------4. Display all employees function done, is case sensitive at the moment-----------------------------------

------------------------5. Employee report is finished, need to write out to files though-----------------------------------------

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
	//Points to start of the list
	struct employee *headPtr = NULL;
	int tempNumber, validationNum, correctUserCoice, updateId;
	char departmentName[15];

	populateLinkedList(&headPtr);

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
				//printf("Insert Update employee function");
				printf("Enter ID to you want to update\n");
				scanf("%d", &updateId);

				if (updateId >= 0 && updateId <= 10000)
				{


					updateIdSearch(headPtr, updateId);
					//Will check if number is unique or not
					//validationNum = uniqueIDSearch(headPtr, tempNumber);

				}
				else
				{

					//Error Message
					printf("Incorrect ID start again\n\n");
					break;

				}//End else
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
				//printf("Insert Display all employees by department function ");
				printf("Enter department\n");
				scanf("%s", departmentName);

				searchDepartment(headPtr, departmentName);
				break;

			case 6:
				//printf("Insert Display employee report function ");
				printf("Enter department\n");
				scanf("%s", departmentName);

				employeeReport(headPtr, departmentName);
				break;

			default:
				//Print out linked list to file
				printEmployeesDatabase(headPtr);
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

	double salary;

	char email[40];

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

			printf("Enter salary\n");
			scanf("%lf", &salary);

			if (salary >= 0 && salary <= 10000000)
			{

				newNodePtr->annualSalary = salary;

			}
			else
			{

				printf("That is invalid for salary must be between 1 and 10000000");

			}
	
			printf("Enter email address\n");
			scanf("%s", newNodePtr->email);

			newNodePtr->nextPtr = NULL;//This node is last in list, currently doesn't link to another node

			previousPtr = NULL;//previousPtr doesn't point to anything

			currentPtr = *headPtr;//currentPtr ponits to begining of list, headPtr is null in begining

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

		printf("There are no employees\n\n");

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
			printf("Annual Salary: %.2lf\n", currentPtr->annualSalary);//Prints to 2 decimal places
			printf("Email: %s\n", currentPtr->email);

			printf("\n\n");

			currentPtr = currentPtr->nextPtr;

		}//End while

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

//Testing
void updateIdSearch(struct employee *headPtr, int searchNumber)
{

	int choice = 0;

	//Loop if headPtr is not null
	while (headPtr != NULL)
	{
		//Compare the user entered number with id's already in list
		if (searchNumber == headPtr->id)
		{


			printf("What would you like to update\n\n");
			printf("1.Address\n2.Department\n3.Salary\n");

			scanf("%d", &choice);

			if (choice >= 1 && choice <= 3)
			{ 
				
			
				if (choice == 1)
				{

					printf("Enter new address\n");
					scanf("%s", headPtr->address);

				}
				else if (choice == 2)
				{

					printf("Enter new Department\n");
					scanf("%s", headPtr->department);

				}
				else if (choice == 3)
				{

					printf("Enter new Salary\n");
					scanf("%lf", &headPtr->annualSalary);

				}//End else if  

			}//End nested if
			else
			{

				printf("Invalid option\n\n");

			}

		}//End if
		else
		{

			printf("ID isn't in database\n\n");

		}//End else
		
		headPtr = headPtr->nextPtr;//Move to next node

	}//End while



}//End updateIdSearch


void searchDepartment(struct employee *headPtr, char departmentName[])
{

	while (headPtr != NULL)
	{

		//Compare strings, 0 means true, this is case sensitive
		if (strcmp(departmentName, headPtr->department) == 0)
		{
			//Print out deatils of this employee
			printf("\nID: %d \n", headPtr->id);
			printf("Name: %s \n", headPtr->name);
			printf("Address: %s\n", headPtr->address);
			printf("Department: %s\n", headPtr->department);
			printf("Day: %d\n", headPtr->employeeDate.day);
			printf("Month: %d\n", headPtr->employeeDate.month);
			printf("Year: %d\n", headPtr->employeeDate.year);
			printf("Annual Salary: %.2lf\n", headPtr->annualSalary);//Prints to 2 decimal places
			printf("Email: %s\n", headPtr->email);

			

		}//End if
		else
		{

			printf("No department by that name\n\n");

		}

		headPtr = headPtr->nextPtr;//Move to next node

	}//End while

}//End searchDepartment

void employeeReport(struct employee *headPtr, char departmentName[])
{

	int employeeCounter = 0, year;
	double totalSalary = 0, totalBonus = 0, salary = 0, singleBonus = 0, totalCost = 0;

	//Create file pointer
	FILE *fp;

	//Create and open txt file
	fp = fopen("employeeRecord.txt", "w");

	//Error message
	if (fp == NULL)
	{

		printf("No file found");

	}


	while (headPtr != NULL)
	{

		//Compare strings, 0 means true, this is case sensitive
		//Searches for department
		if (strcmp(departmentName, headPtr->department) == 0)
		{
			
			//add up employees, save to new variable 
			employeeCounter++;

			//Calculate total salary, save to new variable
			totalSalary += headPtr->annualSalary;

			//Bonuses - take date away from 2015, then calculate bonuses
			salary = headPtr->annualSalary;

			//Get year of employment
			year = headPtr->employeeDate.year;

			//calculate bonus
			singleBonus = bonusCalculater(year, salary);
			
			//Add up all bonuses
			totalBonus += singleBonus;

		}//End if
		else
		{

			printf("No department by that name\n\n");

		}

		headPtr = headPtr->nextPtr;//Move to next node

	}//End while

	//Print Results

	//Header of employee report
	printf("\n\n\t\tEmployee Report\n\t\t***************\n\n");

	//Print figures for employee report
	printf("\tNumber of employees: %d\n", employeeCounter);
	printf("\tTotal salary: %.2lf\n", totalSalary);
	printf("\tTotal bonus: %.2lf\n", totalBonus);
	printf("\tTotal cost: %.2lf\n\n", (totalSalary + totalBonus));

	//Print to file
	fprintf(fp, "Employee Report\n***************\n\n");
	fprintf(fp, "Number of employees: %d\n", employeeCounter);
	fprintf(fp, "Total salary: %.2lf\n", totalSalary);
	fprintf(fp, "Total bonus: %.2lf\n", totalBonus);
	fprintf(fp, "Total cost: %.2lf\n\n", (totalSalary + totalBonus));

	//Close file
	fclose(fp);

}//End employeeReport

double bonusCalculater(int year, double salary)
{

	//Calculates how many years and employee has been there
	int numOfYears = 2015 - year;

	//Calculates bonus
	if (numOfYears > 10)
	{
		salary *= .05;
	}
	else if (numOfYears >= 5 && numOfYears <= 10)
	{
		salary *= .04;
	}
	else
	{
		salary *= .03;
	}

	return salary;

}//End bonusCalculater


void populateLinkedList(struct employee **headPtr)
{

	//Create file pointer
	FILE *fp;

	struct employee *newNodePtr;//Pointer to a new node

	struct employee *previousPtr;//Points to previous node in the list

	struct employee *currentPtr;//Points to current node in the list

	//Open txt file in read mode
	if ((fp = fopen("Database.dat", "r")) == NULL)
	{

		printf("File could not be opened\n");

	}	
	
	newNodePtr = (struct employee*)malloc(sizeof(struct employee));//Creates a new node

	while (fscanf(fp, "%d%s%s%s%d%d%d%lf%s", &newNodePtr->id, newNodePtr->name, newNodePtr->address, newNodePtr->department, &newNodePtr->employeeDate.day, &newNodePtr->employeeDate.month, &newNodePtr->employeeDate.year, &newNodePtr->annualSalary, newNodePtr->email) == 9)
	{

		//Scan in data from file
		//fscanf(fp, "%d%s%s%s%d%d%d%lf%s", &newNodePtr->id, newNodePtr->name, newNodePtr->address, newNodePtr->department, &newNodePtr->employeeDate.day, &newNodePtr->employeeDate.month, &newNodePtr->employeeDate.year, &newNodePtr->annualSalary, newNodePtr->email);

		printf("%d %s %s %s %d %d %d %.2lf %s\n\n", newNodePtr->id, newNodePtr->name, newNodePtr->address, newNodePtr->department, newNodePtr->employeeDate.day, newNodePtr->employeeDate.month, newNodePtr->employeeDate.year, newNodePtr->annualSalary, newNodePtr->email);

		newNodePtr->nextPtr = NULL;//This node is last in list, currently doesn't link to another node

		previousPtr = NULL;//previousPtr doesn't point to anything

		currentPtr = *headPtr;//currentPtr ponits to begining of list

		//First time around currentPtr will be NULL
		while (currentPtr != NULL && newNodePtr->id > currentPtr->id)
		{

			previousPtr = currentPtr;//Assign currentPtr to previousPtr

			currentPtr = currentPtr->nextPtr;//Assign next pointer to currentPtr

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

		newNodePtr = (struct employee*)malloc(sizeof(struct employee));//Creates a new node

	}//End while

	fclose(fp);//Close file

}//End populateLinkedList()

void printEmployeesDatabase(struct employee *currentPtr)
{

	//Create file pointer
	FILE *fp;

	//Open file in write mode
	if((fp = fopen("Database.dat", "w")) == NULL)
	{

		printf("File could not be opened\n");

	}//End if
	else
	{

		while (currentPtr != NULL)
		{
			//Write out data to file
			fprintf(fp, "%d %s %s %s %d %d %d %.2lf %s\n", currentPtr->id, currentPtr->name, currentPtr->address, currentPtr->department, currentPtr->employeeDate.day, currentPtr->employeeDate.month, currentPtr->employeeDate.year, currentPtr->annualSalary, currentPtr->email);

			currentPtr = currentPtr->nextPtr;//Move on to next node in linked list

		}//End while

		//rewind(fp);//Send pointer back to start file

		fclose(fp);//Close file

	}//End else

}//End printEmployeesDatabase







/*

//Run until it's end of file
//!feof(fp)
while (fscanf(fp, "%d%s%s%s%d%d%d%lf%s", &newNodePtr->id, newNodePtr->name, newNodePtr->address, newNodePtr->department, &newNodePtr->employeeDate.day, &newNodePtr->employeeDate.month, &newNodePtr->employeeDate.year, &newNodePtr->annualSalary, newNodePtr->email) == 9)
{

newNodePtr = (struct employee*)malloc(sizeof(struct employee));//Creates a new node

fscanf(fp, "%d%s%s%s%d%d%d%lf%s", &newNodePtr->id, newNodePtr->name, newNodePtr->address, newNodePtr->department, &newNodePtr->employeeDate.day, &newNodePtr->employeeDate.month, &newNodePtr->employeeDate.year, &newNodePtr->annualSalary, newNodePtr->email);


newNodePtr->nextPtr = NULL;//This node is last in list, currently doesn't link to another node

previousPtr = NULL;//previousPtr doesn't point to anything

currentPtr = *headPtr;//currentPtr ponits to begining of list


//First time around currentPtr will be NULL
while (currentPtr != NULL && newNodePtr->id > currentPtr->id)
{

previousPtr = currentPtr;//Assign currentPtr to previousPtr

currentPtr = currentPtr->nextPtr;//Assign next pointer to currentPtr

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
}//End else

}//End while

*/

/*

//Repeat so last entry is entered into linked list

newNodePtr->nextPtr = NULL;//This node is last in list, currently doesn't link to another node

previousPtr = NULL;//previousPtr doesn't point to anything

currentPtr = *headPtr;//currentPtr points to begining of list

//First time around currentPtr will be NULL
while (currentPtr != NULL && newNodePtr->id > currentPtr->id)
{

previousPtr = currentPtr;//Assign currentPtr to previousPtr

currentPtr = currentPtr->nextPtr;//Assign next pointer to currentPtr

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

*/