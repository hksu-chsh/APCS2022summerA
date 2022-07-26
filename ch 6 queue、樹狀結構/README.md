# 07/15 課程補充內容

## deque
1. double-ended queue：雙向佇列
2. `#include<deque>`
### deque 常用成員函式，以 `deque<int> deq;` 為例
1. `bool deq.empty()`：回傳 deq 是不是空的（true / false）
2. `size_t deq.size()`：回傳 deq 內的資料數量
3. `void deq.push_front(data)`：在 deq 前端新增一筆資料
4. `void deq.push_back(data)`：在 deq 後端新增一筆資料
5. `void deq.pop_front()`：在 deq 前端移除一筆資料
6. `void deq.pop_back()`：在 deq 後端移除一筆資料
7. `int deq.front()`：取得 deq 前端的資料
8. `int deq.back()`：取得 deq 後端的資料
9. `void deq.clear()`：清除 deq 中的所有資料

## priority_queue
1. priority queue：優先權佇列
2. `#include<priority_queue>`
3. pop() 的預設優先順序為由大到小，但也可以改為由小到大，或是自行定義
### 宣告方式
1. `priority_queue<int> pq;`：由大到小
2. `priority_queue<int, vector<int>, greater<int>> pq;`：由小到大
* 上述 `priority_queue` 的資料型態，如果不是整數，請將 `int` 全數改為所需設定的資料型態
### priority_queue 常用成員函式，以 `priority_queue<int> pq;` 為例
1. `bool pq.empty()`：回傳 pq 是不是空的（true / false）
2. `size_t pq.size()`：回傳 pq 內的資料數量
3. `void pq.push(data)`：在 pq 內新增一筆資料
4. `void pq.pop()`：移除 pq 優先權最高的一筆資料
5. `int pq.top()`：取得 pq 優先權最高的一筆資料
6. `void pq.clear()`：清除 pq 中的所有資料

## 模擬樹的 4 種方式
### 1. 單一陣列模擬二元樹
1. 以 0 為樹根
    - left child： x * 2 + 1
    - right child： x * 2 + 2
    - parent： (x - 1) / 2
    -  n 層二元樹的最多節點數量： $2^n - 1$
    -  n 層二元樹的最大節點編號： $2^n - 2$
![](https://i.imgur.com/pQ0skeO.png =600x300)
2. 以 1 為樹根
    - left child： x * 2
    - right child： x * 2 + 1
    - parent： x / 2
    -  n 層二元樹的最多節點數量： $2^n - 1$
    -  n 層二元樹的最大節點編號： $2^n - 1$
![](https://i.imgur.com/gHsmfSa.png =600x300)

#### 優點
1. 方便實作，開一個夠大的陣列即可
2. 親子節點的關係簡單好算
3. 方便找根
4. 可用同樣的方法擴展至 n 元樹（但空間的浪費會更明顯）
#### 缺點
1. 容易造成空間的浪費
2. 不適合在不知道根節點編號的情況下使用
3. 不利於存取更多的節點資訊

### 2. 兩個陣列模擬二元樹
```cpp
int leftchild[10] = {-1, 3, 8, 4, -1, -1, 9, -1, -1};
int rightchild[10] = {-1, 5, 0, 7, 6, 2, -1, -1, -1, -1};
```
![](https://i.imgur.com/WniJwZy.png =600x300)

#### 優點
1. 僅需依照節點數量開啟對應大小的陣列，但節點編號必須連續，且不得為負數
2. 相較於前者，更適合在不知道根節點編號的情況下使用
#### 缺點
1. 每次建立一棵樹都需要兩個陣列
2. 難以回溯每個節點的 parent 是誰
3. 資料量大時不好找根
4. 較適用於二元樹


### 3. 使用 `vector<vector<int>>` 模擬二元樹
![](https://i.imgur.com/WniJwZy.png =600x300)
```cpp
vector<vector<int>> v(n);
for(int i=0;i<n-1;i++){
    int parent, child;
    cin >> parent >> child;
    v[parent].push_back(child);
}
```
#### 優點
1. 僅需依照節點數量開啟對應大小的 `vector<vector<int>>`，但節點編號必須連續，且不得為負數
2. 適合在不知道根節點編號的情況下使用
3. 同樣的程式也可直接套用至多元樹
4. 如需存成有標記「左/右」節點的二元樹，也可以改成 `vector<pair<int, int>>` 使用
#### 缺點
1. 難以回溯每個節點的 parent 是誰（但多開一個 vector 儲存即可解決）
2. 節點編號不連續時，可能造成空間浪費（但以大多數題目來說，這不太算是問題）

### 4. 使用 `map<int, vector<int>>` 模擬二元樹
**（map 的詳細使用方法會在 圖形結構 的章節之中詳細介紹）**
![](https://i.imgur.com/WniJwZy.png =600x300)
```cpp
map<int, vector<int>> m;
for(int i=0;i<n-1;i++){
    int parent, child;
    cin >> parent >> child;
    m[parent].push_back(child);
}
```
#### 優點
1. 僅需依照節點數量開啟對應大小的 `map<int, vector<int>>`，且節點可不連續、可為負數
2. 真正的「有幾個節點就使用多少空間」
3. 適合在不知道根節點編號的情況下使用
4. 同樣的程式也可直接套用至多元樹
5. 如需存成有標記「左/右」節點的二元樹，也可以改成 `map<int, pair<int, int>>` 使用
#### 缺點
1. 難以回溯每個節點的 parent 是誰（但多開一個 map 儲存即可解決）