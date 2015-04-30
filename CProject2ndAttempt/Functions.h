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

	//Date is held in a struct
	struct date employeeDate;

	//Double for the money employee makes in year
	double annualSalary;

	//Don't know what email will be in the future so leaving it as a string
	char email[40];

	int found;

	//Create struct pointer
	struct employee *nextPtr;

};

//Global
//struct employee *headPtr;

//istruct employee *employeePtr;

void menu();

//Global variable for user choice
int userChoice, deleteNumber;

//Prototypes
void addEmployee(struct employee **headPtr);

void displayEmployees(struct employee *currentPtr);

void deleteEmployee(struct employee **headPtr, int deleteNumber);

int uniqueIDSearch(struct employee **headPtr, int searchNumber);

void updateIdSearch(struct employee *headPtr, int searchNumber);

void searchDepartment(struct employee *headPtr, char departmentName[]);

void employeeReport(struct employee *headPtr, char departmentName[]);

double bonusCalculater(int year, double salary);

void populateLinkedList(struct employee *currentPtr);

void printEmployeesDatabase(struct employee *currentPtr);

int stringValidation(char * name);

void searchDepartmentNew(struct employee *headPtr, struct employee *comparePtr, struct employee *tempPtr);

void updateNameSearch(struct employee *headPtr, char * name);



