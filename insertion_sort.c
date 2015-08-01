/* 挿入ソートはソート済みの部分とソート済みでない部分があり、
*  ソート済みでない要素をひとつずつ適切な場所に挿入する。
*  ◯◯◯◯◯ △ □□□□
* →◯◯◯◯△◯  □□□□

*  3,5,6,7,9,   8,10,1,4,2
* →3,5,6,7,8,9, 10,1,4,2

*  ◯:ソート済み
*  △:適切な部分に挿入する(i)
*  □:ソート済みでない
*  http://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort
*/
#include <stdio.h>

void insertion_sort (int *array, int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
       temp = array[i];
       j = i - 1;
      //ソート済みの部分(0番目からi-1番目)に適切に隙間を作ってarray[i]を挿入
      while ((temp < array[j]) && (j >= 0)) {
         //挿入するための隙間をつくる
         array[j + 1] = array[j];
         j = j - 1;
      }
      //隙間に挿入する
      arr[j + 1] = temp;
   }
}

//実行例
int int main() {
  int array[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  size_of_array = sizeof array / sizeof a[0];
  insertion_sort(array, size_of_array);
  return 0;
}
