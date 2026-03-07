class Solution {
public:
    vector<bool> sieve(int n){
        vector<bool> primes(n, 1);
        for (int i = 2; i <= n / i; i++){
            if(primes[i]){
                for (long long j = i * i ; j < n; j += i){
                    primes[j] = 0;
                }
            }
        }

        return primes;
    }

    int countPrimes(int n) {
        vector<bool> primes = sieve(n);
        int count  = 0;
        for (int i = 2; i < n; i++){
            if(primes[i]) {
                count++;
            }
        }
        return count;
    }
};