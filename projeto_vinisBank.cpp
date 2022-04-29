#include<stdlib.h>
#include<string.h>
#include<locale.h>
//********* Projeto VinisBank - Praticando a L�gica e Algoritmos em C *********

//Fun��o para validar se a op��o digitada no menu est� correta.
int validarOpMenu (int opMenu) {
		do {
			printf ("OP��O INCORRETA! Digite Novamente:\n");
			scanf("%d", &opMenu);
		}while (opMenu < 0 || opMenu > 4);
		system ("cls");
		return opMenu;
}

//Fun��o que valida se o usu�rio inseriu um valor inv�lido (0 ou negativo) ao realizar uma opera��o de pagamento ou recebimento.
float verificarValor (float dinheiro) {
		do {
			printf ("AVISO\n");
			printf ("N�o � poss�vel inserir o valor 0 ou negativo. \nInsira novamente, por favor:\nR$ ");	
			scanf("%f", &dinheiro);	
		}while (dinheiro <= 0);
		
		return dinheiro;
}

int main () {
	float saldoAtual=0, addDinheiro=0, pagamento=0, extrato [200];
	int opMenu, opMenuOperadoras, cont=0, i=0;
	char nome [50], chavePix, numCelular;
	
	setlocale(LC_ALL,""); //Fun��o para ajustar os caracteres especiais da aplica��o.
	
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
	
	if (saldoAtual < 0)//Valida se o saldo estiver negativo, dar� uma mensagem de aviso para depositar o quanto antes, para deixar o saldo positivo.
		printf("-------AVISO - VinisBank -------\n Seu saldo esta negativo, com taxa de juros di�rias.\nDeposite e normalize seu saldo o quanto antes!\n\n");
	
	printf ("DIGITE A OP��O DESEJADA: \n");
	printf ("[1] - Depositar Dinheiro\n");
	printf ("[2] - Transfer�ncia PIX\n");
	printf ("[3] - Recarga de Celular\n");
	printf ("[4] - Extrato de D�bitos\n");
	printf ("[0] - Sair\n");
	scanf("%d", &opMenu);
	if (opMenu < 0 || opMenu > 4)
		opMenu = validarOpMenu(opMenu);
	switch (opMenu) {
	case 1: //Op��o de Depositar, alimentando a vari�vel saldo.
		printf ("-------------------------------\n");
		printf ("Insira o valor de dep�sito:\n ");
		printf ("-------------------------------\nR$ ");
		scanf("%f", &addDinheiro);
		if (addDinheiro <= 0) //Validando se o valor digitado ao inserir o dep�sito � 0 ou negativo, caso seja, chamar� a fun��o para validar.
			addDinheiro = verificarValor (addDinheiro);			
		saldoAtual = saldoAtual + addDinheiro;//Caso o valor de dep�sito seja maior que 0, o saldo atual recebe o saldo atual + o valor depositado.		
		cont--;//Decrementa o cont toda vez que realiza um dep�sito, por que ao acessar a op��o Extrato, ser� exibida apenas os D�bitos, e nesta op��o est� Creditando, inserindo saldo.
		break;
	case 2: //Op��o transfer�ncia PIX.
		printf ("-------------------------------\n");
		printf ("Digite a chave PIX para a transfer�ncia:\n ");		
		scanf("%s", &chavePix);
		printf ("Insira o valor da transfer�ncia:\nR$ ");
		scanf("%f", &pagamento);
		if (pagamento <= 0) //Validando se o valor digitado � 0 ou negativo, caso seja chamar a fun��o para validar.
			pagamento = verificarValor (pagamento);
		saldoAtual = saldoAtual - pagamento;
		extrato [cont] = pagamento;
	break;
	case 3://Op��o de recarga de celular.
		printf ("-------------------------------\n");
		printf ("Selecione a Operadora:\n ");
		printf ("[1] - VIVO\n ");
		printf ("[2] - CLARO\n ");
		printf ("[3] - TIM\n ");
		printf ("[4] - OI\n ");
		scanf("%d", &opMenuOperadoras);
			while (opMenuOperadoras > 4 || opMenuOperadoras <= 0) {
				printf ("OP��O INCORRETA\nSelecione a Operadora:\n");
				scanf("%d", &opMenuOperadoras);
			}
			switch (opMenuOperadoras) {
			case 1:
				printf ("RECARGA VIVO\n");
				printf ("Digite o numero do celular:\n");
				scanf("%s", &numCelular);
				printf ("Digite o valor da recarga:\nR$ ");
				scanf("%f", &pagamento);		
				if (pagamento <= 0) //Validando se o valor digitado � 0 ou negativo, caso seja chamar a fun��o para validar.
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
				if (pagamento <= 0) //Validando se o valor digitado � 0 ou negativo, caso seja chamar a fun��o para validar.
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
				if (pagamento <= 0) //Validando se o valor digitado � 0 ou negativo, caso seja chamar a fun��o para validar.
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
				if (pagamento <= 0) //Validando se o valor digitado � 0 ou negativo, caso seja chamar a fun��o para validar.
					pagamento = verificarValor (pagamento);
				saldoAtual = saldoAtual - pagamento;
				extrato [cont] = pagamento;
				break;			
			}
	break;
	case 4: //Op��o ver extrato
		printf ("-------------------------------\n");
		printf ("EXTRATO - D�BITOS REALIZADOS\n ");
		if (cont == 0)
			printf("Nenhum d�bito realizado na conta at� o momento :)\n");
		for (i=0; i < cont; i++) {
			printf ("%.2f\n", extrato[i]);
		}
		cont--;//Decrementa o cont toda vez que � verificado o extrato, para n�o exibir valores falsos/zerados.
		system ("pause");
	break;	
	}
	system("cls");
	cont++;
	}while (opMenu != 0);

	return 0;
}
