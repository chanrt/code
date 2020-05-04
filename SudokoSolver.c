#include<stdio.h>

int grid[9][9];

int r_data[9];
int c_data[9];
int b_data[9];

int r_pos[9];
int c_pos[9];
int b_pos[9];

int common1[9], common2[9];

int numCommon()
{
    int num = 0;

    for(int i = 0; i < 9; i++)
    {
        if(common2[i] != 0) num++;
    }

    return num;
}

void checkCommon()
{
    int index = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(r_pos[i] == c_pos[j] && r_pos[i] != 0)
            {
                common1[index] = r_pos[i];
                index++;
            }
        }
    }

    index = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(common1[i] == b_pos[j] && b_pos[j] != 0)
            {
                common2[index] = b_pos[j];
                index++;
            }
        }
    }
}

int notInRow(int element)
{
    for(int i = 0; i < 9; i++)
    {
        if(r_data[i] == element) return 0;
    }
    return 1;
}

int notInColumn(int element)
{
    for(int i = 0; i < 9; i++)
    {
        if(c_data[i] == element) return 0;
    }
    return 1;
}

int notInBox(int element)
{
    for(int i = 0; i < 9; i++)
    {
        if(b_data[i] == element) return 0;
    }
    return 1;
}

void checkPossible()
{
    int index = 0;

    for(int i = 0; i < 9; i++)
    {
        if(notInRow(i+1))
        {
            r_pos[index] = i+1;
            index++;
        }
    }

    index = 0;

    for(int i = 0; i < 9; i++)
    {
        if(notInColumn(i+1))
        {
            c_pos[index] = i+1;
            index++;
        }
    }

    index = 0;

    for(int i = 0; i < 9; i++)
    {
        if(notInBox(i+1))
        {
            b_pos[index] = i+1;
            index++;
        }
    }
}

int checkBox(int i, int j)
{
    if(i < 3 && j < 3) return 1;
    if(i >= 3 && i < 6 && j < 3) return 2;
    if(i >= 6 && j < 3) return 3;
    if(i < 3 && j >= 3 && j < 6) return 4;
    if(i >= 3 && i < 6 && j >= 3 && j < 6) return 5;
    if(i >= 6 && j >= 3 && j < 6) return 6;
    if(i < 3 && j >= 6) return 7;
    if(i >= 3 && i < 6 && j >= 6) return 8;
    if(i >= 6 && j >= 6) return 9;
}

void load(int element, int i, int j)
{
    int index = 0;
    int box_num;
    int init_i, init_j;

    for(int k = 0; k < 9; k++)
    {
        r_data[k] = 0;
        c_data[k] = 0;
        b_data[k] = 0;

        r_pos[k] = 0;
        c_pos[k] = 0;
        b_pos[k] = 0;

        common1[k] = 0;
        common2[k] = 0;
    }

    for(int k = 0; k < 9; k++)
    {
        if(grid[i][k] != 0)
        {
            r_data[index] = grid[i][k];
            index++;
        }
    }

    index = 0;

    for(int k = 0; k < 9; k++)
    {
        if(grid[k][j] != 0)
        {
            c_data[index] = grid[k][j];
            index++;
        }
    }

    index = 0;
    box_num = checkBox(i,j);

    if(box_num == 1)
    {
        init_i = 0;
        init_j = 0;
    }
    if(box_num == 2)
    {
        init_i = 3;
        init_j = 0;
    }
    if(box_num == 3)
    {
        init_i = 6;
        init_j = 0;
    }
    if(box_num == 4)
    {
        init_i = 0;
        init_j = 3;
    }
    if(box_num == 5)
    {
        init_i = 3;
        init_j = 3;
    }
    if(box_num == 6)
    {
        init_i = 6;
        init_j = 3;
    }
    if(box_num == 7)
    {
        init_i = 0;
        init_j = 6;
    }
    if(box_num == 8)
    {
        init_i = 3;
        init_j = 6;
    }
    if(box_num == 9)
    {
        init_i = 6;
        init_j = 6;
    }

    for(int x = init_i; x < init_i + 3; x++)
    {
        for(int y = init_j; y < init_j + 3; y++)
        {
            if(grid[x][y] != 0) 
            {
                b_data[index] = grid[x][y];
                index++;
            }
        }
    }
}

void main()
{
    int pass = 1;
    int next;
    int nonZero;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)  scanf("%d",&grid[i][j]);
    }

    while(1)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++) if(grid[i][j] == 0)
            {
                load(grid[i][j],i,j);
                checkPossible();
                checkCommon();

                /*printf("Row: %d\tColumn: %d", i+1, j+1);
                printf("\nRow data:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",r_data[x]);
                }

                printf("\nColumn data:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",c_data[x]);
                }

                printf("\nBox data:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",b_data[x]);
                }

                printf("\nRow data:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",r_data[x]);
                }

                printf("\nRow possible:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",r_pos[x]);
                }

                printf("\nColumn possible:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",c_pos[x]);
                }

                printf("\nBox possible:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",b_pos[x]);
                }

                printf("\nCommon:");
                for(int x = 0; x < 9; x++)
                {
                    printf("%d ",common2[x]);
                }*/

                if(numCommon() == 1) grid[i][j] = common2[0];

                /*printf("\n\n");
                for(int i = 0; i < 9; i++)
                {
                    for(int j = 0; j < 9; j++) printf("%d ", grid[i][j]);
                    printf("\n");
                }
                scanf("%d",&next);*/
            }
        }

        nonZero = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(grid[i][j] != 0)
                {
                    nonZero++;
                }
            }
        }

        if(nonZero == 81) break;
        printf("\nPass No. %d\t Number of non zero elements: %d",pass,nonZero);
        printf("\nResult: \n");
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++) printf("%d ", grid[i][j]);
            printf("\n");
        }
        pass++;
    }

    printf("\n\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++) printf("%d ", grid[i][j]);
        printf("\n");
    }

    int a;
    scanf("%d",&a);
}