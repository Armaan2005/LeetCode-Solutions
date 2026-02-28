class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        int m=groups.size();
        vector<string>ans={};
        ans.push_back(words[0]);
        for(int i=0;i<n;i++){
            if(i+1<n && groups[i]!=groups[i+1]) ans.push_back(words[i+1]);
            else continue;
        }
        return ans;
    }
};