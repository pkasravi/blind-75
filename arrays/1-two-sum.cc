#include <pair>
#include <unordered_map>
#include <vector>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Solution Description:
 *
 * As we iterate through the array we store seen values in an unordered_map
 * along with the value's index. On each new value we check to see if it's
 * complement exists in the map. If yes we have our indices, otherwise we
 * continue. Since the problem is guaranteed to have a solution we know that by
 * the time we reach the end of the array we will find our answer.
 *
 * Steps:
 * 1 - Iterate through nums storing the values as keys in an unordered_map and
 *     the corresponding indices as the values
 * 2 - On each iteration check if target - current_value exists in the map, if
 *     yes, then grab the two indices, break the loop and return. Otherwise
 *     store the value index pair and continue
 *
 * Complexity Analysis:
 *   Time: Average O(n) Worst O(n^2)
 *   Since both the access and insertion of unordered_map entries is constant on
 *   Average and linear in the worst case, if our match is at the end of the
 *   array we perform n accesses therefore the n^2 runtime.
 *
 *   Space: Worst O(n)
 *   In the worst case we store n-1 elements which reduces to O(n).
 *
 * -----------------------------------------------------------------------------
 */

std::vector<int> two_sum(const vector<int>& nums, const int target) {
	std::unordered_map<int, int> val_to_idx{};
	std::pair<int, int> result;

	for (size_t i = 0; i < nums.size(); ++i) {
		const int current_value{nums[i]};
		const int complement{target - current_value};
		if (val_to_idx.find(current_value) != val_to_idx.end()) {
			result = {val_to_idx.at(current_value), i};
			break;
		}
		val_to_idx[current_value] = i;
	}
	return {result.first, result.second};
}

