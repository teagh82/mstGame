#include "WGraph.h"
#include "MinHeap.h"
#include "VertexSets.h"

class WGraphMST : public WGraph {
public:
   void Kruskal() {     // kruskal의 최소 비용 신장 트리 프로그램
   int sum = 0;
   int temp = MAX;
   int a, b;

   MinHeap heap;
   for( int i=1 ; i<size ; i++ )
   for( int j=i+1 ; j<=size ; j++ )
      if( hasEdge(i,j) )
         heap.insert( getEdge(i,j), i, j ); // 모든 간선 삽입

   VertexSets set(size);      // size개의 집합을 만듦

   int edgeAccepted=0;      // 선택된 간선의 수
   while( edgeAccepted < size-1 ){    // 4.(n-1)개의 edge가 삽입될때까지

         HeapNode& e = heap.remove(); // 2.가장 작은 edge 반환
         int uset=set.findSet(e.getV1()); // v1이 속한 집합의 루트 반환
         int vset=set.findSet(e.getV2()); // v2가 속한 집합의 루트 반환
         if( uset != vset ){          // 3.사이클 생기지 않으면 MST삽입
           // printf( "간선 추가 : %d - %d (비용:%d)\n", getVertex(e.getV1()-1)+1, getVertex(e.getV2()-1)+1, e.getKey());
            set.unionSets(uset, vset);       // 두개의 집합을 합함.
            edgeAccepted++;            
            sum += e.getKey();

			if(e.getKey() < temp){
			temp = e.getKey();
			a = getVertex(e.getV1());
			b = getVertex(e.getV2());
			}
         }
         if(edgeAccepted < size-1 && heap.isEmpty()) {
			sum =0; break;
         } 
     }
         setEdge(a,b,MAX);
         printf("%d ", sum);
   }
};