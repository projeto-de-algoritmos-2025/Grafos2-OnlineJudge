#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 101

typedef struct {
    int node;
    int time;
} Edge;

typedef struct {
    Edge *arr;
    int size;
    int capacity;
} MinHeap;

// Funções auxiliares para o min-heap
MinHeap* createHeap(int capacity) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->arr = malloc(sizeof(Edge) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Edge *a, Edge *b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->arr[parent].time > heap->arr[idx].time) {
            swap(&heap->arr[parent], &heap->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < heap->size && heap->arr[left].time < heap->arr[smallest].time)
        smallest = left;
    if (right < heap->size && heap->arr[right].time < heap->arr[smallest].time)
        smallest = right;
    if (smallest != idx) {
        swap(&heap->arr[smallest], &heap->arr[idx]);
        heapifyDown(heap, smallest);
    }
}

void push(MinHeap* heap, int node, int time) {
    heap->arr[heap->size++] = (Edge){node, time};
    heapifyUp(heap, heap->size - 1);
}

Edge pop(MinHeap* heap) {
    Edge top = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return top;
}

int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// Dijkstra principal
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int adj[MAXN][MAXN];
    int dist[MAXN];

    // Inicializa adjacências
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            adj[i][j] = -1;

    // Preenche grafo
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0], v = times[i][1], w = times[i][2];
        adj[u][v] = w;
    }

    // Inicializa distâncias
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[k] = 0;

    // Min-heap para Dijkstra
    MinHeap* heap = createHeap(n * n);
    push(heap, k, 0);

    while (!isEmpty(heap)) {
        Edge cur = pop(heap);
        int u = cur.node;
        int t = cur.time;

        if (t > dist[u]) continue;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != -1) {
                int newDist = dist[u] + adj[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(heap, v, newDist);
                }
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }

    return maxTime;
}
