import turtle

def draw_tree(branch_length, t):
    if branch_length > 5:
        # Draw the main branch
        t.forward(branch_length)
        
        # Draw right branch
        t.right(20)
        draw_tree(branch_length - 15, t)
        
        # Return to main branch
        t.left(40)
        draw_tree(branch_length - 15, t)
        
        # Reset angle
        t.right(20)
        t.backward(branch_length)

# Setup screen
screen = turtle.Screen()
screen.bgcolor("black")

# Create turtle
tree_turtle = turtle.Turtle()
tree_turtle.color("lime")
tree_turtle.speed(0)
tree_turtle.left(90)
tree_turtle.penup()
tree_turtle.backward(100)
tree_turtle.pendown()

# Draw the tree
draw_tree(100, tree_turtle)

# Exit on click
screen.exitonclick()
