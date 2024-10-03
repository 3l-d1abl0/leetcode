class Solution {
    public int minFlips(String s) {
        int n = s.length();
        // 110
        // 110110
        s = s+s;
        char p[] = s.toCharArray();
        char a[] = new char[n+n];  // 1010101
        char b[] = new char[n+n];  // 0101010
        for (int i=0 ; i<n+n ; i++) {
            a[i] = (i%2 == 0) ? '1' : '0';
            b[i] = (i%2 == 0) ? '0' : '1';
        }
 
        int ans = 9999999;
        int first = 0 , second = 0;
        for (int i=0 ; i<n+n ; i++) {
            if ( a[i] != p[i] )
                ++first;
            if ( b[i] != p[i] )
                ++second;
 
            if ( i>=n ) {
                if ( a[i-n] != p[i-n] ) --first;
                if ( b[i-n] != p[i-n] ) --second;
            }
 
            if ( i>=n-1 )
                ans = Math.min( ans , Math.min(first , second) );
        }
        return ans;
    }
}
