class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0, n=size(letters);
        while (i<n && letters[i]<=target)   i++;
        
        if (i==n)   return letters[0];
                    return letters[i];
    }
};