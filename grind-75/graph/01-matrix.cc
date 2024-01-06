/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/01-matrix/
 *
 * Solution Description:
 * We will solve this using dynamic programming. The idea being that as we
 * traverse the matrix we use the distance values for earlier cells to solve the
 * current cell. We need to traverse the matrix once top-down and then
 * bottom-up. We do this twice because of edge cells possibly being ones, for
 * example if cell (0, 0) is a 1 there is no way we can find the distance using
 * only top-down.
 *
 * Steps:
 * 1 - Create a matrix of similar size and fill it with int_max
 * 2 - Traverse our input matrix from the top left corner to the bottom right
 *     corner
 * a - If a cell in the input matrix is 0, fill the same cell in the output
 *     matrix witha 0
 * b - Otherwise fill it with 1 plus the min of the neighboring cells (not
 *     including diagonals)
 * 3 - Repeat step 2 starting from the bottom right corner to the top left
 *
 * Complexity Analysis:
 * Time: O(m*n) because traversing the matrix takes O(m*n) we do this twice
 *       which gives us O(2m*2n) which reduces to O(m*n)
 * Space: O(1) if we don't count the output container, otherwise O(m*n)
 *
 * -----------------------------------------------------------------------------
 */

struct Bounds {
  int rows;
  int cols;
};

std::vector<std::vector<int>> updateMatrix(
    const std::vector<std::vector<int>>& mat) {
  const Bounds bounds{static_cast<int>(mat.size()),
                      static_cast<int>(mat[0].size())};
  std::vector<std::vector<int>> result(
      bounds.rows,
      std::vector<int>(bounds.cols, std::max(bounds.rows, bounds.cols)));
  fillTopDown(mat, bounds, result);
  fillBottomUp(mat, bounds, result);
  return result;
}

void fillTopDown(const std::vector<std::vector<int>>& mat, const Bounds& bounds,
                 std::vector<std::vector<int>>& result) {
  for (int i = 0; i < bounds.rows; ++i) {
    for (int j = 0; j < bounds.cols; ++j) {
      if (mat[i][j] == 0) {
        result[i][j] = 0;
      } else {
        if (i > 0) {
          result[i][j] = std::min(result[i][j], 1 + result[i - 1][j]);
        }
        if (j > 0) {
          result[i][j] = std::min(result[i][j], 1 + result[i][j - 1]);
        }
      }
    }
  }
}

void fillBottomUp(const std::vector<std::vector<int>>& mat,
                  const Bounds& bounds, std::vector<std::vector<int>>& result) {
  for (int i = bounds.rows - 1; i >= 0; --i) {
    for (int j = bounds.cols - 1; j >= 0; --j) {
      if (mat[i][j] == 0) {
        result[i][j] = 0;
      } else {
        if (i < bounds.rows - 1) {
          result[i][j] = std::min(result[i][j], 1 + result[i + 1][j]);
        }
        if (j < bounds.cols - 1) {
          result[i][j] = std::min(result[i][j], 1 + result[i][j + 1]);
        }
      }
    }
  }
}
