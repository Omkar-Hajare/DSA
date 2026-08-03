class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int r=0;
        int l=0;
        int hashsize=256;
        int hash[hashsize];

        for(int i=0;i<hashsize;i++){
            hash[i]=-1;
        }

       int  substrlen=0;

       while(r<n){
        if(hash[s[r]]!=-1){
            l=max(hash[s[r]]+1,l);
        }
        int len=r-l+1;
        substrlen=max(substrlen,len);

        hash[s[r]]=r;
        r++;

       }
      return substrlen;
    }
};