class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map <int, int> mp1, mp2;
        int dist=0, curr=node1;
        
        while (curr != -1) {
            if (mp1.find(curr) != end(mp1))  break;
            
            mp1[curr] = dist;
            dist++; curr=edges[curr];
        }
        
        dist=0, curr=node2;
        
        while (curr != -1) {
            if (mp2.find(curr) != end(mp2))  break;
            
            mp2[curr] = dist;
            dist++; curr=edges[curr];
        }
        
        int n=size(edges);
        
        int ans=INT_MAX, node=-1;
        for (int i=0; i<n; i++) {
            if (mp1.find(i)!=end(mp1) && mp2.find(i)!=end(mp2)) {
                if (max(mp1[i], mp2[i]) < ans) {
                    ans = max(mp1[i], mp2[i]);
                    node = i;
                }
            }
        }
        
        return node;
    }
};