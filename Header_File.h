typedef struct student_records
{
	char Name[50];
	char SRN[20];
	char Password[50];
	int Semester;
	char Branch[10];
	char Section;
	int No_Days_Present;
	int No_Days_Total;
	int Eligibility;
}student;

typedef struct teacher_records
{
	char Name[50];
	char PRN[20];
	char Password[50];
	char Branch[10];
}teacher;

void LoginMenu();

void GetAdminCredentials();

void AdminMainMenu();

void GetStudentCredentials();
 
void StudentMainMenu(char *name);

void GetTeacherCredentials();

int Cipher(char un[],char pw[]);

void CreateStudentAcc();

void CreateTeacherAcc();

void NumberStudentAcc();

void NumberTeacherAcc();

void SearchStudentAcc();

void SearchTeacherAcc();

void UpdateStudentAcc();

void UpdateTeacherAcc();

void DeleteStudentAcc();

void DeleteTeacherAcc();

void SetExamDetails();

void login();

void changepassword(char *pass);

