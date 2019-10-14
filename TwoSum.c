// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_ARRAY_SIZE 32

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                return res;
            }   
        }
    }
    return NULL;
}

void print_res(int *res)
{
    printf("%d, %d\n", res[0],res[1]);
    
}

int main(int argc, char const *argv[])
{
    int array[MAX_ARRAY_SIZE];
    int length = 0;
    int target;

    // prepare the input
    printf("input the aray\n");
    // while (scanf("%d", &array[length]) != EOF)
    // {
    //     length += 1;
    // }
    char c = ' ';
    while (c != '\n')
    {
        scanf("%d", &array[length]);
        c = getchar();
        length += 1;
    }
    
    printf("the length is %d\n", length);

    printf("input the target\n");
    scanf("%d", &target);
    
    // start calculate
    int *returnsize;
    int *res = twoSum(array,length, target, returnsize);
    if (res) print_res(res);
    return 0;
}