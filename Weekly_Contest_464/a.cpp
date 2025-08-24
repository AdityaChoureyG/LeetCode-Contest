class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 1, even = 2;
        int o = 1, e = 2;
        n--;

        while(n--){
            odd += 2;
            o += odd;
            even += 2;
            e += even;
        }

        for(int i=min(o, e); i>0; i--){
            if(o%i==0 && e%i==0)  return i;
        }

        return 1;
    }
};