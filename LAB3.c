#include <stdio.h>

int main()
{
    FILE *file;
    int n, i, j;
    int countDuplicates = 0;
    int maxCount = 0;
    int mostRepeatingElement;
    int numArray[100];      
    int frequency[100] = {0};
    file = fopen("numbers_f.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(file, "%d", &numArray[i]);
    }
    fclose(file);
    printf("The content of the array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numArray[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (numArray[i] == numArray[j])
            {
                frequency[i]++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (frequency[i] > 0)
        {
            countDuplicates++;
        }
        if (frequency[i] > maxCount)
        {
            maxCount = frequency[i];
            mostRepeatingElement = numArray[i];
        }
    }
    printf("Total number of duplicate values = %d\n", countDuplicates);
    printf("The most repeating element in the array = %d\n", mostRepeatingElement);
    return 0;
}