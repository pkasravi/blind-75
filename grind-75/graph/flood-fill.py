# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from collections import deque
from typing import List

class Point:
    def __init__(self, row: int, col: int):
        self.row = row
        self.col = col

    def isValid(self, max_row: int, max_col: int) -> bool:
        return self.row >= 0 and self.col >= 0 and self.row <= max_row - 1 and self.col <= max_col - 1

    def getNeighbors(self) -> List[Point]:
        return [
            Point(self.row + 1, self.col),
            Point(self.row - 1, self.col),
            Point(self.row, self.col + 1),
            Point(self.row, self.col - 1),
        ]

def floodFill(image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
    max_row = len(image)
    max_col = len(image[0])
    old_color = image[sr][sc]
    visited = [[0] * max_col] * max_row

    work_queue = deque([Point(row=sr, col=sc)])
    while len(work_queue) > 0:
        curr = work_queue.popleft()
        image[curr.row][curr.col] = color

        for neighbor in curr.getNeighbors():
            if neighbor.isValid(max_col=max_col, max_row=max_row) and visited[neighbor.row][neighbor.col] == 0 and image[neighbor.row][neighbor.col] == old_color:
                # TODO: Can't figure out why this isn't working
                work_queue.append(neighbor)
                visited[neighbor.row][neighbor.col] = 1
    return image
