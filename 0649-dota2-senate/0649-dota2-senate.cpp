class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int len=senate.length();
        for (int i=0; i<len; i++) {
            if (senate[i]=='R') q1.push(i);
            else                q2.push(i);
        }
        
        while (!q1.empty() && !q2.empty()) {
            int p1=q1.front(); q1.pop();
            int p2=q2.front(); q2.pop();
            if (p1<p2)  q1.push(len+p1);
            else        q2.push(len+p2);
        }
        
        if (size(q1))   return "Radiant";
        else            return "Dire";
    }
};