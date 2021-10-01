#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

int n, m;
int root[10], rank_node[10];

class Edge {
public:
	int vertex[2];
	int cost;
	Edge(int x, int y, int cost) {
		this->vertex[0] = x;
		this->vertex[1] = y;
		this->cost = cost;
	}
};

void make_set(int x)
{
	root[x] = x;
}

int find_set(int x)
{
	while (x != root[x]) {
		x = root[x];
	}
	return x;
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);

	if (x == y)
		return;
	if (rank_node[x] > rank_node[y])
		root[y] = x;
	else {
		root[x] = y;
		if (rank_node[x] == rank_node[y])
			rank_node[y]++;
	}
		
}

void sort(vector <Edge> *a) //간선 가중치 정렬
{

	for (int i = 0; i<m; i++) {
		for (int j = 1; j < m - i; j++) {
			if (a[j] < a[j - 1]) {
				swap(a[j - 1], a[j]);
			}

		}
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	printf("정점의 개수, 간선의 개수: ");
	scanf("%d%d", &n, &m);

	vector<Edge> G;

	G.push_back(Edge(0, 3, 3));
	G.push_back(Edge(0, 4, 12));
	G.push_back(Edge(1, 2, 2));
	G.push_back(Edge(1, 3, 5));
	G.push_back(Edge(2, 3, 3));
	G.push_back(Edge(2, 4, 7));
	
	sort(G.begin()); //오름차순으로 정렬

	for (int i = 0; i < n; i++) {
		make_set(i);
		cout << i << endl;
	}

	//int a, b, c;
	//for (int i = 0; i < m; i++) {
	//	cout << "정점1, 정점2, 가중치: " << endl;
	//	scanf("%d%d%d", &a, &b, &c);

	//}

	//for (int a = 0; a < n;a++) {
	//	cout << root[a] << endl;
	//}

	for (int i = 0; i < n; i++) {
		if (find_set(i) != find_set(i + 1)) {
			union_set(i, i + 1);
		}
	}
	return 0;
}

//class Edge {
//public:
//	int vertex[2];
//	int cost;
//};
//
//int get_root(int set[], int x) //루트노드 가져오기
//{
//	if (set[x] == x)
//		return x;
//	return set[x] = get_root(set, set[x]);
//}
//
//int make_set(int set[], int x) //단일 element x으로 이루어진 set하나 생성
//{
//	if (set[x] == x)
//		return x;
//	return set[x] = make_set(set, set[x]);
//}
//
//int find_set(int set[], int x) //x가 포함된 set을 return
//{
//	if (set[x] == x)
//		return x;
//	return set[x] = find_set(set, set[x]);
//}
//
//void union_set(int set[], int n, int m) //x가 포함된 set과 y가 포함된 set을 합친다.
//{
//	n = make_set(set, n);
//	m = make_set(set, m);
//
//	if (n < m) {
//		set[m] = n;
//	}
//	else {
//		set[n] = m;
//	}
//}
//
//void insert(Edge *node, int x, int y, int cost) //node에 값 insert하기
//{
//	Edge *node;
//
//	node->vertex[0] = x;
//	node->vertex[1] = y;
//	node->cost = cost;
//}
//
//int Kruskal() {
//
//}
//
//void main()
//{
//	int n = 5; //정점 개수
//	int m = 6; //간선 개수
//
//	Edge *node;
//
//	insert(node, 0, 3, 3);
//	insert(node, 0, 4, 12);
//	insert(node, 1, 3, 5);
//	insert(node, 1, 2, 2);
//	insert(node, 2, 4, 7);
//	insert(node, 3, 2, 3); //정점 값과 edge의 cost삽입
//	
//	for (int i = 0; i < m; i++) { //간선의 개수만큼 반복
//		if()
//	}
//}