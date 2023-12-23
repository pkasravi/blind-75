# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def majorityElement(nums: List[int]) -> int:
    candidate = None
    count = 0

    for val in nums:
        if count == 0:
            candidate = val
        count += 1 if candidate == val else -1
    return candidate
