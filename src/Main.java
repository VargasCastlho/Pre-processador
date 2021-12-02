import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        String nome;
        nome = JOptionPane.showInputDialog(null, "Entre com o nome do arquivo:");
        String arquivoFinal = AtivarCriarArquivoProcessado(nome);
        arquivoFinal = ProcessamentoArquivo.TratarBibliotecaExterna(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.ComentarioSimples(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.ComentarioComplexo(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.TratarDefine(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.tratarCompactacao(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.TratarBiblioteca(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.ComentarioSimples(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.ComentarioComplexo(arquivoFinal);
        arquivoFinal = ProcessamentoArquivo.TratarLinha(arquivoFinal);
        EscreverArquivo(arquivoFinal, nome);
    }

    static String AtivarCriarArquivoProcessado(String nome) throws IOException {
        BufferedReader br;
        String arquivo;
        br = TratamentoArquivo.LeituraAbrirArquivo(nome);
        arquivo = ProcessamentoArquivo.CriarArquivoProcessado(br);
        TratamentoArquivo.LeituraFecharArquivo(br);
        return arquivo;
    }

    static void EscreverArquivo(String arquivoFinal, String nome) throws IOException {
        BufferedReader br;
        br = TratamentoArquivo.LeituraAbrirArquivo(TratamentoArquivo.NomeProcessado(nome));
        TratamentoArquivo.LeituraFecharArquivo(br);
        TratamentoArquivo.EscritaArquivo(arquivoFinal, nome);
    }
}