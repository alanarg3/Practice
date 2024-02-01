from turtle import Turtle, Screen
import random
for turtle_index in range(0, 6):
    tim = Turtle(shape="turtle")
colors = ["red", "orange", "yellow", "green", "blue", "purple"]
screen = Screen()
screen.setup(width=500, height=400)
user_bet = screen.textinput(title="Place your bets!", prompt="Which turtle will win the race?")
x_cor = -230
y_cor = -125
index = 0
value = 0
for turtle in screen.turtles():
    turtle.color(colors[index])
    index +=1
    turtle.penup()
    turtle.goto(x=x_cor, y=y_cor)
    y_cor += 50

if user_bet:
    is_race_on = True

while is_race_on:
    for turtle in screen.turtles():
        random_distance = random.randint(0,10)
        turtle.forward(random_distance)
        if turtle.xcor() >= 230:
            is_race_on = False

for tim in screen.turtles():
    if tim.xcor() > value:
        value = tim.xcor()
        winning_turtle = tim

if winning_turtle.fillcolor() == user_bet:
    screen.title(f"The {user_bet} turtle won the race! You win!!")
else:
    screen.title(f"The {winning_turtle.fillcolor()} turtle won the race. You lose.")

screen.exitonclick()
