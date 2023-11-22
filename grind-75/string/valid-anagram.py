# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def getCharCounts(a: str) -> dict:
    result = {}
    for ch in a:
        if ch not in result:
            result[ch] = 0
        result[ch] += 1
    return result

def isAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    s_counts = getCharCounts(s)
    t_counts = getCharCounts(t)
    result = True
    for char, count in s_counts.items():
        if char not in t_counts or t_counts[char] != count:
            result = False
            break
    return result
