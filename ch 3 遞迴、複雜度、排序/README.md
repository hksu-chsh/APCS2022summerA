# 07/08 課程補充內容

## pair
1. 是一種將兩筆資料綁定在同一個變數裡的方法
2. 兩筆資料之中，第一筆為 .first、第二筆為 .second
3. 在進行 sort 時會先依照 .first 由小到大排序，再依照 .second 由小到大排序
4. 適合兩兩一組的資料，例如：二維坐標平面上的點

### pair 宣告方式
##### `pair<data_type1, data_type2> pair_name;`
1. data_type1：請指定 pair 儲存第一筆資料的型態
2. data_type2：請指定 pair 儲存第二筆資料的型態
3. pair_name：請指定這個 pait 的名稱，就像我們宣告變數、陣列一樣
4. 例如： `pair<int, int> p1;`、`pair<int, string> p2;`

### 更多的初始化方式
1. `pair<int, int> p1 = {3, 5};`：開一個由兩個整數組成的 pair，兩筆資料依序為 `3, 5`
2. `pair<int, string> p2 = {1, "str"};`：開一個由整數與字串組成的 pair，兩筆資料依序為 `1, "str"`


## sort（續，講義p. 111）
### 自定義 sort 函式（使用 cmp 函式）
1. `sort(v.begin(), v.end());` 之後可以加上第三個參數，代表進行排序時判斷大小的依據，通常寫成`cmp`（或`comp`），例如：`sort(v.begin(), v.end(), cmp);`
2. 在這樣寫的同時，必須額外定義一個 `bool cmp()`的函式
3. 以下列程式為例，以 `pair<int, int>` 的第一筆資料優先由大至小排序，再以第二筆資料由小至大排序

```cpp=
#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}
int main(){
    vector<pair<int, int>> v(100);
    // input these pairs
    sort(v.begin(), v.end(), cmp);
}
```

## lower_bound（講義p. 118）
1. C++之中用於搜尋資料的函式（二分搜尋）
2. 需要有一個 target
3. lower_bound 會找出不小於 target 的第一筆符合資料（不一定剛好是 target）
4. 在使用之前請確定資料已經確實排序完成
5. 所需搜尋的資料必須可以互相比較大小（具備可比性），否則必須自行另外定義大小關係（使用`cmp`函式）
6. `#include<algorithm>`
7. * 此外，還有 upper_bound 函式，會找出大於 target 的第一筆符合資料，其使用方法與 lower_bound 雷同

### lower_bound 函式使用方式
1. 對整數陣列`int a[n];`進行搜尋，目標為 target，找出其所在位置 pos：`int pos = lower_bound(a, a + n, target) - a;`
2. 對`vector<int> v(n);`進行搜尋，目標為 target，找出其所在位置 pos：`int pos = lower_bound(v.begin(), v.end(), target) - v.begin();`

### 多重 vector
1. `vector<data_type> v;` 之中，除了基本資料型態（int等）以外，也可以使用一些比較複雜的資料型態，甚至其他STL，例如：放入另一個 vector，或是 pair等。
2. 必須特別注意：vector 之中放入另一個 vector，必須在裡面那層指定其型態，例如：`vector<vector<int>> v;`，我們把外層稱作**大 vector**，內層稱作**小 vector**
3. 上述範例如同二維陣列一般，但有點差別的是，大 vector 裡面存放的每一個小 vector，個別的長度也可以動態的調整，比起二維陣列，雙重 vector 更像一個雙重的 list
4. 以雙重 vector 直接開一個擁有 n 個空的小 vector 的大 vector：`vector<vector<int>> v(m);`
5. 以雙重 vector 直接開一個 $m\times n$ 的擬似二維陣列：`vector<vector<int>> v(m, vector<int>(n));`

![](https://i.imgur.com/4FqjPO1.png)
