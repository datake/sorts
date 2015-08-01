
//http://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C
#include <stdio.h>
#include <stdlib.h>

void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}


void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

//実行例
int int main() {
  int array[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  size_of_array = sizeof array / sizeof a[0];
  merge_sort(array, size_of_array);
  return 0;
}
