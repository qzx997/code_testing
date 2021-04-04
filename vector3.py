class Vector3:
    def __init__(self, x, y, z):
        self.__x = x
        self.__y = y
        self.__z = z

    def __add__(self, other):
        x = self.__x + other.__x
        y = self.__y + other.__y
        z = self.__z + other.__z
        return Vector3(x, y, z)

    def __str__(self):
        return '{} {} {}'.format(self.__x, self.__y, self.__z)


v = [1, 2, 3]
v1 = Vector3(v[0], v[1], v[2])
v2 = Vector3(4, 5, 6)
print(v1 + v2)
print(v)
