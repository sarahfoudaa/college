#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

struct finished_courses
{
    char fcourse_name[100];
    int fcourse_code;
    char fgta_f_name[10],fgta_m_name[10],fgta_l_name[10];
     int fgta_code;
     int finished_courses;
     char flec_f_name[10],flec_m_name[10],flec_l_name[10];
     char flab_f_name[10],flab_m_name[10],flab_l_name[10];
    int flab_code;
        int sevth_exam, tweth_exam,ten_per,final_exam,total_mark;
         char student_grad;
         int flec_code;
};

struct current_courses
{
    char ccourse_name[8];
    int ccourse_code;
int curr_courses;

    char cgta_f_name[10],cgta_m_name[10],cgta_l_name[10];
     int cgta_code;
     char clec_f_name[10],clec_m_name[10],clec_l_name[10];
         char clec_code[10];
         char clab_f_name[10],clab_m_name[10],clab_l_name[10];
         int clab_code;
};

struct cours
{
    int max_cred_h,finished_cred_h,curr_cred_h,remained_cred_h;
    int total_marks,courses_gpa;
         struct current_courses;
         struct finished_courses;
};

struct student
{
    char first_name[20],middle_name[20],last_name[20];
    char nationality[20];
    int ID;
    int flat_no,house_no,postal_code;
    char street_name[25], areadistrict_name[25],city_name[25],gov_name[25],country[25];
    int day_of_birth,month_of_birth,year_of_birth;
    char gender[10];
    char dep[20];
    char tutor_name[20];
    int tutor_code;
    double gpa;
    int enrolment_term,enrolment_year;
    int reg_no;
    char email[50];
    int mobil_no,home_no;
    int crrent_semester;
    struct cours ;
    char regestration_no;
    char reg1,reg2,reg3;



};

int displayinfo(struct student student_data[1000],int n);
int getinfo(struct student student_data[1000],int n );
int main ()
{
    struct student student_data[1000];
    int n;
    displayinfo(student_data,n);
}

