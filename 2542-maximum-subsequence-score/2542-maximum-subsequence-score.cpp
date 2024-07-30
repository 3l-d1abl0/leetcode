class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int N = nums1.size();
        
        vector<pair<int, int>> nums3;
        for(int i=0; i<N; i++){
            nums3.push_back({i, nums2[i]});
        }
        //Sort the num3 in descending order, based on its value
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
            
            
            if(i<k){
                minHeap.push(nums1[nums3[i].first]);
                runningSum += nums1[nums3[i].first];
                
                 maxScore = runningSum*nums3[i].second;
            }else{
                
                //If the incoming index at num1 is greater than the smallest element , othewise ignore
                if(!minHeap.empty() && nums1[nums3[i].first] > minHeap.top()){ 
                
                    runningSum -= minHeap.top();
                    minHeap.pop();
                    
                    minHeap.push(nums1[nums3[i].first]);
                    runningSum += nums1[nums3[i].first];
                
                    maxScore = max(maxScore, runningSum*nums3[i].second);
                }
                
            }
            
            //ask if 'i' is the min element in a sunsequence of size k
            /*
            if(i<k-1){
                minHeap.push(nums1[nums3[i].first]);
                runningSum += nums1[nums3[i].first];
                cout<<i<<" "<<runningSum<<" "<<endl;
                continue;
            }else{
                
                //cout<<"Score = "<<runningSum<<" + "<<nums1[nums3[i].first]<<" * "<<nums3[i].second<<" = "<<(runningSum+nums1[nums3[i].first])*nums3[i].second<<endl;
                
                
                //MaxScore for Current K Windfow
                maxScore = max(maxScore, (runningSum+nums1[nums3[i].first])*nums3[i].second );
                
                //exclude the smallest element , for the next incoming element
                if(!minHeap.empty() && nums1[nums3[i].first] > minHeap.top()){ 
                    
                    runningSum -= minHeap.top();
                    minHeap.pop();
                    
                    minHeap.push(nums1[nums3[i].first]);
                    runningSum += nums1[nums3[i].first];
                }else{
                    //nums1[nums3[i].first] is the smallest in the window
                }
                
                
            }//else
            */
            
        }//for
        
        
        return maxScore;
    }
};