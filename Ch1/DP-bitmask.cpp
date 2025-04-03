#include <bits/stdc++.h>
using namespace std;

/* 
Solves the Minimum Weight Perfect Matching problem for 2N points in 2D space.
Each person must be paired with exactly one other person such that the total
Euclidean distance of all pairs is minimized. Uses bitmask DP to explore all
pair combinations efficiently with memoization.
*/


#define LSOne(S) ((S) & -(S))

int N;
double dist [20][20], memo[1<<16];

int main() {
    int caseNo = 0, x[20], y[20];

    while (true) {
        printf("Enter N (number of pairs, or 0 to exit): ");
        fflush(stdout);  // ensures prompt shows up immediately

        if (scanf("%d", &N) != 1 || N == 0) break;

        printf("Now enter coordinates for %d people (name x y):\n", 2 * N);
        for (int i = 0; i < 2 * N; ++i) {
            printf("  Person %d: ", i + 1);
            fflush(stdout);
            scanf("%*s %d %d", &x[i], &y[i]);  // ignore name, just read coords
        }

        // Compute pairwise distances
        for (int i = 0; i < 2 * N - 1; ++i)
            for (int j = i + 1; j < 2 * N; ++j)
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);

        // Initialize memo table only up to necessary size
        int limit = 1 << (2 * N);
        for (int i = 0; i < limit; ++i)
            memo[i] = -1.0;

        auto start = chrono::high_resolution_clock::now();
        double result = dp((1 << (2 * N)) - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        printf("Case %d: %.21f\n", ++caseNo, result);
        fprintf(stderr, "Computed in %.6f seconds\n\n", elapsed.count());
    }

    printf("Done.\n");
    return 0;
}

double dp(int mask) {
	double &ans = memo[mask];
	if (__builtin_popcount(mask) % 2 == 1) return 1e9; 
	if (ans > -0.5) return ans;
	if (mask == 0) return 0;
	ans = 1e9;
	int two_pow_p1 = LSOne(mask);
	int p1 = __builtin_ctz(two_pow_p1);
	int m = mask-two_pow_p1;
	while (m) {
		int two_pow_p2 = LSOne(m);
		int p2 = __builtin_ctz(two_pow_p2);
		ans = min(ans, dist[p1][p2] + dp(mask^two_pow_p1^two_pow_p2));
		m -= two_pow_p2;
	}
	return ans;
}




