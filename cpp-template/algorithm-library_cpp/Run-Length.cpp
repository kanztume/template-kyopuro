/*ランレングス圧縮 (Run-Length Encoding / RLE)
  連続する同じ要素を {値, 連続する個数} のペア配列に圧縮する。
  計算量: 時間 O(N) / 空間 O(N)
  使い方:auto v = rle(s);
*/
template <typename T>
vector<pair<T, ll>> rle(const vector<T>& a) {
    vector<pair<T, ll>> res;
    for (const auto& x : a) {
        if (res.empty() || res.back().first != x) {
            res.push_back({x, 1});
        } else {
            res.back().second++;
        }
    }
    return res;
}

vector<pair<char, ll>> rle(const string& s) {
    vector<pair<char, ll>> res;
    for (char c : s) {
        if (res.empty() || res.back().first != c) {
            res.push_back({c, 1});
        } else {
            res.back().second++;
        }
    }
    return res;
}
