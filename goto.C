#include <stdio.h> // Biblioteca para usar os comandos de entrada e saida
#include <stdlib.h> // Biblioteca padrão e possui a função de (alocação de memoria), controle de processos, conversões e outras.
#include <string.h> // Biblioteca para utilizar e manipular strings
#include <time.h> // Biblioteca de datas e horários
#include <stdbool.h> // Biblioteca para utilizar retornos booleanos
#include <locale.h> // Biblioteca para usar a linguagem local incluindo acentos.
#include <windows.h> // Biblioteca para usar funcionalidades especificas do windows
#include <conio.h>
#include <ctype.h>

// Função que fará a concatenação das informaçõs e adicionara no bloco de notas para a criação de uma OS.
void concatena_string(char tipasta[35], char titratados[45], char OS[15], char categoria[25], char id[7], char informe[25], char detalhar[255]);
//Funcao para incluir a data e hora nas solicitações / agendamentos
void incluirdatahora(char cm[50]);
//Funcao para limpar o buffer do teclado
void lb(void);
// Função para realizar a leitura de uma senha.
char** lersenha(char senha[9]);
// Funcao cria senha e login padrao
void createloginsenha(char creatediretlogin[50], char creatediretsenha[50],char loginass[60], char cpf[12]);
// Funcao para apresentar uma linha formatada
void lform();
// funcao para Validar usuario admin
bool validarAdmin(char login[11], char senha[16]);
// funcao para Criar login do usuario
int criarnumusuario(long long num);
// Funcao para confirmação de cadastro
void confirmacadastro(char nomePs[35], char nomeMa[35], char idade[3], char sex[10], char cpf[12], char endereco[35], char telcont[12], char ctps[12], char dipl[10], char convenio[12]);
// Funcao para validar um TELEFONE de contato
bool validaTEL(long long valor);
// Funcao para validar um CPF
bool validaCPF(long long cpf_entrada);
// Funcao de pausar a tela
void pause();
// Funcao de limpar tela
void limpatela();
// Funcao de gear numero aleatorio
int gerarOS();
// Funcao que le as informacoes no bloco de texto.
bool leitura(char ler[70]);
// Funcao para cadastro de informacos basicas do usuario/paciente
char cadastrar(char initcadastro[70], char nome[40], char idadeString[5], char sexo[15], char endereco[40], char cpf[16], char telcont[20]);

