#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h> // Biblioteca para usar acentos no programa

int main(void){
    setlocale(LC_ALL,""); // código para setar os acentos no programa

    // Variaveis globais.
    FILE *file;
    char nome[40], endereco[40], sexo[10], cadastro[50], ext[5] = ".txt";
    char cpf[12], ctps[25], idadeString[20], telefonecontato[15] = "";
    int idade;

    iniciar:
        system("cls");
        printf("**********************************************\n");
        printf("\n*         BEM VINDO AO MENU INICIAL!         *\n\n");
        printf("**********************************************\n\n");
        int resp;
        printf("[1] - Cadastros Gerais.\n\n[2] - Consultas Gerais.\n\n[3] - Reclamacoes e elogios.\n\n[4] - Relatorios.\n\n[5] - Abrir chamado para a equipe de TI");
        printf("\n\n[0] - >> Sair <<\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp); // Comando de entrada responsavel por guardar a resposta na variavel "resp"

        // Bloco de escolha
        switch(resp){
            case 1:
                goto cadastros; // Salta para a tela de cadastros
                break;
            case 2:
                goto consultas; // Salta para a tela de consultas
                break;
            case 3:
                goto reclamacoes; // Salta para a tela de reclamações
                break;
            case 4:
                goto relatorios; // Salta para a tela de relatorios
                break;
            case 5:
                goto tichamados; // Salta para a tela de chamados para a equipe de Ti
                break;
            case 0:
                exit(0); // Encerra o programa
                break;
            default:
                goto iniciar; // Salta para o inicio
                break;
        }

//AREA - TELA DE CADASTROS GERAIS INCLUINDO CONSULTA DOS MESMOS
    cadastros:
        system("cls");
        printf("**********************************************\n");
        printf("\n*   BEM VINDO AO CADASTRO DE FUNCIONARIOS!   *\n\n");
        printf("**********************************************\n\n");
        printf("[1] - Cadastrar um novo funcionario.\n\n[2] - Cadastrar um novo paciente.\n\n[3] - Cadastrar um novo medico.\n\n");
        printf("[4] - Cadastro de agendamento clinico.\n\n");
        printf("[0] - Voltar ao menu principal.\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        // Bloco condicional
        if (resp == 1){
            char cadastro[50] = "";
			system("cls");
            printf("Idade: ");
            scanf("%d", &idade);

            // validação de idade para cadastro
            if (idade < 18){
                    // Declaração de variavel
                char validacao;

                    // Entrada de dados do usuario
                printf("\nEste colaborador ainda nao possui idade superior ou equivalente a 18.\nDeseja prosseguir com o cadastro mesmo assim?[S/N]: ");
                scanf("%s", &validacao);

                    //Bloco condicional
                if (validacao == 'N' || validacao == 'n'){ // Se o usuario optar por não cadastrar o menor de idade, o mesmo sera direcionado para o menu iniciar
                    goto iniciar; // Direciona o usuario para o menu iniciar caso a opcao seja verdadeira.
                }else if (validacao == 'S' || validacao == 's'){
                    printf("");
                }else{
                    printf("Opcao invalida! Tente novamente. ");
                    system("pause");
                    goto cadastros; // Direciona o usuario para o bloco de cadastros caso seja inserida uma opcao invalida
				}
            }
            // fim da valicidação de idade.

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
            strcat(cadastro, cpf); // Concatena o cpf no cadastro
            strcat(cadastro, ext); // Concatena o cpf com a extensão txt no cadastro;
            file = fopen(cadastro, "a"); // Abre o arquivo para adicionar valores.

            //Acrescentando informaçoes no arquivo de texto.
            fputs("NOME: ", file);
            fputs(nome, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nIDADE: ", file);
            fputs(idadeString, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nSEXO: ", file);
            fputs(sexo, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nENDERECO: ", file);
            fputs(endereco, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nCARTEIRA DE TRABALHO: ", file);
            fputs(ctps, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nCPF: ", file);
            fputs(cpf, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nTELEFONE DE CONTATO: ", file);
            fputs(telefonecontato, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nTIPO: FUNCIONARIO", file);
            fputs("\n", file);
            fputs("----------------------------------------------------\n", file);
            fclose(file); // Fecha o arquivo de texto
            printf("\nColaborador cadastrado com sucesso!\n"); // Finaliza cadastro informando sucesso para o usuario.

            system("pause"); // Para a tela para que o usuario seja capaz de visualizar as informações
            goto cadastros; // Salta diretamente para a tela de cadastros.

        }else if (resp == 2){
            char cadastro[50] = "";
            char nomemae[40];
            char numconvenio[25], telefonecontato[15] = "";
            system("cls");

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
            strcat(cadastro, cpf); // Acrescenta o CPF a variavel de cadastro
            strcat(cadastro, ext); // Concatena o cpf com a extensão txt a variavel de cadastro;
            file = fopen(cadastro, "a"); // Abre o arquivo para adicionar valores.

            //Acrescentando informaçoes no arquivo de texto.
            fputs("NOME: ", file);
            fputs(nome, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nNOME DA MAE: ", file);
            fputs(nomemae, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nIDADE: ", file);
            fputs(idadeString, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nSEXO: ", file);
            fputs(sexo, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nENDERECO: ", file);
            fputs(endereco, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nCARTAO DE CONVENIO: ", file);
            fputs(numconvenio, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nCPF: ", file);
            fputs(cpf, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nTELEFONE DE CONTATO: ", file);
            fputs(telefonecontato, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nTIPO: PACIENTE", file);
            fputs("\n", file);
            fputs("----------------------------------------------------\n", file);
            fclose(file); // Fecha o arquivo
            printf("Cliente cadastrado com sucesso!"); // Fim Cadastro do paciente

            system("pause"); // Pausa a tela para que o usuario seja capaz de visualizar as informaçoes;
            goto cadastros; // Direciona o usuario para tela de cadastros

        }else if (resp == 3){
            system("cls");

            // Declaração de variavel local
            char telefonecontato[15] = "";
            char cadastro[50] = "";
            char diploma[20];

            // Cadastro do médico
            printf("Idade: ");
            scanf("%d", &idade);

            // validação de idade para cadastro
            if (idade < 21){
                char validacao;
                printf("\nEste colaborador ainda nao possui idade superior ou equivalente a 21 anos.\nNao pode ser cadastrado!\n");
                system("pause");
                goto cadastros;
            }
            // Fim validação de idade

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
            printf("\nNumeracao do diploma em medicina: ");
            scanf("%s", &diploma);

            itoa(idade, idadeString, 10); // Converte um inteiro para String.
            strcat(cadastro, cpf); // Acrescenta o CPF a variavel de cadastro
            strcat(cadastro, ext); // Concatena o cpf com a extensão;
            file = fopen(cadastro, "a"); // Abre o arquivo para adicionar valores.

            //Acrescentando informaçoes no arquivo de texto.
            fputs("NOME: ", file);
            fputs(nome, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nIDADE: ", file);
            fputs(idadeString, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nSEXO: ", file);
            fputs(sexo, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nENDERECO: ", file);
            fputs(endereco, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nCARTEIRA DE TRABALHO: ", file);
            fputs(ctps, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nCPF: ", file);
            fputs(cpf, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nNUMERACAO DO DIPLOMA MEDICO: ", file);
            fputs(diploma, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nTELEFONE DE CONTATO: ", file);
            fputs(telefonecontato, file);
            fputs("----------------------------------------------------\n", file);
            fputs("\nTIPO: MEDICO", file);
            fputs("\n", file);
            fputs("----------------------------------------------------\n", file);
            fclose(file); // Fecha o arquivo
            printf("\nMedico cadastrado com sucesso!"); // Fim do cadastro médico

            system("pause"); // Pausa a tela para que o usuario visualize as informações.
            goto cadastros; // Direciona o usuario para a tela de cadastros.

        }else if (resp == 4){
            system("cls"); // Limpa a tela

            // Declarando variaveis
            char datahora[10], cadastro[50] = "";

            // Entrada de dados do usuario
            printf("Nome do paciente: ");
            scanf("%s", &nome);
            printf("\nCPF do paciente: ");
            scanf("%s", &cpf);
            printf("\nHorario de agendamento(formato hh:mm:ss): ");
            scanf("%s", &datahora);
            printf("\nGerando ordem de serviço... ");

            srand(time(NULL)); // Funcao para gerar numeros aleatórios;

            // Declaração de variaveis para o for e o While
            int i, n;
            char os[15], fn[15];
            while(n <= 99999999){
                for (i = 0; i <=10; i++){ // Gera 10 numero aleatorios
                    n *= rand() % 100; // N recebera ele mesmo multiplicado pelo numero aleatório gerado
                }
            }
            itoa(n, os, 10); // Converte os varelos de inteiros para string
            printf("Numero da OS: %s\n", os); // Informa ao usuario o numero gerado
            strcat(cadastro, "C:\\Users\\BC731459\\Desktop\\Linguagem C\\PIM\\agendamentos\\"); // Acrescenta o caminho de onde serão salvos as informações
            strcat(cadastro, os);
            strcat(cadastro, ext);

            file = fopen(cadastro, "a"); // Abre o arquivo de texto.
            fputs("Nome do paciente: ", file);
            fputs(nome, file);
            fputs("\n----------------------------------------------------\n", file);
            fputs("CPF DO PACIENTE: ", file);
            fputs(cpf, file);
            fputs("\n----------------------------------------------------\n", file);
            fputs("HORARIO DO AGENDAMENTO: ", file);
            fputs(datahora, file);
            fputs("\n----------------------------------------------------\n", file);
            fputs("ORDEM DE SERVICO: ", file);
            fputs(os, file);
            fputs("\n----------------------------------------------------\n", file);
            fclose(file); // Fecha o arquivo de texto

            printf("\nAgendamento concluido com sucesso!\n");
            system("pause"); // Pausa a tela para o usuario conseguir visualizar as informações.
            goto cadastros;

        }else if (resp == 0){
            goto iniciar;
        }else{
            goto cadastros;
        }

// TELA DE CONSULTAS GERAIS
    consultas:
        system("cls");
        printf("**********************************************\n");
        printf("\n*       BEM VINDO A AREA DE CONSULTAS!       *\n\n");
        printf(" **********************************************\n\n");
        printf("[1] - Consultar ficha de um colaborador[medico | funcionario].\n\n[2] - Consultar ficha do cliente.\n\n");
        printf("[3] - Consultar agendamentos.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        // Bloco Condicional
        if (resp == 1){
            system("cls"); // limpa a tela

            //Declaração de variavel
            char cadastro[50] = "", frase[500];

            // Entrada de dados
            printf("CPF a ser consultado: ");
            scanf("%s", &cadastro);
            printf("\n");
            //Concatenação da string com a extensão txt
            strcat(cadastro, ext);
            file = fopen(cadastro, "r");
            if(file == NULL){
                printf("Arquivo nao localizado!\n");
                exit(0);
            }
            while(fgets(frase, 500, file) != NULL){
                printf("%s", frase);
            }
            fclose(file);
            system("pause");
            goto cadastros;

        }else if (resp == 2){
            system("cls"); // limpa a tela

            //Declaração de variavel
            char cadastro[50] = "", frase[500];

            // Entrada de dados
            printf("CPF a ser consultado: ");
            scanf("%s", &cadastro);
            printf("\n");
            //Concatenação da string com a extensão txt
            strcat(cadastro, ext);
            file = fopen(cadastro, "r");
            if(file == NULL){
                printf("Arquivo nao localizado!\n");
                exit(0);
            }
            while(fgets(frase, 500, file) != NULL){
                printf("%s", frase);
            }
            fclose(file);
            system("pause"); // Pausa a tela para o usuario conseguir absorver as informaçoes
            goto cadastros;

        }else if (resp == 3){
            system("cls");
            // Declaracao da variavel;
            char os[15] = "", frase[500];

            //Entrada de dados do usuario
            printf("Digite o numero da ordem de servico do agendamento clinico: ");
            scanf("%s", &os);
            strcat(cadastro, "C:\\Users\\BC731459\\Desktop\\Linguagem C\\PIM\\agendamentos\\");
            strcat(cadastro, os);
            strcat(cadastro, ext);

            file = fopen(cadastro, "r"); // Abre o arquivo de texto
            if(file == NULL){
                printf("Arquivo nao localizado!\n");
                exit(0);
            }
            while(fgets(frase, 500, file) != NULL){
                printf("%s", frase);
            }
            fclose(file);
            printf("\n")
            system("pause"); // Pausa a tela para o usuario conseguir ler as informaçoes;

        }else if (resp == 0){
            goto iniciar;
        }else{
            goto consultas;
        }

//TELA - AREA DE RECLAMACOES E SUGESTOES
    reclamacoes:
        system("cls");
        printf("**********************************************\n");
        printf("\n*       BEM VINDO A AREA DE SUGESTOES!       *\n\n");
        printf(" **********************************************\n\n");
        printf("[1] - Registrar uma reclamacao.\n\n[2] - Consultar uma reclamacao.\n\n[3] - Registar um elogio.\n\n");
        printf("[4] - Consultar um elogio.\n\n[5] - Registar uma sugestao.\n\n[6] - Consultar uma sugestao.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        // Bloco condicional
        if (resp == 1){

        }else if (resp == 2){

        }else if (resp == 3){

        }else if (resp == 4){

        }else if (resp == 5){

        }else if (resp == 6){

        }else if (resp == 0){
            goto iniciar;
        }else{
            goto reclamacoes;
        }

//TELA - ABA DE RELATORIOS
    relatorios:
        system("cls");
        printf("**********************************************\n");
        printf("\n*      BEM VINDO A AREA DE RELATORIOS!       *\n\n");
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
        system("cls");
        printf("**********************************************\n");
        printf("\n*    BEM VINDO A AREA CHAMADOS INTERNOS!     *\n\n");
        printf("**********************************************\n\n");
        printf("[1] - Registrar um novo chamado.\n\n[2] - Consultar um chamado existente.\n\n[3] - Cancelar um chamado existente.\n\n");
        printf("[4] - Reabrir chamado encerrado indevidamente.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        // Declaração de variavel local
        int tipofalha;
		char sistemaafetado[35], resumofalha[255], localfalha[30], resplocal;

		// Bloco condicional
        system("cls");
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
                printf("Tipo de falha nao localizado ou inexistente. Tente novamente.");
                goto tichamados;
            }
        }else if (resp == 2){

        }else{
            printf("Opcao inexistente");
            goto tichamados;
        }
}
