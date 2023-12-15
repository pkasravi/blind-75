# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from collections import deque
from typing import Optional

class MyQueue:

    def __init__(self):
        self.input = deque()
        self.output = deque()

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> Optional[int]:
        if self.empty():
            return None
        if len(self.output) == 0:
            self.fill_output()
        return self.output.pop()

    def peek(self) -> Optional[int]:
        if self.empty():
            return None
        if len(self.output) == 0:
            self.fill_output()
        return self.output[-1]

    def empty(self) -> bool:
        return len(self.input) == 0 and len(self.output) == 0

    def fill_output(self) -> None:
        while len(self.input) > 0:
            self.output.append(self.input.pop())
