import random

# Escalona a matriz
# Está função pode executar infinitamente, pois ainda não foi feito o laço while
# com efeciência (em testes ainda)!.
def escalonar(x, y):
    # Repete o processo do pivotamento até mat[fim - 1][fim - 2] ser 0
    # Ainda não concluído. Estrutura do while não foi verificada para este caso!!
    while True:
        s = 0
        e = mat[s + 1][s]
        a = mat[s][s]
        t = (-e/a)
        print("{} = -{} / {}".format(t, e, a))
        t += e
        mat[s+1][s] = t
        print_mat(mat)
        # Quando der True a matriz foi escalonada com sucesso.
        if mat[y - 1][y - 2] == 0:
            return True
        else:
            s += 1

# Meramente imprime a matriz.
def print_mat(w):
    print()
    for j in w:
        print(j)


i = int(input("Incógnitas: "))
mat = []

# Cria uma matriz com valores aleatórios.
while len(mat) < i:
    vet = []
    for c in range(i):
        vet.append(random.randint(1,9))
    mat.append(vet)

print_mat(mat)

# Enquanto a matriz não for escalonada não cessa a chamada a função escalonar.
# PODE causar erros de execução infinita ou Runtime Error.
flag = False
while not flag:
    flag = escalonar(mat, i)

print_mat(mat)
