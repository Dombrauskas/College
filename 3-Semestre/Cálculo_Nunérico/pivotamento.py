import random

# Escalona a matriz
# Está função pode executar infinitamente, pois ainda não foi feito o laço while
# com efeciência (em testes ainda)!.
def escalonar(x, y):
    # Repete o processo do pivotamento até mat[fim - 1][fim - 2] ser 0
    # Ainda não concluído. Estrutura do while não foi verificada para este caso!!
    #while True:
    lin = 0
    col = 0
    it = 0
    while it < y:
        p = mat[lin][col]
        while col < y:
            t = -mat[lin + 1][col] / p
            mat[lin + 1][col] += (t * mat[lin][col])
            print("t: {} | mat: {} | p: {}".format(t, mat[lin][col], p))
            col += 1
        it += 1
        col = 0
    

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
#flag = False
#while not flag:
escalonar(mat, i)

print_mat(mat)

