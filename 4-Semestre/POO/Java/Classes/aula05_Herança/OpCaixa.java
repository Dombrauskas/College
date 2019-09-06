/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula05_Herança;

/**
 *
 * @author CEITELABINFO
 */
public class OpCaixa extends Funcionário {
    OpCaixa(String nm, String cpf, double salario) {
        super(nm, cpf, salario);
    }
    
    @Override
    void calcularBonus() {
        this.sal *= 1.15;
    }
}
