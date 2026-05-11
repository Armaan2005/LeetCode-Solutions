class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans=0;
        while(k!=0){
            if(numOnes!=0){
                ans++;
                numOnes--;
                k--;
            }
            else if(numOnes==0 && numZeros!=0){
                numZeros--;
                k--;
            }
            else{
                k--;
                numNegOnes--;
                ans--;
            }
        }
        return ans;
    }
};