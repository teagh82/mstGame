#include <stdlib.h>
#include "WGraphMST.h"

void main()
{
    WGraphMST g;

	int v; //정점 수
	int c; //간선 수
	int k; //턴 수

	printf("***정점의 개수와 그래프 간선의 수, 턴의 수를 입력하세요\n");
	printf("   (2 ≤ N ≤ 1,000, 1 ≤ M ≤ min(10,000, N×(N-1)/2), 1 < K ≤ 100)\n");	
	printf("***그 다음 간선을 연결할 두 정점을 입력하세요\n");
	
	scanf("%d%d%d", &v, &c, &k);
   
	//g.insertVertex(v);
	
	for(int i = 1; i <= v; i++){
		g.insertVertex(i);
	}
	

	int i,j,t;   //t행j열 

	for(i=1; i <= c; i++) {
		scanf("%d%d", &t,&j);					
		g.setEdge(t,j,i);	
		g.setEdge(j,t,i);	
	}
	printf("\n");
	//g.display();
	for(int i = 0; i < k; i++)
		g.Kruskal();
	printf("\n");
    system("pause");
}
