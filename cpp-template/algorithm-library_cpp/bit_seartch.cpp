#include <bits/stdc++.h>
using namespace std;

/* bit全探索 (O(2^N * N)
    呼び出し方:
     bit_search([要素数], [データ])
     
    使い方:
     要素数 N 個の全部分集合（2^N 通り）を探索する。
     N は 20 程度まで対応可能。

     URL: https://github.com/kanztume/template-kyopuro
*/

void bit_search(int N, const vector<long long>& A) {
    // 1 << N は 2^N を意味する
    for (int bit = 0; bit < (1 << N); bit++) {
        long long sum = 0;
        vector<int> selected_indices;

        for (int i = 0; i < N; i++) {
            // i 番目の要素が選ばれているか判定 (bitのi桁目が1かどうか)
            if ((bit >> i) & 1) {
                sum += A[i];
                selected_indices.push_back(i);
            }
        }

        // 【問題ごとにここに処理を書く】
        // 例: sum == Target の判定や、条件を満たす最適値の更新など
    }
}
