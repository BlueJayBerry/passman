#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void Create();
void Read();
void Update();
void Delete();
void Login();
void Signup();
bool IsPassValid();
void OpeningScreen();
void MainScreen(char[]);


int main(){
	OpeningScreen();
}

void Clear(){
	system("cls");
}

struct user_data{
	char username[20];
	char email[30];
	char password[30];
};

//Handles user registration
void OpeningScreen(){
	int option;
	printf("Welcome to passman");
	printf("\n\n1.Login");
	printf("\n2.Signup");
	printf("\nSelect an option: ");
	scanf("%d",&option);
	
	switch(option){
		case 1:
			Clear();
			Login();
			printf("You're logged in");
			break;
		case 2:
			Clear();
			Signup();
			break;
		default:
			printf("\nInvalid option - try again:\n");
			OpeningScreen();
			break;
	}
	
}

void Signup(){
	struct user_data sign_up;
	FILE* user_ptr = fopen("files/user.txt","a");
	FILE* num_user_ptr = fopen("files/num_user.txt","w");
	int file_size;
	
	if(user_ptr == NULL || num_user_ptr == NULL)
	{printf("File failed to open.\nRestart program after rectifying problem\n");}
	
	//Checks if user.txt is empty and adds headers if it is
	fseek(user_ptr,0,SEEK_END);
	file_size = ftell(user_ptr);
	fseek(user_ptr,0,SEEK_SET);
	
	if(file_size == 0)
	{fprintf(user_ptr,"%-12s %-12s","Username","Password");}

	//checks if num_user.txt is empty and write zero if it is
	fseek(num_user_ptr,0,SEEK_END);
	file_size = ftell(num_user_ptr);
	fseek(num_user_ptr,0,SEEK_SET);
		
	if(file_size ==0) fprintf(num_user_ptr,"%d",0);
	
	printf("Enter a new username and password for passman\n");
	printf("Username: ");
	scanf("%s", sign_up.username);
	printf("\nPassword: ");
	scanf("%s", sign_up.password);
	
	if(IsPassValid(sign_up.password))
	{fprintf(user_ptr,"\n%-12s %-12s",sign_up.username,sign_up.password);
	 fclose(user_ptr);
	 Clear();
	 MainScreen(sign_up.username);}
	else
	{fclose(user_ptr);
	 Clear();
	 printf("Invalid password \n-password must be at least 7 characters\nand include a number, a lowercase letter and an uppercase letter\n");
	 OpeningScreen();}
}

/*checks if password is valid
  password must be at least 7 characters
  and include a number,
  a lowercase letter and
  an uppercase letter*/
bool IsPassValid(char password[]){
	int lower_amount,upper_amount,digit_amount =0;
	for(int i =0; i <= strlen(password); i++){
		if(password[i]>= 'a' && password[i] <= 'z')
		{++lower_amount;}
		else if(password[i] >= 'A' && password[i] <= 'Z')
		{++upper_amount;}
		else if(password[i] >= '0' && password[i] <= '9')
		{++digit_amount;}
	}
	if
	(strlen(password) >=7 && lower_amount >0 
	&& upper_amount >0 && digit_amount >0)
	{return true;}
	else
	{return false;}
}

void Login(){
	struct user_data log_in;	
	printf("Enter an existing username and password for passman\n");
	printf("Username: ");
	scanf("%s", log_in.username);
	printf("\nPassword: ");
	scanf("%s", log_in.password);
}

//Navigates between the CRUD functions
void MainScreen(char username[]){
	int option;
	
	printf("Username: %s", username);
	printf("\n\n1.Create password");
	printf("\n2.List all password");
	printf("\n3.Update password");
	printf("\n4.Delete password");
	printf("\n5.Exit");
	printf("\nSelect an option: ");
	scanf("%d",&option);
	
	switch(option){
		case 1:
			Clear();
			Create();
			break;
		case 2:
			Clear();
			Read();
			break;
		case 3:
			Clear();
			Update();
			break;
		case 4:
			Clear();
			Delete();
			break;
		case 5:
			Clear();
			exit(1);
			break;	
		default:
			printf("Invalid option - try again");
			MainScreen(username);
			break;
	}
}


//CRUD functions
void Create(){
	printf("Password Created");
}
void Read(){
	printf("Password Read");
}
void Update(){
	printf("Password Updated");
}
void Delete(){
	printf("Password Deleted");
}