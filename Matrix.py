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
    m1 = Matrix([[1, 1], [2, 2]])
    m2 = Matrix([[1, 2], [3, 4]])
    print(m1 + m2)
    print(m2 - m1)
    print(m1 * 2)
    print(m1.t)
    print(m1.multiple(m2))
