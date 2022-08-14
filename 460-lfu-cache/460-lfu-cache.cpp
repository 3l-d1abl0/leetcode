class LFUCache {
public:
  
    unordered_map <int,list<pair<int,int>>> lst_map;                    //will store frequency as key and list of all <key,value> with that frequency
    unordered_map <int,list<pair<int,int>>::iterator> key_map;          //will store key and it's respective address
    unordered_map <int,int> frequency_map;                              //will store key and it's frequency
    int cap=0,size=0,min_frequency=0;
    
    LFUCache(int capacity)
    {
        cap=capacity;
    }
    
    int get(int key) 
    {
      
        auto found= key_map.find(key);
        if(found==key_map.end())
            return -1;
        else
        {   auto temp = found->second->second;
            put(key,temp);
            return temp;
            
        }
    };
    
    void put(int key, int value) 
    {
        
        auto found = key_map.find(key);
        if(found== key_map.end()) 
        {   if(cap!=0)
            {  
            if(size>=cap)
            {                                                    //removing page
               auto temp = lst_map[min_frequency].back();        //making copy of popped element
               lst_map[min_frequency].pop_back();                //popping it out
               key_map.erase(temp.first);                        //popping from key_map
               frequency_map.erase(temp.first);                  //popping from frequency_map;
                                                                 // done removing
            }
            else
                size++;
            lst_map[1].emplace_front(make_pair(key,value));      // adding node in list
            min_frequency=1;
            key_map[key]= lst_map[1].begin();                    // adding new key iterator pair in key map
            frequency_map[key]=1;
            
        }
        }
        else
        {
            auto frequency = frequency_map[key];
            lst_map[frequency].erase(found->second);             //removed from old list
            if(lst_map[frequency].size()==0)                     //in case list becomes empty it might change min_frequency
            {
                if(min_frequency ==frequency)
                    min_frequency++;
            }
            lst_map[++frequency].emplace_front(key,value);       //added in new list
            key_map[key]=lst_map[frequency].begin();             //updated in keymap
            frequency_map[key]=frequency; 
            
        }
    }
    
};