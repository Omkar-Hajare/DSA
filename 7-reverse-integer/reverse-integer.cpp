class Solution {
public:
    int reverse(int x) {
     int reversedigi=0;
        while (x!=0){
           int lastdigi=x%10;
           if((reversedigi>INT_MAX/10)||(reversedigi<INT_MIN/10)){
            return 0;
           }
            reversedigi=(reversedigi*10)+lastdigi;
            x=x/10;
        }
        return reversedigi;
    }
};