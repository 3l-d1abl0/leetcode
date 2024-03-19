class Solution {
public:
    
    vector<bool> method1(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adjMat(numCourses, vector<int> (numCourses, INT_MAX));
        
        //i - i reachable
        for(int i=0; i<numCourses; i++)
            adjMat[i][i]=1;
        
        //node1-node2 reachable
        for(auto edge: prerequisites){
            adjMat[edge[0]][edge[1]]=1;
        }
        
        for(int via=0; via<numCourses; via++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    
                    if(adjMat[i][via]== INT_MAX || adjMat[via][j]==INT_MAX)
                        continue;
                    
                    adjMat[i][j] =1;
                    
                }
            }
        }
        
        
        vector<bool> ans;
        for(auto q: queries){
            
            if( adjMat[q[0]][q[1]] ==1)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        
        return ans;
    }
    
    vector<bool> method2(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        
        //adjecency List
        vector<vector<int>> adjMatrix(numCourses, vector<int>(numCourses, false));
        
        //Create Indegree and adj list
        for(auto row: prerequisites){
            adj[row[0]].push_back(row[1]);
            
            indegree[row[1]]++;
            
            adjMatrix[row[0]][row[1]]=true;
        }
        
        queue<int> q;
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(int neigh: adj[node]){
                
                
                //node --> neigh
                for(int i=0; i<numCourses; i++){
                    if(adjMatrix[i][node] == true)
                        adjMatrix[i][neigh] =true;
                }
                
                indegree[neigh]--;
                
                if(indegree[neigh]==0)
                    q.push(neigh);
            }//for
            
            
        }//while
        
        vector<bool> ans;
        for(auto row: queries){
            if(adjMatrix[row[0]][row[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        
        return ans;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        /*
            Method1: Floyd Warshall
            Find if 2 nodes are reachable for each Pair
            TC: O(N^3)
            134ms
        */
        
        //return method1(numCourses, prerequisites, queries);
        
        /* TOPOSORT
            when processing neighbours of 0 indegree
            
            0indegreeNode --> other node
            
            check how manu other node connects with oindegree
            
            connect those nodes with the neightbours
            151ms
        */
        return method2(numCourses, prerequisites, queries);
    }
};