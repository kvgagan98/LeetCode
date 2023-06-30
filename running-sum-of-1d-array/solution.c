/* Problem 1480 - Running Sum of 1D Array */

#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize);
int main (void)
{
    int nums[] = {1,2,3,4,5,6,7};
    int *returnArr;
    int returnSize;
    int numsSize = sizeof(nums)/sizeof(int);
    int i = 0;

    returnArr = runningSum(nums, numsSize, &returnSize);

    for (i = 0; i < numsSize; i++)
    {
        printf("%d ", *(returnArr + i));
    }

    free(returnArr);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * Constraints:
 *      1 <= sizeof(nums) <= 1000
 *      -10^6 <= nums[i] <= 10^6
 */
int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int *returnArr = (int *) malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int i = 0;

    //First element is itself
    *returnArr = *nums;
    for (i = 1; i < numsSize; i++)
    {
        *(returnArr + i) = *(nums + i) + *(returnArr + (i - 1));
    }

    return returnArr;
}