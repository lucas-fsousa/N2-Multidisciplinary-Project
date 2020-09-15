#include <stdio.h> // Biblioteca para usar os comandos de entrada e saida
#include <stdlib.h> // Biblioteca padrão e possui a função de (alocação de memoria), controle de processos, conversões e outras.
#include <string.h> // Biblioteca para utilizar e manipular strings
#include <time.h> // Biblioteca de datas e horários
#include <stdbool.h> // Biblioteca para utilizar retornos booleanos
#include <locale.h> // Biblioteca para usar acentos no programa

// Velidar usuario admin
bool validarAdmin(char login[11], char senha[16]){
    FILE *verifadm; // Declaração de variavel ponteiro do tipo FILE
    verifadm = fopen(login, "r"); // Tenta abrir o arquivo de texto referente ao login
    if(verifadm == NULL){ // Se o login não existir, retornará um resultado falso
        fclose(verifadm); // Fecha o arquivo de texto do tipo login caso haja abertura
        return false;
    }else{ // Se o login existir, o programa verificará a senha
        fclose(verifadm); // Fecha o arquivo de texto caso haja abertura
        verifadm = fopen(senha, "r"); // Abre o arquivo de texto do tipo senha
        if(verifadm == NULL){ // Se a senha não existir, retornará um resultado falso
            fclose(verifadm); // Fecha o arquivo de texto do tipo senha caso haja abertura
            return false;
        }else{ // Caso exista senha e login válido, retornará um resultado verdadeiro
            fclose(verifadm); // Fecha o arquivo de texto do tipo senha após sua abertura
            return true;
        }
    }
}

// Criar login do usuario
int criarnumusuario(long long num){
    long long aux; // Variavel auxiliar do tipo long long que suporta digitos extremamente com mais de 15 casas
    aux = num % 10000; // a variavel auxiliar receberá o resto da divisão do numero passado como paramentro na função por 10000(retornará 4 digitos se o numero de parametro for valido)
    if(aux > 9999 || aux < 1000){ // Se o numero tiver mais de 4 digitos ou menos de 4 digitos, o mesmo não será valido e o retorno será negativo.
        return -1;
    }else{ // Se o numero possuir 4 digitos, este será valido e haverá o retorno do mesmo
        return aux;
    }
}

// Funcao para confirmação de cadastro
char confirmacadastro(char nomePs[35], char nomeMa[35], char idade[3], char sex[10], char cpf[12], char endereco[35], char telcont[12], char ctps[12], char dipl[10], char convenio[12]){
    //Informará na tela do usuario todas as informações de cadastro que foram utilizadas para que sejam revisadas previamente a conclusão do cadastro.
    printf("\n ------------------------------------------\n");
    printf("  -- REVISAO DE INFORMACOES DO CADASTRO --\n");
    printf("\n  NOME: %s", nomePs);
    printf("\n ------------------------------------------");
    printf("\n  NOME DA MAE: %s", nomeMa);
    printf("\n ------------------------------------------");
    printf("\n  IDADE: %s", idade);
    printf("\n ------------------------------------------");
    printf("\n  SEXO: %s", sex);
    printf("\n ------------------------------------------");
    printf("\n  CPF: %s",cpf);
    printf("\n ------------------------------------------");
    printf("\n  ENDERECO: %s", endereco);
    printf("\n ------------------------------------------");
    printf("\n  TELEFONE DE CONTATO: %s", telcont);
    printf("\n ------------------------------------------");
    printf("\n  CARTEIRA DE TRABALHO: %s", ctps);
    printf("\n ------------------------------------------");
    printf("\n  CERTIFICACAO DIPLOMA - MEDICINA: %s", dipl);
    printf("\n ------------------------------------------");
    printf("\n  CONVENIO MEDICO: %s", convenio);
    printf("\n ------------------------------------------\n");
}

// Funcao para validar um TELEFONE de contato
bool validaTEL(long long valor){
    int contadig = 0, resto; // Declaração de variaveis
    while(valor != 0){ // Enquanto o valor digitado não for 0 a estrutura de repetição repetira o processo de quebra do numero.
        resto = valor % 10;
        valor = valor / 10;
        contadig++; // Contador recebe +1 no final da operação
    }
    /* Validação condicional será verdadeiro se quantidade de digitos for igual a 11.
    Caso o numero seja inferior ou superior a 11, este será considerado inválido.
    */
    if (contadig == 11){
        return true; // Retorna valor verdadeiro se o numero tiver 11 digitos.
    }else{
        return false; // Retorna falso se houver menos de 11 digitos ou mais de 11 digitos no numero telefonico.
    }
}

// Funcao para validar um CPF
bool validaCPF(long long cpf_entrada){
    int n1 , n2 , n3 , n4 , n5 , n6 , n7 , n8 , n9, d1 , d2, verificador; //Declaração de variaveis
    long long CPF, validar_cpf; //Declaração de variaveis
    CPF = cpf_entrada / 100; // Pega apenas os 9 digitos do CPF sem os digitos verificadores
    // Processo de quebra do numero do CPF para pegar os digitos separadamente
    n1 = CPF /100000000;
    n2 = (CPF/10000000)%10;
    n3 = (CPF/1000000)%10;
    n4 = (CPF/100000)%10;
    n5 = (CPF/10000)%10;
    n6 = (CPF/1000)%10;
    n7 = (CPF/100)%10;
    n8 = (CPF/10)%10;
    n9 = CPF%10;
    // Processo de análise para encontar o primeiro digito verificador
    d1 = ((n1*10)+(n2*9)+(n3*8)+(n4*7)+(n5*6)+(n6*5)+(n7*4)+(n8*3)+(n9*2))%11;
    if(d1<2){ // Se o digito encontrado for menor que 2 este sempre receberá 0
       d1 = 0;
    }else{ // Se o digito encontrado for maior ou igual a 2, este será subtraido de 11(valor máximo da numeração de um CPF).
        d1 = 11 - d1;
    }
    // Processo de análise para encontrar o segundo digito verificador
    d2 = ((n1*11)+(n2*10)+(n3*9)+(n4*8)+(n5*7)+(n6*6)+(n7*5)+(n8*4)+(n9*3)+(d1*2))%11;
    if(d2<2){ // Se o digito encontrado for menor que 2 este sempre receberá 0
        d2 = 0;
    }else{ // Se o digito encontrado for maior ou igual a 2, este será subtraido de 11(valor máximo da numeração de um CPF).
        d2 = 11 - d2;
    }
    verificador = (d1 * 10) + d2; // Calculo do digito verificador;
    validar_cpf = CPF*100+verificador; // concatena o digito verificador com a numeração do CPF
    /* Se o CPF digitado tiver o digito verificador igual ao que foi encontrado no processo de calculo,
    este CPF será valido, caso contrário será considerado um CPF inválido.
    */
    if(validar_cpf == cpf_entrada){
        return true;
    }else{
        return false;
    }
}

