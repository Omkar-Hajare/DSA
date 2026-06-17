class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int m1[26] = {0};

        //adding frequency 
        for(int i=0;i<s.size();i++){
            m1[s[i]-'a']++;
        }

        //decreasing frequence
        for(int i=0;i<s.size();i++){
            m1[t[i]-'a']--;
        }

        //if all elements are match the frequency return to 0
        for (int i = 0; i < 26; ++i) {
              if (m1[i] !=0) return false;
        }
        return true;
    }
};