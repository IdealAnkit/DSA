import turtle
import time
from datetime import datetime

# Set up the screen
screen = turtle.Screen()
screen.title("Clock Animation")
screen.bgcolor("white")
screen.setup(width=600, height=600)
screen.tracer(0)  # Turn off auto screen updates

# Create drawing pen

pen = turtle.Turtle()
pen.hideturtle()
pen.pensize(3)

def draw_clock(hr, min, sec, pen):
    pen.clear()
    
    # Draw clock face
    pen.up()
    pen.goto(0, 210)
    pen.setheading(180)
    pen.color("black")
    pen.pendown()
    pen.circle(210)

    # Draw hour marks
    pen.up()
    pen.goto(0, 0)
    pen.setheading(90)
    for _ in range(12):
        pen.forward(190)
        pen.pendown()
        pen.forward(20)
        pen.penup()
        pen.goto(0, 0)
        pen.right(30)

    # Draw hour hand
    pen.goto(0, 0)
    pen.color("black")
    pen.setheading(90)
    angle = (hr % 12) * 30 + min * 0.5
    pen.right(angle)
    pen.pendown()
    pen.forward(100)
    pen.penup()

    # Draw minute hand
    pen.goto(0, 0)
    pen.color("blue")
    pen.setheading(90)
    angle = min * 6 + sec * 0.1
    pen.right(angle)
    pen.pendown()
    pen.forward(150)
    pen.penup()

    # Draw second hand
    pen.goto(0, 0)
    pen.color("red")
    pen.setheading(90)
    pen.right(sec * 6)
    pen.pendown()
    pen.forward(180)
    pen.penup()

    # Draw center
    pen.goto(0, 0)
    pen.dot(12, "black")

# Update clock every second
while True:
    now = datetime.now()
    hr = now.hour
    min = now.minute
    sec = now.second

    draw_clock(hr, min, sec, pen)
    screen.update()
    time.sleep(1)
