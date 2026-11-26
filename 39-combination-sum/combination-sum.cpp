class Solution {
private:
    void backtrack(int index, int target, vector<int>& candidates,
                   vector<int>& current, vector<vector<int>>& answer) {

        if (target == 0) {
            answer.push_back(current);
            return;
        }

        if (index == candidates.size()) {
            return;
        }

        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            backtrack(index, target - candidates[index], candidates, current,
                      answer);

            current.pop_back();
        } else {
        }
        backtrack(index + 1, target, candidates, current, answer);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current;
        backtrack(0, target, candidates, current, answer);

        return answer;
    }
};