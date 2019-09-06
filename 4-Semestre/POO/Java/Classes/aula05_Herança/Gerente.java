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
public class Gerente extends Funcionário {
    private int funcionarios;
    
    Gerente(String nm, String cpf, double sal, int fun) {
        super(nm, cpf, sal);
        funcionarios = fun;
    }
    
    boolean verSenha(int senha) {
        return this.senha == senha;
    }
    
    @Override
    void calcularBonus() {
        this.sal *= 1.35;
    }
}
