package control;

import model.Abastecer;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.RequestScoped;

/**
 * @author Maurício Freire
 * Date 10/03/2021 at 14:05
 * Created on IntelliJ IDEA
 */

@ManagedBean
@RequestScoped
public class AbastecerBean {
    private Abastecer abastecer = new Abastecer();

    public AbastecerBean() { }

    public Abastecer getAbastecer() { return abastecer; }

    public void setAbastecer(Abastecer abastecer) { this.abastecer = abastecer; }

    public String maiorEconomia() {
        abastecer.setMelhor(vantagem());
        return "/melhorEscolha";
    }

    public String vantagem() {
        float v = (float) (getAbastecer().getGasolina() + (getAbastecer().getGasolina() * 0.7));
        if (getAbastecer().getEtanol() < v)
            return "Etanol";
        else return "Gasolina";
    }
}
