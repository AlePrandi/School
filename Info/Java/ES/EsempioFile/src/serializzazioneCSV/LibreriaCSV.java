package serializzazioneCSV;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;

import com.google.gson.Gson;

import originali.Autore;
import originali.Libreria;
import originali.Libro;

public class LibreriaCSV extends Libreria {
    private Vector<Libro> libri;

    public LibreriaCSV() {
        libri = new Vector<Libro>();
    }

    public void addVolume(Libro libro) {
        libri.add(libro);
    }

    public float getValore() {
        float valore = 0;
        for (Libro libro : libri) {
            valore += libro.getPrezzo();
        }
        return valore;
    }

    // metodi necessari per la deserializzazione
    public Vector<Libro> getLibri() {
        return libri;
    }

    public void setLibri(Vector<Libro> libri) {
        this.libri = libri;
    }

    public void salvaFileCSV(String nomeFile) throws IOException {
        FileWriter fw = new FileWriter(nomeFile);
        fw.write("CostoPaginaFisso\n");
        fw.write("" + Libro.getCostoPagina() + "\n");
        fw.write("Titolo, Nome, Cognome, NumeroPagine \n");
        for (Libro l : libri) {
            fw.write("" + l.getTitolo() + ",");
            fw.write("" + l.getAutore() + ",");
            fw.write("" + l.getNumeroPagine());
            fw.write("\n");
        }
        fw.close();
    }

    public void caricaFileJSON2(String nomeFile) throws IOException {
        Gson gson = new Gson();
        FileReader fr = new FileReader(nomeFile);
        LibreriaCSV lib = gson.fromJson(fr, LibreriaCSV.class);
        System.out.println("<<<"+lib);
        this.setLibri(lib.getLibri());
    }

    public void SalvaSuFileJSON(String nomefile) throws IOException {
        FileWriter fw = new FileWriter(nomefile);
        fw.write("{\n");
        fw.write("\t\"Costo pagina fisso\": "+Libro.getCostoPagina()+",\n");
        fw.write("\t\"Libri\":[" + "\n");
        int k = 0;
        for(Libro l:getLibri()){
            fw.write("\t\t{ \n");
            fw.write("\t\t\"Autore\": {\n"
                    +"\t\t\t\"cognome\": \""+l.getAutore().getCognome()+ "\",\n"
                    +"\t\t\t\"nome\": \""+l.getAutore().getNome()+ "\"\n \t\t\t}, \n"
                    + "\t\t\"Titolo\": \""+ l.getTitolo()+"\",\n"
                    + "\t\t\"Numero pagine\": " + l.getNumeroPagine() + "\n");
            if(k<getLibri().size()-1){
                fw.write("\t\t},\n");
            }else{
                fw.write("\t\t}\n");
            }
            k++;
        }
        fw.write("\t]\n");
        fw.write("}");
        fw.close();
    }

    public void caricaDaFile(String nomeFile) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(nomeFile));
        String s = "";
        String[] line = null;
        s = br.readLine();
        s = br.readLine();
        Libro.setCostoPagina(Double.parseDouble(s));
        s = br.readLine();
        s = br.readLine();
        while (s != null) {
            line = s.split(",");
            String titolo = line[0];
            String nomeAutore = line[1];
            String cognomeAutore = line[2];
            int numeroPagine = Integer.parseInt(line[3]);
            Autore autore = new Autore(nomeAutore, cognomeAutore);
            Libro libro = new Libro(titolo, autore, numeroPagine);
            libri.add(libro);
            s = br.readLine();
        }
        br.close();
    }

    @Override
    public String toString() {
        return "Libreria = " + libri;
    }
}
