class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int N = arr.size();

        int i=0;
        while(i<N){

            long long int idx = arr[i]-1ll;

            if(arr[i]>0 && arr[i]<= N && arr[i]!= arr[idx]){
                swap(arr[i], arr[idx]);
            }else{
                i++;
            }
        }//while

        /*for(int ele: arr){
            cout<<ele<<" ";
        }cout<<endl;*/


        vector<int> ans;
        for(int i=0; i<N; i++){
            long long int idx = arr[i]-1ll;
            if(i!= idx){
                return (i+1);
            }
        }
        
        return arr.size()+1;
    }
};