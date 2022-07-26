# 07/11 課程補充內容

## lower_bound（講義p. 118）
1. C++之中用於搜尋資料的函式（二分搜尋）
2. 需要有一個 target
3. lower_bound 會找出不小於 target 的第一筆符合資料（不一定剛好是 target）
4. 在使用之前請確定資料已經確實排序完成
5. 所需搜尋的資料必須可以互相比較大小（具備可比性），否則必須自行另外定義大小關係（使用`cmp`函式）
6. `#include<algorithm`
7. * 此外，還有 upper_bound 函式，會找出大於 target 的第一筆符合資料，其使用方法與 lower_bound 雷同

### lower_bound 函式使用方式
1. 對整數陣列`int a[n];`進行搜尋，目標為 target，找出其所在位置 pos：`int pos = lower_bound(a, a + n, target) - a;`
2. 對`vector<int> v(n);`進行搜尋，目標為 target，找出其所在位置 pos：`int pos = lower_bound(v.begin(), v.end(), target) - v.begin();`

## 多重 vector
1. `vector<data_type> v;` 之中，除了基本資料型態（int等）以外，也可以使用一些比較複雜的資料型態，甚至其他STL，例如：放入另一個 vector，或是 pair等。
2. 必須特別注意：vector 之中放入另一個 vector，必須在裡面那層指定其型態，例如：`vector<vector<int>> v;`，我們把外層稱作**大 vector**，內層稱作**小 vector**
3. 上述範例如同二維陣列一般，但有點差別的是，大 vector 裡面存放的每一個小 vector，個別的長度也可以動態的調整，比起二維陣列，雙重 vector 更像一個雙重的 list
4. 以雙重 vector 直接開一個擁有 n 個空的小 vector 的大 vector：`vector<vector<int>> v(n);`
5. 以雙重 vector 直接開一個 $m\times n$ 的擬似二維陣列：`vector<vector<int>> v(m, vector<int>(n));`

![](https://i.imgur.com/4FqjPO1.png)

## 字串進階應用（以字串 str, str1, str2 為例）
### substr
1. `str.substr(from, len)`：從某字串 str 之中，取得從 `from` 的位置開始連續 `len` 個字元，並作為一個新的字串回傳
2. 如果 `len` 沒有指定，而僅傳入一個參數 `from`，則代表取至這個字串的結尾
```cpp=
string str = "hello";
cout << str.substr(1, 3) << endl;    // 輸出 "ell"
cout << str.substr(1) << endl;    // 輸出 "ello"
```

### find
1. str1.find(str2)：搜尋 str2 在 str1 之中第一次出現的位置
2. 如果在 str1 之中沒有發現 str2，則會得到一個常數 `string::npos`
```cpp=
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1 = "There is one needle.";
    string str2 = "needle";
    size_t found = str1.find(str2);
    if (found != string::npos)
    cout << "第一個 needle 出現在" << found << '\n';
}
```

### stringstream
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