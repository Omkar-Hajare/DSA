class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        for (char task : tasks) {
            frequency[task - 'A']++;
        }
 
        int maxFrequency = 0;
        for (int count : frequency) {
            maxFrequency = max(maxFrequency, count);
        }
 
        int maxFrequencyTasks = 0;
        for (int count : frequency) {
            if (count == maxFrequency) {
                maxFrequencyTasks++;
            }
        }
         int blockLength =
            (maxFrequency - 1) * (n + 1) +
            maxFrequencyTasks;
 
        return max((int) tasks.size(), blockLength);
    }
};