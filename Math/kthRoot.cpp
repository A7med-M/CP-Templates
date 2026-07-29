long long kthRoot(long long n, int k) {
    long long l = 0, r = 1000000000LL, ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;

        __int128 cur = 1;
        bool ok = true;

        for (int i = 0; i < k; i++) {
            cur *= mid;
            if (cur > n) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

double kthRoot(double n, int k) {
    return pow(n, 1.0 / k);
}
