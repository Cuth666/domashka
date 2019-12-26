#include <stdlib.h>
#include <stdio.h>

void bubble_sort_e(int* v, int* s, int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (s[j] < s[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

int main() {


    int n;
    printf("Vvedite kol-vo vershin grafa: ");
    scanf("%d", &n);
    
    
    int **a = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(n*sizeof(int));


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = -1;


//Krasivyi vvod!
    printf("Vvedite matritsu smejnosti:\nX |");
    for(int i = 0; i < n; i++) printf("%2d ", i+1);
    printf("\n--");
    for(int i = 0; i < 3*n; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%2d|", i+1);
        for (int j = 0; j < n; j++) {
            if (j==i) a[i][j] = 0;
            if (a[i][j] == -1) {
                scanf("%2d", &a[i][j]);
                a[j][i] = a[i][j];
            } else
                printf("%2d ", a[i][j]);
        }
    }
    printf("\n");
    
    
    printf("Vvedite vershini, mezdu kotorimi nuzno udalit rebro: ");
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    v1--; v2--;
    if (v1 < n && v2 < n && v1 >= 0 && v2 >= 0)
        if (a[v1][v2] == 0) printf("Takogo rebra net!\n");
        else {
            a[v1][v2] = 0;
            a[v2][v1] = 0;
        }
    else printf("   ---> NEVERNYI VVOD! <---\n");
    printf("\n");
    
    
//Krasivyi vivod
    printf("Teper matritsa vigladit tak:\nX |");
    for(int i = 0; i < n; i++) printf("%2d ", i+1);
    printf("\n--");
    for(int i = 0; i < 3*n; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%2d|", i+1);
        for (int j = 0; j < n; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    int *v = (int*)malloc(n*sizeof(int));
    int *s = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = i;
        s[i] = 0;
    }
    
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0) s[i]++;
         
            
    bubble_sort_e(v, s, n);
    
    
    printf("Versini otsortirovannie po stepeni:\n");
    for (int i = 0; i < n; i++) {
        printf("  |-> Versina %2d imeet stepen %2d\n", v[i]+1, s[i]);
    }
    
    
    System("pause");
    
    
    //VISUAL. IT MAY BE DELETED AT ALL
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
    //END OF VISUAL
    
    
    return 0;
}
