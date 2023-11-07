# ------------------------------------------------------------------------------
# See 1-two-sum.cc for notes
# ------------------------------------------------------------------------------
from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    val_to_idx = {}
    result = [-1, -1]

    for i, val in enumerate(nums):
        complement = target - val
        if complement in val_to_idx:
            result = [val_to_idx[complement], i]
            break
        val_to_idx[val] = i
    return result

