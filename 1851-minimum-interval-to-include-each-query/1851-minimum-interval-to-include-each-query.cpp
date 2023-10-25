class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });
        
        vector<pair<int, int>> qi;
        for(int i=0; i<queries.size(); i++)
            qi.push_back({queries[i], i});
        sort(qi.begin(), qi.end());
        
        //auto comp = []( pair<int, int> a, pair<int, int> b ) { return a.second > b.second; };
        
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b){
            
            if((a.second -a.first) == (b.second - b.first))
                return a.first > b.first;

            
            return (a.second -a.first) > (b.second - b.first); //smallest first
            
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp); //Min Queue
        
        
        vector<int> ans(qi.size());
        int N = intervals.size();
        
        
        int i=0; 
        for(auto pp: qi){
        
            int minn = INT_MAX;
            
            while(i<N && intervals[i][0]<= pp.first){
                pq.push({intervals[i][0], intervals[i][1]});
                //cout<<"<-- "<<intervals[i][0]<<"  , "<<intervals[i][1]<<endl;
                i++;
            }
            
            
            //pop out the ranges which ends before the Query
            while(!pq.empty()  && pp.first > pq.top().second){
                //cout<<"--> "<<pq.top().first<<"   "<<pq.top().second<<endl;
                pq.pop();
            }
            
            
            ans[pp.second] = pq.empty()?-1:(pq.top().second - pq.top().first)+1;
            //cout<<pq.top().first<<"  ---- "<<pq.top().second<<" = "<<(pq.top().second - pq.top().first)+1;
            //cout<<"--------------------"<<endl;
        }
        
        
        
        return ans;
    }
};