
#include <stdio.h>
#include <stdbool.h>
int arr[100][100], child[100], visited[100];
int findPath(int n, int currNode, int count, int source)
{
    if (count == n - 1)
    {
        return arr[currNode][source];
    }
    int ans = 10000;
    visited[currNode] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int temp = arr[currNode][i] + findPath(n, i, count + 1, source);
            if (ans > temp)
            {
                ans = temp;
                child[currNode] = i;
            }
        }
    }
    visited[currNode] = 0;
    return ans;
}
void printPath(int n, int currNode, int source, int count)
{
    if (child[currNode] == currNode || count == n - 1)
    {
        printf("%d->%d", currNode, source);
        return;
    }
    printf("%d->", currNode);
    printPath(n, child[currNode], source, count + 1);
}
int main()
{

    int n, src;
    printf("Enter the number of stops\n");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");

    for (int i = 0; i < n; i++)
    {
        child[i] = i;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter the source\n");
    scanf("%d", &src);
    int cost = findPath(n, src, 0, src);
    printf("Total cost is %d\n", cost);

    printPath(n, src, src, 0);
    return 0;
}
