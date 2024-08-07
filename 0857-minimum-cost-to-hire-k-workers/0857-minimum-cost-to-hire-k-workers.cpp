

class Solution {
public:
    
    double method1(vector<int>& quality, vector<int>& wage, int k) {
        
        
        /*
            TC: O(N) * ( O(N) + O(NlogK) )
            
                O(N^2) + O(N^2 logK)
        */
        
        int N = quality.size();
        double minSum  = 1e9;
        
        for (int idx = 0; idx<N; idx++){
            
            double ratio =  (double)wage[idx] / quality[idx];
            
            vector<double> offer;
            priority_queue<double> mxHeap;
            double totalSum = 0.0;
            int ctr = 0;
            for(int i=0; i<N; i++){
                
                double expectedWage = quality[i] * ratio;
                
                if(expectedWage >= wage[i]){
                    ctr++;
                    offer.push_back(expectedWage);
                
                    if(mxHeap.size() < k){
                        mxHeap.push(expectedWage);
                        totalSum +=expectedWage;
                    }else{
                        
                        if(expectedWage < mxHeap.top() ){
                            
                            totalSum -= mxHeap.top();
                            mxHeap.pop();
                            mxHeap.push(expectedWage);
                            totalSum +=expectedWage;
                        }
                    }
                
                }//if
            }
            
            
            /*Cannot process this scheme with 'idx' as base since less than k worker will be able to get paid
            */
            if(ctr <k)
                continue;    
            else{
                //check if its the min total wage
                minSum  = min(totalSum, minSum);
            }//else
            
            
        }//for idx
        
        
        return minSum;
        
    }
    
    
    struct CompareFn{
            bool operator()( double &a, double &b){
                return a<b; //smallest first
            }
    };

    struct Workers{
      
        int wage;
        int quality;
        
        Workers(int w, int q){
            wage = w;
            quality =q;
        }
    };
    
    double method2(vector<int>& quality, vector<int>& wage, int k){
        
        int N = quality.size();
        
        vector<Workers> sortedRatio;
        for(int i=0; i<N; i++)
            sortedRatio.push_back(Workers(wage[i], quality[i]));
        
        
        //sort(sortedRatio.begin(), sortedRatio.end(), CompareFn);
        sort(sortedRatio.begin(), sortedRatio.end(), []( Workers &a, Workers &b){
            return ((double)a.wage/a.quality) < (double)b.wage/b.quality ;
        });
        //ascending as per wage per Quality ratio
        
        /*
        cout<<"N= "<<N<<endl;
        for(int i=0; i<N; i++){
            cout<<sortedRatio[i].wage<<" "<<sortedRatio[i].quality<<" = "<<sortedRatio[i].wage/sortedRatio[i].quality<<endl;
        }
        
        cout<<endl;
        */
        int runningQualitySum =0;
        priority_queue<double> mxHeap;  // keep the min k Quality
        double minCost = 1e9;
        
        for(int i=0; i<k; i++){
            runningQualitySum += sortedRatio[i].quality;
            mxHeap.push(sortedRatio[i].quality);
        }
        
        //cout<<((double)sortedRatio[k-1].wage/sortedRatio[k-1].quality)<<endl;
        minCost = runningQualitySum *  ((double)sortedRatio[k-1].wage/sortedRatio[k-1].quality);
        //cout<<"minCost: "<<minCost<<" running Sum: "<<runningQualitySum<<endl;
        for(int i=k; i<N; i++){
            
            if(!mxHeap.empty() && sortedRatio[i].quality < mxHeap.top()){
                
                 runningQualitySum-= mxHeap.top();
                 mxHeap.pop();
                
                 runningQualitySum += sortedRatio[i].quality;
                 mxHeap.push(sortedRatio[i].quality);
                
            }
            
            minCost = min(minCost, runningQualitySum *  ((double)sortedRatio[i].wage/sortedRatio[i].quality));
            
             
            
        }
        
        
        
        return minCost;
        
        /*
        for(Workers ele: sortedRatio){
            
            double ratio = (double)ele.wage/ele.quality;
            
            runningSum += ele.quality;
            mxHeap.push(ele.quality);
            
            if(mxHeap.size() >k){
                runningSum -= mxHeap.top();
                mxHeap.pop();
            }
            
            
            //cout<<runningSum<<" * "<<ratio<<" = "<<runningSum * ratio<<endl;
            if(mxHeap.size()  == k){
                ans = min(ans, runningSum * ratio);
                //cout<<"ans ="<<ans<<endl;
            }
        }//for
        
        
        
        return ans;
        */
        
    }
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        /*
            BRUTE FORCE:
            
            Basically calculate the ratio for each worker:
            i.e. cost of 1 Quality.
            
            Basically , choose a ratio, and using that ration calcluate the wages for every worker
            for their Quality
            
            For every ratio chosen and every wages calcluated:
            
            choose the smalles k calculated ACCEPTED wages
            
            MIN(
            (q1.R1 + q2.R1 + q3.R1 +...+ qk.R1 ),
            (q1.R2 + q2.R2 + q3.R2 +...+ qk.R2 ),
            (q1.R3 + q2.R3 + q3.R3 +...+ qk.R3 ),
            ...
            ...
            (q1.R4 + q2.R4 + q3.R4 +...+ qk.R4 ) )
        
            offeredWage[x] >= ExpectedWage[x]
            quantity[x] * ratio[captain] >= ExpectedWage[x]
            
            ratio[captain] >= ExpectedWage[x] / quantity[x]
            
            ratio[captain] >= ratio[x]
            
            So, thee wages will be decides by  the ratio selected,
            so if the ratio select is lesser than any worker's ratio,
            it will not meet its expected Salaray.
            
            So for a given ratio, workers with higher ratio cannot be 
            accepted, the select ratio will work wit people with less ratio.
            
            For all those with leser ratio,
            choose the minimuk k Quality, since we need to find minnimum Wage.
        */
        
        
        
        //Method1 - Brute Force
        //return method1(quality, wage, k);
        
        //method2 - Heap
        return method2(quality, wage, k);
        
    }
};