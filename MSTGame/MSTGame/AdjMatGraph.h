#include <stdio.h>
#define  MAX_VTXS 256
#define MAX 99999

class AdjMatGraph {
protected:
     int    size;
     char   vertices[MAX_VTXS];
     int    adj[MAX_VTXS][MAX_VTXS];
public:
     AdjMatGraph( ) { reset(); }
     char getVertex(int i) { return vertices[i]; }
     int  getEdge(int i, int j) { return adj[i][j]; }
     void setEdge(int i, int j, int val) { adj[i][j] = val; }
     bool isEmpty()	 { return size==0; }
     bool isFull()	 { return size>=MAX_VTXS; }

     // �׷��� �ʱ�ȭ ==> ���� ������ �׷���
     void reset() {
	size=0;
	for(int i=0 ; i<MAX_VTXS ; i++ )
	for(int j=0 ; j<MAX_VTXS ; j++ )
	    setEdge(i,j,MAX);
    }

   /* // ���� ����
	void insertVertex( int name ) {
		size = name;
		for (int i = 1; i <= size; i++) {
			if( !isFull() ) vertices[i] = i;
			else printf("Error: �׷��� ���� ���� �ʰ�\n");
		}
    }*/
	
	//�ȵ�
	 // ���� ����
    void insertVertex( int name ) {
	if( !isFull() ) vertices[++size] = name;
	else printf("Error: �׷��� ���� ���� �ʰ�\n");
    }
	

    // ���� ����: ������ �׷����� �����. 
    void insertEdge( int u, int v ) {
	setEdge(u,v,1);
	setEdge(v,u,1); // ���� �׷��������� ������(<u,v>�� ����)
    }
    // �׷��� ���� ��� (ȭ���̳� ���Ͽ� ���)
    void display( FILE *fp = stdout) {
	fprintf(fp, "%d\n", size);		// ������ ���� ���
	for( int i=1 ; i<=size ; i++ ) {		// �� ���� ���� ���
	    fprintf(fp,"%d ", getVertex(i));	// ������ �̸� ���
	    for( int j=1 ; j<=size ; j++ )	// ���� ���� ���
		fprintf(fp, " %5d", getEdge(i,j));
	    fprintf(fp,"\n");
	}
    }
};