import javax.swing.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        ProcessaArquivo();
    }

    static void ProcessaArquivo() {
        try {
            String linha;
            String nome;
            nome = JOptionPane.showInputDialog(null, "Entre com o nome do arquivo");

            BufferedReader br = new BufferedReader(new FileReader("arquivo_entrada.c"));
            linha = ComentarioSimples(br);
            br.close();
            System.out.println(linha);
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }

    static String ComentarioSimples(BufferedReader br) throws IOException {
        String arq = null;
        String linha;
        while (br.ready()) {
            linha = br.readLine() + "\n";
            if (linha.contains("//")==false)
                arq += linha;
            else{
                int index = linha.indexOf("//");
                if(index==0)
                    arq += linha.substring(0, index);
                else
                    arq += linha.substring(0, index) + "\n";
            }
        }
        return arq;
    }
}
