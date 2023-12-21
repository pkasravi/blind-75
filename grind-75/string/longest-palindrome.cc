/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/longest-palindrome/
 * 
 * Solution Description:
 * Iterate through the input string and build a hashmap of character counts.
 * Then iterate through the items of the hashmap. For every entry that has an
 * even count add the entire count, otherwise add count % 2. When an odd count
 * is encountered we remember that so in our final length we can add 1 for that
 * single character in the middle of the palindrome.
 *
 * Steps:
 * 1 - Build character count hashmap
 * 2 - Iterate through items of hashmap
 * a - If count % 2 == 0 increment our counter by count
 * b - Else increment our counter by count - 1
 * c - If an odd count is encountered set a boolean
 * 3 - Finally return count, if our boolean is true add 1 to our final count
 *
 * Complexity Analysis:
 * TIME: O(n) becuase we iterate through the string to build our hashmap and
 * then iterate through our map one more time which in the worst case of all
 * unique characters would give us 2n which reduces to O(n)
 * SPACE: O(n) for our hashmap where in the worst case all characters are unique
 *
 * NOTE: Technically these could both be reduces to O(1) since there is an upper
 * bound of 128 on the possible letters therefore O(128) reduces to O(1).
 *
 * -----------------------------------------------------------------------------
 */

int longestPalindrome(string s) {
	if (s.length() < 2) {
    return s.empty() ? 0 : 1;
  }
  std::unordered_map<char, int> char_counts;
  std::for_each(s.begin(), s.end(), [&] (const char ch) { ++char_counts[ch]; });
  int length{0};
  bool odd_char_count{false};
  for (const auto& [_, count] : char_counts) {
    if (count % 2 == 0) {
      length += count;
    } else {
      odd_char_count = true;
      length += count - 1;
    }
  }
  return odd_char_count ? length + 1 : length;
}

