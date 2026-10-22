class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'X'));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }

        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans[row][col]='O';

            for(int i=0;i<4;i++){
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && ans[nrow][ncol] == 'X'){
                    q.push({nrow,ncol});
                    ans[nrow][ncol]=='O';
                }
            }
        }
        board=ans;
        return;
    }
};