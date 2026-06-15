class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin(),strs.end());

        string s1=strs[0];
        string s2=strs[strs.size()-1];

       int maxlenght=min(s1.size(),s2.size());
        string ans="";

        for(int i=0;i<maxlenght;i++){
            if(s1[i]!=s2[i]) break;

            ans+=s1[i];

        }

        return ans;
    }
};