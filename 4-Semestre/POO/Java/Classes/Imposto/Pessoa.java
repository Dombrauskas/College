/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Imposto;

/**
 *
 * @author Maurício
 */
public class Pessoa {
        String nome, endereço;
        double rend;
        
        Pessoa(String nm, String end, double din) {
            nome = nm;
            endereço = end;
            rend = din;
        }
    
        double calcularImposto() {
            return this.rend <= 3000 ? this.rend * 1.11 : this.rend * 1.275;
        }
}
