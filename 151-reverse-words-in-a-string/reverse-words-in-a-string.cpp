class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] ==' ') {
                i--;
            }

            if (i < 0)
                break;

            int end = i;

            while (i >= 0 && s[i] !=' ') {
                i--;
            }
            // extracting word from index i+1 of end-i lenght
            string word = s.substr(i + 1, end - i);

            if (!ans.empty()) {
                ans += " ";
            }

            ans += word;
        }

        return ans;
    }
};