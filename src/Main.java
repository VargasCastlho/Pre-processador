import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        String nome;
        //nome = JOptionPane.showInputDialog(null, "Entre com o nome do arquivo");
        nome = "arquivo_entrada.c";
        AtivarCriarArquivoProcessado(nome);
        AtivarComentarioSimples(nome);
        AtivarComentarioComplexo(nome);
        AtivarTratarBiblioteca(nome);
    }

    static void AtivarCriarArquivoProcessado(String nome) throws IOException {
        BufferedReader br;
        String arquivo;
        br = TratamentoArquivo.LeituraAbrirArquivo(nome);
        arquivo = ProcessamentoArquivo.CriarArquivoProcessado(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(arquivo, nome);
    }

    static void AtivarComentarioSimples(String nome) throws IOException {
        BufferedReader br;
        String arquivo;
        br = TratamentoArquivo.LeituraAbrirArquivo(TratamentoArquivo.NomeProcessado(nome));
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

    static void AtivarTratarBiblioteca(String nome) throws IOException {
        BufferedReader br;
        String arquivo;
        br = TratamentoArquivo.LeituraAbrirArquivo(TratamentoArquivo.NomeProcessado(nome));
        arquivo = ProcessamentoArquivo.TratarBiblioteca(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(arquivo, nome);
    }
}
