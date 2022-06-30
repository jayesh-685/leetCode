class Solution {
public:
    bool isValid(string st) {
        stack <char> s;
        for (auto b: st) {
            if (b=='(' || b=='[' || b=='{')
                s.push(b);
            else {
                if (s.empty())
                    return false;
                char c = s.top();
                if (c=='('&&b==')' || c=='['&&b==']' || c=='{'&&b=='}')
                    s.pop();
                else
                    return false;
            }
        }
        
        return !s.size();
    }
};