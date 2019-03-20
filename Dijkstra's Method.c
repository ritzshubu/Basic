#include<stdio.h>
#include<stdlib.h>
void main()
{
	int cost[10][10],parent[10],visited[10],dist[10],i,k,x,w,v,min=0,n,sr,j;
	printf("\nEnter the no. of vertices:\t");
	scanf("%d",&n);
	printf("\nEnter cost matrix(999 for no edge)\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	printf("\nEnter Source Vertex:\t");
	scanf("%d",&sr);
	for(i=1;i<=n;i++)
		{
			visited[i]=0;
			dist[i]=cost[sr][i];
			parent[i]=sr;
		}
	visited[sr]=1;
	dist[sr]=0;
	parent[sr]=sr;
	for(k=1;k<=n;k++)
	{
		min=999;
		for(w=1;w<=n;w++)
		{
			if(dist[w]<min && visited[w]==0)
			{
				min=dist[w];
				v=w;
			}
		}
		visited[v]=1;
		for(w=1;w<=n;w++)
		{
			if(dist[v]+cost[v][w]<dist[w])
			{
				dist[w]=cost[v][w]+dist[v];
				parent[w]=v;
			}
		}
	}
	printf("\nShortest Paths\n");
	for(j=1;j<=n;j++)
	{
		if(j!=sr)
		{
			x=j;
			while(x!=sr)
			{
				printf("%d <---",x);
				x=parent[x];
			}
		}
		printf(" %d=%d\n",sr,dist[j]);
	}
}
