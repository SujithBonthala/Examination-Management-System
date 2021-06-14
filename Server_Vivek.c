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
				s[i].No_Days_Present=0;
				s[i].No_Days_Total=0;
				s[i].Eligibility=0;
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
					if(s1.Semester==sem&&s1.Branch==branch)
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
	rewind(fp);
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
							if(s1.No_Days_Total!=0)
							{
								printf("Attendance(in Percentage) : %f\n",(s1.No_Days_Present/s1.No_Days_Total*100.0));
							}
							else
							{
								printf("Attendance(in Percentage) : 0\n");
							}
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
							if(s1.No_Days_Total!=0)
							{
								printf("Attendance(in Percentage) : %f\n",(s1.No_Days_Present/s1.No_Days_Total*100.0));
							}
							else
							{
								printf("Attendance(in Percentage) : 0\n");
							}
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
	FILE *fp,*fp1;
	student s1;
	fp=fopen("Student_Record.txt","r");
	fp1=fopen("Temp_Student_Record.txt","w");
	rewind(fp);
	rewind(fp1);
	if(fp==NULL||fp1==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		char name[50];
		printf("Enter student's name : ");
		fflush(stdin);
		scanf("%[^\n]s",&name);
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
				case 2:
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
				case 3:
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
				case 4:
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
	FILE *fp,*fp1;
	student s1;
	fp=fopen("Student_Record.txt","r");
	fp1=fopen("Temp_Student_Record.txt","w");
	rewind(fp);
	rewind(fp1);
	if(fp==NULL||fp1==NULL)
	{
		printf("Error...Try again\n");
	}
	else
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
				case 2:
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
				case 3:
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
void SetExamDetails()
{
}
