//q4)
/*
#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    if(num%5==0 && num%11==0){
        printf("Number is divisible by 5 and 11");
    }
    else
    printf("Number is not divisible by 5 and 11");
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%55
//Q7)
/*
#include<stdio.h>
int main(){
    char c;
    scanf("%c",&c);
     if((c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("Character is an ALPHABET.");
    }
    else
    {
        printf("Character is NOT ALPHABET.");
    }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Q8)
/*
#include <stdio.h>
int main()
{
    char c;
    scanf("%c", &c);
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
    {
        printf("'%c' is Vowel.", c);
    }
    else 
    {
    
        printf("'%c' is Consonant.", c);
    }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//q)12
/*
#include <stdio.h>
int main()
{
    int month;
    scanf("%d", &month);
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        printf("It contains 31 day");
    }
    else if(month==2){
        printf("contain28/29");
    }
    else{
          printf("contain 30");
    }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//14)
/*
#include <stdio.h>
int main()
{
 int angle1, angle2, angle3, sum;
    scanf("%d%d%d", &angle1, &angle2, &angle3);
    sum = angle1 + angle2 + angle3; 
     if(sum == 180 ) 
    {
        printf("Triangle is valid.");
    }
    else
    {
        printf("Triangle is not valid.");
    }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//16)
/*
#include <stdio.h>

int main()
{
    int side1, side2, side3;
    printf("Enter three sides of triangle: ");
    scanf("%d%d%d", &side1, &side2, &side3);

    if(side1==side2 && side2==side3) 
    {
        printf("Equilateral triangle.");
    }
    else if(side1==side2 || side1==side3 || side2==side3) 
    {
        printf("Isosceles triangle.");
    }
    else 
    {
        printf("Scalene triangle.");
    }
}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//19)
/*
#include <stdio.h>

int main()
{
   int g1, g2, g3, g4, g5;
    printf("Enter grades for 5 subjects: ");
    scanf("%d %d %d %d %d", &g1, &g2, &g3, &g4, &g5);

    float sum=(g1+g2+g3+g4+g5)/5.0;
    printf("Percentage = %.2f\n", sum);
      if(sum >= 90)
    {
        printf("Grade A");
    }
    else if(sum  >= 80)
    {
        printf("Grade B");
    }
    else if(sum  >= 70)
    {
        printf("Grade C");
    }
    else if(sum  >= 60)
    {
        printf("Grade D");
    }
    else if(sum  >= 40)
    {
        printf("Grade E");
    }
    else
    {
        printf("Grade F");
    }

}
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//20)
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                //switch case
                                
