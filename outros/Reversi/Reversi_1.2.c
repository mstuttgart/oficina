//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
//------------------------------------------------------------------------------
#define DIR 25
#define ESQ 5
#define COLORA 15
#define COLORB 8
//------------------------------------------------------------------------------
typedef enum {true, false} bool;
//==============================================================================
                                  //REVERSI
//==============================================================================
//Inicializa tabuleiro
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
//==============================================================================
//Variável que guarda tabuleiro
char tab [18][18];
//tamanho inicial do tabuleiro
int tamanho = 8; 
//Guarda a figura q representa o tabuleiro
char mcTab = 176;
//==============================================================================
//Função principal
int main (int argc, char* argv[]){
    int quantJog1, quantJog2, resposta;
    inicializaTab ();
    
//O laço abaixo cuida da rotina de movimentação do jogo
do{
    
    //jogarOuPassar(1);
    resposta = controlaJogo ();
//Se o jogador 1 tem possibilidade de jogada  
    if((resposta != 0)&&(resposta != 1)){
             jogarOuPassar(1);
             clrscr();
}//IF

    resposta = controlaJogo ();
    
//Se o jogador 2 tem possibilidade de jogada  
    if((resposta != 0)&&(resposta != 2)){
             jogarOuPassar(2);
             clrscr();
}//IF
            
    
   //jogarOuPassar(2);
    //clrscr();
    
} while (controlaJogo () != 0);//Segunda analise de tabuleiro
//------------------------------------------------------------------------------
//Contagem de peças dos jogadores
    quantJog1 = contaPeca (1, 'X') ;
    quantJog2 = contaPeca (2, 'O');
    imprimeTab (0,0);
//------------------------------------------------------------------------------
    
if (quantJog1 > quantJog2){
              textcolor (14);
              printf ("\n\nJogador 1 venceu! Parabens!");
              }//if
else{
     if (quantJog1 < quantJog2){
                   textcolor (3);
                   printf ("\n\nJogador 2 venceu! Parabens!");
                   }//if
                   
                   else{
                        textcolor (8);
                        printf ("\n\nEmpate");
                        }//else
}//else
//------------------------------------------------------------------------------
    textcolor (15); 
    printf ("\n\n- Quantidade de pecas jogador 1: %d", quantJog1);
    printf ("\n- Quantidade de pecas jogador 2: %d", quantJog2);
    
    printf("\n\n\n");
    system ("pause");
 //   return 0;
    exit (0);
}//main

//==============================================================================
//Inicializa tabuleiro
void inicializaTab (){
     int i, j;
     
for ( i=0; i<18; i++){
    for ( j=0; j<18; j++){
        
    tab [i][j] = mcTab;
    
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
     int i, j;
     
     printf ("\n\n\t\t\t   ");
     
for (i=0; i < tamanho; i++){//Guarda os numerosbdsa casas horizontais
         textcolor(15);
         printf ("%2d ", i);
                                }//for
                                                           
for ( i=0; i<tamanho; i++){
    
    //Guarda o numero das casas verticais
    printf("\n\n\t\t\t%2d ", i);
    
    for ( j=0; j<tamanho; j++){
          
        if (tab [i][j] == 'O'){                     
                      textcolor (3);                      
                      }//if
        if (tab [i][j] == 'X'){    
                      textcolor (14);
                      }//if
        if ((i == linha)&&(j == coluna)){    
                      textbackground (3);
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
     
     imprimeTab(0, 0);
     
     if (jogador == 1){
                 textcolor (14);
                 peca = 'X';
                 }//if
     else{
          textcolor (3);
          peca = 'O';
          }//else
        
     printf("\n\nJogador  %d (%c):", jogador, peca);  
      
do{  
   //  imprimeTab(jogador);     
     gotoxy(ESQ,3*tamanho);
  //  printf("\n\n");
     textcolor(color1);   
     printf ("[ Passar jogada ]   ");
     textcolor(color2);
     gotoxy(DIR,3*tamanho);   
     printf ("[ Jogar ]");
     
     opcao = getch();
     //clrscr(); 
     
    // imprimeTab(jogador);      
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
}//switch
}while (opcao != 13);//Até pressionar ENTER  
       
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
            //jogadores (jogador, peca1, peca2);           
            }//else  
}//jogadas

//==============================================================================
//Controla as jogadas do jogador 1 ou 2
bool jogadores (int jogador, int linha, int coluna, char peca1, char peca2){
     int contador, a, cont = 0;
     char peca;
     
   //  clrscr();
   //  imprimeTab ((tamanho/2) - 1,coluna = tamanho/2);
     
if (jogador == 1){
                 textcolor (14);
                 peca = 'X';
                 }//if
     else{
          textcolor (3);
          peca = 'O';
          }//else
        
    // printf("");
    /* printf("\n\nJogador  %d (%c):", jogador, peca); 
     textcolor(15);
     printf ("\n\n\n- Coordenadas da jogada (linha, coluna): ");
     scanf ("%d,%d", &linha, &coluna);
   //  linha = linha-1;
   //  coluna = coluna-1;
//Foi subtraido 1 para que se possa utilizar o tabuleiro enumerado a partir de 1

//------------------------------------------------------------------------------
//Se as coordenadas estão fora da area do tabuleiro
     if ((linha < 0)||(linha >= tamanho)||(coluna < 0)||(coluna >= tamanho)){
                textcolor(4);
                printf("Jogada invalida.");
                sleep(2000);
                return false;
                }//if*/
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
                        
while (((linha-a >= 0)&&(coluna-a >= 0))&&(tab[linha-a][coluna-a] == peca1)){                                                                                                                             
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
                    
while (((linha-a >= 0)&&(coluna+a < tamanho))&&(tab[linha-a][coluna+a] == peca1)){
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
                   
while (((linha+a < tamanho)&&(coluna-a >= 0))&&(tab[linha+a][coluna-a] == peca1)){
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
while (((linha+a < tamanho)&&(coluna+a < tamanho))&&(tab[linha+a][coluna+a] == peca1)){
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
        
     printf("\n\nJogador  %d (%c):", jogador, peca2);
     textcolor (15); 
//------------------------------------------------------------------------------    
     direcional = getch();

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
        
}//switch
// imprimeTab (linha, coluna);
 
} while (direcional != 13);    
            
//  printf ("%d,%d", linha,coluna);
//  sleep(2000); 
   jogadores (jogador, linha, coluna, peca1, peca2);   
         
}//controlaCursor
