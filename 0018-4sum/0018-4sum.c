#include <stdio.h>
#include <stdlib.h> // Required for malloc, free, and qsort

// Comparison function for qsort (sorts in ascending order)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as a reference parameter in *returnColumnSizes array.
 * Note: Both returned arrays must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // 1. Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize return structures for LeetCode environment
    *returnSize = 0;
    // We will dynamically resize the result array later.
    int capacity = 10;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // Handle edge case where array is too small
    if (numsSize < 4) {
        return result;
    }

    // Use two nested loops to fix the first two elements
    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            // Skip duplicates for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // Use the two-pointer approach for the remaining two elements
            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                // Use long long to avoid potential integer overflow during sum calculation
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    // Found a quadruplet! Add it to the result list

                    // Resize result array if capacity is reached
                    if (*returnSize == capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    // Allocate memory for the new quadruplet
                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Skip duplicates for the third and fourth elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move pointers inward to find the next unique pair
                    left++;
                    right--;
                } else if (sum < target) {
                    left++; // Sum is too small, increase the sum
                } else {
                    right--; // Sum is too large, decrease the sum
                }
            }
        }
    }

    return result;
}