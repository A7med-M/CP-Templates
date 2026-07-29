const int N = 2e5 + 5;
const int MOD = 1e13;

int fact[N], invFact[N];
int power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = result * base % MOD;
        }
        base = base * base % MOD;
        exponent >>= 1;
    }
    return result;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

// nCr = n! / (r! * (n-r)!)
int nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// nPr = n! / (n-r)!
int nPr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return fact[n] * invFact[n - r] % MOD;
}
