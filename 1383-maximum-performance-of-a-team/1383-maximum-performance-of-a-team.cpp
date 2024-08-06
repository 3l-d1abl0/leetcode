class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<vector<int>> workers;
        for(int i=0; i<n; i++){
            workers.push_back({efficiency[i], speed[i]});
        }
        
        sort(workers.begin(), workers.end(), [](vector<int> &a, vector<int> &b){
            return a[0]>b[0];   //sort by descending Order of Effeciecy
        });
        
        
        long speedSum =0;
        long maxE = LONG_MIN;
        long product;
        priority_queue<int, vector<int>, greater<int>> minHeapSpeed;
        
        //prepare the first k size window
        for(int i=0; i<k; i++){
            
            speedSum +=workers[i][1];
            minHeapSpeed.push(workers[i][1]);
            
            product= 1LL*speedSum * workers[i][0];
            maxE= max(maxE, product);
            
        }
        
        
        for(int i=k; i<n; i++){
            //the new speed is smaller than the smallest speed in the heap
            if(workers[i][1] > minHeapSpeed.top()){
                
                speedSum += (workers[i][1] - minHeapSpeed.top());
                minHeapSpeed.pop();
                minHeapSpeed.push(workers[i][1]);
                
                product= 1LL*speedSum * workers[i][0];
                maxE= max(maxE, product);
                
            }
        }
        
        
        return (int)(maxE%1000000007);
        
    }
};