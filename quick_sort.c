/*
  ピボットとして一つ選びそれをPとする。
  左から順に値を調べ、P以上のものを見つけたらその位置をiとする。
  右から順に値を調べ、P以下のものを見つけたらその位置をjとする。
  iがjより左にあるのならばその二つの位置を入れ替え、2に戻る。ただし、次の2での探索はiの一つ右、次の3での探索はjの一つ左から行う。
  2に戻らなかった場合、iの左側を境界に分割を行って2つの領域に分け、そのそれぞれに対して再帰的に1からの手順を行う。要素数が1以下の領域ができた場合、その領域は確定とする。
*/
//https://ja.wikipedia.org/wiki/クイックソート
void quicksort(int a[], int left, int right)
/* クイックソート
 * a     : ソートする配列
 * left  : ソートするデータの開始位置
 * right : ソートするデータの終了位置
 */
{
    if (left < right) {
        int i = left, j = right;
        int tmp;
        int pivot = (i+j)/2 //オーバーフローしそうな場合は違う取り方をすればよい
        while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
            while (a[i] < pivot) i++; /* a[i] >= pivot となる位置を検索 */
            while (pivot < a[j]) j--; /* a[j] <= pivot となる位置を検索 */
            if (i >= j) break;
            swap(a[i], a[j]); /* a[i],a[j] を交換 */
            i++; j--;
        }
        //クイックソートにも複数の実装方法があり、この実装方法ではピボットは、左か右のどちらかの2つに割り振られる
        //あとで、左部分、ピボット、右部分の3つに割り振る実装方法も紹介する
        //今、left,left+1,..,j,i,..,right-1,rightになってる
        //それは、left,left+1,..,i-1,j+1,..right-1,rightである
        //i-1とj+1で分割する
        quicksort(a, left, i - 1);  /* 分割した左を再帰的にソート */
        quicksort(a, j + 1, right); /* 分割した右を再帰的にソート */
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

//左部分、ピボット、右部分の3つに割り振る実装方法(http://www.zentut.com/c-tutorial/c-quicksort-algorithm/)
void quicksort2(int *list, int left, int right){
  int pivot,i,j,k;
    k = (left+right)/2;
    //kをpivotとする
    //pivotを左端(leftに寄せておく)。left+1番目から考える
    swap(&list[left],&list[k]);
    pivot = list[left];
    i = left+1;
    j = right;

    while (1) {
        while (list[i] < pivot) i++;
        while (pivot < list[j]) j--;
        if (i >= j) break;
        //breakしないのはi<jのとき
        swap(list[i], list[j]);
        i++; j--;
    }
    //pivot(←left),smaller,smaller,..,smaller(←j),bigger(←i),..bigger
    swap(&list[left],&list[j]);
    //smaller(←left),smaller,,..smaller(←j-1)|pivot(←j),|bigger(←i or j+1),..bigger

    //[left,..,j-1]
    quicksort(list,left,j-1);
    quicksort(list,j+1,right);
}
