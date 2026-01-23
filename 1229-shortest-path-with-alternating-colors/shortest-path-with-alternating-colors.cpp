class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>red(n),blue(n);
        for(auto ele:redEdges) red[ele[0]].push_back(ele[1]);
        for(auto ele:blueEdges) blue[ele[0]].push_back(ele[1]);
        vector<vector<int>>dist(n,vector<int>(2,-1));
        dist[0][0]=0;
        dist[0][1]=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        while(q.size()!=0){
            auto curr=q.front();
            q.pop();
            if(curr.second==0){
                for(int neighbour:blue[curr.first]){
                    if(dist[neighbour][1]==-1){
                        dist[neighbour][1]=dist[curr.first][0]+1;
                        q.push({neighbour,1});
                    }
                }
            }
            else{
                for(int neighbour:red[curr.first]){
                    if(dist[neighbour][0]==-1){
                        dist[neighbour][0]=dist[curr.first][1]+1;
                        q.push({neighbour,0});
                    }
                }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(dist[i][0]==-1) ans[i]=dist[i][1];
            else if(dist[i][1]==-1) ans[i]=dist[i][0];
            else ans[i]=min(dist[i][1],dist[i][0]);
        }
        return ans;
    }
};