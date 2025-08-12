#define ll long long
#define mod 1000000007

class Solution {
    ll f(ll n){
        return ((n * ((n+1)%mod))%mod)/2;
    }
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;  // y axis cnt
        vector<ll> v;
        vector<ll> sum;

        for(auto it : points){
            int x = it[0], y = it[1];
            mp[y]++;
        }

        for(auto it : mp){
            // cout<<it.second<<endl;
            v.push_back(it.second-1);
        }

        sort(v.begin(), v.end());

        for(int i=0; i<v.size(); i++){
            sum.push_back(f(v[i]));
        }

        vector<ll> pre(v.size());
        pre[0] = sum[0];

        for(int i=1; i<pre.size(); i++){
            pre[i] = (pre[i-1] + sum[i])%mod;
        }

        int n = pre.size();
        for(int i=0; i<n; i++){
            // cout<<v[i]<<' '<<sum[i]<<' '<<pre[i]<<endl;
        }

        ll cnt = 0;

        for(int i=0; i<n-1; i++){
            cnt = (cnt + (sum[i]*(pre[n-1]-pre[i]))%mod)%mod;
        }

        return cnt;
    }
};