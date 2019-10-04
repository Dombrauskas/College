/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula08_comparable;

import java.util.Arrays;
/**
 *
 * @author Maurício
 */
public class Aula08_Comparable {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Alguém da Silva", 25);
        Pessoa p2 = new Pessoa("João José", 44);
        Pessoa p3 = new Pessoa("Astorgildo Menildo", 88);
        
        int c = p1.compareTo(p1);
        System.out.println(p1.getNome().compareTo(p2.getNome()));
        
        Pessoa[] ps = new Pessoa[3];
        ps[0] = p1;
        ps[1] = p2;
        ps[2] = p3;
        
        Arrays.sort(ps);
        
        for (Pessoa x: ps)
            System.out.println(x.getNome() + " " + x.getIdade());
        
        Arrays.sort(ps);
        
        for (Pessoa x: ps)
            System.out.println(x.getNome() + " " + x.getIdade());
    }
}
