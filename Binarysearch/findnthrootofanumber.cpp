class Solution {
public:
    // returns mid^n compared to m, capped to avoid overflow
    int compare(int mid, int n, int m){
        long long ans = 1;
        for(int i = 1; i <= n; i++){
            ans *= mid;
            if(ans > m) return 1; // mid^n > m
        }
        if(ans == m) return 0;
        return -1; // mid^n < m
    }

    int NthRoot(int N, int M) {
        int low = 1, high = M;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cmp = compare(mid, N, M);
            if(cmp == 0) return mid;
            else if(cmp == 1) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};
