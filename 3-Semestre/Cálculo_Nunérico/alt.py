def ss(x, y):
    z = -1
    it = -1
    a = -1
    aux = []
    while z < y - 1:
        for i in x:
            p = x[z+1][z+1]
            z += 1
            it += 1
            a += 1
            b = 0
            for j in x[z]:
                if z == it:
                    e = x[a][b] / p
                    aux.append(e)
                    b += 1
                else:
                    x[a][b] = j - (j / p) * x[0][b]
                    b += 1
        print("Aqui",z,"aux",aux)
        print("\n",pp(x))


def pp(x):
    for i in x:
        print(i)


mat = [[1,2,3],[4,5,6],[7,8,9]]
ss(mat, len(mat))
pp(mat)

