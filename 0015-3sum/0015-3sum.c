#include <stdlib.h>
#include <stdio.h>

// Comparison function required by qsort for ascending order sort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as a reference parameter in *returnColumnSizes array.
 * Note: Both returned arrays must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the input array. This allows us to easily skip duplicates and use two pointers.
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize return structures for LeetCode environment
    *returnSize = 0;
    int capacity = 10; // Initial capacity, will realloc as needed
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // Handle edge case where array is too small
    if (numsSize < 3) {
        return result;
    }

    // Iterate through the array, fixing the first element (nums[i])
    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicates for the first element. Ensures unique triplets.
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Use two-pointer approach for the remaining two elements
        int left = i + 1;
        int right = numsSize - 1;
        int target_sum = 0 - nums[i]; // Target for the remaining two numbers

        while (left < right) {
            int current_sum = nums[left] + nums[right];

            if (current_sum == target_sum) {
                // Found a triplet that sums to zero!
                
                // Resize result array if capacity is reached
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Allocate memory for the new triplet and store values
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Skip duplicates for the second and third elements
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move pointers inward to find the next unique pair
                left++;
                right--;
            } else if (current_sum < target_sum) {
                left++; // Sum is too small, increase the left pointer
            } else {
                right--; // Sum is too large, decrease the right pointer
            }
        }
    }

    return result;
}
