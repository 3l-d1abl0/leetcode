class Solution {
public:
    
    int recursion(int dayIndex, vector<int> &days, vector<int> &costs, vector<int> &memo){
  
        if(dayIndex >= days.size())
            return 0;
        
        
        if(memo[dayIndex]!=-1)
            return memo[dayIndex];
        
        //cout<<dayIndex<<endl;
        int currentDay = days[dayIndex];
        int currentIdx = dayIndex;
        
        //Try the 1-day pass - skip the days which can be covered
        while(currentIdx< days.size() && days[currentIdx]<currentDay+1)
           currentIdx++;
        
        //cout<<"1: "<<currentIdx<<" ";
        int day1Cost = costs[0]+ recursion(currentIdx, days, costs, memo);
        
        currentIdx = dayIndex;
        //Try the 7-day pass - skip the days which can be covered
        while(currentIdx< days.size() && days[currentIdx]<currentDay+7 )
            currentIdx++;
        
        //cout<<"2: "<<currentIdx<<" ";
        int day7Cost = costs[1]+ recursion(currentIdx, days, costs, memo);
        
        
        
        currentIdx = dayIndex;
        //Try the 30-day pass - skip the days which can be covered
        while(currentIdx< days.size() && days[currentIdx]<currentDay+30)
            currentIdx++;
        
        //cout<<"3: "<<currentIdx<<" ";
        int day30Cost = costs[2]+ recursion(currentIdx, days, costs, memo);
        
        
        memo[dayIndex]=min({day1Cost, day7Cost, day30Cost});
        //cout<<dayIndex<<":: "<<dayIndex+1<<" , "<<currentIdx<<" :: "<<day1Cost<<" "<<day30Cost<<endl;
        return memo[dayIndex];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> memo(days.size(), -1);
        
        return recursion(0, days, costs, memo);
        
    }
};