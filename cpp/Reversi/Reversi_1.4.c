//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
//------------------------------------------------------------------------------
#define DIR 25
#define ESQ 5
#define COLORA 15
#define COLORB 8
#define COLORC 10

//------------------------------------------------------------------------------
typedef enum {true, false} bool;

typedef struct no{
        int pontos;
        int jog;
        struct no* prox;
}noLista;
//==============================================================================
                                  //REVERSI
//==============================================================================
//Funções

//Inicializa tabuleiro e contador de pecas a serem capturadas pelo CPU
void inicializaTab ();
//Imprime trabuleiro
void imprimeTab (int linha, int coluna);
//Verifica se a jogada será passada ou não
void jogarOuPassar (int jogador);
//Controla as jogadas do jogador 1 ou 2. 
//Retorna true(1) se a jogada foi válida ou false(0)caso contrário
bool jogadores (int jogador, int linha, int coluna, char peca1, char peca2);
//Controla as condições de encerramento da partida
//Retorna false se o jogo acabou
int controlaJogo ();
//Percorre o tabuleiro verificando se os jogadores tem jogadas disponíveis
bool escaneaTab (int jogador, int linha, int coluna, char peca1, char peca2);
//Conta quantidade de peças do tabuleiro dos dois jogadores
int contaPeca (int jogador, char peca);
//Controla cursor que seleciona posição do tabuleiro
void controlaCursor (int jogador, char peca1, char peca2);
//Analisa melhor jogada para o computador
void melhorJogada ();
//Menu principal do jogo
int menu ();
//Imprime a ajuda do menu principal
void ajudaMenu ();
//Imprime a ajuda do menu de opções
void ajudaOptions ();
//Menu de opções do jogo
int Options ();
//controla o jogo para dificuldade normal
void rotinaJogo (int modoDeJogo);
//Imprime o logotipo do jogo
void logotipo();
//Insere pontuação dos jogadores em uma lista
void ranking (int quant, int jogador);
//Imprime lista de pontos
void imprimeRank ();
//==============================================================================
//Variáveis globais

//Variável que guarda tabuleiro
char tab [12][12];
//tamanho inicial do tabuleiro
int tamanho = 8; 
//Guarda a figura q representa o tabuleiro
char mcTab = 176;
//Guarda a quantidade de peças a serem capturadas pelo CPU em cada casa
int pecaComputador [12][12];
//Determina se o modo de jogo VS computadore (1) ou outro jogador (2).
int modoDeJogo = 1;
//do menu de options, guarda a opção de dificuldade.
int optionsDif = 0;
//Guarda endereço do primeiro elemento da lista;
noLista* prim = NULL;
//==============================================================================
//Função principal
int main (int argc, char* argv[]){
    int quantJog1, quantJog2, resposta;
    logotipo ();
    menu ();
do{
    inicializaTab ();
    clrscr();
    

//------------------------------------------------------------------------------
//Modo de dificuldade normal
  //  if (optionsDif == 0){
                   rotinaJogo (modoDeJogo);
                //   }//if
//modo de dificuldade good lucky
  /*  else{
         difHard (modoDeJogo);
         }//else*/
         
//------------------------------------------------------------------------------
//Contagem de peças dos jogadores
    quantJog1 = contaPeca (1, 'X') ;
    quantJog2 = contaPeca (2, 'O');
    imprimeTab ((tamanho/2) - 1,tamanho/2);
    textcolor (15); 
    printf ("\n\n- Quantidade de pecas jogador 1: %d", quantJog1);
    printf ("\n- Quantidade de pecas jogador 2: %d", quantJog2);
//------------------------------------------------------------------------------
    
if (quantJog1 > quantJog2){
              textcolor (14);
              printf ("\n\nJogador 1 venceu! Parabens!");
              ranking (quantJog1,1);
              getch();
              imprimeRank ();
              }//if
else{
     if (quantJog1 < quantJog2){
            if (modoDeJogo == 1){
                   textcolor (3);
                   printf ("\n\nComputador venceu.");
                   }//if
            else{
                  textcolor (3);
                   printf ("\n\nJogador 2 venceu! Parabens!");
                   ranking (quantJog2,2);
                   getch();
                   imprimeRank ();
                   }//else
                                }//if
                   else{
                        textcolor (8);
                        printf ("\n\nEmpate");
                        }//else
}//else
//------------------------------------------------------------------------------
  //  textcolor (15); 
   // printf ("\n\n- Quantidade de pecas jogador 1: %d", quantJog1);
   // printf ("\n- Quantidade de pecas jogador 2: %d", quantJog2);
   // getch();
   // ranking (quantJog1,1);
    //ranking (quantJog2,2);
   // imprimeRank ();
    getch();
    printf("\n\nPressione qualquer tecla para voltar ao menu...");    
    getch();
    
} while (menu () != 0); 
    printf("\n\n\n"); 
    system ("pause");
 // return 0;
    exit (0);
}//main

//==============================================================================
//Inicializa tabuleiro e contador de pecas a serem capturadas pelo CPU
void inicializaTab (){
     int i, j;
     
for ( i=0; i<tamanho; i++){
    for ( j=0; j<tamanho; j++){
        
    tab [i][j] = mcTab;
    pecaComputador [i][j] = 0;
                          }//for
                     }//for
                                                       
      tab [(tamanho/2) - 1][(tamanho/2) - 1] = 'O';
      tab [(tamanho/2) - 1][tamanho/2] = 'X';
      tab [tamanho/2][(tamanho/2) - 1] = 'X';
      tab [tamanho/2][tamanho/2] = 'O';                                    
                                                    
}//inicilizaTab

//==============================================================================
//Imprime tabuleiro
void imprimeTab (int linha, int coluna){
     int i = 0, j = 0;
        
    textcolor (14);
    printf (" > Jogador 1 pecas: ");
    textcolor (15);
    printf ("%d", contaPeca (1, 'X'));
    textcolor (3);
    printf ("\t\t\t\t\t> Jogador 2 pecas: ");
    textcolor (15);
    printf ("%d", contaPeca (2, 'O'));
                                                           
for ( i=0; i<tamanho; i++){       
    //Guarda o numero das casas verticais          
          printf("\n\n\t\t      ");
    
    for ( j=0; j<tamanho; j++){
          
        if (tab [i][j] == 'O'){                     
                      textcolor (3);                      
                      }//if
        if (tab [i][j] == 'X'){    
                      textcolor (14);
                      }//if
        if ((i == linha)&&(j == coluna)){    
                      textbackground (8);
                      }//if
           
    printf(" %c ", tab [i][j]);
    textbackground (0);   
    textcolor (15);    
                          }//for              
                     }//for
 
}//imprimeTab
     
