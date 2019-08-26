/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
*/
package aula03;

/**
 *
 * @author Maurício
*/
public class Tanque {
    private float volumeMax;
    private float volumeMin;
    private float volumeAtl;
    private boolean bomba;
        
    void encher(float litros) {
        volumeAtl += litros;
        bomba = volumeAtl <= volumeMin;
    }
    
    void setVolumeMax(float capacidade) {
        volumeMax = capacidade;
    }
    
    void setVolumeMin(float min) {
        volumeMin = min;
    }
    
    float getVolumeMax() { return volumeMax; }
    
    float getVolumeMin() { return volumeMin;}
    
    void esvaziar(float litros) {
        volumeAtl -= litros;
    }
    
    float getVolumeAtual() { return volumeAtl; }
    
    String exibirInfos() {
        String str;
        if (bomba) str = " encher o tanque";
        else str = " não encher o tanque";
       
        return "Volume atual do tanque " + volumeAtl + "L, " + str;
    }
}
