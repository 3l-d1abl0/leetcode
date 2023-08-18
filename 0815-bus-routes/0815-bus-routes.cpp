class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        int N =1e6;
        
        //Stores for every bus-stop, the routes it belongs to
        vector<vector<int>> giveRoutes(N, vector<int>());
        
        for(int i=0; i<routes.size(); i++){
            
            int routeNo = i;
            
            for(int j=0; j<routes[routeNo].size(); j++){
                
                int busStop = routes[routeNo][j];
                
                giveRoutes[busStop].push_back(routeNo);
                
            }
            
        }//for
        
        
        if(source==target){
            return 0;
        }
        
        vector<bool> visitedStop(N, false);
        vector<bool> visitedRoutes(N, false);
        
        //stop and hops to reach there
        queue< pair<int, int>> q;
        q.push({source, 0});
        
        visitedStop[source] =true;
        
        
        while(!q.empty()){
            
            
            int busStop = q.front().first;
            int hop = q.front().second;
            
            q.pop();
            
            if(busStop==target)
                return hop;
            
            
            for(int i=0; i<giveRoutes[busStop].size(); i++){
                
                int routeNo = giveRoutes[busStop][i];
                
                
                //Skip if this route has been visited
                if(visitedRoutes[routeNo]==true)
                    continue;
                
                visitedRoutes[routeNo]=true;
                
                //visit all bus Stop in thi sRoute
                for(int idx=0; idx<routes[routeNo].size(); idx++){
                    
                    int nxtBusStop = routes[routeNo][idx];
                    
                    //Skip if this bus Stop has been visited
                    if(visitedStop[nxtBusStop]==true)
                        continue;
                    
                    visitedStop[nxtBusStop]=true;
                    
                    
                    q.push({ nxtBusStop, hop+1 });
                }//for idx
                
                
            }//for i
            
            
            
        }//while q
        
        
        return -1;
    }
};