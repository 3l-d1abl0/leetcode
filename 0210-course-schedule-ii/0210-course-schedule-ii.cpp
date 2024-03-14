class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*
            Prerequisite --> Course 
            Order: pre... course
            
            
            Course --> Prerequisite
            Order: course .. pre
        */
        
        vector<int> indegree(numCourses, 0);
        
        vector<vector<int>> adj(numCourses);
        
        for(auto row: prerequisites){
            
            indegree[row[1]]++;
            
            adj[row[0]].push_back(row[1]);
            
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        
        vector<int> ans;
        while(!q.empty()){
            
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(int it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            
        }//while
        
        /*for(int ele: ans)
            cout<<ele<<" ";*/
        
        //cout<<endl;
        if(ans.size()!= numCourses)
            return {};
        else{
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};