#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

double euclideanDistance(pair<double, double> point1, pair<double, double> point2) {
    return sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
}
void kMeansClustering(vector<pair<double, double>>& data, int k, int iterations) {
    int n = data.size();
    vector<pair<double, double>> centroids(k);
    vector<int> labels(n);  

    for (int i = 0; i < k; i++) 
        centroids[i] = data[i];

    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < n; i++) {
            double minDistance = numeric_limits<double>::max();
            int closestCentroid = 0;

            for (int j = 0; j < k; j++) {
                double distance = euclideanDistance(data[i], centroids[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestCentroid = j;
                }
            }
            labels[i] = closestCentroid;
        }

        vector<pair<double, double>> newCentroids(k, {0, 0});
        vector<int> count(k, 0);

        for (int i = 0; i < n; i++) {
            newCentroids[labels[i]].first += data[i].first;
            newCentroids[labels[i]].second += data[i].second;
            count[labels[i]]++;
        }

        for (int j = 0; j < k; j++) {
            if (count[j] != 0) {
                newCentroids[j].first /= count[j];
                newCentroids[j].second /= count[j];
            }
        }

        centroids = newCentroids; 
    }

    cout << "Final Centroids:\n";
    for (int i = 0; i < k; i++) {
        cout << "Centroid " << i + 1 << ": (" << centroids[i].first << ", " << centroids[i].second << ")\n";
    }

    cout << "\nCluster Assignments:\n";
    for (int i = 0; i < n; i++) {
        cout << "Point (" << data[i].first << ", " << data[i].second << ") is in cluster " << labels[i] + 1 << "\n";
    }
}

int main() {
    int n, k, iterations;

    cout << "Enter the number of data points: ";
    cin >> n;
    vector<pair<double, double>> data(n);
    cout << "Enter the data points (x y):\n";
    for (int i = 0; i < n; i++) 
        cin >> data[i].first >> data[i].second;
    cout << "Enter the number of clusters (k): ";
    cin >> k;
    cout << "Enter the number of iterations: ";
    cin >> iterations;
    kMeansClustering(data, k, iterations);
    return 0;
}
