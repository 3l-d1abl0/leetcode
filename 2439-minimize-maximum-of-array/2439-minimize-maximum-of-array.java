class Solution {

    public int minimizeArrayValue(int[] nums) {
        int s = 0, e = (int) 1e9;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ok(mid, nums)) {
                e = mid - 1;
                ans = mid;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    private boolean ok(int max, int a[]) {
        if (a[0] > max) return false;
        long prev = a[0], ex = 0;
        if (prev < max) ex = max - prev;
        for (int i = 1; i < a.length; i++) {
            if (a[i] > max) {
                long c = (long) (a[i] - max);
                if (c > ex) return false;
                prev = max;
                ex -= c;
            } else {
                ex += (long) (max - a[i]);
            }
            prev = a[i];
        }
        return true;
    }
}