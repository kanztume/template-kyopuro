/* グラフ上の幅優先探索 (BFS - Graph) 計算量: O(V + E)
   呼び出し方:
     auto [dist, parent] = bfs_graph([頂点数], [隣接リスト], [始点]);

   使い方:
     1. 1-indexed ならサイズ N+1、0-indexed ならサイズ N の隣接リスト G を渡す。
     2. 未訪問の頂点は dist[i] == -1 になっている。
     3. 経路復元（直前にいた頂点）が不要な場合は dist だけ使えばよい。

   引数:
     N: グラフの頂点数（1-indexed の場合は N + 1 を渡す）
     G: 隣接リスト vector<vector<int>>
     start: 探索を開始する始点

   戻り値:
     pair<vector<int>, vector<int>>:
       - first (dist): 始点からの最短移動回数（到達不可なら -1）
       - second (parent): 最短経路で直前にいた頂点（始点や到達不可なら -1）

   注意:
     - 辺の重みがすべて 1（または重みなし）のグラフでのみ最短経路が求まる。
     - 1-indexed の頂点番号（1 〜 N）を使う場合は、引数 N に「N + 1」を渡すこと！
   
   URL: https://github.com/kanztume/template-kyopuro
*/

pair<vector<int>, vector<int>> bfs_graph(int N, const vector<vector<int>>& G, int start) {
    vector<int> dist(N, -1);
    vector<int> parent(N, -1);
    queue<int> que;

    dist[start] = 0;
    que.push(start);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int nxt : G[cur]) {
            if (dist[nxt] != -1) continue; // 訪問済みならスキップ
            dist[nxt] = dist[cur] + 1;
            parent[nxt] = cur;             // cur から nxt へ来たことを記録
            que.push(nxt);
        }
    }

    return {dist, parent};
}
