//1)cube func

/*
#include<stdio.h>
double cube(double num);
int main(){
double num; 
scanf("%lf",&num);
double res=cube(num);
printf("%.2lf",res);
}
double cube(double num)
{
    num *=num*num;
    return num;
}
*/

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//2)circle prob
/*
#include<stdio.h>
#include<math.h>
double Diameter(double reduis);
double Circumference(double reduis);
double area(double reduis);
int main()
{
  double reduis;
  scanf("%lf",&reduis);
  double Diameter_res=Diameter(reduis);
  double Circumference_res= Circumference( reduis);
 double area_res= area(reduis);
 printf("Diameter_res:%.2f\n",Diameter_res);
 printf("Circumference_res:%.2lf\n", Circumference_res);
 printf("area:%.2lf\n",area_res);
}

double Diameter(double reduis)
{
    return reduis*2;
}
double Circumference(double reduis)
{
    return 2*M_PI*reduis;
}
double area(double raduis)
{
    return M_PI *pow(raduis,2);
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//3)min-max
/*
#include <stdio.h>

int max(int num1, int num2);
int min(int num1, int num2);

int main(){
    int num1,num2,maxy,miny;
    scanf("%d %d",&num1,&num2);
    maxy =max(num1,num2);
    miny=min(num1,num2);
    printf("%d\n",maxy);
    printf("%d\n",miny);
}
int max(int num1, int num2)
{
    if(num1>num2)
    return num1;
    else
    return num2;
}
int min(int num1, int num2)
{
    if(num1<num2)
    return num1;
    else
    return num2;
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//6)

/*
#include<stdio.h>
void prime(int num1,int num2);

int main()
{
   int num1 ,num2;
   scanf("%d %d",&num1,&num2);
   prime(num1,num2);
}

void prime(int num1,int num2)
{
   
    for(int i=num1;i<=num2;i++)
    {
         int is =1;
        for(int y=2;y<i;y++){
          if(i%y==0)
          {
            is=0;
          }
        }
        if(is){
            printf("%d ",i);
          }
    }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//8)armstrong
/*
#include<stdio.h>
void arm_strong(int num1, int num2);
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    arm_strong(num1,num2);
    return 0;
}

void arm_strong(int num1, int num2)
{

   for(int i=num1;i<=num2;i++)
   {
     int y=i;
     int res=0;
     while(y !=0)
     {
        int  mod = y %10;
        res = res + mod * mod * mod;
         y=y/10;
     }
     if(res==i){
        printf("%d ",i);
     }
     
   }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5

//12)printing even&odd numbers in same range
/*
#include<stdio.h>
void ev_(int start, int end);
void _od(int start, int end);
int main()
{
   int n1,m2;
   scanf("%d %d",&n1,&m2);
   printf("even numbers:");
   ev_(n1,m2);
   printf("\n");
     printf("odd numbers:");
   _od(n1,m2);
}
void ev_(int start, int end)
{
    if(start>end)
    return;
    if(start%2==0){
    printf("%d ",start);
    ev_(start+2,end);
    }
    else{
        start++;
        printf("%d ",start);
        ev_(start+2,end);
    }
     
}

void _od(int start, int end)
{
    if(start>end)
    return;
    if(start%2 !=0){
    printf("%d ",start);
    _od(start+2,end);
    }
    else{
    printf("%d ",start++);
    _od(start+2,end);
    }
     
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//16)palindrom
/*
#include<stdio.h>

int palindrom(int num, int originalNum);

int main() {
    int num;
    scanf("%d", &num);

    if (palindrom(num, num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}

int palindrom(int num, int originalNum) {
    static int reversedNum = 0;

    if (num != 0) {
        int mod = num % 10;
        reversedNum = reversedNum * 10 + mod;
        return palindrom(num / 10, originalNum);
    } else {
        return originalNum == reversedNum;
    }
}
*/

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//17)
/*
#include<stdio.h>
int sum(int num);
int main()
{
    int num;
    scanf("%d",&num);
  int res=  sum(num);
      printf("sum:%d",res);
}
int sum(int num){
   static int sumy=0;
    if(num !=0)
    {
       int mod=num%10;
        sumy +=mod;
        sum(num/10);
    }
   return sumy;
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//18)
/*
#include<stdio.h>
long fac(int num);
int main(){
  int num;
    scanf("%d",&num);
  int res=  fac(num);
      printf("factorial:%d",res);
}
long fac(int num)
{
     if(num == 0) 
        return 1;
    else
        return num * fac(num - 1);
}
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  
    if( n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;
 return find_nth_term(n-1, a, b, c)+find_nth_term(n-2,a , b , c)+(n-3, a, b, c);
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}