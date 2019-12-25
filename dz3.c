#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int N;
    int p;
    printf("Enter the number of graph vertices: ");
    scanf("%d",&n);
    printf("Enter the number of graph edges: ");
    scanf("%d",&N);
    p = 0.5*(n-1)*(n-2);
    if (N>p) {
        printf ("Graph connected");
    }
    if (N<=p) {
        printf ("Graph not connected");
    }
    return 0;
}
