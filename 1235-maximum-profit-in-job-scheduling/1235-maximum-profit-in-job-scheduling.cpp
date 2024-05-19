class Solution {
public:
    
    struct job{
        int start;
        int end;
        int profit;
    };
    
    static int fn(job a, job b) {
            return a.start < b.start;
    }
    
    int lowerBound(vector<job> &jobs, int ele){
        
        int l =-1, r= jobs.size();
        
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            
            if(jobs[mid].start >=ele){
                r=mid;
            }else{
                l=mid;
            }
        }
        
        
        return r;
        
    }
    
    
    int dfs(int idx, vector<job> &jobs, vector<int> &memo){
        
        if(idx==jobs.size()-1)
            return jobs[idx].profit;
        
        
        if(memo[idx]!=-1)
            return memo[idx];
        
        //exclude
        int ex = dfs(idx+1, jobs, memo);
        
        //include
        int index = lowerBound(jobs, jobs[idx].end);
        
        int inc = index == jobs.size()?0:dfs(index, jobs, memo);
        
        
        //cout<<ex<<" "<<inc<<"+"<<jobs[idx].profit<<endl;
        //cout<<idx<<" to "<<jobs[idx].end<<"[ "<<index<<endl<<endl;
        return memo[idx] = max(ex, inc+jobs[idx].profit);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
        int N = startTime.size();
        
        
        vector<job> jobs(N);
        for(int i=0;i<N; i++){
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        
        sort(jobs.begin(), jobs.end(),  fn);
        
        
        /*for(auto ele: jobs){
            cout<<ele.start<<" "<<ele.end<<" "<<ele.profit<<endl;
        }*/
        
        vector<int> memo(N, -1);
        
        return dfs(0, jobs, memo);
        
    }
};