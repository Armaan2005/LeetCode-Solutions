class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        int n = friends.size();
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(id);
        visited[id] = true;

        int currLevel = 0;

        while (!q.empty() && currLevel < level) {
            int sz = q.size();
            currLevel++;

            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();

                for (int nei : friends[curr]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }

        unordered_map<string,int> freq;

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            for (auto &video : watchedVideos[person]) {
                freq[video]++;
            }
        }

        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       greater<pair<int,string>>> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

