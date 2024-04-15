#include <stdio.h>

// Prints edges of tree represented by given Prufer code
void printTreeEdges(int prufer[], int m)
{
    int vertices = m + 2;
    int vertex_set[vertices];

    // Initialize the array of vertices
    for (int i = 0; i < vertices; i++)
        vertex_set[i] = 0;

    // Number of occurrences of vertex in code
    for (int i = 0; i < vertices - 2; i++)
        vertex_set[prufer[i] - 1] += 1;

    printf("\nThe edge set E(G) is :\n");

    // Find the smallest label not present in
    // prufer[].
    int j = 0;
    for (int i = 0; i < vertices - 2; i++) {
        for (j = 0; j < vertices; j++) {
            // If j+1 is not present in prufer set
            if (vertex_set[j] == 0) {
                // Remove from Prufer set and print
                // pair.
                vertex_set[j] = -1;
                printf("(%d, %d) ", j + 1, prufer[i]);

                vertex_set[prufer[i] - 1]--;

                break;
            }
        }
    }

    j = 0;
    // For the last element
    for (int i = 0; i < vertices; i++) {
        if (vertex_set[i] == 0 && j == 0) {
            printf("(%d, ", i + 1);
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1)
            printf("%d)\n", i + 1);
    }
}

// Driver code
int main()
{
    int n;
    printf("Enter the number of elements in the Prufer Code: ");
    scanf("%d", &n);
    int prufer[n];

    printf("Enter the elements of the Prufer Code: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &prufer[i]);

    printTreeEdges(prufer, n);
    return 0;
}
