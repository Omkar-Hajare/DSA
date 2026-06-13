class Solution {
public:
     bool check(vector<int>& arr, int target,int n) {
            int start = 0;
            int end = n- 1;

            while (start <= end) {
                int mid = (start + end) / 2;
                if (arr[mid] == target) {
                    return true;
                }else if(arr[mid]<target){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            return false;
        }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
           if( check(matrix[i], target ,n)){
            return true;
           }
        }
        return false;
    }
};