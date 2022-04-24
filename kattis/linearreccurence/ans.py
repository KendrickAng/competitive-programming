n = int(input())

coefs = map(int, input().split())

xs = list(map(int, input().split()))

A = [[0]*(n+1) for _ in range(n+1)]

A[0][0] = 1
A[1][:] = coefs

for i in range(2,n+1):
	A[i][i-1] = 1

print(A)

# print A
xs.append(1)
xs.reverse()
print(xs)
# print xs


def vecmult(A,v,m):
	u =[]
	for row in A:
		u.append(sum([(i*j)%m for i,j in zip(row,v)])%m)
	return u

def matmult(A,B,m):
	B= list(zip(*B))
	C= [vecmult(A,v,m) for v in B]
	for i in range(len(C)):
		for j in range(i):
			C[i][j], C[j][i] = C[j][i],C[i][j]
	return C


def matexp(A, e, m):
	if e==0:
		return [[int(i==j)%m for j in range(len(A))] for i in range(len(A))]
	if e==1:
		return [[entry%m for entry in row] for row in A]
	B = matexp(A,e>>1,m)
	B = matmult(B,B,m)
	if e&1:
		B= matmult(B,A,m)
	return B




def query(t,m):
    if t<n: return xs[-(t+1)]%m
    print(f"T-N+1: {t-n+1}")
    print(f"A: {A}")
    M = matexp(A,t-n+1, m)
    v= vecmult(M, xs, m)
    # print M
    # print v
    print(f"M: {M}")
    print(f"vec: {xs}")
    print(f"v: {v}")

    return v[1]


# print matmult(A,A,23)

q = int(input())

for _ in range(q):
	print(query(*(map(int, input().split()))))