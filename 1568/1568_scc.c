#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int visited[MAX][MAX];

void dfs(int** grid, int gridSize, int gridColSize, int x, int y) {
    if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize)
        return;
    if (visited[x][y] || grid[x][y] == 0)
        return;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        dfs(grid, gridSize, gridColSize, nx, ny);
    }
}

int countIslands(int** grid, int gridSize, int gridColSize) {
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return count;
}

int minDays(int** grid, int gridSize, int* gridColSize) {
    int colSize = gridColSize[0];

    // Verifica se já está desconectado
    if (countIslands(grid, gridSize, colSize) != 1)
        return 0;

    // Tenta remover cada célula de terra
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                int islands = countIslands(grid, gridSize, colSize);
                grid[i][j] = 1; // restaurar
                if (islands != 1)
                    return 1;
            }
        }
    }

    // Caso contrário, precisa de 2 dias
    return 2;
}
