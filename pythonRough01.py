import turtle
import colorsys

# Set up screen
screen = turtle.Screen()
screen.bgcolor("black")
t = turtle.Turtle()
t.speed(0)  # Fastest

# Color setup
h = 0
n = 36  # Number of colors
colors = [colorsys.hsv_to_rgb(h+i/n, 1.0, 1.0) for i in range(n)]

# Draw spiral
for i in range(360):
    t.color(colors[i % n])
    t.forward(i * 3 / n + i)
    t.left(59)
    t.pensize(i * 3 / n)

# Hide turtle and keep window open
t.hideturtle()
turtle.done()
