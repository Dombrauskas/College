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

        String size;

        while (Multipl.tamanho <= 0) {
            System.out.print("Informe o tamanho da matriz: ");
            size = br.readLine();
            Multipl.tamanho = Integer.parseInt(size);
        }

        Multipl.TI = System.currentTimeMillis();

        Multipl.mat1 = new int[Multipl.tamanho][Multipl.tamanho];
        Multipl.mat2 = new int[Multipl.tamanho][Multipl.tamanho];

        System.out.println("Duas matrizes de tamanho " + Multipl.tamanho + "x"
                + Multipl.tamanho + " foram criadas");

        Multipl ob = new Multipl("Multipl.tamanho");
//        for (int k = 0; k < Multipl.tamanho; k++)
//            ob[k] = new Multipl(Integer.toString(k));

        Random rd = new Random();

        // Gera duas matrizes com valores aleatórios.
        for (int i = 0; i < Multipl.tamanho; i++) {
            for (int j = 0; j < Multipl.tamanho; j++) {
                Multipl.mat1[i][j] = (int) rd.nextGaussian();
                Multipl.mat2[i][j] = (int) rd.nextGaussian();
            }
        }
        ob.criarArquivo(false, Multipl.mat1, Multipl.mat2);
        ob.criarArquivo(true, Multipl.matR);

//        for (int i = 0; i < Multipl.matR.length; i++) {
//            for (int j = 0; j < Multipl.matR.length; j++)
//                System.out.print(Multipl.matR[i][j] + " \t");
//            System.out.println();
//        }
    }
}

