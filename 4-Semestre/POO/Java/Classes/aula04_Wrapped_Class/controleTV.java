/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula04;

import java.util.Scanner;
/**
 *
 * @author CEITELABINFO
 */
public class controleTV {
    public static void main(String args[]) {
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner ler = new Scanner(System.in);
        
        aparelhoTV at = new aparelhoTV();
        
        byte op;
        
        do {
            System.out.println("+ aumentar o volume.");
            System.out.println("- abaixar o volume.");
            System.out.println("> mudar canal.");
            System.out.println("< mudar canal.");
            System.out.println("P liga TV.");
            System.out.println("D desliga TV.");

            op = ler.nextByte();
            
            aparelhoTV.enviar(op);
            
            //System.out.println(aparelhoTV.enviar(op));
        } while (op != 6);
    }
}
