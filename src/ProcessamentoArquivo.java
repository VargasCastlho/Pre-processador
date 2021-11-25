import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

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
                while (linha.contains("*/") == false) {
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
        }catch (FileNotFoundException e){
            System.out.println("Erro: "+e.getMessage());
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
}