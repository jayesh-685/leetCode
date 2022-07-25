class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        int low=0, high=nums.size()-1;
        while (low<=high) {
            int mid=(low+high)/2;
            cout << low << " " << mid << " " << high << endl;
            if (nums[mid] == target) {
                if (mid==low || nums[mid-1]<target) {
                    ans.push_back(mid);
                    break;
                } else {
                    high = mid-1;
                }
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if (!ans.size()) {
            vector <int> temp {-1, -1};
            return temp;
        }
        low=0, high=nums.size()-1;
        while (low<=high) {
            int mid=(low+high)/2;
            if (nums[mid] == target) {
                if (mid==high || nums[mid+1]>target) {
                    ans.push_back(mid);
                    break;
                } else {
                    low = mid+1;
                }
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return ans;
    }
};