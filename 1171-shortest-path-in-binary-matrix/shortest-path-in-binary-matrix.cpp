class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
        return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n-1 && c == m-1)
                return dis;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nrow = r + i;
                    int ncol = c + j;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dis + 1;
                        if (nrow == n - 1 && ncol == m - 1)
                            return dis + 1;
                        q.push({1 + dis, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};