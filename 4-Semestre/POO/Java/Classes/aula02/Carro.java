/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula02;

/**
 *
 * @author CEITELABINFO
 */
public class Carro {
    private float consMedio;
    float tanque, odometro, kmr = 0;
    boolean troca = false;
    
    Carro(float cm, float tq, float od) {
        consMedio = cm;
        tanque = tq;
        odometro = od;
    }

    Carro() {}
    
    void setarVelocidade(float vm, float tempo) {
        float distancia  = vm * tempo;
        float litros = distancia / consMedio;
        odometro += distancia;
        tanque -= litros;
        kmr += distancia;
        
        if (kmr >= 30000)
            troca = true;
    }
    
    boolean trocarPneu(float dist) {
        return troca;
    }
    
    float getConsumoMedio() { return consMedio; }
    
}
