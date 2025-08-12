class Solution {
public:
    string processStr(string s) {
        string ans = "";
        int n = s.length();

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                if(ans.length() > 0)
                    ans.pop_back();
            }
            else if(s[i] == '#'){
                if(ans.length() > 0){
                    string temp = ans;
                    ans.append(temp);
                }
            }
            else if(s[i] == '%'){
                reverse(ans.begin(), ans.end());
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};