//==============================================================================
//Verifica se a jogada será passada ou não
void jogarOuPassar (int jogador){
     char opcao, peca, peca1, peca2; 
     int i = ESQ, color1 = COLORA, color2 = COLORB; 
      
do{  
     clrscr(); 
     imprimeTab((tamanho/2) - 1,tamanho/2);
     if (jogador == 1){
                 textcolor (14);
                 peca = 'X';
                 }//if
     else{
          textcolor (3);
          peca = 'O';
          }//else
          
     printf("\n\n- Jogador  %d (%c):", jogador, peca);  
     printf("\n\n");
     textcolor(color1);   
     printf ("[ Passar jogada ]   ");
     textcolor(color2);  
     printf ("[ Jogar ]");
     
     opcao = getch(); 
          
switch (jogador){
       case 2:
            switch (opcao){//Menu que seleciona a opção de passar ou não a jogada
//------------------------------------------------------------------------------       
         case 77 : //Seta direita
               if(i == ESQ){
                    i = DIR;
                    color1 = COLORB;
                    color2 = COLORA;
                    }//if                                 
   
                  ;break;
//------------------------------------------------------------------------------
         case 75 : //Seta esquerda
               if(i == DIR){
                    i = ESQ;
                    color1 = COLORA;
                    color2 = COLORB;
                    }//if                                 
                            
                  ;break;
//------------------------------------------------------------------------------
         case 27 : //Se a tecla ESC for pressionada, volta para menu.
               
               inicializaTab ();
               modoDeJogo = menu();                                  
                  ;break;
//------------------------------------------------------------------------------                  


}//switchCase2
       ;break;
       case 1:
            switch (opcao){//Menu que seleciona a opção de passar ou não a jogada
//------------------------------------------------------------------------------       
         case 'f' : //Seta direita
               if(i == ESQ){
                    i = DIR;
                    color1 = COLORB;
                    color2 = COLORA;
                    }//if                                 
   
                  ;break;
         case 'F' : //Seta direita
               if(i == ESQ){
                    i = DIR;
                    color1 = COLORB;
                    color2 = COLORA;
                    }//if                                 
   
                  ;break;
//------------------------------------------------------------------------------
         case 's' : //Seta esquerda
               if(i == DIR){
                    i = ESQ;
                    color1 = COLORA;
                    color2 = COLORB;
                    }//if                                 
                            
                  ;break;
         case 'S' : //Seta esquerda
               if(i == DIR){
                    i = ESQ;
                    color1 = COLORA;
                    color2 = COLORB;
                    }//if                                 
                            
                  ;break;
//------------------------------------------------------------------------------
         case 27 : //Se a tecla ESC for pressionada, volta para menu.
               
               inicializaTab ();
               modoDeJogo = menu();                                  
                  ;break;
//------------------------------------------------------------------------------             
      
}//switchCase1 
       ;break;
 
}//switch 

}while ((opcao != 13)&&(opcao != 32));//Até pressionar ENTER  
       
       if (i == ESQ){//Se escolheu passar a jogada
             textcolor(15); 
             printf ("\n\n\tJogador %d passou a vez.", jogador);
             sleep(2000);   
             return;
             }//if
       else{
            if (jogador == 1){
                        peca1 = 'O';
                        peca2 = 'X';
                        }//if
            else{
                 peca1 = 'X';
                 peca2 = 'O';
                 }//else
                 
            controlaCursor(jogador, peca1, peca2);     
                       
            }//else  
}//jogadas

