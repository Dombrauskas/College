/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package banco;

import java.util.Scanner;
/**
 *
 * @author Maurício
*/
public class Banco {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        ContaBancaria[] cb = new ContaBancaria[5];
                
        ContaCorrente cc;
        ContaPoupança cp = null;
        
        for (byte i = 0; i < cb.length; i++) {
            byte e = ler.nextByte();
            if (e == 1) cb[i] = cc = new ContaCorrente(2432, 400.9);
            if (e == 2) cb[i] = cp = new ContaPoupança(2234, 504.39);
            if (e > 2 || e < 1) {
                System.out.println("Operação Inválida");
                --i;
            }
        }
        
        cp.depositar(150);
        
        System.out.println("Saldo Poupança depois de depositar R$ 150: " + 
                cp.saldo);
    }  
}
