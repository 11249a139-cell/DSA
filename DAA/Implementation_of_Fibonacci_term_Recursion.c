/*
Aim:
To find the nth Fibonacci number using recursion.
*/

#include <stdio.h>

// Recursive function to compute Fibonacci
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    printf("Enter the position (n): ");
    scanf("%d", &n);

    // Input validation
    if (n < 0)
    {
        printf("Error: Please enter a non-negative integer.\n");
        return 1;
    }

    int result = fibonacci(n);

    printf("\nThe Fibonacci number at position %d is: %d\n", n, result);

    return 0;
}
