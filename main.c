#include <stdio.h>
#include <stdlib.h>

void printArray (int *v, int n) {
  int i;

  for (i = 0; i < n; i++ ) {
    if (i < n-1) printf("%d ", v[i]);
    else printf("%d\n", v[i]);
  }
}

void swap (int *v, int x, int y) {
  int aux;

  aux = v[x];
  v[x] = v[y];
  v[y] = aux;
}

//Retorna a posição do ultimo pai
int lParent (int *v, int n) {
  return (n/2)-1;
}

//Retorna a posicao do pai do elemento na psoicao i
int cParent (int n) {
  return (n-1)/2;
}

//Retorna a posicao do filho esquerdo
int leftChild (int n ){
  return 2*n+1;
}

//Retorna a posicao do filho direito
int rightChild (int n) {
  return 2*n+2;
}

void shift (int *v, int t, int a) {
  int l = leftChild(a), r = rightChild(a);
  int m = l;

  if (l < t) {
    if (r < t && v[r] >= v[l]) {
      m = r;
    }
    if (v[m] > v[a]) {
      swap (v, m, a);
      shift(v, t, m);
    }
  }
}

//Constroi o Heap
void buildHeap (int *v, int n) {
  int p = lParent(v, n);
  int i;

  for (i = p; i >= 0; i--) {
    shift(v, n, i);
  }
}

void heapSort(int *v, int t) {
  int i;

  buildHeap(v, t);

  for (i = t-1; i >= 0; i--) {
    printArray(v, i+1);
    swap(v, 0, t-1);
    t = t-1;
    shift(v, t, 0);
  }
}

int main(void) {
  int n;
  int i, *v;

  scanf ("%d", &n);
  v = (int*) malloc(n*sizeof(int));

  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  printArray(v, n);

  heapSort(v, n);

  printArray(v, n);

	printf("ZAWARUDOOO!!!");
}