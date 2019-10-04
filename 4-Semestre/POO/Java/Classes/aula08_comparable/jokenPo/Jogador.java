/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jokenPo;

/**
 *
 * @author Maurício
*/
public class Jogador implements Comparable<Jogador> {
    private String nome;
    private int mão;
    
    
    public void setNome(String nm) { this.nome = nm; }
    public void setMao(int mao) { this.mão = mao; }
    public String getNome() { return this.nome; }
    public int getMao() { return this.mão; }
        
    @Override
    public int compareTo(Jogador jd) {
        // 0 - Pedra              
        // 1 - Papel
        // 2 - Tesoura
        switch(this.mão) {
            case 0:
                if (jd.mão == 1) return this.mão - jd.mão;
                else return -(this.mão - jd.mão);
            case 1:
                if (jd.mão == 2) return this.mão - jd.mão;
                else return -(this.mão - jd.mão);
            case 2:
                if (jd.mão == 0) return this.mão - jd.mão;
                else return -(this.mão - jd.mão);
            default:
                System.out.println("Jagada Inválida!");
        }
        return 8;
    }
}
