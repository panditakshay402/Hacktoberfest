// C++ program for the above approach

#include "bits/stdc++.h"
using namespace std;

// interval with start time & end time
struct interval {
	int start, end;
};

// Comparator function to sort the given
// interval according to time
bool compareinterval(interval i1, interval i2)
{
	return (i1.start < i2.start);
}

// Function that find the free interval
void findFreeinterval(interval arr[], int N)
{

	// If there are no set of interval
	if (N <= 0) {
		return;
	}

	// To store the set of free interval
	vector<pair<int, int> > P;

	// Sort the given interval according
	// starting time
	sort(arr, arr + N, compareinterval);

	// Iterate over all the interval
	for (int i = 1; i < N; i++) {

		// Previous interval end
		int prevEnd = arr[i - 1].end;

		// Current interval start
		int currStart = arr[i].start;

		// If ending index of previous
		// is less than starting index
		// of current, then it is free
		// interval
		if (prevEnd < currStart) {
			P.push_back({ prevEnd,
						currStart });
		}
	}

	// Print the free interval
	for (auto& it : P) {
		cout << "[" << it.first << ", "
			<< it.second << "]" << endl;
	}
}

// Driver Code
int main()
{

	// Given set of interval
	interval arr[] = { { 1, 3 },
					{ 2, 4 },
					{ 3, 5 },
					{ 7, 9 } };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	findFreeinterval(arr, N);
	return 0;
}
