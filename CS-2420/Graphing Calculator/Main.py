
from Stack import Stack

# infix:    '3 * 4 + 5'
# postfix:  '3 4 * 5 +'

ops_priority = {
    "^": 1,
    "*": 2,
    "/": 2,
    "+": 1,
    "-": 1
}


def infix_to_postfix(infix):
    chars = infix.split()
    postfix_array = []
    postfix = ""
    s = Stack()
    for char in chars:
        if char == "(":
            s.push(char)
        elif char.isdigit():
            postfix_array.append(char)
        if
    postfix = " ".join(postfix_array)
    return postfix

def evaluate_postfix(postfix, x):
    value = 0
    s = Stack()
    for char in postfix:
        if char.isdigit():
            s.push(char)
        elif char == x:
            s.push(x)
        elif char == "operator":
            rhs = s.pop()
            lhs = s.pop()
            val = eval(lhs + char + rhs)
            s.push(val)
    return value

def draw(points):

    return

def main():
    infix = "3 * 4 + 5"
    postfix = infix_to_postfix(infix)
    print postfix
    lowx = -10
    highx = 10
    inc = .1
    points = []
    for x in range(lowx, highx, inc):
        y = evaluate_postfix(postfix, i)
        print y
        points.append((x, y))
    draw(points)
    return

main()