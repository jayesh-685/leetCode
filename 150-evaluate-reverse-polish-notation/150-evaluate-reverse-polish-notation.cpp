// be careful of order in - /
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res=0;
        stack <int> s;
        
        for (auto t: tokens) {
            if (t=="+" || t=="-" || t=="*" || t=="/") {
                int a=s.top(); s.pop();
                int b=s.top(); s.pop();
                if (t=="+")
                    res = a+b;
                else if (t=="-")
                    res = b-a;
                else if (t=="*")
                    res = a*b;
                else
                    res = b/a;
                s.push(res);
            } else {
                s.push(stoi(t));
            }
        }
        
        return s.top();
    }
};