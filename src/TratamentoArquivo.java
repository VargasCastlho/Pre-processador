import java.io.*;

public class TratamentoArquivo {
    static String NomeProcessado(String nome) {
        return nome.substring(0, nome.length() - 2) + "_pre_processado.c";
    }

    static BufferedReader LeituraAbrirArquivo(String nome) throws IOException {
        return new BufferedReader(new FileReader(nome));
    }

    static void LeituraFecharArquivo(BufferedReader br) throws IOException {
        br.close();
    }

    static void EscritaArquivo(String processado, String nome) throws IOException {
        FileWriter arq = new FileWriter(NomeProcessado(nome));
        PrintWriter gravarArq = new PrintWriter(arq);
        gravarArq.printf("%s", processado);
        arq.close();
    }
}