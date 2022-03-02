#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80
#define R 5

struct circle {
  float x, y, r;
} c;

struct triangle {
  float x1, x2, x3, y1, y2, y3;
} tr;

double chisla(char *str, int *i);  //функция проверки числа

int main() {
  int i;
  char m1[N] = "circle";
  char m2[N] = "triangle";
  char m3[N];

  FILE *file;
  file = fopen("F.txt", "r");

  // Проверка открытия файла
  printf("Открытие файла:");
  if (file == NULL)
    printf("ошибка\n");
  else
    printf("выполнено\n");

  while (fgets(m3, N, file) != NULL) {
    if (strncmp(m1, m3, R) == 0) {
      i = 7;
      c.x = chisla(m3, &i);
      c.y = chisla(m3, &i);
      c.r = chisla(m3, &i);
      printf("Circle: (%0.0f %0.0f) R = %0.2f\n", c.x, c.y, c.r);
    } else if (strncmp(m2, m3, R) == 0) {
      i = 9;
      tr.x1 = chisla(m3, &i);
      tr.y1 = chisla(m3, &i);
      tr.x2 = chisla(m3, &i);
      tr.y2 = chisla(m3, &i);
      tr.x3 = chisla(m3, &i);
      tr.y3 = chisla(m3, &i);
      printf("Triangle: (%0.0f %0.0f) (%0.0f %0.0f) (%0.0f %0.0f)\n", tr.x1,
             tr.y1, tr.x2, tr.y2, tr.x3, tr.y3);
    } else {
      printf("Error\n");
    }
  }
  return 0;
}

// FUNCTION

double chisla(char *str, int *i)  //функция проверки числа
{
  double result = 0;
  :double div = 10;
  int sign = 1;

  while (result == 0) {
    if (str[*i] == '-')  //проверка на отрицательное число
    {
      sign = -1;
      ++*i;
    }

    while (str[*i] >= '0' && str[*i] <= '9') {
      result = result * 10.0 + (str[*i] - '0');

      ++*i;
    }

    if (str[*i] == '.')  //проверка на десятичную дробь
    {
      ++*i;

      while (str[*i] >= '0' && str[*i] <= '9') {
        result = result + (str[*i] - '0') / div;
        div *= 10;

        ++*i;
      }
    }
    ++*i;
  }

  return sign * result;
}
