#define ll long long

class Solution {
    ll sumd(int n){
        ll sum = 0;
        while(n){
            int temp = n%10;
            sum += temp;
            n = n/10;
        }
        return sum;
    }

    ll multi(int n){
        ll pro = 1;
        while(n){
            int temp = n%10;
            pro = pro * temp;
            n = n/10;
        }
        return pro;
    }
public:
    bool checkDivisibility(int n) {
        long long sum = sumd(n);
        ll p = multi(n);
        ll res = sum + p;
        if(n%res == 0)  return 1;
        return 0;
    }
};