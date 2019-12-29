#include <stdlib.h>
#include <stdio.h>

int** a;
int* color;

void connect(int v, int n) {
	color[v] = 1;
	for (int j = 0; j < n; j++)
		if (a[v][j] == 1 && color[j]!=1)
			connect(j, n);
}

int main() {
	// ZADANIE GRAFA
    int n, t, s_min, k, r = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

	color = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) color[i] = 0;
	
    a = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(n*sizeof(int));
	
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = -1;

    printf("Enter the matrix\nX| ");
    for (int j = 0; j < n; j++) printf("%d ", j+1);
    printf("\n--");
    for (int j = 0; j < n; j++) printf("--");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < n; j++) {
            if (j==i) a[i][j] = 0; //If we on the main diagonal, we put 0
            if (a[i][j] == -1) { //If we dont enter this vertex
                scanf("%d", &a[i][j]); //We enter it
                a[j][i] = a[i][j]; //And set mirrored i j - j i same
            } else
                printf("%d ", a[i][j]); //Else we just print already entered value
        }
    }
    printf("\n");
    //=========================================
	//PROVERKA SVAZANNOSTI
	connect(0, n);
	int connect = 1;
	for (int i = 0; i < n; i++)
		if (color[i] == 0)
			connect = 0;
	if (connect == 1) printf("CONNECTIVE!\n");
	else printf("NOT CONNECTIVE!\n");
	//=========================================
	//VISUAL
	FILE* f = fopen("graph.txt", "w");
	fprintf(f, "graph {\n    {1");
	for (int i = 1; i < n; i++) fprintf(f, ", %d", i+1);
	fprintf(f, "}\n");
	for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i][j] == 1) fprintf(f, "    %d -- %d;\n", i+1, j+1);
        }
    }
	fprintf(f, "}");
	fclose(f);
	system("dot -Tpng graph.txt -o graph.png");
	system("graph.png");
	system("pause");
}
