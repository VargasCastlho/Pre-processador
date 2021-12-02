import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ProcessamentoArquivo {
    static String ComentarioSimples(String arquivoFinal) throws IOException {
        String arq = "";
        String linha;
        for(int i = 0; i<arquivoFinal.split("\n").length;i++){
            linha = arquivoFinal.split("\n")[i] + "\n";
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

    static String ComentarioComplexo(String arquivoFinal) throws IOException {
        String arq = "";
        String linha;
        for(int i = 0; i<arquivoFinal.split("\n").length;i++){
            linha = arquivoFinal.split("\n")[i] + "\n";
            if (!linha.contains("/*"))
                arq += linha;
            else {
                int indexPrimeiro = linha.indexOf("/*");
                if (indexPrimeiro > 0)
                    arq += linha.substring(0, indexPrimeiro) + "\n";
                else
                    arq += linha.substring(0, indexPrimeiro);
                while (!linha.contains("*/")) {
                    linha = "";//tirar todas as linhas enquanto não encontrar o "*/"
                    arq += linha;
                    linha = arquivoFinal.split("\n")[++i];
                }
                //chegando aqui quer dizer que a linha contem o "*/"
                int indexSegundo = linha.indexOf("*/");
                if (indexSegundo + 2 == linha.length()) {
                    arq += linha.substring(indexSegundo + 2);
                }
                else
                    arq += linha.substring(indexSegundo + 2) + "\n";
            }
        }
        return arq;
    }

    static String TratarBiblioteca(String arquivoFinal) {
        String arq = "";
        String arquivo = "";
        String biblioteca;
        String linha = "";
        BufferedReader aux;
        try {
            for(int i = 0; i<arquivoFinal.split("\n").length;i++){
                linha = arquivoFinal.split("\n")[i] + "\n";
                if (linha.contains("#include")&&linha.substring(linha.indexOf("#include ") + 9).startsWith("<")) {
                    String include = "#include ";
                    int index = linha.indexOf(include) + 10;
                    biblioteca = linha.substring(index, linha.length() - 2);
                    aux = TratamentoArquivo.LeituraAbrirArquivo("C:\\MinGW\\include\\" + biblioteca);
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

    static String TratarDefine(String arquivoFinal) throws IOException {
        Map<String, String> variavelValor = new HashMap<>();
        ArrayList<String> variavelNome = new ArrayList();
        String linha, linhaDef;
        String nomeVariavel, valorVariavel;
        for(int i = 0; i<arquivoFinal.split("\n").length;i++){
            linha = arquivoFinal.split("\n")[i] + "\n";
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
        return DefinirTratarDefine(variavelValor, variavelNome, arquivoFinal);
    }

    static String DefinirTratarDefine(Map variavelValor, ArrayList<String> variavelNome, String arquivoFinal) throws IOException {
        String linha = "", linhaAntes, linhaDps;
        String arq = "";
        for (int j = 0; j < variavelNome.size(); j++) {
            for (int i = 0; i < variavelNome.size(); i++) {
                arq = "";
                for(int x = 0; x<arquivoFinal.split("\n").length;x++){
                    linha = arquivoFinal.split("\n")[x] + "\n";
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
                arquivoFinal = arq;
            }
        }
        return arq;
    }

    static String tratarCompactacao(String arquivoFinal) throws IOException {
        //1ºpasso compactar toda a linha particularmente com as restrições quanto à função
        String linha;
        String arq = "";
        for(int x = 0; x<arquivoFinal.split("\n").length;x++){
            int verifica = 0;
            linha = arquivoFinal.split("\n")[x] + "\n";
            ArrayList<String> vetor = new ArrayList();
            vetor.add("int");vetor.add("char");vetor.add("return");vetor.add("void");vetor.add("typedef struct");
            for(int i = 0; i<vetor.size(); i++) {
                if (linha.contains(vetor.get(i))) {

                    String string = vetor.get(i);
                    linha = linha.replace(string + " ", string + "´");//tombei apenas os espaços pós tipos ou returns para diferenciar de outro espaço
                    if(linha.contains("\"")) {
                        String linhaAntes, linhaDps;
                        linhaAntes = linha.substring(0, linha.indexOf("\""));
                        linhaDps = linha.substring(linha.lastIndexOf("\"") + 1);
                        linhaAntes = linhaAntes.replace(" ", "");
                        linhaDps = linhaDps.replace(" ", "");
                        linha = linhaAntes + linha.substring(linha.indexOf("\""), linha.lastIndexOf("\"") + 1) + linhaDps;
                    }
                    else
                        linha = linha.replace(" ", "");
                    linha = linha.replace(string + "´", string + " ");
                    verifica = 1;
                }
            }
            if(verifica == 0){
                    linha = linha.replace(" ", "");
            }
            arq += linha;

        }
        return compactacaoTotal(arq);
    }

    static String compactacaoTotal(String arquivoFinal) throws IOException {
        //2º juntar todas as linhas brutalmente, já que só falta isso.
        String linha;
        String arq = "";
        for(int i = 0; i<arquivoFinal.split("\n").length;i++){
            linha = arquivoFinal.split("\n")[i];
            if(linha.contains("#include")||linha.contains("#define"))
                arq += linha + "\n";
            else
                arq += linha;
        }
        return arq;
    }

    static String TratarLinha(String arquivoFinal) {
        String arq = "";
        String linha = "";
            for(int i = 0; i<arquivoFinal.split("\n").length;i++){
                linha = arquivoFinal.split("\n")[i] + "\n";
                if(linha.isBlank()){
                    linha = "";
                }
                arq += linha;
            }
        return arq;
    }

    static String TratarBibliotecaExterna(String arquivoFinal) {
        String arq = "";
        String arquivo = "";
        String biblioteca;
        String linha = "";
        BufferedReader aux;
        try {
            for(int i = 0; i<arquivoFinal.split("\n").length;i++){
                linha = arquivoFinal.split("\n")[i] + "\n";
                if (linha.contains("#include")&&linha.substring(linha.indexOf("#include ") + 9).startsWith("\"")) {
                    String include = "#include ";
                    int index = linha.indexOf(include) + 10;
                    biblioteca = linha.substring(index, linha.length() - 2);
                    aux = TratamentoArquivo.LeituraAbrirArquivo("C:\\MinGW\\include\\" + biblioteca);
                    while (aux.ready()) {
                        arquivo += aux.readLine() + "\n";
                    }
                    TratamentoArquivo.LeituraFecharArquivo(aux);
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
}
