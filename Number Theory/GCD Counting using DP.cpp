vector<int> dp(N); // dp[d] -> count pairs gcd(ai, aj) = d
for(int i = N-1; i >= 1; i--) {
    int count_multiples = 0;
    for(int j = i; j < N; j+=i)
        count_multiples += freq[j];
    dp[i] = (count_multiples * (count_multiples-1))>>1;
    for(int j = i+i; j < N; j+=i)
        dp[i] -= dp[j];
}
