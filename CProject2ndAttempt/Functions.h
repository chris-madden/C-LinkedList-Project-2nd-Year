//Global structs
struct date
{

	int day;
	int month;
	int year;

};

//Struct that will be used for Employee details
//**This is shell for the linked list that makes up the employee database**
struct employee
{

	//Employee ID
	int id;

	//String that can hold name
	char name[30];

	//String to accept address
	char address[50];

	//String for department - may change to int later on
	char department[15];

	//This will need a structure in the future, leaving it as an int for now
	struct date employeeDate;

	//Double for the money employee makes in year
	double annualSalary;

	//Don't know what email will be in the future so leaving it as a string
	char email[40];

	//Create struct pointer
	struct employee *nextPtr;

};

//Global
//struct employee *headPtr;

//istruct employee *employeePtr;

void menu();

//Global variable for user choice
int userChoice;

void addEmployee(struct employee **headPtr);

void displayEmployees(struct employee *currentPtr);



