class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> resultList;
        vector<int> tempList;
        backtrack(resultList, tempList, nums);
        return resultList;
    }

    private:
        void backtrack(vector<vector<int>>& resultList, vector<int>& tempList, vector<int>& nums){
            if(tempList.size() == nums.size()){
                resultList.push_back(tempList);
                return;
            }

            for(int number : nums){
                if (find(tempList.begin(), tempList.end(), number) != tempList.end()) {
                    continue;
                }
                tempList.push_back(number);
                backtrack(resultList, tempList, nums);
                tempList.pop_back();
            }
        }
};