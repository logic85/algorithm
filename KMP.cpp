/*
Function kmpSearch returns matched indexs of 'd' in 's', i.e. d == s.substring(index ~ index + d.length).

Function maxMatch returns suffix array of itself.

- Related problems
-- 

*/

vector<int> maxMatch(string s) {
    int N = s.length();
    vector<int> ret(N, 0);
    int begin = 1, matched = 0;
    while(begin + matched < N) {
        if(s[begin + matched] == s[matched]) {
            matched++;
            ret[begin + matched - 1] = matched;
        }
        else {
            if(!matched) begin++;
                else {
                    begin += matched - ret[matched - 1];
                    matched = ret[matched - 1];
                }
            }
        }
    return ret;
}

vector<int> kmpSearch(string s, string d) {
    int N = s.length(), M = d.length();
    vector<int> pi = maxMatch(d);
    vector<int> ret;
    int begin = 0, matched = 0;
        while(begin <= N - M) {
            if(matched < M && s[begin + matched] == d[matched]) {
                matched++;
                if(matched == M) ret.push_back(begin);
            }
            else {
                if(!matched) begin++;
                else {
                    begin += matched - pi[matched - 1];
                    matched = pi[matched - 1];
                }
            }
        }
    return ret;
} 
    
 
