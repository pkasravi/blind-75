#include <queue>
#include <vector>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/flood-fill/
 *
 * Solution Description:
 * Starting from the starting cell perform a sort of BFS where we traverse the
 * matrix four directionally, and continue the BFS from any cells that get their
 * color changed. For processing cells OTHER than the source cell, we check if
 * its value is the same as the target, if yes we change the value and continue
 * the search from any children.
 *
 * Steps:
 * 1 - Define two helper functions isValid() and getChildren()
 * 2 - Change our source nodes value
 * 3 - Use getChildren and isValid to add any viable children to the BFS queue
 * a - Check that a child is not in our Visited mat prior to adding to the queue
 * 4 - After a child has been added to the queue mark it as visited
 *
 * Complexity Analysis:
 * Time: O(m*n) becuase in the worst case we might need to fill the entire mat
 * Space: O(m*n) for our Visited matrix
 *
 * -----------------------------------------------------------------------------
 */

struct Point {
  int row;
  int col;
};

bool isValid(const Point& cell, const size_t rows, const size_t cols) {
  return (cell.col >= 0) && (cell.col <= cols - 1) && (cell.row >= 0) &&
         (cell.row <= rows - 1);
}

std::vector<Point> getChildren(const Point& cell) {
  return {
      {cell.row + 1, cell.col},
      {cell.row - 1, cell.col},
      {cell.row, cell.col + 1},
      {cell.row, cell.col - 1},
  };
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                        const int sr, const int sc,
                                        const int color) {
  if (image[sr][sc] == color) {
    return image;
  }
  const size_t rows{image.size()};
  const size_t cols{image[0].size()};
  const int old_color{image[sr][sc]};

  std::queue<Point> work_queue{{{.row = sr, .col = sc}}};

  while (!work_queue.empty()) {
    const auto curr{work_queue.front()};
    work_queue.pop();
    image[curr.row][curr.col] = color;

    for (const auto child : getChildren(curr)) {
      if (isValid(child, rows, cols) &&
          image[child.row][child.col] == old_color) {
        work_queue.push(child);
      }
    }
  }
  return image;
}
