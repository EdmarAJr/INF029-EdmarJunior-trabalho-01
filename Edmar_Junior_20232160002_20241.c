
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

//retirar todos os printf() antes da entrega

#include <stdio.h>
#include "Edmar_Junior_20232160002_20241.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
		Somar dois valores x e y e retonar o resultado da soma
@entrada
		dois inteiros x e y
@saida
		resultado da soma (x + y)
 */
int somar(int x, int y)
{
		int soma;
		soma = x + y;
		return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
		calcular o fatorial de um número
@entrada
		um inteiro x
@saida
		fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
	int i, fat = 1;

	for (i = x; i > 1; i--)
		fat = fat * i;

	return fat;
}

int teste(int a)
{
		int val;
		if (a == 2)
				val = 3;
		else
				val = 4;

		return val;
}

DataQuebrada quebraData(char data[]){
	//cria um novo struct chamado dq com as propriedades de DataQuebrada
	DataQuebrada dq; 
	char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	printf("Data de entrada: %s\n", data);
	//limpa o array
	for (int i = 0; i < 5; i++){
		sDia[i] = 0;
		sMes[i] = 0;
		sAno[i] = 0;
	}
	
	//neste for copia os valores da string data ate encontrar a primeira barra e sair do for
	//sDia eh um array e recebe ate 3 valores
	for (i = 0; data[i] != '/'; i++){ 
		sDia[i] = data[i];	
	}

	// testa se tem 1 ou dois digitos e o dia esta entre 1 e 31
	if((i == 1 || i == 2) && (atoi(sDia) > 0 && atoi(sDia) <= 31)){
		sDia[i] = '\0';  // coloca o barra zero no final
	} else{
		dq.valido = 0;//atribui o valor em dq
		return dq;
	}

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	//neste for pula valor atualizado de i para 1 casa copia os valores da string data ate encontrar a segunda barra e sair do for
	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}
	
	int ano_2 = atoi(sAno)+2000;
	int ano_4 = atoi(sAno);

	// testa se o mes tem 1 ou dois digitos e se esta entre 1 e 12
	if((i == 1 || i == 2) && (atoi(sMes) > 0 && atoi(sMes) <= 12)){ 
		sMes[i] = '\0';  // coloca o barra zero no final
	} else if ((i == 2) && (atoi(sMes) == 2) 
				&& (((ano_2 %100 == 0) && (ano_2 %400 == 0)) || (ano_2 %100 != 0) && (ano_2 %100%4 == 0))){
		dq.valido = 1;
	} else if ((i == 4) && (atoi(sMes) == 2) 
				&& (((ano_4 %100 == 0) && (ano_4 %400 == 0)) || ((ano_4 %100 != 0) && (ano_4 %100%4 == 0)))){
			dq.valido = 1;
	} else if((atoi(sMes) == 4 ||
			   atoi(sMes) == 6 ||
			   atoi(sMes) == 9 ||
			   atoi(sMes) == 11) && atoi(sDia) > 0 && atoi (sDia) <=30){
		dq.valido = 1;
	}else {
		if((atoi(sMes) != 2 
			|| atoi(sMes) != 4 
			|| atoi(sMes) != 6 
			|| atoi(sMes) != 11) 
			&& (atoi(sDia) > 0 && atoi(sDia) <=31)) {
			dq.valido = 1; //atribui o valor em dq na propriedade valido
		} else{
			return dq;
		}
	}

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;

	//neste for pula valor atualizado de j para 1 casa copia os valores da string data ate encontrar \0 e sair do for
	for(; data[j] != '\0'; j++){
		sAno[i] = data[j];
		i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
		int ano = atoi(sAno);

			switch (i){
				case 2: {
					switch (ano) {
						case 0: {
							if(((ano+2000)%400 == 0) && (atoi(sMes) == 2) && (atoi(sDia)> 0 && atoi(sDia) <= 29)){
								dq.valido = 1;
							}
							break;	
						}
						default: {
							if(((ano+2000)%100%4 == 0) && (atoi(sMes) == 2) && (atoi(sDia)> 0 && atoi(sDia) <= 29)){
								printf("O ano default bi ano 2 digitos: %d\n", ano);
								dq.valido = 1; 
							} else {
								if((ano+2000%100%4 != 0) && (atoi(sMes) == 2) &&  (atoi(sDia) == 29)){
									printf("ano default nao bi 2 digitos: %d\n",ano);
									dq.valido = 0;
								}
							}
						}
					}
					break;
				}
				case 4: {
					switch (ano%100) {
						case 0: {
							if((ano % 400 == 0) && (atoi(sMes) == 2) && (atoi(sDia)> 0 && atoi(sDia) <= 29)){
								printf("ano 00 eh: %d\n",ano);
								dq.valido = 1;
							}
							break;	
						}
						default: {
							if((ano%100%4 == 0) && (atoi(sMes) == 2) && (atoi(sDia) > 0 && atoi(sDia) <= 29)){
								printf("ano bi eh: %d\n",ano);
								dq.valido = 1; 
							} else {
								if((ano%100%4 != 0) && (atoi(sMes) == 2) &&  (atoi(sDia) == 29)){
									printf("ano nao bi eh: %d\n",ano);
									dq.valido = 0;
								}
							}
						}
					}
					break;
				}	
				default:{
					printf("O ano default2: %d\n", ano);
					dq.valido = 0; 
				}
				break;
		}
	}

	dq.iDia = atoi(sDia); //atribui o valor em dq na propriedade sDia
	dq.iMes = atoi(sMes); //atribui o valor em dq na propriedade sMês
	dq.iAno = atoi(sAno); //atribui o valor em dq na propriedade sAno
	// dq.valido = 1;
	
	//printf("Ano no struct: %d, valido:%d\n", dq.iAno, dq.valido);
	return dq;
}
/*
 Q1 = validar data
@objetivo
		Validar uma data
@entrada
		uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
		0 -> se data inválida
		1 -> se data válida
 @restrições
		Não utilizar funções próprias de string (ex: strtok)   
		pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
	int datavalida;
	
	//quebra a string data em strings sDia, sMes, sAno
	DataQuebrada dataQuebrada = quebraData(data);
	
	if (dataQuebrada.valido == 0) {
		datavalida = 0;	
	} else{
		datavalida = 1;
	}

	if (datavalida)
		return 1;
	else
		return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
		Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
		uma string datainicial, uma string datafinal. 
 @saida
		Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
		1 -> cálculo de diferença realizado com sucesso
		2 -> datainicial inválida
		3 -> datafinal inválida
		4 -> datainicial > datafinal
		Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

		//calcule os dados e armazene nas três variáveis a seguir
		DiasMesesAnos dma;

		if (q1(datainicial) == 0){
			dma.retorno = 2;
			return dma;
		}else if (q1(datafinal) == 0){
			dma.retorno = 3;
			return dma;
		}else{
			//verifique se a data final não é menor que a data inicial

			//calcule a distancia entre as datas


			//se tudo der certo
			dma.retorno = 1;
			return dma;

		}

}

/*
 Q3 = encontrar caracter em texto
 @objetivo
		Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
		uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
				Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
		Um número n >= 0.
 */

