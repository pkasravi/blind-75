/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/add-binary/description/
 * 
 * Solution Description:
 * We will iterate from back to front of the two strings. We will also have a
 * boolean variable representing carry. We will use ASCII character addition
 * to avoid doing conversions on every iteration. When we reach the end of the
 * shorter of the two strings we can use the same logic to add the carry to the
 * remaining characters in the longer string as needed. Finally we reverse our
 * string for our resulting answer.
 *
 * Steps:
 * 1 - Create a carry variable (can use bool or int)
 * 2 - Loop until both strings have been traversed and carry is 0
 * 3 - On each iteration:
 * a - If the character of each respective string is valid, add it to carry.
 *     Keep in mind we are adding chars
 * b - Add carry % 2 to our answer. If we added two 1's this will be 0
 * c - Divide carry by 2. If we added two 1's carry will be 2 and after dividing
 *     will be 1, successfully giving us our carry value
 * 4 - When the loop completes, reverse the resulting string and return
 *
 * Complexity Analysis:
 * Time: O(max(m, n)) where m and n are the lengths of the two strings. Because
 * we must traverse all characters + 1 for our carry, this reduces to O(n)
 * Space: O(n) where n is the length of the longer string. Because in the worst
 * case our new string will be the length of the longer string + 1 for a carry
 *
 * -----------------------------------------------------------------------------
 */

std::string addBinary(const std::string& a, const std::string& b) {
	int carry{0};
	int m{static_cast<int>(a.length()) - 1};
	int n{static_cast<int>(b.length()) - 1};
	std::string result{""};

	while (m >= 0 || n >= 0 || carry > 0) {
		if (m >= 0) {
			carry += a[m--] - '0';
		}
		if (n >= 0) {
			carry += b[n--] - '0';
		}
		result += carry % 2 + '0';
		carry /= 2;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

