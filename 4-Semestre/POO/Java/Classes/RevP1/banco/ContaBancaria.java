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
public abstract class ContaBancaria {
    int num_conta;
    double saldo;
    
    ContaBancaria(int i, double d) {
        num_conta = i;
        saldo = d;
    }
    
    abstract void sacar(int sac);
    abstract void depositar(double dep);
}