//==============================================================================
//Controla as jogadas do jogador 1 ou 2
bool jogadores (int jogador, int linha, int coluna, char peca1, char peca2){
     int contador, a, cont = 0;
     char peca;
     
   clrscr();
   imprimeTab ((tamanho/2) - 1, tamanho/2);
     
if (jogador == 1){
                 textcolor (14);
                 peca = 'X';
                 }//if
     else{
          textcolor (3);
          peca = 'O';
          }//else
        
     printf("\n\nJogador  %d (%c):", jogador, peca); 
     textcolor(15);

//------------------------------------------------------------------------------
if (tab [linha][coluna] == mcTab){//Se a lugar onde a peça será colocada está vazia

//Se a vizinhança da casa escolhida estiver sem peças      
if ((tab[linha-1][coluna-1] == mcTab)&&(tab[linha-1][coluna] == mcTab)&&(tab[linha-1][coluna+1] == mcTab)&&(tab[linha][coluna-1] == mcTab)
&&(tab[linha][coluna+1] == mcTab)&&(tab[linha+1][coluna-1] == mcTab)&&(tab[linha+1][coluna] == mcTab)&&(tab[linha+1][coluna+1] == mcTab)
      ||((linha < 0)||(linha >= tamanho)||(coluna < 0)||(coluna >= tamanho))){
                                                                                                                                
                        textcolor(4);
                        printf("\n\nJogada invalida.\n");
                        sleep(2000);
                        return false;
                        
      }//if

//Analisa as peças que seram convertidas    
else{
//------------------------------------------------------------------------------
//1 - Verifica diagonal superior esquerda  
if ((linha-1>=0)&&(coluna-1>=0)&&(tab[linha-1][coluna-1]==peca1)){
contador = 0;                    
a = 1;  
                        
while ((linha-a >= 0)&&(coluna-a >= 0)&&(tab[linha-a][coluna-a] == peca1)){                                                                                                                             
     contador++;
     a++;   
                                                                               
}//while   
                                                                                                          
if ((tab[linha-a][coluna-a] == peca2)&&(tab[linha-a][coluna-a] != mcTab)){
                  tab[linha][coluna] = peca2;
      
                  for (a=1; a<=contador; a++){
                      tab[linha-a][coluna-a] = peca2;
                      cont++;
}//for
}//if
}//if
//------------------------------------------------------------------------------
//2 - Verifica vertical cima  
if ((linha-1>=0)&&(tab[linha-1][coluna]==peca1)){                                                                                                                                   
contador = 0;                    
a=1;
while ((linha-a>=0)&&(tab[linha-a][coluna] == peca1)){
      contador++;
      a++;  
                                                                                                                                                                                                                               
}//while
                                                                                                       
if ((tab[linha-a][coluna] == peca2)&&(tab[linha-a][coluna] != mcTab)){
                tab[linha][coluna] = peca2;
      
                for (a=1; a<=contador; a++){
                    tab[linha-a][coluna] = peca2;
                    cont++;
}//for
}//if
}//if
//------------------------------------------------------------------------------
//3 - Verifica diagonal superior direita 
if ((linha-1>=0)&&(coluna+1<tamanho)&&(tab[linha-1][coluna+1]==peca1)){                                                                                                                       
contador = 0;                    
a=1; 
                    
while ((linha-a >= 0)&&(coluna+a < tamanho)&&(tab[linha-a][coluna+a] == peca1)){
      contador++;
      a++;
                                                                                          
}//while
                                                                                    
if ((tab[linha-a][coluna+a] == peca2)&&(tab[linha-a][coluna+a] != mcTab)){
                      tab[linha][coluna] = peca2;
      
                      for (a=1; a<=contador; a++){
                          tab[linha-a][coluna+a] = peca2;
                          cont++;
}//for
}//if
}//if
//------------------------------------------------------------------------------
//4 - Verifica horizontal esquerda
if ((coluna-1>=0)&&(tab[linha][coluna-1]==peca1)){                                         
contador = 0;                    
a=1;  
                   
while ((coluna-a >= 0)&&(tab[linha][coluna-a] == peca1)){
      contador++;
      a++; 
                                                                                                                                                                                                                               
}//while                                                                                                                                                 

if ((tab[linha][coluna-a] == peca2)&&(tab[linha][coluna-a] != mcTab)){
                         tab[linha][coluna] = peca2;
                         
                         for (a=1; a<=contador; a++){
                             tab[linha][coluna-a] = peca2; 
                             cont++;                                                            
}//for
}//if
}//if
//------------------------------------------------------------------------------
//5 - Verifica horizontal direita
if ((coluna+1<tamanho)&&(tab[linha][coluna+1]==peca1)){                                                                                                                                                                                                                                                            
contador = 0;                    
a=1; 
                    
while ((coluna+a < tamanho)&&(tab[linha][coluna+a] == peca1)){
      contador++;
      a++; 
                                                                                               
}//while   
                                                                                                                                      
if ((tab[linha][coluna+a] == peca2)&&(tab[linha][coluna+a] != mcTab)){
                         tab[linha][coluna] = peca2;
                         
                         for (a=1; a<=contador; a++){
                             tab[linha][coluna+a] = peca2; 
                             cont++;                                                             
}//for
}//if
}//if
//------------------------------------------------------------------------------
//6 - Verifica diagonal inferior esquerda
if ((linha+1<tamanho)&&(coluna-1>=0)&&(tab[linha+1][coluna-1]==peca1)){                                                                         
contador = 0;                    
a=1;  
                   
while ((linha+a < tamanho)&&(coluna-a >= 0)&&(tab[linha+a][coluna-a] == peca1)){
      contador++;                                          
      a++;
                                                       
}//while
                                                                                                                                                                                                                                                                                                                                                                          
if ((tab[linha+a][coluna-a] == peca2)&&(tab[linha+a][coluna-a] != mcTab)){
                           tab[linha][coluna] = peca2;
                           
                           for (a=1; a<=contador; a++){
                               tab[linha+a][coluna-a] = peca2;
                               cont++;                                                              
}//for
}//if
}//if
//------------------------------------------------------------------------------
//7 - Verifica vertical baixo
if ((linha+1<tamanho)&&(tab[linha+1][coluna]==peca1)){                                                                                                
contador = 0;                    
a = 1;   
                  
while ((linha+a < tamanho)&&(tab[linha+a][coluna] == peca1)){
      contador++;                                                                                                                   
      a++;
                                                                                                                           
}//while
                                                                                                                                                      
if ((tab[linha+a][coluna] == peca2)&&(tab[linha+a][coluna] != mcTab)){
                         tab[linha][coluna] = peca2;
                         for (a=1; a<=contador; a++){
                             tab[linha+a][coluna] = peca2; 
                             cont++;                                                             
}//for
}//if
}//if
//------------------------------------------------------------------------------
//8 - Verifica inferior direita 
if ((linha+1<tamanho)&&(coluna+1<tamanho)&&(tab[linha+1][coluna+1]==peca1)){                                                                                             
contador = 0;                    
a = 1;                     
while ((linha+a < tamanho)&&(coluna+a < tamanho)&&(tab[linha+a][coluna+a] == peca1)){
      contador++;                                                                                                                                 
      a++; 
                                                                                                                 
}//while
                                                                                                                                                    
if ((tab[linha+a][coluna+a] == peca2)&&(tab[linha+a][coluna+a] != mcTab)){
                           tab[linha][coluna] = peca2;
                           
                           for (a=1; a<=contador; a++){                                                              
                               tab[linha+a][coluna+a] = peca2;
                               cont++;                                                              
}//for
}//if
}//if
//------------------------------------------------------------------------------
if (cont == 0){
            textcolor(4);   
            printf("\njogada invalida!\n");
            sleep(2000);
            
            return false;
                         }//if
                                                                                                                         
return true;   
}//else
   
}//if1

//------------------------------------------------------------------------------
//Se a casa escolhida já estiver ocupada
else{
     textcolor(4);
     printf("\nJogada invalida! A casa escolhida ja esta ocupada.\n");
     sleep(2000);
     
     return false;     
     }//else      
     
}//jogador

