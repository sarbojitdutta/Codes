class Solution {
public:
    int myAtoi(string s) {
       int n = s.length();
       int sign = 1;
       long long result = 0;
       bool started = false;

       for(int i = 0; i < n; i++){
        if(!started && s[i] == ' '){
            continue;
        }
        if(!started && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1:1;
            started = true;
            continue;
        }
        if(isdigit(s[i])){
            started = true;
            result = result * 10 + (s[i] - '0');

            if (sign * result > INT_MAX){
                return INT_MAX;
            }
            if(sign * result < INT_MIN){
                return INT_MIN;
            }
        }else{
            break;
        }
        
       }
       return sign * result;
       
    }
};