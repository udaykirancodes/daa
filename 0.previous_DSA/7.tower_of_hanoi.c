// C program for Tower of Hanoi using Recursion
#include <stdio.h>

void towers(int no_of_disks, char fromtower, char totower, char auxtower);

int main()
{
    int no_of_disks;

    printf("Enter the number of disks : ");
    scanf("%d", &no_of_disks);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(no_of_disks, 'S', 'D', 'X');
    return 0;
}
void towers(int no_of_disks, char fromtower, char totower, char auxtower)
{
    if (no_of_disks == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", fromtower, totower);
        return;
    }
    towers(no_of_disks - 1, fromtower, auxtower, totower);
    printf("\n Move disk %d from tower %c to tower %c", no_of_disks, fromtower, totower);
    towers(no_of_disks - 1, auxtower, totower, fromtower);
}