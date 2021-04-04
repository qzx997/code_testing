# module time

import time

t = time.time()
print(t)

# 时间戳 ————》 string
s = time.ctime(t)
print(s)

# 时间戳 ————》 tuple
tup = time.localtime(t)
tup1 = time.localtime(1659817591.35178)
print(tup, '***************', tup1)
print(tup.tm_yday)
print(tup.tm_hour)

# tuple  -----> 时间戳
tt = time.mktime(tup)
print(tt)

# tuple ————》 string
ts = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
ts1 = time.strftime('%Y-%m-%d %H:%M:%S', tup)
print(ts, '  ', ts1)

# string --> tuple
r = time.strftime('%Y/%m/%d', time.localtime())
r1 = time.strptime(r, '%Y/%m/%d')
print(r1)