/*

DFS on adjacency graph.

Sample code under is written to solve ZOMBIEROAD.
adj includes zombie road(1) and normal road(0). (People on each normal road)
Function dfs calculate number of zombie roads to remove to gather people on normal roads.
ret: sum of number of zombie roads on its children, peopole found on its children.

We can change the return type based on problems.

- Related problems
-- ZOMBIEROAD (https://algospot.com/judge/problem/read/ZOMBIEROAD)

*/

vector < vector<pair<int, bool> > > adj;
vector<bool> visited;

pair<int, bool> dfs(int here) {
	pair<int, bool> ret;
	visited[here] = true;
	ret.first = 0;
	ret.second = false;

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i].first;
		if (!visited[there]) {
			if (adj[here][i].second == false) ret.second = true;
			pair<int, bool> ret1 = dfs(there);
			if (ret1.second) {
				ret.first += ret1.first + (adj[here][i].second);
				ret.second = true;
			}
		}
	}
	if (ret.second == false) ret.first = 0;

	return ret;
}
