#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HASH_SIZE 97

struct hash_table
{
  char *key;
  int value;
  struct hash_table *next;
};

int string_hash(char *s)
{
  char c;
  int p = 31, m = 97;
  int hash_value = 0, p_pow = 1;

  while (c = *s++)
  {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return (hash_value);
}

int main()
{
  char s[255];

  fgets(s, 255, stdin);
  s[strcspn(s, "\n")] = '\0';

  printf("%s = %d\n", s, string_hash(s));
}

int string_hash(char *s)
{
  char c;
  int p = 31, m = MAX_HASH_SIZE;
  int hash_value = 0, p_pow = 1;

  while (c = *s++)
  {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

void insert(struct hash_table **table, char *key, int value)
{
  int hash_value = string_hash(key);
  struct hash_table *new_element = (struct hash_table *)malloc(sizeof(struct hash_table));
  new_element->key = key;
  new_element->value = value;
  new_element->next = table[hash_value];
  table[hash_value] = new_element;
}

int search(struct hash_table **table, char *key)
{
  int hash_value = string_hash(key);
  struct hash_table *current = table[hash_value];
  while (current != NULL)
  {
    if (strcmp(current->key, key) == 0)
    {
      return current->value;
    }
    current = current->next;
  }
  return -1;
}

void remove_key(struct hash_table **table, char *key)
{
  int hash_value = string_hash(key);
  struct hash_table *current = table[hash_value];
  struct hash_table *prev = NULL;
  while (current != NULL)
  {
    if (strcmp(current->key, key) == 0)
    {
      if (prev == NULL)
      {
        table[hash_value] = current->next;
      }
      else
      {
        prev->next = current->next;
      }
      free(current);
      break;
    }
    prev = current;
    current = current->next;
  }
}
