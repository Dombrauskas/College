"""
 " 
 " autor Maurício Freire
 " Declaração das classes de diferentes dispositivos
 " Declaration of the classes of different devices.
"""

class Dispositivo:
    ip = str()
    lig = bool()
    app = int()

    def __init__(self, ip, lig, app):
        self.ip = ip
        self.lig = lig
        self.app = app

    def getConsumo(self):
        pass


class Smartphone(Dispositivo):
    ip = str()
    lig = bool()
    app = int()

    def __init__(self, ip, lig, app):
        super().__init__(ip, lig, app)
        self.ip = ip
        self.lig = lig
        self.app = app

    def getConsumo(self):
        if self.lig is True:
            if self.app == 0:
                return 300
            elif self.app == 1:
                return 1
            elif self.app == 2:
                return 180


class Tablet(Dispositivo):
    ip = str()
    lig = bool()
    app = int()

    def __init__(self, ip, lig, app):
        super().__init__(ip, lig, app)
        self.ip = ip
        self.lig = lig
        self.app = app

    def getConsumo(self):
        if self.lig is True:
            if self.app == 0:
                return 400
            elif self.app == 1:
                return 10
            elif self.app == 2:
                return 300


class PC(Dispositivo):
    ip = str()
    lig = bool()
    app = int()

    def __init__(self, ip, lig, app):
        super().__init__(ip, lig, app)
        self.ip = ip
        self.lig = lig
        self.app = app

    def getConsumo(self):
        if self.lig is True:
            if self.app == 0:
                return 400
            elif self.app == 1:
                return 10
            elif self.app == 2:
                return 350
