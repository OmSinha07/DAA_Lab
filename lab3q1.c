#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int size, int target, int* loop_count) {
    int left = 0, right = size - 1;
    *loop_count = 0;

    while (left <= right) {
        (*loop_count)++;
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void binary_search_test() {
    int size = 1000000;
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    int target = arr[50000];  // target is the middle element
    int loop_count;
    clock_t start, end;
    double exec_time;

    start = clock();
    int index = binary_search(arr, size, target, &loop_count);
    end = clock();
    exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("target element: %d\n", target);
    printf("Number of loops: %d\n", loop_count);
    printf("Execution time: %f seconds\n", exec_time);

    free(arr);
}

int main() {
    binary_search_test();
    return 0;
}