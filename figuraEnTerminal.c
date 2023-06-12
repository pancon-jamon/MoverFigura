#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
    system("cls"); // Utiliza "cls" en Windows
}

void moveFigure(int x, int y) {
    // Mueve el cursor a la posición especificada
    printf("\033[%d;%dH", y, x);
}

int main() {
    int x = 0;
    int y = 0;
    char direction;

    while (1) {
        clearScreen();
        moveFigure(x, y);
        printf("Figura");

        direction = getchar();
        getchar(); // Captura el carácter de nueva línea

        switch (direction) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'q':
                return 0; // Sale del programa si se presiona 'q'
        }
    }

    return 0;
}
