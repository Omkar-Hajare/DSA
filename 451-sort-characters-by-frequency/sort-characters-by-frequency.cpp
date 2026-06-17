class Solution {
public:
    string frequencySort(string s) {
        string sorts="";
        int freq[256]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        int maxf=s.size();
        while(maxf>0){
            for(int i=0;i<256;i++){
                if (freq[i]==maxf){
                    sorts+=string(maxf, char(i));
                }
                
            }
            maxf--;
        }
        return sorts;

    }
};