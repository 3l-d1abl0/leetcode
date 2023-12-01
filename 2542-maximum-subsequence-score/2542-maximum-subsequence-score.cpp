class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int N = nums1.size();
        
        vector<pair<int, int>> nums3;
        for(int i=0; i<N; i++){
            nums3.push_back({i, nums2[i]});
        }
        //Sort the num3 in descending order
        sort(nums3.begin(), nums3.end(), [](  pair<int, int> &a,   pair<int, int> &b){
            return a.second > b.second;    
        });
        
        
        /*for(auto ele: nums3)
            cout<<ele.first<<" ,"<<ele.second<<endl;;
        
        cout<<endl;
        */
        
        
        long long int maxScore =0;
        long long int runningSum =0;
        
        priority_queue<int, vector<int> , greater<int> > minHeap;
        
        for(int i=0; i<N; i++){
            
            //ask if 'i' is the min element in a sunsequence of size k
            
            if(i<k-1){
                minHeap.push(nums1[nums3[i].first]);
                runningSum += nums1[nums3[i].first];
                continue;
            }else{
                
                //cout<<"Score = "<<runningSum<<" + "<<nums1[nums3[i].first]<<" * "<<nums3[i].second<<" = "<<(runningSum+nums1[nums3[i].first])*nums3[i].second<<endl;
                
                maxScore = max(maxScore, (runningSum+nums1[nums3[i].first])*nums3[i].second );
                
                
                if(!minHeap.empty() && nums1[nums3[i].first] > minHeap.top()){
                    
                    runningSum -= minHeap.top();
                    minHeap.pop();
                    
                    minHeap.push(nums1[nums3[i].first]);
                    runningSum += nums1[nums3[i].first];
                }
                
                
            }//else
            
        }//for
        
        
        return maxScore;
    }
};