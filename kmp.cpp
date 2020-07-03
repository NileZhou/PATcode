#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 这是一种方法
vector<int> get_next(string pat) {
    vector<int> next;
    if (pat.size() == 0) return next;
    next.push_back(0);
    if (pat.size() == 0) return next;
    int i = 0, j = 1;
    while (i < pat.size() && j < pat.size()) {
        if (pat[j] == pat[i]) {
            next.push_back(i + 1);
            ++i;
            ++j;
        } else {
            if (i == 0) {
                next.push_back(0);
                ++j;
            } else {
                while (i >= 1 && pat[i] != pat[j]) {
                    i = next[i - 1];
                }
                if (pat[i] == pat[j]) {
                    next.push_back(i + 1);
                    ++i;
                    ++j;
                } else {
                    next.push_back(0);
                    ++j;
                }
            }
        }
    }

    return next;
}


int kmp(string s, string pat) {
    vector<int> next = get_next(pat);
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
        while (j > 0 && s[i] != pat[j]) j = next[j - 1];
        if (s[i] == pat[j]) ++j;
        if (j == pat.length()) return i - pat.length() + 1;
    }

    return -1;
}

vector<int> getNext(string pat) {
    int i=0, v=-1; // 这样设置init status
    int plen = pat.length();
    vector<int> next = {-1}; // 其实这个vector最后的长度不会有plen那么长
    while (i < plen) {
        if (v == -1 || pat[i] == pat[v]) { // 其实退无可退和匹配成功是一种解决方案
            ++i; ++v;
            next.push_back(v);
        } else {
            v = next[v];
        }
    }

    return next;
}


int KMP(string s, string pat) {
    vector<int> next = getNext(pat);
    int plen = pat.length(), slen = s.length();
    int ip=0, is=0; // index of pattern, index of string
    while (ip < plen && is < slen) {
        if (ip == -1 || pat[ip] == s[is]) {
            ++ip; ++is;
        } else {
            ip = next[ip];
        }
    }
    if (ip < plen) return -1;
    else return is - plen;
}


int main() {
    string s, pat;

    cin >> s;
    cin >> pat;

    cout << KMP(s, pat) << endl;

    return 0;
}
