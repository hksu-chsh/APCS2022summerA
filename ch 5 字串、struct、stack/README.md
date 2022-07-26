# 07/13 課程補充內容

## stringstream
1. 字串串流，是有別於 string 的另一種型態
2. 類似用來輸出輸入的 `iostream`，你可以把它想像成一個由你所建立的資料緩衝區
3. `#include<sstream>`
4. `stringstream ss;`
5. 使用方法類似 cin, cout，只是需改成該字串串流的名稱
6. 可使用 `clear()` 清空串流
7. 特殊技巧：可用於資料型態的轉換（數值⇔文字）
```cpp=
#include<bits/stdc++.h>
using namespace std;
int main(){
    stringstream ss;
    string s1, s2;
    cin >> s1;
    int n;
    ss << s1;
    ss >> n;	// 要進行此步驟的話，串流內的資料必須要是能被轉成整數型態的資料
    cout << n << endl;
    ss.clear();
    ss << s1;
    ss >> s2;
    cout << s2 << endl;
}
```
## Runtime Error
1. 執行期間錯誤，通常代表通過語法檢查，但程式執行中途出現未預期的錯誤
2. 通常發生於下列情形：
    - 數值除以 0
    - 取得超過 STL 容器範圍的元素
    - 錯誤的執行 pop 的相關指令（`pop(), pop_front(), pop_back()` 等） 

## deque
1. double-ended queue：雙向佇列
2. `#include<deque>`
### deque 常用成員函式，以 `deque<int> deq;` 為例
1. `bool deq.empty()`：回傳 deq 是不是空的（true / false）
2. `sizt_t deq.size()`：回傳 deq 內的資料數量
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
2. `sizt_t pq.size()`：回傳 pq 內的資料數量
3. `void pq.push(data)`：在 pq 內新增一筆資料
4. `void pq.pop()`：移除 pq 優先權最高的一筆資料
5. `int pq.top()`：取得 pq 優先權最高的一筆資料
6. `void pq.clear()`：清除 pq 中的所有資料