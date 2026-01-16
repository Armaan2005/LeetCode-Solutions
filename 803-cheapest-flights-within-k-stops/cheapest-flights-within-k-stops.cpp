class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
          vector<vector<pair<int,int>>> graph(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back({v, w});
        }

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, src, 0});   

        vector<int> bestStops(n, INT_MAX);

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int currCost = top[0];
            int city = top[1];
            int stopsUsed = top[2];

            if(city == dst) return currCost;

            if(stopsUsed > k) continue;

            if(bestStops[city] <= stopsUsed) continue;
            bestStops[city] = stopsUsed;

            for(auto it : graph[city]){
                pq.push({currCost + it.second, it.first, stopsUsed + 1});
            }
        }

        return -1;
    }
};