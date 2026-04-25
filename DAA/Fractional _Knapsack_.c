/*
Aim:
To implement the Fractional Knapsack problem using a greedy approach
to maximize profit based on value-to-weight ratio.
*/

#include <stdio.h>

// Structure to store item details
struct Product
{
    int weight;
    int value;
    float ratio; // value per unit weight
};

// Function to sort items based on ratio (descending order)
void sortByRatio(struct Product arr[], int n)
{
    struct Product temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    printf("Enter the total number of items: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Error: Number of items must be greater than zero.\n");
        return 1;
    }

    struct Product items[n];

    printf("\nEnter weight and value for each item:\n");

    // Input item details
    for (int i = 0; i < n; i++)
    {
        printf("Item %d -> Weight and Value: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Sort items based on ratio
    sortByRatio(items, n);

    float maxProfit = 0.0;

    printf("\nProcessing items based on highest value-to-weight ratio...\n");

    // Apply greedy selection
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            printf("Taking full item %d (Value = %d, Weight = %d)\n",
                   i + 1, items[i].value, items[i].weight);

            maxProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            printf("Taking fractional part of item %d\n", i + 1);

            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("\nMaximum obtainable profit = %.2f\n", maxProfit);

    return 0;
}
