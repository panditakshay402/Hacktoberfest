import random
import numpy as np
import matplotlib.pyplot as plt


def distance(a, b):
    return np.sqrt(np.dot(a - b, a - b))

class EnhancedKMeans:
    def __init__(self, num_clusters=3, iterations=100):
        self.num_clusters = num_clusters
        self.iterations = iterations
        self.centroids = None

    def fit_predict(self, X):
        random_indices = random.sample(range(0, X.shape[0]), self.num_clusters)
        self.centroids = X[random_indices]

        for iteration in range(self.iterations):
            assigned_clusters = self.assign_clusters(X)
            prv_centroids = self.centroids.copy()
            self.centroids = self.recalculate_centroids(X, assigned_clusters)
            if np.allclose(prv_centroids, self.centroids):
                break

        return assigned_clusters

    def assign_clusters(self, X):
        cluster_assignments = []

        for point in X:
            distances = [distance(point, centroid) for centroid in self.centroids]
            nearest_centroid_idx = np.argmin(distances)
            cluster_assignments.append(nearest_centroid_idx)

        return np.array(cluster_assignments)

    def recalculate_centroids(self, X, cluster_assignments):
        new_centroids = []
        for cluster_idx in range(self.num_clusters):
            cluster_points = X[cluster_assignments == cluster_idx]
            if len(cluster_points) > 0:
                new_centroids.append(np.mean(cluster_points, axis=0))

        return np.array(new_centroids)

    def plot_clusters(self, X, cluster_assignments):
        plt.figure(figsize=(10, 8))
        for cluster_idx in range(self.num_clusters):
            cluster_points = X[cluster_assignments == cluster_idx]
            plt.scatter(cluster_points[:, 0], cluster_points[:, 1], label=f"Cluster {cluster_idx + 1}")
        plt.scatter(self.centroids[:, 0], self.centroids[:, 1], s=150, c='red', marker='X', label='Centroids')
        plt.legend()
        plt.show()

if __name__ == "__main__":
    np.random.seed(42)
    data = np.vstack(( 
        np.random.randn(80, 2) + np.array([5, 5]), 
        np.random.randn(80, 2) + np.array([-5, -5]), 
        np.random.randn(80, 2) + np.array([5, -5]) 
    ))

    kmeans = EnhancedKMeans(num_clusters=3)
    cluster_labels = kmeans.fit_predict(data)
    kmeans.plot_clusters(data, cluster_labels)