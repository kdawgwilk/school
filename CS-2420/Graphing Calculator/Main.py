
from Stack import Stack
from graphics import *

# 2*(3+4/5*6)/(9-4+3/2)*8   // Convert infix to postfix
# 2345/6*+*94-32/+/8*

# 123*+4-6*82-/             // Evaluate postfix expression
# 3

# 1-(2+3*4/(5/6*7)-8*9)*2   // Convert infix to postfix
# 1234*56/7*/+89*-2*-

# infix:    '3 * 4 + 5'
# postfix:  '3 4 * 5 +'

ops_priority = {
    '(': 1,
    '+': 2,
    '-': 2,
    '/': 3,
    '*': 3,
    '^': 4
}
ops_list = ['^', '/', '*', '+', '-']


def infix_to_postfix(infix):
    chars = infix.split()
    postfix_array = []
    postfix = ""
    s = Stack()
    for char in chars:
        if char.isdigit() or char in 'xX':
            postfix_array.append(char)
        elif char == "(":
            s.push(char)
        elif char == ")":
            top_char = s.pop()
            while top_char != '(':
                postfix_array.append(top_char)
                top_char = s.pop()
        else:
            while (not s.empty()) and (ops_priority[s.top()] >= ops_priority[char]):
                postfix_array.append(s.pop())
            s.push(char)
    while not s.empty():
        postfix_array.append(s.pop())
    postfix = " ".join(postfix_array)
    return postfix


def evaluate_postfix(postfix, x):
    chars = postfix.split()
    s = Stack()
    for char in chars:
        if char.isdigit():
            s.push(char)
        elif char in 'xX':
            s.push(x)
        elif char in '+-*/^':
            value = None
            rhs = float(s.pop())
            lhs = float(s.pop())
            if char == '+':
                value = lhs + rhs
            elif char in '-':
                value = lhs - rhs
            elif char in '*':
                value = lhs * rhs
            elif char in '/':
                value = lhs / rhs
            elif char in '^':
                value = lhs ** rhs
            if value:
                s.push(value)
    return s.pop()


def draw(points, win):
    print("Drawing!")
    last_point = None
    for point in points:
        p = Point(point[0], point[1])
        # p.draw(win)
        if last_point:
            l = Line(last_point, p)
            l.draw(win)
        last_point = p
    return


def main():
    # infix = input('Enter an Expression to graph: ')
    infix = "2 * x ^ 2 - 2"
    # infix = "1 - ( 2 + 3 * 4 / ( 5 / 6 * 7 ) - 8 * 9 ) * 2"
    # infix = "2 * ( 3 + 4 / 5 * 6 ) / ( 9 - 4 + 3 / 2 ) * 8"
    postfix = infix_to_postfix(infix)
    print postfix
    low_x = -10
    high_x = 10
    x = low_x
    inc = .1
    points = []
    while x < high_x:
        y = evaluate_postfix(postfix, x)
        print y
        points.append((x, y))
        x += inc
    win = GraphWin("My Graph", 500, 500)
    win.setCoords(low_x, low_x, high_x, high_x)
    x_axis = Line(Point(low_x, 0), Point(high_x, 0))
    x_axis.draw(win)
    y_axis = Line(Point(0, low_x), Point(0, high_x))
    y_axis.draw(win)
    draw(points, win)
    win.getMouse()  # Pause to view result
    win.close()     # Close window when done
    return

main()
