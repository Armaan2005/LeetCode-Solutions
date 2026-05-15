class Solution {
public:
int helper(int n){
    if(n==1 || n==2) return 1;
    int x=1;
    int nex=n;
    for(int i=0;i<n;i++){
        int prev=x;
        x*=2;
        if(x==n) return 1;
        else if(x>n){
            nex=min(abs(x-n),abs(prev-n));
            break;
        }
    }
    return 1+helper(nex);
}
    int minOperations(int n) {
        return helper(n);
    }
};