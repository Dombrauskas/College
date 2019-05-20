while (True):
    n = int(input())
    if n >=1 and n <= 1000:
        break

lista1 = []
lista2 = []
resultado = 0

for i in range(n):

    while True:
        lista = list(map(int, input().split()))
        if lista[0] >= 0 and lista[0] <= 3 and lista[1] >= 0 and lista[1] <= 3:
            break
    lista1.append(lista[0])
    lista2.append(lista[1])

k = 0
for i in range(0,len(lista1)):
    if lista1[i] == 3 and lista2[i] <= 1:
        k += 3;
    if lista1[i] == 3 and lista2[i] == 2:
        k += 2;
    if lista1[i] == 2 and lista2[i] == 3:
        k += 1;
print(k)
