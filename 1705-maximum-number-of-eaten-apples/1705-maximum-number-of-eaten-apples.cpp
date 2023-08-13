struct CompareFn{
    
    bool operator()( pair<int, int> &n1, pair<int, int> &n2){
        
        if(n1.first == n2.first)
            return n1.second > n2.second; //less apples goes first
        
        return n1.first > n2.first;
    }
    
};

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        
        //exp-date, numbers
        priority_queue< pair<int, int>, vector<pair<int, int>>, CompareFn > minHeap;
        
        
        int count =0, apple=0;
        int idx =0, day =1;
        
        do{
            
            //1. Add apples
            if(idx < apples.size())
                minHeap.push({day+days[idx], apples[idx]});
            
            //2. exclude exipred apples
            while(!minHeap.empty() && minHeap.top().first <= day){
               // cout<<"Excluding ....on day= "<<day<<endl;
               // cout<<minHeap.top().first<<" "<<minHeap.top().second<<endl;
                minHeap.pop();
            }
            
            
            //3. take apple
            if(!minHeap.empty()){
                auto app = minHeap.top();
                minHeap.pop();

                if(app.second >1){
                    minHeap.push({app.first, app.second-1});
                }
                apple++;
            }
            
            //cout<<"day ="<<day<<"apples eaten = "<<apple<<endl;
            idx++;
            day++;
            
        }while(!minHeap.empty() || idx < apples.size()); //while
        
        
        return apple;
        
    }
};