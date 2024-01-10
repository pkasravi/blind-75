# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------


def maxSubArray(nums: List[int]) -> int:
    if len(nums) == 1:
        return nums[0]

    max_sum, running_sum = -float("inf"), 0
    for val in nums:
        running_sum = max(running_sum + val, val)
        max_sum = max(max_sum, running_sum)
    return max_sum
