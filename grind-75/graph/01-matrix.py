# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------


def updateMatrix(mat: List[List[int]]) -> List[List[int]]:
    # Create an mxn matrix of inf
    m, n = len(mat), len(mat[0])
    result = [[max(m, n)] * n for _ in range(m)]

    # Traverse top-down
    for i in range(m):
        for j in range(n):
            if mat[i][j] == 0:
                result[i][j] = 0
            else:
                if i > 0:
                    result[i][j] = min(result[i][j], 1 + result[i - 1][j])
                if j > 0:
                    result[i][j] = min(result[i][j], 1 + result[i][j - 1])

    # Traverse bottom-up
    for i in range(m - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            if mat[i][j] == 0:
                result[i][j] = 0
            else:
                if i < m - 1:
                    result[i][j] = min(result[i][j], 1 + result[i + 1][j])
                if j < n - 1:
                    result[i][j] = min(result[i][j], 1 + result[i][j + 1])
    return result
