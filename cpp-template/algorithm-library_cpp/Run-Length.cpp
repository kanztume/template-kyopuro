// ==========================================
// ランレングス圧縮 (Run-Length Encoding)
// 計算量: O(N)
// ==========================================
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

// 文字列用
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
