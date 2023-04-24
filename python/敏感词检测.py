import re


def check_filter(key, t):
    return re.sub("|".join(key), "***", t)


keywords = ("暴力", "色情", "草你妈", "狗逼", "傻逼", "婊子", "卧槽", "他妈的", "她妈的")  # 有个暴力的傻逼说了一句卧槽，她妈的狗逼，她就是个婊子
text = input()
print(check_filter(keywords, text))
