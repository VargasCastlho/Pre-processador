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
        String linha = null;
        String str;
        while (br.ready()) {
            str = br.readLine() + "\n";
            if (str.contains("//")==false)
                linha += str;
            else{
                linha += str.substring(0, str.indexOf("//")) + "\n";
            }
        }
        return linha;
    }
}
