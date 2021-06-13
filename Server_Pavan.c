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
		}
	}
	fclose(fp);
}
void NumberTeacherAcc()
{
	FILE *fp;
	fp=fopen("Teacher_Record.txt","r");
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof(teacher);
	printf("\nNumber of teacher records present is %d\n",n);
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
		while(choice!=1&&choice!=2&&choice!=3)
		{
			printf("\nEnter 1 to search a teacher based on his/her name\n");
			printf("Enter 2 to search a teacher based on his/her PRN\n");
			printf("Enter 3 to go back\n");
			printf("Enter your choice : ");
			scanf("%d",&choice);
		}
		switch(choice)
		{
			case 1:
			{
				char name[50];
				printf("Enter the Teacher's name : ");
				fflush(stdin);
				scanf("%[^\n]s",&name);
				while(fread(&t,sizeof(teacher),1,fp))
				{
					if(strcmp(t.Name,name)==0)
					{
						printf("\nTeacher record found!\n");
						printf("Teacher Details:\n");
						printf("Name : %s\n",t.Name);
						printf("PRN : %s\n",t.PRN);
						printf("Branch : %s\n",t.Branch);
					}
				}		
				break;
			}
			case 2:
			{
				char prn[50];
				printf("Enter the student's PRN : ");
				fflush(stdin);
				scanf("%[^\n]s",&prn);
				while(fread(&t,sizeof(teacher),1,fp))
				{
					if(strcmp(t.PRN,prn)==0)
					{
						printf("\nTeacher record found!\n");
						printf("Teacher Details:\n");
						printf("Name : %s\n",t.Name);
						printf("PRN : %s\n",t.PRN);
						printf("Branch : %s\n",t.Branch);
					}						
				}
				break;
			}
		}
	}
	fclose(fp);
}
void UpdateTeacherAcc()
{
	FILE *fp,*fp1;
	teacher t;
	fp=fopen("Teacher_Record.txt","r");
	fp1=fopen("Temp_Teacher_Record.txt","w");
	rewind(fp);
	rewind(fp1);
	if(fp==NULL||fp1==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		char name[50];
		printf("Enter Teacher's name : ");
		fflush(stdin);
		scanf("%[^\n]s",&name);
		int choice=0;
		while(choice!=1&&choice!=2&&choice!=3)
		{
			printf("\nEnter 1 to update Teacher's PRN\n");
			printf("Enter 2 to update Teacher's Branch\n");
			printf("Enter 3 to go back\n");
			printf("Enter your choice : ");
			scanf("%d",&choice);
		}
		switch(choice)
		{
			case 1:
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
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					printf("Record not found\n");
				}
				break;
			}
			case 2:
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
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					printf("Record not found\n");
				}
				break;
           		}
        	}        
    	}
}
void DeleteTeacherAcc()
{
	FILE *fp,*fp1;
	teacher t;
	fp=fopen("Teacher_Record.txt","r");
	fp1=fopen("Temp_Teacher_Record.txt","w");
	rewind(fp);
	rewind(fp1);
	if(fp==NULL||fp1==NULL)
	{
		printf("Error...Try again\n");
	}
	else
	{
		int choice=0;
		while(choice!=1&&choice!=2&&choice!=3)
		{
			printf("\nEnter 1 to delete a teacher account based on his/her name\n");
			printf("Enter 2 to delete a teacher account based on his/her PRN\n");
			printf("Enter 3 to go back\n");
			printf("Enter your choice : ");
			scanf("%d",&choice);
		}
		switch(choice)
		{
			case 1:
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
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					printf("Record not found\n");
				}
				break;
			}
			case 2:
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
					fclose(fp);
					fclose(fp1);
				}
				else
				{
					printf("Record not found\n");
				}
				break;
			}
		}
	}
	fclose(fp);
}