//==============================================================================
//Controla as condições de encerramento da partida
int controlaJogo (){
     int i, j, contadorX = 0, contadorO = 0;
     
for (i=0; i<tamanho; i++){
    for (j=0; j<tamanho; j++){
        
if ((tab [i][j] ==  mcTab)&&(escaneaTab(1,i,j,'O','X') == true)){
                 contadorX++;
                 }//if

if ((tab [i][j] ==  mcTab)&&(escaneaTab(2,i,j,'X','O') == true)){
                 contadorO++;
                 }//if
                                
}//for
}//for

if ((contadorX == 0)&&(contadorO == 0)){             
               return (0);
               
}//if
if ((contadorX == 0)&&(contadorO != 0)){             
               return (1);
               
}//if
if ((contadorX != 0)&&(contadorO == 0)){             
               return (2);
               
}//if
if ((contadorX != 0)&&(contadorO != 0)){             
               return (4);
               
}//if  
              
}//controlaJogo

//==============================================================================
//Escanea o tabuleiro verificando se os jogadores tem jogadas disponíveis
bool escaneaTab (int jogador, int linha, int coluna, char peca1, char peca2){
     int a, cont = 0;

//1 - Verifica diagonal superior esquerda  
if ((linha-1>=0)&&(coluna-1>=0)&&(tab[linha-1][coluna-1]==peca1)){
                   
a = 1;  
                        
while (((linha-a >= 0)&&(coluna-a >= 0))&&(tab[linha-a][coluna-a] == peca1)){                                                                                                                                
     a++;   
                                                                               
}//while   
                                                                                                          
if ((tab[linha-a][coluna-a] == peca2)&&(tab[linha-a][coluna-a] != mcTab)){
                      
                      cont++;

}//if
}//if
//------------------------------------------------------------------------------
//2 - Verifica vertical cima  
if ((linha-1>=0)&&(tab[linha-1][coluna]==peca1)){                                                                                                                                   
                   
a=1;
while ((linha-a>=0)&&(tab[linha-a][coluna] == peca1)){
   
      a++;  
                                                                                                                                                                                                                               
}//while
                                                                                                       
if ((tab[linha-a][coluna] == peca2)&&(tab[linha-a][coluna] != mcTab)){

                    cont++;

}//if
}//if
//------------------------------------------------------------------------------
//3 - Verifica diagonal superior direita 
if ((linha-1>=0)&&(coluna+1<tamanho)&&(tab[linha-1][coluna+1]==peca1)){                                                                                                                       
                   
a=1; 
                    
while (((linha-a >= 0)&&(coluna+a < tamanho))&&(tab[linha-a][coluna+a] == peca1)){
    
      a++;
                                                                                          
}//while
                                                                                    
if ((tab[linha-a][coluna+a] == peca2)&&(tab[linha-a][coluna+a] != mcTab)){

                          cont++;

}//if
}//if
//------------------------------------------------------------------------------
//4 - Verifica horizontal esquerda
if ((coluna-1>=0)&&(tab[linha][coluna-1]==peca1)){                                         
                   
a=1;  
                   
while ((coluna-a >= 0)&&(tab[linha][coluna-a] == peca1)){
      
      a++; 
                                                                                                                                                                                                                               
}//while                                                                                                                                                 

if ((tab[linha][coluna-a] == peca2)&&(tab[linha][coluna-a] != mcTab)){

                             cont++;                                                            

}//if
}//if
//------------------------------------------------------------------------------
//5 - Verifica horizontal direita
if ((coluna+1<tamanho)&&(tab[linha][coluna+1]==peca1)){                                                                                                                                                                                                                                                            
               
a=1; 
                    
while ((coluna+a < tamanho)&&(tab[linha][coluna+a] == peca1)){

      a++; 
                                                                                               
}//while   
                                                                                                                                      
if ((tab[linha][coluna+a] == peca2)&&(tab[linha][coluna+a] != mcTab)){
  
                             cont++;                                                             

}//if
}//if
//------------------------------------------------------------------------------
//6 - Verifica diagonal inferior esquerda
if ((linha+1<tamanho)&&(coluna-1>=0)&&(tab[linha+1][coluna-1]==peca1)){                                                                         
                    
a=1;  
                   
while (((linha+a < tamanho)&&(coluna-a >= 0))&&(tab[linha+a][coluna-a] == peca1)){
                                            
      a++;
                                                       
}//while
                                                                                                                                                                                                                                                                                                                                                                          
if ((tab[linha+a][coluna-a] == peca2)&&(tab[linha+a][coluna-a] != mcTab)){

                               cont++;                                                              

}//if
}//if
//------------------------------------------------------------------------------
//7 - Verifica vertical baixo
if ((linha+1<tamanho)&&(tab[linha+1][coluna]==peca1)){                                                                                                
                  
a = 1;   
                  
while ((linha+a < tamanho)&&(tab[linha+a][coluna] == peca1)){
                                                                                                                   
      a++;
                                                                                                                           
}//while
                                                                                                                                                      
if ((tab[linha+a][coluna] == peca2)&&(tab[linha+a][coluna] != mcTab)){
 
                             cont++;                                                             

}//if
}//if
//------------------------------------------------------------------------------
//8 - Verifica inferior direita 
if ((linha+1<tamanho)&&(coluna+1<tamanho)&&(tab[linha+1][coluna+1]==peca1)){                                                                                             
                   
a = 1;                     
while (((linha+a < tamanho)&&(coluna+a < tamanho))&&(tab[linha+a][coluna+a] == peca1)){
                                                                                                                                  
      a++; 
                                                                                                                 
}//while
                                                                                                                                                    
if ((tab[linha+a][coluna+a] == peca2)&&(tab[linha+a][coluna+a] != mcTab)){
     
                               cont++;                                                              

}//if
}//if

//------------------------------------------------------------------------------
if (cont == 0){
            return false;
                         }//if
                                                                                                                            
else{
     return true;   
     }//else
         
}//escaneaTab

//==============================================================================
//Conta a quantidade de peça dos jogadores restantes no tabuleiro
int contaPeca (int jogador, char peca){
    int i, j, contador = 0;
     
for (i=0; i<tamanho; i++){
    for (j=0; j<tamanho; j++){
        
if (tab [i][j] ==  peca){
                 contador++;
                 }//if
                 
}//for
}//for
return (contador);    
}//contaPeca