int q3(char texto[], char c, int isCaseSensitive){
	int qtdOcorrencias = 0;
	// char copia[] = strcpy(texto, copia);

	// if (!isCaseSensitive){
	// 	int i = 0;
	// 	for (; texto[i] != '\0'; i++){ 
	// 		copia[i] = toupper(copia[i]);
	// 	}
	// 	c = toupper(c);
	// }
	
	// for (int i = 0; texto[i] != '\0'; i++){ 
	// 	if (c == copia[i]) {
	// 		qtdOcorrencias++;
	// 	}
	// }
	// return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
		Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
		uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
		Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
		O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
				posicoes[0] = 13;
				posicoes[1] = 16;
				Observe que o índice da posição no texto deve começar ser contado a partir de 1.
				O retorno da função, n, nesse caso seria 1;

 */
int q4(char strTexto[], char strBusca[], int posicoes[30]){
	// char textoSplitado[300];

	// for(int i = 0; strTexto[i] != "/0"; i++){
	// 		if(strTexto[i] != " "){
	// 			char palavra[30] = strTexto[i];
	// 			textoSplitado[i] = strcpy(palavra);
	// 		}
	// 	}
	
	int qtdOcorrencias = -1;

	int tam_strTexto = strlen(strTexto);
	int tam_strBusca = strlen(strBusca);

	printf("Tamanho do texto: %d\n", tam_strTexto);
	printf("Tamanho do palavra: %d\n", tam_strBusca);

		for (int i = 0; i <= tam_strTexto - tam_strBusca; i++) {
        int j;
        // Verificando se a substring de tam_strTexto a partir da posição i é igual a tam_strBusca
        for (j = 0; j < tam_strBusca; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                break; // Se os caracteres não coincidirem, sai do loop interno
            }
        }
        if (j == tam_strBusca) {
			printf("Ocorrencias: %d\n", qtdOcorrencias);
            qtdOcorrencias++; // Se todos os caracteres de tam_numBusca_S foram encontrados, incrementa qtdOcorrencias
		}
    }

	return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
		Inverter número inteiro
 @entrada
		uma int num.
 @saida
		Número invertido
 */

int q5(int num){

	//refazer pois nao deve usar string
	// char num_S[6];
    // sprintf(num_S, "%d\n", num);
	// char numInvertido_S[6];
	
    // int tam = strlen(num_S)-1;
	// int j = tam-1;
	// int i = 0;

    // for (; i < tam; i++){ 
	// 	numInvertido_S[j] = num_S[i];
	// 	j--;
	// }

	// if(i > 0){
	// 	numInvertido_S[i] = '\0';
	// }
	
	// int numInvertido_I = atoi(numInvertido_S);
    
	// return numInvertido_I;

    int tamanhoNum1 = 0;
    int tempNum1 = num;
	int numInvertido[tamanhoNum1];

    while (tempNum1 > 0) {
        tamanhoNum1++;
        tempNum1 /= 10;
    }
    
    int arrayNum1[tamanhoNum1];

    for (int i = tamanhoNum1 - 1; i >= 0; i--) {
        arrayNum1[i] = num % 10;
        num /= 10;
    }
	
	int j = tamanhoNum1;
    for (int i = tamanhoNum1 - 1; i >= 0; i--) {
        numInvertido[j] = num * 10;
        num *= 10;
		j--;
    }
    
    // for (int i = 0; i <= tamanhoNum1 - tamanhoNum2; i++) {
    //     int j;
    //     for (j = 0; j < tamanhoNum2; j++) {
    //         if (arrayNum1[i + j] != arrayNum2[j]) {
    //             break;
    //         }
    //     }
    //     if (j == tamanhoNum2) {
    //         qtdOcorrencias++;
    //     }
    // } 

	// for(int i = 0; i < tamanhoNum1; i++){
	// 	numInvertido = arrayNum1[i]*10;
	// }
    return numInvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
		Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
		Um número base (numerobase) e um número de busca (numerobusca).
 @saida
		Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
	//refazer pois nao deve usar string
	// int qtdOcorrencias = 0;

	// char num_S[10];
	// char numBusca_S[10];
	// sprintf(num_S, "%d\n", numerobase);
    // sprintf(numBusca_S, "%d\n", numerobusca);

    // int tam_num_S = strlen(num_S)-1;
	// int tam_numBusca_S = strlen(numBusca_S)-1;
	
	// int i = 0;

	// if(i > 0){
	// 	num_S[tam_num_S] = '\0';
	// }

	// if(i > 0){
	// 	numBusca_S[tam_numBusca_S] = '\0';
	// }

	// for (int i = 0; i <= tam_num_S - tam_numBusca_S; i++) {
    //     int j;
    //     // Verificando se a substring de tam_num_S a partir da posição i é igual a tam_numBusca_S
    //     for (j = 0; j < tam_numBusca_S; j++) {
    //         if (num_S[i + j] != numBusca_S[j]) {
    //             break; // Se os caracteres não coincidirem, sai do loop interno
    //         }
    //     }
    //     if (j == tam_numBusca_S) {
    //         qtdOcorrencias++; // Se todos os caracteres de tam_numBusca_S foram encontrados, incrementa qtdOcorrencias
    //     }
    // }
	// return qtdOcorrencias;

    int qtdOcorrencias;

    int tamanhoNum1 = 0;
    int tamanhoNum2 = 0;
    int tempNum1 = numerobase;
    int tempNum2 = numerobusca;

    while (tempNum1 > 0) {
        tamanhoNum1++;
        tempNum1 /= 10;
    }
    while (tempNum2 > 0) {
        tamanhoNum2++;
        tempNum2 /= 10;
    }
    
    int arrayNum1[tamanhoNum1];
    int arrayNum2[tamanhoNum2];

    for (int i = tamanhoNum1 - 1; i >= 0; i--) {
        arrayNum1[i] = numerobase % 10;
        numerobase /= 10;
    }


    for (int i = tamanhoNum2 - 1; i >= 0; i--) {
        arrayNum2[i] = numerobusca % 10;
        numerobusca /= 10;
    }
    
    for (int i = 0; i <= tamanhoNum1 - tamanhoNum2; i++) {
        int j;
        for (j = 0; j < tamanhoNum2; j++) {
            if (arrayNum1[i + j] != arrayNum2[j]) {
                break;
            }
        }
        if (j == tamanhoNum2) {
            qtdOcorrencias++;
        }
    } 
    return qtdOcorrencias;
}
