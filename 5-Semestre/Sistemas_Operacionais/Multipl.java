package Parte_II;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Multipl implements Runnable {
    Thread td;
    double TT;
    static int tamanho = 0;
    static boolean controle, aguardar;
    static int[][] mat1, mat2, matR;

    Multipl(String name) {
        td = new Thread(this, name);
        controle = aguardar = false;

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        TT = (double) System.currentTimeMillis();
        td.start();
    }

    @Override
    public void run() {
        System.out.println("Iniciando thread " + td.getName());
        try {
            synchronized(this) {
                while(aguardar) wait();
            }
        }
        catch (InterruptedException e) {
            System.out.println("Thread " + td.getName() + " interrompido!");
        }
        multMatriz();
    }

    /** Métodos de controle */
    synchronized void interromper() {
        aguardar = true;
        System.out.println("Pausando a thread");
    }

    synchronized void retomar() {
        aguardar = false;
        System.out.println("Retomando a thread");
        notify();
    }

    synchronized void finalizar() {
        controle = true;
        aguardar = false;
        System.out.println("Finalizando a thread");
        notify();
    }

    /** Cálcula a matriz resultado */
    public synchronized void multMatriz() {
        /**
         * Obsoleto
        if (tamanho == 0) {
            //controle = true;
            try {
               while(controle) {
                    this.wait();
                    System.out.println(td.getState().toString());
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        */
        matR = new int[tamanho][tamanho];
        System.out.println("Matriz Resultado criada na Thread");

        for (int i = 0; i < mat1.length; i++)
            for (int j = 0; j < mat2.length; j++)
                for (int k = 0; k < mat1.length; k++)
                    matR[i][j] = matR[i][j] + mat1[i][k] * mat2[k][j];

        System.out.println("Cálculo efetuado");
        criarArquivo(mat1, mat2, matR);
    }

    public void criarArquivo(int[][] ... matriz) {
        try (FileWriter fw = new FileWriter("Desempenho.txt")) {
            for (int i = 0; i < 3; i++) {
                if (i < 2) fw.write("Matriz " + i + "\n");
                else fw.write("Matriz Resultado\n");
                for (int j = 0; j < mat1.length; j++) {
                    for (int k = 0; k < mat2.length; k++) {
                        fw.write(Integer.toString(matriz[i][j][k]) + "\t\t");
                    }
                    fw.write("\n");
                }
                fw.write("\n");
            }
            fw.write("\nTempo total " + Double.toString((double)
                    (System.currentTimeMillis() - TT)/1000) + "s");
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

