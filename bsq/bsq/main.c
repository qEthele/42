#include <stdio.h>

void print_grid(char grid[6][5])
{
    int row = 6;
    int col = 5;
    int i = 0;
    while (i < row)
	{
        int j = 0;
        while (j < col)
		{
            if (grid[i][j] == '*')
			{
                printf("%c ", grid[i][j]);
            } else
			{
                printf("%d ", grid[i][j]);
            }
            j++;
        }
        printf("\n");
        i++;
    }
}

int min(int a, int b, int c)
{
    if (a < b)
	{
        if (a < c)
            return a;
		else
            return c;
    }
	else
	{
        if (b < c)
            return b;
		else
            return c;
    }
}

void ft_solve(char grid[6][5])
{
    int rows = 6;
    int cols = 5;
    int new_matrix[6][5];
    int max_size = 0;
    int max_i = 0, max_j = 0;

    int i = 0, j = 0;

    while (i < rows)
	{
        new_matrix[i][0] = grid[i][0];
		max_size = 1;
        i++;
    }

    i = 0;
    while (i < cols)
	{
        new_matrix[0][i] = grid[0][i];
		max_size = 1;
        i++;
    }

    i = 1;
    while (i < rows)
	{
        j = 1;
        while (j < cols)
		{
            if (grid[i][j] == 1)
			{
                new_matrix[i][j] = min(new_matrix[i-1][j], new_matrix[i][j-1], new_matrix[i-1][j-1]) + 1;
                if (new_matrix[i][j] > max_size)
				{
                    max_size = new_matrix[i][j];
                    max_i = i;
                    max_j = j;
					//printf("\nmax-size = %d", max_size);
					//printf("\ni = %d", i);
					//printf("\nj = %d", j);
                }
            }
			else
			{
                new_matrix[i][j] = 0;
            }
            j++;
        }
        i++;
    }

    i = max_i;
    while (i > max_i - max_size)
	{
        j = max_j;
        while (j > max_j - max_size)
		{
            grid[i][j] = '*';
            j--;
        }
        i--;
	}
}

int main()
{
    char matrix[6][5] = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    
    printf("Original Grid:\n");
    print_grid(matrix);
    
    ft_solve(matrix);
    
    printf("Solve Grid\n");
    print_grid(matrix);

    return 0;
}
