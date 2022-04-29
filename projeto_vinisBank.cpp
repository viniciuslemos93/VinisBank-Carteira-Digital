#include<stdlib.h>
#include<string.h>
#include<locale.h>
//********* Projeto VinisBank - Praticando a Lógica e Algoritmos em C *********

//Função para validar se a opção digitada no menu está correta.
int validarOpMenu (int opMenu) {
		do {
			printf ("OPÇÃO INCORRETA! Digite Novamente:\n");
			scanf("%d", &opMenu);
		}while (opMenu < 0 || opMenu > 4);
		system ("cls");
		return opMenu;
}

//Função que valida se o usuário inseriu um valor inválido (0 ou negativo) ao realizar uma operação de pagamento ou recebimento.
float verificarValor (float dinheiro) {
		do {
			printf ("AVISO\n");
			printf ("Não é possível inserir o valor 0 ou negativo. \nInsira novamente, por favor:\nR$ ");	
			scanf("%f", &dinheiro);	
		}while (dinheiro <= 0);
		
		return dinheiro;
}

int main () {
	float saldoAtual=0, addDinheiro=0, pagamento=0, extrato [200];
	int opMenu, opMenuOperadoras, cont=0, i=0;
	char nome [50], chavePix, numCelular;
	
	setlocale(LC_ALL,""); //Função para ajustar os caracteres especiais da aplicação.
	
	printf ("*****************************************\n");
	printf ("Bem Vindo(a) ao VinisBank - Carteira Digital\n");
	printf ("*****************************************\n");
	printf ("Primeiramente, digite seu nome :=)\n");	
	gets(nome);
	system("cls");
	do {
	printf ("*****************************************\n");
	printf ("Bem Vindo(a) %s ao VinisBank - Carteira Digital\n", nome);
	printf ("*****************************************\n");		
	printf ("\t SALDO ATUAL: R$ %.2f\n", saldoAtual);
	printf ("------------------------------\n");
	
	if (saldoAtual < 0)//Valida se o saldo estiver negativo, dará uma mensagem de aviso para depositar o quanto antes, para deixar o saldo positivo.
		printf("-------AVISO - VinisBank -------\n Seu saldo esta negativo, com taxa de juros diárias.\nDeposite e normalize seu saldo o quanto antes!\n\n");
	
	printf ("DIGITE A OPÇÃO DESEJADA: \n");
	printf ("[1] - Depositar Dinheiro\n");
	printf ("[2] - Transferência PIX\n");
	printf ("[3] - Recarga de Celular\n");
	printf ("[4] - Extrato de Débitos\n");
	printf ("[0] - Sair\n");
	scanf("%d", &opMenu);
	if (opMenu < 0 || opMenu > 4)
		opMenu = validarOpMenu(opMenu);
	switch (opMenu) {
	case 1: //Opção de Depositar, alimentando a variável saldo.
		printf ("-------------------------------\n");
		printf ("Insira o valor de depósito:\n ");
		printf ("-------------------------------\nR$ ");
		scanf("%f", &addDinheiro);
		if (addDinheiro <= 0) //Validando se o valor digitado ao inserir o depósito é 0 ou negativo, caso seja, chamará a função para validar.
			addDinheiro = verificarValor (addDinheiro);			
		saldoAtual = saldoAtual + addDinheiro;//Caso o valor de depósito seja maior que 0, o saldo atual recebe o saldo atual + o valor depositado.		
		cont--;//Decrementa o cont toda vez que realiza um depósito, por que ao acessar a opção Extrato, será exibida apenas os Débitos, e nesta opção está Creditando, inserindo saldo.
		break;
	case 2: //Opção transferência PIX.
		printf ("-------------------------------\n");
		printf ("Digite a chave PIX para a transferência:\n ");		
		scanf("%s", &chavePix);
		printf ("Insira o valor da transferência:\nR$ ");
		scanf("%f", &pagamento);
		if (pagamento <= 0) //Validando se o valor digitado é 0 ou negativo, caso seja chamar a função para validar.
			pagamento = verificarValor (pagamento);
		saldoAtual = saldoAtual - pagamento;
		extrato [cont] = pagamento;
	break;
	case 3://Opção de recarga de celular.
		printf ("-------------------------------\n");
		printf ("Selecione a Operadora:\n ");
		printf ("[1] - VIVO\n ");
		printf ("[2] - CLARO\n ");
		printf ("[3] - TIM\n ");
		printf ("[4] - OI\n ");
		scanf("%d", &opMenuOperadoras);
			while (opMenuOperadoras > 4 || opMenuOperadoras <= 0) {
				printf ("OPÇÃO INCORRETA\nSelecione a Operadora:\n");
				scanf("%d", &opMenuOperadoras);
			}
			switch (opMenuOperadoras) {
			case 1:
				printf ("RECARGA VIVO\n");
				printf ("Digite o numero do celular:\n");
				scanf("%s", &numCelular);
				printf ("Digite o valor da recarga:\nR$ ");
				scanf("%f", &pagamento);		
				if (pagamento <= 0) //Validando se o valor digitado é 0 ou negativo, caso seja chamar a função para validar.
					pagamento = verificarValor (pagamento);
				saldoAtual = saldoAtual - pagamento;
				extrato [cont] = pagamento;
				break;
			case 2:
				printf ("RECARGA CLARO\n");
				printf ("Digite o numero do celular:\n");
				scanf("%s", &numCelular);
				printf ("Digite o valor da recarga:\nR$ ");
				scanf("%f", &pagamento);		
				if (pagamento <= 0) //Validando se o valor digitado é 0 ou negativo, caso seja chamar a função para validar.
					pagamento = verificarValor (pagamento);
				saldoAtual = saldoAtual - pagamento;
				extrato [cont] = pagamento;
				break;
			case 3:
				printf ("RECARGA TIM\n");
				printf ("Digite o numero do celular:\n");
				scanf("%s", &numCelular);
				printf ("Digite o valor da recarga:\nR$ ");
				scanf("%f", &pagamento);		
				if (pagamento <= 0) //Validando se o valor digitado é 0 ou negativo, caso seja chamar a função para validar.
					pagamento = verificarValor (pagamento);
				saldoAtual = saldoAtual - pagamento;
				extrato [cont] = pagamento;
				break;
			case 4:
				printf ("RECARGA OI\n");
				printf ("Digite o numero do celular:\n");
				scanf("%s", &numCelular);
				printf ("Digite o valor da recarga:\nR$ ");
				scanf("%f", &pagamento);		
				if (pagamento <= 0) //Validando se o valor digitado é 0 ou negativo, caso seja chamar a função para validar.
					pagamento = verificarValor (pagamento);
				saldoAtual = saldoAtual - pagamento;
				extrato [cont] = pagamento;
				break;			
			}
	break;
	case 4: //Opção ver extrato
		printf ("-------------------------------\n");
		printf ("EXTRATO - DÉBITOS REALIZADOS\n ");
		if (cont == 0)
			printf("Nenhum débito realizado na conta até o momento :)\n");
		for (i=0; i < cont; i++) {
			printf ("%.2f\n", extrato[i]);
		}
		cont--;//Decrementa o cont toda vez que é verificado o extrato, para não exibir valores falsos/zerados.
		system ("pause");
	break;	
	}
	system("cls");
	cont++;
	}while (opMenu != 0);

	return 0;
}
