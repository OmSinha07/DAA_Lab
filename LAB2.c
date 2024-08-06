#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void findSecondSmallestAndLargest(int arr[],int n,int *secondSmallest,int *secondLargest){
    int firstSmallest = INT_MAX;
    int firstLargest = INT_MIN;

    *secondSmallest = INT_MAX;
    *secondLargest = INT_MIN;

    for(int i =0;i<n;i++){
        if(arr[i]<firstSmallest){
            *secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        }
        else if(arr[i]< *secondSmallest && arr[i]!=firstSmallest){
            *secondSmallest = arr[i];
        }

        if(arr[i]>firstLargest){
            *secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if(arr[i]> *secondLargest && arr[i]!= firstLargest ){
            *secondLargest = arr[i];
        }
    }
}
int main(int argc, char const *argv[])
{
    FILE *file;
    char fileName[] = "numbers_f.txt";
    int *arr;
    int n=0,size = 1000;

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", fileName);
        free(arr);
        return 1;
    }

    while (fscanf(file, "%d", &arr[n]) != EOF) {
        n++;
        if (n >= size) {
            size *= 2;
            arr = (int *)realloc(arr, size * sizeof(int));
            if (arr == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    if (n < 2) {
        printf("Array must have at least two elements\n");
        free(arr);
        return 1;
    }

    int secondSmallest, secondLargest;
    findSecondSmallestAndLargest(arr, n, &secondSmallest, &secondLargest);

    if (secondSmallest == INT_MAX) {
        printf("No second smallest element found\n");
    } else {
        printf("Second smallest element is: %d\n", secondSmallest);
    }

    if (secondLargest == INT_MIN) {
        printf("No second largest element found\n");
    } else {
        printf("Second largest element is: %d\n", secondLargest);
    }
    free(arr);
    return 0;
}