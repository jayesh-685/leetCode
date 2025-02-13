class Solution {
public:
    int countVowelPermutation(int n) {
        long long a=1, e=1, i=1, o=1, u=1, mod=pow(10,9)+7;
        long long a2, e2, i2, o2, u2;
        
        for (int c=1; c<n; c++) {
            a2=e%mod;
            e2=(a+i)%mod;
            i2=(a+e+o+u)%mod;
            o2=(i+u)%mod;
            u2=a%mod;
            
            a=a2; e=e2; i=i2; o=o2; u=u2;
        }
        
        // cout << a << e << i << o << u << endl;
        
        return (a+e+i+o+u)%mod;
    }
};