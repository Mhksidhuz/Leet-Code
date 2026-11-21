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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        disjointSet ds(n);
        unordered_map<string,int>mpp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){

                string acc = accounts[i][j];

                if(mpp.find(acc)==mpp.end()){
                    mpp[acc]=i;
                }
                else{
                    ds.unionbyRank(i,mpp[acc]);
                }
            }
        }

        vector<string> mail[n];
        for(auto it : mpp){
            string acc = it.first;
            int node = ds.findParent(it.second);

            mail[node].push_back(acc);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mail[i].size()==0) continue;
            sort(mail[i].begin(),mail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};