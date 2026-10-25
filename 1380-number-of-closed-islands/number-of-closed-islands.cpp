class Solution {
public:

    void dfs(int row,int col,vector<vector<int>> &vis,int n,int m){
        vis[row][col]=1;

        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};

        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                dfs(nrow,ncol,vis,n,m);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis = grid;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && vis[i][j]==0){
                    dfs(i,j,vis,n,m);
                }
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,n,m);
                }
            }
        }
        return cnt;
    }
};