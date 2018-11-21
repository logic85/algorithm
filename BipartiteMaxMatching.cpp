/*

Constructing adj for some problems require large memory.
In this case, some tricks might be required.
For example, 2-dimension matrix adj can be replaced by
adj[Size][Max connection] with indexs to refer. 

*/

vector< vector<bool> > adj;
vector<int> aMatched, bMatched;
vector<bool> visited;

bool dfs(int here) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int i = 0; i < m; i++) {
		if (adj[here][i]) {
			if (bMatched[i] == -1 || dfs(bMatched[i])) {
				aMatched[here] = i;
				bMatched[i] = here;
				return true;
			}
		}
	}
	return false;
}

int getMaxBipartiteMaxMatching() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		visited = vector<bool>(n, 0);
		if (dfs(i)) ret++;
	}
	return ret;
}
