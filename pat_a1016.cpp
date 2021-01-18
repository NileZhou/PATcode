#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int maxn = 1000;

struct record {
    string name;
    // status： 0_on-line, 1_off-line
    int status, month, day, hour, minute, time;
}records[maxn];

// map-link结构可以做 map<string, <vector> >
// 两重sort是关键
bool cmp(record a, record b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}

int price(record a, record b, int fees[]) {
    int res = 0;
    if (a.day != b.day) {
        record c = a;
        c.hour = 23;
        c.minute = 60;
        record d = b;
        d.hour = 0;
        d.minute = 0;
        return price(a, c) + price(d, b);
    } else {
        int h = a.hour + 1;
        while (h < b.hour) {
            res += fees[h];
        }
        if (a.hour == b.hour) {
            res += (b.minute - a.minute) / 60 * fees[a.hour];
        } else {
            res += (60 - a.minute) / 60 * fees[a.hour];
            res += b.minute / 60 * fees[b.hour];
        }
    }

    return res;
}

int main() {
    int fees[24], n;
    string t;
    string status = "on-line", tmp;

    for (int i=0; i<24; ++i) cin >> fees[i];
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> records[i].name >> t >> tmp;
        sscanf(t.c_str(), "%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
        if (tmp == status) {
            records[i].status = 0;
        } else {
            records[i].status = 1;
        }
        records[i].time = 24 * 60 * records[i].day + 60 * records[i].hour + records[i].minute;
    }
    
    int pre_i = -1; // -1 means that need a new pre_i
    for (int i=0; i<n ++i) {
        if (pre_i == -1) {
            if (records[i].status == 1) continue;
            pre_i = i;
        } else {
            if (records[i].name != records[i-1].name) {
                if (records[i].status == 0) {
                    pre_i = i;
                }
            } else {
                if (records[i].status == 0) {
                    pre_i = i;
                } else {
                    // calculate the price
                    price(records[pre_i], records[i]);
                    pre_i = -1;
                }
            }
        }
    }
    
    for (int i=0; i<n; ++i) {
        cout << records[i].time << " " << endl;
    }
    
    return 0;
}


