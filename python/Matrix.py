class Matrix:
    def __init__(self, ls):
        self.__n = len(ls)
        self.__ls = ls

    def __add__(self, other):
        ls = []
        for i in range(self.__n):
            ls.append([])
            for j in range(self.__n):
                a = self.__ls[i][j] + other.__ls[i][j]
                ls[i].append(a)
        return Matrix(ls)

    @property
    def t(self):
        ls = []
        for i in range(self.__n):
            ls.append([])
            for j in range(self.__n):
                ls[i].append(self.__ls[j][i])
        return Matrix(ls)

    def __mul__(self, other):
        ls = []
        for i in range(self.__n):
            ls.append([])
            for j in range(self.__n):
                a = self.__ls[i][j] * other
                ls[i].append(a)
        return Matrix(ls)

    def multiple(self, other):
        ls = []
        for i in range(self.__n):
            ls.append([])
            for j in range(self.__n):
                a = 0
                for k in range(self.__n):
                    a += self.__ls[i][k] * other.t.__ls[j][k]
                ls[i].append(a)
        return Matrix(ls)

    def __sub__(self, other):
        ls = []
        for i in range(self.__n):
            ls.append([])
            for j in range(self.__n):
                a = self.__ls[i][j] - other.__ls[i][j]
                ls[i].append(a)
        return Matrix(ls)

    def __str__(self):
        s = ''
        for i in range(self.__n):
            for j in range(self.__n):
                s += '{} '.format(self.__ls[i][j])
            s += '\n'
        return s


if __name__ == '__main__':
    # m1 = Matrix([[1, 1, 1], [2, 2, 2], [3, 3, 3]])
    # m2 = Matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

    while 1:
        try:
            n = int(input("请输入矩阵的阶数n："))
            if n > 1:
                break
            else:
                print("请输入一个大于1的整数！")
        except:
            print("请输入一个大于1的整数！")

    while 1:
        print("a.加法 b.减法 c.数乘 d.转置 e.矩阵乘法")
        try:
            s = input("请输入对应字母选择运算类型：")
            if s in 'abcde':
                break
            else:
                print("请选择以下字母")
        except:
            print("请选择以下字母")

    # 矩阵A的读入
    lsa = [[0] * n] * n
    for i in range(n):
        while 1:
            try:
                l = list(map(int, input("请输入矩阵A的第{}行：".format(i + 1)).split()))
                if len(l) == n:
                    break
                else:
                    print("请输入n个整数")
            except:
                print("请输入n个整数")
        lsa[i] = l
    m1 = Matrix(lsa)

    if s == 'a' or s == 'b' or s == 'e':
        # 矩阵B的读入
        lsb = [[0] * n] * n
        for i in range(n):
            while 1:
                try:
                    l = list(map(int, input("请输入矩阵B的第{}行：".format(i + 1)).split()))
                    if len(l) == n:
                        break
                    else:
                        print("请输入n个整数")
                except:
                    print("请输入n个整数")
            lsb[i] = l
        m2 = Matrix(lsb)

    # m1 = Matrix([[1, 1], [2, 2]])
    # m2 = Matrix([[1, 2], [3, 4]])

    if s == 'a':
        print('A+B的结果为：\n')
        print(m1 + m2)
    if s == 'b':
        print('A-B的结果为：\n')
        print(m2 - m1)
    if s == 'c':
        a = int(input("请输入数乘的数："))
        print('数乘结果为：\n')
        print(m1 * a)
    if s == 'd':
        print('A矩阵的转置为：\n')
        print(m1.t)
    if s == 'e':
        print('A*B的结果为：\n')
        print(m1.multiple(m2))
