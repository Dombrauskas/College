package Parte_II;

/**
 *
 * @author Maurício Freire
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Random;

public class Desafio {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long TI = System.currentTimeMillis();
        //double[][] mat1, mat2/*, matR*/;
        String size;

        while (Multipl.tamanho <= 0) {
            System.out.print("Informe o tamanho da matriz: ");
            size = br.readLine();
            Multipl.tamanho = Integer.parseInt(size);
        }

        Multipl.mat1 = new int[Multipl.tamanho][Multipl.tamanho];
        Multipl.mat2 = new int[Multipl.tamanho][Multipl.tamanho];
        //matR = new int[Multipl.tamanho][Multipl.tamanho];
        
        System.out.println("Duas matrizes de tamanho " + Multipl.tamanho + "x"
                + Multipl.tamanho + " foram criadas");

        Multipl mt = new Multipl("Paralelo");

        // Para a thread antes do run(). Evitar erros.
        mt.interromper();
        Random rd = new Random();

        // Gera duas matrizes com valores aleatórios.
        for (int i = 0; i < Multipl.tamanho; i++) {
            for (int j = 0; j < Multipl.tamanho; j++) {
                Multipl.mat1[i][j] = rd.nextInt(1001);
                Multipl.mat2[i][j] = rd.nextInt(1001);
            }
        }

        mt.retomar(); // Inicia a thread - de facto
        mt.multMatriz();
        mt.finalizar();

        for (int i = 0; i < Multipl.matR.length; i++) {
            for (int j = 0; j < Multipl.matR.length; j++)
                System.out.print(Multipl.matR[i][j] + " \t");
            System.out.println();
        }

        System.out.println("Tempo total: "
                + (double)(System.currentTimeMillis() - TI)/1000 + "s");

        try {
            mt.td.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
            return;
        }
    }
}

