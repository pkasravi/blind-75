#include <vector>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/binary-search/
 * 
 * Solution Description:
 * We will use the two pointer method with each at opposite ends of the input
 * array. Since the array is sorted we can look at the value in the middle of
 * the two pointers and if it is less than or greater than the target we move
 * our search to the partition on the left or right, respectively, of the middle
 * value.
 *
 * Steps:
 * 1 - Create a left and right pointer initialized to 0 and the len of the array
 * 2 - Loop until left and right are equal, i.e. left <= right
 * 3 - On each iteration calculate our middle index and look at that value
 * 4 - If the middle value is less than target, we set left to middle + 1
 * a - If middle value is greater than target, we set right to middle - 1
 * b - If middle is equal to target we simply return the index
 * 5 - If we exit our loop without finding target we return -1
 *
 * Complexity Analysis:
 * Time: O(logn) because we are continuously halving our array and decreasing
 * the search space thus giving us logn time
 * Space: O(1) because we only ever create two variables regardless of input
 * size
 *
 * -----------------------------------------------------------------------------
 */

int search(const vector<int>& nums, const int target) {
	int left{0};
	int right{static_cast<int>(nums.size()) - 1};
	int result{-1};

	while (left <= right) {
		const int middle{left + (right - left) / 2};
		if (nums[middle] == target) {
			result = middle;
			break;
		} else if (nums[middle] < target) {
			left = middle + 1;
		} else { // nums[middle] > target
			right = middle - 1;
		}
	}
	return result;
}

