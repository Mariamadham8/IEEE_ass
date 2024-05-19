#include<stdio.h>
#include<string.h>

 typedef struct stu{
    char f_name[20];
    char l_name[20];
    double grade;
}stu;


stu *ptr=NULL;
double avrge ; int n;
stu student[10] ;
void get_stu( stu *ptr);
int avg_score(stu student[],int n);
void get_students_below_avg(stu student[],int n);
void highest_score(stu student[],int n);
void quit();
void choice();

int main()
{
    printf("enter number of students\n");
    scanf("%d",&n);
      student[n] ;
    for(int i=0;i<n;i++)
    {
       ptr =&student[i];
       get_stu(ptr);

    }
printf("************************************************************************\n");
  choice();
}

void choice()
{


printf("1->get avrage score\n"
"2->get students below the average scores\n"
"3->get the highest score students\n");
int cas;
scanf("%d",&cas);
switch(cas)
{
    case 1:
    avrge =avg_score(student,n);
    printf("the avrge grade =%0.2lf\n",avrge);
    quit();
    break;
    case 2:
    get_students_below_avg(student,n);
    quit();
    break;
    case 3:
    highest_score(student,n);
   quit();
   break;
}
}

void get_stu(stu *ptr)
{
    printf("enter stud.f_name: ");
    scanf("%s",ptr->f_name);
    printf("enter stud.l_name:");
    scanf("%s",ptr->l_name);
    printf("enter stud.grade:");
    scanf("%lf",&ptr->grade);
}

int avg_score(stu student[],int n)
{
    double avg=0;
    for(int i=0;i<n;i++)
    {
        avg +=student[i].grade;
    }
  return avg /=n;
}

void get_students_below_avg(stu student[],int n)
{
    for(int i=0;i<n;i++)
    {
      if(student[i].grade<avrge)
      {
        printf("the student %d %s %s score(%0.2lf) is below the avrege grade(%0.2lf)\n ",i,student[i].f_name,student[i].l_name,student[i].grade,avrge);
      }
    } 
}

void highest_score(stu student[],int n)
{
    double max=student[0].grade;
    int idx;
    for(int i=0;i<n;i++)
    {
        if(max<student[i].grade)
        {
            max=student[i].grade;
            idx=i;
        }
    }
    printf(" the maximum grade =%0.2lf\n",max);
     printf("the top students is: \n");
     for(int i=0;i<n;i++)
    {
        if(student[idx].grade==student[i].grade )
        {
           printf(" %s %s\n",student[i].f_name,student[i].l_name);
        }
    }
}

void quit()
{
    printf("do you want continue?1 yes 2 no:");
    int n;
    scanf("%d",&n);
    switch(n){
        case 1:
        choice();
        case 2:
        return ;
    }

}

