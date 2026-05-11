class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k==1 || k==2) return 1;
        vector<int>fibo;
        fibo.push_back(1);
        fibo.push_back(1);
        while(true){
            int n=fibo[fibo.size()-2]+fibo[fibo.size()-1];
            if(n>k) break;
            fibo.push_back(n);
            if(n==k) return 1;
        }
        int count=0;
        while(k!=0){
            for(int i=fibo.size()-1;i>=0;i--){
                if(fibo[i]<=k){
                    k-=fibo[i];
                    count++;
                    break;
                }
            }
        }
        return count;

    }
};