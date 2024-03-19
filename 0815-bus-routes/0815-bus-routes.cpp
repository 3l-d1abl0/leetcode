class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source==target)
            return 0;
        
        //Stop ==> routes 
        unordered_map<int, vector<int>> getRoutes;
        
        int bus=0;
        for(auto route: routes){
            for(int stop: route)
                getRoutes[stop].push_back(bus);
            
            bus++;
        }
        
        /*for(auto node: getRoutes){
            cout<<node.first<<":: ";
            for(int stop: node.second)
                cout<<stop<<" ";
            
            cout<<endl;
        }*/
        
        queue<int> q;
        unordered_set<int> visitedBusRoute;
        
        //push all the stops that lies on source route
        for(int route: getRoutes[source]){
            
            for(int stop: routes[route]){  //get all the stops in th bus route
                
                if(visitedBusRoute.find(stop) == visitedBusRoute.end()){
                    q.push(stop);
                }
            }
            
            //entire route visited
            visitedBusRoute.insert(route);
            
        }
        
        int hop =0;
        while(!q.empty()){
            
            int sz = q.size();
            hop++;
            
            for(int i=0; i<sz; i++){
                
                int stop = q.front();
                q.pop();
                
                if(stop==target)
                    return hop;
                
                //push all the bus stops in the route that this stop is part of, for next hop
                for(int route: getRoutes[stop]){

                    if(visitedBusRoute.find(route) == visitedBusRoute.end()){
                        
                        for(int busStop: routes[route])  //get all the stops in th bus route
                                q.push(busStop);
                        
                        visitedBusRoute.insert(route);
                    }

                }//for get Routes
                
                
            }//for queue size
            
            
        }//while
        
        return -1;
        
    }
};