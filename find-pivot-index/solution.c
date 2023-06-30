/* Problem 724 - Find Pivot Index */

#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize);
int main (void)
{
    int nums[] = {1,7,3,6,5,6};
    int numsSize = sizeof(nums)/sizeof(int);
    int pivIndex = 0;

    pivIndex = pivotIndex(nums, numsSize);
    printf("Pivot Index: %d", pivIndex);

    return 0;
}

/* Pivot Index = Index when left sum = right sum */
int pivotIndex(int* nums, int numsSize)
{
    int pivIndex = -1;
    int leftSum = 0;
    int rightSum = 0;
    int i = 0;

    for (i = 1; i < numsSize; i++)
    {
        rightSum += *(nums + i);
    }
    for (i = 0; i < numsSize; i++)
    {
        if (i == 0)
        {
            leftSum = 0;
        }
        else
        {
            /* Subtract rightSum by previous val and add leftSum by previous Val */
            rightSum -= *(nums + i);
            leftSum += *(nums + (i - 1));
        }

        if (leftSum == rightSum)
        {
            pivIndex = i;
            return pivIndex;
        }
    }

    return pivIndex;
}