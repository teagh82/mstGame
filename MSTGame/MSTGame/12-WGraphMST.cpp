#include <stdlib.h>
#include "WGraphMST.h"

void main()
{
    WGraphMST g;

	int v; //���� ��
	int c; //���� ��
	int k; //�� ��

	printf("***������ ������ �׷��� ������ ��, ���� ���� �Է��ϼ���\n");
	printf("   (2 �� N �� 1,000, 1 �� M �� min(10,000, N��(N-1)/2), 1 < K �� 100)\n");	
	printf("***�� ���� ������ ������ �� ������ �Է��ϼ���\n");
	
	scanf("%d%d%d", &v, &c, &k);
   
	//g.insertVertex(v);
	
	for(int i = 1; i <= v; i++){
		g.insertVertex(i);
	}
	

	int i,j,t;   //t��j�� 

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
