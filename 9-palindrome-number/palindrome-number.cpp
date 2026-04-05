class Solution {
public:
    bool isPalindrome(int x) {
        int number=x;
        long rev=0;
        while(x>0){
            int lastdigi=x%10;
            rev=(rev*10)+lastdigi;
            x=x/10;
        }
        if(number==rev){
            return true;
        }
        return 0;
    }
    
};