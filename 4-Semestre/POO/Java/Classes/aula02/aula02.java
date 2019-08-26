/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
*/
package aula02;

import java.util.Scanner;
/**
 *
 * @author Maurício
*/
public class Aula02 {

    /**
     * @param args the command line arguments
    */
    public static void main(String[] args) {
        float cm, lt, vel, temp, od;
        int s;
        
        Scanner ler = new Scanner(System.in);
        
        for (;;) {
            System.out.print("Tempo: ");
            temp = ler.nextFloat();
            System.out.print("Consumo: ");
            cm = ler.nextFloat();
            System.out.print("Litros: ");
            lt = ler.nextFloat();
            System.out.print("Velocidade: ");
            vel = ler.nextFloat();
            System.out.print("Odometro: ");
            od = ler.nextFloat();
            
            Carro c1 = new Carro(cm, lt, od);
            
            c1.setarVelocidade(vel, temp);
            
            if (c1.tanque <= 0) break;
            System.out.println("Carro 1 odometro: " + c1.odometro + "KM");
            System.out.println("Carro 1 tanque: " + c1.tanque + "L\n");
            
            System.out.println("0 - Sair");
            s = ler.nextInt();
            if (s == 0) break;
        }       
    }
}
