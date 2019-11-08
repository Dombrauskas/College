/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package eleicoes;

import java.util.*;
import java.util.TreeSet;
import java.util.Vector;

/**
 *
 * @author Maurício
 */
public class Urna {
    private TreeSet<Candidato> candidatos = new TreeSet<Candidato>(); //lista de candidatos
    private Vector<Integer> votos = new Vector<Integer>(); //no máximo 5 votos
     
    public Urna() {
        Candidato c1 = new Candidato();        
        Candidato c2 = new Candidato();
        
       candidatos.add(c1);
       candidatos.add(c2);
    }
    
    public Candidato getCandidato(int numero) throws UrnaException {
        for(Candidato c : candidatos) {
            if(c.getNumero().equals(numero)) {
                return c;
            }
        }
        throw new UrnaException("Cadidato não encontrado!");
    }
    
    public TreeSet<Candidato> getCandidatos() {
        return this.candidatos;
    }
    
    public void inserirVoto(int numero) {
        votos.add(numero);
    }
    
    public Vector<Integer> getVotos() {
        return this.votos;
    }
    
    public TreeSet<Candidato> contabilizar() {
        TreeSet<Candidato> t = new TreeSet<Candidato>();
        int total;
        Candidato c = new Candidato();
        Set<Integer> chave = c.getNumero().keySet();
        for(Candidato ch : candidatos) {
            total = 0;
            for(int v : votos) {
                if (c.getNumero().equals(v)) total++;
            }
            c.setTotal(total);
            t.add(c);
        }
        this.candidatos = t;
        return this.candidatos;
    }
    
}
