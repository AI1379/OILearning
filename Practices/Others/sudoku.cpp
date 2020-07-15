#include <bits/stdc++.h>
using namespace std;
struct blank
{
    int value;
    bool pos[10];
};
blank table[10][10];
int update(int x, int y)
{
    if (table[x][y].value != -1)
        return -1;
    int i, j;
    for (i = 1; i < 10; i++)
    {
        if (table[i][y].value != -1)
            table[x][y].pos[table[i][y].value] = false;
    }
    for (i = 1; i < 10; i++)
    {
        if (table[x][i].value != -1)
            table[x][y].pos[table[x][i].value] = false;
    }
    for (i = (((x - 1) / 3) * 3 + 1); i <= (((x - 1) / 3 + 1) * 3); i++)
    {
        for (j = (((y - 1) / 3) * 3 + 1); j <= (((y - 1) / 3 + 1) * 3); j++)
        {
            if (table[i][j].value != -1)
            {
#ifdef DEBUG
                //printf("(%d,%d),(%d,%d),%d\n", x, y, i, j, table[i][j].value);
#endif
                table[x][y].pos[table[i][j].value] = false;
            }
        }
    }
    vector<int> possible;
    for (i = 1; i < 10; i++)
    {
        if (table[x][y].pos[i])
            possible.push_back(i);
    }
    if (possible.size() == 1)
    {
        table[x][y].value = possible[0];
        return 1;
    }
    if (possible.size() == 0)
    {
        cout << "ERROR!";
        exit(0);
        return -1;
    }
    return 0;
}
int main()
{
    int i, j, num = 0;
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            cin >> table[i][j].value;
            if (table[i][j].value == -1)
                num++;
            memset(table[i][j].pos, true, sizeof(table[i][j].pos));
        }
    }
    while (num > 0)
    {
        for (i = 1; i < 10; i++)
        {
            for (j = 1; j < 10; j++)
            {
                if (update(i, j) == 1)
                    num--;
            }
        }
    }
    for (i = 1; i < 10; i++)
    {
        if (i == 1 || i == 4 || i == 7)
            printf("##############################################\n");
        printf("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n",
               table[i][1].value, table[i][2].value, table[i][3].value,
               table[i][4].value, table[i][5].value, table[i][6].value,
               table[i][7].value, table[i][8].value, table[i][9].value);
        if (i != 3 && i != 6 && i != 9)
            printf("#--------------#--------------#--------------#\n");
    }
    printf("##############################################\n");
    return 0;
}

/*
("##############################################\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("#--------------#--------------#--------------#\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("#--------------#--------------#--------------#\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("##############################################\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("#--------------#--------------#--------------#\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("#--------------#--------------#--------------#\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("##############################################\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("#--------------#--------------#--------------#\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("#--------------#--------------#--------------#\n");
("#%3d |%3d |%3d #%3d |%3d |%3d #%3d |%3d |%3d #\n");
("##############################################\n");
*/

/*
-1 -1 -1 6 -1 -1 -1 -1 -1
-1 -1 -1 -1 8 4 -1 -1 6
-1 -1 8 -1 -1 -1 -1 2 1
-1 9 -1 -1 1 -1 -1 -1 2
-1 5 -1 8 -1 7 -1 3 -1
8 -1 -1 -1 5 -1 -1 7 -1
2 1 -1 -1 -1 -1 3 -1 -1
5 -1 -1 4 3 -1 -1 -1 -1 
-1 -1 -1 -1 -1 9 -1 -1 -1
*/