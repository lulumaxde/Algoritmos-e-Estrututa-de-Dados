#include <stdio.h>
void somar (int mat[2][5]) {
  int i, j, total = 0;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 5; j++) {
      printf ("%d ", mat[i][j]);
      total += mat[i][j];
    }
    printf ("Total: %d", total);
    total = 0;
    printf ("\n\n");
  } 


}
int main () {
  int matriz [2][5], i, j;
  for (i=0; i < 2; i++){
    for (j = 0; j < 5; j++) {
      matriz[i][j] = i+j+2;
  }
}
  somar(matriz);
}