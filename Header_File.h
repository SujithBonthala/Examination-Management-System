typedef struct Course
{
	char Course_Name[100];
	char Course_Code[10];
	int Credits;
	int No_Days_Present;
	int No_Days_Total;
	int Eligibility;
	char Grade;
	char Examination_Date[20];
	char Examination_Block;
	char Examination_Section[5];
}course;

typedef struct Course_Info
{
	int no_courses_sem1;
	int no_courses_sem2;
	int no_courses_sem3;
	int no_courses_sem4;
	int no_courses_sem5;
	int no_courses_sem6;
	int no_courses_sem7;
	int no_courses_sem8;
	course sem1[10];
	course sem2[10];
	course sem3[10];
	course sem4[10];
	course sem5[10];
	course sem6[10];
	course sem7[10];
	course sem8[10];
}c_info;

typedef struct student_records
{
	char Name[50];
	char SRN[20];
	char Password[50];
	int Semester;
	char Branch[10];
	char Section;
	c_info Courses;
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

void InitCSE(student*);

void InitECE(student*);

void InitME(student*);

void InitEEE(student*);

void InitCV(student*);

void InitBT(student*);

void ChangeStudentPassword(student *);

void StudentLogin();

void StudentMainMenu(student *);

void InitBranch(student*);

void CheckDetails(student *);

void checkresults(student *s);

void checkattendance(student *s);

void seatallotment(student *s);

void TeacherMainMenu(char prn[]);

void ChangeTeacherPassword(char prn[]);
	
void give_studentattendance(char section);

void GiveAttendance();

void GiveGrades();

void give_studentgrades(char section);

void TeacherLogin();
