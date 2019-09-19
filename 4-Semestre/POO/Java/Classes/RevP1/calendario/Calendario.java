/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calendario;

import java.util.GregorianCalendar;
import java.util.Scanner;
import java.util.Calendar;
/**
 *
 * @author CEITELABINFO
 */
class Person {
    private int by;
    private double ht;
    private String nm;
    
    void setby(int i) { by = i; }
    void setht(double d) { ht = d; }
    void setnm(String s) { nm = s; }
    
    int getby() { return by; }
    double getht() { return ht; }
    String getnm() { return nm; }
}

public class Calendario {
    public static void main(String[] args) {
        int ano, id;
        double alt;
        String nome;
        
        Scanner ler = new Scanner(System.in);
        Person p = new Person();
        Calendar c = GregorianCalendar.getInstance();
        c.get(Calendar.YEAR);
        
        System.out.print("Ano: ");
        ano = ler.nextInt();
        System.out.print("Altura: ");
        alt = ler.nextDouble();
        System.out.print("Nome: ");
        nome = ler.nextLine();
        
        p.setby(ano);
        p.setht(alt);
        p.setnm(nome);
        
        System.out.println(p.getnm() + " tem " + p.getht() + " de altura e " + 
                p.getby() + " anos de idade.");
    }
}
