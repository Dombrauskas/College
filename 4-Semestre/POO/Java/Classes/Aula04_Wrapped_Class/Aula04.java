/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula04;

/**
 *
 * @author CEITELABINFO
 */
import java.io.*;


class showPI {
    
    static int Ipi() {
        Double d = Math.PI;
        return d.intValue();
    }
       
    static byte Bpi() {
        Double d = Math.PI;
        return d.byteValue();
    }
    
    static short Spi() {
        Double d = Math.PI;
        return d.byteValue();
    }
    
    static float Fpi() {
        Double d = Math.PI;
        return d.floatValue();
    }
}

public class Aula04 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        showPI sp = new showPI();
        int op;
        
        System.out.print("Opção: ");
        String str = br.readLine();
        
        try {
            op = Integer.parseInt(str);
        }
        catch (NumberFormatException e) {
            System.out.println("Converção inválida.");
            op = 0;
        }
        
        switch(op) {
            case 1:
                System.out.println("PI int: " + sp.Ipi());
                break;
            case 2:
                System.out.println("PI byte: " + sp.Bpi());
                break;
            case 3:
                System.out.println("PI short: " + sp.Spi());
                break;
            case 4:
                System.out.println("PI float: " + showPI.Fpi());
                break;
            default:
                System.out.println("Opção inválida.");
        }
    }   
}
