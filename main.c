#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "AllTypeDefinition.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ALGraph * G = NULL;
	MGraph * MG = NULL;
	G = (ALGraph*)malloc(sizeof(ALGraph));			//Ϊʲô��G���ڴ�������Ҫ��Main�����н��У� 
	MG = (MGraph*)malloc(sizeof(MGraph));
	CreateMGraph(MG);
//	KruskalALG(G);

//	CreateALGraph(G)	
//	Dijkstra(G,0);
	FloydMG(MG);
	return 0;
}


