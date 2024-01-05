/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/maximum-subarray/description/
 * 
 * Solution Description:
 * We will use a sliding window approach that we can grow and shrink. Since we
 * only care about the sum of the elements in the window, we will only keep
 * track of the running sum and our maximum sum which will be the final answer.
 * The window will start with only the first element and continue to grow
 * (i.e. add elements to the right one by one). When a value is encountered
 * which is greater by itself than with the rest of the window, we reset the
 * window to start at that element (i.e. reset the running sum to that value).
 *
 * Steps:
 * 1 - 
 *
 * Complexity Analysis:
 * Time: O(n) because we iterate through array once
 * Space: O(1) because we only allocate space for our two pointers
 *
 * -----------------------------------------------------------------------------
 */

int maxSubArray(const std::vector<int>& nums) {
	int running_sum{0};
  int result{std::numeric_limits<int>::min()};

  for (const int val : nums) {
    running_sum = std::max(running_sum + val, val);
    result = std::max(result, running_sum);
  }
  return result;
}

