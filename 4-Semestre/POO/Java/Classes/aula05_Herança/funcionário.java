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
public class Funcionário {
    private String nome;
    private String CPF;
    protected double sal;
    protected int senha;
    
    Funcionário(String nm, String doc, double sal) {
        nome = nm;
        CPF = doc;
        this.sal = sal;
    }
    
    void setNome(String nm) {
        nome = nm;
    }
    
    void setCPF(String cpf) {
        CPF = cpf;
    }
    
    void setSalario(double d) {
        sal = d;
    }
    
    void setSenha(int s) {
        senha = s;
    }
    
    String getNome() { return nome; }
    String getCPF() { return CPF; }
    double getsalario() { return sal; }
    
    void calcularBonus() {
        
    }
}
    