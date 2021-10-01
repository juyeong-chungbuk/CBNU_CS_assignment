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
//	int vertexCnt; //정점 개수
//	int edgeCnt;  //간선 개수
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
//	PrintList(G); //리스트 출력
//}
//
//void creategraph(adj_list *List)
//{
//	List->vertexCnt = 0;
//	List->edgeCnt = 0;
//	for (int i = 0; i < 5; i++) //vertex 5개공간 생성
//		List->graph[i] = NULL;
//}
//
//void insertedge(adj_list *List, int num1, int num2) //num1=높이 num2=값
//{
//	Node *node = (Node*)malloc(sizeof(Node));
//	node->vertex = num2;
//
//	Node *p = (Node*)malloc(sizeof(Node));
//	p = List->graph[num1];
//
//	if (List->graph[num1] == NULL) { //1번
//		List->graph[num1] = node;  //
//		node->next = NULL;
//		List->edgeCnt++;
//	}
//
//	else {
//		while (p->next != NULL) //예를 들어, p가 가리키는 곳의 vertex가 0이면, 1과3 두개를 탐색하고 종료하므로 
//			                   //0과 인접한 vertex의 수만큼 반복된다.	
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
//	for (int i = 0; i < List->vertexCnt; i++) { //List->vertexCnt번 반복
//		printf("Linked list for vertex %d :", i); //1번
//		_node = List->graph[i]; //1번
//		while (_node) { //1번
//			printf(" %d ", _node->vertex); //1번
//			_node = _node->next; //1번
//		}
//		printf("\n"); //1번
//	}
//}
