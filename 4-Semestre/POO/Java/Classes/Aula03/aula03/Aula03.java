/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula03;

/**
 *
 * @author CEITELABINFO
 */
import java.util.Scanner;

public class Aula03 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        float mx, mn, lt;
        int s, op;
        
        Tanque ob = new Tanque();
        
        Scanner ler = new Scanner(System.in);
        
        System.out.print("Volume máximo do tanque: ");
        mx = ler.nextFloat();
        System.out.print("Volume mínino do tanque: ");
        mn = ler.nextFloat();
        
        ob.setVolumeMax(mx);
        ob.setVolumeMin(mn);
        
        for (;;) {
            System.out.print("Litros: ");
            lt = ler.nextFloat();
            
            System.out.println("1 - Encher ou 2 - esvaziar?");
            op = ler.nextInt();
            if (op == 1) ob.encher(lt);
            else if (op == 2) ob.esvaziar(lt);

            //System.out.println(ob.getVolumeMax());
            System.out.println(ob.exibirInfos());
            
            System.out.println("0 - Sair");
            s = ler.nextInt();
            if (s == 0) break;
        }
    }
    
}
