from random import uniform
B = [uniform(0, 10) for i in range(50)]

for i in range(len(B) - 1):
    if abs(B[i] - B[i+1]) >= 1:
        print(f"There are integers between {B[i]} and {B[i+1]}")

