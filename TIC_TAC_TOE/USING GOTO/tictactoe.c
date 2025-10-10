#include <stdio.h>
void print(char (*)[3]);
void main()
{
    int i, j;
    char p, n;
    char a[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
k:
    printf("you choose x or 0\n");
    scanf("%c", &p);
    if (p != 'x' && p != '0')
    {
        printf("you choose wrong symbol\n");
        goto k;
    }
    print(a);
    int c = 0;
    while (1)
    {

    r:
    l:    
        scanf(" %c", &n);
        if (!(n >= '1' && n <= '9'))
        {
            printf("you select wrong position!\n");
            goto l;
        }
        int f = 0;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)

            {
                if (a[i][j] == n)
                {
                    if (a[i][j] != 'x' && a[i][j] != '0')
                    {
                        a[i][j] = p;
                        c++;
                        f = 1;
                    }
                }
            }
        }
        if (f != 1)
        {
            printf("already taken Try again.\n");
            goto r;
        }
        print(a);

        if (a[0][0] == a[0][1] && a[0][1] == a[0][2])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[1][0] == a[1][1] && a[1][1] == a[1][2])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[2][0] == a[2][1] && a[2][1] == a[2][2])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[0][0] == a[1][0] && a[1][0] == a[2][0])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[0][1] == a[1][1] && a[1][1] == a[2][1])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[0][2] == a[1][2] && a[1][2] == a[2][2])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
        {
            printf("%c you win, Congrats!", p);
            break;
        }
        else if (c == 9)
        {
            printf("It's a Draw Match!\n");
            break;
        }

        if (p == 'x')
        {
            p = '0';
        }
        else
        {
            p = 'x';
        }
    }
}
void print(char (*a)[3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %c ", a[i][j]);
            if (j != 2)
                printf("|");
        }
        printf("\n");
        if (i != 2)
            printf("---|---|---\n");
    }
    printf("\n");
}