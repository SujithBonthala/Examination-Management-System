#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header_File.h"
void CreateTeacherAcc()
{
	FILE *fp;
	fp=fopen("Teacher_Record.txt","a");
	if(fp==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		teacher *t;
		int n,i;
		printf("\nEnter the number of teacher records that needs to get created : ");
		scanf("%d",&n);
		t=(teacher*)calloc(n,sizeof(teacher));
		if(t==NULL)
		{
			printf("Error...Try again\n");
		}
		else
		{
			for(int i=0;i<n;i++)
			{	
				fflush(stdin);
				printf("\nEnter teacher %d's name : ",i+1);
				scanf("%[^\n]s",&t[i].Name);
				fflush(stdin);
				printf("Enter PRN of the teacher : ");
				scanf("%[^\n]s",&t[i].PRN);
				fflush(stdin);
				strcpy(t[i].Password,t[i].PRN);
				printf("Enter teacher's branch in short form using capital letters(Ex : CSE) : ");
				scanf("%s",&t[i].Branch);
				fflush(stdin);
				fwrite(&t[i],sizeof(teacher),1,fp);
			}
			printf("\nSuccessfully added %d teacher account(s)!\n",n);
		}
	}
	fclose(fp);
}
void NumberTeacherAcc()
{
	FILE *fp;
	fp=fopen("Teacher_Record.txt","r");
	teacher t;
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof(teacher);
	int choice=0;
	while(choice!=3)
	{
		printf("\nEnter 1 to display total number of teacher records\n");
		printf("Enter 2 to display number of teacher records based on the branch\n");
		printf("Enter 3 to go back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				rewind(fp);
				printf("\nNumber of teacher records present is %d\n",n);
				break;
			}
			case 2:
			{
				int res=0;
				rewind(fp);
				char branch[10];
				printf("\nEnter the Branch : ");
				fflush(stdin);
				scanf("%s",&branch);
				rewind(fp);
				while(fread(&t,sizeof(teacher),1,fp))
				{
					if(strcmp(t.Branch,branch)==0)
					{
						res++;
					}
				}
				printf("Number of teachers in Branch %s is %d\n",branch,res);
				break;
			}
		}
	}
	fclose(fp);
}
void SearchTeacherAcc()
{
	FILE *fp;
	fp=fopen("Teacher_Record.txt","r");
	rewind(fp);
	teacher t;
	if(fp==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		int choice=0;
		while(choice!=3)
		{
			printf("\nEnter 1 to search a teacher record based on his/her name\n");
			printf("Enter 2 to search a teacher record based on his/her PRN\n");
			printf("Enter 3 to go back\n");
			printf("Enter your choice : ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
				{
					char name[50];
					int found=0;
					rewind(fp);
					printf("Enter the Teacher's name : ");
					fflush(stdin);
					scanf("%[^\n]s",&name);
					while(fread(&t,sizeof(teacher),1,fp))
					{
						if(strcmp(t.Name,name)==0)
						{
							found=1;
							printf("\nTeacher record found!\n");
							printf("Teacher Details:\n");
							printf("Name : %s\n",t.Name);
							printf("PRN : %s\n",t.PRN);
							printf("Branch : %s\n",t.Branch);
						}
					}
					if(found==0)
					{
						printf("\nTeacher record count not be found.\n");
					}		
					break;
				}
				case 2:
				{
					char prn[50];
					int found=0;
					rewind(fp);
					printf("Enter the student's PRN : ");
					fflush(stdin);
					scanf("%[^\n]s",&prn);
					while(fread(&t,sizeof(teacher),1,fp))
					{
						if(strcmp(t.PRN,prn)==0)
						{
							found=1;
							printf("\nTeacher record found!\n");
							printf("Teacher Details:\n");
							printf("Name : %s\n",t.Name);
							printf("PRN : %s\n",t.PRN);
							printf("Branch : %s\n",t.Branch);
						}						
					}
					if(found==0)
					{
						printf("\nTeacher record could not be found.\n");
					}
					break;
				}
			}
		}
	}
	fclose(fp);
}
void UpdateTeacherAcc()
{
	int choice=0;
	while(choice!=3)
	{
		printf("\nEnter 1 to update Teacher's PRN\n");
		printf("Enter 2 to update Teacher's Branch\n");
		printf("Enter 3 to go back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				FILE *fp,*fp1;
				teacher t;
				fp=fopen("Teacher_Record.txt","r");
				fp1=fopen("Temp_Teacher_Record.txt","w");
				char name[50];
				printf("Enter Teacher's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
				}
				else
				{
					int found=0;
					while(fread(&t,sizeof(t),1,fp))
					{
						if(strcmp(t.Name,name)==0)
						{
							found=1;
							char prn[20];
							fflush(stdin);
							printf("Enter new PRN of the student : ");
							scanf("%[^\n]s",&prn);
							strcpy(t.PRN,prn);
						}
						fwrite(&t,sizeof(teacher),1,fp1);
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Teacher_Record.txt","w");
                				fp1=fopen("Temp_Teacher_Record.txt","r");
						while(fread(&t,sizeof(teacher),1,fp1))
						{
							fwrite(&t,sizeof(teacher),1,fp);
						}
						printf("Teacher record is updated succesfully!\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Teacher record could not be found.\n");
					}
					break;
				}
			}
			case 2:
			{
				FILE *fp,*fp1;
				teacher t;
				fp=fopen("Teacher_Record.txt","r");
				fp1=fopen("Temp_Teacher_Record.txt","w");
				char name[50];
				printf("Enter Teacher's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
				}
				else
				{
					int found=0;
					while(fread(&t,sizeof(t),1,fp))
					{
						if(strcmp(t.Name,name)==0)
						{
							found=1;
							char branch[10];
							printf("Enter new branch of the Teacher : ");
							scanf("%s",&branch);
							strcpy(t.Branch,branch);
						}
						fwrite(&t,sizeof(teacher),1,fp1);
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Teacher_Record.txt","w");
	                			fp1=fopen("Temp_Teacher_Record.txt","r");
						while(fread(&t,sizeof(teacher),1,fp1))
						{
							fwrite(&t,sizeof(teacher),1,fp);
						}
						printf("Teacher record is updated successfully!\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Teacher record could not be found.\n");
					}
					break;
				}
           		}
        	}        
    	}
}
void DeleteTeacherAcc()
{
	int choice=0;
	while(choice!=3)
	{
		printf("\nEnter 1 to delete a teacher account based on his/her name\n");
		printf("Enter 2 to delete a teacher account based on his/her PRN\n");
		printf("Enter 3 to go back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				FILE *fp,*fp1;
				teacher t;
				fp=fopen("Teacher_Record.txt","r");
				fp1=fopen("Temp_Teacher_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
				}
				else
				{
					char name[50];
					int found=0;
					printf("Enter the teacher's name : ");
					fflush(stdin);
					scanf("%[^\n]s",&name);
					while(fread(&t,sizeof(teacher),1,fp))
					{
						if(strcmp(t.Name,name)==0)
						{
							found=1;
						}
						else
						{
							fwrite(&t,sizeof(teacher),1,fp);
						}
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Teacher_Record.txt","w");
                				fp1=fopen("Temp_Teacher_Record.txt","r");
						while(fread(&t,sizeof(teacher),1,fp))
						{
							fwrite(&t,sizeof(teacher),1,fp);
						}
						printf("Teacher record is deleted successfully.\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Teacher record could not be found.\n");
					}
					break;
				}
			}
			case 2:
			{
				FILE *fp,*fp1;
				teacher t;
				fp=fopen("Teacher_Record.txt","r");
				fp1=fopen("Temp_Teacher_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
				}
				else
				{
					char prn[50];
					int found=0;
					printf("Enter the teacher's PRN : ");
					fflush(stdin);
					scanf("%[^\n]s",&prn);
					while(fread(&t,sizeof(teacher),1,fp))
					{
						if(strcmp(t.PRN,prn)==0)
						{
							found=1;
						}
						else
						{
							fwrite(&t,sizeof(teacher),1,fp);
						}
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Teacher_Record.txt","w");
                				fp1=fopen("Temp_Teacher_Record.txt","r");
						while(fread(&t,sizeof(teacher),1,fp))
						{
							fwrite(&t,sizeof(teacher),1,fp);
						}
						printf("Teacher record is deleted successfully.\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Teacher record could not be found.\n");
					}
					break;
				}
			}
		}
	}
}
void TeacherLogin()
{
	FILE *fp;
	fp=fopen("Teacher_Record.txt","r");
	teacher t1;
	char prn[50],pass[50];
	printf("Enter Username:");
	fflush(stdin);
	scanf("%[^\n]s",srn);
	printf("\nEnter the password:");
	fflush(stdin);
	scanf("%[^\n]s",pass);
	if(fp==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		int flag=0;
		rewind(fp);
		while(!feof(fp))
		{
			fread(&t1,sizeof(teacher),1,fp);
			if(strcmp(t1.PRN,prn)==0&&strcmp(t1.Password,pass)!=0)
			{		
				flag=1;
				break;
			}
			else if(strcmp(t1.PRN,prn)==0&&strcmp(t1.Password,pass)==0)
			{
				flag=2;
				break;
			}
		}
		if(flag==0)
		{
			printf("Username does not exist.\n");
			int choice=0;
			while(choice!=1&&choice!=2)
			{
				printf("Enter 1 to try again.\nEnter 2 to go back to Login Menu");
				scanf("%d",&choice);
			}
			if(choice==1)
			{
				TeacherLogin();
			}
			else if(choice==2)
			{
				LoginMenu();
			}
		}
		else if(flag==1)
		{
			printf("Incorrect Password.\n");
			int choice=0;
			while(choice!=1&&choice!=2)
			{
				printf("Enter 1 to try again.\nEnter 2 to go back to Login Menu");
				scanf("%d",&choice);
			}
			if(choice==1)
			{
				TeacherLogin();
			}
			else if(choice==2)
			{
				LoginMenu();
			}
		}
		else
		{
			TeacherMainMenu(prn);
		}
	}
}
void TeacherMainMenu(char prn)
{
	printf("\nLogged in successfully\n");
	printf("\nWELCOME, SELECT PROVIDED OPTIONS TO CONTINUE\n");
	int choice;
	while(choice!=4)
	{
		printf("Enter 1 to change the password\n");
		printf("Enter 2 to give attendance to students of a particular class\n");
		printf("Enter 3 to give grades to students of a particular class\n");
		printf("Enter 4 to logout\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				ChangeTeacherPassword(prn);
				break;
			}
			case 2:
			{
				GiveAttendance();
				break;
			}
			case 3:
			{
				GiveGrades();
				break;
			}
			case 4:
			{
				LoginMenu();
				break;
			}
		}
	}
}	
void ChangeTeacherPassword(char prn[])
{
	FILE *fp,*fp1;
  	teacher t1;
	char p[50];
	char t[50];
	printf("Enter New Password: ");
	fflush(stdin);
	scanf("%[^\n]s",p);
	printf("\nConfirm New password: ");
	fflush(stdin);
	scanf("%[^\n]s",t);
	if(strcmp(p,t)==0)
	{
		fp=fopen("Teacher_Record.txt","r");
		fp1=fopen("Temp_Teacher_Record.txt","w");
		if(fp==NULL||fp1==NULL)
		{
			printf("Error...Try again\n");
			fclose(fp);
			fclose(fp1);
		}
		else
		{
			while(fread(&t1,sizeof(t1),1,fp))
			{
				if(strcmp(t1.PRN,prn)==0)
				{
					fflush(stdin);
					strcpy(t1.Password,p);
				}
				fwrite(&t1,sizeof(teacher),1,fp1);
			}
			fclose(fp);
			fclose(fp1);
			fp=fopen("Teacher_Record.txt","w");
			fp1=fopen("Temp_Teacher_Record.txt","r");
			while(fread(&t1,sizeof(teacher),1,fp1))
			{
				fwrite(&t1,sizeof(teacher),1,fp);
			}
			printf("Password is updated successfully!\n");
			fclose(fp);
			fclose(fp1);
	 	}
	}
	else
	{
		printf("Password and confirmation password do not match. Try again...\n");
		ChangeTeacherPassword(prn);
	}	
}
void Giveattendance()
{
	char section
	printf("Enter the class to which attendance has to be given");
	scanf("%c",&section);
	int choice;
	printf("Enter 1 to display students information\n");
	printf("Enter 2 to give attendance to student of a particular section\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case1:
			displayAllInformation(section) ;
			break;
		case 2:
			givestudentattendance(section);
			break;		
	}
}
void displayAllInformation(char section) 
{		
	FILE *fp;
	int i,choice;
	fp=fopen("Student_Record.txt","r");
	student s1[100];
	if(fp==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		printf("Enter how many student records that has to be displayed\n");
		scanf("%d",&choice);
		for(i=0;i<choice;i++)
		{
			while(fread(&s1,sizeof(student),1,fp))
			{
				if(strcmp(s1.Section,section)==0)
				{
					printf("\nStudent records found!\n");
					printf("Student Details:\n");
					printf("Name : %s\n",s1[i].Name);
					printf("SRN : %s\n",s1[i].SRN);
					printf("Semester : %d\n",s1[i].Semester);
					printf("Branch : %s\n",s1[i].Branch);
				}
				else
				{
					printf("INVALID SECTION NAME\n");
				}
			}
		}
	}
		fclose(fp);
}		
	
