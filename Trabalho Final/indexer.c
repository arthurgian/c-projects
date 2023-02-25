#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define BLACK 0
#define RED 1

typedef struct treeRedBlack
{
  char info[100];
  int count;
  float tfidf;
  int cor;
  struct treeRedBlack *esq;
  struct treeRedBlack *dir;
} TreeRedBlack;

int is_black_node(TreeRedBlack *no)
{
  return no == NULL || no->cor == BLACK;
}

int is_red_node(TreeRedBlack *no)
{
  return no && no->cor == RED;
}

int verify_empty_tree(TreeRedBlack *a)
{
  return (a == NULL);
}

void flip_cor(TreeRedBlack *no)
{
  no->cor = RED;
  no->esq->cor = BLACK;
  no->dir->cor = BLACK;
}

TreeRedBlack *rot_esq(TreeRedBlack *no)
{
  TreeRedBlack *tree = no->dir;
  no->dir = tree->esq;
  tree->esq = no;
  tree->cor = no->cor;
  no->cor = RED;
  return (tree);
}

TreeRedBlack *rot_dir(TreeRedBlack *no)
{
  TreeRedBlack *tree = no->esq;
  no->esq = tree->dir;
  tree->dir = no;
  tree->cor = no->cor;
  no->cor = RED;
  if (is_red_node(tree->dir) && is_red_node(tree->esq))
    flip_cor(tree);
  return (tree);
}

TreeRedBlack *fixRBTree(TreeRedBlack *a)
{
  if (is_red_node(a->dir) && is_black_node(a->esq))
    a = rot_esq(a);
  if (is_red_node(a->esq) && is_red_node(a->esq->esq))
    a = rot_dir(a);
  if (is_red_node(a->dir) && is_red_node(a->esq))
    flip_cor(a);
  return a;
}

int buscar(TreeRedBlack *a, char v[])
{
  return a != NULL && (strcmp(v, a->info) < 0 ? buscar(a->esq, v) : (strcmp(v, a->info) > 0 ? buscar(a->dir, v) : 1));
}

void printTreeOrder(TreeRedBlack *a)
{
  if (!a)
    return;
  printTreeOrder(a->esq);
  printf("%s - %d\n", a->info, a->count);
  printTreeOrder(a->dir);
}

void printTreeOrder2(TreeRedBlack *a)
{
  if (!a)
    return;
  printTreeOrder2(a->dir);
  printf("%s - %f \n", a->info, a->tfidf);
  printTreeOrder2(a->esq);
}

void printTree(TreeRedBlack *a, int height)
{
  if (a != NULL)
  {
    printf("%d - %s / %d / %f : %s\n", height, a->info, a->count, a->tfidf, a->cor ? "RED" : "BLACK");
    printTree(a->esq, height + 1);
    printTree(a->dir, height + 1);
  }
}

TreeRedBlack *inserirByTFIDF(TreeRedBlack *a, char v[], int count, float tfidf)
{
  int change = 0;
  if (a == NULL)
  {
    a = (TreeRedBlack *)malloc(sizeof(TreeRedBlack));
    strcpy(a->info, v);
    a->count = count;
    a->tfidf = tfidf;
    a->cor = BLACK;
    a->esq = a->dir = NULL;
  }
  else if (tfidf < a->tfidf)
  {
    change = a->esq == NULL;
    a->esq = inserirByTFIDF(a->esq, v, count, tfidf);
    if (change)
      a->esq->cor = RED;
  }
  else
  {
    change = a->dir == NULL;
    a->dir = inserirByTFIDF(a->dir, v, count, tfidf);
    if (change)
      a->dir->cor = RED;
  }

  return fixRBTree(a);
}

TreeRedBlack *inserir(TreeRedBlack *a, char v[], int count, float tfidf)
{
  int change = 0;
  if (a == NULL)
  {
    a = (TreeRedBlack *)malloc(sizeof(TreeRedBlack));
    strcpy(a->info, v);
    a->count = count;
    a->tfidf = tfidf;
    a->cor = BLACK;
    a->esq = a->dir = NULL;
  }
  else if (strcmp(v, a->info) < 0)
  {
    change = a->esq == NULL;
    a->esq = inserir(a->esq, v, count, tfidf);
    if (change)
      a->esq->cor = RED;
  }
  else if (strcmp(v, a->info) > 0)
  {
    change = a->dir == NULL;
    a->dir = inserir(a->dir, v, count, tfidf);
    if (change)
      a->dir->cor = RED;
  }
  else
    a->count++;

  return fixRBTree(a);
}

