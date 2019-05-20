l = list()
s = input("")

s = list(s)
sete = set(s)
total = list()
sete = list(sete)

for i in range(0, len(set(sete))):
    total.append(s.count(sete[i]))



maior = max(total)
menor = min(total)
kmaior = total.count(maior)

if maior > menor+1:
    print("NAO")
elif kmaior > 1 and maior != menor:
    print("NAO")
elif kmaior == 1:
    print("SIM")
else:
    print("SIM")

    # abcdefghhgfedecba