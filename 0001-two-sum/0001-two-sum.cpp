class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map;

        for(int i = 0; i < nums.size(); i++){
            int y = target - nums[i];

            if(map.find(y) != map.end()){
                return {map[y], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};