//#include <stdio.h>
//#define NUM 10
//int parent[NUM]; //부모노드
//int num[NUM]; //가중치
//
//typedef struct edge {
//	int x; //정점1
//	int y; //정점2
//	int weight; //가중치
//}Edge;
//
//typedef struct graph {
//	Edge set[NUM]; //새로 넣을 MST set
//	int set_size; //각 set의 크기
//}G;
//
//void make_set(int x) //단일 element로 이루어진 set하나 생성
//{
//	parent[x] = x; //부모노드x에 x를 넣어서 노드 하나 생성
//	num[x] = 0; //rank는 0
//}
//
//int find_set(int x) //x가 포함된 set을 리턴
//{
//	if (parent[x] != x) { //부모노드가 현재x값과 다르면
//		parent[x] = find_set(parent[x]); //재귀를 이용하여 부모노드로 이동
//	} return parent[x]; //부모노드 리턴
//}
//
//void union_set(int x, int y) //x가 포함된 set과 y과 포함된 set합침
//{
//	if (num[x] > num[y]) { //rank가 큰 것을
//		parent[y] = x; //부모노드로
//	}
//	else {
//		parent[x] = y; //rank가 작은 것을 자식노드로
//		if (num[x] == num[y]) //rank가 같으면 
//			num[y] = num[y] + 1; //둘 중 아무거나 증가
//	}
//}
//
//void insert_MST(G *g, Edge e) //MST에 추가하는 함수
//{
//	int i;
//	i = ++(g->set_size); //0이였던 사이즈 +1
//
//	while ((e.weight < g->set[i/2].weight)) { //각 set을 탐색해 부모노드와 비교
//		g->set[i] = g->set[i / 2];
//		i = i / 2;
//	}
//	g->set[i] = e; //MST에 새로운 set삽입
//}
//
//void insert_edge(G *g, int x, int y, int weight) //노드 삽입 함수
//{
//	Edge node;
//	node.x = x;
//	node.y = y;
//	node.weight = weight;
//	insert_MST(g, node);
//}
//
//void swap(int *a, int *b)
//{
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void sort(Edge e[], int n) //정렬함수
//{
//	for (int i = 0; i < n-1; i++) {
//		for (int j = i+ 1; j < n; j++) {
//			if (e[i].weight > e[j].weight) {
//				swap(e[i].weight, e[j].weight); //가중치에 따라 오름차순으로 정렬
//			}
//		}
//	}
//}
//
//void init(G *g)
//{
//	g->set_size = 0; //set의 크기 초기화
//}
//
//void MST_print(G *g) //출력함수
//{
//	int i;
//	for (i = 1; i < g->set_size; i++) {
//		printf("\t%d", g->set[i].weight); //가중치를 출력
//	}
//	printf("\n");
//}
//
//void main()
//{
//	Edge e;
//	init(&e); //초기화
//
//	insert_edge(&e, 0, 3, 3);
//	insert_edge(&e, 0, 4, 12);
//	insert_edge(&e, 1, 2, 2);
//	insert_edge(&e, 1, 3, 5);
//	insert_edge(&e, 2, 3, 3);
//	insert_edge(&e, 2, 4, 7); //그래프 만듦.
//
//	make_set(0);
//	make_set(1);
//	make_set(2);
//	make_set(3);
//	make_set(4); //단일 set만들기
//
//	sort(&e,NUM); //정렬
//
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (find_set(i) != find_set(j)) { //부모노드가 같지않을 경우
//				g.set[i].x = i;
//				g.set[j].y = j;
//				union_set(i, j); //각 set을 합침
//
//			}
//		}
//	}
//	
//	MST_print(&g); //출력함수 호출
//}