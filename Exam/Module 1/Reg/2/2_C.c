#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* indices = (int*) malloc(*returnSize * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main(){
    int numsSize = 5;
    int* nums = (int*) malloc(numsSize * sizeof(int));
    int target = 0;
    int returnSize = 0;

    printf("Enter 5 numbers: ");
    for(int i = 0; i < numsSize; i++){
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int* indices = twoSum(nums, numsSize, target, &returnSize);

    if(returnSize == 2){
        printf("%d %d\n", indices[0], indices[1]);
    } else {
        printf("No Two Numbers Add to the Target\n");
    }

    free(nums);
    free(indices);

    return 0;
}