class Solution {
    vector<int> st;

    void buildTree(vector<int>& nums, int i, int lo, int hi){
        if(lo==hi){
            st[i] = nums[lo];
            return;
        }
        int mid = lo + (hi-lo)/2;
        buildTree(nums, 2*i+1, lo, mid);
        buildTree(nums, 2*i+2, mid+1, hi);

        st[i] = min(st[2*i+1] , st[2*i+2]);
    }

    int getmin(int i, int lo, int hi, int x){
        if(lo==hi)  return lo;
        if(st[i] > x)  return -1;

        int mid = lo + (hi-lo)/2;
        if(st[2*i+2] < x)  return getmin(2*i+2, mid+1, hi, x);
        return   getmin(2*i+1, lo, mid, x);

        // return leftSum + rightSum;
    }

    void updateSegTree(int i, int lo, int hi, int& idx, int& val){
        if(lo==hi){
            st[i] = val;
            return;
        }

        int mid = lo + (hi - lo)/2;
        if(idx<=mid)    updateSegTree(2*i+1, lo, mid, idx, val);
        else        updateSegTree(2*i+2, mid+1, hi, idx, val);

        st[i] = min(st[2*i+1] , st[2*i+2]);
    }

    
public:
    vector<int> maxValue(vector<int>& nums) {
        int n  = nums.size();
        st.resize(4*n, INT_MAX);

        vector<int> fs(n), ans(n);

        for(int i=n-1; i>=0; i--){
            fs[i] = getmin(0, 0, n-1, nums[i]);
            if(fs[i]==-1)  fs[i] = i;
            updateSegTree(0, 0, n-1, i, nums[i]);
            // cout<<fs[i]<<' ';
        }

        for(auto it : fs)    cout<<it<<' ';

        vector<int> pge(n);
        int mxidx = 0;

        for(int i=0; i<n; i++){
            if(nums[mxidx] < nums[i]){
                mxidx = i;
            }
            pge[i] = mxidx;
        }


        for(int i=0; i<n; i++){
            int y = fs[i];
            int x = pge[y];
            int temp = fs[x];
            ans[i] = nums[pge[temp]];
        }

        for(int i=0; i<n; i++){
            ans[i] = max(ans[i] , ans[pge[i]]);
        }

        for(int i=n-1; i>=0; i--){
            ans[i] = max(ans[i], ans[fs[i]]);
        }

        return ans;
    }
};