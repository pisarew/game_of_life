#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 8
#define M 8

int input(char** matrix);
void run(char** matrix);
void output(char** matrix);

int main() {
    char** matrix = (char**) malloc(N * sizeof(char*));
    if (matrix == NULL) {
        printf("n/a");
        return 0;
    }
    if (input(matrix) == 0) {
        printf("n/a");
        return 0;
    }
//    output(matrix);
    run(matrix);
    return 0;
}
int input(char** matrix) {
    for (int i = 0; i < N; i++) {
        matrix[i] = (char*) malloc(M * sizeof(char));
        for (int j = 0; j < M; j++)
            if (scanf("%c", &matrix[i][j]) != 1)
                return 0;
        matrix[i][M] = '\0';
    }
    return 1;
}
void output(char** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == '-')
                matrix[i][j] = ' ';
            if (matrix[i][j] == '+')
                matrix[i][j] = '*';
        }
        printf("%s", matrix[i]);
    }

}
void run(char** matrix) {
    while (1) {
        sleep(1);
        system("clear");
        output(matrix);
        for (int i = 1; i < N - 1; i++) {
            int neighbors = 0;
            for (int j = 1; j < M - 1; j++) {
                if (matrix[i - 1][j - 1] == '*')
                    neighbors++;
                if (matrix[i - 1][j] == '*')
                    neighbors++;
                if (matrix[i - 1][j + 1] == '*')
                    neighbors++;
                if (matrix[i][j - 1] == '*')
                    neighbors++;
                if (matrix[i][j + 1] == '*')
                    neighbors++;
                if (matrix[i + 1][j - 1] == '*')
                    neighbors++;
                if (matrix[i + 1][j] == '*')
                    neighbors++;
                if (matrix[i - 1][j + 1] == '*')
                    neighbors++;
                if ((neighbors < 2 || neighbors > 3) && matrix[i][j] == '*')
                    matrix[i][j] = '-';
                if (neighbors == 3 && matrix[i][j] == ' ')
                    matrix[i][j] = '+';

            }
        }
    }
}
