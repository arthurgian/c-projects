//implementação busca

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_time
{
  int hours;
  int minutes;
  int seconds;
};

struct t_timetable
{
  struct t_time key;
  char *value;
  struct t_timetable *next;
};

struct t_timetable *createNode(struct t_time key, char *value)
{
  struct t_timetable *node = (struct t_timetable *)malloc(sizeof(struct t_timetable));
  node->key = key;
  node->value = (char *)malloc((strlen(value) + 1) * sizeof(char));
  strcpy(node->value, value);
  node->next = NULL;
  return node;
}

int compareTime(struct t_time t1, struct t_time t2)
{
  if (t1.hours != t2.hours)
  {
    return t1.hours > t2.hours ? 1 : -1;
  }
  else if (t1.minutes != t2.minutes)
  {
    return t1.minutes > t2.minutes ? 1 : -1;
  }
  else if (t1.seconds != t2.seconds)
  {
    return t1.seconds > t2.seconds ? 1 : -1;
  }
  else
  {
    return 0;
  }
}

void insert(struct t_timetable **head, struct t_time key, char *value)
{
  struct t_timetable *node = createNode(key, value);
  if (*head == NULL)
  {
    *head = node;
  }
  else
  {
    struct t_timetable *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = node;
  }
}

void put(struct t_timetable **head, struct t_time key, char *value)
{
  if (value == NULL)
  {
    remove(head, key);
  }
  else
  {
    insert(head, key, value);
  }
}

char *get(struct t_timetable *head, struct t_time key)
{
  return search(head, key);
}

bool contains(struct t_timetable *head, struct t_time key)
{
  return search(head, key) != NULL;
}

void delete(struct t_timetable **head, struct t_time key)
{
  if (*head == NULL)
  {
    return;
  }
  if (compareTime((*head)->key, key) == 0)
  {
    struct t_timetable *temp = *head;
    *head = (*head)->next;
    free(temp->value);
    free(temp);
  }
  else
  {
    struct t_timetable *current = *head;
    while (current->next != NULL && compareTime(current->next->key, key) != 0)
    {
      current = current->next;
    }
    if (current->next != NULL)
    {
      struct t_timetable *temp = current->next;
      current->next = current->next->next;
      free(temp->value);
      free(temp);
    }
  }
}

bool is_empty(struct t_timetable *head)
{
  return head == NULL;
}

int size(struct t_timetable *head)
{
  int count = 0;
  struct t_timetable *current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

struct t_time min(struct t_timetable *head)
{
  if (head == NULL)
    return (struct t_time){0, 0, 0};
  struct t_timetable *current = head;
  struct t_time min = current->key;
  while (current != NULL)
  {
    if (compareTime(current->key, min) < 0)
    {
      min = current->key;
    }
    current = current->next;
  }
  return min;
}

struct t_time max(struct t_timetable *head)
{
  if (head == NULL)
    return (struct t_time){0, 0, 0};
  struct t_timetable *current = head;
  struct t_time max = current->key;
  while (current != NULL)
  {
    if (compareTime(current->key, max) > 0)
    {
      max = current->key;
    }
    current = current->next;
  }
  return max;
}

struct t_time floor(struct t_timetable *head, struct t_time key)
{
  struct t_time floor = (struct t_time){0, 0, 0};
  struct t_timetable *current = head;
  while (current != NULL)
  {
    if (compareTime(current->key, key) <= 0 && compareTime(current->key, floor) > 0)
    {
      floor = current->key;
    }
    current = current->next;
  }
  return floor;
}

struct t_time ceiling(struct t_timetable *head, struct t_time key)
{
  struct t_time ceiling = (struct t_time){24, 60, 60};
  struct t_timetable *current = head;
  while (current != NULL)
  {
    if (compareTime(current->key, key) >= 0 && compareTime(current->key, ceiling) < 0)
    {
      ceiling = current->key;
    }
    current = current->next;
  }
  return ceiling;
}

int rank(struct t_timetable *head, struct t_time key)
{
  int rank = 0;
  struct t_timetable *current = head;
  while (current != NULL)
  {
    if (compareTime(current->key, key) < 0)
    {
      rank++;
    }
    current = current->next;
  }
  return rank;
}

struct t_time select(struct t_timetable *head, int k)
{
  int rank = 0;
  struct t_timetable *current = head;
  while (current != NULL)
  {
    if (rank == k)
    {
      return current->key;
    }
    rank++;
    current = current->next;
  }
  return (struct t_time){0, 0, 0};
}

void delete_min(struct t_timetable **head)
{
  if (*head == NULL)
  {
    return;
  }
  struct t_timetable *current = *head;
  struct t_timetable *min_prev = NULL;
  struct t_timetable *min = current;
  while (current->next != NULL)
  {
    if (compareTime(current->next->key, min->key) < 0)
    {
      min_prev = current;
      min = current->next;
    }
    current = current->next;
  }
  if (min_prev == NULL)
  {
    *head = min->next;
  }
  else
  {
    min_prev->next = min->next;
  }
  free(min->value);
  free(min);
}

void delete_max(struct t_timetable **head)
{
  if (*head == NULL)
  {
    return;
  }
  struct t_timetable *current = *head;
  struct t_timetable *max_prev = NULL;
  struct t_timetable *max = current;
  while (current->next != NULL)
  {
    if (compareTime(current->next->key, max->key) > 0)
    {
      max_prev = current;
      max = current->next;
    }
    current = current->next;
  }
  if (max_prev == NULL)
  {
    *head = max->next;
  }
  else
  {
    max_prev->next = max->next;
  }
  free(max->value);
  free(max);
}

int size_range(struct t_timetable *head, struct t_time lo, struct t_time hi)
{
  int count = 0;
  struct t_timetable *current = head;
  while (current != NULL)
  {
    if (compareTime(current->key, lo) >= 0 && compareTime(current->key, hi) <= 0)
    {
      count++;
    }
    current = current->next;
  }
  return count;
}

struct t_time *keys(struct t_timetable *head, struct t_time lo, struct t_time hi)
{
  int count = 0;
  struct t_timetable *current = head;
  while (current != NULL)
  {
    if (compareTime(current->key, lo) >= 0 && compareTime(current->key, hi) <= 0)
    {
      count++;
    }
    current = current->next;
  }
  struct t_time *keys = (struct t_time *)malloc(sizeof(struct t_time) * count);
  current = head;
  count = 0;
  while (current != NULL)
  {
    if (compareTime(current->key, lo) >= 0 && compareTime(current->key, hi) <= 0)
    {
      keys[count++] = current->key;
    }
    current = current->next;
  }
  return keys;
}
