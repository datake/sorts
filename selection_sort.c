/* 選択ソートはソート済みの部分とソート済みでない部分があり、
*  ソート済みでない中で最も小さい要素を順次取り出して端において行くことで整列を行う
*  ◯◯◯◯◯   □□□△□
* →◯◯◯◯◯ △ □□□□

*  1,2,3,4,5, 9,7,10,6,8
* →1,2,3,4,5, 6, 9,7,10,8

*  ◯:ソート済み
*  △:ソート済みでないものの最小値=ソート済みのものの最大値
*  □:ソート済みでない
*  http://rosettacode.org/wiki/Sorting_algorithms/Selection_sort#C
*/

#include <stdio.h>
void selection_sort (int *array, int n) {
    int i, j, m;//mはまだソートされてない部分での最小値
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (array[j] < array[m]) {
                m = j;
            }
        }
        swap(array[i],array[m]);
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
  size_of_array = sizeof array / sizeof array[0];
  selection_sort(array, size_of_array);
  return 0;
}
