import javax.swing.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        ProcessaArquivo();
    }

    static void ProcessaArquivo() {
        try {
            BufferedReader br;
            String linha;
            String nome;
            nome = JOptionPane.showInputDialog(null, "Entre com o nome do arquivo");
            br = LeituraAbrirArquivo("arquivo_entrada.c");
            linha = ComentarioSimples(br);
            LeituraFecharArquivo(br);
            EscritaArquivo(linha);
            System.out.println(linha);
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }

    static BufferedReader LeituraAbrirArquivo(String nome) throws IOException {
        return new BufferedReader(new FileReader(nome));
    }

    static void LeituraFecharArquivo(BufferedReader br) throws IOException {
        br.close();
    }

    static void EscritaArquivo(String processado) throws IOException {
        FileWriter arq = new FileWriter("arquivo_pre_processado.c");
        PrintWriter gravarArq = new PrintWriter(arq);
        gravarArq.printf("%s",processado);
        arq.close();
    }

    static String ComentarioSimples(BufferedReader br) throws IOException {
        String arq = "";
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
