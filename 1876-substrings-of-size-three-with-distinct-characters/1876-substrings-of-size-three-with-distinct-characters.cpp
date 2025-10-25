class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for(int i=0; i+2<n; i++){
            unordered_set<char> st = {s[i], s[i+1], s[i+2]};
            if(st.size() == 3){
                count++;
            }
        }
        return count;

    }
};