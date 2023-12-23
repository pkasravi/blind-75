# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------

def addBinary(a: str, b: str) -> str:
    carry = 0
    result = ""
    m, n = len(a) - 1, len(b) - 1

    while m >= 0 or n >= 0 or carry > 0:
        if m >= 0:
            carry += int(a[m])
            m -= 1
        if n >= 0:
            carry += int(b[n])
            n -= 1
        result += str(carry % 2)
        carry //= 2
    return result[::-1]
