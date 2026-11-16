# URL: https://github.com/kanztume/template-kyopuro

import sys
import time
import random
from collections import deque, defaultdict, Counter
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right

# 高速入出力（大量の入力・出力がある問題やAHCで必須）
input = sys.stdin.readline

# 再帰上限の緩和（DFSなどで RecursionError を防ぐ）
sys.setrecursionlimit(10**7)

# 定数まとめ
INF = 10**18
MOD = 998244353
ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
abc = "abcdefghijklmnopqrstuvwxyz"

# 4方向・8方向移動ベクトル（グリッド探索用）
DIRS4 = ((1, 0), (-1, 0), (0, 1), (0, -1))
DIRS8 = ((1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1))

# 入力ショートカット
def II() -> int:
    return int(input())

def MI():
    return map(int, input().split())

def LI() -> list[int]:
    return list(map(int, input().split()))

def SI() -> str:
    return input().rstrip()

def LLI(H: int) -> list[list[int]]:
    return [LI() for _ in range(H)]

# 2次元配列ショートカット（C++ の make_vec2 相当）
def make_vec2(H: int, W: int, init=0) -> list[list]:
    return [[init] * W for _ in range(H)]


def solve():
    # --- ここから下にコードを書く ---
    START_TIME = time.perf_counter()

    N = II()
    A = LI()

    print(N)
    # --- ここから上にコードを書く ---


if __name__ == "__main__":
    solve()