// Funcao de pausar a tela
void pause(){
    char pausar[3]; // Declaração da variavel.
    printf("\nPressione qualquer tecla para continuar...\n"); // Informa uma mensagem na tela para o usuario.
    scanf("%c", &pausar); // pega a string que for digitada pelo usuario(1 caractere).
    getchar(); // Aguarda o usuario digitar algo ou telcar enter;
}

// Funcao de limpar tela
void limpatela(){
    if (system("cls")){ // Se o comando interno do sistema for falso(não existir) o comando interno "clear" será executado
        system("clear");
    }else{ // Se o comando CLS existir, este será executado.
        system("cls");
    }
}

// Funcao de gear numero aleatorio
int gerarOS(){
    srand(time(NULL)); // Funcao para gerar numeros aleatórios com base na hora atual;
    int i = 0, num; // Declaração de variaveis
    while(i != 1){
        while(num <= 9999999 || num > 9999999999){ // Se o numero tiver mais de de 10 digitos ou menos de 7 a estrutura de repetição contianuará executando o processo
            for (i = 0; i <=9; i++){ // Faz uma contagem de 1 a 9.
                num *= rand() % 100; // Gera um numero aleatório onde Num recebera ele mesmo multiplicado pelo numero aleatório gerado
            }
        }
        if(num != NULL || num != 0){
            break;
        }
    }
    return num; // Retorna o valor final de num.
}

// Funcao que le as informacoes no bloco de texto.
bool leitura(char ler[70]){
    FILE *file; // Declaração da variavel file do tipo FILE.
    char frase[500]; // Declaração de variavel
    file = fopen(ler, "r"); // Tenta realizar a abertura do arquivo passado como paramentro na função
    if(file == NULL){ // Se o arquivo não existir, este retornará -1
        return false;
    }
    while(fgets(frase, 500, file) != NULL){ // enquanto houver caractere dentro do arquivo de texto, o mesmo será apresentado na tela letra após letra.
        printf("%s", frase); // Informa na tela para o usuario o resultado da busca.
    }
    fclose(file); // Fecha o arquivo de texto
    return true;
}

char cadastrar(char initcadastro[70], char nome[40], char idadeString[5], char sexo[15], char endereco[40], char cpf[16], char telcont[20]){
    FILE *file; // Declara uma variavel do tipo FILE com um ponteiro para file.
    file = fopen(initcadastro, "a"); // Abre o arquivo de texto com que fora passado como paramentro na função para que seja possivel adicionar valores.
    //Acrescentando informaçoes no arquivo de texto.
    fputs("NOME: ", file);
    fputs(nome, file);
    fputs("\n----------------------------------------------------", file);
    fputs("\nIDADE: ", file);
    fputs(idadeString, file);
    fputs("\n----------------------------------------------------", file);
    fputs("\nSEXO: ", file);
    fputs(sexo, file);
    fputs("\n----------------------------------------------------", file);
    fputs("\nENDERECO: ", file);
    fputs(endereco, file);
    fputs("\n----------------------------------------------------", file);
    fputs("\nCPF: ", file);
    fputs(cpf, file);
    fputs("\n----------------------------------------------------", file);
    fputs("\nTELEFONE DE CONTATO: ", file);
    fputs(telcont, file);
    fputs("\n----------------------------------------------------", file);
    fclose(file); // Fecha o arquivo de texto.
}

