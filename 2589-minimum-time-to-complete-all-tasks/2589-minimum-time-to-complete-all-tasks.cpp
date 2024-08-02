class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        
        
        //Sort tasks by deadline
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b){
            
            if (a[1]==b[1])
              return a[0]<b[0];
            
            return a[1]<b[1];
        });
        
        
        
        int ran =0;
        unordered_map<int, bool> cpu;
        
        
        for(auto task: tasks){
            
            int startTime = task[0];
            int endTime = task[1];
            int duration = task[2];
            
            //cout<<"task: "<<startTime<<" "<<endTime<<" "<<duration<<endl;
            
            //check for overlap with earlier task
            int idx = startTime;
            while(duration>0 && idx<=endTime){
                
                if(cpu[idx]==true){
                    duration--;
                    //cout<<idx<<", ";    
                }
                
                idx++;
                
            }
            
            //cout<<endl;
            
            //start placing tasks from the back
            idx = endTime;
            while(duration>0){
                
                //cout<<idx<<":: ";
                if(cpu[idx]==false){
                    duration--;
                    ran++;
                    cpu[idx]=true;
                }
                idx--;
                
            }
            
            //cout<<endl<<ran<<" ======= "<<endl;
        }//for
        
        return ran;
        
    }
};