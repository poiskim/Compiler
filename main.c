#include <stdio.h>
#include <stdlib.h>
#include "funs.h"

extern int line_no, syntax_err, semantic_err, gen_err;
extern A_NODE *root;
FILE *fout;
char *fname = "output.txt";

int yyparse();
void print_ast(A_NODE *);
void print_sem_ast(A_NODE *);

void main(void){
    if((fout = fopen(fname, "w")) == NULL){
        fprintf(stderr, "fopen error for %s\n", fname);
    }
    printf("start syntax analyze...\n");
    initialize();
    yyparse();
    if(syntax_err) exit(1);
    // print_ast(root);
    semantic_analysis(root);
    if (semantic_err) exit(1);
    // print_sem_ast(root);
    code_generation(root);
    exit(0);
}
