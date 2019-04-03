#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int amt[n], dist[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &amt[i], &dist[i]);
    }

    int start = 0, curr = start, petrol = 0; 
    while(1)
    {
        petrol = petrol + amt[curr] - dist[curr];
        curr = (curr + 1)%n;
        
        while(petrol < 0 && start != curr)
        {
            petrol = petrol - amt[start] + dist[start];
            start = (start+1)%n;

            if(start == 0)
            {
                printf("Not possible\n");
                return 0;
            }
        }
        if(start == curr)
        {
            break;  
        }
    }
    printf("%d\n", start);
    return 0;
}