TreeRedBlack *arv_libera(TreeRedBlack *a)
{
  if (!verify_empty_tree(a))
  {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
  return NULL;
}

int arv_bin_check(TreeRedBlack *a)
{
  return a == NULL
             ? 1
             : ((a->esq == NULL || strcmp(a->info, a->esq->info) > 0) && (a->dir == NULL || strcmp(a->info, a->dir->info) < 0) && arv_bin_check(a->esq) && arv_bin_check(a->dir));
}

int get_tree_height(TreeRedBlack *a)
{
  int height = 0;
  TreeRedBlack *no = a;
  while (no != NULL)
  {
    if (is_black_node(no))
      height++;
    no = no->esq;
  }
  return height;
}

int arv_rb_check(TreeRedBlack *a, int myHeight, int height)
{
  if (a == NULL)
    return myHeight == height;

  return arv_rb_check(a->esq, myHeight + is_black_node(a), height) && arv_rb_check(a->dir, myHeight + is_black_node(a), height);
}

void getTheBestWords(TreeRedBlack *a, int quantity, char **bestWords, int wordsCount[])
{
  if (!a)
    return;

  for (int i = quantity - 1; i >= 0; i--)
  {
    if (a->count > wordsCount[i])
    {
      if (i < quantity - 1)
      {
        strcpy(bestWords[i + 1], bestWords[i]);
        wordsCount[i + 1] = wordsCount[i];
      }

      strcpy(bestWords[i], a->info);
      wordsCount[i] = a->count;
    }
    else
      break;
  }

  getTheBestWords(a->esq, quantity, bestWords, wordsCount);
  getTheBestWords(a->dir, quantity, bestWords, wordsCount);
}

int showOptions()
{
  printf("OPÇÕES PARA ESCOLHA\n\n--freq N ARQUIVO\n[Descrição do comando]:\nExibe o número de ocorrência das N palavras que mais aparecem em ARQUIVO, em ordem decrescente de ocorrência.\n\n--freq-word PALAVRA ARQUIVO\n[Descrição do comando]:\nExibe o número de ocorrências de PALAVRA em ARQUIVO.\n\n--search TERMO ARQUIVO [ARQUIVO ...]\n[Descrição do comando]:\nExibe uma listagem dos ARQUIVOS mais relevantes encontrados pela busca por TERMO. A listagem é apresentada em ordem descrescente de relevância. TERMO pode conter mais de uma palavra. Neste caso, deve ser indicado entre àspas.\n");
  return -1;
}

int freq(int words, char *file)
{
  TreeRedBlack *a = NULL;

  FILE *fptr = fopen(file, "r");

  if (fptr == NULL)
  {
    printf("\nArquivo não encontrado ou sem permissão de leitura.\n");
    exit(EXIT_FAILURE);
  }

  char c;
  int i = 0;
  char wordRead[100];
  char wordReadStripped[100];
  while (c = getc(fptr))
  {
    c = tolower(c);
    if ((c > 47 && c < 58) || (c >= 97 && c <= 122))
    {
      wordRead[i] = c;
      i++;
    }
    else if (c == ' ' || c == '\n' || c == 32 || c == '-' || c == EOF)
    {
      wordRead[i] = '\0';
      i = 0;

      if (strlen(wordRead) > 1)
      {
        int j = 0, k = 0;
        for (; j < strlen(wordRead); j++)
        {
          if (isalnum(wordRead[j]))
          {
            wordReadStripped[k] = wordRead[j];
            k++;
          }
        }
        wordReadStripped[k] = '\0';
        a = inserir(a, wordReadStripped, 1, 0.0);
      }

      if (c == EOF)
        break;
    }
  }

  char *resultString[words];
  int resultInt[words];

  for (int i = 0; i < words; i++)
  {
    resultString[i] = (char *)malloc(100 * sizeof(char));
    resultInt[i] = 0;
  }

  getTheBestWords(a, words, resultString, resultInt);

  printf("As %d palavras mais usadas no arquivo %s:\n", words, file);

  for (int i = 0; i < words; i++)
  {
    printf("%s - %d vezes\n", resultString[i], resultInt[i]);
    free(resultString[i]);
  }
  fclose(fptr);
  arv_libera(a);

  return 1;
}

int freqWord(char *word, char *file)
{
  int count = 0, len;

  FILE *fptr = fopen(file, "r");

  if (fptr == NULL)
  {
    printf("\nArquivo não encontrado ou sem permissão de leitura.\n");
    exit(EXIT_FAILURE);
  }

  char c;
  int i = 0;
  char wordRead[100];
  char wordReadStripped[100];
  while ((c = getc(fptr)) != EOF)
  {
    c = tolower(c);
    if ((c > 47 && c < 58) || (c >= 97 && c <= 122))
    {
      wordRead[i] = c;
      i++;
    }
    else if (c == ' ' || c == '\n' || c == 32 || c == '-')
    {
      wordRead[i] = '\0';
      i = 0;

      // remove special chars
      int j = 0, k = 0;
      for (; j < strlen(wordRead); j++)
      {
        if (isalnum(wordRead[j]))
        {
          wordReadStripped[k] = wordRead[j];
          k++;
        }
      }
      wordReadStripped[k] = '\0';

      if (strcmp(wordReadStripped, word) == 0)
        count++;
    }
  }

  fclose(fptr);

  printf("A palavra %s ocorre %d vezes no arquivo %s.\n", word, count, file);
  return 1;
}

int search(int argsLength, char **args)
{
  FILE *fptr;
  int allWordsCounter, searchCounter, i, j, k, h, splitCounter = 0, wordIndex;
  int filesLength = argsLength - 3;
  char c;
  char wordRead[100];
  char wordReadStripped[100];
  char delim[] = " ";

  char *search = malloc(sizeof(char) * (strlen(args[2]) + 1));
  strcpy(search, args[2]);

  char *word = strtok(args[2], delim);
  while (word != NULL)
  {
    splitCounter++;
    word = strtok(NULL, delim);
  }
  int wordsArray[splitCounter][filesLength];
  int wordIsInFileArray[splitCounter];
  int wordsInFile[filesLength];

  for (i = 0; i < splitCounter; i++)
    wordIsInFileArray[i] = 0;

  for (h = 3; h < argsLength; h++)
  {
    strcpy(args[2], search);
    word = strtok(args[2], delim);
    i = 0;
    wordIndex = 0;
    allWordsCounter = searchCounter = 0;
    while (word != NULL)
    {
      /* Try to open file */
      fptr = fopen(args[h], "r");

      /* Exit if file not opened successfully */
      if (fptr == NULL)
      {
        printf("\nArquivo não encontrado ou sem permissão de leitura.\n");
        exit(EXIT_FAILURE);
      }

      while ((c = getc(fptr)) != EOF)
      {
        c = tolower(c);
        if ((c > 47 && c < 58) || (c >= 97 && c <= 122))
        {
          wordRead[i] = c;
          i++;
        }
        else if (c == ' ' || c == '\n' || c == 32 || c == '-')
        {
          wordRead[i] = '\0';
          i = 0;

          // remove special chars
          j = 0;
          k = 0;
          for (; j < strlen(wordRead); j++)
          {
            if (isalnum(wordRead[j]))
            {
              wordReadStripped[k] = wordRead[j];
              k++;
            }
          }
          wordReadStripped[k] = '\0';

          if (strcmp(wordReadStripped, word) == 0)
            searchCounter++;
          allWordsCounter++;
        }
      }

      printf("Search counter for '%s' in '%s': %d\n", word, args[h], searchCounter);
      wordsArray[wordIndex][h - 3] = searchCounter;
      if (searchCounter > 0)
        wordIsInFileArray[wordIndex]++;
      wordIndex++;
      word = strtok(NULL, delim);
    }
    wordsInFile[h - 3] = allWordsCounter;
    printf("Total words in '%s': %d\n\n", args[h], allWordsCounter);
    fclose(fptr);
  }

  TreeRedBlack *a = NULL;
  float tf, idf, tfidf;
  for (h = 3; h < argsLength; h++)
  {
    tfidf = 0;
    for (i = 0; i < splitCounter; i++)
    {
      // Calc the TFIDF
      if (wordsInFile[h - 3] > 0 && wordIsInFileArray[i] > 0 && splitCounter > 0)
      {
        tf = (float)wordsArray[i][h - 3] / (float)wordsInFile[h - 3];
        idf = log10((float)filesLength / (float)wordIsInFileArray[i]);
        tfidf += (float)(tf * idf) / (float)splitCounter;
        printf("Word: %d, File: %d, TF: %.3f, IDF: %.3f, TFIDF: %.3f\n", i, h - 3, tf, idf, tfidf);
      }
    }
    a = inserirByTFIDF(a, args[h], 1, tfidf);
  }

  printf("\nRED BLACK OK: %d\n", arv_rb_check(a, 0, get_tree_height(a)));
  // printf("\nBINARY OK: %d\n", arv_bin_check(a));
  printTree(a, 1);
  printf("\nResultados da busca por \"%s\":\n", search);
  printTreeOrder2(a);

  free(search);
  arv_libera(a);
  return 1;
}

int main(int argsLength, char **args)
{
  if (argsLength <= 3)
    return showOptions();

  if (strcmp(args[1], "--freq") == 0 && argsLength == 4)
    return freq(atoi(args[2]), args[3]);
  else if (strcmp(args[1], "--freq-word") == 0 && argsLength == 4)
    return freqWord(args[2], args[3]);
  else if (strcmp(args[1], "--search") == 0 && argsLength >= 4)
    return search(argsLength, args);
  else
    return showOptions();

  return 1;
}
