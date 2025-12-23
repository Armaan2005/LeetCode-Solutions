class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sa=0;
        int sb=0;
        for(auto ele:aliceSizes) sa+=ele;
        for(auto ele:bobSizes) sb+=ele;
        int dif=(sa-sb)/2;
        unordered_set<int>st(bobSizes.begin(),bobSizes.end());
        for(auto ele:aliceSizes){
            int y=ele-dif;
            if(st.count(y)) return {ele,y};
        }
        return {};
    }
};