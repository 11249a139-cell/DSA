/*
Aim:
To solve the Tower of Hanoi problem using recursion and display
the sequence of moves required to transfer all disks from source
to destination.
*/

#include <stdio.h>

// Recursive function for Tower of Hanoi
void solveTOH(int disks, char source, char auxiliary, char destination)
{
    // Base case: only one disk
    if (disks == 1)
    {
        printf("Move Disk 1 from %c --> %c\n", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    solveTOH(disks - 1, source, destination, auxiliary);

    // Step 2: Move the largest disk to destination
    printf("Move Disk %d from %c --> %c\n", disks, source, destination);

    // Step 3: Move n-1 disks from auxiliary to destination
    solveTOH(disks - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0)
    {
        printf("Error: Number of disks must be a positive integer.\n");
        return 1;
    }

    printf("\nTower of Hanoi Solution\n");
    printf("Source: S | Auxiliary: A | Destination: D\n");
    printf("----------------------------------------\n");

    solveTOH(n, 'S', 'A', 'D');

    printf("\nAll disks have been successfully moved to destination.\n");

    return 0;
}