int main(void){
    system("mode 15,1 && color 15"); // Muda o tamanho do terminal para 15 colunas e 1 linha e a cor para fundo azul e letras roxas
    system("msg * AGUARDE! INICIALIZANDO TAREFAS..."); // Mostra uma POP-UP com uma mensagem para o usuario.
    system("mkdir sugerir-reclamar-elogiar\\ELOGIO\\");
    system("mkdir sugerir-reclamar-elogiar\\RECLAMACAO\\");
    system("mkdir sugerir-reclamar-elogiar\\SUGESTAO\\ & attrib +h sugerir-reclamar-elogiar");
    system("mkdir funcionarios\\ & attrib +h funcionarios"); // Cria a pasta de funcionarios
    system("mkdir pacientes\\ & attrib +h pacientes"); // Cria a pasta de pacientes
    system("mkdir system-moderadores\\logins\\ & attrib +h system-moderadores"); // Cria a pasta de logins para moderadores do sistema
    system("mkdir agendamentos\\concluidos\\ & attrib +h agendamentos"); // Cria a pasta de agendamentos e agendamentos concluidos
    system("mkdir ti-sistemas\\tratados\\ & attrib +h ti-sistemas"); // Cria a pasta de ti e sistemas
    system("mkdir relatorios\\ & attrib +h relatorios"); // Cria a pasta de relatorios
    moduser: // ponto de salto para modificar o usuario / trocar login
    system("mode 30,6 && color 07"); // Seta o tamanho do terminal para 30 colunas e 6 linhas e a cor do terminal para o padrão
    struct tm *dataloc; //ponteiro para struct que armazena data e hora
    time_t segundos; //variável do tipo time_t para armazenar o tempo em segundos
    time(&segundos); //obtendo o tempo em segundos
    dataloc = localtime(&segundos); //Para converter de segundos para o tempo local utilizamos a função localtime
    time(&segundos); //obtendo o tempo em segundos
    dataloc = localtime(&segundos);
    limpatela(); // Limpa a tela para o usuário
    setlocale(LC_ALL,""); // código para setar os acentos no programa
    /*O login será a sigla de 2 digitos da clinica e os 4 ultimos digitos do CPF do colaborador
    Senha provisória é o CPF do usuario até que seja realizada a devida alteração.*/
    //Variaveis globais de login
    bool admin = false, moderador = false;//, usuario = false; // declaracao de variavel global
    char identificacao_menu[7] = "", caminhologin[65] = "system-moderadores\\logins\\", caminhosenha[75] = "system-moderadores\\logins\\"; // Declaração de variavel global
    int cc = 0;
    while(cc != -1){ // Entrará em um loop infinito até que uma das opções de login sejam atendidas.
        char login[7] ,log[7] = "", auxlog[60] = "", auxsen[60] = "", senha[9] = ""; // Declaração de variavel local
        printf("\n    LOGIN -> "); // Informa ao usuario para digitar o login
        scanf("%s", &log); // Leitura da string login temporaria
        printf("  --------------------------"); // Separador
        printf("\n    SENHA -> "); // Informa ao usuario para digitar a senha
        strcpy(login, log); // copia os dados da variavel de login temporaria para a variavel de login
        lersenha(senha); // Faz a leitura da senha
        lb(); // Limpa o buffer do teclado.
        strcat(auxlog, caminhologin); // Adiciona o caminho da pasta de login para a variavel auxiliar do login
        strcat(auxlog, login); // Adiciona o login na variavel auxiliar do login
        strcat(auxlog, "\\"); // Adiciona o login na variavel auxiliar do login
        strcat(auxlog, login); // Adiciona o login na variavel auxiliar do login
        strcat(auxlog, ".txt"); // Adiciona a extensão .txt
        // Concatenação de string senha
        strcat(auxsen, caminhosenha); // Adiciona o caminho da pasta de senha para a variavel auxiliar de senha
        strcat(auxsen, login); // Adiciona a senha na variavel auxiliar da senha para criar um novo diretório
        strcat(auxsen, "\\"); // Acrescenta a barra correspondente a separação de diretórios na variavel auxliar da senha
        strcat(auxsen, senha);  // Adiciona a senha na variavel auxiliar da senha para criar um novo arquivo de senha
        strcat(auxsen, "\\"); // Acrescenta a barra correspondente a separação de diretórios na variavel auxliar da senha
        strcat(auxsen, senha);  // Adiciona a senha na variavel auxiliar da senha para criar um novo arquivo de senha
        strcat(auxsen, ".txt"); // Adiciona a extensão .txt
        // Verificação de adminstração do sistema.
        if(strcmp(senha, "1234") == 0 && (strcmp(login, "ADMIN") == 0 || strcmp(login, "admin") == 0)){ // Compara se o as informações digitadas são válidas, caso seja o usuario é reconhecido como admin
            admin = true; // Atribuição de valor booleano verdadeiro a variavel admin
            strcat(identificacao_menu, login); // Concatena o login para mostar no menu inicial
            break; // Encerra o looping
        }else if(validarAdmin(auxlog, auxsen) == true){ // Verifica se o usuario é um usuario válido para liberar acesso ao uso da ferramenta
            moderador = true; // Atribuição de valor booleano verdadeiro a variavel usuario
            strcat(identificacao_menu, login); // Concatena o login para mostar no menu inicial
            break; // Encerra o looping
        }else{ // Se nenhum das alternativas anteriores for válida, uma mensagem de erro será exibida para o usuario.
            system("msg * USUARIO OU SENHA INVALIDOS. TENTE NOVAMENTE!"); // Apresenta uma POP UP com uma mensagem para o usuario
            limpatela();
        }
        if(cc == 2){ // Caso o usuario atinja 3 tentavias de login, o sistema fará autodeslog.
            system("msg * NUMERO DE TENTATIVAS ESGOTADAS. SAINDO DO SISTEMA..."); // Apresenta uma POP UP com uma mensagem para o usuario
            exit(0); // Encerra o programa
        }
        cc++; // Contador de tentativas
    }
    iniciar: // Ponto de salto do GOTO
        limpatela(); // Limpa a tela do usuario
        // DECLARACAO DE VARIAVEIS GLOBAIS PARA USO GERAL
        FILE *file; // Declaracao de variavel do tipo FILE
        int contador = 1, confirma, idade, aux, os, numos; //Declaracao de variavel GLOBAL do tipo inteiro
        // DECLARAÇÃO DE VARIAVEIS GLOBAIS DO TIPO CHAR
        char ext[5] = ".txt", sigla[3] = "CT", sg[3] = "", rlos[15] = "", consultarOS[50] = "", digitoOS[25] = "", auxiliarOS[53] = "", OS[15] = "";
        char cadastro[55] = "", telefonecontato[15] = "", resultadobusca, numconvenio[11] = "", categoria[11] = "", resenha[255] = "";
        char sexo[10] = "", endereco[60] = "", ctps[11] = "", idadeString[3] = "", cpf[12] = "", nome[40] = "", data[11] = "", hora[9] = "";
        char login[60] = "", senha[60] = "", auxsenha[60] = "", auxlogin[60] = "", cadastroOS[53] = "", consultaficha[50] = "", baixaOS[40] = "";
        char criapastalogin[50] = "mkdir system-moderadores\\logins\\", criapastasenha[50] = "mkdir system-moderadores\\logins\\", caminho_recl_sugs_elo[62] = "sugerir-reclamar-elogiar\\";
        char *eptr; //Declaracao de variavel ponteiro tipo char
        //
        long long recebecpf, recebetel; //Declaracao de variavel long long(inteiro)
        system("mode 122,62");
        char resp[3] = ""; // Declaração de variavel local
        printf("\n                                                 ***********************              SÃO [ %d:%d ] HOJE É [%d/%d/%d]\n",dataloc->tm_hour, dataloc->tm_min, dataloc->tm_mday, dataloc->tm_mon+1, dataloc->tm_year+1900);
        printf("  _______________________________________________*                     *________________________________________________\n");
        printf("  _______________________________________________>    ABA PRINCIPAL    <________________________________________________\n");
        printf("                                                 *                     *                                                \n");
        printf("                                                 ***********************                                                \n");
        printf("\n                     ******************************************************************************                   \n");
        printf("                     *                                                                            *           LOG ON    \n");
        printf("                     *            -- BEM VINDO A CENTRAL DE GERENCIAMENTO INTERNO --              *        ____________ \n");
        printf("                     *                                                                            *                     \n");
        printf("                     ******************************************************************************         [ %s ]  \n\n", identificacao_menu);
        printf("  ______________________________________________________________________________________________________________________\n\n");
        printf("                     PARA PROSSEGUIR DIGITE A SIGLA DE 2 DIGITOS CORRESPONDENTE A SUA SOLICITACAO                       \n");
        printf("  ______________________________________________________________________________________________________________________\n\n");
        printf("  **********************************************************************************************************************\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A1 - CADASTRAR UM NOVO FUNCIONARIO                            AD - CONSULTAR UM CHAMADO INTERNO EM HISTORICO - TI  *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A2 - CADASTRAR UM NOVO MEDICO                                 AE - GERAR RELATORIO DE DESEMPENHO DIARIO NA TELA    *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A3 - CADASTRAR UM NOVO PACIENTE                               AF - EXPORTAR RELATORIO DE DESEMPENHO PARA O EXCEL   *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A4 - CADASTAR UMA ORDEM DE AGENDAMENTO                                                                             *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A5 - CONSULTAR O CADASTRO DE UM MEDICO/FUNCIONARIO                                                                 *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A6 - CONSULTAR O CADASTRO DE UM PACIENTE                                                                           *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A7 - CONSULTAR UM AGENDAMENTO PENDENTE                                                                             *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A8 - CONSULTAR AGENDAMENTO EM HISTORICO                                                                            *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * A9 - REGISTRAR RECLAMACAO/SUGESTAO/ELOGIO                                                                          *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * AA - CONSULTAR RECLAMACAO/SUGESTAO/ELOGIO                     B1 - LOGAR COM UM NOVO USUARIO                       *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * AB - REGISTRAR UM CHAMADO INTERNO - TI                        B0 - TROCAR SENHA DE USUARIO                         *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  * AC - CONSULTAR UM CHAMADO INTERNO - TI                        A0 - PARA SAIR DO SISTEMA ->                 [SAIDA] *\n");
        printf("  * ------------------------------------------------------------------------------------------------------------------ *\n");
        printf("  **********************************************************************************************************************\n\n");
        printf("  RESPOSTA --> ");
        scanf("%s", &resp);
        lb(); // Limpa o buffer do teclado
        if(strcmp(resp, "A1") == 0 || strcmp(resp, "a1") == 0){
			limpatela(); // Limpa a tela
			printf("\n ************************************************************************************************************************");
			printf("\n *                                           CADASTRO DE FUNCIONARIO                                                    *");
			printf("\n ************************************************************************************************************************\n\n");
			if (admin == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system(" msg * VOCE NAO POSSUI PRIVILEGIOS DE ADMINSTRADOR PARA EXECUTAR ESTA FUNCAO.");
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            // validação de idade para cadastro
            while(contador !=0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                //Entrada de dados do usuario.
                printf("\n   ENTRE COM A IDADE DO COLABORADOR....................................: ");
                scanf("%s", &idadeString);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                idade = atoi(idadeString); // Converte uma string para um inteiro.
                if (idade < 21 || idade > 65){
                // Entrada de dados do usuario
                    printf("\n   ESTE COLABORADOR NAO POSSUI IDADE QUE SE ENCONTRE NO PADRAO DE CADASTRO DE FUNCIONARIOS!\n");
                    lform(); // Linha formatada
                    pause(); // Pausa a tela para o usuario
                    lform(); // Linha formatada
                    printf("\n   PARA CANCELAR DIGITE 0 OU 1 PARA CONTINUAR: ");
                    scanf("%d", &confirma);
                    lb(); // Limpa o buffer do teclado
                    lform(); // Linha formatada
                    if(confirma == 0){
                        goto iniciar; // Direciona o usuario para o menu iniciar
                    }else{
                        continue;
                    }
                }else{
                    break; // Encerra o looping
                }
            }
            // Bloco cadastro com entrada de dados do usuario
            printf("\n   ENTRE COM O NOME DO COLABORADOR.....................................: ");
            scanf("%[^\n]", &nome); // Faz a leitura da string
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
               printf("\n   ESCOLHA O SEXO DO COLABORADOR [0 - MASCULINO / 1 - FEMININO]........: ");
                scanf("%d", &aux);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                if(aux == 1){ // Validar um sexo padrão.
                    strcat(sexo, "FEMININO");
                    break; // Encerra o looping
                }else if(aux == 0){ // Validar um sexo padrão.
                    strcat(sexo, "MASCULINO");
                    break; // Encerra o looping
                }else{ // Validar retorna um erro caso a opção escolhida não seja 1 ou 0.
                    printf("\n   ALTERNATIVA INVALIDA. TENTE NOVAMENTE!\n");
                    lform(); // Linha formatada
                }
            }
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                // Validar a entrada de um CPF
                printf("\n   ENTRE COM O CPF DO COLABORADOR......................................: ");
                scanf("%s", &cpf);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                recebecpf = strtoll(cpf, &eptr, 10);
                if(validaCPF(recebecpf) == false){
                    printf("\n   CPF INVALIDO. TENTE NOVAMENTE!\n");
                    lform(); // Linha formatada
                }else{ // Se o CPF for válido será declarada uma variavel temporaria para receber um determinado valor
                    char temp[10] = ""; // Declaração de variavel temporaria
                    aux = criarnumusuario(recebecpf); // a variavel auxiliar recebera o numero de usuario de acordo com o CPF digitado
                    itoa(aux, temp, 10); // Converte o valor inteiro para string
                    strcat(auxlogin, sigla); // Concatena a sigla da empresa a variavel de login
                    strcat(auxlogin, temp); // Concatena o valor da variavel temporaria para criar um login de usuario
                    break; // encerra o looping
                }
            }
            printf("\n   DIGITE O ENDERECO DE LOCALIZACAO DO COLABORADOR.....................: ");
            scanf("%[^\n]", &endereco);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                // Validar a entrada de um telefone de contato
                printf("\n   INFORME O TELEFONE DE CONTATO COM O DDD(SEM ESPACOS E SEM O ZERO)...: ");
                scanf("%s", &telefonecontato);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                recebetel = strtoll(telefonecontato, &eptr, 10);
                if(validaTEL(recebetel) == false){
                    printf("\n    TELEFONE INCORRETO, FAVOR TENTAR NOVAMENTE!\n");
                    lform(); // Linha formatada
                }else{
                    break; // Encerra o looping
                }
            }
            printf("\n   INFORME O ID - CARTEIRA DE TRABALHO.................................: ");
            scanf("%s", &ctps);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            // Revisão de informações no cadastro.
            confirmacadastro(nome,"N/A",idadeString,sexo,cpf,endereco,telefonecontato,ctps,"N/A","N/A");
            printf("\n   DESEJA FINALIZAR O CADASTRO DO COLABORADOR? [0 - NÃO / 1 - SIM].....: ");
            scanf("%d", &confirma);
            lform(); // Linha formatada
            if(confirma == 0){
                system("msg * CADASTRO CANCELADO PELO USUARIO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial.
            }
            strcat(cadastro, "funcionarios\\"); // Concatena o caminho da pasta de funcionarios no cadastro de funcionario
            strcat(cadastro, cpf); // Concatena o cpf no cadastro
            strcat(cadastro, ext); // Concatena o cpf com a extensão txt no cadastro;
            file = fopen(cadastro, "r"); // Abre um arquivo de texto em modo leitura
            if(file != NULL){ // Verifica se o colaborador já está cadastrado.
                system("msg * COLABORADOR JA CADASTRADO NO BANCO DE FUNCIONARIOS INTERNOS. CADASTRO CANCELADO PELO SISTEMA!"); // Apresenta uma POP UP com uma mensagem para o usuario
                fclose(file); // Fecha o arquivo de texto caso tenha sido aberto.
                goto iniciar; // Direciona o usuario para a tela inicial.
            }
            fclose(file);// Fecha o arquivo de texto aberto.
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastro, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescentando demais informacoes no cadastro.
            file = fopen(cadastro, "a");
            fputs("\n      CARTEIRA DE TRABALHO.............: ", file);
            fputs(ctps, file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fputs("\n      TIPO.............................: FUNCIONARIO", file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fclose(file); // Fecha o arquivo de texto
            createloginsenha(criapastalogin, criapastasenha, auxlogin, cpf);
            system("msg * COLABORADOR CADASTRADO COM SUCESSO!"); // Apresenta uma POP UP com uma mensagem para o usuario
            goto iniciar; // Direciona o usuario para a tela inicial.
        }else if(strcmp(resp, "A2") == 0 || strcmp(resp, "a2") == 0){
			limpatela(); // Limpa a tela
			char diploma[20] = "";
			if (admin == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system(" msg * VOCE NAO POSSUI PRIVILEGIOS DE ADMINSTRADOR PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
			printf("\n ************************************************************************************************************************");
			printf("\n *                                             CADASTRO DE MEDICOS                                                      *");
			printf("\n ************************************************************************************************************************\n\n");
            // validação de idade para cadastro
            while(contador !=0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                //Entrada de dados do usuario.
                printf("\n   ENTRE COM A IDADE DO COLABORADOR....................................: ");
                scanf("%s", &idadeString);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                idade = atoi(idadeString); // Converte uma string para um inteiro.
                if (idade < 21 || idade > 65){
                // Entrada de dados do usuario
                    printf("\n   ESTE COLABORADOR NAO POSSUI IDADE QUE SE ENCONTRE NO PADRAO DE CADASTRO DE FUNCIONARIOS!\n");
                    lform(); // Linha formatada
                    pause(); // Pausa a tela para o usuario
                    lform(); // Linha formatada
                    printf("\n   PARA CANCELAR DIGITE 0 OU 1 PARA CONTINUAR: ");
                    scanf("%d", &confirma);
                    lform(); // Linha formatada
                    if(confirma == 0){
                        goto iniciar; // Direciona o usuario para o menu iniciar
                    }else{ // Se a condição do if for diferente de 0 continuará a aplicação normamente.
                        continue;
                    }
                }else{ // Se o colaborador tiver idade entre 21 e 65, o looping será interrompido
                    break; // Interrompe um looping
                }
            }
            // Bloco cadastro com entrada de dados do usuario
            printf("\n   ENTRE COM O NOME DO COLABORADOR.....................................: ");
            scanf("%[^\n]", &nome);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
               printf("\n   ESCOLHA O SEXO DO COLABORADOR [0 - MASCULINO / 1 - FEMININO]........: ");
                scanf("%d", &aux);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                if(aux == 1){ // Validar um sexo padrão.
                    strcat(sexo, "FEMININO");
                    break; // Interrompe o looping
                }else if(aux == 0){ // Validar um sexo padrão.
                    strcat(sexo, "MASCULINO");
                    break; // interrompe o looping
                }else{ // Validar retorna um erro caso a opção escolhida não seja 1 ou 0.
                    printf("\n   ALTERNATIVA INVALIDA. TENTE NOVAMENTE!");
                    lform(); // Linha formatada
                }
            }
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                // Validar a entrada de um CPF
                printf("\n   ENTRE COM O CPF DO COLABORADOR......................................: ");
                scanf("%s", &cpf);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                recebecpf = strtoll(cpf, &eptr, 10);
                if(validaCPF(recebecpf) == false){
                    printf("\n   CPF INVALIDO. TENTE NOVAMENTE!\n");
                    lform(); // Linha formatada
                }else{
                    char temp[10] = ""; // Cria uma variavel temporaria do tipo char
                    aux = criarnumusuario(recebecpf); // A variavel auxiliar recebera o numero gerado pela função com base nos digitos do CPF
                    itoa(aux, temp, 10); // Faz a conversão do numero inteiro contido na variavel auxiliar para um valor string na variavel temporaria do tipo char
                    strcat(auxlogin, sigla); // Concatena a sigla da empresa na variavel de login
                    strcat(auxlogin, temp); // Concatena o valor da variavel temporaria no login para criar o user login
                    break; // Encerra o looping
                }
            }
            printf("\n   DIGITE O ENDERECO DE LOCALIZACAO DO COLABORADOR.....................: ");
            scanf("%[^\n]", &endereco);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                // Validar a entrada de um telefone de contato
                printf("\n   INFORME O TELEFONE DE CONTATO COM O DDD(SEM ESPACOS E SEM O ZERO)...: ");
                scanf("%s", &telefonecontato);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                recebetel = strtoll(telefonecontato, &eptr, 10);
                if(validaTEL(recebetel) == false){
                    printf("\n    TELEFONE INCORRETO, FAVOR TENTAR NOVAMENTE!\n");
                    lform(); // Linha formatada
                }else{
                    break; // Encerra o looping
                }
            }
            printf("\n   INFORME O ID - CARTEIRA DE TRABALHO.................................: ");
            scanf("%s", &ctps);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            printf("\n   ID DO CERTIFICADO DE MEDICINA.......................................: ");
            scanf("%s", &diploma);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            confirmacadastro(nome, "N/A", idadeString, sexo, cpf, endereco, telefonecontato, ctps, diploma, "N/A"); // Mostra na tela as informações do cadastro para que o usuario posssa confirma-las.
            printf("\n   DESEJA FINALIZAR O CADASTRO DO COLABORADOR? [0 - NÃO / 1 - SIM].....: ");
            scanf("%d", &confirma);
            lb(); // Limpa o buffer do teclado
            if(confirma == 0){
                system("msg * CADASTRO CANCELADO PELO USUARIO"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial
            }
            strcat(cadastro, "funcionarios\\"); // Concatena a pasta de funcionarios na variavel cadastro
            strcat(cadastro, cpf); // Concatena o cpf no cadastro
            strcat(cadastro, ext); // Concatena o cpf com a extensão txt no cadastro;
            file = fopen(cadastro, "r"); // Abre um arquivo de texto em modo leitura
            if(file != NULL){ // Verifica se o colaborador já está cadastrado.
                system("msg * COLABORADOR JA CADASTRADO NO BANCO DE FUNCIONARIOS. CADASTRO CANCELADO PELO SISTEMA."); // Apresenta uma POP UP com uma mensagem para o usuario
                fclose(file); // Fecha o arquivo de texto caso tenha sido aberto.
                goto iniciar; // Direciona o usuario para a tela de cadastros.
            }
            fclose(file);// Fecha o arquivo de texto aberto.
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastro, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescebtabdi demais informações
            file = fopen(cadastro, "a"); // Abre o arquivo de texto
            fputs("\n      CARTEIRA DE TRABALHO.............: ", file);
            fputs(ctps, file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fputs("\n      CERTIFICACAO DIPLOMA MEDICO......: ", file);
            fputs(diploma, file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fputs("\n      TIPO.............................: MEDICO", file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fclose(file); // Fecha o arquivo
            createloginsenha(criapastalogin, criapastasenha, auxlogin, cpf);
            system("msg * MEDICO CADASTRADO COM SUCESSO!\n"); // Apresenta uma POP UP com uma mensagem para o usuario
            goto iniciar; // Direciona o usuario para a tela de de inicio.
        }else if(strcmp(resp, "A3") == 0 || strcmp(resp, "a3") == 0){
            limpatela(); // Limpa a tela
            char criapastapaciente[42] = "mkdir pacientes\\", nomemae[40] = "";
            printf("\n ************************************************************************************************************************");
			printf("\n *                                             CADASTRO DE PACIENTES                                                    *");
			printf("\n ************************************************************************************************************************\n\n");
            if (admin == false && moderador == false){
                system("msg * VOCE NAO POSSUI PRIVILEGIOS DE ADMINSTRADOR PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial
			}
			//Entrada de dados do usuario.
			while(contador != 0){
                printf("\n   ENTRE COM A IDADE DO PACIENTE....................................: ");
                scanf("%d", &idade);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                itoa(idade, idadeString, 10); // Converter um inteiro para string
                if(idade < 0 && idade >= 150){
                    printf("\n   IDADE INVALIDA. TENTE NOVAMENTE.\n");
                }else{
                    break;
                }
			}
            // Bloco cadastro com entrada de dados do usuario
            printf("\n   ENTRE COM O NOME DO PACIENTE.....................................: ");
            scanf("%[^\n]", &nome);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            printf("\n   ENTRE COM O NOME DA MAE DO PACIENTE..............................: ");
            scanf("%[^\n]", &nomemae);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            while(contador != 0){
                printf("\n   POSSUI PLANO DE SAUDE(CONVENIO MEDICO)? [0 - NÃO / 1 - SIM]......: ");
                scanf("%d", &aux);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                if(aux == 1){
                    printf("\n   IDENTIFICACAO - CARTAO CONVENIO..................................: ");
                    scanf("%[^\n]", &numconvenio);
                    lb(); // Limpa o buffer do teclado
                    lform(); // Linha formatada
                    break;
                }else if(aux == 0){
                    strcat(numconvenio, "N/A");
                    break;
                }else{
                    printf("\n   ALTERNATVA INVALIDA. TENTE NOVAMENTE!\n");
                    lform(); // Linha formatada
                }
            }
            while(contador != 0){
                    // Validar um sexo padrão.
                printf("\n   INFORME O SEXO DO PACIENTE [0 - MASCULINO / 1 - FEMININO]........: ");
                scanf("%d", &aux);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                if(aux == 1){
                    strcat(sexo, "FEMININO");
                    break;
                }else if(aux == 0){
                    strcat(sexo, "MASCULINO");
                    break;
                }else{
                    printf("\n   ALTERNATIVA INVALIDA. TENTE NOVAMENTE!\n");
                    lform(); // Linha formatada
                }
            }
            while(contador != 0){
                // Validar a entrada de um CPF
                printf("\n   ENTRE COM O CPF DO PACIENTE......................................: ");
                scanf("%s", &cpf);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                recebecpf = strtoll(cpf, &eptr, 10);
                if(validaCPF(recebecpf) == false){
                    printf("\n   CPF INVALIDO TENTE NOVAMENTE!");
                    lform(); // Linha formatada
                }else{
                    break;
                }
            }
            printf("\n   DIGITE O ENDERECO DE LOCALIZACAO DO PACIENTE.....................: ");
            scanf("%[^\n]", &endereco);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            while(contador != 0){
                // Validar a entrada de um telefone de contato
                printf("\n   INFORME O TELEFONE DE CONTATO COM O DDD(SEM ESPACOS E SEM O ZERO): ");
                scanf("%s", &telefonecontato);
                lb(); // Limpa o buffer do teclado
                lform(); // Linha formatada
                recebetel = strtoll(telefonecontato, &eptr, 10);
                if(validaTEL(recebetel) == false){
                    printf("\n   TELEFONE INCORRETO, FAVOR TENTAR NOVAMENTE.\n");
                    lform(); // Linha formatada
                }else{
                    break;
                }
            }
            // Revisão de informações no cadastro.
            confirmacadastro(nome,nomemae,idadeString,sexo,cpf,endereco,telefonecontato,ctps,"N/A",numconvenio);
            printf("\n   DESEJA FINALIZAR O CADASTRO DO PACIENTE? [0 - NÃO / 1 - SIM].....: ");
            scanf("%d", &confirma);
            lform(); // Linha formatada
            if(confirma == 0){
                system("msg * CADASTRO CANCELADO PELO USUARIO"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar;
            }
            strcat(criapastapaciente, cpf);// CRIANDO CAMINHO DA PASTA COM INFORMACOES DO PACIENTE
            system(criapastapaciente); // CRIA A PASTA COM AS INFORMACOES DO PACIENTE;
            if(strcmp(numconvenio, "N/A") == 1){ // Se O cliente possuir um convênio médico, este será guardado no "banco de dados"
                char temporario[60] = "pacientes\\"; // Concatena a pasta de destino para acrescentar as informações ao bloco de texto
                strcat(temporario, cpf); // Concaten o CPF do cliente
                strcat(temporario, "\\true"); // Concatena o separador de diretorios
                strcat(temporario, ext); // Concatena a extensão .txt
                file = fopen(temporario, "a"); // abre o arquivo de texto em modo de escrita(cria o arquivo)
                fclose(file); // Fecha o arquivo de texto.
            }
            //Acrescentando demais informacoes no cadastro.
            strcat(cadastro, "pacientes\\");
            strcat(cadastro, cpf); // Concatena o cpf no cadastro
            strcat(cadastro, "\\"); // Concatena o separador de diretorios
            strcat(cadastro, cpf); // Concatena o cpf no cadastro
            strcat(cadastro, ext); // Concatena o cpf com a extensão txt no cadastro;
            file = fopen(cadastro, "r"); // Abre um arquivo de texto em modo leitura
            if(file != NULL){ // Verifica se o colaborador já está cadastrado.
                system("msg * ESTE PACIENTE JA CONSTA CADASTRADO NO BANCO DE CADASTROS. CADASTRO CANCELADO PELO SISTEMA!."); // Apresenta uma POP UP com uma mensagem para o usuario
                fclose(file); // Fecha o arquivo de texto caso tenha sido aberto.
                goto iniciar; // Direciona o usuario para a tela de cadastros.
            }
            fclose(file);// Fecha o arquivo de texto aberto.
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastro, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescentando demais informacoes no cadastro.
            file = fopen(cadastro, "a");
            fputs("\n      NOME DA MAE......................: ", file);
            fputs(nomemae, file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fputs("\n      CARTAO DE CONVENIO...............: ", file);
            fputs(numconvenio, file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fputs("\n      TIPO.............................: PACIENTE", file);
            fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
            fclose(file); // Fecha o arquivo
            system("msg * PACIENTE CADASTRADO COM SUCESSO!"); // Apresenta uma POP UP com uma mensagem para o usuario
            goto iniciar; // Direciona o usuario para tela de inicio
        }else if(strcmp(resp, "A4") == 0 || strcmp(resp, "a4") == 0){
            if(admin == false && moderador == false){
                system("msg * VOCE NAO POSSUI PRIVILEGIOS PARA EXECUTAR ESSA FUNCAO!"); // Apresenta uma popup na tela do usuario
                goto iniciar; // Direciona o usuario para a tela inicial
            }
            limpatela(); // Limpa a tela
            float valorconsulta;
            char verificaconv[35] = "pacientes\\", verificapaciente[45] = "pacientes\\", svalorconsulta[10] = "";
            printf("\n ************************************************************************************************************************");
			printf("\n *                                            CADASTRO DE AGENDAMENTOS                                                  *");
			printf("\n ************************************************************************************************************************\n\n");
            // Entrada de dados do usuario
            printf("\n   ENTRE COM O CPF DO PACIENTE......................................: ");
            scanf("%s", &cpf);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            strcat(verificapaciente, cpf); // Concatena o CPF
            strcat(verificapaciente, "\\"); // Concatena o separador de diretorios
            strcat(verificapaciente, cpf); // Concatena o cpf no cadastro
            strcat(verificapaciente, ext); // Concatena o cpf com a extensão txt no cadastro;
            strcat(verificaconv, cpf); // Concatena o cpf na variavel de verificar convenio
            strcat(verificaconv, "\\true.txt"); // Concatena o  separador de diretorios
            // Valida se o paciente já está cadastrado no sistema.
            if(file = fopen(verificapaciente, "r")){ // abre o arquivo de texto e verifica se o paciente já está cadastrado
                fclose(file); // Fecha o arquivo de texto
            }else{ // Se a afirmação inicial for falsa significa que o paciente não está cadastrado.
                system("msg * PACIENTE NAO LOCALIZADO! FAVOR CADASTRA-LO PRIMEIRAMENTE."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial
            }
            printf("\n   INFORME O NOME DO MEDICO QUE FARA O ATENDIMENTO..................: ");
            scanf("%[^\n]", &nome);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            printf("\n   DATA DO AGENDAMENTO(FORMATO 01.01.2000)..........................: ");
            scanf("%s", &data);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            printf("\n   HORARIO DE AGENDAMENTO(FORMATO 23:59:59).........................: ");
            scanf("%s", &hora);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            system("msg * IMPORTANTE! AO ENTRAR COM OS VALORES, NAO UTILIZE VIRGULA PARA SEPRAR OS VALORES, UTILIZE O PONTO EX: R$150.75");
            printf("\n   VALOR A SER PAGO(FORMATO R$00.00)................................: R$");
            scanf("%f", &valorconsulta);
            if(file = fopen(verificaconv, "r")){
                fclose(file);
                system("msg * ESTE PACIENTE POSSUI CONVENIO MEDICO, O VALOR SERA REAJUSTADO AUTOMATICAMENTE.");
                valorconsulta = valorconsulta - (valorconsulta * 50 / 100);
            }
            itoa(valorconsulta, svalorconsulta, 10);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            printf("\n                                           -- CONFIRMACAO DE CADASTRO -- ");
            lform(); // Linha formatada
            printf("\n       MEDICO QUE ATENDERA O PACIENTE..............: %s", nome);
            lform(); // Linha formatada
            printf("\n       DATA/HORA DO AGENDAMENTO....................: %s AS %s", data, hora);
            lform(); // Linha formatada
            printf("\n       VALOR TOTAL A SER PAGO......................: R$%.2f", valorconsulta);
            lform(); // Linha formatada
            printf("\n\n\n   AS INFORMACOES ESTAO CORRETAS? [0 - CANCELAR / 1 - CONCLUIR]: ");
            scanf("%d", &confirma);
            lform(); // Linha formatada
            if(confirma == 0){
                system("msg * PEDIDO CANCELADO PELO USUARIO!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial
            }else if(confirma == 1){
                srand(time(NULL)); // Funcao auxiliar para gerar numeros aleatórios.
                numos = gerarOS(); // Funcao para gerar a ordem de servico
                printf("\n   ORDEM DE SERVICO DO AGENDAMENTO.................: %d\n", numos); // informa o numero da ordem de serviço para o usuario
                lform(); // Linha formatada
                itoa(numos, OS, 10); // Converte inteiro para string
                strcat(auxiliarOS, "agendamentos\\concluidos\\"); // Concatena o caminho da pasta onde sera armazenado a OS na varaivel auxiliaros
                strcat(cadastroOS, "agendamentos\\"); // Concatena a pasta de armazenameto da OS
                strcat(cadastroOS, "AG"); // Concatena a pasta de armazenamento da OS.
                strcat(cadastroOS, OS); // Concatena o numero da OS na variavel de cadastro
                strcat(cadastroOS, ext); // Concatena a extensao .txt na variavel de cadastrar a os
                strcat(auxiliarOS, "AG"); // Concatena a pasta de armazenamento da OS.
                strcat(auxiliarOS, OS); // Concatena o numero da ordem de servico na variavel auxiliaros
                strcat(auxiliarOS, ext); // Concatena a extensão .txt na variavel auxiliaros
                file = fopen(cadastroOS, "a"); // Abre o arquivo de texto.
                // Acrescentando informações no bloco de texto
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      AGENDAMENTO ABERTO POR......................: ", file);
                fputs(identificacao_menu, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      MEDICO QUE FARA O ATENDIMENTO...............: ", file);
                fputs(nome, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      CPF DO PACIENTE.............................: ", file);
                fputs(cpf, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      VALOR A SER PAGO............................: R$", file);
                fputs(svalorconsulta, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      PREVISAO DA CONCLUSAO DO AGENDAMENTO........: ", file);
                fputs(data, file);
                fputs(" - ", file);
                fputs(hora, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      ORDEM DE SERVICO............................: AG", file);
                fputs(OS, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fclose(file); // Fecha o arquivo de texto
                //Abre arquivo de texto auxiliar.
                file = fopen(auxiliarOS, "a");
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      AGENDAMENTO ABERTO POR......................: ", file);
                fputs(identificacao_menu, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      MEDICO QUE FARA O ATENDIMENTO...............: ", file);
                fputs(nome, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      CPF DO PACIENTE.............................: ", file);
                fputs(cpf, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      VALOR A SER PAGO............................: R$", file);
                fputs(svalorconsulta, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      PREVISAO DA CONCLUSAO DO AGENDAMENTO........: ", file);
                fputs(data, file);
                fputs(" - ", file);
                fputs(hora, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fputs("\n      ORDEM DE SERVICO............................: AG", file);
                fputs(OS, file);
                fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                fclose(file); // Fecha o arquivo de texto
                system("msg * AGENDAMENTO CONCLUIDO COM SUCESSO!");
                goto iniciar; // Direciona o usuario para a tela de inicio.
            }else{
                system("msg * ALTERNATIVA INVALIDA. CADASTRO CANCELADO PELO SISTEMA!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial
            }
        }else if(strcmp(resp, "A5") == 0 || strcmp(resp, "a5") == 0){
            limpatela(); // limpa a tela
            if (admin == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            FILE *file;
            printf("\n ************************************************************************************************************************");
			printf("\n *                                            CONSULTA DE FUNCIONARIOS                                                  *");
			printf("\n ************************************************************************************************************************\n\n");
            // Entrada de dados do usuario
            printf("   CPF A SER CONSULTADO..........................: ");
            scanf("%s", &cpf);
            lform(); // Linha formatada
            strcat(consultaficha, "funcionarios\\"); // Concatena a pasta de funcionarios na variavel de consultarficha
            strcat(consultaficha, cpf); // Concatena o CPF digitado na variavel de consulta
            strcat(consultaficha, ext); // Concatena a extensao .txt na variavel de consulta
            if(file = fopen(consultaficha, "r")){ // Abre  o arquivo de texto para verificar sua validade
                fclose(file); // Fecha o arquivo de texto
            }else{
                system("msg * COLABORADOR NAO LOCALIZADO NA BASE."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Salta para o menu iniciar
            }
            leitura(consultaficha); // Abre o arquivo de leitura da ficha com a funcao de Leitura.
            printf("\n");
            lform(); // Linha formatada
            pause(); // Pausa a tela para o usuario.
            goto iniciar;// Direciona o usuario para o menu inicial
        }else if(strcmp(resp, "A6") == 0 || strcmp(resp, "a6") == 0){
            limpatela(); // limpa a tela
            char frase[500] = "";
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            printf("\n ************************************************************************************************************************");
			printf("\n *                                              CONSULTA DE PACIENTES                                                   *");
			printf("\n ************************************************************************************************************************\n\n");
            // Entrada de dados
            printf("   CPF A SER CONSULTADO..........................: ");
            scanf("%s", &cpf);
            lform(); // Linha formatada
            strcat(consultaficha, "pacientes\\"); // Concatena o caminho da pasta de pacientes na variavel de consulta
            strcat(consultaficha, cpf); // concatena o cpf digitado na variavel de consulta
            strcat(consultaficha, "\\"); // concatena o separador de diretorios digitado na variavel de consulta
            strcat(consultaficha, cpf); // concatena o cpf digitado na variavel de consulta
            strcat(consultaficha, ext); // Concatena a extensao .txt
            file = fopen(consultaficha, "r"); // Verifica se o arquivo existe
            if(file == NULL){ // Se o arquivo não existir, o cliente nao esta cadastrado
                system("msg * CADASTRO NAO LOCALIZADO!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona ao menu de consultas
            }//Processo de leitura do arquivo que imprime na tela caractere por carectere
            while(fgets(frase, 500, file) != NULL){ // Repetira até que o arquivo seja nulo(nao exista mais caracteres para serem lidos)
                printf("%s", frase); // Imprime na tela todas as informacoes do arquivo de texto
            }
            fclose(file); // Fecha o arquivo de texto do cliente.
            lform(); // Linha formatada
            pause(); // Pausa a tela para o usuario conseguir absorver as informaçoes
            goto iniciar; // Direciona o usuario para o menu iniciar.
        }else if(strcmp(resp, "A7") == 0 || strcmp(resp, "a7") == 0){
            limpatela();
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            printf("\n ************************************************************************************************************************");
			printf("\n *                                             CONSULTA DE AGENDAMENTO                                                  *");
			printf("\n ************************************************************************************************************************\n\n");
            // Entrada de dados DO USUARIO
            printf("\n   DIGITE O NUMERO DA OS DO AGENDAMENTO CLINICO.............: ");
            scanf("%s", &digitoOS); // Faz a leitura dos dados digitados pelo usuario e armazena na variavel digitoOS
            //Concatenacao de strings
            strcat(consultarOS, "agendamentos\\AG"); // Concatena o caminho do agendamento na variavel consultarOS
            strcat(consultarOS, digitoOS); // Concatena o que foi digitado pelo usuario na variavel de consultarOS
            strcat(consultarOS, ext); // Concatena a extensão .txt
            resultadobusca = leitura(consultarOS); // Realiza a leitura da ordem de serviço
            // Condicao de verificacao
            if(resultadobusca == false){
                system("msg * ORDEM DE SERVICO NAO LOCALIZADA. VERIFIQUE OS AGENDAMENTOS EM HISTORICO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario ao menu de consultas
            }else if(resultadobusca == true){
                printf("\n\n   DESEJA DAR BAIXA NO AGENDAMENTO? [0 - PARA NAO / 1 - PARA SIM]: ");
                scanf("%d", &aux);
                lform(); // Linha formatada
                if (aux == 1){
                    remove(consultarOS); // Apaga o arquivo de agendamentos pendentes e o move para agendamentos concluidos
                    //Arquivo movido para pasta de conclusão final
                    strcat(baixaOS, "agendamentos\\concluidos\\AG"); // Concatena o caminho de agendamentos concluidos na variavel de baixaOS
                    strcat(baixaOS, digitoOS); // Concatena o que foi digitado pelo usuario na variavel de dar baixa
                    strcat(baixaOS, ext); // concatena a extensão .txt
                    file = fopen(baixaOS, "a"); // realiza a abertura do arquivo
                    fputs("\n      STATUS......................................: CONCLUIDO!", file);
                    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      RESPONSAVEL PELO FECHAMENTO.................: ", file);
                    fputs(identificacao_menu, file);
                    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      DATA/HORA DO FECHAMENTO.....................: ", file);
                    fclose(file); // fecha o arquivo
                    incluirdatahora(baixaOS); // Inclui a data de e hora atual dentro do arquivo a ser editado.
                    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                    system("msg * SOLICITACAO CONCLUIDA COM SUCESSO!"); // Apresenta uma POP UP com uma mensagem para o usuario
                }
            }
            goto iniciar; // Direciona o usuario para o menu iniciar
        }else if(strcmp(resp, "A8") == 0 || strcmp(resp, "a8") == 0){
            limpatela(); // limpa a tela para o usuario
            char verificaPendencia[50] = "agendamentos\\AG";
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            printf("\n ************************************************************************************************************************");
			printf("\n *                                             AGENDAMENTO EM HISTORICO                                                 *");
			printf("\n ************************************************************************************************************************\n\n");
            //Entrada de dados do usuario
            printf("   ENTRE COM O NUMERO DA OS DE AGENDAMENTO EM HISTORICO.............: ");
            scanf("%s", &digitoOS);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            //Concatenacao de informacoes
            strcat(consultarOS, "agendamentos\\concluidos\\AG");
            strcat(consultarOS, digitoOS);
            strcat(consultarOS, ext);
            strcat(verificaPendencia, digitoOS);
            strcat(verificaPendencia, ext);
            FILE *verif; // Declaração de variavel do tipo FILE
            verif = fopen(verificaPendencia, "r"); // Verifica se o arquivo exsiste na pasta indicada.
            if(verif == NULL){
                leitura(consultarOS); // Faz a leitura dos arquivos na pasta indicada
                lform(); // Linha formatada
                pause(); // Pausa a tela para o usuario visualizar as informacoes;
                goto iniciar; // Direciona o usuario ao menu de consultas
            }
            fclose(verif); // fecha o arquivo de texto
            system("msg * ESTA OS DE AGENDAMENTO NAO EXISTE OU PODE ESTAR PENDENTE DE TRATAMENTO."); // Apresenta uma POP UP com uma mensagem para o usuario
            goto iniciar; // DIreciona o usuario para o menu inicial
        }else if(strcmp(resp, "A9") == 0 || strcmp(resp, "a9") == 0){
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            limpatela(); // Limpa a tela para o usuario;
            printf("\n ************************************************************************************************************************");
			printf("\n *                                      REGISTRAR RECLAMACAO/SUGESTAO/ELOGIOS                                           *");
			printf("\n ************************************************************************************************************************\n\n");
            printf("\n   CATEGORIAS DISPONIVEIS...............................: [0 - SUGESTAO] [1 - RECLAMACAO] [2 - ELOGIO]");
            system("msg * INFORME A CATEGORIA UTILIZANDO 0, 1 OU 2");
            lform(); // Linha formatada
            printf("\n   PARA PROSSEGUIR INFORME A CATEGORIA..................: ");
            scanf("%d", &aux);
            lb(); // Limpa o buffer do teclado.
            lform(); // Linha formatada
            if(aux == 0){
                strcat(categoria, "SUGESTAO");
                strcat(sg, "SG");
            }else if(aux == 1){
                strcat(categoria, "RECLAMACAO");
                strcat(sg, "RC");
            }else if(aux == 2){
                strcat(categoria, "ELOGIO");
                strcat(sg, "EL");
            }else{ // Se nenhuma das opcoes forem verdadeiras retornara um erro para o usuario
                system("msg * CATEGORIA INVALIDA. SOLICITACAO CANCELADA PELO SISTEMA!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar;
            }
            printf("\n   INFORME O CPF DO SOLICITANTE DO REGISTRO.............: ");
            scanf("%s", cpf);
            lb(); // Limpa o buffer do teclado.
            lform(); // Linha formatada
            recebecpf = strtoll(cpf, &eptr, 10);// Converte uma string em um inteiro
            if(validaCPF(recebecpf) == true){
                printf("\n\n\n   EM ATE 255 CARACTERES DESCREVA 0(A)%s..: ",categoria);
                scanf("%[^\n]", &resenha); // Faz a leitura do que o usuario digitar e armazena na variavel resenha
                lb(); // Limpa o buffer do teclado.
                lform(); // Linha formatada
                printf("\n   REVISE AS INFORMACOES! PARA PROSSEGUIR TECLE [0 - PARA CANCELAR / 1 - PARA CONCLUIR]: ");
                scanf("%d", &aux); // Faz a leitura dos dados digitados pelo usuario
                lb(); // Limpa o buffer do teclado.
                lform(); // Linha formatada
                if(aux == 0){ // Se a opcao escolhida for zero, o cadastro sera interrompido
                    system("msg * CADASTRO CANCELADO PELO USUARIO!"); // Apresenta uma POP UP com uma mensagem para o usuario
                    goto iniciar; // Direciona o usuario para o menu iniciar
                }else if(aux == 1){
                    os = gerarOS(); // Gera um numero aleatorio para a ordem de serviço
                    printf("\n   ORDEM DE SERVICO PARA %s.............................: %d\n", categoria, os);
                    lform(); // Linha formatada
                    itoa(os, rlos, 10); // Converte um inteiro para String
                    strcat(caminho_recl_sugs_elo, categoria); // Acrescenta uma pasta
                    strcat(caminho_recl_sugs_elo, "\\"); // Acrescenta a barra divisora de diretorios
                    strcat(caminho_recl_sugs_elo, sg); // Acrescenta a sigla da solicitação na variavel de caminho
                    strcat(caminho_recl_sugs_elo, rlos); // Concatena o caminho com o nome do arquivo.
                    strcat(caminho_recl_sugs_elo, ext); // Concatena a extensao
                    file = fopen(caminho_recl_sugs_elo, "a"); // Abre o arquivo de texto.
                    // Acrescentando informacoes ao bloco de texto.
                    fputs("\n\n      REGISTRO EM......................: ",file);
                    fclose(file); // Fecha o arquivo de texto em aberto
                    incluirdatahora(caminho_recl_sugs_elo); // Inclui a data e hora atual do sistema no bloco de texto
                    file = fopen(caminho_recl_sugs_elo, "a"); // Abre o arquivo de texto.
                    fputs("\n  ----------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      REGISTRADO POR...................: ", file);
                    fputs(identificacao_menu, file);
                    fputs("\n  ----------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      REGISTRO A PEDIDO DO CPF.........: ", file);
                    fputs(cpf, file);
                    fputs("\n  ----------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      CATEGORIA........................: ", file);
                    fputs(categoria, file);
                    fputs("\n  ----------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      ORDEM DE SERVICO.................: ", file);
                    fputs(sg, file);
                    fputs(rlos, file);
                    fputs("\n  ----------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n\n\n      RESENHA..........................: ", file);
                    fputs(resenha, file);
                    fclose(file); // Fecha o arquivo de texto
                    system("msg * SOLICITACAO REGISTRADA COM SUCESSO!"); // Apresenta uma POP UP com uma mensagem para o usuario
                    goto iniciar; // Direciona o usuario para o menu iniciar
                }else{
                    system("msg * ALTERNATIVA INVALIDA. CADASTRO CANCELADO PELO SISTEMA"); // Apresenta uma POP UP com uma mensagem para o usuario
                    goto iniciar; // Direciona o usuario para a tela inicial
                }
            }else{ // Se as alternativas não forem 1 ou 0 será retornado um erro ao usuario informando o cancelamento da solicitacao
                system("msg * CPF INVALIDO. SOLICITACAO CANCELADA PELO SISTEMA!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela inicial
            }
        }else if(strcmp(resp, "AA") == 0 || strcmp(resp, "aa") == 0){
            limpatela(); // Limpa a tela para o usuario
            char cons_recl_sugs_elo[15] = "";
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            printf("\n ************************************************************************************************************************");
			printf("\n *                                      CONSULTAR RECLAMACAO/SUGESTAO/ELOGIOS                                           *");
			printf("\n ************************************************************************************************************************\n\n");
            printf("\n   CATEGORIAS DISPONIVEIS...............................: [0 - SUGESTAO] [1 - RECLAMACAO] [2 - ELOGIO]");
            system("msg * INFORME A CATEGORIA UTILIZANDO 0, 1 OU 2");
            lform(); // Linha formatada
            printf("\n   PARA PROSSEGUIR INFORME A CATEGORIA..................: ");
            scanf("%d", &aux); // Faz a leitura e armazena o vlaor digitado pelo usuario
            lform(); // Linha formatada
            if(aux == 0){
                strcat(categoria, "SUGESTAO");
                strcat(sg, "SG");
            }else if(aux == 1){
                strcat(categoria, "RECLAMACAO");
                strcat(sg, "RC");
            }else if(aux == 2){
                strcat(categoria, "ELOGIO");
                strcat(sg, "EL");
            }else{ // Se nenhuma das opcoes forem verdadeiras retornara um erro para o usuario
                system("msg * CATEGORIA INVALIDA. SOLICITACAO CANCELADA PELO SISTEMA!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para o menu inicial
            }
            printf("\n   ENTRE COM A ORDEM DE SERVICO.........................: ");
            scanf("%s", &cons_recl_sugs_elo);
            lb(); // Limpa o buffer do teclado
            lform(); // LINHA FORMATADA
            strcat(caminho_recl_sugs_elo, categoria); // Acrescenta uma pasta
            strcat(caminho_recl_sugs_elo, "\\"); // Acrescenta a barra divisora de diretorios
            strcat(caminho_recl_sugs_elo, sg); // Concatena a sigla da solicitacao
            strcat(caminho_recl_sugs_elo, cons_recl_sugs_elo); // Concatena o caminho com o nome do arquivo.
            strcat(caminho_recl_sugs_elo, ext); // Concatena a extensao
            file = fopen(caminho_recl_sugs_elo, "r"); // Abre o arquivo de texto em modo de leitura
            if(file == NULL){
                system("msg * SOLICITACAO CONCLUIDA SEM SUCESSO POR ORDEM DE SERVICO NAO LOCALIZADA. TENTE NOVAMENTE!"); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para a tela de inicio
            }
            fclose(file); // Fecha o arquivo de texto
            leitura(caminho_recl_sugs_elo); // Realiza a leitura do arquivo de texto
            printf("\n\n"); // Salta 2 linhas
            lform(); // Linha formatada
            pause(); //Pausa a tela para o usuario
            goto iniciar; // Direciona o usuario para o menu inicial
        }else if(strcmp(resp, "AB") == 0 || strcmp(resp, "ab") == 0){
            char infosistema[20] = "", tipasta[35] = "ti-sistemas\\TI", tipastatratados[45] = "ti-sistemas\\tratados\\TI"; // Declaração de variavel local
            char modalidade[27] = ""; // Declaração de variavel local
            limpatela(); //Limpa a tela do usuario
            printf("\n ************************************************************************************************************************");
			printf("\n *                                      REGISTRO DE CHAMADO INTERNO PARA O TI                                           *");
			printf("\n ************************************************************************************************************************\n\n");
			printf("   MODALIDADES DISPONIVEIS PARA TRATAMENTO.......: [0 - SISTEMA DEFEITUOSO] - [1 - PLANTA EXTERNA DANIFICADA]\n");
			lform(); // Linha formatada
			system("msg * INFORME A MODALIDADE DA SOLICITACAO UTILIZANDO 0 OU 1!");
			printf("\n   RESPOSTA -> ");
			scanf("%d", &aux);
			lb(); // Limpa o buffer do teclado.
			lform(); // Linha formatada
			if(aux == 0){
                strcat(modalidade, "SISTEMA DEFEITUOSO"); // Concatena a falha reclamada
                printf("\n   INFORME O NOME DO SISTEMA DANIFICADO: ");
                scanf("%[^\n]", &infosistema);
                lb(); // Limpa o buffer do teclado.
                lform(); // Linha formatada
                printf("\n   DESCREVA A FALHA EM ATE 255 CARACTERES.\n");
                lform(); // Linha formatada
                printf("\n   -> ");
                scanf("%[^\n]", &resenha);
                lb(); // Limpa o buffer do teclado.
                lform(); // Linha formatada
                printf("\n   REVISE AS INFORMACOES ANTES DE PROSSEGUIR.\n");
                lform(); // Linha formatada
                printf("\n   DESEJA CONCLUIR?[0 - NAO / 1 - SIM]: ");
                scanf("%d", &confirma);
                if(confirma == 0){
                    system("msg * CANCELAMENTO EXECUTADO A PEDIDO DO USUARIO!"); // Apresenta uma POP-UP de mensagtem na tela do usuario
                    goto iniciar; // Direciona o usuario para o menu iniciar
                }else{
                    lform(); // Linha formatada
                    os = gerarOS(); // Gera a ordem de serviço
                    itoa(os, OS, 10); // Converte um numero inteiro para STRING
                    printf("\n   OS DE TRATAMENTO: %s\n", OS);
                    lform(); // Linha formatada
                    pause(); // Pausa a tela para o usuario
                    system("msg * SOLICITACAO CONCLUIDA COM SUCESSO!");
                    concatena_string(tipasta, tipastatratados, OS, modalidade, identificacao_menu, infosistema, resenha); // Concatena as informações e cria a OS na pasta indicada
                }
			}else if(aux == 1){
                strcat(modalidade, "PLANTA EXTERNA DANIFICADA"); // Concatena a falha reclamada
                printf("\n   AFETOU ALGUM SISTEMA?[0 - NAO / 1 - SIM]............: ");
                scanf("%d", &aux);
                lb(); // Limpa o buffer do teclado.
                lform(); // Linha formatada
                if(aux == 1){
                    printf("\n   INFORME QUAL FOI O SISTEMA AFETADO..................: ");
                    scanf("%[^\n]", &infosistema);
                    lb(); // Limpa o buffer do teclado.
                    lform(); // Linha formatada
                }else if(aux == 0){
                    strcat(infosistema, "N/A");
                }else{
                    system("msg * ALTERNATIVA INVALIDA! SOLICITACAO CANCELADA PELO SISTEMA!"); // Apresenta uma POP-UP com informações na tela do usuario.
                    goto iniciar; // DIreciona o usuario para tela inicial
                }
                printf("\n   DESCREVA EM ATE 255 CARACTERES A FALHA E A LOCALIDADE DE OCORRENCIA DA MESMA.\n");
                lform(); // Linha formatada
                printf("\n   -> ");
                scanf("%[^\n]", &resenha);
                lb(); // Limpa o buffer do teclado.
                lform(); // Linha formatada
                printf("\n   REVISE AS INFORMACOES ANTES DE PROSSEGUIR.\n");
                lform(); // Linha formatada
                printf("\n   DESEJA CONCLUIR?[0 - NAO / 1 - SIM]: ");
                scanf("%d", &confirma);
                if(confirma == 0){
                    system("msg * CANCELAMENTO EXECUTADO A PEDIDO DO USUARIO!"); // Apresenta uma POP-UP de mensagtem na tela do usuario
                    goto iniciar; // Direciona o usuario para o menu iniciar
                }else{
                    lform(); // Linha formatada
                    os = gerarOS(); // Gera a ordem de serviço
                    itoa(os, OS, 10); // Converte um numero inteiro para STRING
                    printf("\n   OS DE TRATAMENTO: %s\n", OS);
                    lform(); // Linha formatada
                    pause(); // Pausa a tela para o usuario
                    system("msg * SOLICITACAO CONCLUIDA COM SUCESSO!");
                    concatena_string(tipasta, tipastatratados, OS, modalidade, identificacao_menu, infosistema, resenha); // Concatena as informações e cria a OS na pasta indicada
                }
			}else{
                system("msg * ALTERNATIVA INVALIDA. OPERACAO CANCELADA PELO SISTEMA, TENTE NOVAMENTE!"); // Apresenta uma POP-UP de mensagtem na tela do usuario
                goto iniciar; // Direciona o usuario para o menu iniciar
			}
			goto iniciar; // Direciona o usuario para o menu iniciar.
        }else if(strcmp(resp, "AC") == 0 || strcmp(resp, "ac") == 0){
            limpatela();
            printf("\n ************************************************************************************************************************");
			printf("\n *                                      CONSULTA DE CHAMADO INTERNO PARA O TI                                           *");
			printf("\n ************************************************************************************************************************\n\n");
            // Entrada de dados DO USUARIO
            printf("\n   DIGITE O NUMERO DA DO CHAMADO EM TRATAMENTO..............: ");
            scanf("%s", &digitoOS); // Faz a leitura dos dados digitados pelo usuario e armazena na variavel digitoOS
            //Concatenacao de strings
            strcat(consultarOS, "ti-sistemas\\TI"); // Concatena o caminho do chamado na variavel consultarOS
            strcat(consultarOS, digitoOS); // Concatena o que foi digitado pelo usuario na variavel de consultarOS
            strcat(consultarOS, ext); // Concatena a extensão .txt
            resultadobusca = leitura(consultarOS); // Realiza a leitura da ordem de serviço
            // Condicao de verificacao
            if(resultadobusca == false){
                system("msg * ORDEM DE SERVICO NAO LOCALIZADA. VERIFIQUE OS CHAMADOS EM HISTORICO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario ao menu de consultas
            }else if(resultadobusca == true){
                printf("\n\n   DESEJA DAR BAIXA NO CHAMADO? [0 - PARA NAO / 1 - PARA SIM]: ");
                scanf("%d", &aux);
                lform(); // Linha formatada
                if (aux == 1){
                    //Arquivo movido para pasta de conclusão final
                    strcat(baixaOS, "ti-sistemas\\tratados\\TI"); // Concatena o caminho de agendamentos concluidos na variavel de baixaOS
                    strcat(baixaOS, digitoOS); // Concatena o que foi digitado pelo usuario na variavel de dar baixa
                    strcat(baixaOS, ext); // concatena a extensão .txt
                    file = fopen(baixaOS, "a"); // realiza a abertura do arquivo
                    fputs("\n      STATUS......................................: CONCLUIDO!", file);
                    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      ENCERRADO POR...............................: ", file);
                    fputs(identificacao_menu, file);
                    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
                    fputs("\n      DATA DE ENCERRAMENTO........................: ", file);
                    fclose(file); // fecha o arquivo
                    incluirdatahora(baixaOS); // Inclui a data de e hora atual dentro do arquivo a ser editado.
                    remove(consultarOS); // Apaga o arquivo de agendamentos pendentes e o move para agendamentos concluidos
                    system("msg * SOLICITACAO CONCLUIDA COM SUCESSO!"); // Apresenta uma POP UP com uma mensagem para o usuario
                }
            }
            goto iniciar; // Direciona o usuario para o menu iniciar
        }else if(strcmp(resp, "AD") == 0 || strcmp(resp, "ad") == 0){
            limpatela(); // Limpa a tela do usuario
            char verificaP[30] = "ti-sistemas\\TI";
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            printf("\n ************************************************************************************************************************");
			printf("\n *                                CONSULTA DE CHAMADO INTERNO PARA O TI EM HISTORICO                                    *");
			printf("\n ************************************************************************************************************************\n\n");
            //Entrada de dados do usuario
            printf("   ENTRE COM O NUMERO DA OS DE AGENDAMENTO EM HISTORICO.............: ");
            scanf("%s", &digitoOS);
            lb(); // Limpa o buffer do teclado
            lform(); // Linha formatada
            //Concatenacao de informacoes
            strcat(consultarOS, "ti-sistemas\\tratados\\TI");
            strcat(consultarOS, digitoOS);
            strcat(consultarOS, ext);
            strcat(verificaP, digitoOS);
            strcat(verificaP, ext);
            FILE *consultaP; // Declaração de variavel do tipo FILE
            consultaP = fopen(verificaP, "r"); // Verifica se o arquivo exsiste na pasta indicada.
            if(consultaP == NULL){
                leitura(consultarOS); // Faz a leitura dos arquivos na pasta indicada
                lform(); // Linha formatada
                pause(); // Pausa a tela para o usuario visualizar as informacoes;
                goto iniciar; // Direciona o usuario ao menu de consultas
            }
            fclose(consultaP); // fecha o arquivo de texto
            system("msg * ESTA OS DE TRATAMENTO NAO EXISTE OU PODE ESTAR EM SENDO TRATADA AINDA."); // Apresenta uma POP UP com uma mensagem para o usuario
            goto iniciar; // Direciona o usuario para o menu inicial
        }else if(strcmp(resp, "AE") == 0 || strcmp(resp, "ae") == 0){
            goto iniciar; // Direciona o usuario para o menu inicial
        }else if(strcmp(resp, "AF") == 0 || strcmp(resp, "af") == 0){
            if (admin == false && moderador == false){ // O usuario só poderá criar um novo cadastro de funcionário se houver permissão de administrador.
                system("msg * VOCE NAO POSSUI PRIVILEGIOS SUFICIENTES PARA EXECUTAR ESTA FUNCAO."); // Apresenta uma POP UP com uma mensagem para o usuario
                goto iniciar; // Direciona o usuario para tela inicial.
			}
            goto iniciar; // Direciona o usuario para o menu inicial
        }else if(strcmp(resp, "B1") == 0 || strcmp(resp, "b1") == 0){
            goto moduser; // Direciona o usuario para o ponto inicial com oportunidade de mudar o usuario.
        }else if(strcmp(resp, "A0") == 0 || strcmp(resp, "a0") == 0){
            system("msg * SAINDO DO SISTEMA.... ATE LOGO!");
            exit(0); // Encerra a aplicação e sai do sistema.
        }else if(strcmp(resp, "B0") == 0 || strcmp(resp, "b0") == 0){
            char senhaa[9] = "", novasenha[16] = "", novasenha1[9] = "", auxnovasenha[48] = "", loginn[7] = "";
            char criarcaminhonovasenha[62] = "", deletarsenhaantiga[62] = "";
            char logtemp[7] = "", temp01[9] = "", temp02[9] = "";
            FILE *trocasenha; // Declaracao de variavel local do tipo FILE
            limpatela(); // Limpa a tela do usuario
            if(admin == true){
                system("msg * OPERACAO NAO PERMITIDA. CANCELAMENTO EXECUTADO COM SUCESSO!");
                goto iniciar; // Direciona o usuario para o menu iniciar
            }
            while(contador != 0){ // inicia um looping infinito, pois não será aplicada a variavel contadora.
                printf("\n   DIGITE O USER LOGIN: ");
                scanf("%s", &logtemp);
                strcpy(loginn, logtemp);
                lb(); // Limpa o buffer do teclado
                lform(); // Apresenta uma mensagem na tela do usuario
                printf("\n   PARA CONTINUAR DIGITE A SENHA DE USUARIO ATUAL: ");
                lersenha(senhaa);
                lb(); // Limpa o buffer do teclado
                lform(); // Apresenta uma mensagem na tela do usuario
                strcat(auxsenha, caminhosenha); // Adiciona o caminho da pasta de senha para a variavel auxiliar de senha
                strcat(auxsenha, loginn); // Adiciona a senha na variavel auxiliar da senha para criar um novo diretório
                strcat(auxsenha, "\\"); // Acrescenta a barra correspondente a separação de diretórios na variavel auxliar da senha
                strcat(auxsenha, senhaa);  // Adiciona a senha na variavel auxiliar da senha para criar um novo arquivo de senha
                strcat(auxsenha, "\\"); // Acrescenta a barra correspondente a separação de diretórios na variavel auxliar da senha
                strcat(auxsenha, senhaa);  // Adiciona a senha na variavel auxiliar da senha para criar um novo arquivo de senha
                strcat(auxsenha, ".txt"); // Adiciona a extensão .txt
                strcat(auxlogin, caminhologin); // Adiciona o caminho de login na variavel auxiliar do login
                strcat(auxlogin, loginn); // Adiciona o login digitado na variavel auxiliar do login
                strcat(auxlogin, "\\"); // Adiciona o separador de diretorios do windows
                strcat(auxlogin, loginn); // ADiciona o login digitado na variavel auxiliar do login
                strcat(auxlogin, ".txt"); // inclui a extensão .txt na variavel auxiliar do login
                if(validarAdmin(auxlogin, auxsenha) == true){ // faz a validação do admin para confirmar cadastro exsistente
                    printf("\n   DIGITE A NOVA SENHA COM ATE 8 CARACTERES: ");
                    lersenha(novasenha);
                    lb(); // Limpa o buffer do teclado
                    lform(); // Apresenta uma mensagem na tela do usuario
                    printf("\n   CONFIRME A NOVA SENHA: ");
                    lersenha(novasenha1);
                    lb(); // Limpa o buffer do teclado
                    lform(); // Apresenta uma mensagem na tela do usuario
                    if(strcmp(novasenha, novasenha1) == 0){
                        strcat(criarcaminhonovasenha, "mkdir system-moderadores\\logins\\"); // Concatena o comando de criação de novas pastas e o caminho da pasta de login na variavel caminho da senha nova
                        strcat(criarcaminhonovasenha, loginn); // Concatena o login digitado na variavel novasenha
                        strcat(criarcaminhonovasenha, "\\"); // Concatena o separador de diretorios do Windows na variavel novasenha
                        strcat(criarcaminhonovasenha, novasenha); // Acrescenta a nova senha do usuario na variavel criarcaminho nova senha
                        system(criarcaminhonovasenha); // Cria a pasta de arquiivo com a nova senha
                        strcat(auxnovasenha, "system-moderadores\\logins\\"); // concatena o caminho do login na variavel auxiliar da nova senha
                        strcat(auxnovasenha, loginn); // concatena o login digitado pelo usuario na variavel auxiliar novasenha
                        strcat(auxnovasenha, "\\"); // Concatena o separador de diretorios do windows na variavel auxiliar da nova senha
                        strcat(auxnovasenha, novasenha); // Concatena a novasenha na variavel auxiliar da nova senha
                        strcat(auxnovasenha, "\\"); // Concatena o separador de diretorios do windows na variavel auxiliar da nova senha
                        strcat(auxnovasenha, novasenha); // Concatena a novasenha na variavel auxiliar da nova senha
                        strcat(auxnovasenha, ext); // concatena a extensao .txt na variavel auxiliar nova senha
                        trocasenha = fopen(auxnovasenha, "w"); // faz a abertura do arquivo em modo de escrita para criação da nova senha
                        fclose(trocasenha); // fecha o arquivo de texto nova senha
                        remove(auxsenha); // Exclui a senha antiga
                        system("msg * SENHA ALTERADA COM SUCESSO!"); // Apresenta uma mensagem na tela do usuario
                        goto iniciar; // Direciona o usuario para a tela inicial.
                    }else{
                        system("msg * A SENHA DIGITADA NAO CONFERE COM A CONFIRMACAO. PROCESSO CANCELADO PELO SISTEMA!");
                        goto iniciar; // DIreciona o usuario para a tela inicial
                    }
                }else{
                    system("msg * USUARIO OU SENHA NAO CONFERE. PROCEDIMENTO INTERROMPIDO PELO SISTEMA!");
                    goto iniciar; // Direciona o usuario para a tela inicial
                }
                printf("\n   DESEJA CANCELAR A OPERACAO? [0 - NAO / 1 - SIM]: ");
                scanf("%d", &confirma);
                lform(); // linha formatada
                if(confirma == 0){
                    system("msg * PROCEDIMENTO CANCELADO PELO USUARIO!"); // Apresenta uma mensagem na tela do usuario
                    goto iniciar; // Direciona o usuario para o menu iniciar
                }
            }
            goto iniciar; // Direciona o usuario para o menu inicial
        }else{
            system("msg * ALTERNATIVA INVALIDA. TENTE NOVAMENTE!");
            goto iniciar; // Direciona o usuario para o menu inicial
        }
    return 0; // Retorna erros se houverem
}



// |============================================================================================================================| //
// |==================================================== BLOCO DE FUNCOES ======================================================| //
// |============================================================================================================================| //


// Função que fará a concatenação das informaçõs e adicionara no bloco de notas para a criação de uma OS.
void concatena_string(char tipasta[35], char titratados[45], char OS[15], char categoria[25], char id[7], char informe[25], char detalhar[255]){
    FILE *file; // Variavel do tipo FILE
    strcat(tipasta, OS); // Concatena o numero da OS com a localidade da pasta
    strcat(tipasta, ".txt"); // Concatena a extensão arquivo
    strcat(titratados, OS); // Concatena o numero da OS com a localidade da pasta
    strcat(titratados, ".txt"); // Concatena a extensão arquivo
    file = fopen(tipasta, "a"); // Abre o arquivo de texto em modo de edição
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      DATA - HORA DE ABERTURA.....................: ", file);
    fclose(file);
    incluirdatahora(tipasta); // Inclui a data de e hora atual dentro do arquivo a ser editado.
    file = fopen(tipasta, "a");
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      ORDEM DE SERVICO............................: TI", file);
    fputs(OS, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      CHAMADO PARA................................: ", file);
    fputs(categoria, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      RESPONSAVEL PELA ABERTURA...................: ", file);
    fputs(id, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      SISTEMA AFETADO.............................: ", file);
    fputs(informe, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      RESENHA.....................................: ", file);
    fputs(detalhar, file);
    fputs("\n\n  ------------------------------------------------------------------------------------------------------------------", file);
    fclose(file); // fecha o arquivo de texto
    file = fopen(titratados, "a"); // Abre o arquivo de texto para OS concluida / historico
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      DATA - HORA DE ABERTURA.....................: ", file);
    fclose(file);
    incluirdatahora(titratados); // Inclui a data de e hora atual dentro do arquivo a ser editado.
    file = fopen(titratados, "a");
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      ORDEM DE SERVICO............................: TI", file);
    fputs(OS, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      CHAMADO PARA................................: ", file);
    fputs(categoria, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      RESPONSAVEL PELA ABERTURA...................: ", file);
    fputs(id, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      SISTEMA AFETADO.............................: ", file);
    fputs(informe, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      RESENHA.....................................: ", file);
    fputs(detalhar, file);
    fputs("\n\n  ------------------------------------------------------------------------------------------------------------------", file);
    fclose(file); // Fecha o arquivo de texto
}

// Funcao para incluir data e hora dos agendamentos
void incluirdatahora(char cm[50]){
    FILE *file; // Declaração de variavel do tipo FILE.
    struct tm *dataloc; //ponteiro para struct que armazena data e hora
    time_t segundos; //variável do tipo time_t para armazenar o tempo em segundos
    time(&segundos); //obtendo o tempo em segundos
    dataloc = localtime(&segundos); //Para converter de segundos para o tempo local utilizamos a função localtime
    time(&segundos); //obtendo o tempo em segundos
    dataloc = localtime(&segundos);
    char shra[3] = "", smin[3] = "", ssec[3] = "", sdia[3] = "", smes[3] = "", sano[5] = ""; // Variavel local do tipo char para a data / hora
    itoa(dataloc->tm_hour, shra, 10); // Converte a hora atual de inteiro para string
    itoa(dataloc->tm_min, smin, 10); // Converte o minuto atual de inteiro para string
    itoa(dataloc->tm_sec, ssec, 10); // Converte o segundo atual de inteiro para string
    itoa(dataloc->tm_mday, sdia, 10); // Converte o dia atual de inteiro para string
    itoa(dataloc->tm_mon+1, smes, 10); // Converte o mes atual de inteiro para string
    itoa(dataloc->tm_year+1900, sano, 10); // Converte o ano atual de inteiro para string
    file = fopen(cm, "a"); // Abre o arquivo de texto em modo de inclusão de dados
    fputs(shra, file);
    fputs(":", file);
    fputs(smin, file);
    fputs(":", file);
    fputs(ssec, file);
    fputs(" - ", file);
    fputs(sdia, file);
    fputs("/", file);
    fputs(smes, file);
    fputs("/", file);
    fputs(sano, file);
    fclose(file); // Fecha o arquivo de texto
}

//Funcao para limpar o buffer do teclado
void lb(void){
    char x; // Declaração de variavel do tipo char
    while((x = getchar()) != '\n' && x != EOF); // Enquanto x for diferente de ENTE(\n) e diferente do final da leitura de um arquivo (EOF) ele pegará as informações
}

// Função para realizar a leitura de uma senha.
char** lersenha(char senha[9]){
    char digito_senha; // Declaração de variavel do tipo char
    int cont = 0; // Declaração de variavel do tipo inteiro
    do{
        digito_senha = getch(); // A variavel digito_senha receberá o digito informado pelo usuario
        if(isprint(digito_senha)){ // Verifica se o caractere acrescentado pelo usuario pode ser imprimido na tela
            senha[cont] = digito_senha; // A senha recebe o caractere digitado pelo usuario se este puder ser imprimido
            cont++; // Contador recebe +1
            printf("*"); // Se o digito for imprimivel será apresentado o asterisco na tela do usuario
        }else if(digito_senha == 8 && cont){ // Verifica se o digito foi 8, este é o valor char de BACKSPACE na tabela ASCII
            senha[cont]='\0';
            cont--; // Contador recebe -1
            printf("\b \b");  // Apaga 1 Caractere que foi apresentado na tela(apagará 1 asterisco)
        }
    }while(digito_senha!=13); // Enquanto o digito que o usuario informou for diferente de 13, este é o valor char de ENTER na tabela ASCII
    senha[cont]='\0';
    return &senha; // Retorna o endereço da senha
}

// Funcao cria senha e login padrao
void createloginsenha(char creatediretlogin[50], char creatediretsenha[50],char loginass[60], char cpf[12]){
    //Concatenação para criação de login e senha
    //CRIANDO LOGIN
    char infologin[60] = "", infosenha[75]= "";
    FILE *file; // Declaração de variavel do tipo FILE
    strcat(creatediretlogin, loginass); // Concatena a informação da variavel loginass na variavel creatediretlogin
    system(creatediretlogin); // Cria o diretório de login na pasta especificada
    strcat(creatediretsenha, loginass); // Concatena a informação da variavel loginas na variavel createdirectsenha
    strcat(creatediretsenha, "\\"); // Concatena a barra de separação de diretórios do windows na variavel createdirectsenha
    strcat(creatediretsenha, cpf); // Concatena o CPF para criação da senha padrão na variavel createdirectsenha
    system(creatediretsenha); // Cria o diretório da senha padrão
    strcat(infologin, "system-moderadores\\logins\\"); // Concatena o caminho da pasta que conterá o login
    strcat(infologin, loginass); // Concatena a variavel de login
    strcat(infologin, "\\"); // Concatena a variavel de login
    strcat(infologin, loginass); // Concatena a variavel de login
    strcat(infologin, ".txt"); // Concatena a extensão .txt
    file = fopen(infologin, "w"); // Cria o arquivo de login
    fclose(file); // fecha o arquivo de login
    // CRIANDO SENHA PADRAO
    strcat(infosenha, "system-moderadores\\logins\\"); // Concatena o caminho da pasta que contera o login e senha
    strcat(infosenha, loginass); // Concatena o CPF do usuario para a criação da pasta
    strcat(infosenha, "\\"); // Adiciona a barra de separação de diretorios
    strcat(infosenha, cpf); // Concatena o CPF para criação de senha padrão
    strcat(infosenha, "\\"); // Adiciona a barra de separação de diretorios
    strcat(infosenha, cpf); // Concatena o CPF para criação de senha padrão
    strcat(infosenha, ".txt"); // Concatena a extensão .txt
    file = fopen(infosenha, "w"); // Cria a senha padrão
    fclose(file); // Fecha o arquivo
}

// Funcao para apresentar uma linha formatada
void lform(){
    printf("\n  ----------------------------------------------------------------------------------------------------------------------\n");
}

// funcao para Validar usuario admin
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

// funcao para Criar login do usuario
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
void confirmacadastro(char nomePs[35], char nomeMa[35], char idade[3], char sex[10], char cpf[12], char endereco[35], char telcont[12], char ctps[12], char dipl[10], char convenio[12]){
    //Informará na tela do usuario todas as informações de cadastro que foram utilizadas para que sejam revisadas previamente a conclusão do cadastro.

    printf("                                      -- REVISAO DE INFORMACOES DO CADASTRO --                                      \n");
    printf("\n      NOME............................................: %s", nomePs);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      NOME DA MAE.....................................: %s", nomeMa);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      IDADE...........................................: %s", idade);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      SEXO............................................: %s", sex);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      CPF.............................................: %s",cpf);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      ENDERECO........................................: %s", endereco);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      TELEFONE DE CONTATO.............................: %s", telcont);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      CARTEIRA DE TRABALHO............................: %s", ctps);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      CERTIFICACAO DIPLOMA - MEDICINA.................: %s", dipl);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------");
    printf("\n      CONVENIO MEDICO.................................: %s", convenio);
    printf("\n  ----------------------------------------------------------------------------------------------------------------------\n");
}

// Funcao para validar um TELEFONE de contato
bool validaTEL(long long valor){
    int contadig = 0, resto; // Declaração de variaveis
    while(valor != 0){ // Enquanto o valor digitado não for 0 a estrutura de repetição repetira o processo de quebra do numero.
        resto = valor % 10; // pega o resto da divisão inteira de valor por 10
        valor = valor / 10; // divide o valor de entrada por 10
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
    int contadig = 0, resto; // Declaração de variaveis
    if(cpf_entrada >999999){
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
        d1 = ((n1 * 10) + (n2 * 9) + (n3 * 8) + ( n4 * 7) + (n5 * 6) + (n6 * 5) + (n7 * 4) + (n8 * 3) + (n9 * 2)) % 11;
        if(d1 < 2){ // Se o digito encontrado for menor que 2 este sempre receberá 0
           d1 = 0;
        }else{ // Se o digito encontrado for maior ou igual a 2, este será subtraido de 11(valor máximo da numeração de um CPF).
            d1 = 11 - d1;
        }
        // Processo de análise para encontrar o segundo digito verificador
        d2 = ((n1 * 11) + (n2 * 10) + (n3 * 9) + (n4 * 8) + (n5 * 7) + (n6 * 6) + (n7 * 5) + (n8 * 4) + (n9 * 3) + (d1 * 2)) % 11;
        if(d2 < 2){ // Se o digito encontrado for menor que 2 este sempre receberá 0
            d2 = 0;
        }else{ // Se o digito encontrado for maior ou igual a 2, este será subtraido de 11(valor máximo da numeração de um CPF).
            d2 = 11 - d2;
        }
        verificador = (d1 * 10) + d2; // Calculo do digito verificador;
        validar_cpf = CPF * 100 + verificador; // concatena o digito verificador com a numeração do CPF
        /* Se o CPF digitado tiver o digito verificador igual ao que foi encontrado no processo de calculo,
        este CPF será valido, caso contrário será considerado um CPF inválido.
        */
        if(validar_cpf == cpf_entrada){ // Se o CPF digitado tiver o mesmo valor do CPF que foi validado, retornará verdadeiro
            return true;
        }else{ // Se a condição do IF não for verdadeira, sera retornado um valor booleano falso para o usuario
            return false;
        }
    }else{
        return false;
    }
}

// Funcao de pausar a tela
void pause(){
    char pausar[3]; // Declaração da variavel.
    printf("\n   PRESSIONE QUALQUER TECLA PARA CONTINUAR..."); // Informa uma mensagem na tela para o usuario.
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
    int temp, num = 1, cont = 0; // Declaração de variaveis
    srand(time(NULL)); // Funcao para gerar numeros aleatórios com base na hora atual;
    while(cont != 1){ // Se o numero tiver mais de de 10 digitos ou menos de 7 a estrutura de repetição contianuará executando o processo
        temp = rand() % 200; // Gera um numero aleatório para a variavel temp
        if(temp != 0){ // Se o numero gerado for diferente de nulo d diferente de 0 a estrutura de repetição será interrompida
            num = num * temp; // Num recebera num multiplicado pelo valor contido na variavel temp
        }
        if(num > 99999999 && num < 9999999999){
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

// Funcao para cadastro de informacos basicas do usuario/paciente
char cadastrar(char initcadastro[70], char nome[40], char idadeString[5], char sexo[15], char endereco[40], char cpf[16], char telcont[20]){
    FILE *file; // Declara uma variavel do tipo FILE com um ponteiro para file.
    file = fopen(initcadastro, "a"); // Abre o arquivo de texto com que fora passado como paramentro na função para que seja possivel adicionar valores.
    //Acrescentando informaçoes no arquivo de texto.
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      NOME.............................: ", file);
    fputs(nome, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      IDADE............................: ", file);
    fputs(idadeString, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      SEXO.............................: ", file);
    fputs(sexo, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      ENDERECO.........................: ", file);
    fputs(endereco, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      CPF..............................: ", file);
    fputs(cpf, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fputs("\n      TELEFONE DE CONTATO..............: ", file);
    fputs(telcont, file);
    fputs("\n  ------------------------------------------------------------------------------------------------------------------", file);
    fclose(file); // Fecha o arquivo de texto.
}
