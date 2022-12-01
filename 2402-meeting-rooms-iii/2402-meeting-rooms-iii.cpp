class Solution {
public:
    int mostBooked(int N, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());
        
        priority_queue<pair<long long int, int>, vector< pair<long long int, int>>, greater<pair<long long int, int>> > pq;
        
        int i=0;
        vector<int> rooms(N, 0);
        for(auto row: meetings){
            
            
            while(!pq.empty() && pq.top().first < row[0]){
                auto [end, idx] = pq.top();
                pq.pop();
                pq.push({row[0], idx}); // these are empty when seen at time row[0]
            }
            
            if(pq.empty()){
                pq.push({row[1], 0});
                rooms[0]++;
            }else{
                
                //at this point - heap should have ending >= row[0]
                
                if(pq.top().first <= row[0]){
                    int idx= pq.top().second;
                    pq.pop();
                    pq.push({row[1], idx});
                    rooms[idx]++;
                }else{
                    
                    //wait or take new
                    if(pq.size()==N){// no new roow, need to wait
                        
                        long long int delay = pq.top().first - row[0];
                        int idx = pq.top().second;
                        pq.pop();
                        pq.push({row[1]+delay, idx});
                        
                        rooms[idx++]++;
                    }else{
                        //take new Room
                        rooms[pq.size()]++;
                        pq.push({row[1], pq.size()});
                    }
                    
                }
                
                
            }
            
            /*
            if(i==0){ //no meeting rooms engaged
                
                pq.push({row[1], i});
                rooms[i]++;
                i++;
                
            }else{
                
                //end < start -> use this room
                if(pq.top().first <= row[0]){
                    int idx = pq.top().second;
                    pq.pop();
                    pq.push({row[1], idx});
                    rooms[idx]++;
                }else{
                    //end > start
                    if(i==N){ //NO rooms avail, wait
                        
                        int delay = pq.top().first - row[0];
                        int idx = pq.top().second;
                        pq.pop();
                        pq.push({row[1]+delay, idx});
                        rooms[idx]++;                        
                    }else{
                        //use new roow
                        pq.push({row[1], i});
                        rooms[i]++;
                        i++;    
                    }
                    
                }
                    
                
            }//else
            */
        }//for
        
        
        /*for(int i: rooms){
            cout<<i<<" ";
        }cout<<endl;*/
        
        
        //return max_element(begin(cnt), end(cnt)) - begin(cnt);
        //return lesser index, if multiple max
        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};