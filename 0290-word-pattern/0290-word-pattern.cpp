class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while(ss >> word){
            words.push_back(word);
        }

        if(pattern.size() != words.size()) return false;

        unordered_map<char, string>mpp;
        unordered_map<string, char>mpp2;

        for(int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            string w = words[i];

            if(mpp.count(ch)){
                if(mpp[ch] != w) return false;
            }else{
                mpp[ch] = w;
            }

            if(mpp2.count(w)){
                if(mpp2[w] != ch) return false;
            }else{
                mpp2[w] = ch;
            }
        }
        return true;
    }    
        
};