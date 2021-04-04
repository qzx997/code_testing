# module datetime

import datetime, time

print(datetime.time.hour)
print(time.localtime().tm_hour)

d = datetime.date(2021, 1, 10)
print(datetime.date.day)
print(datetime.date.ctime(d))

print(datetime.date.today())

timedel = datetime.timedelta(hours=2, minutes=61)
print(timedel)

now = datetime.datetime.now()
result = now - timedel
print(now)
print(result)
