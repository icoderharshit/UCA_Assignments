#include <stdio.h>
#include <windows.h> //for gotoxy() function
#include <conio.h> // using for delay(), getch() etc.
#include <ctype.h> // using for toupper(),tolower() etc.
#include <string.h> // using for strcmp(),strcpy(),strlen() etc.
#include <stdlib.h>
char ans=0;
int ok;
int b,valid=0;
// Functions Declaration
void welcomeScreen(void); //welcomeScreen function()
void title(void); //Title function()
void mainMenu(void); //Main menu function()
void loginScreen(void); //Login Screen function()
void addRecord(void); //Add record function()
void functionList(); //Patient details function()
void searchRecord(void); //Search Record function()
void editRecord(void); //Edit Records function()
void deleteRecord(void); //Delete Record function()
void exitFunction(void); //Exit function()
void gotoxy(short x,short y)
{
	COORD pos= {x,y}; // sets co-ordinates in (x,y)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
// List of Global Variables
struct patient
{
	int age;
	char gender;
	char firstName[20];
	char lastName[20];
	char contactNo[15];
	char address[30];
	char email[30];
	char doctor[20];
	char problem[20];
};

struct patient p, temp_c; // creating structure variable p for struct patient

main(void)
{
	welcomeScreen(); //calling welcomeScreen function()
	title(); //calling title function()
	loginScreen(); //calling loginScreen function()
}

/* ---------------------------- Welcome Screen ----------------------- */

void welcomeScreen(void) //function for creating Welcome Screen
{
	printf("\n\n\n\n\t\t\t----------------------");
	printf("Welcome to Hospital Management System\t\t\t-----------------\n");
	printf("\n\t\t\t Press any key to continue...\n");
	getch();
	system("cls"); //used to clear screen
}































