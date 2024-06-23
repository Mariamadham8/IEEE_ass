//q1
/*
#include<stdio.h>
int main()
{
    char s[100];
    int i=0,len=-1;
    fgets(s,30,stdin);
    while(s[i]!='\0')
    {
        len++;
        i++;
    }
    printf("%d",len);
}
*/
//****************************************************************************
//q2)
/*
#include<stdio.h>
int main()
{
     char s[100],x[100];
    int i=0,len=-1;
    fgets(s,30,stdin);
    while(s[i]!='\0')
    {
       x[i]=s[i];
       i++;
    }
     x[i] = '\0';

    printf("first string = %s\n", s);
    printf("second string = %s\n", x);
    printf("total characters copied = %d\n", i);

}
*/
//***************************************************************************

//q3)
/*
#include<stdio.h>
#include<string.h>
int main()
{
     char s[100],x[100];
    int i=0,len=-1;
    fgets(s,100,stdin);
    fgets(x,100,stdin);
    while(s[i]!='\0')
    {
        i++;
    }
  if (s[strlen(s) - 1] == '\n')
    s[strlen(s) - 1] = ' ';
    strcpy(s + strlen(s), x);
  printf("the concatinated sting = %s",s);
}
*/
//************************************************************************

//q4)
/*
#include<stdio.h>
#include<string.h>
int main()
{
     char s[100],x[100];
    int i=0,flag=1;
    fgets(s,100,stdin);
    fgets(x,100,stdin);
     while(s[i]!='\0'&& x[i] !='\0')
    {
       if(s[i]==x[i])
       {
       i++;
       continue;
       }
       else
       {
         flag=0;
          break;
       }

    }
    if(flag)
    printf("equal");
   else
   printf("unequal");
}
*/

//*****************************************************************************

//q6)
/*
#include<stdio.h>
#include<string.h>
int main()
{
     char s[100];
    int i=0;
    fgets(s,100,stdin);
     for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i] = s[i] + 32;
        }
    }

    printf("lower case string: %s", s);
}
*/
//*****************************************************************

//q7)
/*
#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = ~(1 << 5) & s[i]; 
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (1 << 5) | s[i];
        }
    }
    
    printf("%s\n", s);
}
*/
//**********************************************************88

//q8)
/*
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0';
    int special = 0, digit = 0, alpha = 0, i = 0;
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            digit++;
        } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            alpha++;
        } else {
            special++;
        }
        i++;
    }
    printf("digits : %d\n", digit);
    printf("alpha : %d\n", alpha);
    printf("special : %d\n", special);
}
*/
//************************************************************
//q11)
/*
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0';
    for(int i=strlen(s);i>=0;i--)
    {
        printf("%c",s[i]);
    }
}
*/
//*********************************************************************
//q12)
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], reverse[100];
    int flag;
    fgets(str,100,stdin);
    strcpy(reverse, str); 
    strrev(reverse);     
    flag = strcmp(str, reverse); 
    if(flag == 1)
    {
        printf("is Palindrome.");
    }
    else
    {
        printf("Not Palindrome.");
    }
}
*/
//**********************************************************************
//q14)

/*
#include <stdio.h>
#include <string.h>
int main()
{
     char s[100];int i=0,pos;
    fgets(s, 100, stdin);
    char c ;scanf("%c",&c);
    s[strcspn(s, "\n")] = '\0';
    while(s[i] !='\0')
    {
        if(s[i]==c)
        {
            pos=i;
            printf("is found in index:%d",pos);
            break;
        }
        i++;
    }
}
*/
//************************************************************************

//q15)
/*
#include <stdio.h>
#include <string.h>
int main()
{
     char s[100];int i=0,pos;
    fgets(s, 100, stdin);
    char c ;scanf("%c",&c);
    s[strcspn(s, "\n")] = '\0';
    while(s[i] !='\0')
    {
        if(s[i]==c)
        {
            pos=i;
        }
        i++;
    }
     printf("is last found in index:%d",pos);
}
*/
//****************************************************************

//q16)
/*
#include <stdio.h>
#include <string.h>
int main()
{
     char s[100];int i=0,pos;
    fgets(s, 100, stdin);
    char c ;scanf("%c",&c);
    s[strcspn(s, "\n")] = '\0';
    while(s[i] !='\0')
    {
        if(s[i]==c)
        {
            pos=i;
            printf("%d",pos);
        }
        i++;
    }
   
}
*/
//*****************************************************************

//q20)
/*
#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    long long freq[256] = {0};  
    int i = 0;
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0';
    while(s[i] != '\0') {
        freq[(unsigned char)s[i]]++;
        i++;
    }
    int printed[256] = {0}; 
    for(int j = 0; j < strlen(s); j++) {
        if (!printed[(unsigned char)s[j]]) {
            printf("%c = %lld\n", s[j], freq[(unsigned char)s[j]]);
            printed[(unsigned char)s[j]] = 1;  
        }
    }
}
*/
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

//q23)

/*
#include <stdio.h>
#include <string.h>
void removeChar(char *str, char charToRemove) {
    int i, j = 0;
    int len = strlen(str);
    
    for(i = 0; i < len; i++) {
        if(str[i] != charToRemove) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';  

int main() {
    char str[100], charToRemove;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
    printf("Enter the character to remove: ");
    scanf(" %c", &charToRemove);
    removeChar(str, charToRemove);
    printf("%s\n", str);
}
*/
//*************************************************************
//q28)
/*
#include <stdio.h>
#include <string.h>
char* findFirstOccurrence(char *str, char *word) {
    return strstr(str, word);
}

int main() {
    char str[200], word[50];
    char *result;
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0';  
    result = findFirstOccurrence(str, word);
    if (result != NULL) {
        printf("the first occurrence of the word '%s' is: %s\n", word, result);
    } else {
        printf("the word '%s' is not found in the string.\n", word);
    }
}
*/
//**************************************************************************

//q35)
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void trimLeadingWhiteSpaces(char *str) {
    int start = 0;
    while (isspace((unsigned char)str[start])) {
        start++;
    }
    if (start > 0) {
        int i = 0;
        while (str[start + i] != '\0') {
            str[i] = str[start + i];
            i++;
        }
        str[i] = '\0'; 
    }
}

int main() {
    char str[200];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
    trimLeadingWhiteSpaces(str);
    printf("Trimmed string: '%s'\n", str);

    return 0;
}
*/
