#include <stack>
#include <unordered_map>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/valid-parentheses/
 * 
 * Solution Description:
 *   We will use two data structures, a stack and a hashmap for this problem.
 *   The stack will be used to keep track of the opening parentheses for our
 *   string. As we iterate through the string if a char is an opener we push it
 *   onto the stack, if it's a closer we pop from the stack and use the hashmap
 *   to look up the correct opener and check if it matches with what we popped.
 *   If a mismatch is encountered we break and return False. If we get to the
 *   end of our string and our stack is empty we return True, if there are still
 *   items in our stack we return False.
 *
 * Steps:
 *   1 - Create a hashmap that will store our lookup table of opener to closer
 *   2 - Iterate through the string char by char
 *   3 - If a char is an opener (in the keys of our map) then we push it onto
 *   our stack
 *   4 - If a char is a closer, we pop from the stack and use the popped value
 *   to look up its corresponding closer.
 *   5 - If the looked up value does not match with the current char from the
 *   string then we break and return False, if it matches we simply continue
 *   6 - Once the end of the string has been reached we check if our stack is
 *   empty, if yes we can return True, if no then we return False
 *
 * Complexity Analysis:
 *   Time: O(n) because we iterate linearly through the input string
 *
 *   Space: O(n) because in the worst case our entire string is openers and we
 *   end up storing them all in the stack.
 *
 * -----------------------------------------------------------------------------
 */

// Ideally this would be static constexpr but that doesn't work with
// unordered_map and I can't remember what I did in the past to get it to work
const std::unordered_map<char, char> kCloserLookup{
	{'(', ')'}, {'['. ']'}, {'{', '}'}};

bool is_opener(const char paren) {
	return kCloserLookup.find(paren) != kCloserLookup.end();
}

bool is_valid(const std::string& s) {
	if (s.length() == 0) {
		return true;
	}

	bool result{true};
	std::stack seen_openers{};
  for (const char paren : s) {
		if (is_opener(paren)) {
			seen_openers.push(paren);
		} else {
			if (seen_openers.empty() || kCloserLookup[seen_openers.top()] != paren) {
				result = false;
				break;
			}
			seen_openers.pop();
		}
	}
	return seen_openers.empty() ? result : false;
}

