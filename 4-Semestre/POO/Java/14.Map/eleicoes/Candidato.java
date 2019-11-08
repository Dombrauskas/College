/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package eleicoes;

import java.util.*;
import java.io.*;

/**
 *
 * @author Maurício
*/
public class Candidato {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    Scanner ler = new Scanner(System.in);
    
    private Map<String, Integer> map;
    private int total;

    public Candidato() {
        map = new HashMap<>();    
        criarMap();
        exibirMap();
    }
    
    private void criarMap() {
        System.out.print("Digite o nome do candidato: ");
        String nome = ler.nextLine();
        
        StringTokenizer st = new StringTokenizer(nome);
        
        while (st.hasMoreTokens()) {
            String nm = st.nextToken();
            if (map.containsKey(nm)) {
                int count = map.get(nm);
                map.put(nm, count + 1);
            }
            else map.put(nm, 1);
        }
    }
     
    private void exibirMap() {
        Set<String> mp = map.keySet();  
        TreeSet<String> sortedKeys = new TreeSet<>(mp);
        
        System.out.println("Mapa: ");
        for (String s : sortedKeys)
            System.out.printf(" %-10s%d\n", s, map.get(s));
        
    }
    
    private void criarArquivo() {
        try (FileInputStream fp = new FileInputStream("Votacao.txt")) {
            int conteudo;
            do {
                conteudo = fp.read();
                if (conteudo != -1) System.out.print((char)conteudo);
            } while(conteudo != -1);
        }
        catch (FileNotFoundException e) {
            System.out.println("Arquivo não encontrado!");
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
    
    
    public Map getNumero() {
        return map;
    }
    
    public void setNumero(Integer numero) {
        map = new HashMap<>();
    }
    /*
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    */
    public void setTotal(int x) {
        this.total = x;
    }
    
    public int getTotal() {
        return this.total;
    }
   
}
