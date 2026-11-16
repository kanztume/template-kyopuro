#include <bits/stdc++.h>
using namespace std;

/* グリッド上の幅優先探索 (BFS - Grid) 計算量: O(H * W)
   呼び出し方:
     auto dist = bfs_grid([縦H], [横W], [グリッド], [始点行sy], [始点列sx], [壁文字]);

   使い方:
     1. 0-indexed のグリッド（vector<string>）と、始点の座標 (sy, sx) を渡す。
     2. 返り値 dist[y][x] に、始点からの最短移動回数が入る（到達不可のマスは -1）。
     3. 斜め移動も含む8方向にしたい場合は、dy, dx を8要素に書き換える。

   引数:
     H: グリッドの高さ（行数）
     W: グリッドの幅（列数）
     grid: 盤面データ vector<string>
     sy: 始点の行番号（0-indexed）
     sx: 始点の列番号（0-indexed）
     wall: 通行できない壁を表す文字（デフォルトは '#'）

   戻り値:
     vector<vector<int>>: 各マス (y, x) への最短移動回数（到達不可なら -1）

   注意:
     - 座標は必ず「0-indexed（0 〜 H-1, 0 〜 W-1）」で渡すこと（1-indexed 入力なら -1 する）。
     - 複数スタート地点（多始点BFS）の場合は、dist の初期化後に複数の始点を que に push する形へ改変する。
     - 壁の判定条件が複雑な場合（特定の文字以外通れない等）は、grid[ny][nx] == wall の行を書き換える。

   URL: https://github.com/kanztume/template-kyopuro
*/

vector<vector<int>> bfs_grid(int H, int W, const vector<string>& grid, int sy, int sx, char wall = '#') {
    // 4方向（下, 上, 右, 左）の移動ベクトル
    const int dy[4] = {1, -1, 0, 0};
    const int dx[4] = {0, 0, 1, -1};

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;

    dist[sy][sx] = 0;
    que.push({sy, sx});

    while (!que.empty()) {
        auto [y, x] = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 1. グリッドの範囲外チェック
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            // 2. 壁チェック
            if (grid[ny][nx] == wall) continue;
            // 3. 訪問済みチェック
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            que.push({ny, nx});
        }
    }

    return dist;
}
