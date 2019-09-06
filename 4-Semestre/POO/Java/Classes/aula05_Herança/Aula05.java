/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
*/
package aula05_Herança;

/**
 *
 * @author Maurício
*/
public class Aula05 {
    public static void main(String[] args) {
        OpCaixa cx1 = new OpCaixa("Eu da Silva", "123.654.852-15", 1000);
        OpCaixa cx2 = new OpCaixa("Ele de Souza", "323.554.992-10", 1000);
        Gerente ger = new Gerente("Nós Pereira-eira", "623.007.392-99", 1000, 5);
        
        cx1.setSenha(124);
        cx2.setSenha(324);
        ger.setSenha(885);
        
        Funcionário[] fc = new Funcionário[3];
        
        for (Funcionário f : fc) 
            System.out.println("Salário do: " + f.getNome() + ": " + f.getsalario());
    }
}
