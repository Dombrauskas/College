package Parte_II;

public class Combinação implements Runnable {
    Thread td;
    private int fat, res;

    Combinação(String nome, int num) {
        td = new Thread(this, nome);
        fat = num;
        td.start();
    }

    public void run() {
        System.out.println(td.getName());
        Resultado rs = this::fatorial;
        res = rs.func(fat);
    }

    synchronized int fatorial(int f) {
        if (f == 1) return 1;
        return f * fatorial(--f);
    }

    public int getRes() { return res; }
}
