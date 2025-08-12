#define ll long long

class Solution {
    ll n;

    bool valid(ll len, vector<int>& v){
        // case for valid that has 
        // 1 if n is even no odd allowed
        if(len%2==0){
            for(auto it : v){
                if(it&1)  return 0;
            }
            return 1;
        }

        // if n is odd one odd allowed only
        bool od = false;
        for(auto it : v){
            if(it&1){
                if(od)  return 0;
                od = 1;
            }
        }

        return true;
    }
    void f(ll i, ll cur, int& len, vector<int>& temp, vector<vector<int>>& res){
        // cout<<i<<' '<<cur<<endl;
        if(i>=10 || i>cur){
            if(cur==0){
                if(valid(len, temp))   res.push_back(temp);
            }
            return;
        }

        f(i+1, cur, len, temp, res);

        if(i<=cur){
            temp.push_back(i);
            f(i+1, cur-i, len, temp, res);
            temp.pop_back();
        }
    }

    void generateCombi(int l, string t, vector<int>& freq, int& odd, vector<string>& listt){
        // cout<<l<<" l t "<<t<<endl;
        if(l==0){
            // cout<<t<<endl;
            if(odd != 0){
                string temp = t;
                reverse(temp.begin(), temp.end());
                t.append(to_string(odd));
                t.append(temp);
                // cout<<"temp "<<t<<endl;
                listt.push_back(t);
            }
            else{
                string temp = t;
                reverse(temp.begin(), temp.end());
                t.append(temp);
                // cout<<"temp "<<t<<endl;
                listt.push_back(t);
            }
            return;
        }

        for(int i=1; i<10; i++){
            if(freq[i]!=0){
                freq[i]--;
                t.append(to_string(i));
                generateCombi(l-1, t, freq, odd, listt);
                t.pop_back();
                freq[i]++;
            }
        }
    }


    void findnos(int len, vector<ll>& nums){
        vector<vector<int>> res;
        vector<int> temp;

        f(1, len, len, temp, res);

        for(int i=0; i<res.size(); i++){
            vector<int> freq(10, 0);
            int odd = 0;
            for(auto it : res[i])   {
                // cout<<it<<' ';
                freq[it] = it/2;
                if(it&1)  odd = it;
            }
            // cout<<"string generated"<<endl;
            vector<string> listt;
            generateCombi(len/2, "", freq, odd, listt);
            for(auto it : listt){
                // cout<<it<<endl;
                nums.push_back(stoll(it));
            }
            // cout<<endl;
        }
    }
public:
    long long specialPalindrome(long long n) {
        if(n==0)  return 1;
        if(n<10)   return 22;
        vector<ll> nums;
        // for(int i=1; i<18; i++){
        //     // cout<<"len is"<<i<<endl;
        //     findnos(i, nums);
        // }
        // cout<<nums.size()<<endl;
        // for(auto it : nums) cout<<it<<' ';

        string sn = to_string(n);

        findnos(sn.length(), nums);
        findnos(sn.length()+1, nums);

        // for(auto it : nums) cout<<it<<' ';

        sort(nums.begin(), nums.end());
        ll lo = 0, hi = nums.size()-1;
        
        while(lo<=hi){
            ll mid = lo + (hi - lo)/2;
            if(nums[mid] <= n){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return nums[lo];
    }
};