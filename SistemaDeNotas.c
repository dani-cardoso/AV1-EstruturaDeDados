#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 100
#define NUM_NOTAS 3

void cadastrarAluno(char nomes[][MAX_ALUNOS], float notas[][NUM_NOTAS], int *quantidade) {
  printf("=====================\n");
  printf("Cadastro de Aluno\n");
  printf("=====================\n");
  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", nomes[*quantidade]);

while (1){
  printf("-------------------------\n");
  
  printf("Informe a 1ª nota do aluno: ");
  scanf("%f", &notas[*quantidade][0]);
  
  printf("Informe a 2ª nota do aluno: ");
  scanf("%f", &notas[*quantidade][1]);
  
  printf("Informe a 3ª nota do aluno: ");
  scanf("%f", &notas[*quantidade][2]);
  
  if (notas[*quantidade][0] >= 0 &&
      notas[*quantidade][0] <= 10 &&
      notas[*quantidade][1] >= 0 &&
      notas[*quantidade][1] <= 10 &&
      notas[*quantidade][2] >= 0 &&
      notas[*quantidade][2] <= 10) {
    
    break;

  } else {
    printf("Notas inválidas. Digite novamente.\n");
  }
}
(*quantidade)++;
  printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos(char nomes[][MAX_ALUNOS], float notas[][NUM_NOTAS], int quantidade) {
  if (quantidade == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  printf("====================\n");
  printf("Alunos cadastrados:\n");
  printf("====================\n");
  for (int i = 0; i < quantidade; i++) {
    printf("%d. %s - Notas: %.2f, %.2f, %.2f\n", i + 1, nomes[i], notas[i][0], notas[i][1], notas[i][2]);
  }
}

float calcularMedia(float notas[][NUM_NOTAS], int quantidade) {
  if (quantidade == 0) {
    printf("Nenhuma nota registrada.\n");
    return 0;
  }

  float soma = 0;
  int quantidadeNotas = 0;
  for (int i = 0; i < quantidade; i++) {
    for (int j = 0; j < NUM_NOTAS; j++) {
      soma += notas[i][j];
      quantidadeNotas++;
    }
  }

  float media = soma / quantidadeNotas;
  printf("--------------------\n");
  printf("A média da turma é: %.2f\n", media);
  return media;
}

void listarAprovados(char nomes[][MAX_ALUNOS], float notas[][NUM_NOTAS], int quantidade) {
  if (quantidade == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  printf("====================\n");
  printf("Alunos aprovados:\n");
  printf("====================\n");
  int quantidadeAprovados = 0;
  for (int i = 0; i < quantidade; i++){
    float soma = 0;
    for (int j = 0; j < NUM_NOTAS; j++) {
      soma += notas[i][j];
    }
    float media = soma / NUM_NOTAS;
    if (media >= 7) {
      printf("%d. %s - Média: %.2f\n", i + 1, nomes[i], media);
      quantidadeAprovados++;
    }
  }

  if (quantidadeAprovados == 0) {
    printf("Nenhum aluno aprovado.\n");
  }
}

int contarAprovadosRecursivo(float notas[][NUM_NOTAS], int quantidade, int indice) {
  if (indice == quantidade) {
    return 0;
  }
  float soma = 0;
  for (int j = 0; j < NUM_NOTAS; j++) {
    soma += notas[indice][j];
  }
  float mediaAluno = soma / NUM_NOTAS;
  if (mediaAluno >= 7){
    return 1 + contarAprovadosRecursivo(notas, quantidade, indice + 1);
  } else {
    return contarAprovadosRecursivo(notas, quantidade, indice + 1);
  }
}

int buscaSequencial(char nomes[][MAX_ALUNOS], float notas[][NUM_NOTAS], int quantidade) {
  char nomeBusca[MAX_ALUNOS];
  printf("--------------------\n");
  printf("Digite o nome do aluno que deseja buscar: ");
  scanf("%s", nomeBusca);
  printf("--------------------\n");
  for (int i = 0; i < quantidade; i++) {
    if (strcmp(nomes[i], nomeBusca) == 0) {
      printf("Aluno encontrado: %s - Notas: %.2f, %.2f, %.2f\n", nomes[i], notas[i][0], notas[i][1], notas[i][2]);
      return i;
    }
  }
  printf("Aluno não encontrado.\n");
  return -1;
}

float somarNotasRecursiva(float notas[][NUM_NOTAS], int quantidade, int indice) {
  if (indice == quantidade) {
    return 0;
    }
    float somaAluno = 0;
    for (int i = 0; i < NUM_NOTAS; i++) {
      somaAluno += notas[indice][i];
    }
    return somaAluno +
      somarNotasRecursiva(notas,quantidade,indice + 1);
}

void estatisticas(float notas[][NUM_NOTAS], int quantidade) {
  if (quantidade == 0) {
    printf("Nenhuma nota registrada.\n");
    return;
  }

  float soma = somarNotasRecursiva(notas, quantidade, 0);
  int quantidadeNotas = quantidade * NUM_NOTAS;
  float media = soma / quantidadeNotas;
  int aprovados = contarAprovadosRecursivo(notas, quantidade, 0);
  float percentual = ((float)aprovados / quantidade) * 100;
  
  printf("--------------------\n");
  printf("Estatísticas da turma:\n");
  printf("--------------------\n");
  printf("Soma das notas: %.2f\n", soma);
  printf("Média da turma: %.2f\n", media);
  printf("Percentual de alunos aprovados: %.2f%%\n", percentual);
  printf("Quantidade de alunos aprovados: %d\n", aprovados);
}

void mediaPorAluno(float notas[][NUM_NOTAS], char nomes[][100], int quantidade) {
  if (quantidade == 0) {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  printf("====================\n");
  printf("Média por aluno:\n");
  printf("====================\n");
  for (int i = 0; i < quantidade; i++) {
    float soma = 0;
    for (int j = 0; j < NUM_NOTAS; j++) {
      soma += notas[i][j];
    }
    float media = soma / NUM_NOTAS;
    printf("%d. Média do aluno %s: %.2f\n", i + 1, nomes[i], media);
  }
}

void funcionalidadesExtras(char nomes[][100],float notas[][NUM_NOTAS],int quantidade) {
  char opcao2[10];
  while (1) {
    printf("====================\n");
    printf("Funcionalidades Extras\n");
    printf("====================\n");

    printf("S1 - Busca sequencial\n");
    printf("S2 - Estatisticas Complementares\n");
    printf("S3 - Contagem de Aprovados\n");
    printf("S4 - Media por aluno\n");
    printf("S - Voltar ao menu principal\n");

    printf("Escolha uma opcao: ");
    scanf("%s", opcao2);
  for (int i = 0; opcao2[i] != '\0'; i++) {
    opcao2[i] = tolower(opcao2[i]);
    }
  if (strcmp(opcao2, "s1") == 0) {
  buscaSequencial(nomes,notas,quantidade);
  } else 
  if (strcmp(opcao2, "s2") == 0) {
    estatisticas(notas,quantidade);
  } else 
  if (strcmp(opcao2, "s3") == 0) {
    int aprovados = contarAprovadosRecursivo(notas,quantidade,0);

  printf("--------------------\n");
  printf("Quantidade de aprovados: %d\n",aprovados);
  } else 
  if (strcmp(opcao2, "s4") == 0) {
    mediaPorAluno(notas,nomes,quantidade);
  } else 
  if (strcmp(opcao2, "s") == 0) {
    return;
  } else {
  printf("Opcao invalida.\n");
    }
  }
}

int main() {
  char nomes[MAX_ALUNOS][100];
  float notas[MAX_ALUNOS][NUM_NOTAS];
  int quantidade = 0;
  while (1) {
    printf("====================\n");
    printf("Sistema de Notas\n");
    printf("====================\n");

    printf("1 - Cadastrar aluno e notas\n");
    printf("2 - Exibir alunos e notas\n");
    printf("3 - Calcular media\n");
    printf("4 - Listar alunos aprovados\n");
    printf("5 - Acessar submenu funcionalidades extras\n");
    printf("0 - Sair\n");

    int opcao;
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);
      if (opcao == 1) {
        if (quantidade < MAX_ALUNOS) {
          cadastrarAluno(nomes,notas,&quantidade);
        } else {
          printf("Limite de alunos atingido.\n");
        }
        } else 
        if (opcao == 2) {
            listarAlunos(nomes,notas,quantidade);
        } else 
        if (opcao == 3) {
          calcularMedia(notas,quantidade);
        } else 
        if (opcao == 4) {
          listarAprovados(nomes,notas,quantidade);
        } else 
        if (opcao == 5) {
          funcionalidadesExtras(nomes,notas,quantidade);
        } else 
        if (opcao == 0) {
          printf("Saindo do sistema...\n");
          break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}
    