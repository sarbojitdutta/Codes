class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char>mapST, mapTS;

        for(int i=0; i<s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];

            //s -> t mapping
            if(mapST.find(c1) == mapST.end()){
                mapST[c1] = c2;
            }else{
                if(mapST[c1] != c2){
                    return false;
                }
            }

            //t -> s mapping
            if(mapTS.find(c2) == mapTS.end()){
                mapTS[c2] = c1;
            }else{
                if(mapTS[c2] != c1){
                    return false;
                }
            }
            
        }
        
        return true;

    }
};