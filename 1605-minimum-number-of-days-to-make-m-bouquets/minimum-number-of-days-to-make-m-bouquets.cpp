class Solution {
public:
    bool possible(vector<int>& arr,int day,int m,int k){
       int n= arr.size();
       int count=0;
       int bouqet=0;

       for(int i=0;i<n;i++){
        if(arr[i]<=day){
            count++;
            if(count==k){
                bouqet++;
                count=0;
            }
        }
        else{
            count=0;
        }
       }
       
       return bouqet>=m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total= 1ll* m*k;
        if(total>bloomDay.size())return -1;

        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());

        int start=mini;
        int end =maxi;
        int result=-1;

        while(start<=end){
            int mid=(start+end)/2;

            if(possible(bloomDay,mid,m,k)==true){
                result=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return result;


    }
};