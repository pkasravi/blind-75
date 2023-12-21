# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from collections import Counter

def longestPalindrome(s: str) -> int:
    if len(s) < 2:
        return 0 if len(s) == 0 else 1
    char_counts = Counter(s)

    length = 0
    odd_found = False
    for count in char_counts.values():
        if count % 2 == 0:
            length += count
        else:
            odd_found = True
            length += count - 1
    return length + 1 if odd_found else length
