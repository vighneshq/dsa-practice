#include<stdio.h>
#include<string.h>

int main()
{
    const int MAX = 1E5;
    char str[MAX];
    scanf("%s", &str);
    int n = strlen(str);
    
    int arr[26] = {0};
    for(int i=0;i<n;i++)
    {
        arr[str[i]-97]++;
    }
    int max = 0;
    for(int i=0;i<26;i++)
    {
        max = (max>arr[i])?max:arr[i];
    }
    if(max <= (n+1)/2)
    {
        printf("Possible\n");
    }
    else
    {
        printf("Not possible\n");
    }
    return 0;
}