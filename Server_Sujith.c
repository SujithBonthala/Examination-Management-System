#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "Header_File.h"
void LoginMenu()
{
	printf("Welcome to Examination Management System\n");
	int choice=0;
	while(choice!=4)
	{
		printf("\nEnter 1 to Login as Admin\n");
		printf("Enter 2 to Login as Student\n");
		printf("Enter 3 to Login as Teacher\n");
		printf("Enter 4 to Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			GetAdminCredentials();
		}
		else if(choice==2)
		{
			GetStudentCredentials();
		}
		else if(choice==3)
		{
			GetTeacherCredentials();
		}
		else if(choice==4)
		{
			exit(0);
		}
	}
}
void GetAdminCredentials()
{
	char username_temp[100],password_temp[100];
	while(1)
	{
		fflush(stdin);
		printf("\nEnter the username : ");
		scanf("%[^\n]s",username_temp);
		fflush(stdin);
		char ch;
		int charpos=0;
		printf("Enter the password : ");
		//scanf("%[^\n]s",password_temp);
		while(1)
		{
			ch=getch();
			if(ch==13)
			{
				break;
			}
			else if(ch==8)
			{
				if(charpos>0)
				{
					charpos--;
					password_temp[charpos]='\0';
					printf("\b \b");
				}
			}
			else
			{
				password_temp[charpos]=ch;
				charpos++;
				printf("*");
			}
		}
		fflush(stdin);
		password_temp[charpos]='\0';
		int un_len=strlen(username_temp);
		int pw_len=strlen(password_temp);
		char username[un_len],password[pw_len];
		int i,j;
		for(i=0;i<un_len;i++)
		{
			username[i]=username_temp[i];
		}
		for(j=0;j<pw_len;j++)
		{
			password[j]=password_temp[j];
		}
		username[i]='\0';
		password[j]='\0';
		if(Cipher(username,password))
		{
			AdminMainMenu();
			break;
		}
		else
		{
			printf("Invalid username or password\n");
			int c=0;
			while(c!=1&&c!=2)
			{
				printf("Enter 1 to try again\n");
				printf("Enter 2 to Exit\n");
				printf("Enter your choice : ");
				scanf("%d",&c);
			}
			if(c==2)
			{
				break;
			}
		}
	}
}
void AdminMainMenu()
{
	printf("\nLogged in successfully\n");
	int choice=0;
	while(choice!=3)
	{
		printf("\nEnter 1 to modify student/teacher accounts");
		printf("\nEnter 2 to Set Exam Details");
		printf("\nEnter 3 to Logout\n");
		printf("Enter your choice : ");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter 1 to create Student Account(s)");
				printf("\nEnter 2 to create Teacher Account(s)");
				printf("\nEnter 3 to display number of Student Account(s)");
				printf("\nEnter 4 to display number of Teacher Account(s)");
				printf("\nEnter 5 to search a Student Account");
				printf("\nEnter 6 to search a Teacher Account");
				printf("\nEnter 7 to update a Student Account");
				printf("\nEnter 8 to update a Teacher Account");
				printf("\nEnter 9 to delete a Student Account");
				printf("\nEnter 10 to delete a Teacher Account");
				printf("\nEnter your choice : ");
				int choice1;
				fflush(stdin);
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:
					{
						CreateStudentAcc();
						break;
					}
					case 2:
					{
						CreateTeacherAcc();
						break;
					}
					case 3:
					{
						NumberStudentAcc();
						break;
					}
					case 4:
					{
						NumberTeacherAcc();
						break;
					}
					case 5:
					{
						SearchStudentAcc();
						break;
					}
					case 6:
					{
						SearchTeacherAcc();
						break;
					}
					case 7:
					{
						UpdateStudentAcc();
						break;
					}
					case 8:
					{
						UpdateTeacherAcc();
						break;
					}
					case 9:
					{
						DeleteStudentAcc();
						break;
					}
					case 10:
					{
						DeleteTeacherAcc();
						break;
					}
					default:
					{
						printf("\nInvalid choice.\n");
					}
				}
				break;
			}
			case 2:
			{
				SetExamDetails();
				break;
			}
		}
	}
}
void GetStudentCredentials()
{
	StudentLogin();
}
void StudentMainMenu(student *s)
{
	printf("\n\nLogged in Successfully\n");
	printf("Welcome %s! Please select one of the options given below.\n",s->Name);
	int choice;
	do
	{
		printf("\nEnter 1 to view Results\n");
		printf("Enter 2 to view the Details of the Courses\n");
        printf("Enter 3 to Check Exam Seat Allotment\n");
		printf("Enter 4 to Change Password\n");
		printf("Enter 5 to check your attendance\n");
		printf("Enter 6 to Logout\n");
		printf("Enter your choice : ");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				//checkresults(s);
				printf("yet to do");
				break;
			}
			case 2:
			{
				CheckDetails(s);
				break;
			}
			case 3:
			{
				printf("yet to do");	
				break;
			}
			case 4:
			{
				ChangeStudentPassword(s);
				break;
			}
			case 5:
			{
				checkattendance(s);
				break;		
			}
			case 6:
			{
				LoginMenu();
				break;
			}
		}
	}while(choice!=6);
}
void InitBranch(student *s)
{
	if(strcmp(s->Branch,"CSE")==0)
	{
		InitCSE(s);
	}
	else if(strcmp(s->Branch,"ECE")==0)
	{
		InitECE(s);
	}
	else if(strcmp(s->Branch,"ME")==0)
	{
		InitME(s);
	}
	else if(strcmp(s->Branch,"EEE")==0)
	{
		InitEEE(s);
	}
	else if(strcmp(s->Branch,"CV")==0)
	{
		InitCV(s);
	}
	else if(strcmp(s->Branch,"BT")==0)
	{
		InitBT(s);
	}
}
void GetTeacherCredentials()
{
	//TeacherLogin();
}
int Cipher(char usn[],char psw[])
{
	int a[26][3];
	for(int k=0;k<26;k++)
    	{
        	a[k][0]=0;
    	}
    	char c[5][5];
    	int i=0,j=0;
	char un[strlen(usn)],pw[strlen(psw)];
	int un_ref=0,pw_ref=0;
	for(int k=0;usn[k]!='\0';k++)
	{
		if((usn[k]>=65&&usn[k]<=90)||(usn[k]>=97&&usn[k]<=122))
		{
			un[un_ref]=usn[k];
			un_ref++;
		}
	}
	un[un_ref]='\0';
	for(int l=0;psw[l]!='\0';l++)
	{
		if((psw[l]>=65&&psw[l]<=90)||(psw[l]>=97&&psw[l]<=122))
		{
			pw[pw_ref]=psw[l];
			pw_ref++;
		}
	}
	pw[pw_ref]='\0';
	for(int k=0;un[k]!='\0';k++)
	{
		if(un[k]>=97&&un[k]<=122)
        	{
            		un[k]=un[k]-32;
        	}
        	if(un[k]>=65&&un[k]<=90&&a[(int)un[k]-65][0]==0)
        	{
            		if((int)un[k]==73||(int)un[k]==74)
            		{
                		a[8][0]++;
                		a[9][0]++;
                		un[k]='I';
                		a[8][1]=i;
                		a[8][2]=j;
                		a[9][1]=i;
                		a[9][2]=j;
            		}
            		else
           		{
                		a[(int)un[k]-65][0]++;
                		a[(int)un[k]-65][1]=i;
                		a[(int)un[k]-65][2]=j;
            		}
            		if(j<4)
            		{
                		c[i][j]=un[k];
                		j++;
            		}
            		else
            		{
                		c[i][j]=un[k];
                		i++;
                		j=0;
            		}
        	}
    	}
    	for(int k=65;k<=90;k++)
    	{
        	if(a[k-65][0]==0)
        	{
            		if(k==73)
            		{
                		a[9][0]=1;
                		a[8][1]=i;
                		a[8][2]=j;
                		a[9][1]=i;
                		a[9][2]=j;
            		}
            		else
            		{
                		a[k-65][1]=i;
                		a[k-65][2]=j;
            		}
            		if(j<4)
            		{
                		c[i][j]=(char)k;
                		j++;
            		}
            		else
            		{
                		c[i][j]=(char)k;
                		i++;
                		j=0;
            		}
        	}
    	}
	int count=0;
	for(int k=0;pw[k]!='\0';k++)
	{
		count++;
		if(pw[k]>=97&&pw[k]<=122)
        	{
            		pw[k]=pw[k]-32;
        	}
	}
	if(count%2!=0)
    	{
        	pw[count]='-';
		pw[count+1]='\0';
        	count+=1;
    	}
    	char encr[count+1];
	if(pw[count-1]!='-')
    	{
        	for(int x=0;x<count;x+=2)
        	{
            		if(pw[x]!='J'&&pw[x+1]!='J')
            		{
                		int rowx=a[(int)pw[x]-65][1];
                		int colx=a[(int)pw[x]-65][2];
                		int rowx1=a[(int)pw[x+1]-65][1];
                		int colx1=a[(int)pw[x+1]-65][2];
                		if(rowx!=rowx1&&colx!=colx1)
                		{
                    			encr[x]=c[rowx][colx1];
                    			encr[x+1]=c[rowx1][colx];
                		}
                		else if(rowx==rowx1&&colx!=colx1)
                		{
                    			if(colx==4)
                    			{
                        			encr[x]=c[rowx][0];
                        			encr[x+1]=c[rowx1][colx1+1];
                    			}
                    			else if(colx1==4)
                    			{
                        			encr[x]=c[rowx][colx+1];
                        			encr[x+1]=c[rowx1][0];
                    			}
                    			else
                    			{
                        			encr[x]=c[rowx][colx+1];
                        			encr[x+1]=c[rowx1][colx1+1];
                    			}
                		}
                		else if(rowx!=rowx1&&colx==colx1)
                		{
                    			if(rowx==4)
                    			{
                        			encr[x]=c[0][colx];
                        			encr[x+1]=c[rowx1+1][colx1];
                    			}
                    			else if(rowx1==4)
                    			{
                        			encr[x]=c[rowx+1][colx];
                        			encr[x+1]=c[0][colx1];
                    			}
                    			else
                    			{
                        			encr[x]=c[rowx+1][colx];
                        			encr[x+1]=c[rowx1+1][colx1];
                    			}
                		}
                		else
                		{
                    			if(rowx==4&&colx==4)
                    			{
                        			encr[x]=c[0][0];
                        			encr[x+1]=c[0][0];
                    			}
                    			else if(rowx==4)
                    			{
                        			encr[x]=c[0][colx+1];
                        			encr[x+1]=c[0][colx+1];
                    			}
                    			else if(colx==4)
                    			{
                        			encr[x]=c[rowx+1][0];
                        			encr[x+1]=c[rowx+1][0];
                    			}
                    			else
                    			{
                        			encr[x]=c[rowx+1][colx+1];
                        			encr[x+1]=c[rowx+1][colx+1];
                    			}
                		}
            		}
            		else if(pw[x]=='J'&&pw[x+1]!='J')
            		{
                		int rowx1=a[(int)pw[x+1]-65][1];
                		int colx=a[((int)'J')-65][2];
                		encr[x]='+';
                		encr[x+1]=c[rowx1][colx];
            		}
            		else if(pw[x]!='J'&&pw[x+1]=='J')
            		{
                		int rowx=a[(int)pw[x]-65][1];
                		int colx1=a[((int)'J')-65][2];
                		encr[x+1]='+';
                		encr[x]=c[rowx][colx1];
            		}
            		else
            		{
                		encr[x]='+';
                		encr[x+1]='+';
            		}
		}
	}
    else
	{
        	for(int x=0;x<count-2;x+=2)
        	{
            		if(pw[x]!='J'&&pw[x+1]!='J')
            		{
                		int rowx=a[(int)pw[x]-65][1];
                		int colx=a[(int)pw[x]-65][2];
                		int rowx1=a[(int)pw[x+1]-65][1];
                		int colx1=a[(int)pw[x+1]-65][2];
                		if(rowx!=rowx1&&colx!=colx1)
                		{
                    			encr[x]=c[rowx][colx1];
                    			encr[x+1]=c[rowx1][colx];
                		}
                		else if(rowx==rowx1&&colx!=colx1)
                		{
                    			if(colx==4)
                    			{
                        			encr[x]=c[rowx][0];
                        			encr[x+1]=c[rowx1][colx1+1];
                    			}
                    			else if(colx1==4)
                    			{
                        			encr[x]=c[rowx][colx+1];
                        			encr[x+1]=c[rowx1][0];
                    			}
                    			else
                    			{
                        			encr[x]=c[rowx][colx+1];
                        			encr[x+1]=c[rowx1][colx1+1];
                    			}
                		}
                		else if(rowx!=rowx1&&colx==colx1)
                		{
                    			if(rowx==4)
                    			{
                        			encr[x]=c[0][colx];
                        			encr[x+1]=c[rowx1+1][colx1];
                    			}
                    			else if(rowx1==4)
                    			{
                        			encr[x]=c[rowx+1][colx];
                        			encr[x+1]=c[0][colx1];
                    			}
                    			else
                    			{
                        			encr[x]=c[rowx+1][colx];
                        			encr[x+1]=c[rowx1+1][colx1];
                    			}
                		}
                		else
                		{
                    			if(rowx==4&&colx==4)
                    			{
                        			encr[x]=c[0][0];
                        			encr[x+1]=c[0][0];
                    			}
                    			else if(rowx==4)
                    			{
                        			encr[x]=c[0][colx+1];
                        			encr[x+1]=c[0][colx+1];
                    			}
                    			else if(colx==4)
                    			{
                        			encr[x]=c[rowx+1][0];
                        			encr[x+1]=c[rowx+1][0];
                    			}
                    			else
                    			{
                        			encr[x]=c[rowx+1][colx+1];
                        			encr[x+1]=c[rowx+1][colx+1];
                    			}
                		}
            		}
            		else if(pw[x]=='J'&&pw[x+1]!='J')
            		{
                		int rowx1=a[(int)pw[x+1]-65][1];
                		int colx=a[((int)'J')-65][2];
                		encr[x]='+';
                		encr[x+1]=c[rowx1][colx];
            		}
            		else if(pw[x]!='J'&&pw[x+1]=='J')
            		{
                		int rowx=a[(int)pw[x]-65][1];
                		int colx1=a[((int)'J')-65][2];
                		encr[x+1]='+';
                		encr[x]=c[rowx][colx1];
            		}
            		else
            		{
                		encr[x]='+';
                		encr[x+1]='+';
            		}
        	}
        	if(pw[count-2]=='J')
        	{
            		encr[count-2]='+';
        	}
        	else
        	{
            		int row=a[(int)pw[count-2]-65][1];
            		int col=a[(int)pw[count-2]-65][2];
            		if(row==4&&col==4)
            		{
                		encr[count-2]=c[0][0];
            		}
            		else if(row==4)
            		{
                		encr[count-2]=c[0][col+1];
            		}
            		else if(col==4)
            		{
                		encr[count-2]=c[row+1][0];
            		}
            		else
            		{
                		encr[count-2]=c[row+1][col+1];
            		}
        	}
        	encr[count-1]='-';
    	}
	encr[count]='\0';
	char s[]={'C','P','W','M','E','I','F','T','G','C','M','-','\0'};
	if(strcmp(encr,s)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void InitCSE(student *s)
{
	//Semester 3
	s->Courses.no_courses_sem3=8;
	strcpy(s->Courses.sem3[0].Course_Code,"CS201");
	strcpy(s->Courses.sem3[0].Course_Name,"Digital Design and Computer Organization");
	s->Courses.sem3[0].Credits=4;
	s->Courses.sem3[0].No_Days_Present=0;
	s->Courses.sem3[0].No_Days_Total=0;
	s->Courses.sem3[0].Eligibility=0;
	s->Courses.sem3[0].Grade='\0';
	s->Courses.sem3[0].Examination_Block='\0';
	strcpy(s->Courses.sem3[0].Examination_Date,"\0");
	strcpy(s->Courses.sem3[0].Examination_Section,"\0");
	strcpy(s->Courses.sem3[1].Course_Code,"CS202");
	strcpy(s->Courses.sem3[1].Course_Name,"Data Structures and its Applications");
	s->Courses.sem3[1].Credits=4;
	s->Courses.sem3[1].No_Days_Present=0;
	s->Courses.sem3[1].No_Days_Total=0;
	s->Courses.sem3[1].Eligibility=0;
	s->Courses.sem3[1].Grade='\0';
	s->Courses.sem3[1].Examination_Block='\0';
	strcpy(s->Courses.sem3[1].Examination_Date,"\0");
	strcpy(s->Courses.sem3[1].Examination_Section,"\0");
	strcpy(s->Courses.sem3[2].Course_Code,"CS203");
	strcpy(s->Courses.sem3[2].Course_Name,"Statistics for Data Science");
	s->Courses.sem3[2].Credits=4;
	s->Courses.sem3[2].No_Days_Present=0;
	s->Courses.sem3[2].No_Days_Total=0;
	s->Courses.sem3[2].Eligibility=0;
	s->Courses.sem3[2].Grade='\0';
	s->Courses.sem3[2].Examination_Block='\0';
	strcpy(s->Courses.sem3[2].Examination_Date,"\0");
	strcpy(s->Courses.sem3[2].Examination_Section,"\0");
	strcpy(s->Courses.sem3[3].Course_Code,"CS204");
	strcpy(s->Courses.sem3[3].Course_Name,"Web Technologies");
	s->Courses.sem3[3].Credits=4;
	s->Courses.sem3[3].No_Days_Present=0;
	s->Courses.sem3[3].No_Days_Total=0;
	s->Courses.sem3[3].Eligibility=0;
	s->Courses.sem3[3].Grade='\0';
	s->Courses.sem3[3].Examination_Block='\0';
	strcpy(s->Courses.sem3[3].Examination_Date,"\0");
	strcpy(s->Courses.sem3[3].Examination_Section,"\0");
	strcpy(s->Courses.sem3[4].Course_Code,"CS205");
	strcpy(s->Courses.sem3[4].Course_Name,"Automata Formal Languages and Logic");
	s->Courses.sem3[4].Credits=4;
	s->Courses.sem3[4].No_Days_Present=0;
	s->Courses.sem3[4].No_Days_Total=0;
	s->Courses.sem3[4].Eligibility=0;
	s->Courses.sem3[4].Grade='\0';
	s->Courses.sem3[4].Examination_Block='\0';
	strcpy(s->Courses.sem3[4].Examination_Date,"\0");
	strcpy(s->Courses.sem3[4].Examination_Section,"\0");
	strcpy(s->Courses.sem3[5].Course_Code,"CS206");
	strcpy(s->Courses.sem3[5].Course_Name,"Digital Design and Computer Organization Laboratory");
	s->Courses.sem3[5].Credits=1;
	s->Courses.sem3[5].No_Days_Present=0;
	s->Courses.sem3[5].No_Days_Total=0;
	s->Courses.sem3[5].Eligibility=0;
	s->Courses.sem3[5].Grade='\0';
	s->Courses.sem3[5].Examination_Block='-';
	strcpy(s->Courses.sem3[5].Examination_Date,"-");
	strcpy(s->Courses.sem3[5].Examination_Section,"-");
	strcpy(s->Courses.sem3[6].Course_Code,"CS207");
	strcpy(s->Courses.sem3[6].Course_Name,"Data Structures and its Applications Laboratory");
	s->Courses.sem3[6].Credits=1;
	s->Courses.sem3[6].No_Days_Present=0;
	s->Courses.sem3[6].No_Days_Total=0;
	s->Courses.sem3[6].Eligibility=0;
	s->Courses.sem3[6].Grade='\0';
	s->Courses.sem3[6].Examination_Block='-';
	strcpy(s->Courses.sem3[6].Examination_Date,"-");
	strcpy(s->Courses.sem3[6].Examination_Section,"-");
	strcpy(s->Courses.sem3[7].Course_Code,"CS208");
	strcpy(s->Courses.sem3[7].Course_Name,"Special Topic I");
	s->Courses.sem3[7].Credits=2;
	s->Courses.sem3[7].No_Days_Present=0;
	s->Courses.sem3[7].No_Days_Total=0;
	s->Courses.sem3[7].Eligibility=0;
	s->Courses.sem3[7].Grade='\0';
	s->Courses.sem3[7].Examination_Block='\0';
	strcpy(s->Courses.sem3[7].Examination_Date,"\0");
	strcpy(s->Courses.sem3[7].Examination_Section,"\0");
	//Semester 4
	s->Courses.no_courses_sem4=8;
	strcpy(s->Courses.sem4[0].Course_Code,"CS251");
	strcpy(s->Courses.sem4[0].Course_Name,"Linear Algebra");
	s->Courses.sem4[0].Credits=4;
	s->Courses.sem4[0].No_Days_Present=0;
	s->Courses.sem4[0].No_Days_Total=0;
	s->Courses.sem4[0].Eligibility=0;
	s->Courses.sem4[0].Grade='\0';
	s->Courses.sem4[0].Examination_Block='\0';
	strcpy(s->Courses.sem4[0].Examination_Date,"\0");
	strcpy(s->Courses.sem4[0].Examination_Section,"\0");
	strcpy(s->Courses.sem4[1].Course_Code,"CS252");
	strcpy(s->Courses.sem4[1].Course_Name,"Design and Analysis of Algorithms");
	s->Courses.sem4[1].Credits=4;
	s->Courses.sem4[1].No_Days_Present=0;
	s->Courses.sem4[1].No_Days_Total=0;
	s->Courses.sem4[1].Eligibility=0;
	s->Courses.sem4[1].Grade='\0';
	s->Courses.sem4[1].Examination_Block='\0';
	strcpy(s->Courses.sem4[1].Examination_Date,"\0");
	strcpy(s->Courses.sem4[1].Examination_Section,"\0");
	strcpy(s->Courses.sem4[2].Course_Code,"CS253");
	strcpy(s->Courses.sem4[2].Course_Name,"Microprocessor and Computer Architecture");
	s->Courses.sem4[2].Credits=4;
	s->Courses.sem4[2].No_Days_Present=0;
	s->Courses.sem4[2].No_Days_Total=0;
	s->Courses.sem4[2].Eligibility=0;
	s->Courses.sem4[2].Grade='\0';
	s->Courses.sem4[2].Examination_Block='\0';
	strcpy(s->Courses.sem4[2].Examination_Date,"\0");
	strcpy(s->Courses.sem4[2].Examination_Section,"\0");
	strcpy(s->Courses.sem4[3].Course_Code,"CS254");
	strcpy(s->Courses.sem4[3].Course_Name,"Computer Networks");
	s->Courses.sem4[3].Credits=4;
	s->Courses.sem4[3].No_Days_Present=0;
	s->Courses.sem4[3].No_Days_Total=0;
	s->Courses.sem4[3].Eligibility=0;
	s->Courses.sem4[3].Grade='\0';
	s->Courses.sem4[3].Examination_Block='\0';
	strcpy(s->Courses.sem4[3].Examination_Date,"\0");
	strcpy(s->Courses.sem4[3].Examination_Section,"\0");
	strcpy(s->Courses.sem4[4].Course_Code,"CS255");
	strcpy(s->Courses.sem4[4].Course_Name,"Operating Systems");
	s->Courses.sem4[4].Credits=4;
	s->Courses.sem4[4].No_Days_Present=0;
	s->Courses.sem4[4].No_Days_Total=0;
	s->Courses.sem4[4].Eligibility=0;
	s->Courses.sem4[4].Grade='\0';
	s->Courses.sem4[4].Examination_Block='\0';
	strcpy(s->Courses.sem4[4].Examination_Date,"\0");
	strcpy(s->Courses.sem4[4].Examination_Section,"\0");
	strcpy(s->Courses.sem4[5].Course_Code,"CS256");
	strcpy(s->Courses.sem4[5].Course_Name,"Computer Networks Laboratory");
	s->Courses.sem4[5].Credits=1;
	s->Courses.sem4[5].No_Days_Present=0;
	s->Courses.sem4[5].No_Days_Total=0;
	s->Courses.sem4[5].Eligibility=0;
	s->Courses.sem4[5].Grade='\0';
	s->Courses.sem4[5].Examination_Block='-';
	strcpy(s->Courses.sem4[5].Examination_Date,"-");
	strcpy(s->Courses.sem4[5].Examination_Section,"-");
	strcpy(s->Courses.sem4[6].Course_Code,"CS257");
	strcpy(s->Courses.sem4[6].Course_Name,"Microprocessor and Computer Architecture Laboratory");
	s->Courses.sem4[6].Credits=1;
	s->Courses.sem4[6].No_Days_Present=0;
	s->Courses.sem4[6].No_Days_Total=0;
	s->Courses.sem4[6].Eligibility=0;
	s->Courses.sem4[6].Grade='\0';
	s->Courses.sem4[6].Examination_Block='-';
	strcpy(s->Courses.sem4[6].Examination_Date,"-");
	strcpy(s->Courses.sem4[6].Examination_Section,"-");
	strcpy(s->Courses.sem4[7].Course_Code,"CS258");
	strcpy(s->Courses.sem4[7].Course_Name,"Special Topic II");
	s->Courses.sem4[7].Credits=2;
	s->Courses.sem4[7].No_Days_Present=0;
	s->Courses.sem4[7].No_Days_Total=0;
	s->Courses.sem4[7].Eligibility=0;
	s->Courses.sem4[7].Grade='\0';
	s->Courses.sem4[7].Examination_Block='\0';
	strcpy(s->Courses.sem4[6].Examination_Date,"\0");
	strcpy(s->Courses.sem4[7].Examination_Section,"\0");
	//Semester 5
	s->Courses.no_courses_sem5=8;
	strcpy(s->Courses.sem5[0].Course_Code,"CS301");
	strcpy(s->Courses.sem5[0].Course_Name,"Database Technologies");
	s->Courses.sem5[0].Credits=4;
	s->Courses.sem5[0].No_Days_Present=0;
	s->Courses.sem5[0].No_Days_Total=0;
	s->Courses.sem5[0].Eligibility=0;
	s->Courses.sem5[0].Grade='\0';
	s->Courses.sem5[0].Examination_Block='\0';
	strcpy(s->Courses.sem5[0].Examination_Date,"\0");
	strcpy(s->Courses.sem5[0].Examination_Section,"\0");
	strcpy(s->Courses.sem5[1].Course_Code,"CS302");
	strcpy(s->Courses.sem5[1].Course_Name,"Principles of Programming Languages");
	s->Courses.sem5[1].Credits=4;
	s->Courses.sem5[1].No_Days_Present=0;
	s->Courses.sem5[1].No_Days_Total=0;
	s->Courses.sem5[1].Eligibility=0;
	s->Courses.sem5[1].Grade='\0';
	s->Courses.sem5[1].Examination_Block='\0';
	strcpy(s->Courses.sem5[1].Examination_Date,"\0");
	strcpy(s->Courses.sem5[1].Examination_Section,"\0");
	strcpy(s->Courses.sem5[2].Course_Code,"CS303");
	strcpy(s->Courses.sem5[2].Course_Name,"Machine Intelligence");
	s->Courses.sem5[2].Credits=4;
	s->Courses.sem5[2].No_Days_Present=0;
	s->Courses.sem5[2].No_Days_Total=0;
	s->Courses.sem5[2].Eligibility=0;
	s->Courses.sem5[2].Grade='\0';
	s->Courses.sem5[2].Examination_Block='\0';
	strcpy(s->Courses.sem5[2].Examination_Date,"\0");
	strcpy(s->Courses.sem5[2].Examination_Section,"\0");
	strcpy(s->Courses.sem5[3].Course_Code,"CS304");
	strcpy(s->Courses.sem5[3].Course_Name,"Database Technologies Laboratory");
	s->Courses.sem5[3].Credits=1;
	s->Courses.sem5[3].No_Days_Present=0;
	s->Courses.sem5[3].No_Days_Total=0;
	s->Courses.sem5[3].Eligibility=0;
	s->Courses.sem5[3].Grade='\0';
	s->Courses.sem5[3].Examination_Block='-';
	strcpy(s->Courses.sem5[3].Examination_Date,"-");
	strcpy(s->Courses.sem5[3].Examination_Section,"-");
	strcpy(s->Courses.sem5[4].Course_Code,"CS305");
	strcpy(s->Courses.sem5[4].Course_Name,"Principles of Programming Languages Laboratory");
	s->Courses.sem5[4].Credits=1;
	s->Courses.sem5[4].No_Days_Present=0;
	s->Courses.sem5[4].No_Days_Total=0;
	s->Courses.sem5[4].Eligibility=0;
	s->Courses.sem5[4].Grade='\0';
	s->Courses.sem5[4].Examination_Block='-';
	strcpy(s->Courses.sem5[4].Examination_Date,"-");
	strcpy(s->Courses.sem5[4].Examination_Section,"-");
	strcpy(s->Courses.sem5[5].Course_Code,"CS306");
	strcpy(s->Courses.sem5[5].Course_Name,"Applied Cryptography");
	s->Courses.sem5[5].Credits=4;
	s->Courses.sem5[5].No_Days_Present=0;
	s->Courses.sem5[5].No_Days_Total=0;
	s->Courses.sem5[5].Eligibility=0;
	s->Courses.sem5[5].Grade='\0';
	s->Courses.sem5[5].Examination_Block='\0';
	strcpy(s->Courses.sem5[5].Examination_Date,"\0");
	strcpy(s->Courses.sem5[5].Examination_Section,"\0");
	strcpy(s->Courses.sem5[6].Course_Code,"CS307");
	strcpy(s->Courses.sem5[6].Course_Name,"Graph Theory and Its Applications");
	s->Courses.sem5[6].Credits=4;
	s->Courses.sem5[6].No_Days_Present=0;
	s->Courses.sem5[6].No_Days_Total=0;
	s->Courses.sem5[6].Eligibility=0;
	s->Courses.sem5[6].Grade='\0';
	s->Courses.sem5[6].Examination_Block='\0';
	strcpy(s->Courses.sem5[6].Examination_Date,"\0");
	strcpy(s->Courses.sem5[6].Examination_Section,"\0");
	strcpy(s->Courses.sem5[7].Course_Code,"CS308");
	strcpy(s->Courses.sem5[7].Course_Name,"Special Topic III");
	s->Courses.sem5[7].Credits=2;
	s->Courses.sem5[7].No_Days_Present=0;
	s->Courses.sem5[7].No_Days_Total=0;
	s->Courses.sem5[7].Eligibility=0;
	s->Courses.sem5[7].Grade='\0';
	s->Courses.sem5[7].Examination_Block='\0';
	strcpy(s->Courses.sem5[7].Examination_Date,"\0");
	strcpy(s->Courses.sem5[7].Examination_Section,"\0");
	//Semester 6
	s->Courses.no_courses_sem6=7;
	strcpy(s->Courses.sem6[0].Course_Code,"CS351");
	strcpy(s->Courses.sem6[0].Course_Name,"Compiler Design");
	s->Courses.sem6[0].Credits=4;
	s->Courses.sem6[0].No_Days_Present=0;
	s->Courses.sem6[0].No_Days_Total=0;
	s->Courses.sem6[0].Eligibility=0;
	s->Courses.sem6[0].Grade='\0';
	s->Courses.sem6[0].Examination_Block='\0';
	strcpy(s->Courses.sem6[0].Examination_Date,"\0");
	strcpy(s->Courses.sem6[0].Examination_Section,"\0");
	strcpy(s->Courses.sem6[1].Course_Code,"CS352");
	strcpy(s->Courses.sem6[1].Course_Name,"Cloud Computing");
	s->Courses.sem6[1].Credits=4;
	s->Courses.sem6[1].No_Days_Present=0;
	s->Courses.sem6[1].No_Days_Total=0;
	s->Courses.sem6[1].Eligibility=0;
	s->Courses.sem6[1].Grade='\0';
	s->Courses.sem6[1].Examination_Block='\0';
	strcpy(s->Courses.sem6[1].Examination_Date,"\0");
	strcpy(s->Courses.sem6[1].Examination_Section,"\0");
	strcpy(s->Courses.sem6[2].Course_Code,"CS353");
	strcpy(s->Courses.sem6[2].Course_Name,"Object Oriented Analysis and Design with Software Engineering");
	s->Courses.sem6[2].Credits=4;
	s->Courses.sem6[2].No_Days_Present=0;
	s->Courses.sem6[2].No_Days_Total=0;
	s->Courses.sem6[2].Eligibility=0;
	s->Courses.sem6[2].Grade='\0';
	s->Courses.sem6[2].Examination_Block='\0';
	strcpy(s->Courses.sem6[2].Examination_Date,"\0");
	strcpy(s->Courses.sem6[2].Examination_Section,"\0");
	strcpy(s->Courses.sem6[3].Course_Code,"CS354");
	strcpy(s->Courses.sem6[3].Course_Name,"Cloud Computing Laboratory");
	s->Courses.sem6[3].Credits=1;
	s->Courses.sem6[3].No_Days_Present=0;
	s->Courses.sem6[3].No_Days_Total=0;
	s->Courses.sem6[3].Eligibility=0;
	s->Courses.sem6[3].Grade='\0';
	s->Courses.sem6[3].Examination_Block='-';
	strcpy(s->Courses.sem6[3].Examination_Date,"-");
	strcpy(s->Courses.sem6[3].Examination_Section,"-");
	strcpy(s->Courses.sem6[4].Course_Code,"CS355");
	strcpy(s->Courses.sem6[4].Course_Name,"Object Oriented Analysis and Design with Software Engineering Laboratory");
	s->Courses.sem6[4].Credits=1;
	s->Courses.sem6[4].No_Days_Present=0;
	s->Courses.sem6[4].No_Days_Total=0;
	s->Courses.sem6[4].Eligibility=0;
	s->Courses.sem6[4].Grade='\0';
	s->Courses.sem6[4].Examination_Block='-';
	strcpy(s->Courses.sem6[4].Examination_Date,"-");
	strcpy(s->Courses.sem6[4].Examination_Section,"-");
	strcpy(s->Courses.sem6[5].Course_Code,"CS356");
	strcpy(s->Courses.sem6[5].Course_Name,"Algorithms for Intelligence Web and Information Retrieval");
	s->Courses.sem6[5].Credits=4;
	s->Courses.sem6[5].No_Days_Present=0;
	s->Courses.sem6[5].No_Days_Total=0;
	s->Courses.sem6[5].Eligibility=0;
	s->Courses.sem6[5].Grade='\0';
	s->Courses.sem6[5].Examination_Block='\0';
	strcpy(s->Courses.sem6[5].Examination_Date,"\0");
	strcpy(s->Courses.sem6[5].Examination_Section,"\0");
	strcpy(s->Courses.sem6[6].Course_Code,"CS357");
	strcpy(s->Courses.sem6[6].Course_Name,"Social Network Analytics");
	s->Courses.sem6[6].Credits=4;
	s->Courses.sem6[6].No_Days_Present=0;
	s->Courses.sem6[6].No_Days_Total=0;
	s->Courses.sem6[6].Eligibility=0;
	s->Courses.sem6[6].Grade='\0';
	s->Courses.sem6[6].Examination_Block='\0';
	strcpy(s->Courses.sem6[6].Examination_Date,"\0");
	strcpy(s->Courses.sem6[6].Examination_Section,"\0");
	//Semester 7
	s->Courses.no_courses_sem7=5;
	strcpy(s->Courses.sem7[0].Course_Code,"CS401");
	strcpy(s->Courses.sem7[0].Course_Name,"Object Oriented Modelling and Design");
	s->Courses.sem7[0].Credits=4;
	s->Courses.sem7[0].No_Days_Present=0;
	s->Courses.sem7[0].No_Days_Total=0;
	s->Courses.sem7[0].Eligibility=0;
	s->Courses.sem7[0].Grade='\0';
	s->Courses.sem7[0].Examination_Block='\0';
	strcpy(s->Courses.sem7[0].Examination_Date,"-");
	strcpy(s->Courses.sem7[0].Examination_Section,"\0");
	strcpy(s->Courses.sem7[1].Course_Code,"CS402");
	strcpy(s->Courses.sem7[1].Course_Name,"Software Engineering");
	s->Courses.sem7[1].Credits=4;
	s->Courses.sem7[1].No_Days_Present=0;
	s->Courses.sem7[1].No_Days_Total=0;
	s->Courses.sem7[1].Eligibility=0;
	s->Courses.sem7[1].Grade='\0';
	s->Courses.sem7[1].Examination_Block='\0';
	strcpy(s->Courses.sem7[1].Examination_Date,"-");
	strcpy(s->Courses.sem7[1].Examination_Section,"\0");
	strcpy(s->Courses.sem7[2].Course_Code,"CS403");
	strcpy(s->Courses.sem7[2].Course_Name,"Block Chain Technologies");
	s->Courses.sem7[2].Credits=4;
	s->Courses.sem7[2].No_Days_Present=0;
	s->Courses.sem7[2].No_Days_Total=0;
	s->Courses.sem7[2].Eligibility=0;
	s->Courses.sem7[2].Grade='\0';
	s->Courses.sem7[2].Examination_Block='\0';
	strcpy(s->Courses.sem7[2].Examination_Date,"-");
	strcpy(s->Courses.sem7[2].Examination_Section,"\0");
	strcpy(s->Courses.sem7[3].Course_Code,"CS404");
	strcpy(s->Courses.sem7[3].Course_Name,"Information Security");
	s->Courses.sem7[3].Credits=4;
	s->Courses.sem7[3].No_Days_Present=0;
	s->Courses.sem7[3].No_Days_Total=0;
	s->Courses.sem7[3].Eligibility=0;
	s->Courses.sem7[3].Grade='\0';
	s->Courses.sem7[3].Examination_Block='\0';
	strcpy(s->Courses.sem7[3].Examination_Date,"-");
	strcpy(s->Courses.sem7[3].Examination_Section,"\0");
	strcpy(s->Courses.sem7[4].Course_Code,"CS405");
	strcpy(s->Courses.sem7[4].Course_Name,"Capstone Project Phase – I");
	s->Courses.sem7[4].Credits=4;
	s->Courses.sem7[4].No_Days_Present=0;
	s->Courses.sem7[4].No_Days_Total=0;
	s->Courses.sem7[4].Eligibility=0;
	s->Courses.sem7[4].Grade='\0';
	s->Courses.sem7[4].Examination_Block='-';
	strcpy(s->Courses.sem7[4].Examination_Date,"-");
	strcpy(s->Courses.sem7[4].Examination_Section,"-");
	//Semester 8
	s->Courses.no_courses_sem8=3;
	strcpy(s->Courses.sem8[0].Course_Code,"CS451");
	strcpy(s->Courses.sem8[0].Course_Name,"Capstone Project Phase – II");
	s->Courses.sem8[0].Credits=4;
	s->Courses.sem8[0].No_Days_Present=0;
	s->Courses.sem8[0].No_Days_Total=0;
	s->Courses.sem8[0].Eligibility=0;
	s->Courses.sem8[0].Grade='\0';
	s->Courses.sem8[0].Examination_Block='-';
	strcpy(s->Courses.sem8[0].Examination_Date,"-");
	strcpy(s->Courses.sem8[0].Examination_Section,"-");
	strcpy(s->Courses.sem8[1].Course_Code,"CS452");
	strcpy(s->Courses.sem8[1].Course_Name,"Internship/Special Topic/Swamyam/MOOC/Study Abroad");
	s->Courses.sem8[1].Credits=8;
	s->Courses.sem8[1].No_Days_Present=0;
	s->Courses.sem8[1].No_Days_Total=0;
	s->Courses.sem8[1].Eligibility=0;
	s->Courses.sem8[1].Grade='\0';
	s->Courses.sem8[1].Examination_Block='-';
	strcpy(s->Courses.sem8[1].Examination_Date,"-");
	strcpy(s->Courses.sem8[1].Examination_Section,"-");
	strcpy(s->Courses.sem8[2].Course_Code,"CS453");
	strcpy(s->Courses.sem8[2].Course_Name,"Software Testing");
	s->Courses.sem8[2].Credits=2;
	s->Courses.sem8[2].No_Days_Present=0;
	s->Courses.sem8[2].No_Days_Total=0;
	s->Courses.sem8[2].Eligibility=0;
	s->Courses.sem8[2].Grade='\0';
	s->Courses.sem8[2].Examination_Block='\0';
	strcpy(s->Courses.sem8[2].Examination_Date,"\0");
	strcpy(s->Courses.sem8[2].Examination_Section,"\0");
}
void InitECE(student *s)
{
	//Semester 3
	s->Courses.no_courses_sem3=8;
	strcpy(s->Courses.sem3[0].Course_Code,"EC201");
	strcpy(s->Courses.sem3[0].Course_Name,"Mathematics for Electronics Engineers");
	s->Courses.sem3[0].Credits=4;
	s->Courses.sem3[0].No_Days_Present=0;
	s->Courses.sem3[0].No_Days_Total=0;
	s->Courses.sem3[0].Eligibility=0;
	s->Courses.sem3[0].Grade='\0';
	s->Courses.sem3[0].Examination_Block='\0';
	strcpy(s->Courses.sem3[0].Examination_Date,"\0");
	strcpy(s->Courses.sem3[0].Examination_Section,"\0");
	strcpy(s->Courses.sem3[1].Course_Code,"EC202");
	strcpy(s->Courses.sem3[1].Course_Name,"Network and Synthesis");
	s->Courses.sem3[1].Credits=4;
	s->Courses.sem3[1].No_Days_Present=0;
	s->Courses.sem3[1].No_Days_Total=0;
	s->Courses.sem3[1].Eligibility=0;
	s->Courses.sem3[1].Grade='\0';
	s->Courses.sem3[1].Examination_Block='\0';
	strcpy(s->Courses.sem3[1].Examination_Date,"\0");
	strcpy(s->Courses.sem3[1].Examination_Section,"\0");
	strcpy(s->Courses.sem3[2].Course_Code,"EC203");
	strcpy(s->Courses.sem3[2].Course_Name,"Signals and Systems");
	s->Courses.sem3[2].Credits=4;
	s->Courses.sem3[2].No_Days_Present=0;
	s->Courses.sem3[2].No_Days_Total=0;
	s->Courses.sem3[2].Eligibility=0;
	s->Courses.sem3[2].Grade='\0';
	s->Courses.sem3[2].Examination_Block='\0';
	strcpy(s->Courses.sem3[2].Examination_Date,"\0");
	strcpy(s->Courses.sem3[2].Examination_Section,"\0");
	strcpy(s->Courses.sem3[3].Course_Code,"EC204");
	strcpy(s->Courses.sem3[3].Course_Name,"Analog Circuit Design");
	s->Courses.sem3[3].Credits=4;
	s->Courses.sem3[3].No_Days_Present=0;
	s->Courses.sem3[3].No_Days_Total=0;
	s->Courses.sem3[3].Eligibility=0;
	s->Courses.sem3[3].Grade='\0';
	s->Courses.sem3[3].Examination_Block='\0';
	strcpy(s->Courses.sem3[3].Examination_Date,"\0");
	strcpy(s->Courses.sem3[3].Examination_Section,"\0");
	strcpy(s->Courses.sem3[4].Course_Code,"EC205");
	strcpy(s->Courses.sem3[4].Course_Name,"Computer Organization and Digital Design");
	s->Courses.sem3[4].Credits=4;
	s->Courses.sem3[4].No_Days_Present=0;
	s->Courses.sem3[4].No_Days_Total=0;
	s->Courses.sem3[4].Eligibility=0;
	s->Courses.sem3[4].Grade='\0';
	s->Courses.sem3[4].Examination_Block='\0';
	strcpy(s->Courses.sem3[4].Examination_Date,"\0");
	strcpy(s->Courses.sem3[4].Examination_Section,"\0");
	strcpy(s->Courses.sem3[5].Course_Code,"EC206");
	strcpy(s->Courses.sem3[5].Course_Name,"Analog Circuit Design Laboratory");
	s->Courses.sem3[5].Credits=1;
	s->Courses.sem3[5].No_Days_Present=0;
	s->Courses.sem3[5].No_Days_Total=0;
	s->Courses.sem3[5].Eligibility=0;
	s->Courses.sem3[5].Grade='\0';
	s->Courses.sem3[5].Examination_Block='-';
	strcpy(s->Courses.sem3[5].Examination_Date,"-");
	strcpy(s->Courses.sem3[5].Examination_Section,"-");
	strcpy(s->Courses.sem3[6].Course_Code,"EC207");
	strcpy(s->Courses.sem3[6].Course_Name,"Computer Organization and Digital Design Laboratory");
	s->Courses.sem3[6].Credits=1;
	s->Courses.sem3[6].No_Days_Present=0;
	s->Courses.sem3[6].No_Days_Total=0;
	s->Courses.sem3[6].Eligibility=0;
	s->Courses.sem3[6].Grade='\0';
	s->Courses.sem3[6].Examination_Block='-';
	strcpy(s->Courses.sem3[6].Examination_Date,"-");
	strcpy(s->Courses.sem3[6].Examination_Section,"-");
	strcpy(s->Courses.sem3[7].Course_Code,"EC208");
	strcpy(s->Courses.sem3[7].Course_Name,"Special Topic I");
	s->Courses.sem3[7].Credits=2;
	s->Courses.sem3[7].No_Days_Present=0;
	s->Courses.sem3[7].No_Days_Total=0;
	s->Courses.sem3[7].Eligibility=0;
	s->Courses.sem3[7].Grade='\0';
	s->Courses.sem3[7].Examination_Block='\0';
	strcpy(s->Courses.sem3[7].Examination_Date,"\0");
	strcpy(s->Courses.sem3[7].Examination_Section,"\0");
	//Semester 4
	s->Courses.no_courses_sem4=8;
	strcpy(s->Courses.sem4[0].Course_Code,"EC251");
	strcpy(s->Courses.sem4[0].Course_Name,"Linear Algebra");
	s->Courses.sem4[0].Credits=4;
	s->Courses.sem4[0].No_Days_Present=0;
	s->Courses.sem4[0].No_Days_Total=0;
	s->Courses.sem4[0].Eligibility=0;
	s->Courses.sem4[0].Grade='\0';
	s->Courses.sem4[0].Examination_Block='\0';
	strcpy(s->Courses.sem4[0].Examination_Date,"\0");
	strcpy(s->Courses.sem4[0].Examination_Section,"\0");
	strcpy(s->Courses.sem4[1].Course_Code,"EC252");
	strcpy(s->Courses.sem4[1].Course_Name,"Embedded System Design");
	s->Courses.sem4[1].Credits=4;
	s->Courses.sem4[1].No_Days_Present=0;
	s->Courses.sem4[1].No_Days_Total=0;
	s->Courses.sem4[1].Eligibility=0;
	s->Courses.sem4[1].Grade='\0';
	s->Courses.sem4[1].Examination_Block='\0';
	strcpy(s->Courses.sem4[1].Examination_Date,"\0");
	strcpy(s->Courses.sem4[1].Examination_Section,"\0");
	strcpy(s->Courses.sem4[2].Course_Code,"EC253");
	strcpy(s->Courses.sem4[2].Course_Name,"Electromagnetic Field Theory");
	s->Courses.sem4[2].Credits=4;
	s->Courses.sem4[2].No_Days_Present=0;
	s->Courses.sem4[2].No_Days_Total=0;
	s->Courses.sem4[2].Eligibility=0;
	s->Courses.sem4[2].Grade='\0';
	s->Courses.sem4[2].Examination_Block='\0';
	strcpy(s->Courses.sem4[2].Examination_Date,"\0");
	strcpy(s->Courses.sem4[2].Examination_Section,"\0");
	strcpy(s->Courses.sem4[3].Course_Code,"EC254");
	strcpy(s->Courses.sem4[3].Course_Name,"Principles of Digital Signal Processing");
	s->Courses.sem4[3].Credits=4;
	s->Courses.sem4[3].No_Days_Present=0;
	s->Courses.sem4[3].No_Days_Total=0;
	s->Courses.sem4[3].Eligibility=0;
	s->Courses.sem4[3].Grade='\0';
	s->Courses.sem4[3].Examination_Block='\0';
	strcpy(s->Courses.sem4[3].Examination_Date,"\0");
	strcpy(s->Courses.sem4[3].Examination_Section,"\0");
	strcpy(s->Courses.sem4[4].Course_Code,"EC255");
	strcpy(s->Courses.sem4[4].Course_Name,"Digital Communication");
	s->Courses.sem4[4].Credits=4;
	s->Courses.sem4[4].No_Days_Present=0;
	s->Courses.sem4[4].No_Days_Total=0;
	s->Courses.sem4[4].Eligibility=0;
	s->Courses.sem4[4].Grade='\0';
	s->Courses.sem4[4].Examination_Block='\0';
	strcpy(s->Courses.sem4[4].Examination_Date,"\0");
	strcpy(s->Courses.sem4[4].Examination_Section,"\0");
	strcpy(s->Courses.sem4[5].Course_Code,"EC256");
	strcpy(s->Courses.sem4[5].Course_Name,"Principles of Digital Signal Processing Laboratory");
	s->Courses.sem4[5].Credits=1;
	s->Courses.sem4[5].No_Days_Present=0;
	s->Courses.sem4[5].No_Days_Total=0;
	s->Courses.sem4[5].Eligibility=0;
	s->Courses.sem4[5].Grade='\0';
	s->Courses.sem4[5].Examination_Block='-';
	strcpy(s->Courses.sem4[5].Examination_Date,"-");
	strcpy(s->Courses.sem4[5].Examination_Section,"-");
	strcpy(s->Courses.sem4[6].Course_Code,"EC257");
	strcpy(s->Courses.sem4[6].Course_Name,"Embedded System Design Laboratory");
	s->Courses.sem4[6].Credits=1;
	s->Courses.sem4[6].No_Days_Present=0;
	s->Courses.sem4[6].No_Days_Total=0;
	s->Courses.sem4[6].Eligibility=0;
	s->Courses.sem4[6].Grade='\0';
	s->Courses.sem4[6].Examination_Block='-';
	strcpy(s->Courses.sem4[6].Examination_Date,"-");
	strcpy(s->Courses.sem4[6].Examination_Section,"-");
	strcpy(s->Courses.sem4[7].Course_Code,"EC258");
	strcpy(s->Courses.sem4[7].Course_Name,"Special Topic II");
	s->Courses.sem4[7].Credits=2;
	s->Courses.sem4[7].No_Days_Present=0;
	s->Courses.sem4[7].No_Days_Total=0;
	s->Courses.sem4[7].Eligibility=0;
	s->Courses.sem4[7].Grade='\0';
	s->Courses.sem4[7].Examination_Block='\0';
	strcpy(s->Courses.sem4[6].Examination_Date,"\0");
	strcpy(s->Courses.sem4[7].Examination_Section,"\0");
	//Semester 5
	s->Courses.no_courses_sem5=8;
	strcpy(s->Courses.sem5[0].Course_Code,"EC301");
	strcpy(s->Courses.sem5[0].Course_Name,"Communication Engineering");
	s->Courses.sem5[0].Credits=4;
	s->Courses.sem5[0].No_Days_Present=0;
	s->Courses.sem5[0].No_Days_Total=0;
	s->Courses.sem5[0].Eligibility=0;
	s->Courses.sem5[0].Grade='\0';
	s->Courses.sem5[0].Examination_Block='\0';
	strcpy(s->Courses.sem5[0].Examination_Date,"\0");
	strcpy(s->Courses.sem5[0].Examination_Section,"\0");
	strcpy(s->Courses.sem5[1].Course_Code,"EC302");
	strcpy(s->Courses.sem5[1].Course_Name,"Digital Image Processing");
	s->Courses.sem5[1].Credits=4;
	s->Courses.sem5[1].No_Days_Present=0;
	s->Courses.sem5[1].No_Days_Total=0;
	s->Courses.sem5[1].Eligibility=0;
	s->Courses.sem5[1].Grade='\0';
	s->Courses.sem5[1].Examination_Block='\0';
	strcpy(s->Courses.sem5[1].Examination_Date,"\0");
	strcpy(s->Courses.sem5[1].Examination_Section,"\0");
	strcpy(s->Courses.sem5[2].Course_Code,"EC303");
	strcpy(s->Courses.sem5[2].Course_Name,"Microwave Engineering");
	s->Courses.sem5[2].Credits=4;
	s->Courses.sem5[2].No_Days_Present=0;
	s->Courses.sem5[2].No_Days_Total=0;
	s->Courses.sem5[2].Eligibility=0;
	s->Courses.sem5[2].Grade='\0';
	s->Courses.sem5[2].Examination_Block='\0';
	strcpy(s->Courses.sem5[2].Examination_Date,"\0");
	strcpy(s->Courses.sem5[2].Examination_Section,"\0");
	strcpy(s->Courses.sem5[3].Course_Code,"EC304");
	strcpy(s->Courses.sem5[3].Course_Name,"Communication Engineering Laboratory");
	s->Courses.sem5[3].Credits=1;
	s->Courses.sem5[3].No_Days_Present=0;
	s->Courses.sem5[3].No_Days_Total=0;
	s->Courses.sem5[3].Eligibility=0;
	s->Courses.sem5[3].Grade='\0';
	s->Courses.sem5[3].Examination_Block='-';
	strcpy(s->Courses.sem5[3].Examination_Date,"-");
	strcpy(s->Courses.sem5[3].Examination_Section,"-");
	strcpy(s->Courses.sem5[4].Course_Code,"EC305");
	strcpy(s->Courses.sem5[4].Course_Name,"Digital Image Processing Laboratory");
	s->Courses.sem5[4].Credits=1;
	s->Courses.sem5[4].No_Days_Present=0;
	s->Courses.sem5[4].No_Days_Total=0;
	s->Courses.sem5[4].Eligibility=0;
	s->Courses.sem5[4].Grade='\0';
	s->Courses.sem5[4].Examination_Block='-';
	strcpy(s->Courses.sem5[4].Examination_Date,"-");
	strcpy(s->Courses.sem5[4].Examination_Section,"-");
	strcpy(s->Courses.sem5[5].Course_Code,"EC306");
	strcpy(s->Courses.sem5[5].Course_Name,"Testing of VLSI Circuits");
	s->Courses.sem5[5].Credits=4;
	s->Courses.sem5[5].No_Days_Present=0;
	s->Courses.sem5[5].No_Days_Total=0;
	s->Courses.sem5[5].Eligibility=0;
	s->Courses.sem5[5].Grade='\0';
	s->Courses.sem5[5].Examination_Block='\0';
	strcpy(s->Courses.sem5[5].Examination_Date,"\0");
	strcpy(s->Courses.sem5[5].Examination_Section,"\0");
	strcpy(s->Courses.sem5[6].Course_Code,"EC307");
	strcpy(s->Courses.sem5[6].Course_Name,"High Speed Digital Interfaces");
	s->Courses.sem5[6].Credits=4;
	s->Courses.sem5[6].No_Days_Present=0;
	s->Courses.sem5[6].No_Days_Total=0;
	s->Courses.sem5[6].Eligibility=0;
	s->Courses.sem5[6].Grade='\0';
	s->Courses.sem5[6].Examination_Block='\0';
	strcpy(s->Courses.sem5[6].Examination_Date,"\0");
	strcpy(s->Courses.sem5[6].Examination_Section,"\0");
	strcpy(s->Courses.sem5[7].Course_Code,"EC308");
	strcpy(s->Courses.sem5[7].Course_Name,"Special Topic III");
	s->Courses.sem5[7].Credits=2;
	s->Courses.sem5[7].No_Days_Present=0;
	s->Courses.sem5[7].No_Days_Total=0;
	s->Courses.sem5[7].Eligibility=0;
	s->Courses.sem5[7].Grade='\0';
	s->Courses.sem5[7].Examination_Block='\0';
	strcpy(s->Courses.sem5[7].Examination_Date,"\0");
	strcpy(s->Courses.sem5[7].Examination_Section,"\0");
	//Semester 6
	s->Courses.no_courses_sem6=7;
	strcpy(s->Courses.sem6[0].Course_Code,"EC351");
	strcpy(s->Courses.sem6[0].Course_Name,"Computer Communication Networks");
	s->Courses.sem6[0].Credits=4;
	s->Courses.sem6[0].No_Days_Present=0;
	s->Courses.sem6[0].No_Days_Total=0;
	s->Courses.sem6[0].Eligibility=0;
	s->Courses.sem6[0].Grade='\0';
	s->Courses.sem6[0].Examination_Block='\0';
	strcpy(s->Courses.sem6[0].Examination_Date,"\0");
	strcpy(s->Courses.sem6[0].Examination_Section,"\0");
	strcpy(s->Courses.sem6[1].Course_Code,"EC352");
	strcpy(s->Courses.sem6[1].Course_Name,"Digital Communication");
	s->Courses.sem6[1].Credits=4;
	s->Courses.sem6[1].No_Days_Present=0;
	s->Courses.sem6[1].No_Days_Total=0;
	s->Courses.sem6[1].Eligibility=0;
	s->Courses.sem6[1].Grade='\0';
	s->Courses.sem6[1].Examination_Block='\0';
	strcpy(s->Courses.sem6[1].Examination_Date,"\0");
	strcpy(s->Courses.sem6[1].Examination_Section,"\0");
	strcpy(s->Courses.sem6[2].Course_Code,"EC353");
	strcpy(s->Courses.sem6[2].Course_Name,"Antenna Theory and Propagation");
	s->Courses.sem6[2].Credits=4;
	s->Courses.sem6[2].No_Days_Present=0;
	s->Courses.sem6[2].No_Days_Total=0;
	s->Courses.sem6[2].Eligibility=0;
	s->Courses.sem6[2].Grade='\0';
	s->Courses.sem6[2].Examination_Block='\0';
	strcpy(s->Courses.sem6[2].Examination_Date,"\0");
	strcpy(s->Courses.sem6[2].Examination_Section,"\0");
	strcpy(s->Courses.sem6[3].Course_Code,"EC354");
	strcpy(s->Courses.sem6[3].Course_Name,"Computer Networks Communication Laboratory");
	s->Courses.sem6[3].Credits=1;
	s->Courses.sem6[3].No_Days_Present=0;
	s->Courses.sem6[3].No_Days_Total=0;
	s->Courses.sem6[3].Eligibility=0;
	s->Courses.sem6[3].Grade='\0';
	s->Courses.sem6[3].Examination_Block='-';
	strcpy(s->Courses.sem6[3].Examination_Date,"-");
	strcpy(s->Courses.sem6[3].Examination_Section,"-");
	strcpy(s->Courses.sem6[4].Course_Code,"EC355");
	strcpy(s->Courses.sem6[4].Course_Name,"Digital Communication Laboratory");
	s->Courses.sem6[4].Credits=1;
	s->Courses.sem6[4].No_Days_Present=0;
	s->Courses.sem6[4].No_Days_Total=0;
	s->Courses.sem6[4].Eligibility=0;
	s->Courses.sem6[4].Grade='\0';
	s->Courses.sem6[4].Examination_Block='-';
	strcpy(s->Courses.sem6[4].Examination_Date,"-");
	strcpy(s->Courses.sem6[4].Examination_Section,"-");
	strcpy(s->Courses.sem6[5].Course_Code,"EC356");
	strcpy(s->Courses.sem6[5].Course_Name,"Timing Analysis of Digital Circuits");
	s->Courses.sem6[5].Credits=4;
	s->Courses.sem6[5].No_Days_Present=0;
	s->Courses.sem6[5].No_Days_Total=0;
	s->Courses.sem6[5].Eligibility=0;
	s->Courses.sem6[5].Grade='\0';
	s->Courses.sem6[5].Examination_Block='\0';
	strcpy(s->Courses.sem6[5].Examination_Date,"\0");
	strcpy(s->Courses.sem6[5].Examination_Section,"\0");
	strcpy(s->Courses.sem6[6].Course_Code,"EC357");
	strcpy(s->Courses.sem6[6].Course_Name,"Memory Design and Testing");
	s->Courses.sem6[6].Credits=4;
	s->Courses.sem6[6].No_Days_Present=0;
	s->Courses.sem6[6].No_Days_Total=0;
	s->Courses.sem6[6].Eligibility=0;
	s->Courses.sem6[6].Grade='\0';
	s->Courses.sem6[6].Examination_Block='\0';
	strcpy(s->Courses.sem6[6].Examination_Date,"\0");
	strcpy(s->Courses.sem6[6].Examination_Section,"\0");
	//Semester 7
	s->Courses.no_courses_sem7=5;
	strcpy(s->Courses.sem7[0].Course_Code,"EC401");
	strcpy(s->Courses.sem7[0].Course_Name,"Microwave Filter Design");
	s->Courses.sem7[0].Credits=4;
	s->Courses.sem7[0].No_Days_Present=0;
	s->Courses.sem7[0].No_Days_Total=0;
	s->Courses.sem7[0].Eligibility=0;
	s->Courses.sem7[0].Grade='\0';
	s->Courses.sem7[0].Examination_Block='\0';
	strcpy(s->Courses.sem7[0].Examination_Date,"-");
	strcpy(s->Courses.sem7[0].Examination_Section,"\0");
	strcpy(s->Courses.sem7[1].Course_Code,"EC402");
	strcpy(s->Courses.sem7[1].Course_Name,"Analog Integrated Circuits");
	s->Courses.sem7[1].Credits=4;
	s->Courses.sem7[1].No_Days_Present=0;
	s->Courses.sem7[1].No_Days_Total=0;
	s->Courses.sem7[1].Eligibility=0;
	s->Courses.sem7[1].Grade='\0';
	s->Courses.sem7[1].Examination_Block='\0';
	strcpy(s->Courses.sem7[1].Examination_Date,"-");
	strcpy(s->Courses.sem7[1].Examination_Section,"\0");
	strcpy(s->Courses.sem7[2].Course_Code,"EC403");
	strcpy(s->Courses.sem7[2].Course_Name,"Project Work - I");
	s->Courses.sem7[2].Credits=4;
	s->Courses.sem7[2].No_Days_Present=0;
	s->Courses.sem7[2].No_Days_Total=0;
	s->Courses.sem7[2].Eligibility=0;
	s->Courses.sem7[2].Grade='\0';
	s->Courses.sem7[2].Examination_Block='-';
	strcpy(s->Courses.sem7[2].Examination_Date,"-");
	strcpy(s->Courses.sem7[2].Examination_Section,"-");
	strcpy(s->Courses.sem7[3].Course_Code,"EC404");
	strcpy(s->Courses.sem7[3].Course_Name,"Parallel and Distributed Computing");
	s->Courses.sem7[3].Credits=4;
	s->Courses.sem7[3].No_Days_Present=0;
	s->Courses.sem7[3].No_Days_Total=0;
	s->Courses.sem7[3].Eligibility=0;
	s->Courses.sem7[3].Grade='\0';
	s->Courses.sem7[3].Examination_Block='\0';
	strcpy(s->Courses.sem7[3].Examination_Date,"-");
	strcpy(s->Courses.sem7[3].Examination_Section,"\0");
	strcpy(s->Courses.sem7[4].Course_Code,"EC405");
	strcpy(s->Courses.sem7[4].Course_Name,"Wireless Networking Fundamentals");
	s->Courses.sem7[4].Credits=4;
	s->Courses.sem7[4].No_Days_Present=0;
	s->Courses.sem7[4].No_Days_Total=0;
	s->Courses.sem7[4].Eligibility=0;
	s->Courses.sem7[4].Grade='\0';
	s->Courses.sem7[4].Examination_Block='\0';
	strcpy(s->Courses.sem7[4].Examination_Date,"-");
	strcpy(s->Courses.sem7[4].Examination_Section,"\0");
	//Semester 8
	s->Courses.no_courses_sem8=6;
	strcpy(s->Courses.sem8[0].Course_Code,"EC451");
	strcpy(s->Courses.sem8[0].Course_Name,"Project Work-II");
	s->Courses.sem8[0].Credits=4;
	s->Courses.sem8[0].No_Days_Present=0;
	s->Courses.sem8[0].No_Days_Total=0;
	s->Courses.sem8[0].Eligibility=0;
	s->Courses.sem8[0].Grade='\0';
	s->Courses.sem8[0].Examination_Block='-';
	strcpy(s->Courses.sem8[0].Examination_Date,"-");
	strcpy(s->Courses.sem8[0].Examination_Section,"-");
	strcpy(s->Courses.sem8[1].Course_Code,"EC452");
	strcpy(s->Courses.sem8[1].Course_Name,"Internship");
	s->Courses.sem8[1].Credits=8;
	s->Courses.sem8[1].No_Days_Present=0;
	s->Courses.sem8[1].No_Days_Total=0;
	s->Courses.sem8[1].Eligibility=0;
	s->Courses.sem8[1].Grade='\0';
	s->Courses.sem8[1].Examination_Block='-';
	strcpy(s->Courses.sem8[1].Examination_Date,"-");
	strcpy(s->Courses.sem8[1].Examination_Section,"-");
	strcpy(s->Courses.sem8[2].Course_Code,"EC453");
	strcpy(s->Courses.sem8[2].Course_Name,"System Verilog");
	s->Courses.sem8[2].Credits=2;
	s->Courses.sem8[2].No_Days_Present=0;
	s->Courses.sem8[2].No_Days_Total=0;
	s->Courses.sem8[2].Eligibility=0;
	s->Courses.sem8[2].Grade='\0';
	s->Courses.sem8[2].Examination_Block='\0';
	strcpy(s->Courses.sem8[2].Examination_Date,"\0");
	strcpy(s->Courses.sem8[2].Examination_Section,"\0");
	strcpy(s->Courses.sem8[3].Course_Code,"EC454");
	strcpy(s->Courses.sem8[3].Course_Name,"Physics & Technology of Semiconductor Nanoscale Devices");
	s->Courses.sem8[3].Credits=2;
	s->Courses.sem8[3].No_Days_Present=0;
	s->Courses.sem8[3].No_Days_Total=0;
	s->Courses.sem8[3].Eligibility=0;
	s->Courses.sem8[3].Grade='\0';
	s->Courses.sem8[3].Examination_Block='\0';
	strcpy(s->Courses.sem8[3].Examination_Date,"\0");
	strcpy(s->Courses.sem8[3].Examination_Section,"\0");
	strcpy(s->Courses.sem8[4].Course_Code,"EC455");
	strcpy(s->Courses.sem8[4].Course_Name,"High Frequency Amplifier Design and Operation");
	s->Courses.sem8[4].Credits=2;
	s->Courses.sem8[4].No_Days_Present=0;
	s->Courses.sem8[4].No_Days_Total=0;
	s->Courses.sem8[4].Eligibility=0;
	s->Courses.sem8[4].Grade='\0';
	s->Courses.sem8[4].Examination_Block='\0';
	strcpy(s->Courses.sem8[4].Examination_Date,"\0");
	strcpy(s->Courses.sem8[4].Examination_Section,"\0");
	strcpy(s->Courses.sem8[5].Course_Code,"EC456");
	strcpy(s->Courses.sem8[5].Course_Name,"Multimedia Communication");
	s->Courses.sem8[5].Credits=2;
	s->Courses.sem8[5].No_Days_Present=0;
	s->Courses.sem8[5].No_Days_Total=0;
	s->Courses.sem8[5].Eligibility=0;
	s->Courses.sem8[5].Grade='\0';
	s->Courses.sem8[5].Examination_Block='\0';
	strcpy(s->Courses.sem8[5].Examination_Date,"\0");
	strcpy(s->Courses.sem8[5].Examination_Section,"\0");
}
void InitME(student *s)
{
	//Semester 3
	s->Courses.no_courses_sem3=7;
	strcpy(s->Courses.sem3[0].Course_Code,"ME201");
	strcpy(s->Courses.sem3[0].Course_Name,"Material Science and Metallurgy");
	s->Courses.sem3[0].Credits=4;
	s->Courses.sem3[0].No_Days_Present=0;
	s->Courses.sem3[0].No_Days_Total=0;
	s->Courses.sem3[0].Eligibility=0;
	s->Courses.sem3[0].Grade='\0';
	s->Courses.sem3[0].Examination_Block='\0';
	strcpy(s->Courses.sem3[0].Examination_Date,"\0");
	strcpy(s->Courses.sem3[0].Examination_Section,"\0");
	strcpy(s->Courses.sem3[1].Course_Code,"ME202");
	strcpy(s->Courses.sem3[1].Course_Name,"Engineering Thermodynamics");
	s->Courses.sem3[1].Credits=4;
	s->Courses.sem3[1].No_Days_Present=0;
	s->Courses.sem3[1].No_Days_Total=0;
	s->Courses.sem3[1].Eligibility=0;
	s->Courses.sem3[1].Grade='\0';
	s->Courses.sem3[1].Examination_Block='\0';
	strcpy(s->Courses.sem3[1].Examination_Date,"\0");
	strcpy(s->Courses.sem3[1].Examination_Section,"\0");
	strcpy(s->Courses.sem3[2].Course_Code,"ME203");
	strcpy(s->Courses.sem3[2].Course_Name,"Engineering Mechanics - Dynamics");
	s->Courses.sem3[2].Credits=4;
	s->Courses.sem3[2].No_Days_Present=0;
	s->Courses.sem3[2].No_Days_Total=0;
	s->Courses.sem3[2].Eligibility=0;
	s->Courses.sem3[2].Grade='\0';
	s->Courses.sem3[2].Examination_Block='\0';
	strcpy(s->Courses.sem3[2].Examination_Date,"\0");
	strcpy(s->Courses.sem3[2].Examination_Section,"\0");
	strcpy(s->Courses.sem3[3].Course_Code,"ME204");
	strcpy(s->Courses.sem3[3].Course_Name,"Mechanics of Solids");
	s->Courses.sem3[3].Credits=4;
	s->Courses.sem3[3].No_Days_Present=0;
	s->Courses.sem3[3].No_Days_Total=0;
	s->Courses.sem3[3].Eligibility=0;
	s->Courses.sem3[3].Grade='\0';
	s->Courses.sem3[3].Examination_Block='\0';
	strcpy(s->Courses.sem3[3].Examination_Date,"\0");
	strcpy(s->Courses.sem3[3].Examination_Section,"\0");
	strcpy(s->Courses.sem3[4].Course_Code,"ME205");
	strcpy(s->Courses.sem3[4].Course_Name,"Material Testing");
	s->Courses.sem3[4].Credits=4;
	s->Courses.sem3[4].No_Days_Present=0;
	s->Courses.sem3[4].No_Days_Total=0;
	s->Courses.sem3[4].Eligibility=0;
	s->Courses.sem3[4].Grade='\0';
	s->Courses.sem3[4].Examination_Block='\0';
	strcpy(s->Courses.sem3[4].Examination_Date,"\0");
	strcpy(s->Courses.sem3[4].Examination_Section,"\0");
	strcpy(s->Courses.sem3[5].Course_Code,"ME206");
	strcpy(s->Courses.sem3[5].Course_Name,"Machine Drawing");
	s->Courses.sem3[5].Credits=1;
	s->Courses.sem3[5].No_Days_Present=0;
	s->Courses.sem3[5].No_Days_Total=0;
	s->Courses.sem3[5].Eligibility=0;
	s->Courses.sem3[5].Grade='\0';
	s->Courses.sem3[5].Examination_Block='-';
	strcpy(s->Courses.sem3[5].Examination_Date,"-");
	strcpy(s->Courses.sem3[5].Examination_Section,"-");
	strcpy(s->Courses.sem3[6].Course_Code,"EC207");
	strcpy(s->Courses.sem3[6].Course_Name,"Special Topic");
	s->Courses.sem3[6].Credits=1;
	s->Courses.sem3[6].No_Days_Present=0;
	s->Courses.sem3[6].No_Days_Total=0;
	s->Courses.sem3[6].Eligibility=0;
	s->Courses.sem3[6].Grade='\0';
	s->Courses.sem3[6].Examination_Block='\0';
	strcpy(s->Courses.sem3[6].Examination_Date,"\0");
	strcpy(s->Courses.sem3[6].Examination_Section,"\0");
	//Semester 4
	s->Courses.no_courses_sem4=7;
	strcpy(s->Courses.sem4[0].Course_Code,"ME251");
	strcpy(s->Courses.sem4[0].Course_Name,"Mechanics of Fluids");
	s->Courses.sem4[0].Credits=4;
	s->Courses.sem4[0].No_Days_Present=0;
	s->Courses.sem4[0].No_Days_Total=0;
	s->Courses.sem4[0].Eligibility=0;
	s->Courses.sem4[0].Grade='\0';
	s->Courses.sem4[0].Examination_Block='\0';
	strcpy(s->Courses.sem4[0].Examination_Date,"\0");
	strcpy(s->Courses.sem4[0].Examination_Section,"\0");
	strcpy(s->Courses.sem4[1].Course_Code,"ME252");
	strcpy(s->Courses.sem4[1].Course_Name,"Mechanics of Machines and Mechanisms");
	s->Courses.sem4[1].Credits=4;
	s->Courses.sem4[1].No_Days_Present=0;
	s->Courses.sem4[1].No_Days_Total=0;
	s->Courses.sem4[1].Eligibility=0;
	s->Courses.sem4[1].Grade='\0';
	s->Courses.sem4[1].Examination_Block='\0';
	strcpy(s->Courses.sem4[1].Examination_Date,"\0");
	strcpy(s->Courses.sem4[1].Examination_Section,"\0");
	strcpy(s->Courses.sem4[2].Course_Code,"ME253");
	strcpy(s->Courses.sem4[2].Course_Name,"Measurement Science and Metrology");
	s->Courses.sem4[2].Credits=4;
	s->Courses.sem4[2].No_Days_Present=0;
	s->Courses.sem4[2].No_Days_Total=0;
	s->Courses.sem4[2].Eligibility=0;
	s->Courses.sem4[2].Grade='\0';
	s->Courses.sem4[2].Examination_Block='\0';
	strcpy(s->Courses.sem4[2].Examination_Date,"\0");
	strcpy(s->Courses.sem4[2].Examination_Section,"\0");
	strcpy(s->Courses.sem4[3].Course_Code,"ME254");
	strcpy(s->Courses.sem4[3].Course_Name,"Manufacturing Technology");
	s->Courses.sem4[3].Credits=4;
	s->Courses.sem4[3].No_Days_Present=0;
	s->Courses.sem4[3].No_Days_Total=0;
	s->Courses.sem4[3].Eligibility=0;
	s->Courses.sem4[3].Grade='\0';
	s->Courses.sem4[3].Examination_Block='\0';
	strcpy(s->Courses.sem4[3].Examination_Date,"\0");
	strcpy(s->Courses.sem4[3].Examination_Section,"\0");
	strcpy(s->Courses.sem4[4].Course_Code,"ME255");
	strcpy(s->Courses.sem4[4].Course_Name,"Metal Casting and Welding Laboratory");
	s->Courses.sem4[4].Credits=1;
	s->Courses.sem4[4].No_Days_Present=0;
	s->Courses.sem4[4].No_Days_Total=0;
	s->Courses.sem4[4].Eligibility=0;
	s->Courses.sem4[4].Grade='\0';
	s->Courses.sem4[4].Examination_Block='-';
	strcpy(s->Courses.sem4[4].Examination_Date,"-");
	strcpy(s->Courses.sem4[4].Examination_Section,"-");
	strcpy(s->Courses.sem4[5].Course_Code,"ME256");
	strcpy(s->Courses.sem4[5].Course_Name,"Fluid Mechanics and Machinery");
	s->Courses.sem4[5].Credits=1;
	s->Courses.sem4[5].No_Days_Present=0;
	s->Courses.sem4[5].No_Days_Total=0;
	s->Courses.sem4[5].Eligibility=0;
	s->Courses.sem4[5].Grade='\0';
	s->Courses.sem4[5].Examination_Block='-';
	strcpy(s->Courses.sem4[5].Examination_Date,"-");
	strcpy(s->Courses.sem4[5].Examination_Section,"-");
	strcpy(s->Courses.sem4[6].Course_Code,"ME257");
	strcpy(s->Courses.sem4[6].Course_Name,"Design Engineering");
	s->Courses.sem4[6].Credits=2;
	s->Courses.sem4[6].No_Days_Present=0;
	s->Courses.sem4[6].No_Days_Total=0;
	s->Courses.sem4[6].Eligibility=0;
	s->Courses.sem4[6].Grade='\0';
	s->Courses.sem4[6].Examination_Block='\0';
	strcpy(s->Courses.sem4[6].Examination_Date,"\0");
	strcpy(s->Courses.sem4[6].Examination_Section,"\0");
	//Semester 5
	s->Courses.no_courses_sem5=8;
	strcpy(s->Courses.sem5[0].Course_Code,"ME301");
	strcpy(s->Courses.sem5[0].Course_Name,"Design of Machine Elements");
	s->Courses.sem5[0].Credits=4;
	s->Courses.sem5[0].No_Days_Present=0;
	s->Courses.sem5[0].No_Days_Total=0;
	s->Courses.sem5[0].Eligibility=0;
	s->Courses.sem5[0].Grade='\0';
	s->Courses.sem5[0].Examination_Block='\0';
	strcpy(s->Courses.sem5[0].Examination_Date,"\0");
	strcpy(s->Courses.sem5[0].Examination_Section,"\0");
	strcpy(s->Courses.sem5[1].Course_Code,"ME302");
	strcpy(s->Courses.sem5[1].Course_Name,"Principles of Energy Conversion");
	s->Courses.sem5[1].Credits=4;
	s->Courses.sem5[1].No_Days_Present=0;
	s->Courses.sem5[1].No_Days_Total=0;
	s->Courses.sem5[1].Eligibility=0;
	s->Courses.sem5[1].Grade='\0';
	s->Courses.sem5[1].Examination_Block='\0';
	strcpy(s->Courses.sem5[1].Examination_Date,"\0");
	strcpy(s->Courses.sem5[1].Examination_Section,"\0");
	strcpy(s->Courses.sem5[2].Course_Code,"ME303");
	strcpy(s->Courses.sem5[2].Course_Name,"Manufacturing Processes and CIM");
	s->Courses.sem5[2].Credits=4;
	s->Courses.sem5[2].No_Days_Present=0;
	s->Courses.sem5[2].No_Days_Total=0;
	s->Courses.sem5[2].Eligibility=0;
	s->Courses.sem5[2].Grade='\0';
	s->Courses.sem5[2].Examination_Block='\0';
	strcpy(s->Courses.sem5[2].Examination_Date,"\0");
	strcpy(s->Courses.sem5[2].Examination_Section,"\0");
	strcpy(s->Courses.sem5[3].Course_Code,"ME304");
	strcpy(s->Courses.sem5[3].Course_Name,"Machine Shop Practice");
	s->Courses.sem5[3].Credits=1;
	s->Courses.sem5[3].No_Days_Present=0;
	s->Courses.sem5[3].No_Days_Total=0;
	s->Courses.sem5[3].Eligibility=0;
	s->Courses.sem5[3].Grade='\0';
	s->Courses.sem5[3].Examination_Block='-';
	strcpy(s->Courses.sem5[3].Examination_Date,"-");
	strcpy(s->Courses.sem5[3].Examination_Section,"-");
	strcpy(s->Courses.sem5[4].Course_Code,"ME305");
	strcpy(s->Courses.sem5[4].Course_Name,"Energy Conversion Laboratory");
	s->Courses.sem5[4].Credits=1;
	s->Courses.sem5[4].No_Days_Present=0;
	s->Courses.sem5[4].No_Days_Total=0;
	s->Courses.sem5[4].Eligibility=0;
	s->Courses.sem5[4].Grade='\0';
	s->Courses.sem5[4].Examination_Block='-';
	strcpy(s->Courses.sem5[4].Examination_Date,"-");
	strcpy(s->Courses.sem5[4].Examination_Section,"-");
	strcpy(s->Courses.sem5[5].Course_Code,"ME306");
	strcpy(s->Courses.sem5[5].Course_Name,"Vehicle Dynamics");
	s->Courses.sem5[5].Credits=4;
	s->Courses.sem5[5].No_Days_Present=0;
	s->Courses.sem5[5].No_Days_Total=0;
	s->Courses.sem5[5].Eligibility=0;
	s->Courses.sem5[5].Grade='\0';
	s->Courses.sem5[5].Examination_Block='\0';
	strcpy(s->Courses.sem5[5].Examination_Date,"\0");
	strcpy(s->Courses.sem5[5].Examination_Section,"\0");
	strcpy(s->Courses.sem5[6].Course_Code,"ME307");
	strcpy(s->Courses.sem5[6].Course_Name,"Sustainable Energy Systems");
	s->Courses.sem5[6].Credits=4;
	s->Courses.sem5[6].No_Days_Present=0;
	s->Courses.sem5[6].No_Days_Total=0;
	s->Courses.sem5[6].Eligibility=0;
	s->Courses.sem5[6].Grade='\0';
	s->Courses.sem5[6].Examination_Block='\0';
	strcpy(s->Courses.sem5[6].Examination_Date,"\0");
	strcpy(s->Courses.sem5[6].Examination_Section,"\0");
	strcpy(s->Courses.sem5[7].Course_Code,"ME308");
	strcpy(s->Courses.sem5[7].Course_Name,"Design Engineering");
	s->Courses.sem5[7].Credits=2;
	s->Courses.sem5[7].No_Days_Present=0;
	s->Courses.sem5[7].No_Days_Total=0;
	s->Courses.sem5[7].Eligibility=0;
	s->Courses.sem5[7].Grade='\0';
	s->Courses.sem5[7].Examination_Block='\0';
	strcpy(s->Courses.sem5[7].Examination_Date,"\0");
	strcpy(s->Courses.sem5[7].Examination_Section,"\0");
	//Semester 6
	s->Courses.no_courses_sem6=7;
	strcpy(s->Courses.sem6[0].Course_Code,"ME351");
	strcpy(s->Courses.sem6[0].Course_Name,"Control Engineering");
	s->Courses.sem6[0].Credits=4;
	s->Courses.sem6[0].No_Days_Present=0;
	s->Courses.sem6[0].No_Days_Total=0;
	s->Courses.sem6[0].Eligibility=0;
	s->Courses.sem6[0].Grade='\0';
	s->Courses.sem6[0].Examination_Block='\0';
	strcpy(s->Courses.sem6[0].Examination_Date,"\0");
	strcpy(s->Courses.sem6[0].Examination_Section,"\0");
	strcpy(s->Courses.sem6[1].Course_Code,"ME352");
	strcpy(s->Courses.sem6[1].Course_Name,"Heat Transfer");
	s->Courses.sem6[1].Credits=4;
	s->Courses.sem6[1].No_Days_Present=0;
	s->Courses.sem6[1].No_Days_Total=0;
	s->Courses.sem6[1].Eligibility=0;
	s->Courses.sem6[1].Grade='\0';
	s->Courses.sem6[1].Examination_Block='\0';
	strcpy(s->Courses.sem6[1].Examination_Date,"\0");
	strcpy(s->Courses.sem6[1].Examination_Section,"\0");
	strcpy(s->Courses.sem6[2].Course_Code,"ME353");
	strcpy(s->Courses.sem6[2].Course_Name,"Metal Forming Processes and Non Traditional Machining");
	s->Courses.sem6[2].Credits=4;
	s->Courses.sem6[2].No_Days_Present=0;
	s->Courses.sem6[2].No_Days_Total=0;
	s->Courses.sem6[2].Eligibility=0;
	s->Courses.sem6[2].Grade='\0';
	s->Courses.sem6[2].Examination_Block='\0';
	strcpy(s->Courses.sem6[2].Examination_Date,"\0");
	strcpy(s->Courses.sem6[2].Examination_Section,"\0");
	strcpy(s->Courses.sem6[3].Course_Code,"ME354");
	strcpy(s->Courses.sem6[3].Course_Name,"Dynamics and Design Laboratory");
	s->Courses.sem6[3].Credits=1;
	s->Courses.sem6[3].No_Days_Present=0;
	s->Courses.sem6[3].No_Days_Total=0;
	s->Courses.sem6[3].Eligibility=0;
	s->Courses.sem6[3].Grade='\0';
	s->Courses.sem6[3].Examination_Block='-';
	strcpy(s->Courses.sem6[3].Examination_Date,"-");
	strcpy(s->Courses.sem6[3].Examination_Section,"-");
	strcpy(s->Courses.sem6[4].Course_Code,"ME355");
	strcpy(s->Courses.sem6[4].Course_Name,"Heat Transfer Laboratory");
	s->Courses.sem6[4].Credits=1;
	s->Courses.sem6[4].No_Days_Present=0;
	s->Courses.sem6[4].No_Days_Total=0;
	s->Courses.sem6[4].Eligibility=0;
	s->Courses.sem6[4].Grade='\0';
	s->Courses.sem6[4].Examination_Block='-';
	strcpy(s->Courses.sem6[4].Examination_Date,"-");
	strcpy(s->Courses.sem6[4].Examination_Section,"-");
	strcpy(s->Courses.sem6[5].Course_Code,"ME356");
	strcpy(s->Courses.sem6[5].Course_Name,"Mechanical Vibrations");
	s->Courses.sem6[5].Credits=4;
	s->Courses.sem6[5].No_Days_Present=0;
	s->Courses.sem6[5].No_Days_Total=0;
	s->Courses.sem6[5].Eligibility=0;
	s->Courses.sem6[5].Grade='\0';
	s->Courses.sem6[5].Examination_Block='\0';
	strcpy(s->Courses.sem6[5].Examination_Date,"\0");
	strcpy(s->Courses.sem6[5].Examination_Section,"\0");
	strcpy(s->Courses.sem6[6].Course_Code,"ME357");
	strcpy(s->Courses.sem6[6].Course_Name,"Computational Fluid Dynamics");
	s->Courses.sem6[6].Credits=4;
	s->Courses.sem6[6].No_Days_Present=0;
	s->Courses.sem6[6].No_Days_Total=0;
	s->Courses.sem6[6].Eligibility=0;
	s->Courses.sem6[6].Grade='\0';
	s->Courses.sem6[6].Examination_Block='\0';
	strcpy(s->Courses.sem6[6].Examination_Date,"\0");
	strcpy(s->Courses.sem6[6].Examination_Section,"\0");
	//Semester 7
	s->Courses.no_courses_sem7=4;
	strcpy(s->Courses.sem7[0].Course_Code,"ME401");
	strcpy(s->Courses.sem7[0].Course_Name,"Mechanical Vibrations");
	s->Courses.sem7[0].Credits=4;
	s->Courses.sem7[0].No_Days_Present=0;
	s->Courses.sem7[0].No_Days_Total=0;
	s->Courses.sem7[0].Eligibility=0;
	s->Courses.sem7[0].Grade='\0';
	s->Courses.sem7[0].Examination_Block='\0';
	strcpy(s->Courses.sem7[0].Examination_Date,"-");
	strcpy(s->Courses.sem7[0].Examination_Section,"\0");
	strcpy(s->Courses.sem7[1].Course_Code,"ME402");
	strcpy(s->Courses.sem7[1].Course_Name,"Principles of Aerodynamics");
	s->Courses.sem7[1].Credits=4;
	s->Courses.sem7[1].No_Days_Present=0;
	s->Courses.sem7[1].No_Days_Total=0;
	s->Courses.sem7[1].Eligibility=0;
	s->Courses.sem7[1].Grade='\0';
	s->Courses.sem7[1].Examination_Block='\0';
	strcpy(s->Courses.sem7[1].Examination_Date,"-");
	strcpy(s->Courses.sem7[1].Examination_Section,"\0");
	strcpy(s->Courses.sem7[2].Course_Code,"ME403");
	strcpy(s->Courses.sem7[2].Course_Name,"Computational Rotor Dynamics");
	s->Courses.sem7[2].Credits=4;
	s->Courses.sem7[2].No_Days_Present=0;
	s->Courses.sem7[2].No_Days_Total=0;
	s->Courses.sem7[2].Eligibility=0;
	s->Courses.sem7[2].Grade='\0';
	s->Courses.sem7[2].Examination_Block='\0';
	strcpy(s->Courses.sem7[2].Examination_Date,"-");
	strcpy(s->Courses.sem7[2].Examination_Section,"\0");
	strcpy(s->Courses.sem7[3].Course_Code,"ME404");
	strcpy(s->Courses.sem7[3].Course_Name,"Project Work Phase - I");
	s->Courses.sem7[3].Credits=4;
	s->Courses.sem7[3].No_Days_Present=0;
	s->Courses.sem7[3].No_Days_Total=0;
	s->Courses.sem7[3].Eligibility=0;
	s->Courses.sem7[3].Grade='\0';
	s->Courses.sem7[3].Examination_Block='-';
	strcpy(s->Courses.sem7[3].Examination_Date,"-");
	strcpy(s->Courses.sem7[3].Examination_Section,"-");
	//Semester 8
	s->Courses.no_courses_sem8=3;
	strcpy(s->Courses.sem8[0].Course_Code,"ME451");
	strcpy(s->Courses.sem8[0].Course_Name,"Project Work Phase - II");
	s->Courses.sem8[0].Credits=4;
	s->Courses.sem8[0].No_Days_Present=0;
	s->Courses.sem8[0].No_Days_Total=0;
	s->Courses.sem8[0].Eligibility=0;
	s->Courses.sem8[0].Grade='\0';
	s->Courses.sem8[0].Examination_Block='-';
	strcpy(s->Courses.sem8[0].Examination_Date,"-");
	strcpy(s->Courses.sem8[0].Examination_Section,"-");
	strcpy(s->Courses.sem8[1].Course_Code,"ME452");
	strcpy(s->Courses.sem8[1].Course_Name,"Internship");
	s->Courses.sem8[1].Credits=4;
	s->Courses.sem8[1].No_Days_Present=0;
	s->Courses.sem8[1].No_Days_Total=0;
	s->Courses.sem8[1].Eligibility=0;
	s->Courses.sem8[1].Grade='\0';
	s->Courses.sem8[1].Examination_Block='-';
	strcpy(s->Courses.sem8[1].Examination_Date,"-");
	strcpy(s->Courses.sem8[1].Examination_Section,"-");
	strcpy(s->Courses.sem8[2].Course_Code,"ME453");
	strcpy(s->Courses.sem8[2].Course_Name,"Aerospace Engineering");
	s->Courses.sem8[2].Credits=4;
	s->Courses.sem8[2].No_Days_Present=0;
	s->Courses.sem8[2].No_Days_Total=0;
	s->Courses.sem8[2].Eligibility=0;
	s->Courses.sem8[2].Grade='\0';
	s->Courses.sem8[2].Examination_Block='\0';
	strcpy(s->Courses.sem8[2].Examination_Date,"\0");
	strcpy(s->Courses.sem8[2].Examination_Section,"\0");
}
void InitEEE(student *s)
{
	//Semester 3
	s->Courses.no_courses_sem3=6;
	strcpy(s->Courses.sem3[0].Course_Code,"EE201");
	strcpy(s->Courses.sem3[0].Course_Name,"Electric Circuit Theory");
	s->Courses.sem3[0].Credits=4;
	s->Courses.sem3[0].No_Days_Present=0;
	s->Courses.sem3[0].No_Days_Total=0;
	s->Courses.sem3[0].Eligibility=0;
	s->Courses.sem3[0].Grade='\0';
	s->Courses.sem3[0].Examination_Block='\0';
	strcpy(s->Courses.sem3[0].Examination_Date,"\0");
	strcpy(s->Courses.sem3[0].Examination_Section,"\0");
	strcpy(s->Courses.sem3[1].Course_Code,"EE202");
	strcpy(s->Courses.sem3[1].Course_Name,"Analog Electronic Circuits");
	s->Courses.sem3[1].Credits=4;
	s->Courses.sem3[1].No_Days_Present=0;
	s->Courses.sem3[1].No_Days_Total=0;
	s->Courses.sem3[1].Eligibility=0;
	s->Courses.sem3[1].Grade='\0';
	s->Courses.sem3[1].Examination_Block='\0';
	strcpy(s->Courses.sem3[1].Examination_Date,"\0");
	strcpy(s->Courses.sem3[1].Examination_Section,"\0");
	strcpy(s->Courses.sem3[2].Course_Code,"EE203");
	strcpy(s->Courses.sem3[2].Course_Name,"Digital Electronics");
	s->Courses.sem3[2].Credits=4;
	s->Courses.sem3[2].No_Days_Present=0;
	s->Courses.sem3[2].No_Days_Total=0;
	s->Courses.sem3[2].Eligibility=0;
	s->Courses.sem3[2].Grade='\0';
	s->Courses.sem3[2].Examination_Block='\0';
	strcpy(s->Courses.sem3[2].Examination_Date,"\0");
	strcpy(s->Courses.sem3[2].Examination_Section,"\0");
	strcpy(s->Courses.sem3[3].Course_Code,"EE204");
	strcpy(s->Courses.sem3[3].Course_Name,"Electromagnetic Theory");
	s->Courses.sem3[3].Credits=4;
	s->Courses.sem3[3].No_Days_Present=0;
	s->Courses.sem3[3].No_Days_Total=0;
	s->Courses.sem3[3].Eligibility=0;
	s->Courses.sem3[3].Grade='\0';
	s->Courses.sem3[3].Examination_Block='\0';
	strcpy(s->Courses.sem3[3].Examination_Date,"\0");
	strcpy(s->Courses.sem3[3].Examination_Section,"\0");
	strcpy(s->Courses.sem3[4].Course_Code,"EE205");
	strcpy(s->Courses.sem3[4].Course_Name,"Analog Electronic Circuits Laboratory");
	s->Courses.sem3[4].Credits=1;
	s->Courses.sem3[4].No_Days_Present=0;
	s->Courses.sem3[4].No_Days_Total=0;
	s->Courses.sem3[4].Eligibility=0;
	s->Courses.sem3[4].Grade='\0';
	s->Courses.sem3[4].Examination_Block='-';
	strcpy(s->Courses.sem3[4].Examination_Date,"-");
	strcpy(s->Courses.sem3[4].Examination_Section,"-");
	strcpy(s->Courses.sem3[5].Course_Code,"EE206");
	strcpy(s->Courses.sem3[5].Course_Name,"Digital Electronics Laboratory");
	s->Courses.sem3[5].Credits=1;
	s->Courses.sem3[5].No_Days_Present=0;
	s->Courses.sem3[5].No_Days_Total=0;
	s->Courses.sem3[5].Eligibility=0;
	s->Courses.sem3[5].Grade='\0';
	s->Courses.sem3[5].Examination_Block='-';
	strcpy(s->Courses.sem3[5].Examination_Date,"-");
	strcpy(s->Courses.sem3[5].Examination_Section,"-");
	//Semester 4
	s->Courses.no_courses_sem4=6;
	strcpy(s->Courses.sem4[0].Course_Code,"EE251");
	strcpy(s->Courses.sem4[0].Course_Name,"Control Systems - I");
	s->Courses.sem4[0].Credits=4;
	s->Courses.sem4[0].No_Days_Present=0;
	s->Courses.sem4[0].No_Days_Total=0;
	s->Courses.sem4[0].Eligibility=0;
	s->Courses.sem4[0].Grade='\0';
	s->Courses.sem4[0].Examination_Block='\0';
	strcpy(s->Courses.sem4[0].Examination_Date,"\0");
	strcpy(s->Courses.sem4[0].Examination_Section,"\0");
	strcpy(s->Courses.sem4[1].Course_Code,"EE252");
	strcpy(s->Courses.sem4[1].Course_Name,"Micro-controllers");
	s->Courses.sem4[1].Credits=4;
	s->Courses.sem4[1].No_Days_Present=0;
	s->Courses.sem4[1].No_Days_Total=0;
	s->Courses.sem4[1].Eligibility=0;
	s->Courses.sem4[1].Grade='\0';
	s->Courses.sem4[1].Examination_Block='\0';
	strcpy(s->Courses.sem4[1].Examination_Date,"\0");
	strcpy(s->Courses.sem4[1].Examination_Section,"\0");
	strcpy(s->Courses.sem4[2].Course_Code,"EE253");
	strcpy(s->Courses.sem4[2].Course_Name,"Power Electronics");
	s->Courses.sem4[2].Credits=4;
	s->Courses.sem4[2].No_Days_Present=0;
	s->Courses.sem4[2].No_Days_Total=0;
	s->Courses.sem4[2].Eligibility=0;
	s->Courses.sem4[2].Grade='\0';
	s->Courses.sem4[2].Examination_Block='\0';
	strcpy(s->Courses.sem4[2].Examination_Date,"\0");
	strcpy(s->Courses.sem4[2].Examination_Section,"\0");
	strcpy(s->Courses.sem4[3].Course_Code,"EE254");
	strcpy(s->Courses.sem4[3].Course_Name,"Generation Transmission");
	s->Courses.sem4[3].Credits=4;
	s->Courses.sem4[3].No_Days_Present=0;
	s->Courses.sem4[3].No_Days_Total=0;
	s->Courses.sem4[3].Eligibility=0;
	s->Courses.sem4[3].Grade='\0';
	s->Courses.sem4[3].Examination_Block='\0';
	strcpy(s->Courses.sem4[3].Examination_Date,"\0");
	strcpy(s->Courses.sem4[3].Examination_Section,"\0");
	strcpy(s->Courses.sem4[4].Course_Code,"EE255");
	strcpy(s->Courses.sem4[4].Course_Name,"Micro-controllers Laboratory");
	s->Courses.sem4[4].Credits=1;
	s->Courses.sem4[4].No_Days_Present=0;
	s->Courses.sem4[4].No_Days_Total=0;
	s->Courses.sem4[4].Eligibility=0;
	s->Courses.sem4[4].Grade='\0';
	s->Courses.sem4[4].Examination_Block='-';
	strcpy(s->Courses.sem4[4].Examination_Date,"-");
	strcpy(s->Courses.sem4[4].Examination_Section,"-");
	strcpy(s->Courses.sem4[5].Course_Code,"EE256");
	strcpy(s->Courses.sem4[5].Course_Name,"Power Electronics Laboratory");
	s->Courses.sem4[5].Credits=1;
	s->Courses.sem4[5].No_Days_Present=0;
	s->Courses.sem4[5].No_Days_Total=0;
	s->Courses.sem4[5].Eligibility=0;
	s->Courses.sem4[5].Grade='\0';
	s->Courses.sem4[5].Examination_Block='-';
	strcpy(s->Courses.sem4[5].Examination_Date,"-");
	strcpy(s->Courses.sem4[5].Examination_Section,"-");
	//Semester 5
	s->Courses.no_courses_sem5=8;
	strcpy(s->Courses.sem5[0].Course_Code,"EE301");
	strcpy(s->Courses.sem5[0].Course_Name,"Electrical Machines");
	s->Courses.sem5[0].Credits=4;
	s->Courses.sem5[0].No_Days_Present=0;
	s->Courses.sem5[0].No_Days_Total=0;
	s->Courses.sem5[0].Eligibility=0;
	s->Courses.sem5[0].Grade='\0';
	s->Courses.sem5[0].Examination_Block='\0';
	strcpy(s->Courses.sem5[0].Examination_Date,"\0");
	strcpy(s->Courses.sem5[0].Examination_Section,"\0");
	strcpy(s->Courses.sem5[1].Course_Code,"EE302");
	strcpy(s->Courses.sem5[1].Course_Name,"Microcontrollers");
	s->Courses.sem5[1].Credits=4;
	s->Courses.sem5[1].No_Days_Present=0;
	s->Courses.sem5[1].No_Days_Total=0;
	s->Courses.sem5[1].Eligibility=0;
	s->Courses.sem5[1].Grade='\0';
	s->Courses.sem5[1].Examination_Block='\0';
	strcpy(s->Courses.sem5[1].Examination_Date,"\0");
	strcpy(s->Courses.sem5[1].Examination_Section,"\0");
	strcpy(s->Courses.sem5[2].Course_Code,"EE303");
	strcpy(s->Courses.sem5[2].Course_Name,"Linear Systems and Signals");
	s->Courses.sem5[2].Credits=4;
	s->Courses.sem5[2].No_Days_Present=0;
	s->Courses.sem5[2].No_Days_Total=0;
	s->Courses.sem5[2].Eligibility=0;
	s->Courses.sem5[2].Grade='\0';
	s->Courses.sem5[2].Examination_Block='\0';
	strcpy(s->Courses.sem5[2].Examination_Date,"\0");
	strcpy(s->Courses.sem5[2].Examination_Section,"\0");
	strcpy(s->Courses.sem5[3].Course_Code,"EE304");
	strcpy(s->Courses.sem5[3].Course_Name,"Power Converter Topologies");
	s->Courses.sem5[3].Credits=4;
	s->Courses.sem5[3].No_Days_Present=0;
	s->Courses.sem5[3].No_Days_Total=0;
	s->Courses.sem5[3].Eligibility=0;
	s->Courses.sem5[3].Grade='\0';
	s->Courses.sem5[3].Examination_Block='\0';
	strcpy(s->Courses.sem5[3].Examination_Date,"\0");
	strcpy(s->Courses.sem5[3].Examination_Section,"\0");
	strcpy(s->Courses.sem5[4].Course_Code,"EE305");
	strcpy(s->Courses.sem5[4].Course_Name,"Data Structures and Algorithms");
	s->Courses.sem5[4].Credits=4;
	s->Courses.sem5[4].No_Days_Present=0;
	s->Courses.sem5[4].No_Days_Total=0;
	s->Courses.sem5[4].Eligibility=0;
	s->Courses.sem5[4].Grade='\0';
	s->Courses.sem5[4].Examination_Block='\0';
	strcpy(s->Courses.sem5[4].Examination_Date,"\0");
	strcpy(s->Courses.sem5[4].Examination_Section,"\0");
	strcpy(s->Courses.sem5[5].Course_Code,"EE306");
	strcpy(s->Courses.sem5[5].Course_Name,"Electrical Machines Laboratory");
	s->Courses.sem5[5].Credits=1;
	s->Courses.sem5[5].No_Days_Present=0;
	s->Courses.sem5[5].No_Days_Total=0;
	s->Courses.sem5[5].Eligibility=0;
	s->Courses.sem5[5].Grade='\0';
	s->Courses.sem5[5].Examination_Block='-';
	strcpy(s->Courses.sem5[5].Examination_Date,"-");
	strcpy(s->Courses.sem5[5].Examination_Section,"-");
	strcpy(s->Courses.sem5[6].Course_Code,"EE307");
	strcpy(s->Courses.sem5[6].Course_Name,"Microcontrollers Laboratory");
	s->Courses.sem5[6].Credits=1;
	s->Courses.sem5[6].No_Days_Present=0;
	s->Courses.sem5[6].No_Days_Total=0;
	s->Courses.sem5[6].Eligibility=0;
	s->Courses.sem5[6].Grade='\0';
	s->Courses.sem5[6].Examination_Block='-';
	strcpy(s->Courses.sem5[6].Examination_Date,"-");
	strcpy(s->Courses.sem5[6].Examination_Section,"-");
	strcpy(s->Courses.sem5[7].Course_Code,"EE308");
	strcpy(s->Courses.sem5[7].Course_Name,"Smart Power Control");
	s->Courses.sem5[7].Credits=2;
	s->Courses.sem5[7].No_Days_Present=0;
	s->Courses.sem5[7].No_Days_Total=0;
	s->Courses.sem5[7].Eligibility=0;
	s->Courses.sem5[7].Grade='\0';
	s->Courses.sem5[7].Examination_Block='\0';
	strcpy(s->Courses.sem5[7].Examination_Date,"\0");
	strcpy(s->Courses.sem5[7].Examination_Section,"\0");
	//Semester 6
	s->Courses.no_courses_sem6=7;
	strcpy(s->Courses.sem6[0].Course_Code,"EE351");
	strcpy(s->Courses.sem6[0].Course_Name,"Power System Analysis and Stability");
	s->Courses.sem6[0].Credits=4;
	s->Courses.sem6[0].No_Days_Present=0;
	s->Courses.sem6[0].No_Days_Total=0;
	s->Courses.sem6[0].Eligibility=0;
	s->Courses.sem6[0].Grade='\0';
	s->Courses.sem6[0].Examination_Block='\0';
	strcpy(s->Courses.sem6[0].Examination_Date,"\0");
	strcpy(s->Courses.sem6[0].Examination_Section,"\0");
	strcpy(s->Courses.sem6[1].Course_Code,"EE352");
	strcpy(s->Courses.sem6[1].Course_Name,"Control Systems - II");
	s->Courses.sem6[1].Credits=4;
	s->Courses.sem6[1].No_Days_Present=0;
	s->Courses.sem6[1].No_Days_Total=0;
	s->Courses.sem6[1].Eligibility=0;
	s->Courses.sem6[1].Grade='\0';
	s->Courses.sem6[1].Examination_Block='\0';
	strcpy(s->Courses.sem6[1].Examination_Date,"\0");
	strcpy(s->Courses.sem6[1].Examination_Section,"\0");
	strcpy(s->Courses.sem6[2].Course_Code,"EE353");
	strcpy(s->Courses.sem6[2].Course_Name,"Digital Signal Processing");
	s->Courses.sem6[2].Credits=4;
	s->Courses.sem6[2].No_Days_Present=0;
	s->Courses.sem6[2].No_Days_Total=0;
	s->Courses.sem6[2].Eligibility=0;
	s->Courses.sem6[2].Grade='\0';
	s->Courses.sem6[2].Examination_Block='\0';
	strcpy(s->Courses.sem6[2].Examination_Date,"\0");
	strcpy(s->Courses.sem6[2].Examination_Section,"\0");
	strcpy(s->Courses.sem6[3].Course_Code,"EE354");
	strcpy(s->Courses.sem6[3].Course_Name,"Design of Embedded Systems");
	s->Courses.sem6[3].Credits=4;
	s->Courses.sem6[3].No_Days_Present=0;
	s->Courses.sem6[3].No_Days_Total=0;
	s->Courses.sem6[3].Eligibility=0;
	s->Courses.sem6[3].Grade='\0';
	s->Courses.sem6[3].Examination_Block='\0';
	strcpy(s->Courses.sem6[3].Examination_Date,"\0");
	strcpy(s->Courses.sem6[3].Examination_Section,"\0");
	strcpy(s->Courses.sem6[4].Course_Code,"EE355");
	strcpy(s->Courses.sem6[4].Course_Name,"Solar Photovoltaic Systems");
	s->Courses.sem6[4].Credits=1;
	s->Courses.sem6[4].No_Days_Present=0;
	s->Courses.sem6[4].No_Days_Total=0;
	s->Courses.sem6[4].Eligibility=0;
	s->Courses.sem6[4].Grade='\0';
	s->Courses.sem6[4].Examination_Block='\0';
	strcpy(s->Courses.sem6[4].Examination_Date,"\0");
	strcpy(s->Courses.sem6[4].Examination_Section,"\0");
	strcpy(s->Courses.sem6[5].Course_Code,"EE356");
	strcpy(s->Courses.sem6[5].Course_Name,"Control Systems - II Laboratory");
	s->Courses.sem6[5].Credits=1;
	s->Courses.sem6[5].No_Days_Present=0;
	s->Courses.sem6[5].No_Days_Total=0;
	s->Courses.sem6[5].Eligibility=0;
	s->Courses.sem6[5].Grade='\0';
	s->Courses.sem6[5].Examination_Block='-';
	strcpy(s->Courses.sem6[5].Examination_Date,"-");
	strcpy(s->Courses.sem6[5].Examination_Section,"-");
	strcpy(s->Courses.sem6[6].Course_Code,"EE357");
	strcpy(s->Courses.sem6[6].Course_Name,"Digital Signal Processing Lab");
	s->Courses.sem6[6].Credits=1;
	s->Courses.sem6[6].No_Days_Present=0;
	s->Courses.sem6[6].No_Days_Total=0;
	s->Courses.sem6[6].Eligibility=0;
	s->Courses.sem6[6].Grade='\0';
	s->Courses.sem6[6].Examination_Block='-';
	strcpy(s->Courses.sem6[6].Examination_Date,"-");
	strcpy(s->Courses.sem6[6].Examination_Section,"-");
	//Semester 7
	s->Courses.no_courses_sem7=3;
	strcpy(s->Courses.sem7[0].Course_Code,"EE401");
	strcpy(s->Courses.sem7[0].Course_Name,"Advanced Power Electronics");
	s->Courses.sem7[0].Credits=4;
	s->Courses.sem7[0].No_Days_Present=0;
	s->Courses.sem7[0].No_Days_Total=0;
	s->Courses.sem7[0].Eligibility=0;
	s->Courses.sem7[0].Grade='\0';
	s->Courses.sem7[0].Examination_Block='\0';
	strcpy(s->Courses.sem7[0].Examination_Date,"-");
	strcpy(s->Courses.sem7[0].Examination_Section,"\0");
	strcpy(s->Courses.sem7[1].Course_Code,"EE402");
	strcpy(s->Courses.sem7[1].Course_Name,"Testing and Commissioning");
	s->Courses.sem7[1].Credits=4;
	s->Courses.sem7[1].No_Days_Present=0;
	s->Courses.sem7[1].No_Days_Total=0;
	s->Courses.sem7[1].Eligibility=0;
	s->Courses.sem7[1].Grade='\0';
	s->Courses.sem7[1].Examination_Block='\0';
	strcpy(s->Courses.sem7[1].Examination_Date,"-");
	strcpy(s->Courses.sem7[1].Examination_Section,"\0");
	strcpy(s->Courses.sem7[2].Course_Code,"EE403");
	strcpy(s->Courses.sem7[2].Course_Name,"Project Work Phase - I");
	s->Courses.sem7[2].Credits=4;
	s->Courses.sem7[2].No_Days_Present=0;
	s->Courses.sem7[2].No_Days_Total=0;
	s->Courses.sem7[2].Eligibility=0;
	s->Courses.sem7[2].Grade='\0';
	s->Courses.sem7[2].Examination_Block='-';
	strcpy(s->Courses.sem7[2].Examination_Date,"-");
	strcpy(s->Courses.sem7[2].Examination_Section,"-");
	//Semester 8
	s->Courses.no_courses_sem8=3;
	strcpy(s->Courses.sem8[0].Course_Code,"EE451");
	strcpy(s->Courses.sem8[0].Course_Name,"Project Work Phase - II");
	s->Courses.sem8[0].Credits=4;
	s->Courses.sem8[0].No_Days_Present=0;
	s->Courses.sem8[0].No_Days_Total=0;
	s->Courses.sem8[0].Eligibility=0;
	s->Courses.sem8[0].Grade='\0';
	s->Courses.sem8[0].Examination_Block='-';
	strcpy(s->Courses.sem8[0].Examination_Date,"-");
	strcpy(s->Courses.sem8[0].Examination_Section,"-");
	strcpy(s->Courses.sem8[1].Course_Code,"EE452");
	strcpy(s->Courses.sem8[1].Course_Name,"Power Electronic Drives and Energy Systems");
	s->Courses.sem8[1].Credits=2;
	s->Courses.sem8[1].No_Days_Present=0;
	s->Courses.sem8[1].No_Days_Total=0;
	s->Courses.sem8[1].Eligibility=0;
	s->Courses.sem8[1].Grade='\0';
	s->Courses.sem8[1].Examination_Block='\0';
	strcpy(s->Courses.sem8[1].Examination_Date,"\0");
	strcpy(s->Courses.sem8[1].Examination_Section,"\0");
	strcpy(s->Courses.sem8[2].Course_Code,"EE453");
	strcpy(s->Courses.sem8[2].Course_Name,"Special Topic - II");
	s->Courses.sem8[2].Credits=2;
	s->Courses.sem8[2].No_Days_Present=0;
	s->Courses.sem8[2].No_Days_Total=0;
	s->Courses.sem8[2].Eligibility=0;
	s->Courses.sem8[2].Grade='\0';
	s->Courses.sem8[2].Examination_Block='\0';
	strcpy(s->Courses.sem8[2].Examination_Date,"\0");
	strcpy(s->Courses.sem8[2].Examination_Section,"\0");
}
void InitCV(student *s)
{
	//Semester 3
	s->Courses.no_courses_sem3=8;
	strcpy(s->Courses.sem3[0].Course_Code,"CV201");
	strcpy(s->Courses.sem3[0].Course_Name,"Engineering Mathematics - III");
	s->Courses.sem3[0].Credits=4;
	s->Courses.sem3[0].No_Days_Present=0;
	s->Courses.sem3[0].No_Days_Total=0;
	s->Courses.sem3[0].Eligibility=0;
	s->Courses.sem3[0].Grade='\0';
	s->Courses.sem3[0].Examination_Block='\0';
	strcpy(s->Courses.sem3[0].Examination_Date,"\0");
	strcpy(s->Courses.sem3[0].Examination_Section,"\0");
	strcpy(s->Courses.sem3[1].Course_Code,"CV202");
	strcpy(s->Courses.sem3[1].Course_Name,"Strength of Materials");
	s->Courses.sem3[1].Credits=4;
	s->Courses.sem3[1].No_Days_Present=0;
	s->Courses.sem3[1].No_Days_Total=0;
	s->Courses.sem3[1].Eligibility=0;
	s->Courses.sem3[1].Grade='\0';
	s->Courses.sem3[1].Examination_Block='\0';
	strcpy(s->Courses.sem3[1].Examination_Date,"\0");
	strcpy(s->Courses.sem3[1].Examination_Section,"\0");
	strcpy(s->Courses.sem3[2].Course_Code,"CV203");
	strcpy(s->Courses.sem3[2].Course_Name,"Geoinformatics");
	s->Courses.sem3[2].Credits=4;
	s->Courses.sem3[2].No_Days_Present=0;
	s->Courses.sem3[2].No_Days_Total=0;
	s->Courses.sem3[2].Eligibility=0;
	s->Courses.sem3[2].Grade='\0';
	s->Courses.sem3[2].Examination_Block='\0';
	strcpy(s->Courses.sem3[2].Examination_Date,"\0");
	strcpy(s->Courses.sem3[2].Examination_Section,"\0");
	strcpy(s->Courses.sem3[3].Course_Code,"CV204");
	strcpy(s->Courses.sem3[3].Course_Name,"Transportation - Highway");
	s->Courses.sem3[3].Credits=4;
	s->Courses.sem3[3].No_Days_Present=0;
	s->Courses.sem3[3].No_Days_Total=0;
	s->Courses.sem3[3].Eligibility=0;
	s->Courses.sem3[3].Grade='\0';
	s->Courses.sem3[3].Examination_Block='\0';
	strcpy(s->Courses.sem3[3].Examination_Date,"\0");
	strcpy(s->Courses.sem3[3].Examination_Section,"\0");
	strcpy(s->Courses.sem3[4].Course_Code,"CV205");
	strcpy(s->Courses.sem3[4].Course_Name,"Construction Materials & Technology");
	s->Courses.sem3[4].Credits=4;
	s->Courses.sem3[4].No_Days_Present=0;
	s->Courses.sem3[4].No_Days_Total=0;
	s->Courses.sem3[4].Eligibility=0;
	s->Courses.sem3[4].Grade='\0';
	s->Courses.sem3[4].Examination_Block='\0';
	strcpy(s->Courses.sem3[4].Examination_Date,"\0");
	strcpy(s->Courses.sem3[4].Examination_Section,"\0");
	strcpy(s->Courses.sem3[5].Course_Code,"CV206");
	strcpy(s->Courses.sem3[5].Course_Name,"Surveying Practice Laboratory");
	s->Courses.sem3[5].Credits=1;
	s->Courses.sem3[5].No_Days_Present=0;
	s->Courses.sem3[5].No_Days_Total=0;
	s->Courses.sem3[5].Eligibility=0;
	s->Courses.sem3[5].Grade='\0';
	s->Courses.sem3[5].Examination_Block='-';
	strcpy(s->Courses.sem3[5].Examination_Date,"-");
	strcpy(s->Courses.sem3[5].Examination_Section,"-");
	strcpy(s->Courses.sem3[6].Course_Code,"CV207");
	strcpy(s->Courses.sem3[6].Course_Name,"MT Laboratory");
	s->Courses.sem3[6].Credits=1;
	s->Courses.sem3[6].No_Days_Present=0;
	s->Courses.sem3[6].No_Days_Total=0;
	s->Courses.sem3[6].Eligibility=0;
	s->Courses.sem3[6].Grade='\0';
	s->Courses.sem3[6].Examination_Block='-';
	strcpy(s->Courses.sem3[6].Examination_Date,"-");
	strcpy(s->Courses.sem3[6].Examination_Section,"-");
	strcpy(s->Courses.sem3[7].Course_Code,"CV208");
	strcpy(s->Courses.sem3[7].Course_Name,"Special Topic - I");
	s->Courses.sem3[7].Credits=2;
	s->Courses.sem3[7].No_Days_Present=0;
	s->Courses.sem3[7].No_Days_Total=0;
	s->Courses.sem3[7].Eligibility=0;
	s->Courses.sem3[7].Grade='\0';
	s->Courses.sem3[7].Examination_Block='\0';
	strcpy(s->Courses.sem3[7].Examination_Date,"\0");
	strcpy(s->Courses.sem3[7].Examination_Section,"\0");
	//Semester 4
	s->Courses.no_courses_sem4=8;
	strcpy(s->Courses.sem4[0].Course_Code,"CV251");
	strcpy(s->Courses.sem4[0].Course_Name,"Linear Algebra and its Applications");
	s->Courses.sem4[0].Credits=4;
	s->Courses.sem4[0].No_Days_Present=0;
	s->Courses.sem4[0].No_Days_Total=0;
	s->Courses.sem4[0].Eligibility=0;
	s->Courses.sem4[0].Grade='\0';
	s->Courses.sem4[0].Examination_Block='\0';
	strcpy(s->Courses.sem4[0].Examination_Date,"\0");
	strcpy(s->Courses.sem4[0].Examination_Section,"\0");
	strcpy(s->Courses.sem4[1].Course_Code,"CV252");
	strcpy(s->Courses.sem4[1].Course_Name,"Structural Analysis");
	s->Courses.sem4[1].Credits=4;
	s->Courses.sem4[1].No_Days_Present=0;
	s->Courses.sem4[1].No_Days_Total=0;
	s->Courses.sem4[1].Eligibility=0;
	s->Courses.sem4[1].Grade='\0';
	s->Courses.sem4[1].Examination_Block='\0';
	strcpy(s->Courses.sem4[1].Examination_Date,"\0");
	strcpy(s->Courses.sem4[1].Examination_Section,"\0");
	strcpy(s->Courses.sem4[2].Course_Code,"CV253");
	strcpy(s->Courses.sem4[2].Course_Name,"Basics of Geo Technical Engineering");
	s->Courses.sem4[2].Credits=4;
	s->Courses.sem4[2].No_Days_Present=0;
	s->Courses.sem4[2].No_Days_Total=0;
	s->Courses.sem4[2].Eligibility=0;
	s->Courses.sem4[2].Grade='\0';
	s->Courses.sem4[2].Examination_Block='\0';
	strcpy(s->Courses.sem4[2].Examination_Date,"\0");
	strcpy(s->Courses.sem4[2].Examination_Section,"\0");
	strcpy(s->Courses.sem4[3].Course_Code,"CV254");
	strcpy(s->Courses.sem4[3].Course_Name,"Fluid Mechanics");
	s->Courses.sem4[3].Credits=4;
	s->Courses.sem4[3].No_Days_Present=0;
	s->Courses.sem4[3].No_Days_Total=0;
	s->Courses.sem4[3].Eligibility=0;
	s->Courses.sem4[3].Grade='\0';
	s->Courses.sem4[3].Examination_Block='\0';
	strcpy(s->Courses.sem4[3].Examination_Date,"\0");
	strcpy(s->Courses.sem4[3].Examination_Section,"\0");
	strcpy(s->Courses.sem4[4].Course_Code,"CV255");
	strcpy(s->Courses.sem4[4].Course_Name,"Concrete Technology");
	s->Courses.sem4[4].Credits=4;
	s->Courses.sem4[4].No_Days_Present=0;
	s->Courses.sem4[4].No_Days_Total=0;
	s->Courses.sem4[4].Eligibility=0;
	s->Courses.sem4[4].Grade='\0';
	s->Courses.sem4[4].Examination_Block='\0';
	strcpy(s->Courses.sem4[4].Examination_Date,"\0");
	strcpy(s->Courses.sem4[4].Examination_Section,"\0");
	strcpy(s->Courses.sem4[5].Course_Code,"CV256");
	strcpy(s->Courses.sem4[5].Course_Name,"Building planning and drawing");
	s->Courses.sem4[5].Credits=4;
	s->Courses.sem4[5].No_Days_Present=0;
	s->Courses.sem4[5].No_Days_Total=0;
	s->Courses.sem4[5].Eligibility=0;
	s->Courses.sem4[5].Grade='\0';
	s->Courses.sem4[5].Examination_Block='\0';
	strcpy(s->Courses.sem4[5].Examination_Date,"\0");
	strcpy(s->Courses.sem4[5].Examination_Section,"\0");
	strcpy(s->Courses.sem4[6].Course_Code,"CV257");
	strcpy(s->Courses.sem4[6].Course_Name,"Concrete & Highway Laboratory");
	s->Courses.sem4[6].Credits=1;
	s->Courses.sem4[6].No_Days_Present=0;
	s->Courses.sem4[6].No_Days_Total=0;
	s->Courses.sem4[6].Eligibility=0;
	s->Courses.sem4[6].Grade='\0';
	s->Courses.sem4[6].Examination_Block='-';
	strcpy(s->Courses.sem4[6].Examination_Date,"-");
	strcpy(s->Courses.sem4[6].Examination_Section,"-");
	strcpy(s->Courses.sem4[7].Course_Code,"CV258");
	strcpy(s->Courses.sem4[7].Course_Name,"Special Topic - II");
	s->Courses.sem4[7].Credits=2;
	s->Courses.sem4[7].No_Days_Present=0;
	s->Courses.sem4[7].No_Days_Total=0;
	s->Courses.sem4[7].Eligibility=0;
	s->Courses.sem4[7].Grade='\0';
	s->Courses.sem4[7].Examination_Block='\0';
	strcpy(s->Courses.sem4[6].Examination_Date,"\0");
	strcpy(s->Courses.sem4[7].Examination_Section,"\0");
	//Semester 5
	s->Courses.no_courses_sem5=8;
	strcpy(s->Courses.sem5[0].Course_Code,"CV301");
	strcpy(s->Courses.sem5[0].Course_Name,"Design & Detailing of RC Structural Elements");
	s->Courses.sem5[0].Credits=4;
	s->Courses.sem5[0].No_Days_Present=0;
	s->Courses.sem5[0].No_Days_Total=0;
	s->Courses.sem5[0].Eligibility=0;
	s->Courses.sem5[0].Grade='\0';
	s->Courses.sem5[0].Examination_Block='\0';
	strcpy(s->Courses.sem5[0].Examination_Date,"\0");
	strcpy(s->Courses.sem5[0].Examination_Section,"\0");
	strcpy(s->Courses.sem5[1].Course_Code,"CV302");
	strcpy(s->Courses.sem5[1].Course_Name,"Computational Structural Analysis");
	s->Courses.sem5[1].Credits=4;
	s->Courses.sem5[1].No_Days_Present=0;
	s->Courses.sem5[1].No_Days_Total=0;
	s->Courses.sem5[1].Eligibility=0;
	s->Courses.sem5[1].Grade='\0';
	s->Courses.sem5[1].Examination_Block='\0';
	strcpy(s->Courses.sem5[1].Examination_Date,"\0");
	strcpy(s->Courses.sem5[1].Examination_Section,"\0");
	strcpy(s->Courses.sem5[2].Course_Code,"CV303");
	strcpy(s->Courses.sem5[2].Course_Name,"Applied Geotechnical Engineering");
	s->Courses.sem5[2].Credits=4;
	s->Courses.sem5[2].No_Days_Present=0;
	s->Courses.sem5[2].No_Days_Total=0;
	s->Courses.sem5[2].Eligibility=0;
	s->Courses.sem5[2].Grade='\0';
	s->Courses.sem5[2].Examination_Block='\0';
	strcpy(s->Courses.sem5[2].Examination_Date,"\0");
	strcpy(s->Courses.sem5[2].Examination_Section,"\0");
	strcpy(s->Courses.sem5[3].Course_Code,"CV304");
	strcpy(s->Courses.sem5[3].Course_Name,"Fluid Mechanics and Machines Laboratory for Civil Engineers");
	s->Courses.sem5[3].Credits=1;
	s->Courses.sem5[3].No_Days_Present=0;
	s->Courses.sem5[3].No_Days_Total=0;
	s->Courses.sem5[3].Eligibility=0;
	s->Courses.sem5[3].Grade='\0';
	s->Courses.sem5[3].Examination_Block='-';
	strcpy(s->Courses.sem5[3].Examination_Date,"-");
	strcpy(s->Courses.sem5[3].Examination_Section,"-");
	strcpy(s->Courses.sem5[4].Course_Code,"CV305");
	strcpy(s->Courses.sem5[4].Course_Name,"Geotechnical Engineering Laboratory");
	s->Courses.sem5[4].Credits=1;
	s->Courses.sem5[4].No_Days_Present=0;
	s->Courses.sem5[4].No_Days_Total=0;
	s->Courses.sem5[4].Eligibility=0;
	s->Courses.sem5[4].Grade='\0';
	s->Courses.sem5[4].Examination_Block='-';
	strcpy(s->Courses.sem5[4].Examination_Date,"-");
	strcpy(s->Courses.sem5[4].Examination_Section,"-");
	strcpy(s->Courses.sem5[5].Course_Code,"CV306");
	strcpy(s->Courses.sem5[5].Course_Name,"Special Topic - III");
	s->Courses.sem5[5].Credits=2;
	s->Courses.sem5[5].No_Days_Present=0;
	s->Courses.sem5[5].No_Days_Total=0;
	s->Courses.sem5[5].Eligibility=0;
	s->Courses.sem5[5].Grade='\0';
	s->Courses.sem5[5].Examination_Block='\0';
	strcpy(s->Courses.sem5[5].Examination_Date,"\0");
	strcpy(s->Courses.sem5[5].Examination_Section,"\0");
	strcpy(s->Courses.sem5[6].Course_Code,"CV307");
	strcpy(s->Courses.sem5[6].Course_Name,"Design of Foundation");
	s->Courses.sem5[6].Credits=4;
	s->Courses.sem5[6].No_Days_Present=0;
	s->Courses.sem5[6].No_Days_Total=0;
	s->Courses.sem5[6].Eligibility=0;
	s->Courses.sem5[6].Grade='\0';
	s->Courses.sem5[6].Examination_Block='\0';
	strcpy(s->Courses.sem5[6].Examination_Date,"\0");
	strcpy(s->Courses.sem5[6].Examination_Section,"\0");
	strcpy(s->Courses.sem5[7].Course_Code,"CV308");
	strcpy(s->Courses.sem5[7].Course_Name,"Mechanization in construction");
	s->Courses.sem5[7].Credits=4;
	s->Courses.sem5[7].No_Days_Present=0;
	s->Courses.sem5[7].No_Days_Total=0;
	s->Courses.sem5[7].Eligibility=0;
	s->Courses.sem5[7].Grade='\0';
	s->Courses.sem5[7].Examination_Block='\0';
	strcpy(s->Courses.sem5[7].Examination_Date,"\0");
	strcpy(s->Courses.sem5[7].Examination_Section,"\0");
	//Semester 6
	s->Courses.no_courses_sem6=7;
	strcpy(s->Courses.sem6[0].Course_Code,"CV351");
	strcpy(s->Courses.sem6[0].Course_Name,"Sewage treatment plant and sanitary engineering");
	s->Courses.sem6[0].Credits=4;
	s->Courses.sem6[0].No_Days_Present=0;
	s->Courses.sem6[0].No_Days_Total=0;
	s->Courses.sem6[0].Eligibility=0;
	s->Courses.sem6[0].Grade='\0';
	s->Courses.sem6[0].Examination_Block='\0';
	strcpy(s->Courses.sem6[0].Examination_Date,"\0");
	strcpy(s->Courses.sem6[0].Examination_Section,"\0");
	strcpy(s->Courses.sem6[1].Course_Code,"CV352");
	strcpy(s->Courses.sem6[1].Course_Name,"Design & Detailing of Steel Structural Elements");
	s->Courses.sem6[1].Credits=4;
	s->Courses.sem6[1].No_Days_Present=0;
	s->Courses.sem6[1].No_Days_Total=0;
	s->Courses.sem6[1].Eligibility=0;
	s->Courses.sem6[1].Grade='\0';
	s->Courses.sem6[1].Examination_Block='\0';
	strcpy(s->Courses.sem6[1].Examination_Date,"\0");
	strcpy(s->Courses.sem6[1].Examination_Section,"\0");
	strcpy(s->Courses.sem6[2].Course_Code,"CV353");
	strcpy(s->Courses.sem6[2].Course_Name,"Estimation & Costing");
	s->Courses.sem6[2].Credits=4;
	s->Courses.sem6[2].No_Days_Present=0;
	s->Courses.sem6[2].No_Days_Total=0;
	s->Courses.sem6[2].Eligibility=0;
	s->Courses.sem6[2].Grade='\0';
	s->Courses.sem6[2].Examination_Block='\0';
	strcpy(s->Courses.sem6[2].Examination_Date,"\0");
	strcpy(s->Courses.sem6[2].Examination_Section,"\0");
	strcpy(s->Courses.sem6[3].Course_Code,"CV354");
	strcpy(s->Courses.sem6[3].Course_Name,"Hydrology & Irrigation Engineering");
	s->Courses.sem6[3].Credits=4;
	s->Courses.sem6[3].No_Days_Present=0;
	s->Courses.sem6[3].No_Days_Total=0;
	s->Courses.sem6[3].Eligibility=0;
	s->Courses.sem6[3].Grade='\0';
	s->Courses.sem6[3].Examination_Block='\0';
	strcpy(s->Courses.sem6[3].Examination_Date,"\0");
	strcpy(s->Courses.sem6[3].Examination_Section,"\0");
	strcpy(s->Courses.sem6[4].Course_Code,"CV355");
	strcpy(s->Courses.sem6[4].Course_Name,"Earth retaining structures");
	s->Courses.sem6[4].Credits=4;
	s->Courses.sem6[4].No_Days_Present=0;
	s->Courses.sem6[4].No_Days_Total=0;
	s->Courses.sem6[4].Eligibility=0;
	s->Courses.sem6[4].Grade='\0';
	s->Courses.sem6[4].Examination_Block='\0';
	strcpy(s->Courses.sem6[4].Examination_Date,"\0");
	strcpy(s->Courses.sem6[4].Examination_Section,"\0");
	strcpy(s->Courses.sem6[5].Course_Code,"CV356");
	strcpy(s->Courses.sem6[5].Course_Name,"ComputerAided Analysis and Design Laboratory");
	s->Courses.sem6[5].Credits=1;
	s->Courses.sem6[5].No_Days_Present=0;
	s->Courses.sem6[5].No_Days_Total=0;
	s->Courses.sem6[5].Eligibility=0;
	s->Courses.sem6[5].Grade='\0';
	s->Courses.sem6[5].Examination_Block='-';
	strcpy(s->Courses.sem6[5].Examination_Date,"-");
	strcpy(s->Courses.sem6[5].Examination_Section,"-");
	strcpy(s->Courses.sem6[6].Course_Code,"CV357");
	strcpy(s->Courses.sem6[6].Course_Name,"Design and Detailing of Hydraulic structures Laboratory");
	s->Courses.sem6[6].Credits=1;
	s->Courses.sem6[6].No_Days_Present=0;
	s->Courses.sem6[6].No_Days_Total=0;
	s->Courses.sem6[6].Eligibility=0;
	s->Courses.sem6[6].Grade='\0';
	s->Courses.sem6[6].Examination_Block='-';
	strcpy(s->Courses.sem6[6].Examination_Date,"-");
	strcpy(s->Courses.sem6[6].Examination_Section,"-");
	//Semester 7
	s->Courses.no_courses_sem7=5;
	strcpy(s->Courses.sem7[0].Course_Code,"CV401");
	strcpy(s->Courses.sem7[0].Course_Name,"Pavement Construction Management & Maintenance");
	s->Courses.sem7[0].Credits=4;
	s->Courses.sem7[0].No_Days_Present=0;
	s->Courses.sem7[0].No_Days_Total=0;
	s->Courses.sem7[0].Eligibility=0;
	s->Courses.sem7[0].Grade='\0';
	s->Courses.sem7[0].Examination_Block='\0';
	strcpy(s->Courses.sem7[0].Examination_Date,"-");
	strcpy(s->Courses.sem7[0].Examination_Section,"\0");
	strcpy(s->Courses.sem7[1].Course_Code,"CV402");
	strcpy(s->Courses.sem7[1].Course_Name,"Design & Detailing of Steel Structural Elements");
	s->Courses.sem7[1].Credits=4;
	s->Courses.sem7[1].No_Days_Present=0;
	s->Courses.sem7[1].No_Days_Total=0;
	s->Courses.sem7[1].Eligibility=0;
	s->Courses.sem7[1].Grade='\0';
	s->Courses.sem7[1].Examination_Block='\0';
	strcpy(s->Courses.sem7[1].Examination_Date,"-");
	strcpy(s->Courses.sem7[1].Examination_Section,"\0");
	strcpy(s->Courses.sem7[2].Course_Code,"CV403");
	strcpy(s->Courses.sem7[2].Course_Name,"Mechanization in Construction");
	s->Courses.sem7[2].Credits=4;
	s->Courses.sem7[2].No_Days_Present=0;
	s->Courses.sem7[2].No_Days_Total=0;
	s->Courses.sem7[2].Eligibility=0;
	s->Courses.sem7[2].Grade='\0';
	s->Courses.sem7[2].Examination_Block='\0';
	strcpy(s->Courses.sem7[2].Examination_Date,"-");
	strcpy(s->Courses.sem7[2].Examination_Section,"\0");
	strcpy(s->Courses.sem7[3].Course_Code,"CV404");
	strcpy(s->Courses.sem7[3].Course_Name,"Transportation Engineering");
	s->Courses.sem7[3].Credits=4;
	s->Courses.sem7[3].No_Days_Present=0;
	s->Courses.sem7[3].No_Days_Total=0;
	s->Courses.sem7[3].Eligibility=0;
	s->Courses.sem7[3].Grade='\0';
	s->Courses.sem7[3].Examination_Block='\0';
	strcpy(s->Courses.sem7[3].Examination_Date,"-");
	strcpy(s->Courses.sem7[3].Examination_Section,"\0");
	strcpy(s->Courses.sem7[4].Course_Code,"CV405");
	strcpy(s->Courses.sem7[4].Course_Name,"Project Work Phase - I");
	s->Courses.sem7[4].Credits=4;
	s->Courses.sem7[4].No_Days_Present=0;
	s->Courses.sem7[4].No_Days_Total=0;
	s->Courses.sem7[4].Eligibility=0;
	s->Courses.sem7[4].Grade='\0';
	s->Courses.sem7[4].Examination_Block='-';
	strcpy(s->Courses.sem7[4].Examination_Date,"-");
	strcpy(s->Courses.sem7[4].Examination_Section,"-");
	//Semester 8
	s->Courses.no_courses_sem8=4;
	strcpy(s->Courses.sem8[0].Course_Code,"CV451");
	strcpy(s->Courses.sem8[0].Course_Name,"Project Work Phase - II");
	s->Courses.sem8[0].Credits=4;
	s->Courses.sem8[0].No_Days_Present=0;
	s->Courses.sem8[0].No_Days_Total=0;
	s->Courses.sem8[0].Eligibility=0;
	s->Courses.sem8[0].Grade='\0';
	s->Courses.sem8[0].Examination_Block='-';
	strcpy(s->Courses.sem8[0].Examination_Date,"-");
	strcpy(s->Courses.sem8[0].Examination_Section,"-");
	strcpy(s->Courses.sem8[1].Course_Code,"CV452");
	strcpy(s->Courses.sem8[1].Course_Name,"Internship");
	s->Courses.sem8[1].Credits=6;
	s->Courses.sem8[1].No_Days_Present=0;
	s->Courses.sem8[1].No_Days_Total=0;
	s->Courses.sem8[1].Eligibility=0;
	s->Courses.sem8[1].Grade='\0';
	s->Courses.sem8[1].Examination_Block='-';
	strcpy(s->Courses.sem8[1].Examination_Date,"-");
	strcpy(s->Courses.sem8[1].Examination_Section,"-");
	strcpy(s->Courses.sem8[2].Course_Code,"CV453");
	strcpy(s->Courses.sem8[2].Course_Name,"Special Topic - IV");
	s->Courses.sem8[2].Credits=2;
	s->Courses.sem8[2].No_Days_Present=0;
	s->Courses.sem8[2].No_Days_Total=0;
	s->Courses.sem8[2].Eligibility=0;
	s->Courses.sem8[2].Grade='\0';
	s->Courses.sem8[2].Examination_Block='\0';
	strcpy(s->Courses.sem8[2].Examination_Date,"\0");
	strcpy(s->Courses.sem8[2].Examination_Section,"\0");
	strcpy(s->Courses.sem8[3].Course_Code,"CV454");
	strcpy(s->Courses.sem8[3].Course_Name,"Special Topic - V");
	s->Courses.sem8[3].Credits=2;
	s->Courses.sem8[3].No_Days_Present=0;
	s->Courses.sem8[3].No_Days_Total=0;
	s->Courses.sem8[3].Eligibility=0;
	s->Courses.sem8[3].Grade='\0';
	s->Courses.sem8[3].Examination_Block='\0';
	strcpy(s->Courses.sem8[3].Examination_Date,"\0");
	strcpy(s->Courses.sem8[3].Examination_Section,"\0");
}
void InitBT(student *s)
{
	//Semester 3
	s->Courses.no_courses_sem3=8;
	strcpy(s->Courses.sem3[0].Course_Code,"BT201");
	strcpy(s->Courses.sem3[0].Course_Name,"Engineering Mathematics - III for Biotechnology");
	s->Courses.sem3[0].Credits=4;
	s->Courses.sem3[0].No_Days_Present=0;
	s->Courses.sem3[0].No_Days_Total=0;
	s->Courses.sem3[0].Eligibility=0;
	s->Courses.sem3[0].Grade='\0';
	s->Courses.sem3[0].Examination_Block='\0';
	strcpy(s->Courses.sem3[0].Examination_Date,"\0");
	strcpy(s->Courses.sem3[0].Examination_Section,"\0");
	strcpy(s->Courses.sem3[1].Course_Code,"BT202");
	strcpy(s->Courses.sem3[1].Course_Name,"Bioprocess Calculations");
	s->Courses.sem3[1].Credits=4;
	s->Courses.sem3[1].No_Days_Present=0;
	s->Courses.sem3[1].No_Days_Total=0;
	s->Courses.sem3[1].Eligibility=0;
	s->Courses.sem3[1].Grade='\0';
	s->Courses.sem3[1].Examination_Block='\0';
	strcpy(s->Courses.sem3[1].Examination_Date,"\0");
	strcpy(s->Courses.sem3[1].Examination_Section,"\0");
	strcpy(s->Courses.sem3[2].Course_Code,"BT203");
	strcpy(s->Courses.sem3[2].Course_Name,"Fluid Mechanics and Mechanical Operations");
	s->Courses.sem3[2].Credits=4;
	s->Courses.sem3[2].No_Days_Present=0;
	s->Courses.sem3[2].No_Days_Total=0;
	s->Courses.sem3[2].Eligibility=0;
	s->Courses.sem3[2].Grade='\0';
	s->Courses.sem3[2].Examination_Block='\0';
	strcpy(s->Courses.sem3[2].Examination_Date,"\0");
	strcpy(s->Courses.sem3[2].Examination_Section,"\0");
	strcpy(s->Courses.sem3[3].Course_Code,"BT204");
	strcpy(s->Courses.sem3[3].Course_Name,"Microbiology");
	s->Courses.sem3[3].Credits=4;
	s->Courses.sem3[3].No_Days_Present=0;
	s->Courses.sem3[3].No_Days_Total=0;
	s->Courses.sem3[3].Eligibility=0;
	s->Courses.sem3[3].Grade='\0';
	s->Courses.sem3[3].Examination_Block='\0';
	strcpy(s->Courses.sem3[3].Examination_Date,"\0");
	strcpy(s->Courses.sem3[3].Examination_Section,"\0");
	strcpy(s->Courses.sem3[4].Course_Code,"BT205");
	strcpy(s->Courses.sem3[4].Course_Name,"Biochemistry - I");
	s->Courses.sem3[4].Credits=4;
	s->Courses.sem3[4].No_Days_Present=0;
	s->Courses.sem3[4].No_Days_Total=0;
	s->Courses.sem3[4].Eligibility=0;
	s->Courses.sem3[4].Grade='\0';
	s->Courses.sem3[4].Examination_Block='\0';
	strcpy(s->Courses.sem3[4].Examination_Date,"\0");
	strcpy(s->Courses.sem3[4].Examination_Section,"\0");
	strcpy(s->Courses.sem3[5].Course_Code,"BT206");
	strcpy(s->Courses.sem3[5].Course_Name,"Microbiology Laboratory");
	s->Courses.sem3[5].Credits=1;
	s->Courses.sem3[5].No_Days_Present=0;
	s->Courses.sem3[5].No_Days_Total=0;
	s->Courses.sem3[5].Eligibility=0;
	s->Courses.sem3[5].Grade='\0';
	s->Courses.sem3[5].Examination_Block='-';
	strcpy(s->Courses.sem3[5].Examination_Date,"-");
	strcpy(s->Courses.sem3[5].Examination_Section,"-");
	strcpy(s->Courses.sem3[6].Course_Code,"BT207");
	strcpy(s->Courses.sem3[6].Course_Name,"Biochemistry - I Laboratory");
	s->Courses.sem3[6].Credits=1;
	s->Courses.sem3[6].No_Days_Present=0;
	s->Courses.sem3[6].No_Days_Total=0;
	s->Courses.sem3[6].Eligibility=0;
	s->Courses.sem3[6].Grade='\0';
	s->Courses.sem3[6].Examination_Block='-';
	strcpy(s->Courses.sem3[6].Examination_Date,"-");
	strcpy(s->Courses.sem3[6].Examination_Section,"-");
	strcpy(s->Courses.sem3[7].Course_Code,"BT208");
	strcpy(s->Courses.sem3[7].Course_Name,"Special Topic - I");
	s->Courses.sem3[7].Credits=2;
	s->Courses.sem3[7].No_Days_Present=0;
	s->Courses.sem3[7].No_Days_Total=0;
	s->Courses.sem3[7].Eligibility=0;
	s->Courses.sem3[7].Grade='\0';
	s->Courses.sem3[7].Examination_Block='\0';
	strcpy(s->Courses.sem3[7].Examination_Date,"\0");
	strcpy(s->Courses.sem3[7].Examination_Section,"\0");
	//Semester 4
	s->Courses.no_courses_sem4=8;
	strcpy(s->Courses.sem4[0].Course_Code,"BT251");
	strcpy(s->Courses.sem4[0].Course_Name,"Linear Algebra and its Applications");
	s->Courses.sem4[0].Credits=4;
	s->Courses.sem4[0].No_Days_Present=0;
	s->Courses.sem4[0].No_Days_Total=0;
	s->Courses.sem4[0].Eligibility=0;
	s->Courses.sem4[0].Grade='\0';
	s->Courses.sem4[0].Examination_Block='\0';
	strcpy(s->Courses.sem4[0].Examination_Date,"\0");
	strcpy(s->Courses.sem4[0].Examination_Section,"\0");
	strcpy(s->Courses.sem4[1].Course_Code,"BT252");
	strcpy(s->Courses.sem4[1].Course_Name,"Thermodynamics and Heat Transfer");
	s->Courses.sem4[1].Credits=4;
	s->Courses.sem4[1].No_Days_Present=0;
	s->Courses.sem4[1].No_Days_Total=0;
	s->Courses.sem4[1].Eligibility=0;
	s->Courses.sem4[1].Grade='\0';
	s->Courses.sem4[1].Examination_Block='\0';
	strcpy(s->Courses.sem4[1].Examination_Date,"\0");
	strcpy(s->Courses.sem4[1].Examination_Section,"\0");
	strcpy(s->Courses.sem4[2].Course_Code,"BT253");
	strcpy(s->Courses.sem4[2].Course_Name,"Genetics and Molecular Biology");
	s->Courses.sem4[2].Credits=4;
	s->Courses.sem4[2].No_Days_Present=0;
	s->Courses.sem4[2].No_Days_Total=0;
	s->Courses.sem4[2].Eligibility=0;
	s->Courses.sem4[2].Grade='\0';
	s->Courses.sem4[2].Examination_Block='\0';
	strcpy(s->Courses.sem4[2].Examination_Date,"\0");
	strcpy(s->Courses.sem4[2].Examination_Section,"\0");
	strcpy(s->Courses.sem4[3].Course_Code,"BT254");
	strcpy(s->Courses.sem4[3].Course_Name,"Biochemistry - II");
	s->Courses.sem4[3].Credits=4;
	s->Courses.sem4[3].No_Days_Present=0;
	s->Courses.sem4[3].No_Days_Total=0;
	s->Courses.sem4[3].Eligibility=0;
	s->Courses.sem4[3].Grade='\0';
	s->Courses.sem4[3].Examination_Block='\0';
	strcpy(s->Courses.sem4[3].Examination_Date,"\0");
	strcpy(s->Courses.sem4[3].Examination_Section,"\0");
	strcpy(s->Courses.sem4[4].Course_Code,"BT255");
	strcpy(s->Courses.sem4[4].Course_Name,"Mass Transfer");
	s->Courses.sem4[4].Credits=4;
	s->Courses.sem4[4].No_Days_Present=0;
	s->Courses.sem4[4].No_Days_Total=0;
	s->Courses.sem4[4].Eligibility=0;
	s->Courses.sem4[4].Grade='\0';
	s->Courses.sem4[4].Examination_Block='\0';
	strcpy(s->Courses.sem4[4].Examination_Date,"\0");
	strcpy(s->Courses.sem4[4].Examination_Section,"\0");
	strcpy(s->Courses.sem4[5].Course_Code,"BT256");
	strcpy(s->Courses.sem4[5].Course_Name,"Genetics and Molecular Biology Laboratory");
	s->Courses.sem4[5].Credits=1;
	s->Courses.sem4[5].No_Days_Present=0;
	s->Courses.sem4[5].No_Days_Total=0;
	s->Courses.sem4[5].Eligibility=0;
	s->Courses.sem4[5].Grade='\0';
	s->Courses.sem4[5].Examination_Block='-';
	strcpy(s->Courses.sem4[5].Examination_Date,"-");
	strcpy(s->Courses.sem4[5].Examination_Section,"-");
	strcpy(s->Courses.sem4[6].Course_Code,"BT257");
	strcpy(s->Courses.sem4[6].Course_Name,"Biochemistry - II Laboratory");
	s->Courses.sem4[6].Credits=1;
	s->Courses.sem4[6].No_Days_Present=0;
	s->Courses.sem4[6].No_Days_Total=0;
	s->Courses.sem4[6].Eligibility=0;
	s->Courses.sem4[6].Grade='\0';
	s->Courses.sem4[6].Examination_Block='-';
	strcpy(s->Courses.sem4[6].Examination_Date,"-");
	strcpy(s->Courses.sem4[6].Examination_Section,"-");
	strcpy(s->Courses.sem4[7].Course_Code,"BT258");
	strcpy(s->Courses.sem4[7].Course_Name,"Special Topic - II");
	s->Courses.sem4[7].Credits=2;
	s->Courses.sem4[7].No_Days_Present=0;
	s->Courses.sem4[7].No_Days_Total=0;
	s->Courses.sem4[7].Eligibility=0;
	s->Courses.sem4[7].Grade='\0';
	s->Courses.sem4[7].Examination_Block='\0';
	strcpy(s->Courses.sem4[6].Examination_Date,"\0");
	strcpy(s->Courses.sem4[7].Examination_Section,"\0");
	//Semester 5
	s->Courses.no_courses_sem5=8;
	strcpy(s->Courses.sem5[0].Course_Code,"BT301");
	strcpy(s->Courses.sem5[0].Course_Name,"Bioprocess Reaction Engineering");
	s->Courses.sem5[0].Credits=4;
	s->Courses.sem5[0].No_Days_Present=0;
	s->Courses.sem5[0].No_Days_Total=0;
	s->Courses.sem5[0].Eligibility=0;
	s->Courses.sem5[0].Grade='\0';
	s->Courses.sem5[0].Examination_Block='\0';
	strcpy(s->Courses.sem5[0].Examination_Date,"\0");
	strcpy(s->Courses.sem5[0].Examination_Section,"\0");
	strcpy(s->Courses.sem5[1].Course_Code,"BT302");
	strcpy(s->Courses.sem5[1].Course_Name,"Genetic Engineering and applications");
	s->Courses.sem5[1].Credits=4;
	s->Courses.sem5[1].No_Days_Present=0;
	s->Courses.sem5[1].No_Days_Total=0;
	s->Courses.sem5[1].Eligibility=0;
	s->Courses.sem5[1].Grade='\0';
	s->Courses.sem5[1].Examination_Block='\0';
	strcpy(s->Courses.sem5[1].Examination_Date,"\0");
	strcpy(s->Courses.sem5[1].Examination_Section,"\0");
	strcpy(s->Courses.sem5[2].Course_Code,"BT303");
	strcpy(s->Courses.sem5[2].Course_Name,"Bioinformatics");
	s->Courses.sem5[2].Credits=4;
	s->Courses.sem5[2].No_Days_Present=0;
	s->Courses.sem5[2].No_Days_Total=0;
	s->Courses.sem5[2].Eligibility=0;
	s->Courses.sem5[2].Grade='\0';
	s->Courses.sem5[2].Examination_Block='\0';
	strcpy(s->Courses.sem5[2].Examination_Date,"\0");
	strcpy(s->Courses.sem5[2].Examination_Section,"\0");
	strcpy(s->Courses.sem5[3].Course_Code,"BT304");
	strcpy(s->Courses.sem5[3].Course_Name,"Bioprocess Reaction Engineering Laboratory");
	s->Courses.sem5[3].Credits=1;
	s->Courses.sem5[3].No_Days_Present=0;
	s->Courses.sem5[3].No_Days_Total=0;
	s->Courses.sem5[3].Eligibility=0;
	s->Courses.sem5[3].Grade='\0';
	s->Courses.sem5[3].Examination_Block='-';
	strcpy(s->Courses.sem5[3].Examination_Date,"-");
	strcpy(s->Courses.sem5[3].Examination_Section,"-");
	strcpy(s->Courses.sem5[4].Course_Code,"BT305");
	strcpy(s->Courses.sem5[4].Course_Name,"Bioinformatics Laboratory");
	s->Courses.sem5[4].Credits=1;
	s->Courses.sem5[4].No_Days_Present=0;
	s->Courses.sem5[4].No_Days_Total=0;
	s->Courses.sem5[4].Eligibility=0;
	s->Courses.sem5[4].Grade='\0';
	s->Courses.sem5[4].Examination_Block='-';
	strcpy(s->Courses.sem5[4].Examination_Date,"-");
	strcpy(s->Courses.sem5[4].Examination_Section,"-");
	strcpy(s->Courses.sem5[5].Course_Code,"BT306");
	strcpy(s->Courses.sem5[5].Course_Name,"Special Topic - III");
	s->Courses.sem5[5].Credits=2;
	s->Courses.sem5[5].No_Days_Present=0;
	s->Courses.sem5[5].No_Days_Total=0;
	s->Courses.sem5[5].Eligibility=0;
	s->Courses.sem5[5].Grade='\0';
	s->Courses.sem5[5].Examination_Block='\0';
	strcpy(s->Courses.sem5[5].Examination_Date,"\0");
	strcpy(s->Courses.sem5[5].Examination_Section,"\0");
	strcpy(s->Courses.sem5[6].Course_Code,"BT307");
	strcpy(s->Courses.sem5[6].Course_Name,"Enzyme Technology");
	s->Courses.sem5[6].Credits=4;
	s->Courses.sem5[6].No_Days_Present=0;
	s->Courses.sem5[6].No_Days_Total=0;
	s->Courses.sem5[6].Eligibility=0;
	s->Courses.sem5[6].Grade='\0';
	s->Courses.sem5[6].Examination_Block='\0';
	strcpy(s->Courses.sem5[6].Examination_Date,"\0");
	strcpy(s->Courses.sem5[6].Examination_Section,"\0");
	strcpy(s->Courses.sem5[7].Course_Code,"BT308");
	strcpy(s->Courses.sem5[7].Course_Name,"Molecular Genetics");
	s->Courses.sem5[7].Credits=4;
	s->Courses.sem5[7].No_Days_Present=0;
	s->Courses.sem5[7].No_Days_Total=0;
	s->Courses.sem5[7].Eligibility=0;
	s->Courses.sem5[7].Grade='\0';
	s->Courses.sem5[7].Examination_Block='\0';
	strcpy(s->Courses.sem5[7].Examination_Date,"\0");
	strcpy(s->Courses.sem5[7].Examination_Section,"\0");
	//Semester 6
	s->Courses.no_courses_sem6=7;
	strcpy(s->Courses.sem6[0].Course_Code,"BT351");
	strcpy(s->Courses.sem6[0].Course_Name,"Bioprocess Systems Analysis and Control");
	s->Courses.sem6[0].Credits=4;
	s->Courses.sem6[0].No_Days_Present=0;
	s->Courses.sem6[0].No_Days_Total=0;
	s->Courses.sem6[0].Eligibility=0;
	s->Courses.sem6[0].Grade='\0';
	s->Courses.sem6[0].Examination_Block='\0';
	strcpy(s->Courses.sem6[0].Examination_Date,"\0");
	strcpy(s->Courses.sem6[0].Examination_Section,"\0");
	strcpy(s->Courses.sem6[1].Course_Code,"BT352");
	strcpy(s->Courses.sem6[1].Course_Name,"Upstream & Downstream Process Technology");
	s->Courses.sem6[1].Credits=4;
	s->Courses.sem6[1].No_Days_Present=0;
	s->Courses.sem6[1].No_Days_Total=0;
	s->Courses.sem6[1].Eligibility=0;
	s->Courses.sem6[1].Grade='\0';
	s->Courses.sem6[1].Examination_Block='\0';
	strcpy(s->Courses.sem6[1].Examination_Date,"\0");
	strcpy(s->Courses.sem6[1].Examination_Section,"\0");
	strcpy(s->Courses.sem6[2].Course_Code,"BT353");
	strcpy(s->Courses.sem6[2].Course_Name,"Immunology");
	s->Courses.sem6[2].Credits=4;
	s->Courses.sem6[2].No_Days_Present=0;
	s->Courses.sem6[2].No_Days_Total=0;
	s->Courses.sem6[2].Eligibility=0;
	s->Courses.sem6[2].Grade='\0';
	s->Courses.sem6[2].Examination_Block='\0';
	strcpy(s->Courses.sem6[2].Examination_Date,"\0");
	strcpy(s->Courses.sem6[2].Examination_Section,"\0");
	strcpy(s->Courses.sem6[3].Course_Code,"BT354");
	strcpy(s->Courses.sem6[3].Course_Name,"Bioprocess Systems Analysis and Control Laboratory");
	s->Courses.sem6[3].Credits=1;
	s->Courses.sem6[3].No_Days_Present=0;
	s->Courses.sem6[3].No_Days_Total=0;
	s->Courses.sem6[3].Eligibility=0;
	s->Courses.sem6[3].Grade='\0';
	s->Courses.sem6[3].Examination_Block='-';
	strcpy(s->Courses.sem6[3].Examination_Date,"-");
	strcpy(s->Courses.sem6[3].Examination_Section,"-");
	strcpy(s->Courses.sem6[4].Course_Code,"BT355");
	strcpy(s->Courses.sem6[4].Course_Name,"Upstream & Downstream Process Technology Laboratory");
	s->Courses.sem6[4].Credits=1;
	s->Courses.sem6[4].No_Days_Present=0;
	s->Courses.sem6[4].No_Days_Total=0;
	s->Courses.sem6[4].Eligibility=0;
	s->Courses.sem6[4].Grade='\0';
	s->Courses.sem6[4].Examination_Block='-';
	strcpy(s->Courses.sem6[4].Examination_Date,"-");
	strcpy(s->Courses.sem6[4].Examination_Section,"-");
	strcpy(s->Courses.sem6[5].Course_Code,"BT356");
	strcpy(s->Courses.sem6[5].Course_Name,"Forensic Science");
	s->Courses.sem6[5].Credits=4;
	s->Courses.sem6[5].No_Days_Present=0;
	s->Courses.sem6[5].No_Days_Total=0;
	s->Courses.sem6[5].Eligibility=0;
	s->Courses.sem6[5].Grade='\0';
	s->Courses.sem6[5].Examination_Block='\0';
	strcpy(s->Courses.sem6[5].Examination_Date,"\0");
	strcpy(s->Courses.sem6[5].Examination_Section,"\0");
	strcpy(s->Courses.sem6[6].Course_Code,"BT357");
	strcpy(s->Courses.sem6[6].Course_Name,"Nanobiotechnology");
	s->Courses.sem6[6].Credits=4;
	s->Courses.sem6[6].No_Days_Present=0;
	s->Courses.sem6[6].No_Days_Total=0;
	s->Courses.sem6[6].Eligibility=0;
	s->Courses.sem6[6].Grade='\0';
	s->Courses.sem6[6].Examination_Block='\0';
	strcpy(s->Courses.sem6[6].Examination_Date,"\0");
	strcpy(s->Courses.sem6[6].Examination_Section,"\0");
	//Semester 7
	s->Courses.no_courses_sem7=5;
	strcpy(s->Courses.sem7[0].Course_Code,"BT401");
	strcpy(s->Courses.sem7[0].Course_Name,"Downstream Process Technology");
	s->Courses.sem7[0].Credits=4;
	s->Courses.sem7[0].No_Days_Present=0;
	s->Courses.sem7[0].No_Days_Total=0;
	s->Courses.sem7[0].Eligibility=0;
	s->Courses.sem7[0].Grade='\0';
	s->Courses.sem7[0].Examination_Block='\0';
	strcpy(s->Courses.sem7[0].Examination_Date,"-");
	strcpy(s->Courses.sem7[0].Examination_Section,"\0");
	strcpy(s->Courses.sem7[1].Course_Code,"BT402");
	strcpy(s->Courses.sem7[1].Course_Name,"Drug Development and Toxicology");
	s->Courses.sem7[1].Credits=4;
	s->Courses.sem7[1].No_Days_Present=0;
	s->Courses.sem7[1].No_Days_Total=0;
	s->Courses.sem7[1].Eligibility=0;
	s->Courses.sem7[1].Grade='\0';
	s->Courses.sem7[1].Examination_Block='\0';
	strcpy(s->Courses.sem7[1].Examination_Date,"-");
	strcpy(s->Courses.sem7[1].Examination_Section,"\0");
	strcpy(s->Courses.sem7[2].Course_Code,"BT403");
	strcpy(s->Courses.sem7[2].Course_Name,"Capstone Project work Phase - I");
	s->Courses.sem7[2].Credits=4;
	s->Courses.sem7[2].No_Days_Present=0;
	s->Courses.sem7[2].No_Days_Total=0;
	s->Courses.sem7[2].Eligibility=0;
	s->Courses.sem7[2].Grade='\0';
	s->Courses.sem7[2].Examination_Block='-';
	strcpy(s->Courses.sem7[2].Examination_Date,"-");
	strcpy(s->Courses.sem7[2].Examination_Section,"-");
	strcpy(s->Courses.sem7[3].Course_Code,"BT404");
	strcpy(s->Courses.sem7[3].Course_Name,"Metabolic Engineering");
	s->Courses.sem7[3].Credits=4;
	s->Courses.sem7[3].No_Days_Present=0;
	s->Courses.sem7[3].No_Days_Total=0;
	s->Courses.sem7[3].Eligibility=0;
	s->Courses.sem7[3].Grade='\0';
	s->Courses.sem7[3].Examination_Block='\0';
	strcpy(s->Courses.sem7[3].Examination_Date,"-");
	strcpy(s->Courses.sem7[3].Examination_Section,"\0");
	strcpy(s->Courses.sem7[4].Course_Code,"BT405");
	strcpy(s->Courses.sem7[4].Course_Name,"Tissue Engineering");
	s->Courses.sem7[4].Credits=4;
	s->Courses.sem7[4].No_Days_Present=0;
	s->Courses.sem7[4].No_Days_Total=0;
	s->Courses.sem7[4].Eligibility=0;
	s->Courses.sem7[4].Grade='\0';
	s->Courses.sem7[4].Examination_Block='\0';
	strcpy(s->Courses.sem7[4].Examination_Date,"-");
	strcpy(s->Courses.sem7[4].Examination_Section,"\0");
	//Semester 8
	s->Courses.no_courses_sem8=2;
	strcpy(s->Courses.sem8[0].Course_Code,"BT451");
	strcpy(s->Courses.sem8[0].Course_Name,"Internship");
	s->Courses.sem8[0].Credits=8;
	s->Courses.sem8[0].No_Days_Present=0;
	s->Courses.sem8[0].No_Days_Total=0;
	s->Courses.sem8[0].Eligibility=0;
	s->Courses.sem8[0].Grade='\0';
	s->Courses.sem8[0].Examination_Block='-';
	strcpy(s->Courses.sem8[0].Examination_Date,"-");
	strcpy(s->Courses.sem8[0].Examination_Section,"-");
	strcpy(s->Courses.sem8[1].Course_Code,"BT452");
	strcpy(s->Courses.sem8[1].Course_Name,"Capstone Project Phase - II");
	s->Courses.sem8[1].Credits=4;
	s->Courses.sem8[1].No_Days_Present=0;
	s->Courses.sem8[1].No_Days_Total=0;
	s->Courses.sem8[1].Eligibility=0;
	s->Courses.sem8[1].Grade='\0';
	s->Courses.sem8[1].Examination_Block='-';
	strcpy(s->Courses.sem8[1].Examination_Date,"-");
	strcpy(s->Courses.sem8[1].Examination_Section,"-");
}
void SetExamDetails()
{
	printf("Enter the semester of students whose examination needs to get conducted : ");
	int sem,no_blocks,no_floors,no_rooms,no_students;
	fflush(stdin);
	scanf("%d",&sem);
	printf("Enter the number of blocks in the college where the examination is planned to get conducted : ");
	scanf("%d",&no_blocks);
	printf("Enter the average number of floors present in a block : ");
	scanf("%d",&no_floors);
	printf("Enter the average number of classrooms present in a floor in a block : ");
	scanf("%d",&no_rooms);
	printf("Enter how many students can be accommodated in a classroom : ");
	scanf("%d",&no_students);
	int total_students=no_blocks*no_floors*no_rooms*no_students;
	FILE *fp1,*fp2;
	student s1;
	fp1=fopen("Student_Record.txt","r");
	fp2=fopen("Temp_Student_Record.txt","w");
	if(fp1==NULL||fp2==NULL)
	{
		printf("Error...Try again.\n");
	}
	else
	{
		int n=0;
		while(fread(&s1,sizeof(student),1,fp1))
		{
			if(sem==s1.Semester)
			{
				int m=0;
				if(s1.Semester==1)
				{
					for(int i=0;i<s1.Courses.no_courses_sem1;i++)
					{
						if(s1.Courses.sem1[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==2)
				{
					for(int i=0;i<s1.Courses.no_courses_sem2;i++)
					{
						if(s1.Courses.sem2[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==3)
				{
					for(int i=0;i<s1.Courses.no_courses_sem3;i++)
					{
						if(s1.Courses.sem3[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==4)
				{
					for(int i=0;i<s1.Courses.no_courses_sem4;i++)
					{
						if(s1.Courses.sem4[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==5)
				{
					for(int i=0;i<s1.Courses.no_courses_sem5;i++)
					{
						if(s1.Courses.sem5[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==6)
				{
					for(int i=0;i<s1.Courses.no_courses_sem6;i++)
					{
						if(s1.Courses.sem6[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==7)
				{
					for(int i=0;i<s1.Courses.no_courses_sem7;i++)
					{
						if(s1.Courses.sem7[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				else if(s1.Semester==8)
				{
					for(int i=0;i<s1.Courses.no_courses_sem8;i++)
					{
						if(s1.Courses.sem8[i].Eligibility)
						{
							m=1;
							break;
						}
					}
				}
				if(m)
				{
					n++;
				}
			}
		}
		if(n>total_students)
		{
			printf("\nSeat allotment is not possible as the number of students taking up the examination might exceed the number of seats allocated.\n");
		}
		else
		{
			rewind(fp1);
			char block='A';
			int classroom=1001;
			int number_students_room=0;
			int number_students_floor=0;
			int number_students_block=0;
			int total_number_students_room=no_students;
			int total_number_students_floor=no_students*no_rooms;
			int total_number_students_block=no_students*no_rooms*no_floors;
			while(fread(&s1,sizeof(student),1,fp1))
			{
				if(sem==s1.Semester&&sem==1)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem1;i++)
					{
						if(s1.Courses.sem1[i].Examination_Section!="-"&&s1.Courses.sem1[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem1[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem1[i].Examination_Block=block;
							strcpy(s1.Courses.sem1[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem1[i].Examination_Section!="-"&&s1.Courses.sem1[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem1[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==2)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem2;i++)
					{
						if(s1.Courses.sem2[i].Examination_Section!="-"&&s1.Courses.sem2[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem2[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem2[i].Examination_Block=block;
							strcpy(s1.Courses.sem2[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem2[i].Examination_Section!="-"&&s1.Courses.sem2[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem2[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==3)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem3;i++)
					{
						if(s1.Courses.sem3[i].Examination_Section!="-"&&s1.Courses.sem3[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem3[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem3[i].Examination_Block=block;
							strcpy(s1.Courses.sem3[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem3[i].Examination_Section!="-"&&s1.Courses.sem3[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem3[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==4)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem4;i++)
					{
						if(s1.Courses.sem4[i].Examination_Section!="-"&&s1.Courses.sem4[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem4[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem4[i].Examination_Block=block;
							strcpy(s1.Courses.sem4[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem4[i].Examination_Section!="-"&&s1.Courses.sem4[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem4[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==5)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem5;i++)
					{
						if(s1.Courses.sem5[i].Examination_Section!="-"&&s1.Courses.sem5[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem5[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem5[i].Examination_Block=block;
							strcpy(s1.Courses.sem5[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem5[i].Examination_Section!="-"&&s1.Courses.sem5[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem5[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==6)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem6;i++)
					{
						if(s1.Courses.sem6[i].Examination_Section!="-"&&s1.Courses.sem6[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem6[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem6[i].Examination_Block=block;
							strcpy(s1.Courses.sem6[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem6[i].Examination_Section!="-"&&s1.Courses.sem6[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem6[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==7)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem7;i++)
					{
						if(s1.Courses.sem7[i].Examination_Section!="-"&&s1.Courses.sem7[i].Eligibility)
						{
							found=1;
							char temp[2];
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem7[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem7[i].Examination_Block=block;
							strcpy(s1.Courses.sem7[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem7[i].Examination_Section!="-"&&s1.Courses.sem7[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem7[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				else if(sem==s1.Semester&&sem==8)
				{
					int d=1;
					int found=0;
					for(int i=0;i<s1.Courses.no_courses_sem8;i++)
					{
						if(s1.Courses.sem8[i].Examination_Section!="-"&&s1.Courses.sem8[i].Eligibility)
						{
							char temp[2];
							found=1;
							itoa(d,temp,10);
							char temp1[10];
							itoa(classroom,temp1,10);
							strcpy(s1.Courses.sem8[i].Examination_Date,strcat("Day - ",temp));
							s1.Courses.sem8[i].Examination_Block=block;
							strcpy(s1.Courses.sem8[i].Examination_Section,temp1);
							d++;
						}
						else if(s1.Courses.sem8[i].Examination_Section!="-"&&s1.Courses.sem8[i].Eligibility==0)
						{
							strcpy(s1.Courses.sem8[i].Examination_Date,"Not Eligible");
						}
					}
					if(found)
					{
						number_students_room++;
						number_students_block++;
						number_students_floor++;
						if(number_students_block==total_number_students_block)
						{
							number_students_room=0;
							number_students_floor=0;
							number_students_block=0;
							block+=1;
							classroom=1001;
						}
						else if(number_students_floor==total_number_students_floor)
						{
							number_students_floor=0;
							number_students_room=0;
							classroom=classroom+1000-no_rooms+1;
						}
						else if(number_students_room==total_number_students_room)
						{
							number_students_room=0;
							classroom+=1;
						}
					}
				}
				fwrite(&s1,sizeof(student),1,fp2);
			}
			fclose(fp1);
			fclose(fp2);
			fp1=fopen("Student_Record.txt","w");
			fp2=fopen("Temp_Student_Record.txt","r");
			while(fread(&s1,sizeof(student),1,fp2))
			{
				fwrite(&s1,sizeof(student),1,fp1);
			}
			printf("\nExamination Seat Allotment is completed successfully!");
			fclose(fp1);
			fclose(fp2);
		}
	}
}
