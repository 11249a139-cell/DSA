/*
Aim:
To generate the Fibonacci series up to 'n' terms and display
the nth Fibonacci number.
*/

#include <stdio.h>

int main()
{
    int n;
    int first = 0, second = 1, next;

    printf("Enter number of terms: ");

    // Input validation
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Error: Please enter a valid positive integer.\n");
        return 0;
    }

    printf("\nFibonacci series up to %d terms:\n", n);

    // Print first term
    if (n >= 1)
        printf("%d ", first);

    // Print second term
    if (n >= 2)
        printf("%d ", second);

    // Generate remaining terms
    for (int i = 3; i <= n; i++)
    {
        next = first + second;
        printf("%d ", next);

        // Update values
        first = second;
        second = next;
    }

    // Display nth term
    if (n == 1)
        printf("\n\nThe %dth Fibonacci number is: %d\n", n, first);
    else
        printf("\n\nThe %dth Fibonacci number is: %d\n", n, second);

    return 0;
}
