/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/climbing-stairs/
 * 
 * Solution Description:
 * Basically we can solve this solution using a dp array to store previous
 * answers, and we will see that since the final answer only depends on the
 * previous two answers we can optimize it further to do away with the array and
 * simply use two variables. Walking through some examples gives us the
 * recurrence relation shown below:
 *
 * n = 1: 1 b/c there is only one option
 * n = 2: 2 (1 + 1), (2)
 * n = 3: 3 (1 + 1 + 1), (1 + 2), (2 + 1)
 * n = 4: 5 (1 + 1 + 1 + 1), (1 + 2 + 1), (2 + 1 + 1), (2 + 2), (1 + 1 + 2)
 *
 * Here we can see that as n increases we simply take the options from n - 1 and
 * can add 1 to each to get n, and we can also take the options from n - 2 and
 * add 2 to each to get n. Therefore our recurrence relation is as follows:
 *
 * T[n] = T[n - 1] + T[n - 2]
 * With the base cases
 * T[0] = 0
 * T[1] = 1
 * 
 * NOTE: We are using a 0-indexed array which means if we use an array our final
 * answer will be in T[n + 1]
 *
 * Steps:
 * 1 - Create two variables prev and prev_prev, these are our base cases
 * a - Initialize prev_prev to 0 (this is T[0]) and prev to 1 (this is T[1])
 * 2 - Iterate from 1 to n + 1
 * 3 - As we iterate set store prev in a temporary variable and set prev to
 *     prev + prev_prev
 * 4 - Set prev_prev to the value we stored in our temporary variable
 * 5 - Finally return prev as our final answer
 *
 * Complexity Analysis:
 * Time: O(n) since we iterate to n + 1 which reduces to O(n)
 * Space: O(1) because we only create two variables regardless of the input size
 *
 * -----------------------------------------------------------------------------
 */

int climbStairs(int n) {
	int prev_prev{0};
	int prev{1};
	for (int _ = 0; _ < n; ++_) {
		const int curr{prev + prev_prev};
		prev_prev = prev;
		prev = curr;
	}
	return prev;
}

