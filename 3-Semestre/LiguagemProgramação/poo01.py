class Imovel:
    inscricao = 0
    area = 0.0
    valor_m2 = 0.0

    def __init__(self, i, a, m):
        self.inscricao = i
        self.area = a
        self.valor_m2 = m

    def calcularIPTU(self, a, m):
        self.area = a
        self.valor_m2 = m
        return self.area * self.valor_m2


class Casa(Imovel):
    area_constr = 0.0
    taxa_constr = 0.0

    def calcularIPTU(self, a, t):
        self.area_constr = a
        self.taxa_constr = t
        return Imovel.calcularIPTU(a, t) + self.area_constr * self.taxa_constr


A = Imovel(1, 45.8, 3000)
B = Imovel(2, 88.9, 5000)
C = Casa(0, 385, 3.7)
D = Casa(0, 223, 5)
E = Casa(0, 424, 1.44)

lt = [A, B, C, D, E]

for i in lt:
    print(i.calcularIPTU())
