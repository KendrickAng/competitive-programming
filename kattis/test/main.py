m = 1e7+9
# print(pow(94906267,2) % m)
# print(((94906267%m)*(94906267))%m)
# print(((94906267%m)*(94906267%m))%m)
for i in range(94906267, int(1e9)):
    a = pow(i,2)%m
    b = ((i%m)*(i))%m
    c = ((i%m)*(i%m))%m
    if a != b and a == c:
        print(a, b, c)
