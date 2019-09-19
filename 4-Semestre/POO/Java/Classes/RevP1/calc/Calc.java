/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc;

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/**
 *
 * @author Maurício
*/
class Operar {
    
    public static int somar(int x, int y) {
        return x + y;
    }
    
    public static double somar(double x, double y) {
        return x + y;
    }
    
    public static String somar(String x, String y) {
        int soma;
        soma = Integer.parseInt(x) + Integer.parseInt(y);
        return String.valueOf(soma);
    }
}

public class Calc {
    public static void main(String[] args) throws IOException {        
        Scanner ler = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer i, h;
        Double d, e;
        String r, s;
        int op;
        
        System.out.print("Operação: ");
        op = ler.nextInt();
        switch(op) {
            case 1:
                i = ler.nextInt();
                h = ler.nextInt();
                System.out.println("Somatório de " + i + " + " + h + " = " + Operar.somar(i, h));
                break;
            case 2:
                d = ler.nextDouble();
                e = ler.nextDouble();
                System.out.println("Somatório de " + d + " + " + e + " = " + Operar.somar(d, e));
                break;
            case 3:
                r = br.readLine();
                s = br.readLine();
                System.out.println("Somatório de " + r + " + " + s + " = " + Operar.somar(r, s));
                break;
            default:
                System.out.println("Opção Inválida!");
        }
    }   
}
