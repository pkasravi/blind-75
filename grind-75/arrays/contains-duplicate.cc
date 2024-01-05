/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/contains-duplicate/
 * 
 * Solution Description:
 * There are a couple ways to solve this. We can iterate linearly and check to
 * see if a value exists in a set of seen values. Or we can simply construct a
 * set from the input array and compare its length to the length of the original
 * array. Either way our worst case complexities are the same.
 *
 * Steps:
 * 1 - Create a set
 * 2 - Iterate through input array
 * a - Check if value exists in set, if yes break loop and return true
 * b - If doesn't exist, insert it and continue
 *
 * Complexity Analysis:
 * Time: O(n*logn) because insertions are logn and in the worst case we perform
 * n of those
 * Space: O(n) for our set in the case where all values are unique
 *
 * NOTE: Even though using a set is more efficient on paper, it seems using an
 * unordered_set yields a faster runtime on leetcode.
 *
 * -----------------------------------------------------------------------------
 */

bool containsDuplicate(vector<int>& nums) {
  std::set<int> seen{};
  bool result{false};
  for (const int val : nums) {
    if (seen.find(val) != seen.end()) {
      result = true;
      break;
    }
    seen.insert(val);
  }
  return result;
}

bool containsDuplicate2(vector<int>& nums) {
	return std::set<int>{nums.begin(), nums.end()}.size() < nums.size();
}

