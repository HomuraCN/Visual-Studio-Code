#include <stdio.h>
#include <stdlib.h>
#define INFINITY 0x7fffffff
#define MAX_VERTEX_NUM 20

/*邻接矩阵*/
typedef struct ArcCell {
	int adj;
}ARCCELL, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum;
	int arcnum;
}MGraph;

/*邻接链表*/
typedef struct ArcBox {
	int tailvex;
	int headvex;
	struct ArcBox* hlink, * tlink;
}ArcBox;
typedef struct VexNode {
	char data;
	ArcBox* firstin, * firstout;
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
}OLGraph;

/*邻接矩阵*/
int LocateVex(MGraph G, char v);
void CreateUDN(MGraph& G);
/*邻接链表*/
int Locate_Vertices(OLGraph G, char v);
void CreateDG(OLGraph& G);

int main() {
	MGraph G;
	CreateUDN(G);
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			printf("%d ", G.arcs[i][j].adj);
		}
		printf("\n");
	}

	return 0;
}
int LocateVex(MGraph G, char v) {
	for (int i = 0; i != G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}
void CreateUDN(MGraph &G) {
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	for (int i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.vexs[i]);
	}
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = { INFINITY }; /*G.arcs[i][j].adj = INFINITY*/
		}
	}
	for (int k = 0; k < G.arcnum; k++) {
		char u, v;
		int w;
		getchar();
		scanf("%c %c %d", &u, &v, &w);
		int i = LocateVex(G, u), j = LocateVex(G, v);
		G.arcs[i][j].adj = w;
	}
}
int Locate_Vertices(OLGraph G, char v) {
	for (int i = 0; i != G.vexnum; i++) {
		if (G.xlist[i].data == v)
			return i;
	}
	return -1;
}
void CreateDG(OLGraph &G) {
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	for (int i = 0; i < G.vexnum; i++) {
		scanf("%c", &G.xlist[i].data);
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;
	}
	for (int k = 0; k < G.arcnum; k++) {
		char u, v;
		getchar();
		scanf("%c %c", &u, &v);
		int i = Locate_Vertices(G, u), j = Locate_Vertices(G, v);
		ArcBox* p = NULL;
		p = (ArcBox*)malloc(sizeof(ArcBox));
		*p = { i, j, G.xlist[j].firstin, G.xlist[i].firstout };
		G.xlist[j].firstin = G.xlist[i].firstout = p;
	}
}