//==============================================================================
//Controla cursor que seleciona posição do tabuleiro
void controlaCursor (int jogador, char peca1, char peca2){
     int linha, coluna;
     char direcional;
 
if (jogador == 1){//posiciona cursor para jogador 1
            linha = (tamanho/2) - 1;
            coluna = tamanho/2;
            }//if
            
else{//posiciona cursor para jogador 2
            linha = (tamanho/2) - 1;
            coluna = (tamanho/2) - 1;
            }//else
//------------------------------------------------------------------------------            
     clrscr();
     imprimeTab(linha, coluna);

do{ 
     clrscr();
     imprimeTab(linha, coluna);
//------------------------------------------------------------------------------     
     if (jogador == 1){
                 textcolor (14);
                 }//if
     else{
          textcolor (3);
          }//else
        
     printf("\n\n- Jogador  %d (%c):", jogador, peca2);
     textcolor (15); 
//------------------------------------------------------------------------------    
     direcional = getch();

      
switch (jogador){
       case 2 ://Direcional para jogador 2
            switch (direcional){
//------------------------------------------------------------------------------       
         case 77 : //Seta direita
               if(coluna < tamanho-1){
                        coluna++;                            
                        }//if
   
                  ;break;
//------------------------------------------------------------------------------
         case 75 : //Seta esquerda
               if(coluna > 0){
                        coluna--;                            
                        }//if                              
                            
                  ;break;
//------------------------------------------------------------------------------       
         case 80 : //Seta baixo
               if(linha < tamanho-1){
                        linha++;                            
                        }//if
   
                  ;break;
//------------------------------------------------------------------------------
         case 72 : //Seta cima
               if(linha > 0){
                        linha--;                            
                        }//if                              
                            
                  ;break;
//------------------------------------------------------------------------------
}//switch
;break;
       case 1:
             switch (direcional){
             //Direcional para o jogador 1      
         case 'f' : //Seta direita
               if(coluna < tamanho-1){
                        coluna++;                            
                        }//if
   
                  ;break;
//------------------------------------------------------------------------------
         case 's' : //Seta esquerda
               if(coluna > 0){
                        coluna--;                            
                        }//if                              
                            
                  ;break;
//------------------------------------------------------------------------------       
         case 'd' : //Seta baixo
               if(linha < tamanho-1){
                        linha++;                            
                        }//if
   
                  ;break;
//------------------------------------------------------------------------------
         case 'e' : //Seta cima
               if(linha > 0){
                        linha--;                            
                        }//if                              
                            
                  ;break;
}//switch
;break;  
//------------------------------------------------------------------------------
         case 27 : //Se a tecla ESC for pressionada, volta para menu.
               
               inicializaTab ();
               modoDeJogo = menu();                                  
                  ;break;
//------------------------------------------------------------------------------             
}//switchJogador
 
} while ((direcional != 13)&&(direcional != 32));    

   jogadores (jogador, linha, coluna, peca1, peca2);   
         
}//controlaCursor

