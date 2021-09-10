#include <stdio.h>
#include <windows.h> //for gotoxy() function
#include <conio.h> // using for delay(), getch() etc.
#include <ctype.h> // using for toupper(),tolower() etc.
#include <string.h> // using for strcmp(),strcpy(),strlen() etc.
#include <stdlib.h>
typedef enum {false, true} bool;
char ans=0;
int ok;
int iterator;
bool valid=false;
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
	char gender[2];
	char firstName[20];
	char lastName[20];
	char contactNo[15];
	char address[70];
	char email[30];
	char doctor[20];
	char problem[20];
};

struct patient p, temp_c; // creating structure variable p for struct patient
main(void)
{
 	system("color 0c"); //this will change the foreground color to Red in executable file
	welcomeScreen(); //calling welcomeScreen function()
	title(); //calling title function()
	loginScreen(); //calling loginScreen function()
}	

/* ---------------------------- Welcome Screen ----------------------- */

void welcomeScreen(void) //function for creating Welcome Screen
{
	printf("\n\n\n\n\t\t   ----------------------");
	printf(" Welcome to Hospital Management System -----------------                       \n");
	printf("\n\t\t\t\t\t    Press any key to continue...\n");
	getch();
	system("cls"); //used to clear screen
//	mainMenu();
}

void title(void)
{
	printf("\n\n\t\t------------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t\t   HOSPITAL MANAGEMENT SYSTEM   ");
	printf("\n\t\t\t Created by: Harshit Sharma, 1910990073 (Group 11 UCA-Batch A)");
	printf("\n\n\t\t------------------------------------------------------------------------------------");
}

void mainMenu(void)
{
	system("cls");
	int option;
	title();
	printf("\n\n\t\t 1. Add new patient's record\n");
	printf("\n\n\t\t 2. List patients records\n");
	printf("\n\n\t\t 3. Search patients record\n");
	printf("\n\n\t\t 4. Edit patients record\n");
	printf("\n\n\t\t 5. Delete patients record\n");
	printf("\n\n\t\t 6. Exit\n");
	printf("\n\n\t\t Choose an option from the menu above [1 to 6] :\n");
	scanf("%i",&option);
	switch(option){
		case 1:
			addRecord();
			break;
		case 2:
			functionList();
			break;
		case 3:
			searchRecord();
			break;
		case 4:
			editRecord();
			break;
		case 5:
//			deleteRecord();
			break;
		case 6:
			exitFunction();
			break;
		default:
			printf("\t\t Invalid entry. Please enter a valid option :-p");
			getch();
	}
	
}

/* ---------------------------------------Exit Screen------------------------------- */
void exitFunction(void) //function to exit screen
{
	system("cls");
	title();
	printf("\n\n\n\t\t Thank you for using this database application :)");
	getch();
}

/* -------------------------------------Login Screen------------------------ */
void loginScreen(void) 
{
	// list of variables
	int loginAttempts=0;
	char user[15];
	char pass[15];
	char admin_user[20]="harshit";
	char admin_pass[20]="G11-UCA_hs";
	do{
		printf("\n\n\n\t\t\t Enter your username & password to proceed !");
		printf("\n\n\t\t\t\t Username: ");
		scanf("%s",user);
		printf("\n\n\t\t\t\t Password: ");
		scanf("%s",pass);
	if(strcmp(user,admin_user)==0 && strcmp(pass,admin_pass)==0)
	{
		printf("\n\n\t\t\t ---- Login successful ----");
		getch();
		mainMenu(); //call mainMenu function
		break;	
	}
	else
	{
		printf("\n\t\t\t Incorrect credentials, please check again.");
		loginAttempts++;
		getch();
	}
  }
  while(loginAttempts<=2);
  if(loginAttempts>2)
  {
  	printf("You have crossed the number of login attempts. You cannot try again, make sure to get COVID-19 Vaccine ;-)");
  	getch();
  	exitFunction();
  }
  system("cls");
}

