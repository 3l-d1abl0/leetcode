class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        /*
            1. start, end at same point --> start gets prefrence
            2. start, start at same point --> greater val gets prefrence
            3. end, end at same point --> smaller get prefrence

            basically, look for change in max Height on any bounday
        */

        vector<tuple<char, int, int>> points;   //s/e, x, h
        for(auto b: buildings){
            points.push_back(make_tuple('s', b[0], b[2]));
            points.push_back(make_tuple('e', b[1], b[2]));
        }

        //sort the edges by the rules
        sort(points.begin(), points.end(), [](const tuple<char, int, int> &a, const tuple<char, int, int> &b){
                
                if(get<0>(a) == get<0>(b) && get<0>(a)=='s' && get<1>(a)==get<1>(b))//both start at same Point
                    return get<2>(a)>get<2>(b); //greater first

                if(get<0>(a) == get<0>(b) && get<0>(b)=='e'&& get<1>(a)==get<1>(b))   //both end at the same Point
                    return get<2>(a)<get<2>(b); //smaller first

                if(get<0>(a) != get<0>(b) && get<1>(a)==get<1>(b)) //start, end same point
                    return get<0>(a) =='s';


                return get<1>(a)<get<1>(b);//first come, first serve

        });

        //since need to pop eleents, use multiset
        multiset<int, greater<int>> pq{0};

        int currentMaxHeight = 0;
        vector<vector<int>> ans;
        for(auto [edge, point, height]: points){

            cout<<edge<<" "<<point<<" "<<height<<endl;
            if(edge =='s'){
                if(height > *pq.begin())    //new Heights
                    ans.push_back({point, height});

                pq.insert(height);
            }else{
                if(height == *pq.begin()){  //if the current building is the highest, there will be a Drop
                    pq.erase(pq.find(height));
                    
                    if(height> *pq.begin())  //drop
                        ans.push_back({point, *pq.begin()});
                }else
                    pq.erase(pq.find(height));
            }
        }//


        return ans;


    }
};