# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def climbStairs(n: int) -> int:
    prev_prev = 0
    prev = 1
    for _ in range(n):
        curr = prev + prev_prev
        prev_prev = prev
        prev = curr
    return prev
