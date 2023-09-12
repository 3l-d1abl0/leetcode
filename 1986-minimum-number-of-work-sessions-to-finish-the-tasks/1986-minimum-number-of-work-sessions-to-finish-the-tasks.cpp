class Solution {
public:
    
    int recur(int idx, vector<int> &tasks, int sessionTime, vector<int> &buckets, vector<int> &memo){
        
        
        if(idx<0)
            return buckets.size();   //need no bucket
        
        
        //if the earlier answer is better, return that
        if(memo[idx]!=-1 && buckets.size() >= memo[idx])
            return memo[idx];
        
        //Include
        int inc = INT_MAX;
        for(int i=0; i<buckets.size(); i++){
            
            if(tasks[idx]+buckets[i]<= sessionTime){    //can be included in bucket
                
                
                buckets[i] += tasks[idx];
                
                inc = min(inc, recur(idx-1, tasks, sessionTime, buckets, memo));
                
                buckets[i] -= tasks[idx];
            }
            
        }
        
        
        //exclude - tried inserting into buckets , now create a new bucket and inset itself
        
        buckets.push_back(tasks[idx]);
        
        int exc = recur(idx-1, tasks, sessionTime, buckets, memo);
        
        buckets.pop_back();
        
        
        return memo[idx] = min(inc, exc);
    }
    
    int method1(vector<int> &tasks, int sessionTime){
        
        /*
            Given a set of avail/unavail bits v/s remainint Session time, huw amny sessions are required
            
            [10110][remTime] -> how many sessions are required
            
            
            [00000][] - 0 doesnt require any bits
            
            [11111][sessionTime] - ans
        
        */
        int N = tasks.size();
        vector<vector<int>> memo(1<<N, vector<int>(sessionTime+1, -1));
        
        //all 1's and zero remaining time
        return topDown((1<<N)-1, 0, memo, sessionTime, tasks);
       
        
        //O(2^N * sessionTime * N)
        
        return memo[(1<<N)-1][0];
        
    }
    
    int topDown(int mask, int remainingTime, vector<vector<int>> &memo, int sessionTime, vector<int> &tasks){
        
        if(mask==0){
            return 0;
        }
        
        if(memo[mask][remainingTime]!=-1)
            return memo[mask][remainingTime];
        
        
        int ans = INT_MAX;
        
        for(int i=0; i<tasks.size(); i++){
            
            if( (mask & (1<<i))!=0 ){  //ith bit is not chosen/available
                
                if(tasks[i]<=remainingTime){ //can include/exclude
                      ans = min(ans, topDown( (mask & ( ~(1<<i) ) ), remainingTime-tasks[i], memo, sessionTime, tasks) );
                   /* ans = min(ans, min( 
                            topDown( (mask & ( ~(1<<i) ) ), remainingTime-tasks[i], memo, sessionTime, tasks),
                            1+topDown((mask & ( ~(1<<i) )), sessionTime, memo, sessionTime, tasks)));            */
                    
                }else{  //exclude
                    //cout<<"creating new "<<mask<<" "<<tasks[i]<<" "<<remainingTime<<endl;
                    ans = min(ans, 1+topDown((mask & ( ~(1<<i) )), sessionTime-tasks[i], memo, sessionTime, tasks) );
                }
                
                
            }//if mask
            
        }//for
                              
                    
        //cout<<mask<<" "<<remainingTime<<" = "<<ans<<endl;
        return memo[mask][remainingTime] = ans;
        
    }
    
    
    int method2(vector<int> &tasks, int sessionTime){
        
        int N = tasks.size();
        vector< pair<int, int> > memo( (1<<N), {-1, -1});   
        return recursion( (1<<N)-1, tasks, sessionTime, memo).first;
    }
    
    pair<int, int> recursion( int mask, vector<int> &tasks, int sessionTime, vector<pair<int, int>> &memo){
        
        
        if(mask ==0 )
            return {0, 0};
        
        
        if(memo[mask].first!=-1)
            return memo[mask];
        
        int N = tasks.size();
        pair<int, int> ans = {1e9, 1e9};
        
        for(int i=0; i<N; i++){
            
            if( (mask&(1<<i)) !=0){  //1
                
                auto sub = recursion( mask &(~(1<<i)), tasks, sessionTime, memo);  //solve for subset first
                
                int nos = sub.first, remainingTime = sub.second;
                if(tasks[i] <= remainingTime){  //include
                   remainingTime -=tasks[i]; 
                }else{  //exclude //create new session
                    nos+=1;
                    remainingTime = sessionTime-tasks[i];
                }
                
                
                if(nos<ans.first || (nos==ans.first && remainingTime > ans.second) ){
                    ans = {nos, remainingTime};
                }
                
            }//if
            
        }//for
        
        return memo[mask] = ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        
        
        
        //return method1(tasks, sessionTime);
        
        
        return method2(tasks, sessionTime);
        
        vector<int> bucket;
        
        vector<int> memo(15, -1);
        return recur(tasks.size()-1, tasks, sessionTime, bucket, memo);
        
    }
};