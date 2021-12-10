#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define INFINITY 0x7fffffff
#define MAX_VERTEX_NUM 20
using namespace std;

/*邻接矩阵(有向)*/
typedef struct ArcCell {
	int adj;
}ARCCELL, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum;
	int arcnum;
}MGraph;
/*邻接链表(有向)*/
typedef struct ArcNode {
	int u;
	int w;
	struct ArcNode* next;
}ARCNODE;
typedef struct VNode {
	int vex;
	ARCNODE* firstarc = NULL;
}VNODE, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

/*邻接矩阵(有向)*/
int LocateVex(MGraph G, char v);
void CreateUDN(MGraph& G);
void DFSG(MGraph G, char tempu);
void BFSG(MGraph G);
/*邻接链表(有向)*/
void CreateALGraph(ALGraph& ALG);
void DFSALG(ALGraph ALG, char tempu);
void BFSALG(ALGraph ALG);

int flag[MAX_VERTEX_NUM];
queue<int> Q;

int main() {
	/*邻接矩阵(有向)*/
	MGraph G;
	CreateUDN(G);
	memset(flag, 0, sizeof(flag));
	DFSG(G, 'A');
	printf("\n");
	memset(flag, 0, sizeof(flag));
	BFSG(G);
	printf("\n");
	/*邻接链表(有向)*/
	ALGraph ALG;
	CreateALGraph(ALG);
	memset(flag, 0, sizeof(flag));
	DFSALG(ALG, 'A');
	printf("\n");
	memset(flag, 0, sizeof(flag));
	BFSALG(ALG);
	printf("\n");

	return 0;
}
/*邻接矩阵(有向)*/
int LocateVex(MGraph G, char v) {
	for (int i = 0; i != G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}
void CreateUDN(MGraph& G) {
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
void DFSG(MGraph G, char tempu) {
	printf("%c ", tempu);
	int u = tempu - 'A';
	flag[u] = 1;
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[u][i].adj != INFINITY) {
			if (flag[i] != 1) {
				DFSG(G, i + 'A');
			}
			else {
				return;
			}
		}
	}
}
void BFSG(MGraph G) {
	printf("A ");
	flag[0] = 1;
	Q.push(0);
	while (!Q.empty()) {
		int tempu = Q.front();
		Q.pop();
		for (int i = 0; i < G.vexnum; i++) {
			if (G.arcs[tempu][i].adj != INFINITY) {
				if (flag[i] != 1) {
					flag[i] = 1;
					printf("%c ", i + 'A');
					Q.push(i);
				}
			}
		}
		flag[tempu] = 1;
	}
}
/*邻接链表(有向)*/
void CreateALGraph(ALGraph& ALG) {
	scanf("%d %d", &ALG.vexnum, &ALG.arcnum);
	for (int i = 1; i <= ALG.arcnum; i++) {
		int u, v, w;
		char tempu, tempv;
		ARCNODE* p, *q;
		getchar();
		scanf("%c %c %d", &tempu, &tempv, &w);
		u = tempu - 'A', v = tempv - 'A';
		if (ALG.vertices[u].firstarc == NULL) {
			ALG.vertices[u].firstarc = (ARCNODE*)malloc(sizeof(ARCNODE));
			ALG.vertices[u].firstarc->u = v, ALG.vertices[u].firstarc->w = w;
			ALG.vertices[u].firstarc->next = NULL;
		}
		else {
			p = ALG.vertices[u].firstarc;
			while (p->next != NULL) {
				p = p->next;
			}
			q = (ARCNODE*)malloc(sizeof(ARCNODE));
			q->u = v, q->w = w;
			q->next = NULL;
			p->next = q;
		}
	}
}
void DFSALG(ALGraph ALG, char tempu) {
	printf("%c ", tempu);
	int u = tempu - 'A';
	flag[u] = 1;
	if (ALG.vertices[u].firstarc != NULL) {
		for (ARCNODE* p = ALG.vertices[u].firstarc; p != NULL; p = p->next) {
			if (flag[p->u] == 1) {
				return;
			}
			else {
				DFSALG(ALG, (p->u) + 'A');
			}
		}
	}
}
void BFSALG(ALGraph ALG) {
	printf("A ");
	flag[0] = 1;
	Q.push(0);
	while (!Q.empty()) {
		int tempu = Q.front();
		Q.pop();
		if (ALG.vertices[tempu].firstarc != NULL) {
			for (ARCNODE* p = ALG.vertices[tempu].firstarc; p != NULL; p = p->next) {
				if (flag[p->u] != 1) {
					flag[p->u] = 1;
					printf("%c ", (p->u) + 'A');
					Q.push(p->u);
				}
			}
		}
	}
}