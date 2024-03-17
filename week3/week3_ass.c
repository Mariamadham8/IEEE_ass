

//*********************************************************************************
// prob3)find all arithmaitic oprations
/*
#include <stdio.h>

int main(){
    int n,y;
    printf("enter 2 numbers:\n");
    scanf("%d %d",&n,&y);
    int sum =n+y;
    int def =n-y;
    int mul =n*y;
    float div = (float)n/y;
    int mod=n%y;
    printf("SUM = %d\n", sum);
    printf("DIFFERENCE = %d\n", def);
    printf("PRODUCT = %d\n", mul);
    printf("QUOTIENT = %f\n", div);
    printf("MODULUS = %d", mod);
}
*/
//**********************************************************************

//prob4)perimeter of the rectangle
/*
#include <stdio.h>
int main(){
    int x,y;
    printf("enter directions:\n");
    scanf("%d %d",&x,&y);
    int res=(x+y)*2;
    printf("the perimeter =%d",res);
}
*/
//*****************************************************************
//prob5)area of rigtangle
/*
#include <stdio.h>
int main(){
 float x,y;
    printf("enter directions:\n");
    scanf("%f %f",&x,&y);
    float res=x*y;
    printf("the perimeter =%f",res);
}
*/
//***************************************************************
//prob6)diameter, circumference and area of the circle

/*
#include <stdio.h>
int main(){
    float x,d,area,res;
    float const pi=3.14;
    printf("enter radius");
    scanf("%f",&x);
    d=2*x;
    res=pi*2*x;
    area=pi*x*x;
     printf("Diameter of circle = %.2f units \n", d);
    printf("Circumference of circle = %.2f units \n", res);
    printf("Area of circle = %.2f sq. units ", area);
}
*/
//*******************************************************************

//prob7)How to convert length from centimeter to meter and kilometer
/*
#include <stdio.h>
int main(){
    float m;
    printf("enter cm:\n");
    scanf("%f",&m);
    float meter =m/100;
    float kmeter =meter/1000;
    printf("Length in Meter = %.2f m \n", meter);
    printf("Length in Kilometer = %.2f km", kmeter);

}
*/
//****************************************************************
//prob8)
/*
#include <stdio.h>
int main()
{
    float celsus, fahrenhit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenhit = (celsus * 9 / 5) + 32;
    printf("%.2f Celsus = %.2f Fahrenhit", celsius, fahrenheit);
}
*/
//**********************************************************************
//prob10)convert days to years, weeks and day
/*
#include <stdio.h>
int main()
{
  int days;
  scanf("%d",&days);
  int years=days/365;
  int weeks=(days%365)/7;
   days=(days%365)%7;
   printf("YEARS: %d\n", years);
    printf("WEEKS: %d\n", weeks);
    printf("DAYS: %d", days);
}
*/
//**************************************************************************
//prob11)power
/*
#include <stdio.h>
#include <math.h> 
int main()
{
    double base, expo, power;

    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%lf", &expo);
    power = pow(base, expo);

    printf("%.2lf ^ %.2lf = %.2lf", base, expo, power);
}
*/
//**********************************************************
//prob12) squarw root
/*
#include <stdio.h>
#include <math.h>

int main()
{
    double num, res;
    printf("Enter any numbe: ");
    scanf("%lf", &num);
    res = sqrt(num);
    printf("Square root of %.2lf = %.2lf", num, res);

    return 0;
}
*/
//**********************************************************************
//prob16)find avrg/tatal/percentage

/*
#include <stdio.h>

int main()
{
    float num1, num2, num3, num4, num5; 
    float total, average, percentage;

    printf("Enter marks of five subjects: \n");
    scanf("%f%f%f%f%f", &num1, &num2, &num3, &num4, &num5);

    total = num1+ num2 +num3+ num4+ num5; 
    average = total / 5.0;
    percentage = (total / 500.0) * 100;

    printf("Total marks = %.2f\n", total);
    printf("Average marks = %.2f\n", average);
    printf("Percentage = %.2f", percentage);

    
}
*/