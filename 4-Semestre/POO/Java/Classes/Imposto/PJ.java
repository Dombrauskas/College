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
public class PJ extends Pessoa {
    String CNPJ;
    
    PJ(String nm, String end, double r, String CNPJ) {
        super(nm, end, r);
        this.CNPJ = CNPJ;
    }
    
    double calcularImposto() {
        return this.rend * 1.18;
    }
}
