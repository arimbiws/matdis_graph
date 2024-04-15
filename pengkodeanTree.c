#include <stdio.h>
#include <stdlib.h>

// Function to print the edges of the tree represented by the Prufer code
void printTreeEdges(int prufer[], int m) {
    int vertices = m + 2;
    int vertex_set[vertices];

    // Initialize the vertex_set array
    for (int i = 0; i < vertices; ++i) {
        vertex_set[i] = 0;
    }

    // Count the frequency of each vertex in the Prufer code
    for (int i = 0; i < m; ++i) {
        vertex_set[prufer[i]]++;
    }

    // Find the vertex with the lowest degree that is not in the Prufer code
    int x;
    for (int i = 0; i < vertices; ++i) {
        if (vertex_set[i] == 0) {
            x = i;
            break;
        }
    }

    // Construct the tree based on the Prufer code
    for (int i = 0; i < m; ++i) {
        int y;
        for (int j = 0; j < vertices; ++j) {
            if (vertex_set[j] == 0) {
                y = j;
                break;
            }
        }
        printf("%d ---- %d\n", x, y);
        vertex_set[x]--;
        vertex_set[y]--;
        x = prufer[i];
    }

    // The remaining two vertices
    int y;
    for (int i = 0; i < vertices; ++i) {
        if (vertex_set[i] == 0) {
            y = i;
            break;
        }
    }
    printf("%d ---- %d\n", x, y);
}

int main() {
    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int prufer[m];
    printf("Enter the Prufer code: ");
    for (int i = 0; i < m; ++i) {
        scanf("%d", &prufer[i]);
    }

    printf("Edges of the tree represented by the Prufer code:\n");
    printTreeEdges(prufer, m);

    return 0;
}

