package E2;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.util.Random;

/**
 * @author Maurício Freire
 * Date 13/04/2020 at 16:36
 * Created on IntelliJ IDEA
 */
public class Ex2b {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String size;
        int tamanho, comb;
        tamanho = comb = 0;

        System.out.print("Tamanho do vetor: ");
        size = br.readLine();
        tamanho = Integer.parseInt(size);
        int[] array = new int[tamanho];

        Random rd = new Random();
        Arquivo arq = new Arquivo();
        for (int i = 0; i < tamanho; i++)
            array[i] = rd.nextInt(1001);

        arq.criarAquivo(array, false);
        
        for (int a : array)
            System.out.print(a + " ");

        System.out.print("\nQuantidade de combinações: ");
        size = br.readLine();
        comb = Integer.parseInt(size);

        int s = 0;
        long f;
        Geradora[] ger = new Geradora[4];
        f = (fatorial(tamanho) / (fatorial(comb) * (fatorial(tamanho - comb))));
        double db = (double) System.currentTimeMillis();
        while (s < f) {
            ger[s % 4] = new Geradora(array, (s % tamanho), comb, f);
            s++;
        }

        try (FileWriter fw = new FileWriter("Combinacoes.txt", true)) {
            ger[0].td.join();
            ger[1].td.join();
            ger[2].td.join();
            ger[3].td.join();
            db = (double) (System.currentTimeMillis() - db)/1000;
            fw.write("\nTempo total: " + db + "s\n");
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(f);
    }

    public static int fatorial(int n) {
        if (n == 1) return 1;
        return n * fatorial(--n);
    }
}

class Geradora implements Runnable {
    Thread td;
    int[] vetor, cbn;
    int combina, inicio;
    long fat;
    Arquivo ob = new Arquivo();

    Geradora(int[] vetor, int ini, int c, long fat) {
        td = new Thread(this, String.valueOf(ini % 4));
        this.vetor = vetor;
        combina = c;
        inicio = ini;
        this.fat = fat;
        td.start();
    }

    @Override
    public void run() {
        synchronized(this) {
            ///*cbn = */criarCombina(inicio);
            JF();
            System.out.println();
        }
    }

    public void JF() {
        int j, id, aux, d = 0;
        int[] v_idx = new int[combina];
        int[] res = new int[combina];

        while (d < fat) {
            j = vetor[0];
            for (int i = 0; i < combina; i++) {
                v_idx[i] = j;
                j++;
                res[i] = vetor[v_idx[i]];
            }
            ob.criarAquivo(res, true);
            aux = vetor.length - 1;
            id = combina - 1;
            while (v_idx[id] != vetor[0]) {
                if (v_idx[id] == aux) {
                    id--;
                    aux--;
                } else {
                    v_idx[id]++;
                    for (int i = id; i < vetor.length; i++)
                        v_idx[i] = v_idx[i - 1] + 1;

                    id = vetor.length - 1;
                    aux = combina - 1;
                    for (int i = 0; i < vetor.length; i++) {
                        j = v_idx[i];
                        res[i] = vetor[v_idx[i]];
                    }
                    ob.criarAquivo(res, true);
                }
            }
            d++;
        }
    }

    public void cc(int inicio) {
        int[] vet = new int[combina];
        int j = 1;

        while (j <= vetor.length) {
            int v = 0, f = 1;
            vet[0] = vetor[inicio];
            for (int i = inicio + j;  combina - f > 0; i++) {
                f++;
                vet[++v] = vetor[i];
                ob.criarAquivo(vet, true);
            }
            j++;
        }
    }

    public void criarCombina(int inicio) {
        int[] vet = new int[combina];
        int v = 1, f = combina;

        vet[0] = vetor[inicio];
        for (int i = inicio + 1; i < combina + inicio; i++) {
            f--;
            if (i == (vetor.length) || i == (vetor.length - 1)) {
                for (int j = 0; j < f; j++)
                    vet[v++] = vetor[j];
            }
            vet[v++] = vetor[i];
        }

        ob.criarAquivo(vet, true);
        for (int c : vet)
            System.out.print(c + " ");

    }
}

class Arquivo {
    static int count = 0;

    public void criarAquivo(int[] array, boolean overwrite) {
        try (FileWriter fw = new FileWriter("Combinacoes.txt", overwrite)) {
            fw.write("Vetor " + count++ + ":   ");
            for (int i : array)
                fw.write(i + " ");
            fw.write("\n");
        }
        catch (FileNotFoundException e) {
            System.out.println("Falha ao criar o arquivo");
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

