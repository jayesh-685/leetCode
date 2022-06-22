class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector <bool> reachable (n, false);
        vector <bool> visited (n, false);
        queue <int> q;
        q.push(0);
        reachable[0] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            // cout << curr << endl;
            q.pop();
            visited[curr] = true;
            for (int x: rooms[curr]) {
                if (!reachable[x]) {
                    q.push(x);
                    reachable[x] = true;
                }
            }
        }
        
        for (int i=0; i<n; i++)
            if (!visited[i])
                return false;
        
        return true;
    }
};