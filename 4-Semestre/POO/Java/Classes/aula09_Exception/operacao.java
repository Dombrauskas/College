/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula_09;

/**
 *
 * @author ceitelabinfo
 */
public class operacao {
    private int result;
    
    public int dividir(int div) throws ArithmeticException {
        return this.result / div;
    }
    
    public int modulo(int m) throws ArithmeticException {
        return this.result % m;
    }
    
    public void setResultado(int res) { this.result = res; }
    public int getResultado() { return this.result; }
}
