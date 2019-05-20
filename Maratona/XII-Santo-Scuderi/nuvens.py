n = int(input(''))

cam = list(map(int, input().split()))
total = 0
aux = list()

for i in range(0,len(cam)):
    if cam[i] == 1:
        total +=1
        aux = list()
    else:
        aux.append(0)
        if i != len(cam)-1: # se é a ultima iteracao
            if cam[i+1] == 1: # se a proxima iteracao nao é 1
                if len(aux) % 2 != 0:
                    total += int(len(aux) / 2)
                elif len(aux) == 1:
                    continue
                elif len(aux) % 2 == 0:
                    total += len(aux) / 2
                aux = list()
        elif i == len(cam)-1:

            if cam[i-1] == 1:
                break
            elif len(aux) % 2 != 0:
                total += int(len(aux) / 2)
            elif len(aux) % 2 == 0:
                total += len(aux) / 2
            aux = list()
print(int(total))