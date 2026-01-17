class Solution {
public:

    bool dfs(string s, string d,
             unordered_map<string, vector<pair<string,double>>> &m,
             unordered_set<string> &visited,
             double curr,
             double &result) {

        if(s == d) {
            result = curr;
            return true;
        }

        visited.insert(s);

        for(auto &neighbour : m[s]) {
            if(visited.find(neighbour.first) != visited.end()) continue;

            if(dfs(neighbour.first, d, m, visited,
                   curr * neighbour.second, result))
                return true;
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> m;

        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            m[u].push_back({v, val});
            m[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for(auto &q : queries) {
            string s = q[0];
            string d = q[1];

            if(m.find(s) == m.end() || m.find(d) == m.end()) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = -1.0;

            dfs(s, d, m, visited, 1.0, result);
            ans.push_back(result);
        }

        return ans;
    }
};
