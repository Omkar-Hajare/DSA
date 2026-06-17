class Solution {
public:
    int maxDepth(string s) {
      int Mdepth=0; 
       int Cdepth=0; 
      for(char ch:s){
        if(ch=='('){
             Cdepth++;
        }else if(ch==')'){
            Cdepth--;
        }
          Mdepth=max(Cdepth,Mdepth);
      }
      return Mdepth;  
    }
};