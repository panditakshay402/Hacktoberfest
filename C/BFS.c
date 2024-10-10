#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Adjacency list
struct Graph {
    int numberOfVertices;
    struct Node** adjacencyList;
    int* visited;
};

// Create a node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numberOfVertices = vertices;

    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge to graph
void addEdge(struct Graph* graph, int source, int destination) {
    // Add edge from source to destination
    struct Node* newNode = createNode(destination);
    newNode->next = graph->adjacencyList[source];
    graph->adjacencyList[source] = newNode;
}

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    return 0;
}

// Add to queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX - 1)
        printf("\nQueue is full!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Remove from queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjacencyList[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Perform BFS
    printf("Breadth-First Search starting from vertex 0:\n");
    bfs(graph, 0);

    return 0;
}
