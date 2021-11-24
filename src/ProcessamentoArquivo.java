import java.io.BufferedReader;
import java.io.IOException;

public class ProcessamentoArquivo {
    static String ComentarioSimples(BufferedReader br) throws IOException {
        String arq = "";
        String linha;
        while (br.ready()) {
            linha = br.readLine() + "\n";
            if (!linha.contains("//"))
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
    static String ComentarioComplexo(BufferedReader br) throws IOException {
        String arq ="";
        String linha;
        while(br.ready()) {
            linha = br.readLine()+"\n";
            if(!linha.contains("/*"))
                arq += linha;
            else{
                int indexPrimeiro = linha.indexOf("/*");
                if(indexPrimeiro>0)
                    arq += linha.substring(0,indexPrimeiro)+"\n";
                else
                    arq += linha.substring(0,indexPrimeiro);
                linha = br.readLine();
                while(linha.contains("*/") == false){
                    linha = "";//tirar todas as linhas enquanto não encontrar o "*/"
                    arq += linha;
                    linha = br.readLine();
                }
                //chegando aqui quer dizer que a linha contem o "*/"
                int indexSegundo = linha.indexOf("*/");
                if(indexSegundo+2 == linha.length())
                    arq += linha.substring(indexSegundo+2,linha.length());
                else
                    arq += linha.substring(indexSegundo+2,linha.length())+"\n";
            }
        }
        return arq;
    }
}
