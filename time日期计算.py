import time, math

n1 = '2020-09-21 13:00:00'
n2 = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time()))

struct_time1 = time.strptime(n1, '%Y-%m-%d %H:%M:%S')
struct_time2 = time.strptime(n2, '%Y-%m-%d %H:%M:%S')

struct_time1, struct_time2 = time.mktime(struct_time1), time.mktime(struct_time2)

diff_time = struct_time2 - struct_time1

print('python课开始距离今天{}天'.format(math.ceil(diff_time / (24 * 60 * 60))))