int displayinfo(struct student student_data[1000],int n)
{
  getinfo(student_data,n );
  int i,j,k;
   time_t currentTime;
    time(&currentTime);
    struct tm*myTime=localtime(&currentTime);

    printf("=====================================================================================\n");


    printf(" the student name: %s %s %s\n",student_data[i].first_name,student_data[i].middle_name,student_data[i].last_name);
    printf(" the student nationality: %s\n",student_data[i].nationality);
     printf(" the student ID: %d\n",student_data[i].ID);
   printf(" the student flat number %d\nhouse number %d\n postal code %d\n",student_data[i].flat_no,student_data[i].house_no,student_data[i].postal_code);
   printf(" the student address: %s, %s, %s, %s, %s\n",student_data[i].street_name, student_data[i].areadistrict_name,student_data[i].city_name,student_data[i].gov_name,student_data[i].country);
   printf(" the student's age is %d years and %d months\n ",(myTime->tm_year+1900)-student_data[i].year_of_birth,(myTime->tm_mon+1)-student_data[i].month_of_birth);
   printf(" the gender of the student is %s\n",student_data[i].gender);
   printf(" the student's department: %s\n",student_data[i].dep);
   printf(" the tutor name: %s\n",student_data[i].tutor_name);
   printf(" the tutor code: %d\n",student_data[i].tutor_code);
    printf(" the student gpa: %lf\n",student_data[i].gpa);
    //printf(" the the student's reg number : %d\n",student_data[i].tutor_code);
    printf(" the student's enrolment term : %d\n and enrolment year: %d\n",student_data[i].enrolment_term,student_data[i].enrolment_year);
 printf("student regestration number %s:\n",student_data[i].regestration_no);
 printf("the student contacts\n email: %s \n mobile number: 0%d \n home number %d \n",student_data[i].email,student_data[i].mobil_no,student_data[i].home_no);


      printf("the student's finished courses is \t name %s \t code %d \n",student_data[i].fcourse_name,student_data[i].fcourse_code);
         printf("the student's finished courses lecturer is \t name %s %s %s \t code %d \n",student_data[i].flec_f_name,student_data[i].flec_m_name,student_data[i].flec_l_name,student_data[i].flec_code);
         printf("the student's finished courses GTA is \t name %s %s %s \t code %d \n",student_data[i].fgta_f_name,student_data[i].fgta_m_name,student_data[i].fgta_l_name,student_data[i].fgta_code);
         printf("the student's finished courses GTA lab is \t name %s %s %s \t code %d \n",student_data[i].flab_f_name,student_data[i].flab_m_name,student_data[i].flab_l_name,student_data[i].flab_code);
         printf("the student's total marks of this course out of 100 %d % \n", student_data[i].total_mark);
         printf("total mark of all finished courses is %d \n",student_data[i].total_marks);
         printf("GPA for finished courses is %d \n", student_data[i].courses_gpa);
         printf("grade for this course is %c\n",student_data[i].student_grad);

        printf("the student's current courses is \n name %s \n code %d \n",student_data[i].ccourse_name,student_data[i].ccourse_code);
          printf("the student's current courses lecturer is \n name %s %s %s \n code %d \n ",student_data[i].clec_f_name,student_data[i].clec_m_name,student_data[i].clec_l_name,student_data[i].clec_code);
          printf("the student's current courses GTA is \n name %s %s %s \n code %d \n",student_data[i].cgta_f_name,student_data[i].cgta_m_name,student_data[i].cgta_l_name,student_data[i].cgta_code);
          printf("the student's current courses GTA lab is \n name %s %s %s \n code %d \n",student_data[i].clab_f_name,student_data[i].clab_m_name,student_data[i].clab_l_name,student_data[i].clab_code);

    printf(" maximum hours the student should achieve %d hours\n hours he already finished %d hours\n current hours he is achieving %d hours \n hours remaining for him to graduate %d hours \n ",student_data[i].max_cred_h,student_data[i].finished_cred_h,student_data[i].curr_cred_h,student_data[i].remained_cred_h);
printf("the studend is in term %d\n",student_data[i].crrent_semester);


}


int getinfo(struct student student_data[1000],int n )

