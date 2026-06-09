#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void drawRectangle(int row, int col, int width, int height) {
    int i;

    for(i = col; i < col + width && i < COLS; i++) {
        canvas[row][i] = '*';

        if(row + height - 1 < ROWS)
            canvas[row + height - 1][i] = '*';
    }

    for(i = row; i < row + height && i < ROWS; i++) {
        canvas[i][col] = '*';

        if(col + width - 1 < COLS)
            canvas[i][col + width - 1] = '*';
    }
}

void displayCanvas() {
    int i, j;

    printf("\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row, col, width, height;

    initializeCanvas();

    printf("RECTANGLE DRAWING PROGRAM\n");

    printf("Enter starting row: ");
    scanf("%d", &row);

    printf("Enter starting column: ");
    scanf("%d", &col);

    printf("Enter width: ");
    scanf("%d", &width);

    printf("Enter height: ");
    scanf("%d", &height);

    drawRectangle(row, col, width, height);

    printf("\nRectangle Drawn Successfully!\n");

    displayCanvas();

    return 0;
}
void drawLine(int x1, int y1, int x2, int y2)
{
    int i;

    // Horizontal line
    if(y1 == y2)
    {
        int start = (x1 < x2) ? x1 : x2;
        int end = (x1 > x2) ? x1 : x2;

        for(i = start; i <= end; i++)
        {
            canvas[y1][i] = '*';
        }
    }

    // Vertical line
    else if(x1 == x2)
    {
        int start = (y1 < y2) ? y1 : y2;
        int end = (y1 > y2) ? y1 : y2;

        for(i = start; i <= end; i++)
        {
            canvas[i][x1] = '*';
        }
    }

    // Diagonal line
    else
    {
        int dx = (x2 > x1) ? 1 : -1;
        int dy = (y2 > y1) ? 1 : -1;

        int x = x1;
        int y = y1;

        while(1)
        {
            canvas[y][x] = '*';

            if(x == x2 && y == y2)
                break;

            x += dx;
            y += dy;
        }
    }
}