//==============================================================================
//Analisa melhor jogada para o computador
void melhorJogada (){
     int linha, coluna, i, j, a, contador, cont = 0;
     char peca1 = 'X', peca2 = 'O';
//------------------------------------------------------------------------------     
     textcolor (3);
     printf("\n\nJogador  %d (%c):", 2, peca2); 
     textcolor(15);
     sleep(1000);
     clrscr();
//------------------------------------------------------------------------------     
for (linha=0; linha<tamanho; linha++){
    for (coluna=0; coluna<tamanho; coluna++){
        
if (tab [linha][coluna] == mcTab){//Se a lugar onde a peça será colocada está vazia

//Se a vizinhança da casa escolhida estiver sem peças      
if ((tab[linha-1][coluna-1] == mcTab)&&(tab[linha-1][coluna] == mcTab)&&(tab[linha-1][coluna+1] == mcTab)&&(tab[linha][coluna-1] == mcTab)
&&(tab[linha][coluna+1] == mcTab)&&(tab[linha+1][coluna-1] == mcTab)&&(tab[linha+1][coluna] == mcTab)&&(tab[linha+1][coluna+1] == mcTab)){                                                                                                                               
                        
      }//if

//Analisa as peças que seram convertidas    
else{
     
//------------------------------------------------------------------------------
//1 - Verifica diagonal superior esquerda  
if ((linha-1>=0)&&(coluna-1>=0)&&(tab[linha-1][coluna-1]==peca1)){
contador = 0;                    
a = 1;  
                        
while (((linha-a >= 0)&&(coluna-a >= 0))&&(tab[linha-a][coluna-a] == peca1)){                                                                                                                             
     contador++;
     a++;   
                                                                               
}//while   
                                                                                                          
if ((tab[linha-a][coluna-a] == peca2)&&(tab[linha-a][coluna-a] != mcTab)){
      
                  for (a=1; a<=contador; a++){
                      cont++;
}//for
}//if
}//if
//------------------------------------------------------------------------------
//2 - Verifica vertical cima  
if ((linha-1>=0)&&(tab[linha-1][coluna]==peca1)){                                                                                                                                   
contador = 0;                    
a=1;
while ((linha-a>=0)&&(tab[linha-a][coluna] == peca1)){
      contador++;
      a++;  
                                                                                                                                                                                                                               
}//while
                                                                                                       
if ((tab[linha-a][coluna] == peca2)&&(tab[linha-a][coluna] != mcTab)){
      
                for (a=1; a<=contador; a++){
                    cont++;
}//for
}//if
}//if
//------------------------------------------------------------------------------
//3 - Verifica diagonal superior direita 
if ((linha-1>=0)&&(coluna+1<tamanho)&&(tab[linha-1][coluna+1]==peca1)){                                                                                                                       
contador = 0;                    
a=1; 
                    
while (((linha-a >= 0)&&(coluna+a < tamanho))&&(tab[linha-a][coluna+a] == peca1)){
      contador++;
      a++;
                                                                                          
}//while
                                                                                    
if ((tab[linha-a][coluna+a] == peca2)&&(tab[linha-a][coluna+a] != mcTab)){
      
                      for (a=1; a<=contador; a++){
                          cont++;
}//for
}//if
}//if
//------------------------------------------------------------------------------
//4 - Verifica horizontal esquerda
if ((coluna-1>=0)&&(tab[linha][coluna-1]==peca1)){                                         
contador = 0;                    
a=1;  
                   
while ((coluna-a >= 0)&&(tab[linha][coluna-a] == peca1)){
      contador++;
      a++; 
                                                                                                                                                                                                                               
}//while                                                                                                                                                 

if ((tab[linha][coluna-a] == peca2)&&(tab[linha][coluna-a] != mcTab)){
                         
                         for (a=1; a<=contador; a++){
                             cont++;                                                            
}//for
}//if
}//if
//------------------------------------------------------------------------------
//5 - Verifica horizontal direita
if ((coluna+1<tamanho)&&(tab[linha][coluna+1]==peca1)){                                                                                                                                                                                                                                                            
contador = 0;                    
a=1; 
                    
while ((coluna+a < tamanho)&&(tab[linha][coluna+a] == peca1)){
      contador++;
      a++; 
                                                                                               
}//while   
                                                                                                                                      
if ((tab[linha][coluna+a] == peca2)&&(tab[linha][coluna+a] != mcTab)){
                         
                         for (a=1; a<=contador; a++){
                             cont++;                                                             
}//for
}//if
}//if
//------------------------------------------------------------------------------
//6 - Verifica diagonal inferior esquerda
if ((linha+1<tamanho)&&(coluna-1>=0)&&(tab[linha+1][coluna-1]==peca1)){                                                                         
contador = 0;                    
a=1;  
                   
while (((linha+a < tamanho)&&(coluna-a >= 0))&&(tab[linha+a][coluna-a] == peca1)){
      contador++;                                          
      a++;
                                                       
}//while
                                                                                                                                                                                                                                                                                                                                                                          
if ((tab[linha+a][coluna-a] == peca2)&&(tab[linha+a][coluna-a] != mcTab)){
                           
                           for (a=1; a<=contador; a++){
                               cont++;                                                              
}//for
}//if
}//if
//------------------------------------------------------------------------------
//7 - Verifica vertical baixo
if ((linha+1<tamanho)&&(tab[linha+1][coluna]==peca1)){                                                                                                
contador = 0;                    
a = 1;   
                  
while ((linha+a < tamanho)&&(tab[linha+a][coluna] == peca1)){
      contador++;                                                                                                                   
      a++;
                                                                                                                           
}//while
                                                                                                                                                      
if ((tab[linha+a][coluna] == peca2)&&(tab[linha+a][coluna] != mcTab)){
                         for (a=1; a<=contador; a++){
                             cont++;                                                             
}//for
}//if
}//if
//------------------------------------------------------------------------------
//8 - Verifica inferior direita 
if ((linha+1<tamanho)&&(coluna+1<tamanho)&&(tab[linha+1][coluna+1]==peca1)){                                                                                             
contador = 0;                    
a = 1;                     
while (((linha+a < tamanho)&&(coluna+a < tamanho))&&(tab[linha+a][coluna+a] == peca1)){
      contador++;                                                                                                                                 
      a++; 
                                                                                                                 
}//while
                                                                                                                                                    
if ((tab[linha+a][coluna+a] == peca2)&&(tab[linha+a][coluna+a] != mcTab)){
                           
                           for (a=1; a<=contador; a++){                                                              
                               cont++;                                                              
}//for
}//if
}//if
//------------------------------------------------------------------------------
}//else
}//if1

pecaComputador [linha][coluna] = cont;
cont = 0; 
  
}//for
}//for
  
for (i=0; i<tamanho; i++){
    for (j=0; j<tamanho; j++){
        
        if ((pecaComputador [i][j] > cont)&&(optionsDif == 1)){
                      
                cont = pecaComputador [i][j];
                linha = i;
                coluna = j;
                }//if
                
        if ((pecaComputador [i][j] > cont)&&(optionsDif == 0)){
                 
                cont = pecaComputador [i][j];
                linha = i;
                coluna = j;
                ;break;
                }//if
                
}//for
}//for
     
jogadores (2, linha, coluna, 'X', 'O');                     
            
}//melhorJogada

//==============================================================================
//Menu principal do jogo
int menu (){
    int color [3];
    int opcao = 0, i;//marca a opcao escolhida pelo jogador
    char tecla;
    
do{
    clrscr();
//------------------------------------------------------------------------------

for (i=0; i<3; i++){
    
    color [i] = COLORA;
    
         if (i == opcao){
           color [i] = COLORC;
           }//if
}//for 
    textcolor(10);  
    printf("\n\t\t\t  \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBB");
    printf ("\n\t\t\t  \xBA Escolha o modo de jogo \xBA");
    printf("\n\t\t\t  \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBC"); 
           
    textcolor(color [0]);
    printf ("\n\n\n\t\t\t\t  One Player");
    textcolor(color [1]);
    printf ("\n\n\n\n\t\t\t\t  Multiplayer");
    textcolor(color [2]);
    printf ("\n\n\n\n\t\t\t\t  Options");
  //  textcolor(color [3]);   
   // printf ("\n\n\n\t\t\t\t  Score");
    
    textcolor(10);
    gotoxy(55,25);
    printf("[ Q ]");
    textcolor(15);
    printf(" Sair");
    gotoxy(67,25);
    textcolor(10);
    printf("[ A ]");
    textcolor(15);
    printf(" Ajuda"); 
           
    tecla = getch();

switch (tecla){
//------------------------------------------------------------------------------       
         case 80 : //Seta baixo
               if(opcao < 2){
                        opcao++;                            
                        }//if
   
                  ;break;
//------------------------------------------------------------------------------
         case 72 : //Seta cima
               if(opcao > 0){
                        opcao--;                            
                        }//if                              
                            
                  ;break;
//------------------------------------------------------------------------------
         case 'a' : //chama a função ajuda
                  ajudaMenu();                          
                            
                  ;break;
         case 'A' : //chama a função ajuda
                  ajudaMenu();                          
                            
                  ;break;
         
//------------------------------------------------------------------------------
         case 'q' : //sai do jogo
                  gotoxy(2,25);
                  printf ("Sair do jogo (y/n)?");
                  tecla = getch(); 
                  
                  switch (tecla){
//------------------------------------------------------------------------------
                         case 'y':
                              exit (0);
                              ;break;
                                               
//------------------------------------------------------------------------------
                                 }//switch                            
                  ;break;
         
//------------------------------------------------------------------------------ 
}//switch 
     
} while (tecla != 13);
//Se a opção for um jogador
if (opcao == 0){
          modoDeJogo = 1;
}//if
//Se a opção for dois jogadores
if (opcao == 1){
          modoDeJogo = 2;
}//if
//Se a opção for menu de opções
if (opcao == 2){
          Options ();
}//if
        
}//menu