// Codigo principal
int main(void){
    system("mkdir funcionarios\\"); // Cria a pasta de funcionarios
    system("mkdir pacientes\\"); // Cria a pasta de pacientes
    system("mkdir system-admins\\logins"); // Cria a pasta de logins
    limpatela(); // Limpa a tela para o usuário
    setlocale(LC_ALL,""); // código para setar os acentos no programa
    /*O login será a sigla de 3 digitos da clinica e os 4 ultimos digitos do CPF do colaborador
    Senha provisória é o CPF do usuario até que seja realizada a devida alteração.*/
    // Variaveis globais.
    FILE *file;
    char ext[5] = ".txt", sigla[4] = "CPU", caminhologin[50] = "system-admins\\logins\\", caminhosenha[65] = "system-admins\\senhas\\";
    int idade, aux;
    bool admin, usuario;
    int cc = 0;
    while(cc != -1){
        char login[10] = "", senha[12] = "", auxlogin[34] = "", auxsenha[48] = ""; // Declaração de variavel local
        printf("LOGIN -> "); // Informa ao usuario para digitar o login
        scanf("%s", &login); // Leitura da string login
        printf("SENHA -> "); // Informa ao usuario para digitar a senha
        scanf("%s", &senha); // Leitura da string senha
        // Caoncatenação de string login
        strcat(auxlogin, caminhologin); // Adiciona o caminho da pasta de login para a variavel auxiliar do login
        strcat(auxlogin, login); // Adiciona o login na variavel auxiliar do login
        strcat(auxlogin, ".txt"); // Adiciona a extensão .txt
        // Caoncatenação de string senha
        strcat(auxsenha, caminhosenha); // Adiciona o caminho da pasta de senha para a variavel auxiliar de senha
        strcat(auxsenha, senha); // Adiciona a senha na variavel auxiliar da senha para criar um novo diretório
        strcat(auxsenha, "\\"); // Acrescenta a barra correspondente a separação de diretórios na variavel auxliar da senha
        strcat(auxsenha, senha);  // Adiciona a senha na variavel auxiliar da senha para criar um novo arquivo de senha
        strcat(auxsenha, ".txt"); // Adiciona a extensão .txt
        // Verificação de adminstração do sistema.
        if(strcmp(senha, "1234") == 0 && strcmp(login, "admin") == 0){ // Compara se o as informações digitadas são válidas, caso seja o usuario é reconhecido como admin
            admin = true;
            break;
        }else if(validarAdmin(auxlogin, auxsenha) == true){ // Verifica se o usuario é um usuario válido para liberar acesso ao uso da ferramenta
            usuario = true;
            break;
        }else{ // Se nenhum das alternativas anteriores for válida, uma mensagem de erro será exibida para o usuario.
            printf("\nUsuario ou senha inválidos. Tente novamente.\n");
        }
        if(cc == 2){ // Caso o usuario atinja 3 tentavias de login, o sistema fará autodeslog.
            printf("Numero de tentativas de login esgotadas. Tente novamente mais tarde.");
            pause();
            exit(0);
        }
        cc++; // Contador de tentativas
    }
    iniciar:
        limpatela();
        printf("**********************************************\n");
        printf("*         BEM VINDO AO MENU INICIAL!         *\n");
        printf("**********************************************\n\n");
        int resp;
        printf("[1] - Cadastros Gerais.\n\n[2] - Consultas Gerais.\n\n[3] - Reclamacoes e elogios.\n\n[4] - Relatorios.\n\n[5] - Abrir chamado para a equipe de TI");
        printf("\n\n[9] - Alterar senha de usuario.\n\n[0] - >> Sair <<\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp); // Comando de entrada responsavel por guardar a resposta na variavel "resp"
        // Bloco de escolha
        switch(resp){ // Conforme a opção do usuario, o mesmo será direcionado para uma aba especifica de sua escolha.
            case 1:
                goto cadastros; // Direcionado o usuario para o setor de cadastros
                break;
            case 2:
                goto consultas; // Direcionado o usuario para o setor de consultas
                break;
            case 3:
                goto reclamacoes; // Direcionado o usuario para o setor de reclamações
                break;
            case 4:
                goto relatorios; // Direcionado o usuario para o setor de relatórios
                break;
            case 5:
                goto tichamados; // Direcionado o usuario para o setor de abertura e consulta de chamados internos
                break;
            case 9:
                goto trocasenhausuario;
                break;
            case 0:
                printf("Saindo do sistema... Até logo!\n");
                exit(0); // Encerra o programa
                break;
            default:
                printf("\nResposta inválida!! Tente novamente.");
                pause(); // Pausa a tela para o usuario visualizar as informações
                goto iniciar; // Direcionado o usuario para a tela inicial
        }
//AREA - TELA DE CADASTROS GERAIS INCLUINDO CONSULTA DOS MESMOS
    cadastros:
        limpatela();
        printf("**********************************************\n");
        printf("*       BEM VINDO A TELA DE CADASTROS!       *\n");
        printf("**********************************************\n\n");
        printf("[1] - Cadastrar um novo funcionario.\n\n[2] - Cadastrar um novo paciente.\n\n[3] - Cadastrar um novo medico.\n\n");
        printf("[4] - Cadastro de agendamento clinico.\n\n");
        printf("[0] - Voltar ao menu principal.\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);
        // Bloco condicional
        if (resp == 1){
            char cadastroFunc[50] = "", idadeString[5] = "", cpf[15] = "", telefonecontato[15] = "", nome[40] = ""; // Declaracao de variavel local
            char sexo[10] = "", endereco[60] = "", ctps[15] = "", login[25] = "", auxlogin[25] = "", criapastasenha[60] = "mkdir system-admins\\senhas\\"; //Declaracao de variavel local;
            char senha[42] = "";
            int contador = 1, confirma; //Declaracao de variavel local
            char *eptr; //Declaracao de variavel local
            long long recebecpf, recebetel; //Declaracao de variavel local
			limpatela(); // Limpa a tela
			if (admin == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                printf("Você não possui privilégios suficientes para está função.");
                pause(); // Pausa a tela para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            // validação de idade para cadastro
            while(contador !=0){
                //Entrada de dados do usuario.
                printf("Idade: ");
                scanf("%s", &idadeString);
                idade = atoi(idadeString); // Converte uma string para um inteiro.
                if (idade < 21 || idade > 65){
                // Entrada de dados do usuario
                    printf("\nEste colaborador não possui idade que se encontre no padrão para cadastro de funcionarios!.\n");
                    pause(); // Pausa a tela para o usuario
                    printf("Para cancelar digite 0 ou pressione 1 para continuar: ");
                    scanf("%d", &confirma);
                    printf("\n");
                    if(confirma == 0){
                        goto cadastros;
                    }else{
                        continue;
                    }
                }else{
                    break;
                }
            }
            // Bloco cadastro com entrada de dados do usuario
            printf("\nNome do funcionario: ");
            scanf("%s", &nome);
            while(contador != 0){
                printf("\nSexo [0 - MASCULINO / 1 - FEMININO]: ");
                scanf("%d", &aux);
                if(aux == 1){ // Validar um sexo padrão.
                    strcat(sexo, "FEMININO");
                    break;
                }else if(aux == 0){ // Validar um sexo padrão.
                    strcat(sexo, "MASCULINO");
                    break;
                }else{ // Validar retorna um erro caso a opção escolhida não seja 1 ou 0.
                    printf("\nAlternativa inválida. Tente novamente.");
                }
            }
            while(contador != 0){
                // Validar a entrada de um CPF
                printf("\nCPF: ");
                scanf("%s", &cpf);
                recebecpf = strtoll(cpf, &eptr, 10);
                if(validaCPF(recebecpf) == false){
                    printf("\nCPF inválido. Tenve novamente.");
                }else{
                    char temp[10] = "";
                    aux = criarnumusuario(recebecpf);
                    itoa(aux, temp, 10);
                    strcat(auxlogin, sigla);
                    strcat(auxlogin, temp);
                    break;
                }
            }
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            while(contador != 0){
                // Validar a entrada de um telefone de contato
                printf("\nTelefone contato com DDD(sem espacos e sem o zero): ");
                scanf("%s", &telefonecontato);
                recebetel = strtoll(telefonecontato, &eptr, 10);
                if(validaTEL(recebetel) == false){
                    printf("\nTelefone incorreto, favor tentar novamente.");
                }else{
                    break;
                }
            }
            printf("\nID - Carteira de trabalho: ");
            scanf("%s", &ctps);

            // Revisão de informações no cadastro.
            confirmacadastro(nome,"N/A",idadeString,sexo,cpf,endereco,telefonecontato,ctps,"N/A","N/A");
            printf("\nDeseja finalizar o cadastro?[0 - NÃO / 1 - SIM]: ");
            scanf("%d", &confirma);
            if(confirma == 0){
                printf("\nCadastro cancelado.");
                pause();
                goto cadastros;
            }
            strcat(cadastroFunc, "funcionarios\\");
            strcat(cadastroFunc, cpf); // Concatena o cpf no cadastro
            strcat(cadastroFunc, ext); // Concatena o cpf com a extensão txt no cadastro;
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastroFunc, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescentando demais informacoes no cadastro.
            file = fopen(cadastroFunc, "a");
            fputs("\nCARTEIRA DE TRABALHO: ", file);
            fputs(ctps, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nTIPO: FUNCIONARIO", file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo de texto
            //CRIANDO LOGIN
            strcat(login, "system-admins\\logins\\"); // Concatenação de string caminho absoluto da pasta
            strcat(login, auxlogin); // Concatena a variavel de login
            strcat(login, ext); // Concatena a extensão .txt
            file = fopen(login, "w"); // Cria o arquivo de login
            fclose(file); // fecha o arquivo de login
            strcat(criapastasenha, cpf); // concatena o CPF ao comando de criar pastas
            strcat(criapastasenha, "\\"); // Concatena o separador de pastas padrão do windows
            system(criapastasenha); // Cria uma pasta com a senha padrão do usuario
            // CRIANDO SENHA PADRAO
            strcat(senha, "system-admins\\senhas\\");
            strcat(senha, cpf); // Concatena o CPF do usuario para a criação da pasta
            strcat(senha, "\\"); // Adiciona a barra de separação de diretorios
            strcat(senha, cpf); // Concatena o CPF para criação de senha padrão
            strcat(senha, ext); // Concatena a extensão .txt
            limpatela(); // limpa a tela do usuario
            file = fopen(senha, "w"); // Cria a senha padrão
            fclose(file); // Fecha o arquivo
            printf("\nColaborador cadastrado com sucesso!\n"); // Finaliza cadastro informando sucesso para o usuario.
            pause(); // Para a tela para que o usuario seja capaz de visualizar as informações
            goto iniciar; // Salta diretamente para a tela de inicio.
        }else if (resp == 2){
            char idadeString[5] = "", cpf[15] = "", telefonecontato[15] = "", nome[40] = ""; //Declaracao de variavel local
            char sexo[10] = "", endereco[60] = "", ctps[15] = "", nomemae[40] = "", numconvenio[25] = ""; //Declaracao de variavel local
            char cadastroPac[50] = ""; //Declaracao de variavel local
            int contador = 1, confirma; //Declaracao de variavel local
            char *eptr; //Declaracao de variavel local
            long long recebecpf, recebetel; //Declaracao de variavel local
            limpatela(); // Limpa a tela
            if (admin == false && usuario == false){
                printf("Você não possui privilégios suficientes para está função.");
                pause(); // Pausa a tela para o usuario
                goto iniciar;
			}
			//Entrada de dados do usuario.
			while(contador != 0){
                printf("Idade: ");
                scanf("%s", &idadeString);
                idade = atoi(idadeString); // Converte uma string para um inteiro.
                if(idade < 0 && idade >= 150){
                    printf("\nidade inválida. Tente novamente.\n");
                }else{
                    break;
                }
			}
            // Bloco cadastro com entrada de dados do usuario
            printf("\nNome do paciente: ");
            scanf("%s", &nome);
            printf("\nNome da mãe do paciente: ");
            scanf("%s", &nomemae);
            while(contador != 0){
                printf("\nPossui plano de saude(CONVENIO)[0 - NÃO / 1 - SIM]? ");
                scanf("%d", &aux);
                if(aux == 1){
                    printf("\nIdentifição - Cartao de convenio: ");
                    scanf("%s", &numconvenio);
                    break;
                }else if(aux == 0){
                    strcat(numconvenio, "N/A");
                    break;
                }else{
                    printf("\nAlternativa inválida. Tente novamente.");
                }
            }
            while(contador != 0){
                    // Validar um sexo padrão.
                printf("\nSexo [0 - MASCULINO / 1 - FEMININO]: ");
                scanf("%d", &aux);
                if(aux == 1){
                    strcat(sexo, "FEMININO");
                    break;
                }else if(aux == 0){
                    strcat(sexo, "MASCULINO");
                    break;
                }else{
                    printf("\nAlternativa inválida. Tente novamente.");
                }
            }
            while(contador != 0){
                // Validar a entrada de um CPF
                printf("\nCPF: ");
                scanf("%s", &cpf);
                recebecpf = strtoll(cpf, &eptr, 10);
                if(validaCPF(recebecpf) == false){
                    printf("\nCPF inválido. Tenve novamente.");
                }else{
                    break;
                }
            }
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            while(contador != 0){
                // Validar a entrada de um telefone de contato
                printf("\nTelefone contato com DDD(sem espacos e sem o zero): ");
                scanf("%s", &telefonecontato);
                recebetel = strtoll(telefonecontato, &eptr, 10);
                if(validaTEL(recebetel) == false){
                    printf("\nTelefone incorreto, favor tentar novamente.");
                }else{
                    break;
                }
            }
            // Revisão de informações no cadastro.
            confirmacadastro(nome,nomemae,idadeString,sexo,cpf,endereco,telefonecontato,ctps,"N/A",numconvenio);
            printf("\nDeseja finalizar o cadastro?[0 - NAO / 1 - SIM]: ");
            scanf("%d", &confirma);
            if(confirma == 0){
                printf("Cadastro cancelado.\n");
                pause();
                goto cadastros;
            }
            //Acrescentando demais informacoes no cadastro.
            strcat(cadastroPac, "pacientes\\");
            strcat(cadastroPac, cpf); // Concatena o cpf no cadastro
            strcat(cadastroPac, ext); // Concatena o cpf com a extensão txt no cadastro;
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastroPac, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescentando demais informacoes no cadastro.
            file = fopen(cadastroPac, "a");
            fputs("\nNOME DA MAE: ", file);
            fputs(nomemae, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nCARTAO DE CONVENIO: ", file);
            fputs(numconvenio, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nTIPO: PACIENTE", file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo
            printf("\nPaciente cadastrado com sucesso!\n"); // Fim Cadastro do paciente
            pause(); // Pausa a tela para que o usuario seja capaz de visualizar as informaçoes;
            goto iniciar; // Direciona o usuario para tela de inicio
        }else if (resp == 3){
            char idadeString[5] = "", cpf[15] = "", telefonecontato[15] = "", nome[40] = ""; //Declaracao de variavel local
            char sexo[10] = "", endereco[60] = "", ctps[15] = "", cadastromed[50] = "", diploma[20] = "", login[25] = "", auxlogin[25] = "", criapastasenha[60] = "mkdir system-admins\\senhas\\"; //Declaracao de variavel local;
            char senha[42] = "";
            int contador = 1, confirma; //Declaracao de variavel local
            char *eptr; //Declaracao de variavel local
            long long recebecpf, recebetel; //Declaracao de variavel local
			limpatela(); // Limpa a tela
			//Verificação de privilégios de admin.
			if (admin == false){
                printf("Você não possui privilégios suficientes para está função.");
                pause(); // Pausa a tela para o usuario
                goto iniciar;
			}
            // validação de idade para cadastro
            while(contador !=0){
                //Entrada de dados do usuario.
                printf("Idade: ");
                scanf("%s", &idadeString);
                idade = atoi(idadeString); // Converte uma string para um inteiro.
                if (idade < 21 || idade > 65){
                // Entrada de dados do usuario
                    printf("\nEste colaborador não possui idade que se encontre no padrão para cadastro de funcionarios!.\n");
                    pause(); // Pausa a tela para o usuario
                    printf("\nPara cancelar digite 0, para prosseguir digite 1");
                    scanf("%d", &confirma);
                    if(confirma == 0){
                        goto cadastros;
                    }else{
                        continue;
                    }
                }else{
                    break;
                }
            }
            // Bloco cadastro com entrada de dados do usuario
            printf("\nNome do funcionario: ");
            scanf("%s", &nome);
            while(contador != 0){
                    // Validar um sexo padrão.
                printf("\nSexo [0 - MASCULINO / 1 - FEMININO]: ");
                scanf("%d", &aux);
                if(aux == 1){
                    strcat(sexo, "FEMININO");
                    break;
                }else if(aux == 0){
                    strcat(sexo, "MASCULINO");
                    break;
                }else{
                    printf("\nAlternativa inválida. Tente novamente.");
                }
            }
            while(contador != 0){
                // Validar a entrada de um CPF
                printf("\nCPF: ");
                scanf("%s", &cpf);
                recebecpf = strtoll(cpf, &eptr, 10);
                if(validaCPF(recebecpf) == false){
                    printf("\nCPF inválido. Tenve novamente.");
                }else{
                    char temp[10] = "";
                    aux = criarnumusuario(recebecpf);
                    itoa(aux, temp, 10);
                    strcat(auxlogin, sigla);
                    strcat(auxlogin, temp);
                    break;
                }
            }
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            while(contador != 0){
                // Validar a entrada de um telefone de contato
                printf("\nTelefone contato com DDD(sem espacos e sem o zero): ");
                scanf("%s", &telefonecontato);
                recebetel = strtoll(telefonecontato, &eptr, 10);
                if(validaTEL(recebetel) == false){
                    printf("\nTelefone incorreto, favor tentar novamente.");
                }else{
                    break;
                }
            }
            printf("\nID - Carteira de trabalho: ");
            scanf("%s", &ctps);
            printf("\nID do certificado de medicina: ");
            scanf("%s", &diploma);
            confirmacadastro(nome, "N/A", idadeString, sexo, cpf, endereco, telefonecontato, ctps, diploma, "N/A");
            printf("\nDeseja finalizar o cadastro?[0 - NAO / 1 - SIM]: ");
            scanf("%d", &confirma);
            if(confirma == 0){
                printf("Cadastro cancelado.\n");
                pause();
                goto cadastros;
            }
            strcat(cadastromed, "funcionarios\\");
            strcat(cadastromed, cpf); // Concatena o cpf no cadastro
            strcat(cadastromed, ext); // Concatena o cpf com a extensão txt no cadastro;
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastromed, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescebtabdi demais informações
            file = fopen(cadastromed, "a");
            fputs("\nCARTEIRA DE TRABALHO: ", file);
            fputs(ctps, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nCERTIFICACAO DIPLOMA MEDICO: ", file);
            fputs(diploma, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nTIPO: MEDICO", file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo
            //CRIANDO LOGIN
            strcat(login, "system-admins\\logins\\"); // Concatenação de string caminho absoluto da pasta
            strcat(login, auxlogin); // Concatena a variavel de login
            strcat(login, ext); // Concatena a extensão .txt
            file = fopen(login, "w"); // Cria o arquivo de login
            fclose(file); // fecha o arquivo de login
            strcat(criapastasenha, cpf); // concatena o CPF ao comando de criar pastas
            strcat(criapastasenha, "\\"); // Concatena o separador de pastas padrão do windows
            system(criapastasenha); // Cria uma pasta com a senha padrão do usuario
            // CRIANDO SENHA PADRAO
            strcat(senha, "system-admins\\senhas\\");
            strcat(senha, cpf); // Concatena o CPF do usuario para a criação da pasta
            strcat(senha, "\\"); // Adiciona a barra de separação de diretorios
            strcat(senha, cpf); // Concatena o CPF para criação de senha padrão
            strcat(senha, ext); // Concatena a extensão .txt
            limpatela(); // limpa a tela do usuario
            file = fopen(senha, "w"); // Cria a senha padrão
            fclose(file); // Fecha o arquivo
            printf("\nMedico cadastrado com sucesso!\n"); // Fim do cadastro médico
            pause(); // Pausa a tela para que o usuario visualize as informações.
            goto cadastros; // Direciona o usuario para a tela de cadastros.
        }else if (resp == 4){
            limpatela(); // Limpa a tela
            char data[15] = "", nome[40] = "", hora[15] = "", cadastroOS[50] = "", verificapaciente[50] = "", os[15] = "", auxiliarOS[50] = ""; // Declarando variaveis locais
            char cpf[15] = "";
            int numos; // Declarando variavel local
            system("mkdir pacientes\\");
            strcat(verificapaciente, "pacientes\\");
            limpatela(); // Limpa a tela
            // Entrada de dados do usuario
            printf("\nCPF do paciente: ");
            scanf("%s", &cpf);
            strcat(verificapaciente, cpf); // Concatena o cpf no cadastro
            strcat(verificapaciente, ext); // Concatena o cpf com a extensão txt no cadastro;
            // Valida se o paciente já está cadastrado no sistema.
            if (file = fopen(verificapaciente, "r")){
                fclose(file);
                system("mkdir agendamentos\\concluidos\\");
                limpatela(); // Limpa a tela
                printf("\n");
            }else{
                printf("Paciente ainda nao cadastrado! Favor realizar o cadastro primeiramente.\n");
                pause();
                goto cadastros;
            }
            printf("Nome do paciente: ");
            scanf("%s", &nome);
            printf("\nData do agendamento(formato DD.MM.AA): ");
            scanf("%s", &data);
            printf("\nHora do agendamento(formato hh:mm:ss): ");
            scanf("%s", &hora);
            printf("\nGerando ordem de serviço... ");
            numos = gerarOS();
            printf("Numero da OS: %d\n", numos); // Informa ao usuario o numero gerado
            srand(time(NULL)); // Funcao auxiliar para gerar numeros aleatórios.
            itoa(numos, os, 10); // Converte inteiro para string
            //Concatenacao de strings
            strcat(cadastroOS, "agendamentos\\");
            strcat(cadastroOS, os);
            strcat(cadastroOS, ext);
            strcat(auxiliarOS, "agendamentos\\concluidos\\");
            strcat(auxiliarOS, os);
            strcat(auxiliarOS, ext);
            file = fopen(cadastroOS, "a"); // Abre o arquivo de texto.
            fputs("\nNome do paciente: ", file);
            fputs(nome, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nCPF DO PACIENTE: ", file);
            fputs(cpf, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nHORARIO DO AGENDAMENTO: ", file);
            fputs(data, file);
            fputs(" - ", file);
            fputs(hora, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nORDEM DE SERVICO: ", file);
            fputs(os, file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo de texto
            //Abre arquivo de texto auxiliar.
            file = fopen(auxiliarOS, "a");
            fputs("Nome do paciente: ", file);
            fputs(nome, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nCPF DO PACIENTE: ", file);
            fputs(cpf, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nHORARIO DO AGENDAMENTO: ", file);
            fputs(data, file);
            fputs(" - ", file);
            fputs(hora, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nORDEM DE SERVICO: ", file);
            fputs(os, file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo de texto
            printf("\nAgendamento concluido com sucesso!\n");
            pause(); // Pausa a tela para o usuario conseguir visualizar as informações.
            goto iniciar; // Direciona o usuario para a tela de inicio.
        }else if (resp == 0){
            goto iniciar;
        }else{
            goto cadastros;
        }
// TELA DE CONSULTAS GERAIS
    consultas:
        limpatela(); // Limpa a tela
        printf("**********************************************\n");
        printf("*       BEM VINDO A AREA DE CONSULTAS!       *\n");
        printf("**********************************************\n\n");
        printf("[1] - Consultar ficha de um colaborador [medico | funcionario].\n\n[2] - Consultar ficha do paciente.\n\n");
        printf("[3] - Consultar agendamentos pendentes.\n\n[4] - Consultar historico de agendamentos.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);
        // Bloco Condicional
        if (resp == 1){
            limpatela(); // limpa a tela
            if (admin == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                printf("Você não possui privilégios suficientes para está função.");
                pause(); // Pausa a tela para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            char consultaficha[50] = "", cpf[12] = ""; //Declaração de variavel local
            // Entrada de dados do usuario
            printf("CPF a ser consultado: ");
            scanf("%s", &cpf);
            printf("\n");
            //Concatenação da string com a extensão txt
            strcat(consultaficha, "funcionarios\\");
            strcat(consultaficha, cpf);
            strcat(consultaficha, ext);
            leitura(consultaficha);
            pause(); // Pausa a tela para o usuario.
            goto consultas; // Direciona o usuario ao menu de consulta.
        }else if (resp == 2){
            limpatela(); // limpa a tela
            char consultaPac[50] = "", frase[500] = "", cpf[12] = ""; //Declaração de variavel local
            // Entrada de dados
            printf("CPF a ser consultado: ");
            scanf("%s", &cpf);
            printf("\n");
            //Concatenação da string com a extensão txt
            strcat(consultaPac, "pacientes\\");
            strcat(consultaPac, cpf);
            strcat(consultaPac, ext);
            file = fopen(consultaPac, "r");
            if(file == NULL){
                printf("Cadastro nao localizado!\n");
                pause(); // Pausa a tela para o usuario.
                goto consultas; // Direciona ao menu de consultas
            }//Processo de leitura do arquivo que imprime na tela caractere por carectere
            while(fgets(frase, 500, file) != NULL){
                printf("%s", frase);
            }
            fclose(file);
            pause(); // Pausa a tela para o usuario conseguir absorver as informaçoes
            goto iniciar;
        }else if (resp == 3){
            limpatela();
            // Declaracao da variavel local;
            char consultarOS[50] = "", digitoOS[25] = "", baixaOS[40] = "", resultadobusca;
            //Entrada de dados do usuario
            printf("Digite o numero da OS do agendamento clinico: ");
            scanf("%s", &digitoOS);
            //Concatenacao de strings
            strcat(consultarOS, "agendamentos\\");
            strcat(consultarOS, digitoOS);
            strcat(consultarOS, ext);
            resultadobusca = leitura(consultarOS);
            // Condicao de verificacao
            if(resultadobusca == false){
                printf("\nEsta ordem de servico não foi localizada. Verifique no histórico de angendamentos.\n");
                pause(); // Pausa a tela para o usuario
                goto consultas; // Direciona o usuario ao menu de consultas
            }else if(resultadobusca == true){
                printf("\nDeseja dar baixa no agendamento? [0 - para NAO / 1 - para SIM]: ");
                scanf("%d", &resp);
                if (resp == 1){
                    //Arquivo movido para pasta de conclusão final
                    strcat(baixaOS, "agendamentos\\concluidos\\");
                    strcat(baixaOS, digitoOS);
                    strcat(baixaOS, ext);
                    file = fopen(baixaOS, "a");
                    fputs("\nSTATUS: CONCLUIDO!", file);
                    fputs("\n----------------------------------------------------", file);
                    fclose(file);
                    remove(consultarOS);
                }
                goto consultas; // Salta para a tela de consultas
            }
            goto consultas; // Salta para a tela de consultas
        }else if (resp == 4){
            limpatela();
            // Declaracao da variavel;
            char consultarOS[50] = "", digitoOS[25] = "", verificaPendencia[50] = "agendamentos\\";
            //Entrada de dados do usuario
            printf("Digite o numero da OS do agendamento clinico para buscar no histórico: ");
            scanf("%s", &digitoOS);
            printf("\n");
            //Concatenacao de informacoes
            strcat(consultarOS, "agendamentos\\concluidos\\");
            strcat(consultarOS, digitoOS);
            strcat(consultarOS, ext);
            strcat(verificaPendencia, digitoOS);
            strcat(verificaPendencia, ext);
            FILE *verif; // Declaração de variavel do tipo FILE
            verif = fopen(verificaPendencia, "r"); // Verifica se o arquivo exsiste na pasta indicada.
            if(verif == NULL){
                leitura(consultarOS); // Faz a leitura dos arquivos na pasta indicada
                pause(); // Pausa a tela para o usuario visualizar as informacoes;
                goto consultas; // Direciona o usuario ao menu de consultas
            }
            fclose(verif); // fecha o arquivo de texto
            printf("Esta OS de agendamento não existe ou pode estar pendente de tratamento. Favor verificar agendamentos pendentes.");
            pause(); // Pausa a tela para o usuario verificar as informacoes
            goto consultas; // Salta para a tela de consultas
        }else if (resp == 0){
            goto iniciar; // Direciona o usuario para o menu inicial
        }else{
            goto consultas; // Salta para a tela de consultas
        }

//TELA - AREA DE RECLAMACOES E SUGESTOES
    reclamacoes:
        limpatela();
        printf("**********************************************\n");
        printf("*       BEM VINDO A AREA DE SUGESTOES!       *\n");
        printf(" **********************************************\n\n");
        printf("[1] - Registrar uma reclamacao/Sugestao/Elogio.\n\n[2] - Consultar uma reclamacao/Sugestao/Elogio.\n\n");
        printf("[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        // Bloco condicional
        if (resp == 1){
            char resenha[255], categoria[15];
            printf("Para prosseguir informe a categoria.\n");
            printf("Sugestao/Elogio/Critica: ");
            scanf("%s", &categoria);
            printf("%s: ",categoria);
            scanf("%s", &resenha);

            strcat(categoria, ext); // Concatena a extensao com o nome do arquivo.
            file = fopen(categoria, "a"); // Abre o arquivo de texto.

            // Acrescentando informacoes ao bloco de texto.
            fputs("CATEGORIA: ", file);
            fputs(categoria, file);
            fputs("\n----------------------------------------------------", file);
            fputs("RESENHA: ", file);
            fputs(resenha, file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo de texto
            printf("%s registrada com sucesso!\n", categoria);

            pause(); // Pausa o sistem para que o osuario visualize as informacoes
            goto reclamacoes; // Direciona o usuario para o setor de reclamacoes

        }else if (resp == 2){

        }else if (resp == 0){
            goto iniciar;
        }else{
            goto reclamacoes;
        }

//TELA - ABA DE RELATORIOS
    relatorios:
        limpatela();
        printf("**********************************************\n");
        printf("*      BEM VINDO A AREA DE RELATORIOS!       *\n");
        printf("**********************************************\n\n");
        printf("[1] - Gerar relatorio de consultas do dia.\n\n[2] - Gerar relatiorio de vendas do dia.\n\n[3] - Gerar relatorio folha ponto do dia.\n\n");
        printf("[4] - Gerar todos os relatorios.\n\n[5] - Exportar relatorio mensal para uma planilha eletronica.\n\n[6] - Consultar relatorio(s) em tela.");
        printf("\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        //Bloco condicional
        if (resp == 1){

        }else if (resp == 2){

        }else if (resp == 3){

        }else if (resp == 4){

        }else if (resp == 5){

        }else if (resp == 6){

        }else if (resp == 0){
            goto iniciar;
        }else{
            goto relatorios;
        }
    tichamados:
        limpatela();
        printf("**********************************************\n");
        printf("*    BEM VINDO A AREA CHAMADOS INTERNOS!     *\n");
        printf("**********************************************\n\n");
        printf("[1] - Registrar um novo chamado.\n\n[2] - Consultar um chamado existente.\n\n[3] - Cancelar um chamado existente.\n\n");
        printf("[4] - Reabrir chamado encerrado indevidamente.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        // Declaração de variavel local
        int tipofalha;
		char sistemaafetado[35], resumofalha[255], localfalha[30], resplocal;

		// Bloco condicional
        limpatela();
        if (resp == 1){
            printf("\n[1] - Falha Sistemica. [2] Falha na infra da empresa.\n\n");
            printf("Resposta -> ");
            scanf("%d", &tipofalha);
            if (tipofalha == 1){
                printf("\nSistema afetado: ");
                scanf("%s", &sistemaafetado);
				printf("Resumo da falha(max 100 caracteres): ");
				scanf("%s", &resumofalha);
				printf("\nGerando protocolo do chamado...");
				printf("");
				goto tichamados; // Salta para a tela de chamados.
            }else if(tipofalha == 2){
				printf("\nLocal da falha: ");
				scanf("%s", &localfalha);
				printf("\nAfetou algum sistema? [S/N]: ");
				scanf("%s", &resplocal);
				if (resplocal == 's' || resplocal == 'S'){
					printf("Sistema afetado: ");
					scanf("%s", &sistemaafetado);
				}
				printf("Gerando protocolo do chamado..");
				printf("");
				goto tichamados;
            }else{
                printf("\nTipo de falha nao localizado ou inexistente. Tente novamente.\n");
                goto tichamados;
            }
        }else if (resp == 2){

        }else{
            printf("\nOpcao inexistente.\n");
            goto tichamados;
        }
        //Alteração da senha
        trocasenhausuario:
            char senha[16], auxsenha[42] = "", novasenha[16] = "", novasenha1[16] = "", auxnovasenha[38] = "", login[9] = "", auxlogin[34] = "";
            char criarcaminhonovasenha[62] = "", deletarsenhaantiga[62] = "";
            FILE *trocasenha;
            int errata, contador = 1;
            limpatela();
            while(contador != 0){
                printf("\nDigite o user login: ");
                scanf("%s", &login);
                printf("\nPara continuar digite sua senha atual: ");
                scanf("%s", &senha);
                strcat(auxsenha, caminhosenha);
                strcat(auxsenha, senha);
                strcat(auxsenha, "\\");
                strcat(auxsenha, senha);
                strcat(auxsenha, ".txt");
                strcat(auxlogin, caminhologin);
                strcat(auxlogin, login);
                strcat(auxlogin, ".txt");
                if(validarAdmin(auxlogin, auxsenha) == true){
                    printf("\nDigite a nova senha: ");
                    scanf("%s", &novasenha);
                    printf("\nConfirme a nova senha: ");
                    scanf("%s", &novasenha1);
                    if(strcmp(novasenha, novasenha1) == 0){
                        strcat(criarcaminhonovasenha, "mkdir system-admins\\senhas\\");
                        strcat(criarcaminhonovasenha, novasenha);
                        strcat(criarcaminhonovasenha, "\\");
                        strcat(criarcaminhonovasenha, novasenha);
                        system(criarcaminhonovasenha);
                        strcat(auxnovasenha, "system-admins\\senhas\\");
                        strcat(auxnovasenha, novasenha);
                        strcat(auxnovasenha, "\\");
                        strcat(auxnovasenha, novasenha);
                        strcat(auxnovasenha, ext);
                        trocasenha = fopen(auxnovasenha, "w");
                        fclose(trocasenha);
                        remove(auxsenha);
                        printf("\nSenha alterada com sucesso!");
                        pause();
                        goto iniciar;
                        break;
                    }else{
                        printf("\nA senha digitada é diferente da confirmação de senha. Processo interrompido!");
                        pause();
                        goto iniciar;
                    }
                }else{
                    printf("\nUsuario ou senha não confere.");
                }
                printf("\nDeseja cancelar a operação? [0 - NAO / 1 - SIM]: ");
                scanf("%d", &errata);
                if(errata == 0){
                    printf("Procedimento cancelado pelo usuário.");
                    pause();
                    break;
                }
            }
            goto iniciar;
}
