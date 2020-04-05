package Parte_II;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

/**
 * @author Maurício Freire
 * Date 02/04/2020 at 16:48
 * Created on IntelliJ IDEA
 */

public class Ex2b {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String size;
        int tamanho, comb;
        tamanho = comb = 0;

        while (tamanho <= 0 || tamanho > 1000) {
            System.out.print("Tamanho do vetor: ");
            size = br.readLine();
            tamanho = Integer.parseInt(size);
        }
        int[] arr = new int[tamanho];

        Random rd = new Random();
        for (int i = 0; i < tamanho; i++)
            arr[i] = rd.nextInt();

        while (comb >= (tamanho / 2) || comb <= 0) {
            System.out.print("Número de combinações: ");
            size = br.readLine();
            comb = Integer.parseInt(size);
        }
//        Combinação[] cb = new Combinação[comb];
        Combinação cb1 = new Combinação("Thread-1", tamanho);
        Combinação cb2 = new Combinação("Thread-2", comb);
        Combinação cb3 = new Combinação("Thread-3", tamanho - comb);

        //for (int k = 0; k < comb; k++)

        try {
            cb1.td.join();
            cb2.td.join();
            cb3.td.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Fatorial: " + cb1.getRes());
        System.out.println("Fatorial: " + cb2.getRes());
        System.out.println("Fatorial: " + cb3.getRes());

        int tc = cb1.getRes() / (cb2.getRes() * cb3.getRes());
        System.out.println("Combinações possíveis: " + tc);
    }
}

