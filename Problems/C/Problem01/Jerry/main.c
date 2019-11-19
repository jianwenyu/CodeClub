#include <stdio.h>
#include <stdlib.h>

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, char **argv){
    int a[] = {2,7,11,15};
    int *returnSize =NULL;
    returnSize = twoSum(a,4, 9,returnSize);
    printf("%d %d\n",returnSize[0],returnSize[1]);
    free(returnSize);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    int j = 0;
    returnSize = (int*)malloc(sizeof(int)*2);
    for(i = 0; i<numsSize; i++){
        if(nums[i]>target){
            continue;
        }else if(nums[i]==target){
            for(j=0;j<numsSize;j++){
                if(nums[j]==0){
                    returnSize[0]=i;
                    returnSize[1]=j;
                    return returnSize;
                }
            }
        }else{
            for(j=0;j<numsSize;j++){
                if(nums[j]==(target-nums[i])){
                    returnSize[0]=i;
                    returnSize[1]=j;
                    return returnSize;
                }
            }
        }
    }
    returnSize[0]=0;
    returnSize[1]=0;
    return returnSize;
}
