# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def isBadVersion(n: int) -> bool:
    return True

def firstBadVersion(self, n: int) -> int:
    left, right = 1, n
    result = -1

    while left <= right:
        middle = left + (right - left) // 2

        if isBadVersion(middle):
            result = middle
            right = middle - 1
        else:
            left = middle + 1
    return result
