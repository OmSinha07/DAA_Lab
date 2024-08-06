#include<stdio.h>
#include<stdlib.h>
#include<time.h>



bubble_sort(int arr[],int n){
        for (int i = n-1; i >= 1; i--) {
           int didSwap =0;
            for (int j = 0; j <= i-1; j++) {
                if (arr[j]>arr[j+1]) {
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                    didSwap = 1;
                }
            }
            if (didSwap==0) {
                break;
            }
            
        }
        
    }
    void selection_sort(int arr[],int n ){
    for(int i = 0;i<n-1;i++){
        int mini =i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
        
    }
}
int main(int argc, char const *argv[])
{
    srand(time(0));
    int n = 20000;

    int *arr = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
        
    }
    clock_t t1,t2;
    double t,t_1;
    t1 = clock();


    bubble_sort(arr,n);
    t2 = clock();
    t = (double)(t2-t1)/CLOCKS_PER_SEC;

   
    printf("The time complexity of bubble sort will be %lf", t);
    selection_sort(arr,n);
    t2 = clock();
    t_1 = (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("\n");
    printf("The time complexity of selection sort will be %lf", t_1);

    free(arr);
    return 0;
}