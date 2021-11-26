import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ProcessamentoArquivo {
    static String ComentarioSimples(BufferedReader br) throws IOException {
        String arq = "";
        String linha;
        while (br.ready()) {
            linha = br.readLine() + "\n";
            if (!linha.contains("//"))
                arq += linha;
            else {
                int index = linha.indexOf("//");
                if (index == 0)
                    arq += linha.substring(0, index);
                else
                    arq += linha.substring(0, index) + "\n";
            }
        }
        return arq;
    }

    static String ComentarioComplexo(BufferedReader br) throws IOException {
        String arq = "";
        String linha;
        while (br.ready()) {
            linha = br.readLine() + "\n";
            if (!linha.contains("/*"))
                arq += linha;
            else {
                int indexPrimeiro = linha.indexOf("/*");
                if (indexPrimeiro > 0)
                    arq += linha.substring(0, indexPrimeiro) + "\n";
                else
                    arq += linha.substring(0, indexPrimeiro);
                linha = br.readLine();
                while (!linha.contains("*/")) {
                    linha = "";//tirar todas as linhas enquanto não encontrar o "*/"
                    arq += linha;
                    linha = br.readLine();
                }
                //chegando aqui quer dizer que a linha contem o "*/"
                int indexSegundo = linha.indexOf("*/");
                if (indexSegundo + 2 == linha.length())
                    arq += linha.substring(indexSegundo + 2);
                else
                    arq += linha.substring(indexSegundo + 2) + "\n";
            }
        }
        return arq;
    }

    static String TratarBiblioteca(BufferedReader br) {
        String arq = "";
        String arquivo = "";
        String biblioteca;
        String linha = "";
        BufferedReader aux;
        try {
            while (br.ready()) {
                linha = br.readLine() + "\n";
                if (linha.contains("#include")) {
                    String include = "#include ";
                    int index = linha.indexOf(include) + 10;
                    biblioteca = linha.substring(index, linha.length() - 2);
                    aux = TratamentoArquivo.LeituraAbrirArquivo(biblioteca);
                    while (aux.ready()) {
                        arquivo += aux.readLine() + "\n";
                    }
                    linha = arquivo;
                }
                arq += linha;
            }
        } catch (FileNotFoundException e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return arq;
    }

    static String CriarArquivoProcessado(BufferedReader br) throws IOException {
        String arq = "";
        while (br.ready()) {
            arq += br.readLine() + "\n";
        }
        return arq;
    }

    static void TratarDefine(BufferedReader br, String nome) throws IOException {
        Map<String, String> variavelValor = new HashMap<>();
        ArrayList<String> variavelNome = new ArrayList();
        String linha, linhaDef;
        String nomeVariavel, valorVariavel;
        while (br.ready()) {
            linha = br.readLine() + "\n";
            if (linha.contains("#define")) {
                int indexNomeVariavel = linha.indexOf("#define") + 8;
                linhaDef = linha.substring(indexNomeVariavel, linha.length() - 1);
                nomeVariavel = linha.substring(indexNomeVariavel, linhaDef.indexOf(" ") + 8);
                int indexValorVariavel = linha.indexOf(nomeVariavel) + 1 + nomeVariavel.length();
                valorVariavel = linha.substring(indexValorVariavel, linha.length() - 1);
                variavelValor.put(nomeVariavel, valorVariavel);
                variavelNome.add(nomeVariavel);
            }
        }
        TratamentoArquivo.LeituraFecharArquivo(br);
        DefinirTratarDefine(variavelValor, variavelNome, nome);
    }

    static void DefinirTratarDefine(Map variavelValor, ArrayList<String> variavelNome, String nome) throws IOException {
        BufferedReader br;
        String linha = "", linhaAntes, linhaDps;
        String arq = "";
        for (int j = 0; j < variavelNome.size(); j++) {
            for (int i = 0; i < variavelNome.size(); i++) {
                br = TratamentoArquivo.LeituraAbrirArquivo(TratamentoArquivo.NomeProcessado(nome));
                arq = "";
                while (br.ready()) {
                    linha = br.readLine() + "\n";
                    if (linha.contains(variavelNome.get(i))) {
                        if (linha.substring(0, linha.indexOf(variavelNome.get(i))).equals("#define ") && linha.substring(0, linha.indexOf(variavelNome.get(i)) + variavelNome.get(i).length()).equals("#define " + variavelNome.get(i))) {
                            linha = "";
                        } else {
                            linhaAntes = linha.substring(0, linha.indexOf(variavelNome.get(i)));
                            linhaDps = linha.substring(linha.indexOf(variavelNome.get(i)) + variavelNome.get(i).length());
                            linha = linhaAntes + variavelValor.get(variavelNome.get(i)) + linhaDps;
                        }
                    }
                    arq += linha;
                }
                TratamentoArquivo.LeituraFecharArquivo(br);
                TratamentoArquivo.EscritaArquivo(arq, nome);
            }
        }
    }

    static void tratarCompactacao(BufferedReader br,String nome) throws IOException {
        //1ºpasso compactar toda a linha particularmente com as restrições quanto à função
        String linha;
        String arq = "";
        while(br.ready()) {
            linha=br.readLine()+"\n";
            if(linha.contains("int")||linha.contains("char")||linha.contains("return")) {
                linha.replaceFirst(" ","´");//tombei os espaços pós tipos de funções para diferenciar de outro espaço
            }

            linha.replaceAll(" ", "");
            linha.replaceAll("´"," ");
            arq += linha;

        }
        TratamentoArquivo.EscritaArquivo(arq, nome);
        //compactacaoTotal(br,nome);
    }

    static void compactacaoTotal(BufferedReader br,String nome) throws IOException {
        //2º passo concatenar todas as linhas
        String linha;
        String arq = "";
        while(br.ready()) {
            linha = br.readLine() + "\n";
            arq+=linha.concat(arq);
        }
        TratamentoArquivo.EscritaArquivo(arq,nome);

    }

}
