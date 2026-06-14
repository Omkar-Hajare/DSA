class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (level > 0)
                    result += s[i];
                level++;
            } else {
                level--;
                if (level > 0)
                    result += s[i];
            }
        }
        return result;
    }
};