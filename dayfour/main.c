#include <stdio.h>
#include <stdlib.h>

int check_is_xmas(char x, char m, char a, char s) {
    return x == 'X' && m == 'M' && a == 'A' && s == 'S';
}

int check_right(int row, int col, char crossword[142][142]) {
    if (col+3 > 141) return 0;
    return check_is_xmas(
        crossword[row][col],
        crossword[row][col+1],
        crossword[row][col+2],
        crossword[row][col+3]
        );
}

int check_left(int row, int col, char crossword[142][142]) {
    if (col < 3) return 0;
    return check_is_xmas(
        crossword[row][col],
        crossword[row][col-1],
        crossword[row][col-2],
        crossword[row][col-3]
        );
}

int check_up(int row, int col, char crossword[142][142]) {
    if (row < 3) return 0;
    return check_is_xmas(
        crossword[row][col],
        crossword[row-1][col],
        crossword[row-2][col],
        crossword[row-3][col]
        );
}

int check_down(int row, int col, char crossword[142][142]) {
    if (row+3 > 141) return 0;
    return check_is_xmas(
        crossword[row][col],
        crossword[row+1][col],
        crossword[row+2][col],
        crossword[row+3][col]
        );
}

int check_diagonal_right_down(int row, int col,char crossword[142][142]) {
    if (row+3 > 141 || col+3 > 141) return 0;
    return check_is_xmas(
        crossword[row][col],
        crossword[row+1][col+1],
        crossword[row+2][col+2],
        crossword[row+3][col+3]
        );
}

static int check_diagonal_right_up(int row, int col,char crossword[142][142]) {
    if (row < 3 || col+3 > 139) return 0;
    return check_is_xmas(
            crossword[row][col],
            crossword[row-1][col+1],
            crossword[row-2][col+2],
            crossword[row-3][col+3]
    );
}
static int check_diagonal_left_down(int row, int col,char crossword[142][142]) {
    if (row+3 > 139 || col < 3) return 0;
    return check_is_xmas(
            crossword[row][col],
            crossword[row+1][col-1],
            crossword[row+2][col-2],
            crossword[row+3][col-3]
    );
}
static int check_diagonal_left_up(int row, int col,char crossword[142][142]) {
    if (row < 3 || col < 3) return 0;
    return check_is_xmas(
            crossword[row][col],
            crossword[row-1][col-1],
            crossword[row-2][col-2],
            crossword[row-3][col-3]
    );
}

int check_all_possibilities(int row, int col, char crossword[142][142]) {
    int count = 0;
    count += check_right(row, col, crossword);
    count += check_left(row, col, crossword);
    count += check_up(row, col, crossword);
    count += check_down(row, col, crossword);
    count += check_diagonal_right_down(row, col, crossword);
    count += check_diagonal_right_up(row, col, crossword);
    count += check_diagonal_left_down(row, col, crossword);
    count += check_diagonal_left_up(row, col, crossword);
    return count;
}

int iterate_through_matrix(char crossword[142][142]) {
    int count = 0;
    for (int i = 0; i < 142; i++) {
        for (int j = 0; j < 142; j++) {
            count += check_all_possibilities(i, j, crossword);
        }
    }
    return count;
}

int main(void) {
    FILE* fptr;
    fptr = fopen("./input", "r");
    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }
    char crossword[142][142];


    //fscanf(fptr, "%s", crossword);
    for (int i = 0; i < 141; i++) {
        fgets(crossword[i], 142, fptr);
    }

    printf("%d", iterate_through_matrix(crossword));
    return 0;
}