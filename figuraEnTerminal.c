#include <stdio.h>

#define ROWS 20
#define COLS 40

void clearScreen() {
    printf("\033[H\033[J");
}

void moveFigure(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void printFigure(int x, int y) {
    clearScreen();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == y && j == x) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x = 0;
    int y = 0;
    char direction;

    while (1) {
        printFigure(x, y);

        direction = getchar();
        getchar(); // Captura el carácter de nueva línea

        switch (direction) {
            case 'w':
                if (y > 0) {
                    y--;
                }
                break;
            case 's':
                if (y < ROWS - 1) {
                    y++;
                }
                break;
            case 'a':
                if (x > 0) {
                    x--;
                }
                break;
            case 'd':
                if (x < COLS - 1) {
                    x++;
                }
                break;
            case 'q':
                return 0; // Sale del programa si se presiona 'q'
        }
    }

    return 0;
}