/* ------------------------------- Add new record ----------------------------- */
void addRecord(void)
{
	system("cls");
	title(); // call to title function
	// list of variables
	char ans;
	FILE *file_pointer;
	file_pointer=fopen("recordDB.txt","a"); // opening a file named recordDB.dat in write mode
	printf("\n\n\t\t\t Add new patient's record \n");
	// First Name
	get_fName:
		printf("\n\t\t\t First Name: ");
		scanf("%s",p.firstName);
		p.firstName[0]=toupper(p.firstName[0]);
		if(strlen(p.firstName)>20 || strlen(p.firstName)<2)
		{
			printf("\n\t Invalid name entry :-( \t Please enter a valid First Name.");
			goto get_fName;
		}
		else{
			for(iterator=0;iterator<strlen(p.firstName);iterator++)
			{
				if(isalpha(p.firstName[iterator]))
				{
					valid=true;
				}
				else
				{
					valid=false;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t First name contains INVALID CHARACTER :( Try entering again.");
				goto get_fName;
			}
		}
		/* -------------------------------------- Last Name ------------------------------------- */
		get_lName:
		printf("\n\t\t Last Name: ");
		scanf("%s",p.lastName);
		p.lastName[0]=toupper(p.lastName[0]);
		if(strlen(p.lastName)>20 || strlen(p.lastName)<2)
		{
			printf("\n\t Invalid name entry :-( \t Please enter a valid Last Name.");
			goto get_lName;
		}		
		else{
		  for(iterator=0;iterator<strlen(p.lastName);iterator++)
			{
				if(isalpha(p.lastName[iterator]))
		 		{
					valid=true;
				}
				else
				{
					valid=false;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Last name contains INVALID CHARACTER :( Try entering again.");
				goto get_lName;
			}
	}
			/* ------------------------------ Gender -------------------------- */
	
	do{
		printf("\n\t\t Gender[M/F]:");
		getchar();
		scanf("%s",p.gender);	
		if(toupper(p.gender[0])=='M'||toupper(p.gender[0])=='F') 
		{
			valid=true;	
		}
		else{
			valid=false;
		}
		if(!valid)
		{
			printf("\n\t\t Gender contains Invalid character :( Please enter either M or F:");
		}
	}while(!valid);
	/* ----------------------- Age ----------------- */
	printf("\n\t\t Age: ");
	scanf("%d",&p.age);
	/* ----------------------- Address -------------------- */
	do{
		getAddress:
			printf("\n\t\t\t Address: ");
					getchar();
			gets(p.address);	
			p.address[0]=toupper(p.address[0]);
			if(strlen(p.address)>70 || strlen(p.address)<5)
			{
				printf("\n\t Invalid address :( Please try entering a correct address.");
				valid=false;
				goto getAddress;
			}
			valid=true;
	 }while(!valid);
	/* ------------------------ Contact No. ----------------------- */
	do{
		getContactNo:
				printf("\n\t\t Contact No. : ");
				gets(p.contactNo);
				if(strlen(p.contactNo)<8){
					printf("Enter a valid contact no. : ");
					goto getContactNo;
				}
				else
				{
					for(iterator=0;iterator<10;iterator++)
					{
						if(!isalpha(p.contactNo[iterator]))
						{
							valid=true;
						}
						else{
							valid=false;
							break;
						}
					}
					if(!valid)
					{
						printf("\n\t\t Contact no. contains certain Invalid Character :( Try entering again: ");
						goto getContactNo;
					}
							}			
	}while(!valid);
	
	/* --------------------------- Email ------------------------- */
	do{
		printf("\n\t\t Email: ");
		scanf("%s",p.email);
		if(strlen(p.email)>30 || strlen(p.email)<8)
			{
				printf("\n\t Invalid email id ! Please check again.");
			}
	}while(strlen(p.email)>30 || strlen(p.email)<8);
		/* ---------------------- Problem -------------------- */
		getProblem:
			printf("\n\t\t What problem is the patient facing ? ");
			getchar();
			scanf("%s",p.problem);
			p.problem[0]=toupper(p.problem[0]);
			if(strlen(p.problem)>15 || strlen(p.problem)<3)
		{
			printf("\n\t Invalid entry :( Please try again.");
			goto getProblem;
		}
			else{
				for(iterator=0;iterator<strlen(p.problem);iterator++){
					if(isalpha(p.problem[iterator]))
					{
						valid=true;
					}
					else
					{
						valid=false;
						break;
					}
				}
				if(!valid)
				{
					printf("\n\t\t Mentioned problem contains invalid character, please check again .");
					goto getProblem;
				}
			}
		/* ------------------------- Presribed Doctor ------------------------- */
		getDoctor:
			printf("\n\t\t\t Prescribed Doctor: ");
			getchar();
			gets(p.doctor);
			p.doctor[0]=toupper(p.doctor[0]);
			if(strlen(p.doctor)>30 || strlen(p.doctor)<3)
			{
				printf("\n\t Invalid doctor entry, please try again.");
				goto getDoctor;
			}
			else{
				for(iterator=0;iterator<strlen(p.doctor);iterator++)
				{
					if(isalpha(p.doctor[iterator]))
					{
						valid=true;
					}
					else
					{
						valid=false;
						break;
					}
				}
				if(!valid)
				{
					printf("\n\t\t Doctor name contains invalid character :(");
					goto getDoctor;
				}
			}
			fprintf(file_pointer,"%s %s %s %d %s %s %s %s %s\n",p.firstName,p.lastName,p.gender,p.age,p.address,p.contactNo,p.email,p.problem,p.doctor);
			printf("\n\n\t\t\t ------------ Information Recorded successfully ---------------");
			fclose(file_pointer);
			check:
				getch();
				printf("\n\n\t\t\tDo you want to add more[Y/N]?");
				scanf(" %c",&ans);
				if(toupper(ans)=='Y'){
					addRecord();					
				}
				else if(toupper(ans)=='N'){
						printf("\n\t\t Thankyou :)");
						getch();
						mainMenu();
				}
				else{
					printf("\n\t\tInvalid Input\n");
					goto check;
				}
		}

/* ------------------- View Record ------------------- */
void functionList()
{
	int row;
	system("cls");
	title();
	FILE *file;
	file=fopen("recordDB.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Contact No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Problem");
		gotoxy(98,15);
		printf("Prescribed Doctor\n");
		printf("=================================================================================================================");
		row=17;
		while(fscanf(file,"%s %s %s %d %s %s %s %s %s\n", p.firstName, p.lastName, p.gender, &p.age, p.address, p.contactNo, p.email, p.problem, p.doctor)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.firstName, p.lastName);
			gotoxy(20,row);
			printf("%s",p.gender);
			gotoxy(32,row);
			printf("%d",p.age);
			gotoxy(37,row);
			printf("%s",p.address);
			gotoxy(49,row);
			printf("%s",p.contactNo);
			gotoxy(64,row);
			printf("%s",p.email);
			gotoxy(88,row);
			printf("%s",p.problem);
			gotoxy(98,row);
			printf("%s",p.doctor);
			row++;
		}
	fclose(file);
	getch();
	mainMenu();
}
void searchRecord(void)
{
	char name[20];
	system("cls");
	title();
	FILE *file;
	file=fopen("recordDB.txt","r");
	printf("\n\n\t\t!!!!!!!!! Search Patient's Record !!!!!!!!!!!\n");
//	gotoxy(12,8);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
while(fscanf(file,"%s %s %s %d %s %s %s %s %s\n", p.firstName, p.lastName, p.gender, &p.age, p.address, p.contactNo, p.email, p.problem, p.doctor)!=EOF)
	{
		if(strcmp(p.firstName,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Problem");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.firstName, p.lastName);
			gotoxy(25,18);
			printf("%c",p.gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.address);
			gotoxy(52,18);
			printf("%s",p.contactNo);
			gotoxy(64,18);
			printf("%s",p.email);
			gotoxy(80,18);
			printf("%s",p.problem);
			gotoxy(95,18);
			printf("%s",p.doctor);
			printf("\n");
			break;
		}
	}
	if(strcmp(p.firstName,name)!=0)
	{
//		gotoxy(5,10);
		printf("\nRecord not found !");
		getch();
	}
	fclose(file);
	L:
		getch();
		printf("\n\n\t\t\tDo you want to view more[Y/N]?");
		scanf("%c",&ans);
		if(toupper(ans)=='Y')
		{
			searchRecord();
		}
		else if(toupper(ans)=='N')
		{
			printf("\n\t\t Thank you :) ");
			getch();
			mainMenu();
		}
		else{
			printf("\n\t Invalid Input. \n");
			goto L;
		}
}
void editRecord(void)
{
	FILE *ek, *ft;
  	int i,b, validd=0;
  	char ch;
  	char name[20];
	system("cls");
  	title();
 	ft=fopen("tempFile.txt","w+");
	ek=fopen("recordDB.txt","r");
	if(ek==NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		mainMenu();
	}
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,13);
	printf("Enter the First Name of the Patient : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL)
	{
		printf("\n Can not open file");
		getch();
		mainMenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, &p.gender, &p.age, p.address, p.contactNo, p.email, p.problem, p.doctor)!=EOF)
	{
		if(strcmp(p.firstName, name)==0)
		{
			validd=1;
			gotoxy(25,17);
			printf("*** Existing Record ***");
			gotoxy(10,19);
			printf("%s \t%s \t%s \t%d \t%s \t%s \t%s \t%s \t%s\n",p.firstName,p.lastName,p.gender, p.age,p.address,p.contactNo,p.email,p.problem,p.doctor);
			gotoxy(12,22);	
			printf("Enter New First Name: ");
			scanf("%s",p.firstName);    
			gotoxy(12,24);
			printf("Enter Last Name: ");
			scanf("%s",p.lastName);
			gotoxy(12,26);
			printf("Enter Gender: ");
			scanf(" %s",p.gender);
			p.gender[0]=toupper(p.gender[0]);
			gotoxy(12,28);				
			printf("Enter age: ");
			scanf(" %d",&p.age);
			gotoxy(12,30);
			printf("Enter Address: ");
			scanf("%s",p.address);
			p.address[0]=toupper(p.address[0]);
			gotoxy(12,32);
			printf("Enter Contact no: ");
			scanf("%s",p.contactNo);
			gotoxy(12,34);
			printf("Enter New email: ");
			scanf("%s",p.email);
			gotoxy(12,36);
			printf("Enter Problem: ");
			scanf("%s",p.problem);
			p.problem[0]=toupper(p.problem[0]);
			gotoxy(12,38);
			printf("Enter Doctor: ");
			scanf("%s",p.doctor);
			p.doctor[0]=toupper(p.doctor[0]);
			printf("\nPress U character for the Updating the data... ");
			ch=getche();
			if(ch=='u' || ch=='U')
			{
				fprintf(ft,"%s %s %s %d %s %s %s %s %s\n",p.firstName,p.lastName,p.gender, p.age,p.address,p.contactNo,p.email,p.problem,p.doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
			}					
		}
		else
		{
			fprintf(ft,"%s %s %s %d %s %s %s %s %s\n",p.firstName,p.lastName,p.gender, p.age,p.address,p.contactNo,p.email,p.problem,p.doctor);	
		}
	}
	if(!validd) 
	{
		printf("\n\t\tNO RECORD FOUND...");
	}
	fclose(ft);
	fclose(ek);
	remove("recordDB.txt");
   	rename("tempFile.txt","recordDB.txt");
	getch();
	mainMenu();		
}












	

