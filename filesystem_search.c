/*
 * File System Representation and Search Using BFS and DFS
 * Activity ID: SY-S3-B-09
 * Nodes = files/directories, edges = parent -> child (directed).
 * Representation: adjacency matrix.
 *
 * Input (stdin):
 *   n                      number of nodes
 *   n names                node names (no spaces)
 *   m                      number of edges
 *   m lines: parent child  edge from parent to child
 *   start target           start node name, file to search
 */
#include <stdio.h>
#include <string.h>

#define MAX 50
#define NAME_LEN 50

int n, adj[MAX][MAX];
char names[MAX][NAME_LEN];

int indexOf(const char *s) {
    for (int i = 0; i < n; i++)
        if (strcmp(names[i], s) == 0) return i;
    return -1;
}

void printMatrix(void) {
    printf("\nAdjacency Matrix:\n%-15s", "");
    for (int i = 0; i < n; i++) printf("%-4d", i);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-2d %-12s", i, names[i]);
        for (int j = 0; j < n; j++) printf("%-4d", adj[i][j]);
        printf("\n");
    }
}

int bfs(int start, int target) {
    int visited[MAX] = {0}, queue[MAX], front = 0, rear = 0, found = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%s ", names[u]);
        if (u == target) { found = 1; break; }
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
    }
    printf("\n");
    return found;
}

int dfsRec(int u, int target, int visited[]) {
    visited[u] = 1;
    printf("%s ", names[u]);
    if (u == target) return 1;
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !visited[v])
            if (dfsRec(v, target, visited)) return 1;
    return 0;
}

int dfs(int start, int target) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    int found = dfsRec(start, target, visited);
    printf("\n");
    return found;
}

int main(void) {
    int m;
    char a[NAME_LEN], b[NAME_LEN];

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid node count.\n"); return 1; }
    for (int i = 0; i < n; i++) scanf("%49s", names[i]);

    if (scanf("%d", &m) != 1 || m < 0) { printf("Invalid edge count.\n"); return 1; }
    for (int i = 0; i < m; i++) {
        scanf("%49s %49s", a, b);
        int u = indexOf(a), v = indexOf(b);
        if (u < 0 || v < 0) { printf("Unknown node in edge: %s %s\n", a, b); return 1; }
        adj[u][v] = 1;
    }

    scanf("%49s %49s", a, b);
    int s = indexOf(a), t = indexOf(b);
    if (s < 0) { printf("Start node '%s' not found in file system.\n", a); return 1; }

    printMatrix();
    printf("\nStart: %s | Searching for: %s\n\n", a, b);

    if (t < 0) {
        printf("'%s' does not exist in the file system.\n", b);
        bfs(s, -1);
        dfs(s, -1);
        printf("\nBFS Result: File NOT found\nDFS Result: File NOT found\n");
        return 0;
    }
    int fb = bfs(s, t);
    int fd = dfs(s, t);
    printf("\nBFS Result: File %s\n", fb ? "FOUND" : "NOT found");
    printf("DFS Result: File %s\n", fd ? "FOUND" : "NOT found");
    return 0;
}
