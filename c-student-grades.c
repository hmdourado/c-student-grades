/**
 * @file aula17-exercicio6.c
 * @author Henrique Dourado
 * @brief 
 * @version 0.1
 * @date 2026-09-12
 * 
 * @copyright Copyright (c) 2026
 * 
 * Faça um programa em C que leia as notas de 5 alunos e armazene-as em um vetor de estruturas. Cada aluno tem um nome (string) e uma nota(float)

Crie funções para:

cadastrar os alunos;
calcular e retornar a média das notas;
identificar o aluno com a maior nota;
exibir os dados de todos os alunos.
Na main, chame as funções na sequencia e exiba os resultados obtidos e/ou retornados
 * 
 */

#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura de cadastro de alunos.
 * 
 */
typedef struct {
    char nome[50];
    float nota;
} Aluno;

/**
 * @brief Entrada de nomes e notas dos alunos.
 * 
 * @param dados 
 */
void cadastrarAlunos (Aluno dados []){
    for (int i = 0; i < 5; i++){
        setbuf(stdin, NULL);
        printf("\nDigite o %d nome: ", i+1);
        fgets(dados[i].nome, 50, stdin);
        dados[i].nome[strcspn(dados[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("Digite a nota de %s: ", dados[i].nome);
        scanf("%f", &dados[i].nota);

    }   
}

/**
 * @brief Cálculo de média de todas as notas do cadastro de cada um dos alunos.
 * 
 * @param dados 
 * @return float 
 */
float calcularMedia (Aluno dados[]){
    float soma = 0;
    float media;

    for (int i = 0; i < 5; i++){
        media = soma += dados[i].nota;
    }

    media = media / 5;
    return media;
}

/**
 * @brief Verificação de qual aluno tirou a maior nota, o retorno é feito apenas com o indice, assim na função para exibir 
 * é possivel acessar o nome e a nota na estrutura de cadastro com as informações exatas atráves do indice.
 * 
 * @param dados 
 * @return int 
 */
int maiorNota (Aluno dados[]){
    int indice = 0;

    for (int i = 0; i < 5; i++){
        if (dados[i].nota > dados[indice].nota){
            indice = i;
        }
    }
    return indice;
}

/**
 * @brief Exibição de dados cadastrados e resultados obtidos através dos cáculos acima.
 * 
 * @param dados 
 * @param media 
 * @param indice 
 */
void exibirAlunos (Aluno dados [], float media, int indice){
    printf("\n-----Dados Cadastrados-----\n");
    
    for (int i = 0; i < 5; i++){
        printf("\nNome: %s", dados[i].nome);
        printf("\nNota: %.2f", dados[i].nota);
        printf("\n");
    }
    printf("\n-----Resultados Obtidos-----\n");
    
    printf("\nMédia das notas: %.2f", media);
    printf("\nMaior nota: %.2f", dados[indice].nota);
    printf("\nAluno com maior nota: %s", dados[indice].nome);

}

int main (void) {

    //Declaração da estrutura de vetor.
    Aluno dados[5];

    //Prenchimento dos dados dos alunos.
    cadastrarAlunos(dados);

    //Armazenamento de retorno das variáveis.
    float media = calcularMedia(dados);
    int maior = maiorNota(dados);

    //Exibição de todo o conteúdo.
    exibirAlunos(dados, media, maior);

    return 0;
}