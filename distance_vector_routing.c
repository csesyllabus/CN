#include <stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[10];
int main()
{
    int costmat[20][20];
    int nodes, i, j, k, count = 0;
    printf("\n enter the no of nodes");
    scanf("%d", &nodes);
    printf("\n enter the cost matrix : \n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            scanf("%d", &costmat[i][j]);
            costmat[i][j] = 0;
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }
    do
    {
        count = 0;
        for (i = 0; i < nodes; i++)
            for (j = 0; j < nodes; j++)
                for (k = 0; k < nodes; k++)
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
    } while (count != 0);
    for (i = 0; i < nodes; i++)
    {
        printf("\n\n for router %d\n", i + 1);
        for (j = 0; j < nodes; j++)
        {
            printf("\t \n node %d via distance  %d", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    printf("\n\n");
    getch();
}

/*
OUTPUT:


 enter the no of nodes3

 enter the cost matrix :
1 1 3
2 5 6
4 6 7


 for router 1

 node 1 via distance  1
 node 2 via distance  2
 node 3 via distance  3

 for router 2

 node 1 via distance  1
 node 2 via distance  2
 node 3 via distance  3

 for router 3

 node 1 via distance  1
 node 2 via distance  2
 node 3 via distance  3


*/
