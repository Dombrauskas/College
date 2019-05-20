def conta(x, y, z, buracos):
    while y < len(x):
        x[y][z] = 'C'
        y += 1
        if y >= len(x) or x[y][z] != 'P':
            while z < len(x):
                x[y][z] = 'C'
                z += 1
    buracos += 1
    return buracos


a, c = input().split(" ")
a = int(a)
c = int(c)
aux_i = aux_j = int
buracos = 0
foto = []


for i in range(a):
    photo = []
    for j in range(c):
        t = input()
        photo.append(t)
    foto.append(photo)

for i in range(len(foto)):
    for j in foto[i]:
        print(j, end=" ")
    print()

for i in range(len(foto)):
    for j in range(len(foto[i])):
        if foto[i][j] == 'P':
            buracos = conta(foto, i, j, buracos)

print(buracos)


