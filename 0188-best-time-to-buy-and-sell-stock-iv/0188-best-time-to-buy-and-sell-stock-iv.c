
int max(int a, int b){
    
    if(a > b)
        return a;
    
    return b;
}

int maxProfit(int k, int* price, int n){

    if(k==0 || n ==0)
        return 0;
    
    int profit[k + 1][n];

    //No transaction on 0th day, so profit 0
    for (int i = 0; i < n; i++)
        profit[0][i] = 0;

    //no profit with just one price
    for (int i = 0; i <=k; i++)
        profit[i][0] = 0;

    for (int i = 1; i <=k; i++)
    {
        int max_profit = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            //selling at jth Day
            max_profit = max(max_profit, profit[i - 1][j - 1] - price[j - 1]);
            profit[i][j] = max(profit[i][j - 1], price[j] + max_profit);
        }
    }

   
    return profit[k][n-1];
    
}