//==============================================================================
//Imprime a ajuda do menu principal
void ajudaMenu (){
     char tecla;
     
do{ 
                clrscr();
                textcolor(10);
                printf("Ajuda");                       
                sleep(70);
                textcolor(15);
                printf("\n\nO jogo REVERSI se constitui de um tabuleiro onde dois jogadores buscam possuir,"); 
                sleep(70);                    
                printf("\nao final da partida, a maior quantidade de pecas.");
                sleep(70);
                printf("\n\nO jogador que estiver em sua jogada deve buscar encurralar uma ou mais pecas\ndo adversario. ");
                sleep(70);
                printf("\n\nAo fazer isso as pecas do adversario serao convertidas para as pecas do jogador\nque efetuou a jogada.");
                sleep(70);
                printf("\n\nE permitido jogar apenas nas casas que nao possuem nenhum dos dois tipos de ");
                sleep(70);
                printf("\npecas, e que possuam ao menos, a possibildade de converter uma peca.");
                sleep(70);
                printf("\n\nCaso estas condicoes nao forem obedecidas, a jogada sera dada como");
                textcolor(14);
                printf(" invalida.");
                textcolor(15);
                sleep(70);
                printf("\n\nO jogador que estiver em seu turno pode escolher jogar ou passar a vez para");
                sleep(70);
                printf("\no adversario.");
                sleep(70);
                printf("\n\nO jogo acaba quando todo o tabuleiro estiver preenchido ou se as possibildades");
                sleep(70);
                printf("\nde jogadas se esgotarem para ambos os jogadores em um mesmo turno.");
                sleep(70);
                printf("\n\nEm ambos os casos, o jogador que possuir a maior quantidade de pecas");
                sleep(70);
                printf(" sera\no vencedor ou sera declarado impate caso a suas quantidades de pecas forem\niguais.");
                
                getch();
                tecla = getch();
                clrscr();
                textcolor(10);
                printf("Ajuda");
                textcolor(15);
                /*sleep(70);
                printf("\n\nNo modo de dificuldade Good Lucky cada jogador tem sua vez de jogar sorteada de modo "); 
                sleep(70);
                printf("aleatorio. Vence o jogador que tiver a melhor estrategia e mais sortudo.");*/
                sleep(70);
                printf("\n\nPressione");
                textcolor (10);
                printf (" ESC ");
                textcolor (15);
                printf ("durante a partida para voltar ao MENU principal");
                sleep(70);
                textcolor(10);
                printf("\n\nSobre o MENU");
                sleep(70);
                printf("\n\nOne Player.");
                textcolor(15);                
                sleep(70);
                printf("\nDesafie o computador para uma partida.\nA escolha do nivel de dificuldade e valida apenas para esse modo de jogo.");
                textcolor(10);
                sleep(70);
                printf("\n\nMultiplayer");
                textcolor(15);
                sleep(70);
                printf("\nModo de jogo para dois jogadore.");
                textcolor(10);
                sleep(70);
                printf("\n\nOptions");
                textcolor(15);
                sleep(70);
                printf("\nO MENU de opcoes do jogo. ");
                printf("\n\nPressione ");
                textcolor (10);
                printf ("ENTER ");
                textcolor (15);
                printf ("para retornar ao menu principal do jogo.");
                tecla = getch();
                
}while (tecla != 13);            
     
menu();     
}//ajuda

//==============================================================================
//Ajuda do menu de opções
void ajudaOptions (){
     char tecla;
     
do{ 
                textcolor(COLORC);            
                clrscr();
                sleep(70);
                printf("Options.");
                sleep(70);
                printf("\n\nDificuldade\n\n");
                sleep(70);
                textcolor(COLORA);  
                printf("Selecione Easy (o computador realiza uma jogada qualquer ou Hard (o computador\nrealiza a melhor jogada).");
                sleep(70);
                textcolor(COLORC);  
                printf("\n\nTamanho do Tabuleiro");
                sleep(70);
                textcolor(COLORA);  
                printf("\n\nSelecione o tamanho do tabuleiro a ser usado. O tamanho do tabuleiro inicial\n");
                sleep(70);
                printf("e 8x8 e o nivel de dififculdade inicial e Easy.");
                textcolor(10);
                sleep(70);
                /*printf("\n\nScore");
                textcolor(15);
                sleep(70);
                printf("\nVerifique aqui o seu SCORE e o de outros jogadores.");*/
                textcolor(15);
                sleep(70);
                printf("\n\nPressione "); 
                textcolor(10);
                printf("ENTER "); 
                textcolor(15);
                printf("para voltar ao menu de opcoes");  
                                        
                tecla = getch();
                
}while (tecla != 13);            
     
Options();     
}//ajuda

