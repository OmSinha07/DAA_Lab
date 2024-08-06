#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void prefixsum(int arr[],int n)
{
    int sum=0;
    printf(arr[0]);
    sum=arr[0];
    for(int i =0;i<n;i++)
    {
        sum+=arr[i+1];
        printf("%d,",sum);
    }
        
    }

int main(int argc, char const *argv[])
{
    FILE *file;
    char fileName[] = "numbers_f.txt";
    int *arr;
    int n=0,size;
    printf("Enter size from file ");
    scanf("%d",&size);
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
    prefixsum( arr,size);
}
