//
// Created by rodrigo on 2/15/23.
//
//   Exercise: program that generates the euromillions key in the Terminal and graphical console

#include <stdio.h>  // para as funções de ler do teclado e escrever no terminal
#include <math.h>   // para se usar funções matemáticas
#include <stdlib.h> // para se usar funções matemáticas e outras
#include <string.h> // para se usar funções de tratamento de cadeias de caracteres
#include <time.h>   // para se usar funções sobre contagem de tempo
#include <limits.h> // para sabermos as constantes de domínio dos tipos C
#include <ctype.h>  // para se usar funções de tratamento de caracteres
#include <stdbool.h>// para usar os valores booleanos - os literais C true e false

/// ASSINATURAS  ============================================================
/**
 * retorna um nº aleatorio dentro do intervalo [inf,sup], onde inf e sup serão
 * os valores recebidos a partir dos argumentos quando a função é chamada
 */
int numeroAleatorio( int inf, int sup );
/**
 * retorna true ou false respetivamente se x igual a y ou não, onde x e y são
 * os valores recebidos a partir dos argumentos quando a função é chamada
 */
bool igual( long double x, long double y );
/**
 * retorna o maior valor de entre se x e y, onde x e y são os valores
 * recebidos a partir dos argumentos quando a função é chamada
 */
long double  maior( long double x, long double y );
/**
 * retorna o menor valor de entre se x e y, onde x e y são os valores
 * recebidos a partir dos argumentos quando a função é chamada
 */
long double  menor( long double x, long double y );

/**
 * retorna o menor valor contido no array v entre os indices inicio e fim, onde estes
 * parametros são "carregados" partir dos argumentos quando a função é chamada.
 * chama a função menor()
 */
int menorArray( int v[], int inicio, int fim );
/**
 * retorna o maior valor contido no array v entre os indices inicio e fim, onde estes
 * parametros são "carregados" partir dos argumentos quando a função é chamada
 * chama a função maior()
 */
int maiorArray( int v[], int inicio, int fim );
/**
 * retorna true ou false respetivamente se existir no array v um valor igual elem ou não, onde
 * todos os parametros são "carragados" a partir dos argumentos quando a função é chamada.
 * chama a função igual()
 */
bool igualEmArray( int v[], int elem, int inicio, int fim );
/**
 * escreve no terminal o texto contido em txt e os valores contidos no array v entre os
 * indices inicio e fim o no final da escrrita ainda ecreve o caracter contido em c, onde
 * estes parametros são "carregados" partir dos argumentos quando a função é chamada.
 */
void escreverArray( const char txt[], int v[], int inicio, int fim, char c );
/**
 * Escreve no terminal os valores contidos em v de forma ordenada crescente desde os indices
 * inicio e fim.
 * NOTA: o algoritmo de ordenação usado está baseado no conhecimentos dos valores inteiros
 * armazenados no array, ou seja, sabemos que os valores estão DENTRO dum certo INTERVALO e
 * NUNCA fora desse intervalo. O algoritmo tira partido deste conhecimento. Este algoritmos
 * de ordenação NÃO É eficiente.
 */
void escreverOrdenarArray( int v[], int inicio, int fim );


/**
 * faz a copia do array v para m e faz a ordenação crescente os valores contidos em m
 */
void ordenar( int v[], int inicio, int fim, int m[] );