//==============================================================================
//Options
int Options (){
    int colorDif [2], colorTam [3];
    int opcaoDif = 0, opcaoTam = 0, difOuTam = 0, i;//marca a opcao escolhida pelo jogador
    char tecla;
    
do{
    clrscr();
//------------------------------------------------------------------------------
//Para analisar a dificuldade escolhida pelo cursor
for (i=0; i<2; i++){
    
    colorDif [i] = COLORA;
    
         if (i == opcaoDif){
             colorDif [i] = COLORC;
           }//if
}//for 
//------------------------------------------------------------------------------
//Para analisar o tamanho escolhida pelo cursor
for (i=0; i<3; i++){
    
    colorTam [i] = COLORA;
    
         if (i == opcaoTam){
             colorTam [i] = COLORC;
           }//if
}//for 
    textcolor(COLORC); 
    printf("\n\t\t\t\t  \xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD");        
    printf("\xCD\xCD\xCD\xBB");
    printf ("\n\t\t\t\t  \xBA  Options \xBA");
    printf("\n\t\t\t\t  \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD");       
    printf("\xCD\xCD\xCD\xBC"); 
           
    textcolor(COLORC);
    printf ("\n\n\n\t\t\t\t   Dificuldade");
    textcolor(colorDif [0]);
    printf ("\n\n\n\t\t\t\t  Easy");
    textcolor(colorDif [1]);
    printf ("\t  Hard");
    textcolor(COLORC);
    printf ("\n\n\n\t\t\t       Tamanho do tabuleiro");
    textcolor(colorTam [0]);   
    printf ("\n\n\n\t\t\t\t6");
    textcolor(colorTam [1]);   
    printf ("\t8");
    textcolor(colorTam [2]);   
    printf ("\t10");
    
   /* textcolor(COLORC);
    gotoxy(55,25);
    printf("[ Q ]");
    textcolor(COLORA);
    printf(" Sair");*/
    gotoxy(67,25);
    textcolor(COLORC);
    printf("[ A ]");
    textcolor(COLORA);
    printf(" Ajuda"); 
           
    tecla = getch();

switch (tecla){
//------------------------------------------------------------------------------       
         case 80 : //Seta baixo
               if(difOuTam < 1){
                        difOuTam++;                            
                        }//if
   
                  ;break;
//------------------------------------------------------------------------------
         case 72 : //Seta cima
               if(difOuTam > 0){
                        difOuTam--;                            
                        }//if                              
                            
                  ;break;
//------------------------------------------------------------------------------       
         case 77 : //Seta direita
        
         if (difOuTam == 0){
               if (opcaoDif < 1){
               opcaoDif++;
               }//if
                            }//if
         else{
              if (opcaoTam < 2){
              opcaoTam++;
                                }//if
              }//else
               
                  ;break;
//------------------------------------------------------------------------------
         case 75 : //Seta esquerda
         
         if (difOuTam == 0){
               if (opcaoDif > 0){
               opcaoDif--;
               }//if
                          }//if  
         else{
              if (opcaoTam > 0){
              opcaoTam--;
                                }//if
              }//else                        
                            
                  ;break;
         
//------------------------------------------------------------------------------
         case 'a' : //chama a função ajuda
                  
         ajudaOptions ();                          
                            
                  ;break;
         case 'A' : //chama a função ajuda
         
         ajudaOptions ();                          
                            
                  ;break;
         
/*/------------------------------------------------------------------------------
         case 'q' : //chama a função ajuda
                  return;                       
                            
                  ;break;
          case 'Q' : //chama a função ajuda
                  return;                       
                            
                  ;break;
         */
//------------------------------------------------------------------------------  
}//switch
    
} while (tecla != 13);
//------------------------------------------------------------------------------
//Para guardar a escolha da dificuldade
if (opcaoDif == 0){
          optionsDif = 0;
}//if
else{
          optionsDif = 1;
          }//else
//------------------------------------------------------------------------------  
//Para guardar a escolha do tamanho do tabuleiro
if (opcaoTam == 0){
          tamanho = 6;
}//if 
if (opcaoTam == 1){
          tamanho = 8;
}//if  
if (opcaoTam == 2){
          tamanho = 10;
}//if
inicializaTab (); 
menu();      
}//options

//==============================================================================
//controla o jogo para dificuldade normal
void rotinaJogo (int modoDeJogo){
     int resposta;
     
     //O laço abaixo cuida da rotina de movimentação do jogo
do{
    
    resposta = controlaJogo ();
//Se o jogador 1 tem possibilidade de jogada  
    if((resposta != 0)&&(resposta != 1)){
             jogarOuPassar(1);
             
             
}//IF
    clrscr();
    resposta = controlaJogo ();
    
//Se o jogador 2 tem possibilidade de jogada  
    if((resposta != 0)&&(resposta != 2)){
                 
                 if (modoDeJogo == 1){
                         clrscr();   
                         imprimeTab ((tamanho/2) - 1,tamanho/2);
                         melhorJogada ();
                          }//if
                 else{
                         jogarOuPassar (2);
                         }//else
                        
}//if
clrscr();            
    
} while (controlaJogo () != 0);//Segunda analise de tabuleiro     
   
}//difNormal

//=============================================================================
void logotipo(){ 
    int tecla, i, j=14, auxi, auxj; 
    char *palavra = "REVERSI";
    
    gotoxy(35,10);
    
for ( i=0; i<7; i++){       // Usar esta implementação    
    textcolor (10);
    printf ("%c", *(palavra+i));
    sleep(100);
    
}//for
for ( i=0; i<7; i++){       // Usar esta implementação    
    beep (440+20*i,120);
}//for
       // beep (440,200);
        sleep (500);                
        gotoxy(35,10);
        textcolor(14);
        printf("NOW LOADING...");
        sleep(1500);
        clrscr();
         
        menu();
       
}//logotipo
        
//==============================================================================
//Insere pontuação dos jogadores em uma lista
void ranking (int quant, int jogador){
     noLista* novo = (noLista*) malloc(sizeof(noLista));
     noLista* atual = prim;
     noLista* ant = atual;
                                       
while ((atual != NULL)&&(ant -> pontos <= atual -> pontos)){
      ant = atual;
      atual = atual -> prox;
      }//while
     
if (ant != NULL){              
             ant -> prox = novo;
             }//if
else{
             prim = novo;
            // novo -> prox = atual;
             }//else
             
             novo -> pontos = quant;
             novo -> prox = atual;
             novo -> jog = jogador;               
                   
}//ranking

//==============================================================================
//Imprime lista de pontos
void imprimeRank (){
     noLista* atual = prim;
     clrscr();
     textcolor (14);
     printf ("\t\t\t\tRANKING");
     
while (atual != NULL){
      printf ("\t\t\t\t\n\nJogador %d - Pontos: %d", atual -> jog, atual -> pontos);
      atual = atual -> prox;
      }//while 
      
      textcolor (15);  
     
}//imprimeRank
