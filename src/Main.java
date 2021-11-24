import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        String nome;
            //nome = JOptionPane.showInputDialog(null, "Entre com o nome do arquivo");
            nome = "arquivo_entrada.c";
            AtivarComentarioSimples(nome);
            AtivarComentarioComplexo(nome);
    }

    static void AtivarComentarioSimples(String nome) throws IOException {
        BufferedReader br = null;
        String linha = null;
        br = TratamentoArquivo.LeituraAbrirArquivo(nome);
        linha = ProcessamentoArquivo.ComentarioSimples(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(linha, nome);
    }

    static void AtivarComentarioComplexo(String nome) throws IOException {
        BufferedReader br;
        String linha;
        br = TratamentoArquivo.LeituraAbrirArquivo(TratamentoArquivo.NomeProcessado(nome));
        linha = ProcessamentoArquivo.ComentarioComplexo(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(linha, nome);
    }
}
