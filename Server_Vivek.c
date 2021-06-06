#include<stdio.h>
#include<conio.h>

void insert_record();
void display_record();
void update_record();
struct student
{
    int roll;
    char sec[10];
    char name[50];
    char branch[30];
    int sem, attendance, total;
};
    struct student s;
void main()
{
    int ch;
    

    while(ch!=5)
    {
    
    printf("\t\tWELCOME TO EXAM MANAGEMENT PROGRAM\n");

 

    

        
        printf("\t\t1: Insert student record\n");
        printf("\t\t2: Display student record\n");
        printf("\t\t3: Update student record\n");
        printf("\t\t4: Exit\n\n");
        fflush(stdin);
        printf("\t\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_record();
                break;
            case 2:
            display_record();
                break;

            case 3:
            update_record();
                break;
            case 4:exit(1);
            default:
                    

                printf("\n\t\tWrong choice Entered");
              
        }
        printf("\n\t\tPress any key to continue ");
        getch();
   }
}
void insert_record()
{
    FILE *fp;

    fp=fopen("exam.txt","ab+");

    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\t **** Previous Stored Data ****");
    display_record();
    printf("\n\n\t**** ENTER NEW STUDENT DATA ****\n\n");
    printf("\n\t\tEnter Student Roll Number: ");
    scanf("%d",&s.roll);
    fflush(stdin);
    printf("\n\t\tEnter Student Name: ");
    gets(s.name);
    printf("\n\t\tEnter Student Section: ");
    gets(s.sec);
    printf("\n\t\tEnter Student SEMESTER: ");
    scanf("%d",&s.sem);
    printf("\n\t\tenter the total number of working days:");
    scanf("%d",&s.total);
    printf("\n\t\tEnter Student total days present: ");
    scanf("%d",&s.attendance);
    if(s.attendance>s.total)
    {
        printf("\n\tThe Total days present cannot exceed total working days");
        printf("\n\t\tEnter Student total days present: ");
        scanf("%d",&s.attendance);
    }
    fwrite(&s,sizeof(s),1,fp);
    
    fclose(fp);
    printf("\n\t\t Updated Record !!\n");
    display_record();

}

void display_record()
{
    FILE *fp;
    
    fp=fopen("exam.txt","rb");

    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the File !!!");
        return;
    }

    printf("\n\n\t **** Students Details Are As Follows ****\n");
    printf("\nRoll.No\t\t\tName of Student\t\t\tSection\t\t\tsem\t\t\tattendance\n\n");
    
    

 

   
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%d\t\t\t%s\t\t\t\t%s\t\t\t%d\t\t\t%d\n",s.roll,s.name,s.sec,s.sem,s.attendance);
    }
    fclose(fp);
}
void update_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("exam.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Roll Number of Student Whose Record You Want To Update: ");
    scanf("%d",&ro);
    printf("\n\t\t*** Previously Stored Record Of Given Roll Number ***");

    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\nRoll.No\tName of Student\tSection\t\tattendance\t\tsem\n\n");
        printf("%d\t%s\t%s  \t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.attendance,s.sem);
        printf("\n\t\t*** Now Enter the New Record ***\n\n");

        printf("\n\t\tUpdated Student Roll Number: ");
        scanf("%d",&s.roll);
        fflush(stdin);
        printf("\n\t\tUpdated Student Name: ");
        gets(s.name);
        printf("\n\t\tUpdated Student Section: ");
        gets(s.sec);
        printf("\n\t\tUpdated Student attendance: ");
        scanf("%d",&s.attendance);
        printf("\n\t\tUpdated Student sem: ");
        scanf("%f",&s.sem);
        fseek(fp,-(long)sizeof(s),1);
        fwrite(&s,sizeof(s),1,fp);
        printf("\n\n\t\tRecord Updated Successfully Check The Display Section!!\n\t\t");
        }
    }
    if(flag==0)
    {
        printf("\n\t\tError : Something went wrong!!!");
    }
fclose(fp);
}
