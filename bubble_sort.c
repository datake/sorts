//http://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort#C
//バブルソート(隣接交換法)は、隣り合う要素を比較し交換する
/*
4132
1432
1342
1324

1324
1324
1234

1234
1234
*/

#include <stdio.h>
void bubble_sort (int *array, int n) {
    for(int i = 1; i < n; i++) {
        for (j = 1; j < i; j++) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
}

void swap (int *small, int *big){
  tmp = small;
  small = big;
  big = tmp;
}
//実行例
int int main() {
  int array[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  size_of_array = sizeof array / sizeof a[0];
  bubble_sort(array, size_of_array);
  return 0;
}
