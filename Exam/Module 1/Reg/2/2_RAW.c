#include <stdio.h>
#include <stdlib.h>

___ twoSum(int* nums, int numsSize, int target, int* returnSize,int* isSuccess) {
    int* result = ___(___ * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = ___; j < ___; j++) {
            if (___ == target) {
                result[0] = i;
                result[1] = j;
                *isSuccess = 1;
                return result;
            }
        }
    }
    *isSuccess = 0;
    return result;
}

int main() {
    int nums[10] = {1,2,3,4,5};
    int target = 0;
    printf("Enter the target: ");
    scanf("%d", &target);
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize, isSuccess;
    int* result = twoSum(___);
    int i;
    if (isSuccess == ___) {
        printf("Indices: ");
        for (i = 0; i < returnSize; i++) {
            printf("%d ", ___);
        }
    } else {
        printf("No two numbers add up to the target");
    }
    return 0;
}
