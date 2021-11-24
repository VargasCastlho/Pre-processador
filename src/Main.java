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
        BufferedReader br;
        String arquivo;
        br = TratamentoArquivo.LeituraAbrirArquivo(nome);
        arquivo = ProcessamentoArquivo.ComentarioSimples(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(arquivo, nome);
    }

    static void AtivarComentarioComplexo(String nome) throws IOException {
        BufferedReader br;
        String arquivo;
        br = TratamentoArquivo.LeituraAbrirArquivo(TratamentoArquivo.NomeProcessado(nome));
        arquivo = ProcessamentoArquivo.ComentarioComplexo(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(arquivo, nome);
    }
}
