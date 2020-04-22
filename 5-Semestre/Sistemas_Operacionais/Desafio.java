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

        Multipl.mat1 = new int[Multipl.tamanho][Multipl.tamanho];
        Multipl.mat2 = new int[Multipl.tamanho][Multipl.tamanho];

        System.out.println("Duas matrizes de tamanho " + Multipl.tamanho + "x"
                + Multipl.tamanho + " foram criadas");

        Multipl mt = new Multipl();
        Multipl[] ob;
        if (Multipl.tamanho < 5)
            ob = new Multipl[Multipl.tamanho];
        else ob = new Multipl[5];

        Random rd = new Random();

        // Gera duas matrizes com valores aleatórios.
        for (int i = 0; i < Multipl.tamanho; i++) {
            for (int j = 0; j < Multipl.tamanho; j++) {
                Multipl.mat1[i][j] = (int) rd.nextGaussian();
                Multipl.mat2[i][j] = (int) rd.nextGaussian();
            }
        }

        for (int k = 0; k < ob.length; k++)
            ob[k] = new Multipl(Integer.toString(k));

        // Inicia a contagem do tempo
        Multipl.TI = System.currentTimeMillis();

        mt.criarArquivo(false, Multipl.mat1, Multipl.mat2);
        mt.criarArquivo(true, Multipl.matR);
    }
}

