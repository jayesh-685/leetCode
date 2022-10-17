class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if (num==0)
            return true;
        for (int i=num/2; i<num; i++) {
            string temp = to_string(i);
            reverse(temp.begin(), temp.end());
            int x = stoi(temp);
            if (x+i == num)
                return true;
        }
        
        return false;
    }
};