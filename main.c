#include <stdio.h>

#define MEMSIZE 30000
#define MAXLOOPDEPTH 1000

int w_mem[MEMSIZE]; // working memory
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

void process_loop() {
  int instructions[MAXLOOPDEPTH];
  int curr_pos = 0;
  int nest_level = 1;

  while(nest_level) {
    int next = next_char();
    if (next == '[') {
      nest_level++;
    }
    if (next == ']') {
      nest_level--;
      if(!nest_level) break;
    }
    instructions[curr_pos++] = next;
  }

  while(w_mem[ip]) {
    for(int i = 0; i < curr_pos; i++) {
      process_char(instructions[i]);
    }
  }
};

void end_loop() {};

