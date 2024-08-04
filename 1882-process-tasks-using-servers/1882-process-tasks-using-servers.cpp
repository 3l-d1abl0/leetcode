class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        int N = servers.size();
        int M = tasks.size();
        
        
        vector<int> ans(M, 0);
        
        //available queue - weight, idx
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b){
            
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
            
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> available(comp); //minHeap
        
        
        //waiting Queue - freeTime, idx
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>> > waiting; //minHeap
        
        
        //Initailly , all the servers are vailable
        for(int i=0; i<N; i++){
            available.push({servers[i], i});
        }
        
        
        long currentTime =0;
        for(int time =0; time<M; time++){
            
            currentTime = max(static_cast<long>(time), currentTime);
            
            //if none of the servers are available, skp to the time where 1st server in Q becomes free
            if(available.empty())
                currentTime = waiting.top().first;
            
            //cout<<time<<" "<<currentTime<<endl;
            //chek if any servers got free
            while(!waiting.empty() && waiting.top().first <= currentTime){
                
                //int server_idx = static_cast<int>(info.second);
                available.push({servers[waiting.top().second], waiting.top().second});
                waiting.pop();
            }
            
            //get a free server
            auto freeServer = available.top();
            waiting.push({currentTime+tasks[time], freeServer.second});
            
            ans[time] = freeServer.second;
            
            available.pop();
        }
        
        
        return ans;
        
    }
};