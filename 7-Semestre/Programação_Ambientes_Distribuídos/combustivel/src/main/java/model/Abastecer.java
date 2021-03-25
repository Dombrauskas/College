package model;

/**
 * @author Maurício Freire
 * Date 10/03/2021 at 14:03
 * Created on IntelliJ IDEA
 */

public class Abastecer {
    private float gasolina;
    private float etanol;
    private String melhor;

    public Abastecer() {
    }

    public float getGasolina() {
        return gasolina;
    }

    public void setGasolina(float gasolina) {
        this.gasolina = gasolina;
    }

    public float getEtanol() {
        return etanol;
    }

    public void setEtanol(float etanol) {
        this.etanol = etanol;
    }

    public String getMelhor() {
        return melhor;
    }

    public void setMelhor(String melhor) {
        this.melhor = melhor;
    }
}
