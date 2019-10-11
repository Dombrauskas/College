/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula_09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.Scanner;
/**
 *
 * @author Maurício
*/
public class Aula_09 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner ler = new Scanner(System.in);
        char op = '/', lx;
        int x = 0, y = 0;
        boolean c = true;
        
        operacao ob = new operacao();
        
        System.out.print("Digite dois números: ");
       
        while (c)
            try {
                c = false;
                x = ler.nextInt();
                ob.setResultado(x);
                y = ler.nextInt();
                System.out.print("\nQual operação Divisão (/) ou Módulo (%)? ");
            }
            catch(InputMismatchException e) {
                System.out.println("Digite apenas números.");
                c = true;
            }
        
        do {
            do {
                lx = (char) br.read();
            } while (op != '\n');
            op = (char) br.read();
            if (op != '%' || op != '/')
                System.out.println("Apenas os símbolos acima!");
        } while (op != '%' || op != '/');
        
        try {
            if (op == '/') 
                System.out.println(x + " / " + y + " = " + ob.dividir(y));
            else
                System.out.println(x + " % " + y + " = " + ob.modulo(y));
        }
        catch(ArithmeticException e) {
            System.out.println("Houve um erro no cálculo.");
        }
    }
}
