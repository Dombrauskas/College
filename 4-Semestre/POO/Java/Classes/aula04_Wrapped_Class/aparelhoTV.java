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
public class aparelhoTV {
    int canal, volume;
    String bateria;
    
    public static final byte a = '+';
    public static final char b = '-';
    public static final char c = '>';
    public static final char d = '<';
    public static final char e = 'P';
    public static final char f = 'D';
    
    public static void ligaControle() {
        
    }
    
    public static void enviar(byte cd) {
        switch (cd) {
            case 1:
                System.out.println(a + " aumentar volume.");
                break;
            case 2:
                System.out.println(b + " diminuir volume.");
                break;
            case 3:
                System.out.println(c + " mudar canal.");
                break;
            case 4:
                System.out.println(d + " mudar canal.");
                break;
            case 5:
                System.out.println(e + " ligar TV.");
                break;
            case 6:
                System.out.println(f + " desligar TV.");
                break;
            default:
                break;
        }
    }
}
