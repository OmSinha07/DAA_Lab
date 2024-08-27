#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void readFileAndSort(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (inFile == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    int arr[500];
    int n = 0;

    while (fscanf(inFile, "%d", &arr[n]) != EOF && n < 500) {
        n++;
    }

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1e9;

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++) {
        fprintf(outFile, "%d ", arr[i]);
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %lf nanoseconds\n", time_spent);

    fclose(inFile);
    fclose(outFile);
}

int main() {
    int option;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &option);

        comparisons = 0;

        switch (option) {
            case 1:
                readFileAndSort("inAsce.txt", "outMergeAsce.txt");
                break;
            case 2:
                readFileAndSort("inDesc.txt", "outMergeDesc.txt");
                break;
            case 3:
                readFileAndSort("inRand.txt", "outMergeRand.txt");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}