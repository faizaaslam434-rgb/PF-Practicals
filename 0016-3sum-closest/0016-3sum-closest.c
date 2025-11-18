#include <stdlib.h> // Required for qsort and abs
#include <limits.h> // Required for INT_MAX

// Comparison function required by qsort for ascending order sort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Given an integer array nums of length n and an integer target, 
 * find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 */
int threeSumClosest(int* nums, int numsSize, int target) {
    // 1. Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initialize the closest sum found so far with the sum of the first three elements
    int closest_sum = nums[0] + nums[1] + nums[2];

    // Iterate through the array, fixing the first element (nums[i])
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];

            // Check if the current sum is closer to the target than our current closest_sum
            if (abs(current_sum - target) < abs(closest_sum - target)) {
                closest_sum = current_sum;
            }

            if (current_sum < target) {
                left++; // Sum is too small, move left pointer right to increase sum
            } else if (current_sum > target) {
                right--; // Sum is too large, move right pointer left to decrease sum
            } else {
                // If sum is exactly equal to target, we found the solution.
                // The problem guarantees exactly one solution, so we can return immediately.
                return current_sum;
            }
        }
    }

    return closest_sum;
}
