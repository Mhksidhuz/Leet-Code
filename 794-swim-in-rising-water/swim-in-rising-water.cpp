class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});

        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0}; 

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int height = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1) return height;
            if(dist[row][col]) continue;
            dist[row][col]=1;

            for(int i=0;i<4;i++){
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !dist[nrow][ncol]){
                    int newH = max(height,grid[nrow][ncol]);
                    pq.push({newH,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};