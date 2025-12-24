#include <stdio.h>

#define ROWS 5
#define COLS 5
#define FILE_NAME "seats.dat"

int main() {
    int seats[ROWS][COLS];
    int i, j, r, c;
    FILE *fp;

    /* Open file to read previous seat data */
    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        /* If file does not exist, initialize seats */
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                seats[i][j] = 0;
            }
        }
    } else {
        fread(seats, sizeof(seats), 1, fp);
        fclose(fp);
    }

    while (1) {
        printf("\n---------------------------------------\n");
        printf("           MOVIE TICKET BOOKING        \n");
        printf("---------------------------------------\n");
        printf(" 0 = Available   1 = Booked\n");

        printf("\n    SCREEN THIS SIDE\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf(" %d", seats[i][j]);
            }
            printf("\n");
        }

        printf("\nEnter Row (0-4): ");
        scanf("%d", &r);
        printf("Enter Column (0-4): ");
        scanf("%d", &c);

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            printf("\nInvalid seat position! Try again.\n");
        }
        else if (seats[r][c] == 0) {
            seats[r][c] = 1;
            printf("\nSeat Booked Successfully!\n");
        }
        else {
            printf("\nSorry! Seat Already Booked.\n");
        }

        int choice;
        printf("\nDo you want to book another seat? (1-Yes / 0-No): ");
        scanf("%d", &choice);

        if (choice == 0)
            break;
    }

    /* Save seat data to file */
    fp = fopen(FILE_NAME, "wb");
    fwrite(seats, sizeof(seats), 1, fp);
    fclose(fp);

    printf("\nThank you for Booking! Enjoy the movie 🎬\n");
    return 0;
}
