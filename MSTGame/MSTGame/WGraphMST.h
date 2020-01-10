#include "WGraph.h"
#include "MinHeap.h"
#include "VertexSets.h"

class WGraphMST : public WGraph {
public:
   void Kruskal() {     // kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
   int sum = 0;
   int temp = MAX;
   int a, b;

   MinHeap heap;
   for( int i=1 ; i<size ; i++ )
   for( int j=i+1 ; j<=size ; j++ )
      if( hasEdge(i,j) )
         heap.insert( getEdge(i,j), i, j ); // ��� ���� ����

   VertexSets set(size);      // size���� ������ ����

   int edgeAccepted=0;      // ���õ� ������ ��
   while( edgeAccepted < size-1 ){    // 4.(n-1)���� edge�� ���Եɶ�����

         HeapNode& e = heap.remove(); // 2.���� ���� edge ��ȯ
         int uset=set.findSet(e.getV1()); // v1�� ���� ������ ��Ʈ ��ȯ
         int vset=set.findSet(e.getV2()); // v2�� ���� ������ ��Ʈ ��ȯ
         if( uset != vset ){          // 3.����Ŭ ������ ������ MST����
           // printf( "���� �߰� : %d - %d (���:%d)\n", getVertex(e.getV1()-1)+1, getVertex(e.getV2()-1)+1, e.getKey());
            set.unionSets(uset, vset);       // �ΰ��� ������ ����.
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