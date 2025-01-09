#include "s21_cat.h"

int main(int argc, char *argv[]) {
  opt options = {0};
  parser(argc, argv, &options);
  reader(argc, argv, &options);
}

void parser(int argc, char *argv[], opt *options) {
  int opt;
  int option_index;

  static struct option long_option[] = {
      {"blank", 0, 0, 'b'},  {"dollar", 0, 0, 'e'}, {"number", 0, 0, 'n'},
      {"squuez", 0, 0, 's'}, {"tabul", 0, 0, 't'},  {"value", 0, 0, 'v'},
      {0, 0, 0, 0}};
  while ((opt = getopt_long(argc, argv, "+benstvTE", long_option,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'T':
        options->T = 1;
        break;
      case 'E':
        options->E = 1;
        break;
      default:
        printf("No such arguments");
        break;
    }
  }
}

void reader(int argc, char **argv, opt *options) {
  char *DIR;
  FILE *f;
  for (int i = optind; i < argc; i++) {
    DIR = argv[i];

    if ((f = fopen(DIR, "r")) == NULL) {
      printf("%s: No such file or directory", DIR);
    } else {
      printfile(f, options);
      fclose(f);
    }
  }
}
void prChar(unsigned char symbol, int v) {
  if (v == 1) {
    if (symbol < 32 && symbol != '\t' && symbol != '\n') {
      symbol += 64;
      printf("^%c", symbol);
    } else if (symbol == 127) {
      printf("^?");
    } else if (symbol > 127 && symbol < 160) {
      symbol -= 64;
      printf("M-^%c", symbol);
    } else {
      printf("%c", symbol);
    }
  } else {
    printf("%c", symbol);
  }
}
void printfile(FILE *f, opt *options) {
  char buffer[BUFSIZE] = {0};
  int str_count = 1;
  int isSpace = 0;

  while (fgets(buffer, BUFSIZE, f) != NULL) {
    if (options->b && buffer[0] != '\n') {
      printf("%6d\t", str_count++);
    }
    if (options->s) {
      if (!isSpace && options->s && buffer[0] == '\n') {
        isSpace = 1;
      } else if (isSpace && options->s && buffer[0] == '\n') {
        continue;
      } else if (isSpace && buffer[0] != '\n') {
        isSpace = 0;
      }
    }
    if (options->n && !options->b) {
      printf("%6d\t", str_count++);
    }
    for (size_t i = 0; i < strlen(buffer); i++) {
      if ((options->T || options->t) && buffer[i] == '\t') {
        printf("^");
        buffer[i] += 64;
      }
      if ((options->E || options->e) && buffer[i] == '\n' && options->b &&
          i == 0) {
        printf("      \t$");
      } else if ((options->E || options->e) && buffer[i] == '\n') {
        printf("$");
      }
      prChar(buffer[i], options->v);
    }
  }
}