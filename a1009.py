from collections import OrderedDict

la = list(map(float, input().strip().split()))
lb = list(map(float, input().strip().split()))

ta = [tuple(la[i: i+2]) for i in range(1, len(la), 2)]
tb = [tuple(lb[i: i+2]) for i in range(1, len(lb), 2)]

dt = OrderedDict()

for i, a in enumerate(ta):
    for j, b in enumerate(tb):
        if dt.get(a[0]+b[0], None) is None:
            dt[a[0]+b[0]] = a[1]*b[1]
        else:
            dt[a[0]+b[0]] += a[1]*b[1]
for k, v in dt.items():
    dt[k] = round(v, 1)
print(len(dt), end=' ')
b = [str(int(tup[0])) + ' ' + str(tup[1]) for tup in dt.items()]
print(' '.join(b))
