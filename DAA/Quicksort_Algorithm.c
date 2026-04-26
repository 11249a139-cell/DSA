/*
Aim:
To implement Randomized Quick Sort by selecting a random pivot
to improve average-case performance during sorting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* swap two integers */
void swapValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* partition using last element as pivot */
int partitionArray(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swapValues(&arr[i], &arr[j]);
        }
    }

    swapValues(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* randomized quick sort */
void quickSortRandom(int arr[], int low, int high)
{
    if (low < high)
    {
        int randomIndex = low + rand() % (high - low + 1);

        // move random pivot to end
        swapValues(&arr[randomIndex], &arr[high]);

        int pivotPos = partitionArray(arr, low, high);

        quickSortRandom(arr, low, pivotPos - 1);
        quickSortRandom(arr, pivotPos + 1, high);
    }
}

int main()
{
    int n;

    srand(time(NULL));  // initialize random seed

    printf("Randomized Quick Sort Execution\n");
    printf("--------------------------------\n");

    printf("Enter total number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    quickSortRandom(arr, 0, n - 1);

    printf("\nSorted Output:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nSorting completed successfully.\n");

    return 0;
}
