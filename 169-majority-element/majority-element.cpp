class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> st;

        for(int i : nums){
            st[i]++;
        }

        int n = nums.size();

        for(auto it : st){
            if(it.second > n/2){
                return it.first;
            }
        }
        return -1;
    }
};