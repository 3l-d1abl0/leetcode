


class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& profits, vector<int>& capital) {
        
        /*
        
            1. find all the project which can be done with current capital
            2. from all the selected project, get the one with max Profit
            3. Get the profict from the selected project.
            
            recpear k times.
        */
        
        //capital, profit
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cap; //min  heap
        priority_queue< int > prof; //max
        
        int N = profits.size();
        for(int i=0; i<N; i++)
            cap.push({capital[i], profits[i]});    
        
        
        while(k--){
            
            while(!cap.empty() && cap.top().first <= W){
                prof.push(cap.top().second);
                
                cap.pop();
            }
            
            if(prof.empty())
                return W;
            /*
            Of all the projects that can be completed,
            get the one with max profit
            */
            W+= prof.top();
            prof.pop();
            
        }
        
        
        return W;
    }
};