{
 int i,j,k,gen;

printf("please enter the number of students\n");

    scanf("%d",&n);
    char gender[10];

    for(i=0;i<n;i++)
    {



     printf(" please your first name \n");
    gets(student_data[i].first_name);
    gets(student_data[i].first_name);

    printf(" please enter your middle name \n");
    gets(student_data[i].middle_name);

    printf(" please enter your last name \n");
    gets(student_data[i].last_name);

    printf(" please enter your nationality \n");
    gets(student_data[i].nationality);
    printf(" please enter your ID \n");
    scanf("%d",&student_data[i].ID);


    printf(" please enter your flat number,house number and postal code \n");
    scanf("%d%d%d",&student_data[i].flat_no,&student_data[i].house_no,&student_data[i].postal_code);


    printf(" please enter your address\n ");
    printf("  street name: \n");
    gets(student_data[i].street_name);
    gets(student_data[i].street_name);

    printf("  area or district name: \n");
    gets(student_data[i].areadistrict_name);

    printf("  city name: \n");
    gets(student_data[i].city_name);

    printf("  government name: \n");
    gets(student_data[i].gov_name);

    printf("  country: \n");
    gets(student_data[i].country);

    printf(" please enter your\n ");
    printf("  month of birth in numbers: \n");
    scanf("%d",&student_data[i].month_of_birth);

    printf("  year of birth in numbers: \n");
    scanf("%d",&student_data[i].year_of_birth);

    time_t currentTime;
    time(&currentTime);
    struct tm*myTime=localtime(&currentTime);

      printf("please enter your gender \n (enter 1 for female or 0 for male)\n");
      scanf("%d",&gen);


     if(gen==1)
        {
            gender[10]="female";
            strcpy(student_data[i].gender,"female");
        }
      else
        if(gen==0)
        {
            gender[10]="male";
           strcpy(student_data[i].gender,"male");
        }
    else
        {
            gender[10]="undefined";
            strcpy(student_data[i].gender,"undefined");
        }

    printf(" please enter your department \n");
    gets(student_data[i].dep);
    gets(student_data[i].dep);


    printf(" please enter your tutor name \n");
    gets(student_data[i].tutor_name);

    printf(" please enter your tutor code \n");
    scanf("%d",&student_data[i].tutor_code);


    printf(" please enter your gpa \n");
    scanf("%lf",&student_data[i].gpa);

    int enrolment_term,enrolment_year;
    printf(" please enter your enrolment term \n");
    scanf("%d",&student_data[i].enrolment_term);


    printf(" please enter your enrolment year \n");
    scanf("%d",&student_data[i].enrolment_year);


    printf("please enter your contacts\n");
    printf("email\t");
    gets(student_data[i].email);
     gets(student_data[i].email);

    printf("mobile number\t");
    scanf("%d",&student_data[i].mobil_no);

    printf("home number\t");
    scanf("%d",&student_data[i].home_no);

      printf("how much courses have the student finished?\n");
    scanf("%d",&student_data[i].finished_courses);

     for (j=0;j<student_data[i].finished_courses;j++)
     {
         printf("please enter the student's finished course information\n");
         printf("name\t");
         gets(student_data[i].fcourse_name);
         gets(student_data[i].fcourse_name);


         printf(" code\t");
    scanf("%d",&student_data[i].fcourse_code);


         printf("lecturer full name  \n");
         printf("first name\t");
         gets(student_data[i].flec_f_name);
          gets(student_data[i].flec_f_name);

         printf("middle name\t");
         gets(student_data[i].flec_m_name);
        printf("last name\t");
         gets(student_data[i].flec_l_name);


        printf(" code\t");
    scanf("%d",&student_data[i].flec_code);

         printf("GTA full name  \n");
         printf("first name\t");
         gets(student_data[i].fgta_f_name);
         gets(student_data[i].fgta_f_name);

         printf("middle name\t");
         gets(student_data[i].fgta_m_name);

        printf("last name\t");
         gets(student_data[i].fgta_l_name);


         printf(" code\t");
    scanf("%d",&student_data[i].fgta_code);

         printf("GTA lab full name  \n");
         printf("first name\t");
         gets(student_data[i].flab_f_name);
         gets(student_data[i].flab_f_name);

         printf("middle name\t");
         gets(student_data[i].flab_m_name);

        printf("last name\t");
         gets(student_data[i].flab_l_name);

       printf(" code\n");
    scanf("%d",&student_data[i].flab_code);

         printf("please enter your marks for this course \n");
         printf("7th exam \t");
         scanf("%d",&student_data[i].sevth_exam);

         printf("12th exam \t");
         scanf("%d",&student_data[i].tweth_exam);

         printf("10 percent of attendence \t");
         scanf("%d",&student_data[i].ten_per);

         printf("final exam \t");
         scanf("%d",&student_data[i].final_exam);

         student_data[i].total_mark=student_data[i].sevth_exam+student_data[i].tweth_exam+student_data[i].ten_per+student_data[i].final_exam;
         student_data[i].total_marks=0;
         student_data[i].total_marks=student_data[i].total_marks+student_data[i].total_mark;
         student_data[i].courses_gpa=(student_data[i].total_marks/100)*4;


        if(student_data[i].total_mark>=90&&student_data[i].total_mark<=100)
            student_data[i].student_grad='A';

       else if(student_data[i].total_mark>=80&&student_data[i].total_mark<=89)
                student_data[i].student_grad='B';

        else if(student_data[i].total_mark>=74&&student_data[i].total_mark<=79)
                student_data[i].student_grad='C';

          else if(student_data[i].total_mark>=70&&student_data[i].total_mark<=73)

                student_data[i].student_grad='D';
            else if(student_data[i].total_mark>=0&&student_data[i].total_mark<=69)
                student_data[i].student_grad='F';

     }

    printf("how many course are the student having currently?\n");
    scanf("%d",&student_data[i].curr_courses);

    for (k=0;k<student_data[i].curr_courses;k++)
     {
        printf("please enter the student's current course information\n");
         printf("name\t");
         gets(student_data[i].ccourse_name);
         gets(student_data[i].ccourse_name);

         printf(" code\n");
    scanf("%d",&student_data[i].ccourse_code);

         printf("lecturer full name  \n");
         printf("first name\t");
         gets(student_data[i].clec_f_name);
         gets(student_data[i].clec_f_name);

         printf("middle name\t");
         gets(student_data[i].clec_m_name);

        printf("last name\t");
         gets(student_data[i].clec_l_name);


         printf(" code\t");
    scanf("%d",&student_data[i].clec_code);



          printf("GTA full name  \n");
         printf("first name\t");
         gets(student_data[i].cgta_f_name);
         gets(student_data[i].cgta_f_name);

         printf("middle name\t");
         gets(student_data[i].cgta_m_name);
        printf("last name\t");
         gets(student_data[i].cgta_l_name);


         printf(" code\n");
    scanf("%d",&student_data[i].cgta_code);



         printf("GTA lab full name  \n");
         printf("first name\t");
         gets(student_data[i].clab_f_name);
         gets(student_data[i].clab_f_name);

         printf("middle name\t");
         gets(student_data[i].clab_m_name);

        printf("last name\t");
         gets(student_data[i].clab_l_name);


         printf(" code\t");
    scanf("%d",&student_data[i].clab_code);


         }


          printf("please enter your credit hours information: \n");

    student_data[i].max_cred_h=1728;

     printf("current credit hours \n");
     scanf("%d",&student_data[i].curr_cred_h);

     student_data[i].finished_cred_h=(student_data[i].finished_courses+student_data[i].curr_courses)*3*16;

    student_data[i].remained_cred_h=student_data[i].max_cred_h-student_data[i].finished_cred_h-student_data[i].curr_cred_h;

    if(student_data[i].finished_cred_h>0&&student_data[i].finished_cred_h<=288)//1     *    3     *    16     *      6
            student_data[i].crrent_semester=1;                                    //course    credit     weeks      courses

    else if (student_data[i].finished_cred_h>288&&student_data[i].finished_cred_h<=576)
            student_data[i].crrent_semester=2;
    else if (student_data[i].finished_cred_h>576&&student_data[i].finished_cred_h<=864)
            student_data[i].crrent_semester=3;
    else if (student_data[i].finished_cred_h>864&&student_data[i].finished_cred_h<=1152)
                  student_data[i].crrent_semester=4;

    else if (student_data[i].finished_cred_h>1152&&student_data[i].finished_cred_h<=1440)
            student_data[i].crrent_semester=5;
    else if (student_data[i].finished_cred_h>1440&&student_data[i].finished_cred_h<=1728)
              student_data[i].crrent_semester=6;
     else if (student_data[i].finished_cred_h>1728&&student_data[i].finished_cred_h<=2016)
            student_data[i].crrent_semester=7;

     else if (student_data[i].finished_cred_h>2016&&student_data[i].finished_cred_h<=2304)

            student_data[i].crrent_semester=8;


    }

   student_data[i].reg1 = strcat(student_data[i].enrolment_term,0);

   student_data[i].reg2= strcat( student_data[i].reg1, i);
   student_data[i].reg3=strcat(student_data[i].reg2,0);

    student_data[i].regestration_no=strcat(student_data[i].reg3,student_data[i].enrolment_year);



return student_data;
}
