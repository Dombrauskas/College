/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package eleição;

import java.util.Scanner;
import java.util.InputMismatchException;
/**
 *
 * @author Maurício
*/
public class Eleição {
    public static void main(String[] args) throws urnaExceção {
        int votos = 0, n = 0;
        Scanner sc = new Scanner(System.in);
        urna urna = new urna();
        
        do {
            while(votos < urna.getVotos().length) { 
                System.out.println("==== ELEICOES ====");
                System.out.print("Digite o numero o candidato..: ");

                do {
                    try {
                        n = sc.nextInt();
                        break;
                    }
                    catch(InputMismatchException e) {
                        System.out.println("Erro de digitação");
                    }
                } while (true);

                try {
                    candidato c = urna.getCandidato(n);
                    System.out.print("Candidato "+ c.getNome() + " confirma ? (S/N)");
                    throw new urnaExceção("Candidato não encontrado!");
                }
                catch(urnaExceção e) {
                    System.out.println(e.getMessage());
                    System.out.println("Confirmar voto? (S/N)");
                    String op = sc.next();
                    op = op.toUpperCase();
                    if(op.equals("S")) {
                        urna.inserirVoto(n);
                        votos++;
                    } else System.out.println("Voto cancelado!");
                }

                try {
                    String op = sc.next();
                    if(op.equals("S")) {
                        urna.inserirVoto(n);
                        votos++;
                    } else {
                        throw new EntradaExceção("Voto não válido");
                    }
                }
                catch (EntradaExceção e) {
                    System.out.println(e.getMessage());
                }  
            } // fim while voto
        } while (votos >= (--votos));
       //mostrarResultados(urna);
    }
}
