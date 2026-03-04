class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";

        for(int i = 0; i< path.size(); i++){
            if(path[i] == '/'){
                if(temp == "" || temp == "."){
                    //do nothing
                }else if (temp == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }else{
                    st.push(temp);
                }
                temp = "";
            }else{
                temp += path[i];
            }
        }
        if (temp == "..") {
            if (!st.empty()) st.pop();
        } 
        else if (temp != "" && temp != ".") {
            st.push(temp);
        }

        string result = "";
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
        
    }
};