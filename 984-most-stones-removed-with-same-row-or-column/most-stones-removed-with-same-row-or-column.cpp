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
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        disjointSet ds(maxRow+maxCol+2);

        unordered_map<int,int>stonesNodes;

        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.unionbySize(nodeRow,nodeCol);
            stonesNodes[nodeRow] = 1;
            stonesNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto it : stonesNodes){
            if(ds.findParent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};