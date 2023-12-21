# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from collections import Counter

def canConstruct(ransomNote: str, magazine: str) -> bool:
    char_counts = Counter(magazine)

    result = True
    for ch in ransomNote:
        if ch not in char_counts or char_counts[ch] == 0:
            result = False
            break
        char_counts[ch] -= 1
    return result
