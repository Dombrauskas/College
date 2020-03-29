package Parte_II;

public class Multipl implements Runnable {
    Thread td;
    static int tamanho = 0;
    static boolean controle, aguardar;
    static double[][] mat1, mat2, matR;

    Multipl(String name) {
        td = new Thread(this, name);
        controle = aguardar = false;

        try {
            Thread.sleep(2500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
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
        matR = new double[tamanho][tamanho];
        System.out.println("Matriz Resultado criada na Thread");

        for (int i = 0; i < mat1.length; i++)
            for (int j = 0; j < mat2.length; j++)
                for (int k = 0; k < mat1.length; k++)
                    matR[i][j] = matR[i][j] + mat1[i][k] * mat2[k][j];

        System.out.println("Cálculo efetuado");
    }
}

