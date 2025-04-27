class Solution {
    public:
    int MAX  = 1e9+7;
    long long binpow(long long a, long long b) {
        a %= MAX;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MAX;
            a = a * a % MAX;
            b >>= 1;
        }
        return res;
    }
        int countGoodNumbers(long long n) {
            long long even = n/2 + n%2;
            long long odd  = n/2;
            long long sum = binpow(5,even) * binpow(4,odd);
            return sum%MAX;
    
        }
    };