#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header_File.h"
void CreateStudentAcc()
{
	FILE *fp;
	fp=fopen("Student_Record.txt","a");
	if(fp==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		student *s;
		int n,i;
		printf("\nEnter the number of student records that needs to get created : ");
		scanf("%d",&n);
		s=(student*)calloc(n,sizeof(student));
		if(s==NULL)
		{
			printf("Error...Try again\n");
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				fflush(stdin);
				printf("\nEnter student %d's name : ",i+1);
				scanf("%[^\n]s",&s[i].Name);
				fflush(stdin);
				printf("Enter SRN of the student : ");
				scanf("%[^\n]s",&s[i].SRN);
				fflush(stdin);
				strcpy(s[i].Password,s[i].SRN);
				printf("Enter student's branch in short form using capital letters(Ex : CSE) : ");
				scanf("%s",&s[i].Branch);
				fflush(stdin);
				printf("Enter student's section : ");
				scanf("%c",&s[i].Section);
				fflush(stdin);
				printf("Enter student's semester : ");
				scanf("%d",&s[i].Semester);
				s[i].Courses.no_courses_sem1=8;
				s[i].Courses.no_courses_sem2=8;
				strcpy(s[i].Courses.sem1[0].Course_Code,"MA101");
				strcpy(s[i].Courses.sem1[0].Course_Name,"Engineering Mathematics - I");
				s[i].Courses.sem1[0].Credits=4;
				s[i].Courses.sem1[0].No_Days_Present=0;
				s[i].Courses.sem1[0].No_Days_Total=0;
				s[i].Courses.sem1[0].Eligibility=0;
				s[i].Courses.sem1[0].Grade='\0';
				strcpy(s[i].Courses.sem1[1].Course_Code,"CS101");
				strcpy(s[i].Courses.sem1[1].Course_Name,"Python for Computational Problem Solving");
				s[i].Courses.sem1[1].Credits=4;
				s[i].Courses.sem1[1].No_Days_Present=0;
				s[i].Courses.sem1[1].No_Days_Total=0;
				s[i].Courses.sem1[1].Eligibility=0;
				s[i].Courses.sem1[1].Grade='\0';
				strcpy(s[i].Courses.sem1[2].Course_Code,"PH101");
				strcpy(s[i].Courses.sem1[2].Course_Name,"Engineering Physics");
				s[i].Courses.sem1[2].Credits=4;
				s[i].Courses.sem1[2].No_Days_Present=0;
				s[i].Courses.sem1[2].No_Days_Total=0;
				s[i].Courses.sem1[2].Eligibility=0;
				s[i].Courses.sem1[2].Grade='\0';
				strcpy(s[i].Courses.sem1[3].Course_Code,"ME101");
				strcpy(s[i].Courses.sem1[3].Course_Name,"Mechanical Engineering Sciences");
				s[i].Courses.sem1[3].Credits=4;
				s[i].Courses.sem1[3].No_Days_Present=0;
				s[i].Courses.sem1[3].No_Days_Total=0;
				s[i].Courses.sem1[3].Eligibility=0;
				s[i].Courses.sem1[3].Grade='\0';
				strcpy(s[i].Courses.sem1[4].Course_Code,"EE101");
				strcpy(s[i].Courses.sem1[4].Course_Name,"Elements of Electrical Engineering");
				s[i].Courses.sem1[4].Credits=4;
				s[i].Courses.sem1[4].No_Days_Present=0;
				s[i].Courses.sem1[4].No_Days_Total=0;
				s[i].Courses.sem1[4].Eligibility=0;
				s[i].Courses.sem1[4].Grade='\0';
				strcpy(s[i].Courses.sem1[5].Course_Code,"EV101");
				strcpy(s[i].Courses.sem1[5].Course_Name,"Environmental Studies and Life Sciences");
				s[i].Courses.sem1[5].Credits=2;
				s[i].Courses.sem1[5].No_Days_Present=0;
				s[i].Courses.sem1[5].No_Days_Total=0;
				s[i].Courses.sem1[5].Eligibility=0;
				s[i].Courses.sem1[5].Grade='\0';
				strcpy(s[i].Courses.sem1[6].Course_Code,"PH102");
				strcpy(s[i].Courses.sem1[6].Course_Name,"Physics Laboratory");
				s[i].Courses.sem1[6].Credits=1;
				s[i].Courses.sem1[6].No_Days_Present=0;
				s[i].Courses.sem1[6].No_Days_Total=0;
				s[i].Courses.sem1[6].Eligibility=0;
				s[i].Courses.sem1[6].Grade='\0';
				strcpy(s[i].Courses.sem1[7].Course_Code,"CS102");
				strcpy(s[i].Courses.sem1[7].Course_Name,"Python for Computational Problem Solving Laboratory");
				s[i].Courses.sem1[7].Credits=1;
				s[i].Courses.sem1[7].No_Days_Present=0;
				s[i].Courses.sem1[7].No_Days_Total=0;
				s[i].Courses.sem1[7].Eligibility=0;
				s[i].Courses.sem1[7].Grade='\0';
				strcpy(s[i].Courses.sem2[0].Course_Code,"MA151");
				strcpy(s[i].Courses.sem2[0].Course_Name,"Engineering Mathematics - II");
				s[i].Courses.sem2[0].Credits=4;
				s[i].Courses.sem2[0].No_Days_Present=0;
				s[i].Courses.sem2[0].No_Days_Total=0;
				s[i].Courses.sem2[0].Eligibility=0;
				s[i].Courses.sem2[0].Grade='\0';
				strcpy(s[i].Courses.sem2[1].Course_Code,"CS151");
				strcpy(s[i].Courses.sem2[1].Course_Name,"Problem Solving with C");
				s[i].Courses.sem2[1].Credits=4;
				s[i].Courses.sem2[1].No_Days_Present=0;
				s[i].Courses.sem2[1].No_Days_Total=0;
				s[i].Courses.sem2[1].Eligibility=0;
				s[i].Courses.sem2[1].Grade='\0';
				strcpy(s[i].Courses.sem2[2].Course_Code,"CY101");
				strcpy(s[i].Courses.sem2[2].Course_Name,"Engineering Chemistry");
				s[i].Courses.sem2[2].Credits=4;
				s[i].Courses.sem2[2].No_Days_Present=0;
				s[i].Courses.sem2[2].No_Days_Total=0;
				s[i].Courses.sem2[2].Eligibility=0;
				s[i].Courses.sem2[2].Grade='\0';
				strcpy(s[i].Courses.sem2[3].Course_Code,"CV101");
				strcpy(s[i].Courses.sem2[3].Course_Name,"Engineering Mechanics - Statics");
				s[i].Courses.sem2[3].Credits=4;
				s[i].Courses.sem2[3].No_Days_Present=0;
				s[i].Courses.sem2[3].No_Days_Total=0;
				s[i].Courses.sem2[3].Eligibility=0;
				s[i].Courses.sem2[3].Grade='\0';
				strcpy(s[i].Courses.sem2[4].Course_Code,"EC101");
				strcpy(s[i].Courses.sem2[4].Course_Name,"Electronic Principles and Devices");
				s[i].Courses.sem2[4].Credits=4;
				s[i].Courses.sem2[4].No_Days_Present=0;
				s[i].Courses.sem2[4].No_Days_Total=0;
				s[i].Courses.sem2[4].Eligibility=0;
				s[i].Courses.sem2[4].Grade='\0';
				strcpy(s[i].Courses.sem2[5].Course_Code,"CE101");
				strcpy(s[i].Courses.sem2[5].Course_Name,"Constitution of India, Cyber Law and Professional Ethics");
				s[i].Courses.sem2[5].Credits=2;
				s[i].Courses.sem2[5].No_Days_Present=0;
				s[i].Courses.sem2[5].No_Days_Total=0;
				s[i].Courses.sem2[5].Eligibility=0;
				s[i].Courses.sem2[5].Grade='\0';
				strcpy(s[i].Courses.sem2[6].Course_Code,"CY102");
				strcpy(s[i].Courses.sem2[6].Course_Name,"Chemistry Laboratory");
				s[i].Courses.sem2[6].Credits=1;
				s[i].Courses.sem2[6].No_Days_Present=0;
				s[i].Courses.sem2[6].No_Days_Total=0;
				s[i].Courses.sem2[6].Eligibility=0;
				s[i].Courses.sem2[6].Grade='\0';
				strcpy(s[i].Courses.sem2[7].Course_Code,"CS152");
				strcpy(s[i].Courses.sem2[7].Course_Name,"Problem Solving with C Laboratory");
				s[i].Courses.sem2[7].Credits=1;
				s[i].Courses.sem2[7].No_Days_Present=0;
				s[i].Courses.sem2[7].No_Days_Total=0;
				s[i].Courses.sem2[7].Eligibility=0;
				s[i].Courses.sem2[7].Grade='\0';
				if(strcmp(s[i].Branch,"CSE")==0)
				{
					InitCSE(s[i]);
				}
				else if(strcmp(s[i].Branch,"ECE")==0)
				{
					InitECE(s[i]);
				}
				else if(strcmp(s[i].Branch,"ME")==0)
				{
					InitME(s[i]);
				}
				else if(strcmp(s[i].Branch,"EEE")==0)
				{
					InitEEE(s[i]);
				}
				else if(strcmp(s[i].Branch,"CV")==0)
				{
					InitCV(s[i]);
				}
				else if(strcmp(s[i].Branch,"BT")==0)
				{
					InitBT(s[i]);
				}
				fwrite(&s[i],sizeof(student),1,fp);
			}
			printf("\nSuccessfully added %d student account(s)!\n",n);
		}
	}
	fclose(fp);
}
void NumberStudentAcc()
{
	FILE *fp;
	student s1;
	fp=fopen("Student_Record.txt","r");
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof(student);
	int choice=0;
	while(choice!=5)
	{
		printf("\nEnter 1 to display total number of student records\n");
		printf("Enter 2 to display number of student records based on the semester\n");
		printf("Enter 3 to display the number of student records based on the semester and section\n");
		printf("Enter 4 to display the number of student records based on the semester and branch\n");
		printf("Enter 5 to go back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				rewind(fp);
				printf("\nNumber of student records present is %d\n",n);
				break;
			}
			case 2:
			{
				int sem,res=0;
				printf("\nEnter the semester : ");
				scanf("%d",&sem);
				rewind(fp);
				while(fread(&s1,sizeof(student),1,fp))
				{
					if(s1.Semester==sem)
					{
						res++;
					}
				}
				printf("Number of students in Semester %d is %d\n",sem,res);
				break;
			}
			case 3:
			{
				int sem,res=0;
				char section;
				printf("\nEnter the semester : ");
				scanf("%d",&sem);
				fflush(stdin);
				printf("Enter the section : ");
				scanf("%c",&section);
				rewind(fp);
				while(fread(&s1,sizeof(student),1,fp))
				{
					if(s1.Semester==sem&&s1.Section==section)
					{
						res++;
					}
				}
				printf("Number of students in Semester %d and Section %c is %d\n",sem,section,res);
				break;
			}
			case 4:
			{
				int sem,res=0;
				char branch[10];
				printf("\nEnter the semester : ");
				scanf("%d",&sem);
				fflush(stdin);
				printf("Enter the branch : ");
				scanf("%s",&branch);
				rewind(fp);
				while(fread(&s1,sizeof(student),1,fp))
				{
					if(s1.Semester==sem&&strcmp(s1.Branch,branch)==0)
					{
						res++;
					}
				}
				printf("Number of students in Semester %d and Branch %s is %d\n",sem,branch,res);
				break;
			}
		}
	}
	fclose(fp);
}
void SearchStudentAcc()
{
	FILE *fp;
	fp=fopen("Student_Record.txt","r");
	student s1;
	if(fp==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		int choice=0;
		while(choice!=3)
		{
			printf("\nEnter 1 to search a student record based on his/her name\n");
			printf("Enter 2 to search a student record based on his/her SRN\n");
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
					printf("Enter the student's name : ");
					fflush(stdin);
					scanf("%[^\n]s",&name);
					while(fread(&s1,sizeof(student),1,fp))
					{
						if(strcmp(s1.Name,name)==0)
						{
							found=1;
							printf("\nStudent record found!\n");
							printf("Student Details:\n");
							printf("Name : %s\n",s1.Name);
							printf("SRN : %s\n",s1.SRN);
							printf("Semester : %d\n",s1.Semester);
							printf("Branch : %s\n",s1.Branch);
							printf("Section : %c\n",s1.Section);
						}
					}
					if(found==0)
					{
						printf("\nStudent record could not be found.\n");
					}
					break;
				}
				case 2:
				{
					char srn[50];
					int found=0;
					rewind(fp);
					printf("Enter the student's SRN : ");
					fflush(stdin);
					scanf("%[^\n]s",&srn);
					while(fread(&s1,sizeof(student),1,fp))
					{
						if(strcmp(s1.SRN,srn)==0)
						{
							found=1;
							printf("\nStudent record found!\n");
							printf("Student Details:\n");
							printf("Name : %s\n",s1.Name);
							printf("SRN : %s\n",s1.SRN);
							printf("Semester : %d\n",s1.Semester);
							printf("Branch : %s\n",s1.Branch);
							printf("Section : %c\n",s1.Section);
						}
					}
					if(found==0)
					{
						printf("\nStudent record could not be found.\n");
					}
					break;
				}
			}
		}
	}
	fclose(fp);
}
void UpdateStudentAcc()
{
	int choice=0;
	while(choice!=5)
	{
		printf("\nEnter 1 to update student's SRN\n");
		printf("Enter 2 to update student's Section\n");
		printf("Enter 3 to update student's Branch\n");
		printf("Enter 4 to update student's Semester\n");
		printf("Enter 5 to go back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				FILE *fp,*fp1;
				student s1;
				char name[50];
				printf("Enter student's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					int found=0;
					while(fread(&s1,sizeof(s1),1,fp))
					{
						if(strcmp(s1.Name,name)==0)
						{
							found=1;
							char srn[20];
							fflush(stdin);
							printf("Enter new SRN of the student : ");
							scanf("%[^\n]s",&srn);
							strcpy(s1.SRN,srn);
						}
						fwrite(&s1,sizeof(student),1,fp1);
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student record is updated successfully!\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Student record could not be found.\n");
					}
					break;
				}
			}
			case 2:
			{
				FILE *fp,*fp1;
				student s1;
				char name[50];
				printf("Enter student's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					int found=0;
					while(fread(&s1,sizeof(s1),1,fp))
					{
						if(strcmp(s1.Name,name)==0)
						{
							found=1;
							char section;
							printf("Enter new section of the student : ");
							fflush(stdin);
							scanf("%c",&section);
							s1.Section=section;
						}
						fwrite(&s1,sizeof(student),1,fp1);
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student record is updated successfully!\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Student record could not be found.\n");
					}
					break;
				}
			}
			case 3:
			{
				FILE *fp,*fp1;
				student s1;
				char name[50];
				printf("Enter student's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					int found=0;
					while(fread(&s1,sizeof(s1),1,fp))
					{
						if(strcmp(s1.Name,name)==0)
						{
							found=1;
							char branch[10];
							printf("Enter new branch of the student : ");
							scanf("%s",&branch);
							strcpy(s1.Branch,branch);
						}
						fwrite(&s1,sizeof(student),1,fp1);
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student record is updated successfully!\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Student record could not be found.\n");
					}
					break;
				}
			}
			case 4:
			{
				FILE *fp,*fp1;
				student s1;
				char name[50];
				printf("Enter student's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					int found=0;
					while(fread(&s1,sizeof(s1),1,fp))
					{
						if(strcmp(s1.Name,name)==0)
						{
							found=1;
							int semester;
							printf("Enter new semester of the student : ");
							scanf("%d",&semester);
							s1.Semester=semester;
						}
						fwrite(&s1,sizeof(student),1,fp1);
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student record is updated successfully!\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Student record could not be found.\n");
					}
					break;
				}
			}
		}
	}
}
void DeleteStudentAcc()
{
	int choice=0;
	while(choice!=4)
	{
		printf("\nEnter 1 to delete a student account based on his/her name\n");
		printf("Enter 2 to delete a student account based on his/her SRN\n");
		printf("Enter 3 to delete all student accounts based on the semester of the students\n");
		printf("Enter 4 to go back\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				FILE *fp,*fp1;
				student s1;
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					char name[50];
					int found=0;
					printf("Enter the student's name : ");
					fflush(stdin);
					scanf("%[^\n]s",&name);
					while(fread(&s1,sizeof(student),1,fp))
					{
						if(strcmp(s1.Name,name)==0)
						{
							found=1;
						}
						else
						{
							fwrite(&s1,sizeof(student),1,fp1);
						}
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student record is deleted successfully.\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Student record could not be found.\n");
					}
					break;
				}
			}
			case 2:
			{
				FILE *fp,*fp1;
				student s1;
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					char srn[50];
					int found=0;
					printf("Enter the student's SRN : ");
					fflush(stdin);
					scanf("%[^\n]s",&srn);
					while(fread(&s1,sizeof(student),1,fp))
					{
						if(strcmp(s1.SRN,srn)==0)
						{
							found=1;
						}
						else
						{
							fwrite(&s1,sizeof(student),1,fp1);
						}
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student record is deleted successfully.\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("Student record could not be found.\n");
					}
					break;
				}
			}
			case 3:
			{
				FILE *fp,*fp1;
				student s1;
				fp=fopen("Student_Record.txt","r");
				fp1=fopen("Temp_Student_Record.txt","w");
				if(fp==NULL||fp1==NULL)
				{
					printf("Error...Try again\n");
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					int sem;
					int found=0;
					printf("Enter the semester of the students : ");
					fflush(stdin);
					scanf("%d",&sem);
					while(fread(&s1,sizeof(student),1,fp))
					{
						if(s1.Semester==sem)
						{
							found=1;
						}
						else
						{
							fwrite(&s1,sizeof(student),1,fp1);
						}
					}
					fclose(fp);
					fclose(fp1);
					if(found)
					{
						fp=fopen("Student_Record.txt","w");
						fp1=fopen("Temp_Student_Record.txt","r");
						while(fread(&s1,sizeof(student),1,fp1))
						{
							fwrite(&s1,sizeof(student),1,fp);
						}
						printf("Student records are deleted successfully.\n");
						fclose(fp);
						fclose(fp1);
					}
					else
					{
						printf("No student belonged to semester %d.\n",sem);
					}
					break;
				}
			}
		}
	}
}
void StudentLogin()
{
	FILE *fp;
	fp=fopen("Student_Record.txt","r");
	student s1;
	char srn[50],pass[50];
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
			fread(&s1,sizeof(student),1,fp);
			if(strcmp(s1.SRN,srn)==0&&strcmp(s1.Password,pass)!=0)
			{		
				flag=1;
				break;
			}
			else if(strcmp(s1.SRN,srn)==0&&strcmp(s1.Password,pass)==0)
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
				StudentLogin();
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
				StudentLogin();
			}
			else if(choice==2)
			{
				LoginMenu();
			}
		}
		else
		{
			StudentMainMenu(srn);
		}
	}
}
void ChangeStudentPassword(char srn[])
{
	FILE *fp,*fp1;
    student s1;
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
		fp=fopen("Student_Record.txt","r");
		fp1=fopen("Temp_Student_Record.txt","w");
		if(fp==NULL||fp1==NULL)
		{
			printf("Error...Try again\n");
			fclose(fp);
			fclose(fp1);
		}
		else
		{
			while(fread(&s1,sizeof(s1),1,fp))
			{
				if(strcmp(s1.SRN,srn)==0)
				{
					fflush(stdin);
					strcpy(s1.Password,p);
				}
				fwrite(&s1,sizeof(student),1,fp1);
			}
			fclose(fp);
			fclose(fp1);
			fp=fopen("Student_Record.txt","w");
			fp1=fopen("Temp_Student_Record.txt","r");
			while(fread(&s1,sizeof(student),1,fp1))
			{
				fwrite(&s1,sizeof(student),1,fp);
			}
			printf("Password is updated successfully!\n");
			fclose(fp);
			fclose(fp1);
	    }
	}
	else
	{
		printf("Password and confirmation password do not match. Try again...\n");
		ChangeStudentPassword(srn);
	}	
}
