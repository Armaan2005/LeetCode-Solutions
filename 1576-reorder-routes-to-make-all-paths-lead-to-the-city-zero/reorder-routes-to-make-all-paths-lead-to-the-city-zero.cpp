class Solution {
public:
    void dfs(vector<bool>&visited,int st,vector<vector<pair<int,int>>>&graph,int &ans){
        if(visited[st]==true) return;
        visited[st]=true;
        for(auto n:graph[st]){
            if(visited[n.first]==true) continue;
            if(n.second==1) ans++;
            dfs(visited,n.first,graph,ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto ele:connections){
            graph[ele[0]].push_back({ele[1],1});
            graph[ele[1]].push_back({ele[0],-1});
        }
        int ans=0;
        vector<bool>visited(n);
        dfs(visited,0,graph,ans);
        return ans;

    }
};