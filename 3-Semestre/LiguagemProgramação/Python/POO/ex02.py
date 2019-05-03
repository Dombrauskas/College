class Dispositivo:
    IP = str
    lig = True
    app = int
    con = 0
    NF = 0
    CC = 1
    YT = 2

    def __init__(self, ip, lig, app):
        self.IP = ip
        self.lig = lig
        self.app = app

class Smartphone(Dispositivo):

    def getConsumo(self, a, b, c):
        super().__init__(a, b, c)
        if self.lig is True:
            if self.app == 0:
                return 300
            elif self.app == 1:
                return 1
            elif self.app == 2:
                return 180
            else:
                return "Aplicativo inválido"
        else:
            return


class Tablet(Dispositivo):

    def getConsumo(self, a, b, c):
        super().__init__(a, b, c)
        if self.lig is True:
            if self.app == 0:
                return 400
            elif self.app == 1:
                return 10
            elif self.app == 2:
                return 300
            else:
                return "Aplicativo inválido"
        else:
            return

class PC(Dispositivo):

    def getConsumo(self, a, b, c):
        super().__init__(a, b, c)
        if self.lig is True:
            if self.app == 0:
                return 400
            elif self.app == 1:
                return 10
            elif self.app == 2:
                return 350
            else:
                return "Aplicativo inválido"
        else:
            return


lt = []

B = Smartphone("AAA", True, 1)
x = B.getConsumo(B.IP, B.lig, B.app)


while len(lt) < 3:
    x = input("IP: ")
    y = bool(input("Está ligada [1] ou desligado [0]: "))
    z = int(input("0 - Netflix, 1 - Candy Crush, 2 - Youtube: "))

    if len(lt) == 0:
        A = Smartphone(x, y, z)
        A.getConsumo(A.IP, A.lig, A.app)
    elif len(lt) == 1:
        A = Tablet(x, y, z)
        A.getConsumo(A.IP, A.lig, A.app)
    else:
        A.getConsumo(A.IP, A.lig, A.app)

    lt.append(A)

for i in lt:
    print("IP: {}\tIs on: {}\tAplicativo: {}".format(i.IP, i.lig, i.app))

