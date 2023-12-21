/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/ransom-note/
 * 
 * Solution Description:
 * Iterate through magazine to build a hashmap of character counts. Subsequently
 * iterate through ransomNote and deduct one from each count in the hashmap. If
 * a character has a zero count or doesn't exist in the map return False.
 *
 * Steps:
 * 1 - Iterate through magazine by each char to build hashmap of char counts
 * 2 - Iterate through ransomNote
 * a - Look up chars for ransomNote in the hashmap
 * b - Each time a char is found, subtract 1 from its count
 * c - If a char is not found or its count is already zero return False
 * 3 - If we successfully reach the end of ransomNote return True
 *
 * Complexity Analysis:
 * TIME: O(m+n) where m and n are the lengths of the two strings
 * NOTE: Technically it would be O(m^2 + n) because the worst case insertion time
 * is O(m) and we do that m times for O(m^2) where m is the length of magazine.
 *
 * SPACE: O(m) where m is the length of magazine because in the worst case it is
 * all unique characters
 *
 * -----------------------------------------------------------------------------
 */

bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
	std::unordered_map<char, int> char_counts;
	std::for_each(magazine.begin(), magazine.end(), [&](const char ch) { ++char_counts[ch]; });
	bool result{true};
	for (const char ch : ransomNote) {
		if (char_counts.find(ch) == char_counts.end() || char_counts[ch] == 0) {
			result = false;
			break;
		}
		--char_counts[ch];
	}
	return result;
}


