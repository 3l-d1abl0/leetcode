class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int N=tasks.size();
        vector<vector<int>> available_tasks;
        
        for(int i=0; i<N; i++){
            available_tasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(available_tasks.begin(), available_tasks.end(), [](vector<int> &a, vector<int> &b){
            
                if(a[0]==b[0])
                    return a[1]<b[1];//acending by processin gtime, if start time is Same
                else
                    return a[0]<b[0];//ascending by enque time
            
        });
        
        
        // for(auto row: available_tasks){
        //     cout<<row[0]<<", "<<row[1]<<"  "<<row[2]<<endl;
        // }
        
        auto comp = [](const vector<int> &a, const vector<int> &b){
            
            if(a[1]==b[1])  //same duration
                return a[2] > b[2]; //earlier start time, if same duration
            return a[1] > b[1]; //asc duration
            
        };
        
        //minHeap - waiting Queue
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> waiting(comp);
        //startTime, processTime, Index
        
        int i =0;
        vector<int> ans;
        long long int current_time =1;
        
        
        for(int i=0; i<N || !waiting.empty();){
            
            
            
            //fetch the tasks which are available and place them in the waiting Queue
                
                while(i<N && available_tasks[i][0]<=current_time){
                    waiting.push(available_tasks[i]);
                    //cout<<"pushing :: "<<available_tasks[i][0]<<" "<<available_tasks[i][1]<<" "<<available_tasks[i][2]<<endl;
                    i++;
                        
                }
                
            
            
            //process the task from waiting queue and update time
            if(!waiting.empty()){
                
                
                int index = waiting.top()[2];
                ans.push_back(index);
                
                current_time += waiting.top()[1];
                
                waiting.pop();
               
                
            }else{
                current_time = available_tasks[i][0];
            }
            
            //cout<<"CT: "<<current_time<<"::"<<i<<endl;
        }//for

                
        return ans;
    }
};