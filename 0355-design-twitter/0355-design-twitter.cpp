class Twitter {
    
    
    unordered_map<int, unordered_set<int> > followList;
    unordered_map<int, list< pair<int, int> >> userPosts;
    
    //map of iterator , pointer to the last tweet of each user
    unordered_map<int, list< pair<int, int> > ::iterator> itrList;
    
    int tstamp;
public:
    Twitter() {
        
        tstamp =0;
    }
    
    void postTweet(int userId, int tweetId) {
        
        userPosts[userId].push_front({tstamp, tweetId});
        
        //Increase the timestamp
        tstamp++;
        
        //update the pointer to the fron tof the list
        itrList[userId] = userPosts[userId].begin();
    }
    
    vector<int> getNewsFeed(int userId) {
        
         followList[userId].insert(userId);
        
        //auto comp = [](pair <int, int> a, pair<int, int> b){ return a.first > b.first; };
        
        auto comp = []( pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
            return a.second.first < b.second.first;
        };
        
        
        /*
        
        0 ......4......8......9..........34......|   minHeap|.....67..........101
        */
        
        //tstamp, tweetId
        priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >> , decltype(comp)> minHeap(comp);
        
        //Indicates if all teh timelines from where the tweets should be fetched, are exhausted
        bool allDone = false;
        int doneCount =0;
        
         int N = followList[userId].size();
        
        //cout<<"follows "<<N<<" people ... "<<endl;
        
        for(int userID: followList[userId]){
        
             itrList[userID] = userPosts[userID].begin() ;
            
            if ( itrList[userID] == userPosts[userID].end() ){
                doneCount++;
                
                if (doneCount == N) allDone = true;
            }else{
            
                minHeap.push( { userID,  { (*itrList[userID]).first, (*itrList[userID]).second }  } );
                
                itrList[userID]++;
            }
            
            
        }//for
        
       // cout<<"size:: "<<minHeap.size()<<endl;
        
        vector<int> ans;
        
        followList[userId].erase(userId);
        
        while(allDone == false){
            
            
            int userID = minHeap.top().first;
            ans.push_back( minHeap.top().second.second);
            
            if (ans.size() ==10 )
                return ans;
            
            minHeap.pop();
            
            
            if ( itrList[userID] == userPosts[userID].end() ){
                doneCount++;
                
                if (doneCount == N)
                    allDone = true;
            }else{
            
                minHeap.push( { userID,  { (*itrList[userID]).first, (*itrList[userID]).second }  } );
                itrList[userID]++;
            }
            
            
        }//while
        
        
            
        while(!minHeap.empty()){
            ans.push_back( minHeap.top().second.second);
        }


        //reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        
        //x follows y
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        //x unfollow y
        followList[followerId].erase(followeeId);
    }
};


/*
    
        Approach 1:
        
        follows[2] => [users who follow 2]
        
        feed[2] => [feed for userId 2]
        
        
        follow(): 
            x-follows-->y
        
        follows[y] => [.., x]   => O(1) , via set
        
        unfollow():
            x--unfollows--y
        
            follows[y] => [...] , remove x  -> O(1), via set

            feed[x] => remove post from y -> O(LFeed) , linear
            
        getFeed():
        
            retrun feed[x]
            
        postTweet():
        
            every users who follow (x):
                
                feed[user] <- add post[x] -> O(Lenfollowers * 1)
                
        
        
        Approach 2:
        
        user[1] => [users followed by 2]
        
        postBy[1] -> [posta made by user 1]
        
        follow():
            x--folows-->y
            
            user[x] => add y
            
        unfollow():
            x---unfollows--->y
            user[x] => remove y
            
        post():
        
            postby[x] => add post by x
            
            
        getFeed():
        
            get users followed by x
            
                get 10 recent post from a list of post of N users
                
                O(10logN)
                
                user x follows :    1, 4, 6, 7
                    Userpost[1] -> ordered by time/creation (ascending)
                    Userpost[4]
                    Userpost[6]
                    Userpost[7]
                    
                    Make a Heap of size 4,
                    
                    pull a recent tweet 10 times.
                    
                    
*/


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */