from math import sqrt

def findRoot(a, b, c):
    D = b*b-4*a*c; 
    x1 = (-b + sqrt(D)) / (2*a);
    x2 = (-b + sqrt(D) * -1) / (2*a);
    return (x1, x2);

result = findRoot(2, -7, -4)
print(result[0], result[1])
