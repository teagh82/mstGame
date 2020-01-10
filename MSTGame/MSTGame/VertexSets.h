// VertexSets.h : ���� ���� Ŭ����
#define  MAX_VTXS 256

class VertexSets {
    
    int        nSets;		// ������ ����
public:
	int        parent[MAX_VTXS];	// �θ� ������ id
    VertexSets (int n) : nSets(n) {
	for( int i=0 ; i<nSets ;i++ )
	    parent[i] = -1;	// �ʱ⿡ ��� ������ ������ ���տ� ����
    }

	bool isRoot( int i ) { return parent[i] < 0; }  // -1�̸� root

	int findSet( int v ) {	    // v�� ���� ������ ã�� root ��ȯ
		while (!isRoot(v)) v = parent[v]; // v�� ���� ������ ��Ʈ�� ã��
		return v;
		}

    void unionSets(int s1, int s2) { // ���� s1�� ���� s2�� ��ħ
		parent[s1] = s2;  // s1�� parent�� s2�� ����
		nSets--;          // 2���� ������ ���ļ� ���� ������ 1 ����
		}
};