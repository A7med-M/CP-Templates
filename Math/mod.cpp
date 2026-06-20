const int MOD = 1e9 + 7;

inline int mod(int x) {
    return ((x % MOD) + MOD) % MOD;
}

inline int add(int a, int b) {
    return mod(mod(a) + mod(b));
}

inline int sub(int a, int b) {
    return mod(mod(a) - mod(b));
}

inline int mul(int a, int b) {
    return (mod(a) * mod(b)) % MOD;
}

int fp(int a, int b) {
    a = mod(a);

    int res = 1;

    while (b > 0) {

        if (b & 1)
            res = mul(res, a);

        a = mul(a, a);

        b >>= 1;
    }

    return res;
}

inline int inv(int a) {
    return fp(a, MOD - 2);
}

inline int divide(int a, int b) {
    return mul(a, inv(b));
}

