//Q1)
/*
#include<stdio.h>
int main()
{
    int n ,arr[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

 printf("the arrray u enter :");
 for(int i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
}
*/

//**************************************************************************
//q2)
/*
#include<stdio.h>
int main()
{
    int n ;
    int sum=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
 printf("sum of the arrray u enter :");
 for(int i=0;i<n;i++)
    {
        sum +=arr[i];
    }
     printf("%d ",sum);
}*/
//**********************************************************************
//q5)
/*
#include <stdio.h>
#include <limits.h> 
int main() {
    int arr[20], size, i;
    int largest = INT_MIN, secondLargest = INT_MIN;
    scanf("%d", &size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    printf("first largest = %d\n", largest);
    printf("second largest = %d", secondLargest);
 
}
*/
//***************************************************************************8

//q9)
/*
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], size, insertPos, newValue;
    printf("enter size of the array (1-%d): ", MAX_SIZE);
    scanf("%d", &size);
    printf("enter elements in the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("enter position to insert (1-%d): ", size + 1);
    scanf("%d", &insertPos);
    printf("enter value to insert: ");
    scanf("%d", &newValue);
    if (insertPos < 1 || insertPos > size + 1) {
        printf("invalid insert position. Please enter a position between 1 and %d.\n", size + 1);
    } else {
        
        for (int i = size; i >= insertPos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insertPos - 1] = newValue;

        printf("Array after insertion: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

*/
//**********************************************************************
//q13)
/*

#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE], freq[MAX_SIZE];
    int size, count = 0;

    printf("Enter size of the array (1-%d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter elements in the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for (int i = 0; i < size; i++) {
        int duplicate = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                if (freq[j] != 0) {
                    if (duplicate) {
                        count++;
                        duplicate = 0;
                    }
                    freq[j] = 0;
                }
            }
        }
    }

    if (count == 0) {
        printf("no duplicate elements found.\n");
    } else {
        printf("total duplicate elements: %d\n", count);
    }

    return 0;
}
*/
//***********************************************************************
//q15)
/*
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
    int size1, size2, mergeSize;

    printf("Enter size of the first array (1-%d): ", MAX_SIZE);
    scanf("%d", &size1);

    printf("Enter elements of the first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of the second array (1-%d): ", MAX_SIZE);
    scanf("%d", &size2);

  
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    mergeSize = size1 + size2;
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    printf("merged array");
    for (int i = 0; i < mergeSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
*/
//*************************************************************************
//q16)
/*
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], reverse[MAX_SIZE];
    int size;

    printf("Enter size of the array (1-%d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter elements in the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        reverse[i] = arr[size - i - 1];
    }

    printf("Reverse of the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", reverse[i]);
    }
    printf("\n");

    return 0;
}
*/
//*************************************************************************
//q19)
/*
#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int arr[], int size);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size, choice;

    printf("Enter size of the array (1-%d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter elements in the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 to sort in ascending order, 2 to sort in descending order: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortAscending(arr, size);
    } else if (choice == 2) {
        sortDescending(arr, size);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
*/


