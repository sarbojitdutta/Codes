class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ch;

        for(char c : s){
            if(!ch.empty() && ch.top() == c){
                ch.pop();
            }else{
                ch.push(c);
            }
        }

        string result = "";
        while(!ch.empty()){
            result = ch.top() + result;
            ch.pop();
        }
        return result;
    }
};