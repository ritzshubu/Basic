#include<stdio.h>
#include<stdlib.h>
int min,mincost,cost[10][10],parent[10],ne=1,a,b,u,v,i,j,n;
int main()
{
	printf("\nEnter no of Vertices\t");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			{
				scanf("%d",&cost[i][j]);
				if(cost[i][j]==0)
					cost[i][j]=999;
			}
	printf("\nThe Edges of Spanning Tree are\n");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min =cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(parent[u])
			u=parent[u];
		while(parent[v])
			v=parent[v];
		if(u!=v)
			{
				printf("\n%d edge(%d,%d)=%d",ne++,a,b,min);
				mincost+=min;
				parent[v]=u;
			}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nMinimum Cost=%d\n",mincost);
	
	return 0;
}
