/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/insert-interval/description/
 * 
 * Solution Description:
 * We will iterate through intervals linearly while the start of the new
 * interval is greater than end_i. Once this loop terminates we have found our
 * insertion point. Next we continue iterating, merging intervals by updating
 * new interval to be the min of the two starts and the max of the two ends.
 * This loop terminates when the end of this new interval is less than the start
 * of the subsequent interval, at that point we insert the new interval. Lastly
 * we insert any remaining intervals.
 *
 * Steps:
 * 1 - Create an output container
 * 2 - While newInterval[0] is greater than intervals[i][1] push intervals[i]
 *     into our output container
 * 3 - While newInterval[1] is less than or equal to intervals[i][1] set
 * 		 newInterval[0] to min of the two starts and newInterval[1] to the max of
 * 		 the two ends
 * 4 - When loop terminates push newInterval into our output container
 * 5 - Push remaining elements into our output container
 *
 * Complexity Analysis:
 * Time: O(n) becuase we iterate through entire input list
 * Space: O(1) if we don't count output container otherwise O(n)
 *
 * -----------------------------------------------------------------------------
 */

std::vector<std::vector<int>> insert(
		const std::vector<std::vector<int>>& intervals,
		std::vector<int>& newInterval) {
	const size_t n{intervals.size()};
	if (n == 0) {
		return {newInterval};
	}
	std::vector<std::vector<int>> result;
	size_t i{0};

	while (i < n && intervals[i][1] < newInterval[0]) {
		result.push_back(intervals[i++]);
	}
	while (i < n && intervals[i][0] <= newInterval[1]) {
		newInterval[0] = std::min(newInterval[0], intervals[i][0]);
		newInterval[1] = std::max(newInterval[1], intervals[i][1]);
		++i;
	}
	result.push_back(newInterval);
	while (i < n) {
		result.push_back(intervals[i++]);
	}
	return result;
}

std::vector<std::vector<int>> insert2(
		const std::vector<std::vector<int>>& intervals,
		std::vector<int>& newInterval) {
  const size_t n{intervals.size()};
  if (n == 0) {
    return {newInterval};
  }
  std::vector<std::vector<int>> result;
  size_t i{0};
  bool inserted{false};

  while (i < n) {
    if (newInterval[1] < intervals[i][0]) {
      result.push_back(newInterval);
      result.insert(result.end(), intervals.begin() + i, intervals.end());
      inserted = true;
      break;
    } else if (intervals[i][1] < newInterval[0]) {
      result.push_back(intervals[i++]);
    } else {
      newInterval[0] = std::min(newInterval[0], intervals[i][0]);
      newInterval[1] = std::max(newInterval[1], intervals[i][1]);
      ++i;
    }
  }
  if (!inserted) {
    result.push_back(newInterval);
  }
  return result;
}
