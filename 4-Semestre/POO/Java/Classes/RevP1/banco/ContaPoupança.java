/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package banco;

/**
 *
 * @author Maurício
*/
public class ContaPoupança extends ContaBancaria {
    double bonus = 6.35;

    public ContaPoupança(int i, double d) {
        super(i, d);
    }
    
    @Override
    void sacar(int sac) {
        if ((saldo - sac) >= (-bonus)) saldo -= sac;
        else System.out.println("Saldo insuficiente!");
    }
    
    @Override
    void depositar(double dep) {
        saldo += dep;
    }
}
