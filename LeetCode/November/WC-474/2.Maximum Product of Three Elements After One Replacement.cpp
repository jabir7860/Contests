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
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(abs(nums[i]) > max1)
            {
                max2 = max1;
                max1 = abs(nums[i]);
            }
            else if(abs(nums[i]) > max2) max2 = abs(nums[i]);
        }

        return (long long) max1 * max2 * 100000;
    }
};

Approach : Largest Two Elements * 10^5 

TC : O(N) 
SC : O(1) 
