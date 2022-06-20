class Solution {
public:
    static bool comp(string a , string b){
        return((a.length())>(b.length()));
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        set<string> arr; int ans=0; int n=words.size();
        for(int i=0;i<n;i++){
            if(arr.find(words[i])==arr.end()){
                string temp="";
                int m=words[i].length();
                for(int j=m-1;j>=0;j--){
                    temp=words[i][j]+temp;
                    arr.insert(temp);
                }    
                ans+=(m+1);
            }
        }
        return(ans);
    }
};