class disjointSet{
    public:

        vector<int>parent,rank,size;

        disjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionbyRank(int u,int v){
            int upu = findParent(u);
            int upv = findParent(v);

            if(upu==upv) return;
            if(rank[upu]>rank[upv]){
                parent[upv] = upu;
            }
            else if(rank[upu]<rank[upv]){
                parent[upu] = upv;
            }
            else {
                parent[upv] = upu;
                rank[upu]++;
            }
        }

        void unionbySize(int u,int v){
            int upu = findParent(u);
            int upv = findParent(v);
            if(upu==upv) return;
            if(size[upu]<size[upv]){
                parent[upu] = upv;
                size[upv] += size[upu];
            }   
            else{
                parent[upv] = upu;
                size[upu] += size[upv];
            }         
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        disjointSet ds(n*n);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};

                for(int i=0;i<4;i++){
                    int nrow = row+dr[i];
                    int ncol = col+dc[i];

                    if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==1){
                        int node = row*n+col;
                        int adjNode = nrow*n+ncol;

                        ds.unionbySize(node,adjNode);
                    }
                }
            }
        }

        int ans = 0;

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;

                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int>component;

                for(int i=0;i<4;i++){
                    int nrow = row+dr[i];
                    int ncol = col+dc[i];

                    if(nrow<n && nrow>=0 && ncol<n && ncol>=0){
                        if(grid[nrow][ncol]==1){
                            component.insert(ds.findParent(nrow*n+ncol));
                        }
                    }
                }
                int size = 1;
                for(auto it : component){
                    size+=ds.size[it];
                }
                ans = max(ans,size);
            }
        }
        for(int column = 0; column< n*n ; column++){
            ans = max(ans,ds.size[ds.findParent(column)]);
        }
        return ans;
    }
};