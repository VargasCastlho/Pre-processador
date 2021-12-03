import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;

/*
    A main está ordenada da seguinte forma:
        1º- Pede-se o nome do arquivo a ser pré processado
        2º- Transferimos o conteúdo do arquivo para uma String temporária e criamos o nome do arquivo novo que é
    basicamente o nome do (arquivo de entrada)+"_pre_processado.c"
        Assim dá-se o tratamento com o arquivo de entrada, a partir daí ele se fecha e nós modificamos apenas sua String
        Segue a ordem:
        1º- Nós tratamos a biblioteca externa, que no caso de "arquivo_entrada.c" é a "bib.h"
        2º- Tratamos os comentários lineares("//") e multilineares.
        3º- Tratamos os #defines, ou seja, substituimos as variáveis definidas pelo define com seu devido valor.
        4º- Tratamos das bibliotecas internas(em um primeiro momento não é possível tratá-las antes pela absurda
    quantidade de tipos e ferramentas que não pode ser compactada)
        5º- Tratamos dos comentários dessas bibliotecas, assim como a etapa 2
        6º- Tiramos os espaços entre linhas e escrevemos a String no arquivo pre processado.
 */

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