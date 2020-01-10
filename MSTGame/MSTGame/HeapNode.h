// HeapNode.h: ���� ������ ��� Ŭ����
#include <stdio.h>

class HeapNode {
    int	key;    // Key ��: ������ ����ġ
    int	v1;     // ���� 1
    int	v2;     // ���� 2
public:
	HeapNode( ) {}
    HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) { }
    void setKey(int k) { key = k; }
    void  setKey(int k, int u, int v  ){
           key= k;   v1= u;  v2= v;
    }
    int getKey() { return key; }
    int getV1() { return v1; }
    int getV2() { return v2; }
	void 	display()	{ printf("\t%d", key); }
};
