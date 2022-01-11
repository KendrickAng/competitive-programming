class Solution:
    def updateMatrix(self, matrix):

            # So this problem asks us to find the minimum distance of 0  from every cell with value 1, 
            # BFS should ring in your mind and instead of our single-source BFS, we 
            # Apply multiple source BFS.

            dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

            m, n = len(matrix), len(matrix[0])

            queue = collections.deque()

            res = [[-1 for _ in range(n)] for _ in range(m)]

            for i in range(m):
                for j in range(n):

                    if matrix[i][j] == 0:
                        # The distance to itself is 0 and add all sources here to queue
                        res[i][j] = 0
                        queue.append((i, j))


            # Now we start our BFS

            while queue:

                curI, curJ = queue.popleft()
                for i, j in dirs:
                    neighBorI, neighBorJ = curI + i, curJ + j
                    # Validate all the neighbors and validate the distance as well
                    if 0 <= neighBorI < m and 0 <= neighBorJ < n and res[neighBorI][neighBorJ] == -1:
                        res[neighBorI][neighBorJ] = res[curI][curJ] + 1
                        queue.append((neighBorI, neighBorJ))

            return res        