void givestudentattendance(char section) 
{
		FILE *fp;
		fp=fopen("Student_Record.txt","r");
		student s1[100];
		int op,choice;
		char information[15];
		printf("Enter 1 to give attendance based on SRN\n");
		printf("Enter 2 to give attendance based on name\n");
		scanf("%d", &op);
		if (op == 1) 
		{
			printf ("Please enter the student SRN:");
			scanf("%s", information);
			printf("Enter how many students attendance must be given"\n);
			scanf("%d",&choice);
			for(int i=0;i<choice;i++)
			{	
				if (strcmp(information,[i].SRN) == 0)
				{ 
					int choice1;
					printf("Enter 1 to mark present\n");
					printf("Enter 2 to mark absent\n");
					scanf("%d",&choice);
					if(choice1==1)
					{
						s[i].No_Days_Present+=1;
						s[i].No_Days_Total+=1;
					}
					else if(choice==2)
					{
						s[i].No_Days_Total+=1;
					}
					else
					{
						printf("Enter 1 or 2... invalid input\n");
					}	
					}
 				}
			}
		else if (op == 2) 
		{
			printf ("Please enter the student's name:");
			scanf("%s", information);
			printf("Enter how many students attendance must be given"\n);
			scanf("%d",&choice);
			for(int i=0;i<choice;i++)
			{
				if (strcmp(information,s1[i].Name) == 0)
				{ 
					printf("Enter 1 to mark present\n");
					printf("Enter 2 to mark absent\n");
					scanf("%d",&choice);
					if(choice1==1)
					{
						s[i].No_Days_Present+=1;
						s[i].No_Days_Total+=1;
					}
					else if(choice==2)
					{
						s[i].No_Days_Total+=1;
					}
					else
					{
						printf("Enter 1 or 2... invalid input\n");
					}	
					}
 				}
			}
		 	printf ("Attendance is given\n");
}
void GiveGrades()
{
	prinf("Yet to do\n");
}
	

