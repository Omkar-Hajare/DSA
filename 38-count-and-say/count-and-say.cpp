class Solution {
private:

    string buildNextTerm(string currentTerm) {
        string nextTerm = "";
 
        int index = 0;
 
        while (index < currentTerm.length()) {
            char digit = currentTerm[index];
 
            int count = 0;

            while (index < currentTerm.length() && currentTerm[index] == digit) {
                count++;
                index++;
            }
 
            nextTerm += to_string(count) + digit;
        }
 
        return nextTerm;
    }
 
public:

    string countAndSay(int n) {

        if (n == 1) {
            return "1";
        }
 
        string previousTerm = countAndSay(n - 1);
 
        return buildNextTerm(previousTerm);
    }
};