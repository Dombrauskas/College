def conta(lin, col, foto, x, y):
    if x >= 0 and x < lin and y >= 0 and y < col and foto[x][y] == 'P':
        foto[x][y] = 'X';
        conta(lin, col, foto, x + 1, y)
        conta(lin, col, foto, x - 1, y)
        conta(lin, col, foto, x, y + 1)
        conta(lin, col, foto, x, y - 1)



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
            buracos += 1
            conta(a, c, foto, i, j)

print(buracos)

