const int N = 1e7 + 5;

vector<int> spf(N);

// O(N log log N)
void build_spf() {

    for (int i = 0; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++) {

        if (spf[i] == i) {

            for (int j = i * i; j < N; j += i) {

                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// O(log n)
vector<int> factorize(int n) {

    vector<int> factors;

    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    return factors;
}

