#ifndef HEADER_H
#define HEADER_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

typedef struct options {
  int b, e, n, s, t, v, T, E;
} opt;

void reader(int argc, char **argv, opt *options);
void parser(int argc, char *argv[], opt *options);
void prChar(unsigned char symbol, int v);
void printfile(FILE *f, opt *options);

#endif
