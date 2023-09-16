#include <stdio.h>

#define MEMSIZE 3000

int w_mem[MEMSIZE];
int ip; // instruction pointer

int next_char(void);
void process_char(char ch);
void process_loop(void);
void end_loop(void);

int main() {
  for(;;) {
    char ch = next_char();
    process_char(ch);
  }

  return 0;
}

int next_char() {
  return getchar();
}

void process_char(char ch) {
  switch(ch) {
    case '+': 
      {
        w_mem[ip]++;
        break;
      }
    case '-': 
      {
        w_mem[ip]--;
        break;
      }
    case '>':
      {
        ip++;
        break;
      }
    case '<':
      {
        ip--;
        break;
      }
    case '.': 
      {
        printf("%c", w_mem[ip]);
        break;
      }
    case ',':
      {
        scanf("%d", w_mem + ip);
        break;
      }
    case '[':
      {
        process_loop();
        break;
      }
    case ']':
      {
        end_loop();
        break;
      }
  }
}

void process_loop() {};

void end_loop() {};

