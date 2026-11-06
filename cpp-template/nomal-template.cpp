// URL: https://github.com/kanztume/template-kyopuro

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end() //配列の前から全範囲
#define rall(v) v.rbegin(), v.rend() // 配列の後ろから全範囲
#define yes cout << "Yes" << "\n" // Yes出力 
#define no cout << "No" << "\n"  // No出力

//定数まとめ
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

//二次元配列ショートカット
//auto [変数名] = make_vec2<型>([縦], [横], [初期値]);
template <typename T>
inline vector<vector<T>> make_vec2(const size_t H, const size_t W, const T& init) {
    return vector<vector<T>>(H, vector<T>(W, init));
}
template <typename T>
inline vector<vector<T>> make_vec2(const size_t H, const size_t W) {
    return vector<vector<T>>(H, vector<T>(W));
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 小数点用
    cout << fixed << setprecision(15);

    // --- ここから下にコードを書く ---
    
    // --- ここから上にコードを書く ---
}