/// ===================================================================
int main( void ){

    srand( time( NULL ) );/// arraque da iniciação dos nº aleatorios
    int aposta[7];        /// armazena 5 + 2 aleatorios


    int i=0; bool b;
    do{
        if( i<=4 ){
            aposta[i] = numeroAleatorio( 1, 50 );
            if( !(b=igualEmArray(aposta, aposta[i], 1, i)) ) i++;
        }
        else{
            aposta[i] = numeroAleatorio( 1, 12 );
            if( !(b=igualEmArray(aposta, aposta[i], 5, i)) ) i++;
        }
    }while( i<7 );

    escreverArray("Aposta NÂO ordenada:\n", aposta, 0, 5, '+' );
    escreverArray( "", aposta, 5, 7, '\n' );

    printf("Aposta     ORDENADA:\n");
    escreverOrdenarArray(aposta, 0, 5);
    printf("  +");
    escreverOrdenarArray(aposta, 5, 7);
    printf("\n");
    int apostaOrd[7];
    ordenar( aposta, 0, 5, apostaOrd);
    ordenar( aposta, 5, 7, apostaOrd);
    escreverArray("Aposta  ordenada em apostaOrd:\n", apostaOrd, 0, 7, '\n' );


///    PARTE GRAFICA ============================
/** Há 3 tipos e tamanhos de letras com estas dimensões
   LARGE_FONT  - 20x26
   MEDIUM_FONT - 10x16
   SMALL_FONT  -  8x10
   */
    //Todo o programa grafico em PG1 se inicia com a chamada da função seguinte
    graph_init2("Euro Milhoes",600, 500);

    /// converte aposta dos nº inteiros em string de digitos dos mesmos nº
    char strNum[7][3]; //7 numeros e cada numero tem 3 caracteres =2 digitos + terminador
    for( int i=0; i<7; ++i ) sprintf(strNum[i],"%2d",aposta[i]);


    ///medidas: x-abcissa, y-ordenada, deltaX é o valor para cada caracter e espaçamento
    int x =   10,
            y =  100,
            deltaX= 2*(20+5);  /// 50=20 para largura e 5 para espaçamento entre
    RGB cor = c_red;

    // assinaturas de duas funções da biblioteca gráfica de PG1   que iremos usar
    // void graph_text( short x, short y, RGB color, char text[], int fontsize );
    // bool graph_image(const char *path, int x, int y, int width, int height);

    ///escrever os numeros da aposta euromilhões na consola grafica PG1
    graph_text( x, (y-26-10), cor, "Chave Euro Milhoes nao ordenada:", MEDIUM_FONT);      /// escreve o titulo

    for( int i=1; i<=7; ++i ) graph_text( x+(i*deltaX), y, cor, strNum[i-1], LARGE_FONT );/// escrever 7 digitos


/// ================== sobre manipulação de imagens =========================================
    graph_text( x, y+30, cor, "Chave ordenada  em imagens  ", MEDIUM_FONT);  /// escreve o titulo


    /// tabela com os nomes dos ficheiro img dos nº de 0,1,2, ...50  e cada nome tem 7 caracteres
    char nomesImg[51][6+1]={"", "1.jpg", "2.jpg", "3.jpg", "4.jpg", "5.jpg",
                            "6.jpg", "7.jpg", "8.jpg", "9.jpg", "10.jpg", "11.jpg", "12.jpg",
                            "13.jpg", "14.jpg", "15.jpg", "16.jpg", "17.jpg", "18.jpg",
                            "19.jpg", "20.jpg", "21.jpg", "22.jpg", "23.jpg", "24.jpg", "25.jpg",
                            "26.jpg", "27.jpg", "28.jpg", "29.jpg", "30.jpg", "31.jpg", "32.jpg",
                            "33.jpg", "34.jpg", "35.jpg", "36.jpg", "37.jpg", "38.jpg",
                            "39.jpg", "40.jpg", "41.jpg", "42.jpg", "43.jpg", "44.jpg", "45.jpg",
                            "46.jpg", "47.jpg", "48.jpg", "49.jpg", "50.jpg",};

    ///nome da pasta das figuras em disco é n, nome ficheiro imgDigito + restante nome
    char img0[11+6+1]="n/imgDigito";
    char  img[11+6+1]="";

    int yy = y+26+10, // inicio da imagem no eixo YY
    x0 =      20, // inicio da imagem no eixo XX
    dx =   60+20; // 60 dimensão figDoNumero + 20 separador entre nº = 60 no eixo  XX+

    for( int i=0; i<7; ++i ) {
        strcpy(img,img0);                          /// inicia com nome inicial da pasta onde estão as figuras
        strcat(img, nomesImg[ apostaOrd[i] ]);     /// acrescenta ao nome da pasta o nome do ficheiro
        graph_image( img, x0+(i*dx),  yy, 60, 60 );/// afixa a imagem que está em img no posição em x, y de 60 por 60

        if( i==5 ) { graph_image("n/sinalMais.jpg", x0+(i*dx)-20,  yy+15, 20, 20); }//sinalMais.jpg
    }

//Todo o programa grafico em PG1 tem a chamada da função seguinte para manter "viva" a consola grafica
    graph_start();


    return 0;
}

/// ===================================================================

/// DEFINIÇÕES para cada umas das assinaturas previamente escritas   ========================
int numeroAleatorio( int inf, int sup ){
    return inf + rand()%(sup-inf+1);
}

bool igual( long double x, long double y ){
    return (fabsl(x-y)<=10E-15);/// x,y são iguais se a sua diferença for menor ou igual a 10 elevado a -15
}

long double maior( long double x, long double y ){
    return x>y ? x : y;
}

long double menor( long double x, long double y ){
    return x<y ? x : y;
}
/// ========== as funções seguintes operam array ===================

int menorArray( int v[], int inicio, int fim ){
    int m=v[inicio];
    for( int i=inicio+1; i<fim; ++i )
        m=menor( m, v[i] );
    return m;
}

int maiorArray(int v[], int inicio, int fim ){
    int m=v[inicio];
    for( int i=inicio+1; i<fim; ++i )
        m=maior( m, v[i] );
    return m;
}

void escreverArray( const char txt[], int v[], int inicio, int fim, char c ){
    printf("%s", txt );
    int m=maiorArray(v, inicio, fim );
    int t = (int)(log10(m))+2;
    for( int i=inicio; i<fim; ++i ) printf("%*d", t, v[i] );
    printf("%*c", t, c );
}

bool igualEmArray( int v[], int elem, int inicio, int fim ){
    for( int i=inicio; i<fim; ++i )
        if( igual( elem, v[i]) ) return true;
    return false;
}

void escreverOrdenarArray(int v[], int inicio, int fim){
    int me = menorArray(v, inicio, fim);
    int ma = maiorArray(v, inicio, fim);
    int t = (int)(log10(ma))+2;
    for(int i=me ; i<=ma; ++i)
        if( igualEmArray( v, i, inicio, fim ) ) printf("%*d", t, i );
}

void copiar( int v[], int inicio, int fim, int m[] ){
    for( int i=inicio; i<fim; ++i ) m[i]=v[i];
}

void trocar(int v[], int inicio, int fim ){
    int x = v[inicio]; v[inicio] = v[fim]; v[fim] = x;
}
void trocarAp(int *a1, int *a2 ){
    int x = *a1; *a1 = *a2; *a2 = x;
}
void ordenar( int v[], int inicio, int fim, int m[] ){
    copiar(v, inicio,  fim, m );
    for( int i=inicio; i<fim; ++i )
        for(int j=i+1;j<fim; ++j )
            if( m[j] < m[i] )   /// ordem crescente tem haver com o < e decrescente com o >
                trocar( m, i, j); /// troca os valores de m que se encontam nos indices i,j
    ///trocarAp( &m[i],&m[j] ); /// troca os valores &m[i] com &m[j] ounde se passa o endereço
}


