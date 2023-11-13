# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def areEqual(a: str, b: str) -> bool:
    if a.isalpha():
        a = a.lower()
    if b.isalpha():
        b = b.lower()
    return a == b

def isPalindrome(s: str) -> bool:
    left = 0
    right = len(s) - 1
    result = True

    while left < right:
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        if not areEqual(s[left], s[right]):
            result = False
            break
        left += 1
        right -= 1
    return result
