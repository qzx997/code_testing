import turtle


class DrawLine:
    def __init__(self, x1, y1, x2, y2):
        # turtle.reset()
        self.__x1 = x1
        self.__x2 = x2
        self.__y1 = y1
        self.__y2 = y2

    def draw(self):
        turtle.penup()
        turtle.goto(self.__x1, self.__y1)
        turtle.pendown()
        turtle.goto(self.__x2, self.__y2)
        turtle.penup()


class DrawCircle:
    def __init__(self, x, y, r):
        # turtle.reset()
        self.__x = x
        self.__y = y
        self.__r = r

    def draw(self):
        turtle.penup()
        turtle.goto(self.__x, self.__y - self.__r)
        turtle.pendown()
        turtle.circle(self.__r)


class DrawRect:
    def __init__(self, x, y, w, h):
        # turtle.reset()
        self.__x = x
        self.__y = y
        self.__w = w
        self.__h = h

    def draw(self):
        turtle.penup()
        turtle.goto(self.__x, self.__y)
        turtle.pendown()
        # turtle.forward(self.__w)
        # turtle.tilt(90)
        # turtle.forward(self.__h)
        # turtle.tilt(90)
        # turtle.forward(self.__w)
        # turtle.tilt(90)
        # turtle.forward(self.__h)
        turtle.goto(self.__x + self.__w, self.__y)
        turtle.goto(self.__x + self.__w, self.__y + self.__h)
        turtle.goto(self.__x, self.__y + self.__h)
        turtle.goto(self.__x, self.__y)


if __name__ == '__main__':
    turtle.reset()
    line = DrawLine(10, 10, 200, 300)
    line.draw()
    rect = DrawRect(10, 10, 50, 70)
    rect.draw()
    circ = DrawCircle(-100, -100, 100)
    circ.draw()
    turtle.done()
