/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/first-bad-version/
 * 
 * Solution Description:
 * Simply run binary search on values 1 to n, calling isBadVersion on the
 * calculated middle value. When a bad version is found, store that version
 * and continue searching for an earlier bad version.
 *
 * Steps:
 * 1 - Initialize left and right pointers to 1 and n
 * 2 - Create a variable to store our previous bad version
 * 3 - In our binary search algorithm, if a version is bad we store it and 
 *     shift our search to the left of the bad version to find an earlier bad
 *     version
 * a - If the version is good we shift our search to the right of middle because
 *     there will never be a good version after a bad version so we must look at
 *     newer versions
 * 4 - When the loop exits (left > right) return the stored bad version
 *
 * Complexity Analysis:
 * Time: O(logn) since we are iteratively halving the search space, this gives
 * us a logn time complexity
 * Space: O(1) since we only create three variables regardless of input size
 *
 * -----------------------------------------------------------------------------
 */

int firstBadVersion(int n) {
  int left{1};
  int right{n};
  int result{-1};

  while (left <= right) {
    const int middle{left + (right - left) / 2};

    if (isBadVersion(middle)) {
      result = middle;
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return result;
}

