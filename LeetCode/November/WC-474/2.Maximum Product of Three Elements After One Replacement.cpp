Just Brute Force Approch tried and got TLE. 

  class Solution {
public:
    const int MOD=1e5; 
    long long maxProduct(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        const long long INF = 1000000LL; // safer than 1e9

        for (int i = 0; i < n; i++) {
            vector<int> jabir = nums;
            jabir[i] = 1000000;

            sort(jabir.begin(), jabir.end());
            long long first = 1LL * jabir[n - 1] * jabir[n - 2] * jabir[n - 3];
            long long second = 1LL * jabir[0] * jabir[1] * jabir[n - 1];
            ans = max(ans, max(first, second));

            // Reset and test negative extreme
            jabir = nums;  
            jabir[i] = -1000000;

            sort(jabir.begin(), jabir.end());
            first = 1LL * jabir[n - 1] * jabir[n - 2] * jabir[n - 3];
            second = 1LL * jabir[0] * jabir[1] * jabir[n - 1];
            ans = max(ans, max(first, second));
        }

        return ans/10;
    }
};

TLE : 
TC : O(N^2LOGN) 
SC : O(N) 
==========================================================================================================================================================================
