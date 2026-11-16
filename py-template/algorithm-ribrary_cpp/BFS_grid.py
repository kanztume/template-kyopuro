# URL: https://github.com/kanztume/template-kyopuro

from collections import deque

""" グリッド上の幅優先探索 (BFS - Grid) 計算量: O(H * W)
    呼び出し方:
      dist, parent = bfs_grid(H, W, grid, sy, sx)

    使い方:
      1. 0-indexed のグリッド（list[str] または 2次元 list）と始点 (sy, sx) を渡す。
      2. 返り値 dist[y][x] に最短移動回数（未到達は -1）、parent[y][x] に直前の座標 (py, px) が入る。
      3. 経路復元が不要な場合は `dist, _ = bfs_grid(...)` で受け取る。
      4. AHCで高速化したい場合は、毎回関数を呼ぶのではなく deque と dist の再利用を検討する。

    引数:
      H (int): グリッドの高さ（行数）
      W (int): グリッドの幅（列数）
      grid (list): 盤面データ（list[str] または list[list]）
      sy (int): 始点の行番号（0-indexed）
      sx (int): 始点の列番号（0-indexed）
      wall (str/int): 通行できない壁を表す値（デフォルトは '#'）

    戻り値:
      tuple[list[list[int]], list[list[tuple[int, int] | None]]]:
        - dist: 各マス (y, x) への最短移動回数（到達不可なら -1）
        - parent: 最短経路で直前にいた座標 (py, px)（始点や到達不可なら None）

    注意:
      - 座標は必ず「0-indexed（0 <= y < H, 0 <= x < W）」で渡すこと。
      - Python は関数呼び出しやタプル生成のコストがあるため、AHC の焼きなましループ内などで
        数万回呼ぶ場合は、PyPy3 で実行し、タプルではなく 1次元インデックス (y * W + x) で管理すると数倍速くなる。

    URL: https://github.com/kanztume/template-kyopuro
"""

def bfs_grid(H: int, W: int, grid: list, sy: int, sx: int, wall='#') -> tuple:
    # 4方向（下, 上, 右, 左）の移動ベクトル
    DIRS = ((1, 0), (-1, 0), (0, 1), (0, -1))

    dist = [[-1] * W for _ in range(H)]
    parent = [[None] * W for _ in range(H)]

    dist[sy][sx] = 0
    que = deque([(sy, sx)])

    while que:
        y, x = que.popleft()
        next_d = dist[y][x] + 1

        for dy, dx in DIRS:
            ny = y + dy
            nx = x + dx

            # 1. グリッドの範囲外チェック
            if not (0 <= ny < H and 0 <= nx < W):
                continue
            # 2. 壁チェック
            if grid[ny][nx] == wall:
                continue
            # 3. 訪問済みチェック
            if dist[ny][nx] != -1:
                continue

            dist[ny][nx] = next_d
            parent[ny][nx] = (y, x)
            que.append((ny, nx))

    return dist, parent
