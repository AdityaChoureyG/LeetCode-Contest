#define ll long long

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prime(n+1, 0);

        ll sumA = 0, sumB = 0;
        prime[1] = prime[0] = 1;

        for(int i=2; i<prime.size(); i++){
            if(prime[i]==0){
                int j = i*2;
                int cnt = 3;
                while(j<prime.size()){
                    // cout<<j<<' ';
                    prime[j] = 1;
                    j = i*cnt;
                    cnt++;
                }
            }
        }

        // cout<<endl;

        for(int i=0; i<n; i++){
            // cout<<prime[i]<<' ';
            if(prime[i]==0){
                // prime indices
                sumA += nums[i];
            }
            else   sumB += nums[i];
        }

        return abs(sumA-sumB);
    }
};