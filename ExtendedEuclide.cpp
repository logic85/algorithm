/*
When a and b are coprime relation, find (x, y) meets (ax + by = 1).

- Related problems
-- https://codeforces.com/contest/1396/problem/A
*/

int x, y;
void extendedEuclide(int r0, int r1, int s0, int s1, int t0, int t1) {
    int r2 = r0 % r1;
    if(r2 == 0) {
        x = s1;
        y = t1;
        return;
    }
    
    int q1 = r0 / r1;
    int s2 = s0 - s1 * q1;
    int t2 = t0 - t1 * q1;
    extendedEuclide(r1, r2, s1, s2, t1, t2);
}
