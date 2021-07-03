
#include<stdio.h>
#include<string.h>
#include "Header_File.h"
void LoginMenu()
{
	int choice=0;
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4)
	{
		printf("\nEnter 1 to Login as Admin\n");
		printf("Enter 2 to Login as Student\n");
		printf("Enter 3 to Login as Teacher\n");
		printf("Enter 4 to Exit\n");
		scanf("%d",&choice);
	}
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
		printf("Enter the password : ");
		scanf("%[^\n]s",password_temp);
		fflush(stdin);
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
			printf("Invalid useraname or password\n");
			int c=0;
			while(c!=1&&c!=2&&c!=3)
			{
				printf("Enter 1 to try again\n");
				printf("Enter 2 to go back to Login Menu\n");
				printf("Enter 3 to Exit\n");
				scanf("%d",&c);
			}
			if(c==2)
			{
				LoginMenu();
				break;
			}
			else if(c==3)
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
	while(choice!=12)
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
		printf("\nEnter 11 to Set Exam Details");
		printf("\nEnter 12 to Logout\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
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
			case 11:
			{
				SetExamDetails();
				break;
			}
		}
	}
}
void GetStudentCredentials()
{
	login();
}

void StudentMainMenu(char *pass)
{
	printf("Logged in Successfully\n");
	printf("\nWELCOME SELECT PROVIDED OPTIONS TO CONTINUE\n");
	int choice;
	do
	{
		printf("\nEnter 1 to View Results\n");
		printf("\nEnter 2 to the Details of the Course\n");
        printf("\nEnter 3 to the Check Exam seat allotment\n");
		printf("\nEnter 4 to change password\n");
		printf("\nEnter 5 to logout\n");
		printf("\nEnter your Choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("yet to do");
			 break;
			
			case 2:printf("yet to do");
				break;
			case 3:printf("yet to do");	
				break;
			
			case 4: changepassword(pass);
				break;
			case 5: LoginMenu();
					 break;
		


		}
 

	
	}while(choice!=5);
	
}
void GetTeacherCredentials()
{
	printf("\nYet to do\n");
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
