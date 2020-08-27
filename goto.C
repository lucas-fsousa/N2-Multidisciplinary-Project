#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
    // Variaveis de loguin
    char login[8];
    char *senha[8];

    // Variaveis de cadastro e consulta

    char nome[40], endereco[40], sexo[10], cadastro[10];
    int idade, cpf, ctps;


    /*
    telalog:
    printf("Digite seu login -> ");
    scanf("%s", &login);
    printf("\nDigite sua senha -> ");
    scanf("%s", &senha);
    */
// MENU INICIAR

    iniciar:
        system("cls");
        printf("**********************************************\n");
        printf("\n*         BEM VINDO AO MENU INICIAL!         *\n\n");
        printf("**********************************************\n\n");
        int resp;
        printf("[1] - Cadastros Gerais.\n\n[2] - Consultas Gerais.\n\n[3] - Reclamacoes e elogios.\n\n[4] - Relatorios.\n\n[0] - >> Sair <<\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);
        if (resp == 1) {
            goto cadastros;
        }else if (resp == 2){
            goto consultas;
        }else if (resp == 3){
            goto reclamacoes;
        }else if (resp == 4){
            goto relatorios;
        }else if (resp == 0){
            exit(0);
        }else{
            goto iniciar;
        }

//AREA - TELA DE CADASTROS GERAIS INCLUINDO CONSULTA DOS MESMOS

    cadastros:
        system("cls");
        printf("**********************************************\n");
        printf("\n*   BEM VINDO AO CADASTRO DE FUNCIONARIOS!   *\n\n");
        printf("**********************************************\n\n");
        printf("[1] - Cadastrar um novo funcionario.\n\n[2] - Cadastrar um novo paciente.\n\n[3] - Cadastrar um novo médico.\n\n");
        printf("[4] - Cadastro de agendamento clinico.\n\n");
        printf("[9] - Consultar cadastros existentes.\n\n[0] - Voltar ao menu principal.\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        if (resp == 1){
                system("cls");
                printf("\nNome do funcionario: ");
                scanf("%s" , &nome);
                printf("Idade: ");
                scanf("%d", &idade);

                // VALIDACAO DE IDADE PARA CADASTRO

                if (idade < 18){
                    char validacao;
                    printf("Este colaborador ainda nao possui idade superior ou equivalente a 18.\nDeseja prosseguir com o cadastro mesmo assim?[S/N]: ");
                    scanf("%s", &validacao);
                    if (validacao == 'N' || validacao == 'n'){
                        goto iniciar;
                    }else if (validacao == 'S' || validacao == 's'){
                        printf("");
                    }else{
                        printf("Opcao invalida! Tente novamente.");
                        goto cadastros;
                    }
                }
                // FIM DA VALIDACAO DE IDADE

                printf("Sexo [Masculino/Feminino]: ");
                scanf("%s", &sexo);
                printf("CPF: ");
                scanf("%d", &cpf);
                printf("Endereco: ");
                scanf("%s", &endereco);
                printf("Numero - Carteira de trabalho: ");
                scanf("%d", &ctps);
                printf("Colaborador cadastrado com sucesso!");
                goto cadastros;

        }else if (resp == 2){

        }else if (resp == 3){

        }else if (resp == 4){

        }else if (resp == 9){

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
        printf("**********************************************\n\n");
        printf("[1] - Consultar ficha do funcionario.\n\n[2] - Consulta ficha do medico.\n\n[3] - Consultar ficha do cliente.\n\n");
        printf("[4] - Consultar agendamentos pendentes.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        if (resp == 1){

        }else if (resp == 2){

        }else if (resp == 3){

        }else if (resp == 4){

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
        printf("**********************************************\n\n");
        printf("[1] - Registrar uma reclamacao.\n\n[2] - Consultar uma reclamacao.\n\n[3] - Registar um elogio.\n\n");
        printf("[4] - Consultar um elogio.\n\n[5] - Registar uma sugestao.\n\n[6] - Consultar uma sugestao.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

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
}
