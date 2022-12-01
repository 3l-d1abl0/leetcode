struct Endpoint {
    int val, load;
    bool isStart;
};
 
// custom comparator function which is used by the c++ sort stl
bool comp(const Endpoint& a, const Endpoint& b) {
    if (a.val != b.val)
        return a.val < b.val;
    //prioratize departing time
    return a.isStart == false && b.isStart == true;
}

bool func(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
}


struct Endp {
    int end, cap;
};

/*bool custom(Endp const& a, Endp const &b) {
    return a.end < b.end;
}*/


struct custom {
		constexpr bool operator()( Endp const& a, Endp const& b) const noexcept{
			return a.end > b.end;	//min//asc
		}
};




class Solution {
public:
    
    bool method1(vector<vector<int>>& trips, int capacity){
        
        int N = trips.size();
        if(N==0)
            return 0;
        
          int count = 0; // count will contain the count of current loads
          int result = 0; // result will contain maximum of all counts

          // this data array will contain all the endpoints combined with their load values
          // and flags telling whether they are starting or ending point
        vector<Endpoint> data;

        for (int i = 0; i < N; i++) {
            data.emplace_back(Endpoint{ trips[i][1], trips[i][0], true});//from
            data.emplace_back(Endpoint{ trips[i][2], trips[i][0], false});//to
        }

        sort(data.begin(), data.end(), comp);

        for (int i = 0; i < data.size(); i++) {
            if (data[i].isStart == true) {
                count += data[i].load;
                result = max(result, count);
            }
            else
                count -= data[i].load;

            //cout<<"i= "<<i<<endl;
        }

        return result<=capacity;
        
    }
    
    bool method2(vector<vector<int>>& trips, int capacity){
        
        int N = trips.size();
        if(N==0)
            return 0;
        
        sort(trips.begin(), trips.end(), func);
        
        priority_queue<Endp, vector<Endp>, custom> pq;
        
        int cap =1;
        int load = trips[0][0];
        int maxxLoad = load;
        
        Endp obj = {trips[0][2], trips[0][0]};
        pq.push(obj);
        
        for(int i=1; i<N; i++){
            //cout<<"i= "<<i<<endl;
            //cout<<trips[i][1]<<"  "<<pq.top().end<<endl;
            /*if(trips[i][1] < pq.top().end){ // need new seat
                cap++;
                load += trips[i][0];
            }else*/
            
            while(!pq.empty() && pq.top().end<= trips[i][1]){
                load -= pq.top().cap;
                pq.pop();
            }
            
            load += trips[i][0];
            pq.push({trips[i][2], trips[i][0]});
            
            maxxLoad = max(maxxLoad, load);
            //cout<<"MaxLoad ="<<maxxLoad<<endl;
        }
        
        //cout<<maxxLoad<<" "<<capacity<<endl;
        return maxxLoad <=capacity;
    }
    
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        //uses dorting 
        //return method1(trips, capacity);
        
        //sort + priority Queue
        return method2(trips, capacity);
        
    }
};