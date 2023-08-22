#include <stdio.h>

#define V 5  // Number of vertices in the graph

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

void printSolution() {
    printf("Hamiltonian circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  // Print the starting vertex to complete the circuit
}

int isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v])
        return 0;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return 0;
    }
    return 1;
}

int hamiltonianCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])  // Last vertex should be connected to the first vertex
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(pos + 1))
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

int hamiltonianCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamiltonianCycleUtil(1) == 0) {
        printf("No Hamiltonian circuit exists.\n");
        return 0;
    }

    printSolution();
    return 1;
}

int main() {
    hamiltonianCycle();
    return 0;
}
