#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[100];
    char matricula[5];
    float p1;
    float p2;
    float p3;
};

void leitura (struct aluno *tAluno, FILE *read_file){
    fscanf (read_file, "%s", tAluno->nome);
    fscanf (read_file, "%s", (tAluno->matricula));
    fscanf (read_file, "%f", &(tAluno->p1));
    fscanf (read_file, "%f", &(tAluno->p2));
    fscanf (read_file, "%f", &(tAluno->p3));
}

float Media (struct aluno *tAluno){
    float media;
    media = tAluno->p1 + tAluno->p2 + tAluno->p3;
    media /= 3;
    return media;
}

void escrita (struct aluno *tAluno, FILE *write_file){
    fprintf (write_file, "%s ", tAluno->nome);
    fprintf (write_file, "%s ", tAluno->matricula);
    fprintf (write_file, "%.2f\n", Media(tAluno));
}

int main(){
    FILE *read_file;
    FILE *write_file;
    struct aluno *tAluno = (struct aluno*) malloc(sizeof(struct aluno));
    float media;
    int i;
    
    //abertura de arquivo
    read_file = fopen("lista_alunos.txt", "r");
    write_file = fopen("media_alunos.txt", "w+");
    
    //while(fgetc(read_file) != EOF){
    for(i=0; i<50; i++){
        leitura(tAluno, read_file);
        escrita(tAluno, write_file);
    }
    
    //fechamento do arquivo
    fclose(read_file);
    fclose(write_file);
    return 0;
}