/*

*/

vector < vector<pair<int, int>>> adj;
int dist[1000], path[1000];

void dijkstra(int s, int e) {
	dist[s] = 0;
	path[s] = s;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		pair<int, int> ele = pq.top();
		pq.pop();
		int idx = ele.second;
		int d = -ele.first;
		for (int i = 0; i < adj[idx].size(); i++) {
			int idx1 = adj[idx][i].first;
			int v = adj[idx][i].second;

			if (dist[idx1] > d + v || (dist[idx1] == d + v && path[idx1] > idx)) {
				dist[idx1] = d + v;
				path[idx1] = idx;
				pq.push(make_pair(-dist[idx1], idx1));
			}
		}
	}
}
