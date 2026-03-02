class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        
        for(int i = 0; i < expression.size(); i++) {
            char op = expression[i];
            
            if(op == '+' || op == '-' || op == '*') {
                
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for(int l : left) {
                    for(int r : right) {
                        if(op == '+')
                            result.push_back(l + r);
                        else if(op == '-')
                            result.push_back(l - r);
                        else if(op == '*')
                            result.push_back(l * r);
                    }
                }
            }
        }
        
        if(result.empty()) {
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};