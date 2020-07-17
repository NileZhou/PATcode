#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct node {
    double time, ptime; // process time
};

bool cmp(node a, node b) {
    return a.time < b.time;
}

/**
 * out of main() can't assign value, or the compiler will throw error
 */

int main() {
    int n, k, ncust, h, m, sec, deal_cnt=0;
    double stime=8*60, etime=17*60, res=0, tail_times[100]={8*60}, wait_time=0;
    string s;
    vector<node> nodes;
    
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        node customer;
        cin >> s >> customer.ptime;
        sscanf(s.c_str(), "%d:%d:%d", &h, &m, &sec);
        customer.time = h * 60.0 + m + sec / 60.0;
        if (customer.time < etime) {
            nodes.push_back(customer);
        }
    }
    ncust = nodes.size();
    sort(nodes.begin(), nodes.end(), cmp); // sort a vector
    for (int i=0; i<ncust; ++i) {
        int min_i=0 , min_time=tail_times[0];
        for (int j=1; j<k; ++j) {
            if (tail_times[j] < min_time) {
                min_time = tail_times[j];
                min_i = j;
            }
        }
        if (min_time < etime) { // deal
            if (nodes[i].time >= min_time) { // dosen't need to wait
                tail_times[min_i] = nodes[i].time + nodes[i].ptime;
            } else {
                wait_time += min_time - nodes[i].time;
                tail_times[min_i] += nodes[i].ptime;
            }
            ++deal_cnt;
        } else {
            break;
        }
    }

    printf("%.1lf\n", wait_time / deal_cnt);

    return 0;
}

