package Parte_II;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Multipl implements Runnable {
    Thread td;
    static double TI;
    private int id = 0;
    static int tamanho = 0;
    static boolean controle, aguardar;
    static int[][] mat1, mat2, matR;

    Multipl(String name) {
        td = new Thread(this, name);
        controle = aguardar = false;
        td.start();
    }

    Multipl() { }

    @Override
    public void run() {
        multMatriz();
    }

    /** Cálcula a matriz resultado */
    public synchronized void multMatriz() {
        matR = new int[tamanho][tamanho];

        for (int i = 0; i < mat1.length; i++) {
            for (int j = 0; j < mat2.length; j++) {
                for (int k = 0; k < mat1.length; k++) {
                    matR[i][j] = matR[i][j] + mat1[i][k] * mat2[k][j];
                }
            }
        }
    }

    public void criarArquivo(boolean b, int[][] ... matriz) {
        try (FileWriter fw = new FileWriter("Desempenho.txt", b)) {
            int count = 0;
            while (count < matriz.length) {
                if (id < 2) fw.write("Matriz " + id + "\n");
                else fw.write("Matriz Resultado\n");

                for (int j = 0; j < mat1.length; j++) {
                    for (int k = 0; k < mat2.length; k++) {
                        fw.write(Integer.toString(matriz[count][j][k]) + "\t\t");
                    }
                    fw.write("\n");
                }
                fw.write("\n");

                if (id == 2)
                    fw.write("\nTempo total " + Double.toString((double)
                        (System.currentTimeMillis() - TI)/1000) + "s");

                ++count;
                ++id;
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

