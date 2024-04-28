
//q5)
/*
#include<stdio.h>
int main()
{
   int arr[10];
   for(int i=0;i<10;i++)
   {
     scanf("%d",&arr[i]);
   }
   int *ptr=arr;
   for(int i=0;i<10;i++)
   {
    printf("%d ",*ptr);
    ptr++;
   }
}
*/

//*****************************************************************

//q6)
/*
#include<stdio.h>
int main() {
    int arr[10];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    int arr2[10];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &arr2[i]);
    }

    int *ptr = arr, *ptr2 = arr2;
    while(ptr < arr + 3 && ptr2 < arr2 + 3) {
        int temp = *ptr;
        *ptr = *ptr2;
        *ptr2 = temp;
        ptr++;
        ptr2++;
    }

    printf("array 1 after swapping: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("array 2 after swapping: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}
*/

//******************************************************************

//q7)
//مش فاهمه دي ليه مش شغاله
/*
#include<stdio.h>
int main() 
{
     int arr[10];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    int size =sizeof(arr)/sizeof(arr[0]);
    int *ptr=arr+size-1;
     for(int i = 0; i < 3; i++) 
     {
        printf("%d ",*ptr);
        ptr--;
     }
}
*/

//**********************************************************
//q8)
/*
#include<stdio.h>
int search(int *arr, int size, int target) {
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        if (*ptr == target) {
            return 1; 
        }
        ptr++;
    }
    return 0; 
}

int main() {
    int arr[10];
    int size, target;
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter the element to search: ");
    scanf("%d", &target);

    if (search(arr, size, target)) {
        printf("element %d found in the array.\n", target);
    } else {
        printf("element %d not found in the array.\n", target);
    }
}
*/
//*****************************************************************

//q11)

//********************************************************************8

//q12)
/*
#include<stdio.h>

int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
int main() {
    char str[100];
    printf("enter a string: ");
    scanf("%s", str);

    int length = stringLength(str);
    printf("length of the string: %d\n", length);
}
*/
//****************************************************************
//q14)

/*
#include<stdio.h>

void concatenateStrings(char *str1, char *str2) {
    while (*str1 != '\0') {
        str1++;
    }
    *str1 = ' '; 
    str1++;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);

    concatenateStrings(str1, str2);

    printf("%s\n", str1);

}
*/

//**************************************************

//q16)
