class disjointSet{
    public:

        vector<int>parent,rank,size;

        disjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n;i++){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);

        int cntExtra = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u)==ds.findParent(v)){
                cntExtra++;
            }
            else{
                ds.unionbyRank(u,v);
            }
        }

        int cntC = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }

        int ans = cntC-1;
        if(cntExtra>=ans) return ans;
        return -1;
    }
};