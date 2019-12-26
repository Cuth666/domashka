#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *file;
    file= fopen("graf.dot", "w");
    if (file == NULL){
        printf("Error");
        exit(0);
    }
    fprintf (file,"digraph test{\n");
    //fprintf(file,"node [shape = box];\n");
    int N,a,i,j;
    printf("Vvedite col-vo vershin grafa: ");
    scanf ("%d", &N);
    int A[N][N];
    for (i=0; i<N;i++){
            for (j=0;j<N;j++){
                scanf ("%d",&A[N][N]);
                getchar();
                if (A[N][N] > 0){
                    fprintf(file,"%d->%d\n",i,j);
                }
                if (A[N][N]<0){
                    fprintf(file,"%d->%d\n",j,i);
                }
            }
    }
    fprintf(file,"}");
    fclose(file);
system("PAUSE");
    return 0;
}
