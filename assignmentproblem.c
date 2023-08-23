#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define N 4
struct Node {
    int assignment[N];
    int level;
    int cost;
};
int calculateCost(int costMatrix[N][N], int i, int j) {
    return costMatrix[i][j];
int calculateLowerBound(int costMatrix[N][N], struct Node node) {
    int bound = node.cost;
    for (int i = node.level; i < N; i++) {
        int minCost = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!node.assignment[j] && calculateCost(costMatrix, i, j) < minCost) {
                minCost = calculateCost(costMatrix, i, j);
            }
        }
        bound += minCost;
    }
    return bound;
}
void branchAndBound(int costMatrix[N][N]) {
    struct Node rootNode;
    for (int i = 0; i < N; i++) {
        rootNode.assignment[i] = -1;
    }
    rootNode.level = 0;
    rootNode.cost = 0;

    while (!queue_or_stack_empty) {
    }
}

int main() {
    int costMatrix[N][N] = {
        // Initialize your cost matrix here
    };

    branchAndBound(costMatrix);

    return 0;
}
}
