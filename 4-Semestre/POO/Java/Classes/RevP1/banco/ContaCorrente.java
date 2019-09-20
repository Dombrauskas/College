/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package banco;

/**
 *
 * @author CEITELABINFO
 */
public class ContaCorrente extends ContaBancaria {
    double taxaOperação = 3.5;

    public ContaCorrente(int i, double d) {
        super(i, d);
    }
    
    @Override
    void sacar(int sac) {
        if ((saldo - sac) <= 0) System.out.println("Saldo insuficiente!");
        else saldo -= sac + taxaOperação;
    }
    
    @Override
    void depositar(double dep) {
        saldo += dep - taxaOperação;
    }
}
