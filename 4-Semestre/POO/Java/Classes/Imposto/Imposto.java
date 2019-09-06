/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Imposto;

/**
 *
 * @author CEITELABINFO
*/
import java.util.Scanner;
import java.io.*;

public class Imposto {
    public static void main(String[] args) throws IOException {
        Scanner ler = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String nome, endereço, cnpj;
        double dinheiro;
        byte i = 0;
        
        while (i < 3) {
            System.out.println("CAD");
            String cad = br.readLine();
            ++i;
            
            Integer op = new Integer(cad);
            System.out.println(op);
            switch(op) {
                case 1:
                    System.out.print("Nome: ");
                    nome = ler.nextLine();
                    System.out.print("Endereço: ");
                    endereço = ler.nextLine();
                    System.out.print("Rendimento: ");
                    dinheiro = ler.nextDouble();
                    
                    Pessoa pp = new Pessoa(nome, endereço, dinheiro);
                    break;
                case 2:
                    System.out.print("Nome: ");
                    nome = ler.nextLine();
                    System.out.print("Endereço: ");
                    endereço = ler.nextLine();
                    System.out.print("Rendimento: ");
                    dinheiro = ler.nextDouble();
                    System.out.print("CNPJ: ");
                    cnpj = ler.nextLine();
                    
                    PJ pj = new PJ(nome, endereço, dinheiro, cnpj);
                    break;
                default:
                    System.out.println("Opção Inválida!");
            }
            
        }
    }
}
