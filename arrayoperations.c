//
// Created by rodrigo on 2/16/23.
//
//    exercise: dobre a definição e uso de varaiveis do tipo ArrayBi a ser definido com typedef.....
//    escrever o texto da linha seguinte no terminal do ubuntu (unix) para compilar/linkar
//


#include <stdio.h>  //contém funções de ler do teclado e de escrever no terminal
#include <math.h>   //contém funções matemáticas
#include <stdlib.h> //contém funções matemáticas e outras
#include <stdbool.h>//contém os valores booleanos - os literais C true e false

#include <string.h> //contém funções de tratamento de cadeias de caracteres
#include <time.h>   //contém funções sobre contagem de tempo
#include <limits.h> //contém as constantes e domínio dos tipos C
#include <ctype.h>  //contém funções de tratamento de caracteres


#define MAX_LINHAS 5
#define MAX_COL    8

typedef int ArrayBi[ MAX_LINHAS ][ MAX_COL ];

// assinaturas das funções
void arrayBi_init( ArrayBi m, int x, int y, int lin, int col, int v );
void arrayBi_write( ArrayBi m, int x, int y, int lin, int col);
int arrayBi_maior( ArrayBi m, int x, int y, int lin, int col);


// definições das funções
void arrayBi_init( ArrayBi m, int x, int y, int lin, int col, int v)
{
    for( int i=y; i<=lin; ++i ){
        for( int j=x; j<=col; ++j ){
            m[i][j] = v;
        }
    }
}

void arrayBi_write( ArrayBi m, int x, int y, int lin, int col )
{
    for( int i=y; i<=lin; ++i ){
        for( int j=x; j<=col; ++j ){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

///TPC do dia 6/12/2021 _retornar o maior de entre todos do array bidimensional m contidos entre x,y e lin,col
int arrayBi_maior( ArrayBi m, int x, int y, int lin, int col )
{
    int ma = m[0][0];
    for( int i=y; i<=lin; ++i ){
        for( int j=x; j<=col; ++j ){
            if( m[i][j] > ma ) { ma=m[i][j]; }
        }
    }
    return ma;
}
///realize a função que soma linha a linha de m dado por x,y até lin,col e coloca o resultado em h
void arrayBi_add_horizontal( ArrayBi m, int x, int y, int lin, int col, int h[] )
{
    ////// FALTA IMPLEMENTAR


}
///realize a função que soma coluna a coluna de m dado por x,y até lin,col e coloca o resultado em h
void arrayBi_add_vertical( ArrayBi m, int x, int y, int lin, int col, int v[] )
{
    ////// FALTA IMPLEMENTAR


}
int main( void )
{
    int matriz[MAX_LINHAS][MAX_COL];
    arrayBi_init( matriz, 0,0, MAX_LINHAS-1, MAX_COL-1, 0);
    arrayBi_init( matriz, 2,2, 4,4, 1);

    matriz[3][7] = 15;
    arrayBi_write( matriz, 0,0, MAX_LINHAS-1, MAX_COL-1 );


    int res = arrayBi_maior( matriz, 0,0, MAX_LINHAS-1, MAX_COL-1 );
    printf("O maior do array = %d\n", res );


    /////// FALTA CHAMAR AS FUNÇÔES que TERÁ de completar a definição
    return 0;
}
