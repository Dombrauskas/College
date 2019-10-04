/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jokenPo;

import java.util.Scanner;
/**
 *
 * @author CEITELABINFO
 */
public class JokenPo {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        
        Jogador j1 = new Jogador();
        Jogador j2 = new Jogador();
        
        int a = 0;
        while (a == 0) {
            j1.setNome("Maiquen Táisom");
            j1.setMao(ler.nextInt());
            j2.setNome("Morrâmedi Ali");
            j2.setMao(ler.nextInt());
        
            a = j1.compareTo(j2);
            
            if (a > 0)
                System.out.println("Vencedor: " + j1.getNome());
            else if (a < 0)
                System.out.println("Vencedor: " + j2.getNome());
            else
                System.out.println("Empate");
        }
    }
}
