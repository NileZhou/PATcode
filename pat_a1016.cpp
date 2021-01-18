#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int maxn = 1000;

struct record {
    string name;
<<<<<<< HEAD
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
=======
    int status, time, month, day, hour, minute;
}records[maxn];

bool cmp(record a, record b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}

double fees[24];

double sum_fees() {
    double res = 0;
    for (int i=0; i<24; ++i) {
        res += fees[i] * 60;
    }

    return res;
} 

double cal_price(record a, record b) { // a < b
    double res = 0;
    if (a.day == b.day) {
        int h = a.hour+1;
        while (h < b.hour) {
            res += fees[h++] * 60 ;
        }

        if (a.hour == b.hour) {
            res += (b.minute - a.minute) * fees[a.hour];
        } else {
            res += (60.0 - a.minute) * fees[a.hour];
            res += b.minute * fees[b.hour];
        }
    } else { // crossdays
        int day = a.day + 1;
        while (day++ < b.day) {
            res += sum_fees();
        }
        record c = a;
        c.hour = 23;
        c.minute = 60;
        
        record d = b;
        d.hour = 0;
        d.minute = 0;
        
        res += cal_price(a, c) + cal_price(d, b);
    }

    return res;
}

int main() {
    int n;
    string time, status;
    for (int i=0; i<24; ++i) {
        cin >> fees[i];
        fees[i] = fees[i] / 100; // dollar which every minute costs
    }
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> records[i].name >> time >> status;
        if (status == "on-line") {
            records[i].status = 0;
        } else {
            records[i].status = 1;
        }
        sscanf(time.c_str(), "%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
        records[i].time = (records[i].day - 1) * 24 * 60 + records[i].hour * 60 + records[i].minute;
    }
    
    sort(records, records+n, cmp);

    int pre_i = -1;
    map<string, vector<record> > mp;

    for (int i=0; i<n; ++i) {
        if (pre_i == -1) { // expect an on-line
            if (records[i].status == 0) {
                pre_i = i;
            }
        } else { // expect an off-line
            if (records[i].status == 1) {
                if (records[i].name == records[pre_i].name) {
                    // put a pair
                    if (mp.find(records[i].name) == mp.end()) {
                        vector<record> v;
                        mp[records[i].name] = v;
                    }
                    mp[records[i].name].push_back(records[pre_i]);
                    mp[records[i].name].push_back(records[i]);
                }
                pre_i = -1;
            } else {
                pre_i = i;
            }
        }
    }

    map<string, vector<record> >::iterator it;
    for (it=mp.begin(); it != mp.end(); ++it) {
        printf("%s %02d\n", it->first.c_str(), it->second[0].month);
        int size = it->second.size();
        double pri=0, res=0;
        for (int i=0; i<size/2; ++i) {
            record a = it->second[2*i], b = it->second[2*i+1];
            pri = cal_price(a, b);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", a.day, a.hour, a.minute, b.day, b.hour, b.minute, b.time-a.time, pri);
            res += pri;
        }
        printf("Total amount: $%.2lf\n", res);
    }
>>>>>>> 72b0de2e57f628ea2118c9005ff488cbc5b9c903
    
    return 0;
}


