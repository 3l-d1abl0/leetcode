class Solution {
public:
    
    bool static comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int rec(int idx, int start, vector<vector<int>> &courses, vector<vector<int>> &memo){
        
        
        if(idx>=courses.size()){
            return 0;
        }
        
        if(memo[idx][start] !=-1)
            return memo[idx][start];
        
        int ans =0;
        //1. Include
        if(start+courses[idx][0]<=courses[idx][1]){
            ans = 1+rec(idx+1, start+courses[idx][0], courses, memo);
        }
        
        //2.Exclude
        ans = max(ans, rec(idx+1, start, courses, memo));
        
        
        return memo[idx][start] = ans;
    }
    
    
    int method1(vector<vector<int>>& courses){
        
                int N= courses.size();
        
        sort(courses.begin(), courses.end(), comp);
        /*for(auto row: courses){
            cout<<row[0]<<" "<<row[1]<<endl;
        }*/
        
        vector<vector<int>> memo(N, vector<int> (courses[N-1][1], -1));
        
        int idx=0, start=0;
        return rec(idx, start, courses, memo);
        
    }
    
    
    int method2(vector<vector<int>>& courses){
        
        int N = courses.size();
        
        sort(courses.begin(), courses.end(), comp);
        
        priority_queue<int> pq;
        
        int totalDuration =0;
        for(auto row: courses){
            
            if(totalDuration+row[0]<=row[1]){
                pq.push(row[0]);
                totalDuration += row[0];
            }else{
                
                if(!pq.empty() && pq.top() > row[0]){
                    totalDuration -=pq.top(); pq.pop();
                    pq.push(row[0]);
                    totalDuration += row[0];
                }
                
            }
        }//for
        
        return pq.size();
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        
        //return method1(courses);
        
        return method2(courses);    
    }
};