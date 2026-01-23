class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int ans = -1;
        int minCount = INT_MAX;

        for (int src = 0; src < n; src++) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;

                for (auto [v, w] : adj[u]) {
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= minCount) {
                minCount = cnt;
                ans = src;
            }
        }
        return ans;
    }
};
