# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def containsDuplicate(nums: List[int]) -> bool:
    seen = set()
    result = False
    for val in nums:
        if val in seen:
            result = True
            break
        seen.add(val)
    return result

def containsDuplicate2(nums: List[int]) -> bool:
    return len(set(nums)) < len(nums)
