class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for(int i=0; i+2<n; i++){
            int a = s[i];
            int b = s[i+1];
            int c = s[i+2];

            if(a != b && b != c && a != c){
                count++;
            }
        }
        return count;

    }
};