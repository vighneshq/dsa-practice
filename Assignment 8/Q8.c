#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &matrix[i][j]);

        }
    }
    int aux[n][n];
    for(int i=0;i<n;i++)
    {
        aux[0][i] = matrix[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            aux[i][j] = matrix[i][j] + aux[i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            aux[i][j] += aux[i][j-1];
        }
    }
    
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=i;k<n;k++)
            {
                for(int l=j;l<n;l++)
                {
                    int sum = aux[k][l];
                    if(i > 0)
                    {
                        sum -= aux[i-1][l];
                    }
                    if(j > 0)
                    {
                        sum -= aux[k][j-1];
                    }
                    if(i > 0 && j > 0)
                    {
                        sum += aux[i-1][j-1];
                    }
                    if(sum == 1)
                    {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}