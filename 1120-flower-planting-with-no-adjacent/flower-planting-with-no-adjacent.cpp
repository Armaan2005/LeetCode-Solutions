class Solution {
public:
   
    void dfs(int st,vector<vector<int>>&adj,vector<int>&nc){
        vector<bool>used(5,false);
        for(auto neighbour:adj[st]){
            if(nc[neighbour]!=-1){
                used[nc[neighbour]]=true;
            }
        }
        for(int i=1;i<5;i++){
            if(used[i]==false){
                nc[st]=i;
                break;
            }
        }
        for(auto neighbour:adj[st]){
            if(nc[neighbour]!=-1) continue;
            dfs(neighbour,adj,nc);
        }
        return;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto ele:paths){
            adj[ele[0]].push_back({ele[1]});
            adj[ele[1]].push_back({ele[0]});
        }
        vector<int>nc(n+1,-1);
        for(int i=1;i<=n;i++){
            if(nc[i]==-1) dfs(i,adj,nc);
        }
        nc.erase(nc.begin());
        return nc;
    }
};