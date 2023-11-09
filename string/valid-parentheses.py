# ------------------------------------------------------------------------------
# See valid_parentheses.cc for notes
# ------------------------------------------------------------------------------
from collections import deque

CLOSER_LOOKUP = {
	'(': ')',
    '[': ']',
    '{': '}'
}

def is_opener(paren: str) -> bool:
    return paren in CLOSER_LOOKUP


def is_valid(s: str) -> bool:
    if len(s) == 0:
        return True
    seen_openers = deque()
    result = True
    for paren in s:
        if is_opener(paren):
            seen_openers.append(paren)
        else:
            if len(seen_openers) == 0 or CLOSER_LOOKUP[seen_openers[-1]] != paren:
                result = False
                break
            seen_openers.pop()
    return result if len(seen_openers) == 0 else False
