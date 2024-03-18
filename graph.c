#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph *g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
}

void add_edge(Graph *g, int u, int v) {
    g->graph[u][v] = 1;
    g->graph[v][u] = 1;
}

void degree_of_vertices(Graph *g, int *degrees) {
    for (int i = 0; i < g->V; i++) {
        degrees[i] = 0;
        for (int j = 0; j < g->V; j++) {
            degrees[i] += g->graph[i][j];
        }
    }
}

bool is_connected(Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES];
    int top = -1;
    stack[++top] = 0;
    visited[0] = true;
    while (top != -1) {
        int s = stack[top--];
        for (int i = 0; i < g->V; i++) {
            if (g->graph[s][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

void print_adjacency_matrix(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            printf("%d ", g->graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g, 5);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);

    printf("Matriks Ketetanggaan:\n");
    print_adjacency_matrix(&g);

    int degrees[MAX_VERTICES];
    degree_of_vertices(&g, degrees);
    printf("\nDerajat Verteks:\n");
    for (int i = 0; i < g.V; i++) {
        printf("Verteks %d: %d\n", i, degrees[i]);
    }

    if (is_connected(&g)) {
        printf("\nGraf terhubung\n");
    } else {
        printf("\nGraf tidak terhubung\n");
    }

 return 0;
}
