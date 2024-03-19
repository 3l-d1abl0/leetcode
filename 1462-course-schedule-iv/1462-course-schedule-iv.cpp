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
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        /*
            Method1: Floyd Warshall
            Find if 2 nodes are reachable for each Pair
        */
        
        return method1(numCourses, prerequisites, queries);
        
        
    }
};