class Solution {
public:
    string removeDuplicates(string s) {
        string ch = "";

        for(char c : s){
            if(!ch.empty() && ch.back() == c){
                ch.pop_back();
            }else{
                ch.push_back(c);
            }
        }

        return ch;
    }
};