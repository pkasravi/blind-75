# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from typing import List

def maxSubArray(self, nums: List[int]) -> int:
    if len(nums) == 0:
        return 0

    max_sum, running_sum = -float("inf"), 0
    for val in nums:
        running_sum = max(running_sum + val, val)
        max_sum = max(max_sum, running_sum)
    return max_sum

