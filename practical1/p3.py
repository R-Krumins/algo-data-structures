from random import randint

arrM = [randint(0, 100) for i in range(10)]

smallest = arrM[0]
largest = arrM[0]

for numb in arrM:
    if(numb > largest): largest = numb
    if(numb < smallest): smallest = numb

print(arrM)
print(smallest, largest)
