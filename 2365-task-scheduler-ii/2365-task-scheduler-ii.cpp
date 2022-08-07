class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
     
        
        long long int day =0;
        int N = tasks.size();
        
        unordered_map<int, int> mp; //taks_no => day
        for(int i=0; i<N; i++){
            
            day++;
            if(mp.find(tasks[i]) == mp.end()){   //day=1
                mp[tasks[i]] = day;
                //cout<<"i ="<<i<<" d="<<day<<endl;
            }else{
                int prev = mp[tasks[i]];
                int gap = day-prev-1;
                if(gap<space)
                    day += space-gap;
                
                mp[tasks[i]] = day;
                
                //cout<<prev<<"d= "<<day<<" i="<<i<<endl;
            }
               
        }
               
               
        return day;
    }
};