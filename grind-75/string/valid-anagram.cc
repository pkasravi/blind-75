#include <string>
#include <unordered_map>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/valid-anagram/description/
 * 
 * Solution Description:
 * We will use two hashmaps to map character to count. Then compare the two maps
 * for equivalence.
 *
 * Steps:
 * 1 - Convert each string to a map of <string, int>
 * 2 - Iterate through one of the maps comparing the value to the corresponding
 * value in the second map.
 * 3 - If a key doesn't exist or the values are not equal we return False,
 * otherwise return True
 *
 * Complexity Analysis:
 * Time: O(n) where n is the number of characters in s or t, assuming they are
 * of equal lengths.
 * Space: O(n) because in the worst case we have no repeated characters which
 * constitutes O(2n) which reduces to O(n)
 *
 * -----------------------------------------------------------------------------
 */

std::unordered_map<char, int> GetCharCounts(const std::string& a) {
	std::unordered_map<char, int> result;
	std::for_each(s.begin(), s.end(), [&] (const char& ch) { ++result[ch]; });
	return result;
}

bool isAnagram(const std::string& s, const std::string& t) {
	if (s.size() != t.size()) {
		return false;
	}

	const auto s_counts{GetCharCounts(s)};
	const auto t_counts{GetCharCounts(t)};

	bool result{true};
	for (const auto& [ch, count] : s_counts) {
		if (t_counts.find(ch) == t_counts.end() || t_counts.at(ch) != count) {
			result = false;
			break;
		}
	}
	return result;
}
