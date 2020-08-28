#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
    // Variaveis de loguin
    char login[8];
    char *senha[8];

    // Variaveis de cadastro e consulta

    char nome[40], endereco[40], sexo[0];
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
        printf("[1] - Cadastros Gerais.\n\n[2] - Consultas Gerais.\n\n[3] - Reclamacoes e elogios.\n\n[4] - Relatorios.\n\n[5] - Abrir chamado para a equipe de TI");
        printf("\n\n[0] - >> Sair <<\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp); // Comando de entrada responsavel por guardar a resposta na variavel "resp"

        // Bloco condicional
        if (resp == 1) {
            goto cadastros; // Salta para a tela de cadastros
        }else if (resp == 2){
            goto consultas; // Salta para a tela de consultas
        }else if (resp == 3){
            goto reclamacoes; // Salta para a tela de reclamações
        }else if (resp == 4){
            goto relatorios; // Salta para a tela de relatorios
        }else if (resp == 5){
            goto tichamados; // Salta para a tela de chamados para a equipe de Ti
        }else if (resp == 0){
            exit(0); // Encerra o programa
        }else{
            goto iniciar;
        }

//AREA - TELA DE CADASTROS GERAIS INCLUINDO CONSULTA DOS MESMOS

    cadastros:
        system("cls");
        printf("**********************************************\n");
        printf("\n*   BEM VINDO AO CADASTRO DE FUNCIONARIOS!   *\n\n");
        printf("**********************************************\n\n");
        printf("[1] - Cadastrar um novo funcionario.\n\n[2] - Cadastrar um novo paciente.\n\n[3] - Cadastrar um novo medico.\n\n");
        printf("[4] - Cadastro de agendamento clinico.\n\n");
        printf("[9] - Consultar cadastros existentes.\n\n[0] - Voltar ao menu principal.\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        if (resp == 1){
			system("cls");
            printf("Idade: ");
            scanf("%d", &idade);

            // validação de idade para cadastro

            if (idade < 18){
                char validacao;
                printf("\nEste colaborador ainda nao possui idade superior ou equivalente a 18.\nDeseja prosseguir com o cadastro mesmo assim?[S/N]: ");
                scanf("%s", &validacao);
                if (validacao == 'N' || validacao == 'n'){
                    goto iniciar;
                }else if (validacao == 'S' || validacao == 's'){
                    printf("");
                }else{
                    printf("Opcao invalida! Tente novamente.");
                    goto cadastros;
				}
            }// fim da valicidação de idade.

			// Bloco cadastro

            printf("\nNome do funcionario: ");
            scanf("%s" , &nome);
            printf("\nSexo [M/F]: ");
            scanf("%s", &sexo);
            printf("\nCPF: ");
            scanf("%d", &cpf);
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            printf("\nNumero - Carteira de trabalho: ");
            scanf("%d", &ctps);

            printf("\nColaborador cadastrado com sucesso!"); // Finaliza cadastro informando sucesso para o usuario.

            goto cadastros; // Salta diretamente para a tela de cadastros.

        }else if (resp == 2){

            // Cadastro do paciente

            char nomemae[40]; // Variavel Local.
            int numconvenio, telefonecontato;// Variavel Local

            system("cls");
            printf("\nNome do paciente: ");
            scanf("%s", &nome);
            printf("\nIdade do paciente: ");
            scanf("%d", &idade);
            printf("\nSexo [M/F]: ");
            scanf("%s", &sexo);
            printf("\nNumero - Cartao de convenio(Ou 0 se nao houver): ");
            scanf("%d", &numconvenio);
            printf("\nNome da Mae: ");
            scanf("%s", &nomemae);
            printf("\nTelefone contato com DDD(sem espacos): ");
            scanf("%d", &telefonecontato);

            printf("Cliente cadastrado com sucesso!"); // Fim Cadastro do paciente

            goto cadastros; // Salta para a tela de cadastros

        }else if (resp == 3){

            // Cadastro do médico

            int diploma; // Variavel Local

            system("cls");
            printf("Idade: ");
            scanf("%d", &idade);

            // validação de idade para cadastro

            if (idade < 21){
                char validacao;
                printf("\nEste colaborador ainda nao possui idade superior ou equivalente a 21 anos.\nNao pode ser cadastrado!\n");
                system("pause");
                goto cadastros;
            } // Fim validação de idade

            printf("\nNome do medico: ");
            scanf("%s" , &nome);
            printf("\nSexo [M/F]: ");
            scanf("%s", &sexo);
            printf("\nCPF: ");
            scanf("%d", &cpf);
            printf("\nEndereco: ");
            scanf("%s", &endereco);
            printf("\nNumero - Carteira de trabalho: ");
            scanf("%d", &ctps);
            printf("\nNumeracao do diploma em medicina: ");
            scanf("%d", &diploma);

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
        printf(" **********************************************\n\n");
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
        printf(" **********************************************\n\n");
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

    tichamados:
        system("cls");
        printf("**********************************************\n");
        printf("\n*    BEM VINDO A AREA CHAMADOS INTERNOS!     *\n\n");
        printf("**********************************************\n\n");
        printf("[1] - Registrar um novo chamado.\n\n[2] - Consultar um chamado existente.\n\n[3] - Cancelar um chamado existente.\n\n");
        printf("[4] - Reabrir chamado encerrado indevidamente.\n\n[0] - Voltar ao menu inicial\n\n");
        printf("Resposta -> ");
        scanf("%d", &resp);

        int tipofalha;		// Variavel local
		char sistemaafetado[35], resumofalha[100], localfalha[30], resplocal; // Variavel local
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
