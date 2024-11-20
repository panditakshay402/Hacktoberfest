// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of steps
int shortestPath(vector<vector<int> > mat, int k)
{
	int n = mat.size();
	int m = mat[0].size();
	if (n == 1 && m == 1 && (mat[0][0] == 0 || k >= 1))
		return 0;

	vector<vector<vector<bool> > > visited(
		n, vector<vector<bool> >(
			m, vector<bool>(k + 1, false)));
	int steps = 0;

	queue<vector<int> > q;
	q.push({ 0, 0, k });
	int ar1[4] = { 1, -1, 0, 0 };
	int ar2[4] = { 0, 0, -1, 1 };

	// Loop to run a BFS
	while (!q.empty()) {
		int size = q.size();

		steps++;
		while (size--) {
			auto curr = q.front();
			int i = curr[0], j = curr[1], w = curr[2];
			q.pop();
			visited[i][j][w] = true;
			for (int dir = 0; dir < 4; dir++) {
				int new_x = i + ar1[dir];
				int new_y = j + ar2[dir];
				int new_k = w;
				if (new_x >= 0 && new_x < n && new_y >= 0
					&& new_y < m) {
					if (mat[new_x][new_y] == 0
						&& !visited[new_x][new_y][new_k]) {
						if (new_x == n - 1
							&& new_y == m - 1)
							return steps;
						q.push({ new_x, new_y, new_k });
						visited[new_x][new_y][new_k] = true;
					}
					else if (mat[new_x][new_y] == 1
							&& new_k >= 1
							&& !visited[new_x][new_y]
										[new_k - 1]) {
						if (new_x == n - 1
							&& new_y == m - 1)
							return steps;
						q.push({ new_x, new_y, new_k - 1 });
						visited[new_x][new_y][new_k - 1]
							= true;
					}
				}
			}
		}
	}
	return -1;
}

// Driver code
int main()
{
	vector<vector<int> > mat
		= { { 0, 0, 0 }, { 0, 0, 1 }, { 0, 1, 0 } };
	int K = 1;

	// Function call
	cout << shortestPath(mat, K);
	return 0;
}
