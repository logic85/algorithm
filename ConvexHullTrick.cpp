/*
Some DP problems of O(n^2) with naive approach can be reduced to O(n * log n) through this trick.
Constructing recursion formula is required for this.

dp[i] = min_(j < i) (dp[j] + a[i] * b[j]) (b[j - 1] >= b[j])
--> f(x = a[i]) = min_(j < i) (b[j] * x + dp[j])
--> min value can be obtained from 1-dimension formulas

- Related problems
-- https://codeforces.com/contest/1083/problem/E
-- http://codeforces.com/contest/319/problem/C
*/

ll dp[1000005], la[1000005], lb[1000005];

double cross(int x, int y) {
	return (double)(lb[y] - lb[x]) / (la[y] - la[x]);
}

void add(ll x, ll y) {
	// Put first!
	la[sz] = x;
	lb[sz] = y;

	// Erase element at (sz - 1) if intersection of sz - (sz-1) > intersection of (sz-1) - (sz-2)
	while (sz > 1 && cross(sz, sz - 1) > cross(sz - 1, sz - 2)) {
		la[sz - 1] = la[sz];
		lb[sz - 1] = lb[sz];
		sz--;
	}
	++sz;  
}

ll query(ll y) {
	// Pop_front intersections behind y
	while (p + 1 < sz && cross(p, p + 1) > y) p++;

	// Recursion formula here!!
	return lb[p] - y * la[p];
}

/*
Usage:
add(0, 0);
for(int i = 0; i < n; i++) {
	dp[i] = query(y); // Change here based on problems!!
	add(x, dp[i]);
}
*/
