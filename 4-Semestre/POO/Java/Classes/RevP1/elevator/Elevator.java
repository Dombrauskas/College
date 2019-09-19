/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package elevator;

//import java.io.*;
import java.util.Scanner;
/**
 *
 * @author Maurício
 */
class Ascensor {
    private int storey;
    private int sto_flo;
    private int capac;
    private int pessoas;
    
    Ascensor(int sf, int fl) {
        capac = fl;
        storey = sf;
        pessoas = 0;
        sto_flo = 0;
    }
    
    void Receber() {
        if (pessoas < capac) pessoas++;
        else System.out.println("Elevador lotado!");
    }
    
    void Entregar() {
        if (pessoas >= 1) pessoas--;
        else System.out.println("Elevador vazio!");
    }
    
    void Subir() {
        if (sto_flo < storey) sto_flo++;
        else System.out.println("Último andar!");
    }
    
    void Descer() {
        if (sto_flo > 0) sto_flo--;
        else System.out.println("Térreo!");
    }
    
    int getStorey() { return sto_flo; }
    int getPessoas() { return pessoas; }
}

public class Elevator {
    public static void main(String[] args) {
        int andar, pes;
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner ler = new Scanner(System.in);
        Ascensor as;
        char[] x = new char[2];
        
        System.out.print("Quantas andares tem o prédio? ");
        andar = ler.nextInt();
        System.out.print("Quantas pessoas cabem no elevador? ");
        pes = ler.nextInt();
        
        
        as = new Ascensor(andar, pes);
        
        as.Receber();
        as.Subir();
        System.out.println("Andar atual: " + as.getStorey() + " pessoas: " + as.getPessoas());
        as.Receber();
        as.Subir();
        as.Entregar();
        as.Receber();
        as.Subir();
        as.Subir();
        System.out.println("Andar atual: " + as.getStorey() + " pessoas: " + as.getPessoas());
        as.Descer();
        as.Entregar();
        as.Entregar();
        System.out.println("Andar atual: " + as.getStorey() + " pessoas: " + as.getPessoas());
    }
}
