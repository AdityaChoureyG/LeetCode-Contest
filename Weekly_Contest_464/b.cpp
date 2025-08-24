class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int group;

        if(n%k!=0)  return false;

        group = n/k;

        for(auto it : nums)   mp[it]++;

        for(auto it : mp){
            if(it.second > group)   return 0;
        }

        return 1;
    }
};