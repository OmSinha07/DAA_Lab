#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int binarySearch(int ar[],int low,int high,int ele);
    int selectionSort(int ar[], int n);
    void printArray(int arr[], int size) ;
    FILE *file;
    int ar[10];
    int i;

  
    file = fopen("numbers_f.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        if (fscanf(file, "%d", &ar[i]) != 1) {
            printf("Error: Could not read number %d\n", i + 1);
            fclose(file);
            return 1;
        }
    }

    
    fclose(file);

    printf("The numbers read from the file are:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
    int ele;
    selectionSort(ar,10);
    printf("Array after sorting");
    printArray(ar,10);
    printf("Enter element to be searched ");
    scanf("%d",&ele);
    int low=0;
    int high=sizeof(ar) / sizeof(ar[0]);
    int ele1=binarySearch(ar,low,high,ele);
    printf("element found at index %d",ele1);
    printf("\n");
    return 0;
}

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

      
        if (arr[mid] == target) {
            return mid;
        }

        
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        
        return binarySearch(arr, mid + 1, right, target);
    }

   
    return -1;
}

int selectionSort(int ar[], int n) {
    int i, j, minIndex, temp;

    
    for (i = 0; i < n-1; i++) {
        
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (ar[j] < ar[minIndex]) {
                minIndex = j;
            }
        }

        
        if(minIndex != i) {
            temp = ar[minIndex];
            ar[minIndex] = ar[i];
            ar[i] = temp;
        }
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



