// VertexSets.h : 정점 집합 클래스
#define  MAX_VTXS 256

class VertexSets {
    
    int        nSets;		// 집합의 개수
public:
	int        parent[MAX_VTXS];	// 부모 정점의 id
    VertexSets (int n) : nSets(n) {
	for( int i=0 ; i<nSets ;i++ )
	    parent[i] = -1;	// 초기에 모든 정점이 고유의 집합에 속함
    }

	bool isRoot( int i ) { return parent[i] < 0; }  // -1이면 root

	int findSet( int v ) {	    // v가 속한 집합을 찾아 root 반환
		while (!isRoot(v)) v = parent[v]; // v가 속한 집합의 루트를 찾음
		return v;
		}

    void unionSets(int s1, int s2) { // 집합 s1을 집합 s2와 합침
		parent[s1] = s2;  // s1의 parent를 s2로 설정
		nSets--;          // 2개의 집합을 합쳐서 집합 개수는 1 감소
		}
};