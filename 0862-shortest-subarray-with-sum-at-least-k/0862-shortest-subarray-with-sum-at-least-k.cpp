struct Node{
    long long int sum;
    int idx;
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int N = nums.size();
        deque<Node> dq;
        
        long long int cSum =0;
        int minn = INT_MAX;
        
        for(int i=0; i<N; i++){
            
            cSum+= nums[i];
            
            if(cSum >= k)
                minn = min(minn, i+1);
            
            //cout<<"minn "<<minn<<endl;
            //1. Add the new element to queue
            while(!dq.empty() && dq.back().sum >= cSum){
                dq.pop_back();
            }
            dq.push_back({cSum, i});
            
            
            //2. Shrink the dq id sum of range >=k
            while(!dq.empty() && cSum-dq.front().sum >= k){
                minn = min(minn, dq.back().idx-dq.front().idx);
                dq.pop_front();
            }
            
            //if(!dq.empty())
              //  cout<<dq.front().sum<<" "<<dq.back().sum<<endl;
            
            //cout<<"minn= "<<minn<<endl<<endl;
        }
        
        if(minn==INT_MAX)
            return -1;
        else
            return minn;
        
    }
};