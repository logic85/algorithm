/*
Constructing pallindrome array in O(N) time.
This algorithm works only for strings having odd lengthes.
For general use, convert string to odd string through convertToOddString.
- Related problems
-- https://leetcode.com/problems/palindrome-partitioning/
*/

string convertToOddString(string s) {
	string ret = "";
	for (int i = 0; i < s.length(); i++) {
		ret += s[i];
		if (i == s.length() - 1) continue;
		ret += '#';
	}
	return ret;
}

vector<int> manacher(string s) {
	vector<int> p(s.length(), 0);
	int c = -1, r = -1;
	for(int i = 0; i < s.length(); i++) {
		if(r > i) {
			p[i] = min(r - i, p[c * 2 - i]);
		}
		else {
			p[i] = 0;
		}
		
		while(i + p[i] + 1 < s.length() 
		      && i - p[i] - 1 >= 0
		      && s[i + p[i] + 1] == s[i - p[i] - 1]) {
			p[i]++;
		}
		if(i + p[i] > r) {
			r = i + p[i];
			c = i;
		}
	}
	return p;
}
