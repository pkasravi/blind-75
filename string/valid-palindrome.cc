/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/valid-palindrome/
 * 
 * Solution Description:
 * We will be iterating from both ends of the string towards the middle. For
 * each alphanumeric character we perform a comparison and if they are equal we
 * continue iterating, otherwise we quit and return false.
 *
 * Steps:
 * 1 - Create two index pointers for opposite ends of s
 * 2 - Write a simple helper function, when given two chars, converts them to
 * lowercase and performs a comparison
 * 3 - Have a while loop iterate until our left and right pointers point to the
 * same index
 * 4 - Have two nested while loops, one for each pointer, that move the pointer
 * while the value being pointed to is NOT alphanumeric
 * 5 - Once BOTH chars are alphanumeric; if numeric perform a comparison, if
 * alpha call our helper function
 * 6 - If a comparison fails we return False, if our while loop breaks with no
 * failures return True
 *
 * Complexity Analysis:
 * Time: O(n) because we must iterate through the entire input string
 * Space: O(1) because we only ever create the two pointers regardless of input
 * size.
 *
 * -----------------------------------------------------------------------------
 */

bool areEqual(char a, char b) {
	if (std::isalpha(a)) {
		a = std::lower(a);
	}
	if (std::isalpha(b)) {
		b = std::lower(b);
	}
	return a == b;
}

bool isPalindrome(const std::string& s) {
	if (s.length() <= 1) {
		return true;
	}
	int left{0};
	int right{static_cast<int>(s.length()) - 1};
	bool result{true};

	while (left < right) {
		while (left < right && !std::isalnum(s[left])) {
			++left;
		}
		while (left < right && !std::isalnum(s[right])) {
			--right;
		}
		if (!areEqual(s[left], s[right])) {
			result = false;
			break;
		}
		++left;
		--right;
	}
	return result;
}

