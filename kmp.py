from typing import List


def get_next(pat:str) -> List[int]:
    """
    arr[i]代表pat[0: i+1]的最长公共前缀最后一位的下标
    """
    arr = [-1 for _ in range(len(pat))]  # 默认arr[0]和arr[1]都是-1
    j = -1
    for i in range(1, len(pat)):
        while j != -1 and pat[i] != pat[j + 1]:
            j = arr[j]
        if pat[i] == pat[j + 1]:
            j += 1
        arr[i] = j

    return arr


def kmp(s: str, pat: str) -> int:
    arr = get_next(pat)
    i, j = 0, 0
    m, n = len(s), len(pat)
    while i < m - n + 1 and j < n:
        while j != -1 and pat[j] != s[i]:
            j = arr[j]
        if j == -1:
            j = 0
        else:
            j += 1
        i += 1
    if j == n:
        return i-j
    else:
        return -1


if __name__ == '__main__':
    s = input('输入原字符串: ').strip()
    pat = input('模式串: ').strip()
    res = kmp(s, pat)
    print(res)
    print(get_next(pat))

