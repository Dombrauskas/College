/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula08_comparable;

/**
 *
 * @author Maurício
*/
public class Pessoa implements Comparable<Pessoa> {
    
    private String nome;
    private int idade;

    public Pessoa(String str, int i) {
        this.nome = str;
        this.idade = i;
    }
    
    public void setNome(String nome) { this.nome = nome; }
    public int getIdade() { return idade; }
    public void setIdade(int idade) { this.idade = idade; }
    public String getNome() { return nome; }
    
    @Override
    public int compareTo(Pessoa p) {
        return this.idade - p.getIdade();
    }
    
}
