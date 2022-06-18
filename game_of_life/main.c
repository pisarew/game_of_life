#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 16
#define M 16

int input(int matrix[][M]);
void print_new_generation(int matrix[][M]);
int live_neighbors(int matrix[][M], int x, int y);
void run(int matrix[][M]);

int main() {
    int matrix[N][M];
    if (input(matrix) == 0) {
        printf("n/a");
        return 0;
    }
//    for (int i = 1; i < N - 1; i++) {
//        for (int j = 1; j < M - 1; j++)
//            printf("%d - %d\t", matrix[i][j], live_neighbors(matrix, i, j));
//        printf("\n\n");
//    }
    run(matrix);
    return 0;
}
int input(int matrix[][M]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return 0;
    return 1;
}
void print_new_generation(int matrix[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
            if (matrix[i][j] == 2)
                matrix[i][j] = 1;
            if (matrix[i][j] == 0)
                printf(" ");
            if (matrix[i][j] == 1)
                printf("*");
        }
        printf("\n");
    }

}
int live_neighbors(int matrix[][M], int x, int y) {
    int neighbors = 0;
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y)
                continue;
            if (matrix[i][j] == 1 || (matrix[i][j] == -1))
                neighbors++;
        }
    return neighbors;
}
void run(int matrix[][M]) {
    while (1) {
        sleep(1);
        system("clear");
        print_new_generation(matrix);
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                int neighbors = live_neighbors(matrix, i, j);
                if (neighbors == 3 && matrix[i][j] == 0)
                    matrix[i][j] = 2;
                if ((neighbors < 2 || neighbors > 3) && matrix[i][j] == 1)
                    matrix[i][j] = -1;
            }
        }
    }
}
