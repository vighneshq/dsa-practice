#include<stdio.h>
#include<string.h>

int increasing(char str[], int x, int y)
{
    int m = (x+y)/2;
    for(int i=x+1;i<=m;i++)
    {
        if(str[i] < str[i-1])
        {
            return 0;
        }
    }
    return 1;
}

int isPalindrome(char str[], int x, int y)
{
    int len = y - x + 1;
    for(int i=0;i<len;i++)
    {
        if(str[x+i] != str[y-i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    const int MAX_SIZE = 1000;
    char str[MAX_SIZE];
    scanf("%s", str);
    int len = strlen(str);
    int i = 0;

    int start = -1, end = -1, length = 0;
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>i+1;j--)
        {
            if(isPalindrome(str,i,j) && increasing(str,i,j))
            {
                int temp = j - i + 1;
                if(start == -1 || end == -1 || temp > length)
                {
                    start = i;
                    end = j;
                    length = temp;
                }
                else if(temp == length)
                {
                    for(int k=0;k<temp;k++)
                    {
                        if(str[i+k] < str[start+k])
                        {
                            start = i;
                            end = j;
                            length = temp;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(start == -1 || end == -1)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=start;i<=end;i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}



