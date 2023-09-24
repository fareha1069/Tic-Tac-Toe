#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int isValid(char arr[][3], int i, int j)
{
    if (i >= 0 && i < 3 && j >= 0 && j < 3 && arr[i][j] == '-')
        return 1;
    return 0;
}
void takeInputAndPlace(char arr[][3], char mark)
{
    int i, j;
    printf("Enter input Row(0 - 2) and coloumn(0 -2) separated by space:");
    scanf("%d %d", &i, &j);
    while (isValid(arr, i, j) == 0)
    {
        printf("invalid input! Again Enter input Row(0 - 2) and coloumn(0 - 2) separated by space:");
        scanf("%d %d", &i, &j);
    }
    arr[i][j] = mark;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}
int checkWin(char arr[][3])
{
    if (arr[0][0] != '-' && arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
        return 1;

    if (arr[0][0] != '-' && arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
        return 1;

    if (arr[0][0] != '-' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return 1;

    if (arr[1][0] != '-' && arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
        return 1;

    if (arr[2][0] != '-' && arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
        return 1;

    if (arr[0][1] != '-' && arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])
        return 1;

    if (arr[0][2] != '-' && arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2])
        return 1;

    if (arr[0][2] != '-' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return 1;

    return 0;
}
int main()
{
    int i, j;
    char arr[3][3], mark;
    srand(time(0));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = '-';
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
            mark = 'A';
        else
            mark = 'B';
        takeInputAndPlace(arr, mark);
        if (checkWin(arr) == 1)
        {
            printf("Congratulations! player %c won", mark);
            return 0;
        }
    }
    printf("Game Draw");
}
