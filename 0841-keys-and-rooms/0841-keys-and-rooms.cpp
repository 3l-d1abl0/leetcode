class Solution {
public:
    
    bool dfs(vector<vector<int>> &rooms, int node, unordered_set<int> &keys, unordered_set<int> &visited){
        
        visited.insert(node);
        
        if(rooms.size() ==  visited.size())
            return true;
        
        //collect the keys
        for(int k: rooms[node])
            keys.insert(k);
        
        
        //iterate through the keys
        for(int n: keys){
            
            //not yet visited
            if(visited.find(n) == visited.end()){
                if (dfs(rooms, n, keys, visited) )
                    return true;
            }
        }
        
        return false;
    }
    
    bool method1(vector<vector<int>> &rooms){
        
        int N = rooms.size();
        
        unordered_set<int> keys;
        unordered_set<int> visited;
        
        return dfs(rooms, 0, keys, visited);
            
        //return false;
    }
    
    bool method2(vector<vector<int>> &rooms){
        
        unordered_set<int> visited;
        queue<int> q;
        
        q.push(0);
        
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            visited.insert(node);
            
            
            if(visited.size() == rooms.size())
                return true;
            
            for(int k: rooms[node]){
                
                
                if(visited.find(k) == visited.end())
                    q.push(k);
            }
            
        }//while
        
        
        return false;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        //method1: DFS
        //return method1(rooms);
        
        
        //method2: BFS
        return method2(rooms);
    }
};