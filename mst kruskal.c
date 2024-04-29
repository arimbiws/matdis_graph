#include <stdio.h>

#define V 6
#define E 9

struct Edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void KruskalMST(struct Edge edges[]) {
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    int edgeCount = 0;
    int mstWeight = 0;
    while (edgeCount < V - 1) {
        int min = 9999, minIndex = -1;
        for (int i = 0; i < E; i++) {
            if (find(parent, edges[i].src) != find(parent, edges[i].dest) && edges[i].weight < min) {
                min = edges[i].weight;
                minIndex = i;
            }
        }

        Union(parent, edges[minIndex].src, edges[minIndex].dest);
        printf("%d - %d\n", edges[minIndex].src, edges[minIndex].dest);
        mstWeight += min;
        edgeCount++;
    }
    printf("Bobot MST: %d\n", mstWeight);
}

int main() {
    struct Edge edges[] = {
        {0, 1, 10}, {0, 3, 30}, {0, 4, 45},
        {1, 2, 50}, {1, 5, 25},
        {2, 4, 35}, {2, 5, 15},
        {3, 5, 20},
        {4, 5, 55}
    };

    KruskalMST(edges);

    return 0;
}
