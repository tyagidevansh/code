from matplotlib import pyplot as plt

a, b, c = [], [], []

def f(x, y):
    return x + y

def euler(h, x, y, target):
    while x < target:
        y = y + h * f(x, y)
        x += h
    return y

def euler_modified(h, x, y, target, y0):
    while x < target:
        y1 = f(x, y)
        y = y + h/2 * (y1 + y0)
        y0 = y1  # Update y0 here
        x += h
    return y

h = 0.2
target = 0.4
x, y, y0 = 0, 0, 0
print("h =", h)

while h > 0.000021:
    print("Euler's method:")
    a.append(h)
    b.append(euler(h, x, y, target))

    print("Approximate solution at 0.4:", euler(h, x, y, target))

    print("Modified Euler's method: ")
    c.append(euler_modified(h, x, y, target, y0))
    print("Approximate solution at 0.4:", c[-1]) 

    h /= 2

a.reverse()
b.reverse()
c.reverse()

plt.plot(a, b, label="Euler's method")
plt.plot(a, c, label="Modified Euler's method")
plt.xlabel("h")
plt.ylabel("y")
plt.legend()
plt.show()
