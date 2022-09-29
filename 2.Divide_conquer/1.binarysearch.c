#include <stdio.h>
int binarysearch(int barr[], int l, int r, int x)
{
    if (l <= r)
    {
        int m = l + (r - l) / 2;

        if (barr[m] == x)
            return m;

        if (barr[m] > x)
            return binarysearch(barr, 1, m - 1, x);

        else
            return binarysearch(barr, m + 1, r, x);
    }
    return -1;
}

int main(void)
{
    int barr[] = {21, 33, 55, 88, 91, 100};
    int n = sizeof(barr) / sizeof(barr[0]);
    int x = 88;
    int result = binarysearch(barr, 0, n - 1, x);

    if (result == -1)
        printf("\nNot present in array\n");
    else
        printf("\n\nPresent at index %d\n\n", result);

    return 0;
}
