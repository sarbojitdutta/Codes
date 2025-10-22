class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        long long currSum = 0;
        int minlen = INT_MAX;

        for(int right = 0; right < n; right++){
            currSum += nums[right];

            while(currSum >= target){
                minlen = min(minlen, right-left +1 );
                currSum -= nums[left++];
            }
        }
        return (minlen == INT_MAX) ? 0 : minlen;
        
    }
};