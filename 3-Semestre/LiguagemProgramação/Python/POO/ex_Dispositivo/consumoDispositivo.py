"""
 " 
 " autor Maurício Freire
 " Programa que calcula o consumo de dados de diferentes dispositivos ao
 " executar algumas aplicações.
 " Program that calculates the consumption of data of different devices
 " while running some applications.
"""

from dispositivo import *

n = int(input("Informe a quantidade de dispositivos: "))

tt = 0
lt = []

for i in range(n):
    ip = input("IP: ")
    li = int(input("Ligado (1) / Desligado (0): "))
    app = int(input("Netflix 0; Candy Crush 1; Youtube 2")
    dis = int(input("Smartphone 0; Tablet 1; PC 2"))

    if (dis == 0):
        x = SmartPhone(ip, ligado, dispositivo)
        lt.append(x)
    elif (dis == 1):
        x = Tablet(ip, ligado, dispositivo)
        lt.append(x)
    elif (dis == 2):
        x = PC(ip, ligado, dispositivo)
        lt.append(x)

for i in lista:
    tt += i.getConsumo()
