#define pi pair<int, int>

class Solution {

    static bool cmp(pi p1, pi p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<pi> v;

        for(int i=0; i<value.size(); i++){
            v.push_back({limit[i], value[i]});
        }

        sort(v.begin(), v.end(), cmp);
        // for(auto it : v){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }

        long long ans = 0;
        int cnt = 0;
        int cur = 0;

        for(int i=0; i<v.size(); i++){
            if(v[i].first != cur){
                cnt = 1;
                ans += v[i].second;
                cur = v[i].first;
            }
            else if(v[i].first == cur){
                if(cnt < v[i].first){
                    // cout<<cnt<<' '<<v[i].first<<endl;
                    cnt++;
                    ans += v[i].second;
                }
            }
        }

        return ans;
    }
};