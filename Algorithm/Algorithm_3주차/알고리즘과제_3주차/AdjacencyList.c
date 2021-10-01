//#include<stdio.h>
//#define N 10
//int adj_matrix[N][N];
//
//typedef struct node{
//	int vertex;
//	struct node *next;
//}Node;
//
//typedef struct {
//	Node *graph[N];
//	int vertexCnt; //���� ����
//	int edgeCnt;  //���� ����
//}adj_list;
//
//void creategraph(adj_list *List);
//void insertedge(adj_list *List, int num1, int num2);
//void PrintList(adj_list *List);
//
//void main()
//{
//	adj_list *G = (adj_list*)malloc(sizeof(adj_list));
//	creategraph(G);
//
//	int Num1, Num2;
//
//	for(int i=0;i<5;i++)
//		G->vertexCnt++;
//
//	insertedge(G, 0, 1);
//	insertedge(G, 0, 3);
//	insertedge(G, 1, 0);
//	insertedge(G, 1, 2);
//	insertedge(G, 2, 1);
//	insertedge(G, 2, 3);
//	insertedge(G, 3, 0);
//	insertedge(G, 3, 2);
//	insertedge(G, 3, 4);
//	insertedge(G, 4, 3);
//
//	PrintList(G); //����Ʈ ���
//}
//
//void creategraph(adj_list *List)
//{
//	List->vertexCnt = 0;
//	List->edgeCnt = 0;
//	for (int i = 0; i < 5; i++) //vertex 5������ ����
//		List->graph[i] = NULL;
//}
//
//void insertedge(adj_list *List, int num1, int num2) //num1=���� num2=��
//{
//	Node *node = (Node*)malloc(sizeof(Node));
//	node->vertex = num2;
//
//	Node *p = (Node*)malloc(sizeof(Node));
//	p = List->graph[num1];
//
//	if (List->graph[num1] == NULL) { //1��
//		List->graph[num1] = node;  //
//		node->next = NULL;
//		List->edgeCnt++;
//	}
//
//	else {
//		while (p->next != NULL) //���� ���, p�� ����Ű�� ���� vertex�� 0�̸�, 1��3 �ΰ��� Ž���ϰ� �����ϹǷ� 
//			                   //0�� ������ vertex�� ����ŭ �ݺ��ȴ�.	
//		p->next = node;
//		node->next = NULL;
//		List->edgeCnt++;
//	}
//	return;
//
//}
//
//void PrintList(adj_list *List)
//{
//	Node *_node;
//
//	for (int i = 0; i < List->vertexCnt; i++) { //List->vertexCnt�� �ݺ�
//		printf("Linked list for vertex %d :", i); //1��
//		_node = List->graph[i]; //1��
//		while (_node) { //1��
//			printf(" %d ", _node->vertex); //1��
//			_node = _node->next; //1��
//		}
//		printf("\n"); //1��
//	}
//}
