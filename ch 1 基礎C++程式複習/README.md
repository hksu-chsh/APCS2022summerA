# 07/04 課程補充內容

## 萬用標頭檔
```cpp=
#include<bits/stdc++.h>
```
1. 這是一個把幾乎你在APCS之中可能用到的標頭檔全部包含在內的萬用標頭檔
2. 但當你使用的時候，還是要記得你所使用的功能本來來自哪個標頭檔

## vector（講義p. 82）
1. 與數學中的「向量」英文相同，然而與數學中向量的意思截然不同，為避免混淆僅稱為 vector
2. 可以想像為一個可指定大小、隨時新增或刪除資料的容器
3. 屬於C++標準範本函式庫（Standard Template Library，STL）之中的一種
4. `#include<vector>`
### vector 宣告方式
##### `vector<data_type> vector_name;`
1. data_type：請指定 vector 儲存資料的型態
2. vector_name：請指定這個 vector 的名稱，就像我們宣告變數、陣列一樣
3. 例如： `vector<int> v;`、`vector<string> vs;`

### 更多的初始化方式，以 `vector<int> v;` 為例
1. `vector<int> v(n);`：開一個大小為 n 的 vector，且所有元素初始設定為 0
2. `vector<int> v(n, -1);`：開一個大小為 n 的 vector，且所有元素初始設定為 -1

### vector 的一些可用函式
1. v.size()：v 的大小，使用範例：`for(int i=0;i<v.size();i++)`
2. v.push_back(data)：新增一筆資料在 v 的末端，使用範例：`v.push_back(n);`
3. v.pop_back()：移除 v 末端的資料，使用範例：`v.pop_back()`
4. v.resize()：重新調整 v 的元素數量，使其成為重新設定的大小，使用範例：`v.resize(100);`
5. v.begin()：v 最前端所在的記憶體位置
6. v.end()：v 最末端所在的記憶體位置
7. v.front()：v 最前端所儲存的資料內容
8. v.back()：v 最末端所儲存的資料內容

**注意：5, 6 與 7, 8 意義不同，不可以混用**

## sort（講義p. 111）
1. C++之中用於排序資料的函式
2. 預設排序方式為由小至大排序，但可以自行改變排序方式
3. 所需排序的資料必須可以互相比較大小（具備可比性），否則必須自行另外定義大小關係
4. 排序用於字串類型的資料，則依**字典序**進行排序
5. `#include<algorithm>`

### sort 函式使用方式
1. 對整數陣列`int a[n];`進行排序：`sort(a, a + n);`
2. 對`vector<int> v(n);`進行排序：`sort(v.begin(), v.end());`
3. 對`string s;`內部進行排序：`sort(s.begin(), s.end());`

## 資料型態的範圍
| 資料型態 | 使用記憶體空間 | 儲存範圍 |
|:----:|:----:|:--------:|
| int | 32 bits | $-2^{31}\sim2^{31}-1$ |
| long long | 64 bits | $-2^{63}\sim2^{63}-1$ |
| short | 32 bits | $-2^{15}\sim2^{15}-1$ |
| char | 8 bits | $0\sim256$ |
| string | 動態調整 | × |

### 超出範圍的資料可處置方式（通常指整數的大數運算）
1. 使用陣列（vector）模擬，陣列之中每個元素僅儲存一位
2. 使用字串模擬，字串之中的文字只使用`'0' ~ '9'`