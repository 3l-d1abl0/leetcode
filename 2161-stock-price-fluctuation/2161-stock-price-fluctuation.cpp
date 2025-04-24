class StockPrice {

        pair<int, int> curr; //timestamp, price
        unordered_map<int, int> mapping;    //timesamp -> price
        multiset<int> orderedPrices; //asc

public:
    StockPrice() {
        

    }
    
    void update(int timestamp, int price) {
        
        cout<<"Update:: "<<timestamp<<" -> "<<price<<endl;

        if(mapping.find(timestamp) != mapping.end()){
            auto it = orderedPrices.find(mapping[timestamp]);
            if(it!=orderedPrices.end())
                orderedPrices.erase(it);
        }

        mapping[timestamp] = price;
        orderedPrices.insert(price);

        cout<<timestamp<<", "<<price<<" v/s "<<curr.first<<","<<curr.second<<endl;
        if(timestamp>= curr.first)
            curr = {timestamp, price};
        //else if(timestamp == curr.first)
        //    curr = {timestamp, max(price, curr.second)};
    }
    
    int current() {
        cout<<"current: "<<this->curr.second<<endl;
        return this->curr.second;
    }
    
    int maximum() {
        return *(orderedPrices.rbegin());
    }
    
    int minimum() {
        return *orderedPrices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */