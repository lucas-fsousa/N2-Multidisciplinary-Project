#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdexcept>
#include <stdbool.h>
#include <locale.h> // Biblioteca para usar acentos no programa

// Funcao de pausar a tela
void pause(){
    char pausar[3];
    printf("\nPressione qualquer tecla para continuar...\n");
    scanf("%c", &pausar);
    getchar();
}

// Funcao de limpar tela
void limpatela(){
    if (system("cls")){
        system("clear");
    }else{
        system("cls");
    }
}

// Funcao de gear numero aleatorio
int gerarOS(){
    srand(time(NULL)); // Funcao para gerar numeros aleatórios;
    int i, num;
    char os[15], fn[15];
    while(num <= 999999 || num > 9999999999){
        for (i = 0; i <=10; i++){ // Gera 10 numero aleatorios
            num *= rand() % 100; // Num recebera ele mesmo multiplicado pelo numero aleatório gerado
        }
    }
    return num;
}

// Funcao que le as informacoes no bloco de texto.
char leitura(char ler[70]){
    FILE *file;
    char frase[500];
    file = fopen(ler, "r");
    if(file == NULL){
        return 1;
    }
    while(fgets(frase, 500, file) != NULL){
        printf("%s", frase);
    }
    fclose(file);
    return 0;
}

char cadastrar(char initcadastro[70], char nome[40], char idadeString[5], char sexo[15], char endereco[40], char cpf[16], char telcont[20]){
    FILE *file;
    file = fopen(initcadastro, "a"); // Abre o arquivo para adicionar valores.

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
    fclose(file);
}

// Codigo principal
int main(void){
    iniciar:
    setlocale(LC_ALL,""); // código para setar os acentos no programa
    // Variaveis globais.
    FILE *file;
    char nome[40] = "", endereco[40] = "", sexo[10] = "", ext[5] = ".txt";
    char cpf[12] = "", ctps[25] = "", telefonecontato[15] = "";
    char frase[500] = "";
    int idade;
        limpatela();
        printf("**********************************************\n");
        printf("*         BEM VINDO AO MENU INICIAL!         *\n");
        printf("**********************************************\n\n");
        int resp;
        printf("[1] - Cadastros Gerais.\n\n[2] - Consultas Gerais.\n\n[3] - Reclamacoes e elogios.\n\n[4] - Relatorios.\n\n[5] - Abrir chamado para a equipe de TI");
        printf("\n\n[0] - >> Sair <<\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp); // Comando de entrada responsavel por guardar a resposta na variavel "resp"
        // Bloco de escolha
        switch(resp){
            case 1:
                goto cadastros;
                break;
            case 2:
                goto consultas;
                break;
            case 3:
                goto reclamacoes;
                break;
            case 4:
                goto relatorios;
                break;
            case 5:
                goto tichamados;
                break;
            case 0:
                printf("Saindo do sistema... Até logo!\n");
                exit(0);
                break;
            default:
                printf("Resposta inválida!! Tente novamente.");
                pause();
                goto iniciar;
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
            char cadastroFunc[50] = "", idadeString[20] = ""; //Declaracao de variavel local
			limpatela(); // Limpa a tela
			//Entrada de dados do usuario.
            printf("Idade: ");
            scanf("%d", &idade);
            // validação de idade para cadastro
            if (idade < 21){
            // Entrada de dados do usuario
                printf("\nEste colaborador ainda nao possui idade superior ou equivalente a 21.\n");
                pause();
                goto iniciar;
            }
            // Bloco cadastro com entrada de dados do usuario
            printf("\nNome do funcionario: ");
            scanf("%s" , &nome);
            printf("\nSexo [Masculino/Feminino]: ");
            scanf("%s", &sexo);
            printf("\nCPF: ");
            scanf("%s", &cpf);
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            printf("\nTelefone contato com DDD(sem espacos): ");
            scanf("%s", &telefonecontato);
            printf("\nNumero - Carteira de trabalho: ");
            scanf("%s", &ctps);
            itoa(idade, idadeString, 10); // Converte um inteiro para String.
            system("mkdir funcionarios\\");
            strcat(cadastroFunc, "funcionarios\\");
            limpatela();
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
            printf("\nColaborador cadastrado com sucesso!\n"); // Finaliza cadastro informando sucesso para o usuario.
            pause(); // Para a tela para que o usuario seja capaz de visualizar as informações
            goto iniciar; // Salta diretamente para a tela de inicio.
        }else if (resp == 2){
            char cadastroPac[50] = "", idadeString[20] = ""; //Declaracao de variavel local
            char nomemae[40]; // Declaracao de variavel local
            char numconvenio[25]; // Declaracao de variavel local
            limpatela();
            // Entrada de dados do usuario para cadastro do paciente
            printf("\nNome do paciente: ");
            scanf("%s", &nome);
            printf("\nIdade do paciente: ");
            scanf("%d", &idade);
            printf("\nSexo [Masculino/Feminino]: ");
            scanf("%s", &sexo);
            printf("\nNumero - Cartao de convenio(Ou 0 se nao houver): ");
            scanf("%s", &numconvenio);
            printf("\nNome da Mae: ");
            scanf("%s", &nomemae);
            printf("\nTelefone contato com DDD(sem espacos): ");
            scanf("%s", &telefonecontato);
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            printf("\nCPF: ");
            scanf("%s", &cpf);
            itoa(idade, idadeString, 10); // Converte um inteiro para String.
            system("mkdir pacientes\\");
            strcat(cadastroPac, "pacientes\\");
            limpatela();
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
            limpatela();
            char cadastromed[50] = "", idadeString[20] = "", diploma[20] = ""; //Declaracao de variavel local
            printf("Idade: ");
            scanf("%d", &idade);
            // validação de idade para cadastro
            if(idade < 21){
                printf("Esta pessoa não possui idade superior ou equivalente a 21 anos.");
                pause();
                goto iniciar; // Direciona o usuario para a tela de inicio
            }
            // Entrada de dados do usuario
            printf("\nNome do medico: ");
            scanf("%s" , &nome);
            printf("\nSexo [Masculino/Feminino]: ");
            scanf("%s", &sexo);
            printf("\nCPF: ");
            scanf("%s", &cpf);
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            printf("\nNumero - Carteira de trabalho: ");
            scanf("%s", &ctps);
            printf("\nTelefone contato com DDD(sem espacos): ");
            scanf("%s", &telefonecontato);
            printf("\nNumeracao do diploma em medicina: ");
            scanf("%s", &diploma);
            itoa(idade, idadeString, 10); // Converte um inteiro para String.
            system("mkdir funcionarios\\");
            limpatela;
            strcat(cadastromed, "funcionarios\\");
            strcat(cadastromed, cpf); // Concatena o cpf no cadastro
            strcat(cadastromed, ext); // Concatena o cpf com a extensão txt no cadastro;
            //Acrescentando informaçoes basicas de cadastro no arquivo de texto.
            cadastrar(cadastromed, nome, idadeString, sexo, endereco, cpf, telefonecontato);
            //Acrescentando demais informacoes no cadastro.
            file = fopen(cadastromed, "a");
            fputs("\nCARTEIRA DE TRABALHO: ", file);
            fputs(ctps, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nNUMERACAO DO DIPLOMA MEDICO: ", file);
            fputs(diploma, file);
            fputs("\n----------------------------------------------------", file);
            fputs("\nTIPO: MEDICO", file);
            fputs("\n----------------------------------------------------", file);
            fclose(file); // Fecha o arquivo
            printf("\nMedico cadastrado com sucesso!\n"); // Fim do cadastro médico
            pause(); // Pausa a tela para que o usuario visualize as informações.
            goto iniciar; // Direciona o usuario para a tela de inicio.
        }else if (resp == 4){
            limpatela(); // Limpa a tela
            char data[15] = "", hora[15] = "",cadastroOS[50] = "", verificapaciente[50] = "", os[15] = "", auxiliarOS[50] = ""; // Declarando variaveis locais
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
            char consultaficha[50] = ""; //Declaração de variavel local
            // Entrada de dados
            printf("CPF a ser consultado: ");
            scanf("%s", &cpf);
            printf("\n");
            //Concatenação da string com a extensão txt
            strcat(consultaficha, "funcionarios\\");
            strcat(consultaficha, cpf);
            strcat(consultaficha, ext);
            leitura(consultaficha);
            pause(); // Pausa a tela para o usuario.
            goto iniciar; // Salta para o menur iniciar.
        }else if (resp == 2){
            limpatela(); // limpa a tela
            char consultaPac[50] = "", frase[500] = ""; //Declaração de variavel local
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
                goto iniciar;
            }
            while(fgets(frase, 500, file) != NULL){
                printf("%s", frase);
            }
            fclose(file);
            pause(); // Pausa a tela para o usuario conseguir absorver as informaçoes
            goto iniciar;
        }else if (resp == 3){
            limpatela();
            // Declaracao da variavel;
            char consultarOS[50] = "", digitoOS[25] = "", baixaOS[40] = "";
            //Entrada de dados do usuario
            printf("Digite o numero da ordem de servico do agendamento clinico: ");
            scanf("%s", &digitoOS);
            strcat(consultarOS, "agendamentos\\");
            strcat(consultarOS, digitoOS);
            strcat(consultarOS, ext);
            if(leitura(consultarOS) == 1){
                printf("Esta ordem de servico não foi localizada. Talvez tenha sido concluida, portanto verifique no histórico.");
                pause();
                goto iniciar;
            }
            printf("\n");
            printf("Deseja dar baixa no agendamento? [0 - para SIM / 1 - para NAO]: ");
            scanf("%d", &resp);
            if (resp == 0){
                file = fopen(consultarOS, "a");
                fputs("\nSTATUS: CONCLUIDO!", file);
                fputs("\n----------------------------------------------------", file);
                fclose(file);
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
            pause(); // Pausa a tela para o usuario conseguir ler as informaçoes;
            goto iniciar;
        }else if (resp == 4){
            limpatela();
            // Declaracao da variavel;
            char consultarOS[50] = "", digitoOS[25] = "";
            //Entrada de dados do usuario
            printf("Digite o numero da ordem de servico do agendamento clinico: ");
            scanf("%s", &digitoOS);
            printf("\n");
            strcat(consultarOS, "agendamentos\\concluidos\\");
            strcat(consultarOS, digitoOS);
            strcat(consultarOS, ext);
            if(leitura(consultarOS) == 1){
                printf("Essa ordem de servico nao existe ou possui prazo de criacao superior a 365 dias e foi removida do banco.");
                pause();
                goto iniciar;
            }
            pause(); // Pausa a tela para o usuario visualizar as informacoes;
            goto iniciar;
        }else if (resp == 0){
            goto iniciar;
        }else{
            goto iniciar;
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

}
