#include <bits/stdc++.h>
using namespace std;

/* 尺取り法 (Two Pointers) 計算量: O(N)
   呼び出し方: long long ans = two_pointers([要素数], [上限], [データ]);

   使い方:
     1. 左端 left を固定し、条件を満たす限界まで右端 right を進める。
     2. [left, right) の半開区間（left 以上 right 未満）で状態を管理する。
     3. left が1つ右へ進む前に、A[left] の分を状態から取り除く。

   引数:
     N: 配列の要素数
     K: 条件のしきい値（合計の上限など）
     A: 対象の配列（正の整数など単調性があるもの）

   戻り値:
     long long: 条件を満たす連続部分列の個数（または最大長）

   注意:
     - right が left に追いつかれた場合（right == left）は right を 1 つ進めてリセットする。
     - 負の数が含まれる配列では単調性が崩れるため使えない（その場合は累積和＋二分探索などを使う）。
   
   URL: https://github.com/kanztume/template-kyopuro
*/

long long two_pointers(int N, long long K, const vector<long long>& A) {
    long long ans = 0;
    long long current_sum = 0; // 区間 [left, right) の現在の状態（合計値など）
    int right = 0;

    for (int left = 0; left < N; left++) {
        // 1. 条件を満たす限り right を右へ伸ばす
        while (right < N && current_sum + A[right] <= K) {
            current_sum += A[right];
            right++;
        }

        // 【問題ごとにここを書き換える】
        
        // 例A: 条件を満たす連続部分列の「個数」を数える場合
        //ans += (right - left);
    
        // 例B: 条件を満たす連続部分列の「最大長」を求める場合
        // ans = max(ans, (long long)(right - left));

        // 3. left を1つ進める準備（A[left] を区間から外す）
        if (right == left) {
            // 1要素も選べなかった場合は right も一緒に進める
            right++;
        } else {
            current_sum -= A[left];
        }
    }

    return ans;
}
