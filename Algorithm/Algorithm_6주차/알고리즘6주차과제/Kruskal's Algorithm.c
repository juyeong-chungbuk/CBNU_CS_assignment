//#include <stdio.h>
//#define NUM 10
//int parent[NUM]; //�θ���
//int num[NUM]; //����ġ
//
//typedef struct edge {
//	int x; //����1
//	int y; //����2
//	int weight; //����ġ
//}Edge;
//
//typedef struct graph {
//	Edge set[NUM]; //���� ���� MST set
//	int set_size; //�� set�� ũ��
//}G;
//
//void make_set(int x) //���� element�� �̷���� set�ϳ� ����
//{
//	parent[x] = x; //�θ���x�� x�� �־ ��� �ϳ� ����
//	num[x] = 0; //rank�� 0
//}
//
//int find_set(int x) //x�� ���Ե� set�� ����
//{
//	if (parent[x] != x) { //�θ��尡 ����x���� �ٸ���
//		parent[x] = find_set(parent[x]); //��͸� �̿��Ͽ� �θ���� �̵�
//	} return parent[x]; //�θ��� ����
//}
//
//void union_set(int x, int y) //x�� ���Ե� set�� y�� ���Ե� set��ħ
//{
//	if (num[x] > num[y]) { //rank�� ū ����
//		parent[y] = x; //�θ����
//	}
//	else {
//		parent[x] = y; //rank�� ���� ���� �ڽĳ���
//		if (num[x] == num[y]) //rank�� ������ 
//			num[y] = num[y] + 1; //�� �� �ƹ��ų� ����
//	}
//}
//
//void insert_MST(G *g, Edge e) //MST�� �߰��ϴ� �Լ�
//{
//	int i;
//	i = ++(g->set_size); //0�̿��� ������ +1
//
//	while ((e.weight < g->set[i/2].weight)) { //�� set�� Ž���� �θ���� ��
//		g->set[i] = g->set[i / 2];
//		i = i / 2;
//	}
//	g->set[i] = e; //MST�� ���ο� set����
//}
//
//void insert_edge(G *g, int x, int y, int weight) //��� ���� �Լ�
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
//void sort(Edge e[], int n) //�����Լ�
//{
//	for (int i = 0; i < n-1; i++) {
//		for (int j = i+ 1; j < n; j++) {
//			if (e[i].weight > e[j].weight) {
//				swap(e[i].weight, e[j].weight); //����ġ�� ���� ������������ ����
//			}
//		}
//	}
//}
//
//void init(G *g)
//{
//	g->set_size = 0; //set�� ũ�� �ʱ�ȭ
//}
//
//void MST_print(G *g) //����Լ�
//{
//	int i;
//	for (i = 1; i < g->set_size; i++) {
//		printf("\t%d", g->set[i].weight); //����ġ�� ���
//	}
//	printf("\n");
//}
//
//void main()
//{
//	Edge e;
//	init(&e); //�ʱ�ȭ
//
//	insert_edge(&e, 0, 3, 3);
//	insert_edge(&e, 0, 4, 12);
//	insert_edge(&e, 1, 2, 2);
//	insert_edge(&e, 1, 3, 5);
//	insert_edge(&e, 2, 3, 3);
//	insert_edge(&e, 2, 4, 7); //�׷��� ����.
//
//	make_set(0);
//	make_set(1);
//	make_set(2);
//	make_set(3);
//	make_set(4); //���� set�����
//
//	sort(&e,NUM); //����
//
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (find_set(i) != find_set(j)) { //�θ��尡 �������� ���
//				g.set[i].x = i;
//				g.set[j].y = j;
//				union_set(i, j); //�� set�� ��ħ
//
//			}
//		}
//	}
//	
//	MST_print(&g); //����Լ� ȣ��
//}