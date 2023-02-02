class Solution {
public:
    // if we can develop a graph with the words as nodes then we just have to find the shortest path from startWord
// to target word (using bfs)
// to find the neighbours of each word, just replace each char of word with a to z and see if it exists
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        unordered_set <string> st (begin(wordList), end(wordList));  // to check if the new word we have created exists or not
        queue < pair<string,int> > q; // for bfs
        q.push({startWord, 1});
        st.erase(startWord);  // any word that we find, we will erase from set so that we don't visit it again since we are finding the shortest path
        
        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if (word == targetWord) return dist;
            
            for (int i=0; i<word.length(); i++) {
                string temp=word;
                for (char ch='a'; ch<='z'; ch++) {
                    word[i]=ch;
                    if (st.find(word) != end(st)) {
                        st.erase(word);
                        q.push({word, dist+1});
                    }
                }
                word = temp;
            }
        }
        
        return 0;
    }
};