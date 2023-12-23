/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/majority-element/
 * 
 * Solution Description:
 * First we will calculate the number of times for the majority element given
 * the size of our array. Then we will simply iterate through the array counting
 * the occurence of values until we find our majority element. The problem
 * doesn't specify the most frequent majority element, so we can quite once A
 * majority element is found.
 *
 * ANOTHER approach is to avoid using the hashmap. Basically we create a pointer
 * to the first value in the array. As we iterate if the current value is equal
 * to our pointer's value, we increment a counter. If not, then we decrement the
 * counter. If/when the counter reaches 0 we reset our pointer to the current
 * value. The idea here is that when we reach the end of the array our pointer
 * will end up pointing to our majority value because due to the number of
 * occurences required for it to be a majority value and the fact that we know
 * one exists, it's impossible for there to be more occurences of a different
 * value, otherwise that other value would be the majority.
 * NOTE: This brings our space complexity down to O(1)
 *
 * Steps:
 * 1 - Calculate floor(n/2)
 * 2 - Create a hashmap for value counts
 * 3 - Iterate through the array counting values and storing counts in our map
 * 4 - Break loop and return majority element when the count is met
 *
 * Complexity Analysis:
 * Time: O(n) because in the worst case we must iterate the entire array
 * Space: O(n) because in the worst case we store 1 + n/2 in our hashmap which
 * reduces to O(n) runtime.
 *
 * NOTE: Since there is an upper bound on the values in the array, technically
 * we could say O(1) space.
 *
 * -----------------------------------------------------------------------------
 */

int majorityElementOpt(const vector<int>& nums) {
	int count{0};
	int candidate{};

	for (const int val : nums) {
		if (count == 0) {
			candidate = val;
		}
		count += val == candidate ? 1 : -1;
	}
	return candidate;
}

int majorityElement(const vector<int>& nums) {
	const int majority_count{static_cast<int>(nums.size()) / 2};
	std::unordered_map<int, int> val_to_count{};

	int result{-1};
	for (const int val : nums) {
		++val_to_count[val];
		if (val_to_count[val] > majority_count) {
			result = val;
			break;
		}
	}
	return result;
}



