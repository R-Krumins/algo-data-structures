from random import randint

while True:
    a = randint(1, 10)
    b = randint(1, 10)
    answer = input(f"What is {a}x{b}? ")
    answer = int(answer)

    if(answer == a*b):
        print("Correct!")
    else:
        print("Wrong!")

