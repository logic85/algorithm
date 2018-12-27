/*
Floyd can be used when N(node number) is small. 
Reconstructing details of the paths can be easily done during floyd running.

- Related problems
-- NEWBUS (https://algospot.com/judge/problem/read/NEWBUS) - Check the path (a, b) is single or not
-- DRUNKEN (https://algospot.com/judge/problem/read/DRUNKEN) - distance (edge) + cost (node)
*/

#define INF 987654321
vector< vector<int> > fw;

void initialize() {
  for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
        if(i == j) fw[i][j] = 0;
        else fw[i][j] = INF;
			}
	}
}

void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (fw[i][j] > fw[i][k] + fw[k][j]) {
					fw[i][j] = fw[i][k] + fw[k][j];
				}
			}
		}
	}
}
