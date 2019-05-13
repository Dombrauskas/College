import random

# Escalona a matriz
# Está função pode executar infinitamente, pois ainda não foi feito o laço while
# com efeciência (em testes ainda)!.
def escalonar(x, y):
    z = y-1 #Seleciona a linha a ser dividida pelo pivot. | Ainda não 100%.
    a = -1
    pivot = mat[y][y]
    aux = []
    for r in mat:
        z += 1
        a += 1
        b = 0
        for s in mat[z]:
            # Divide e salva a nova linha do pivot em uma lista auxiliar.
            if z == y:
                e = mat[a][b] / pivot
                aux.append(e)
                b += 1
            # O escalonamento em si.
            else:
                mat[a][b] = s - (s / pivot) * mat[0][b]
                print("s: {}\tmat[0][b]: {}".format(s,mat[0][b]))
                b += 1
    # Insere a nova linha do pivot na matriz
    mat[y] = aux
    

# Meramente imprime a matriz.
def print_mat(w):
    print()
    for j in w:
        print(j)


i = int(input("Incógnitas: "))
mat = []

# Cria uma matriz com valores aleatórios. | Falta incluir a coluna do resultado.
while len(mat) < i: # + 1:
    vet = []
    for c in range(i):
        vet.append(random.randint(-9,9))
    mat.append(vet)

print_mat(mat)

# Chama a função de escalonar repetidas vezes.
it = -1
while it < i - 1:
    escalonar(mat, it + 1)
    it += 1

print_mat(mat)

