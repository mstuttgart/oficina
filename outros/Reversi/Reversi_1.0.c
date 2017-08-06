#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//------------------------------------------------------------------------------
#define DIR 25
#define ESQ 5
#define COLORA 8
#define COLORB 15

//==============================================================================
                            //REVERSI
//==============================================================================
//Inicializa tabuleiro
void inicializaTab ();
//Imprime trabuleiro
void imprimeTab (int jogador);
//Verifica se a jogada será passada ou não
void jogarOuPassar (int jogador);
//Controla as jogadas do jogador 1 ou 2
void jogadores (int jogador, char peca1, char peca2);
//==============================================================================
//Variavel que guarda tabuleiro
char tab [18][18];
//tamanho inicial do tabuleiro
int tamanho = 8; 
//Guarda a figura q representa o tabuleiro
char mcTab = 176;
//==============================================================================
//Função principal
int main (int argc, char* argv[]){
    srand (time(NULL));
    int quemComeca = 1, i;
   
//------------------------------------------------------------------------------
    inicializaTab ();
for (i=0;i<8;i++){
   // quemComeca = (rand()%2+1);//quem começa em ordem aleatória
    quemComeca = 1;
    jogarOuPassar(quemComeca);
    clrscr();
    quemComeca = 2;
    jogarOuPassar(quemComeca);
    clrscr();
    
}//for
//------------------------------------------------------------------------------
    printf("\n\n\n");
    system ("pause");
    return 0;
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
      //textcolor(4);                                                       
      tab [(tamanho/2) - 1][(tamanho/2) - 1] = 'O';
      tab [(tamanho/2) - 1][tamanho/2] = 'X';
      tab [tamanho/2][(tamanho/2) - 1] = 'X';
      tab [tamanho/2][tamanho/2] = 'O';                                    
                                                    
}//inicilizaTab

//==============================================================================
//Imprime tabuleiro
void imprimeTab (int jogador){
     int i, j;
     char peca;
     
     printf ("\n\n\t\t\t   ");
     
for (i=0; i < tamanho; i++){//Guarda os numerosbdsa casas horizontais
         textcolor(15);
         printf ("%2d ", i+1);
                                }//for
  // printf("\n");                            
for ( i=0; i<tamanho; i++){
    
    //Guarda o numero das casas verticais
    printf("\n\n\t\t\t%2d ", i+1);
    
    for ( j=0; j<tamanho; j++){
        textcolor(15);
        
        if (tab [i][j] == 'O'){                     
                      textcolor (3);                      
                      }//if
        if (tab [i][j] == 'X'){    
                      textcolor (14);
                      }//if
    
    printf(" %c ", tab [i][j]);
    
                          }//for
                     }//for
    
    if (jogador == 1){
                 textcolor (14);
                 peca = 'X';
                 }//if
     else{
          textcolor (3);
          peca = 'O';
          }//else
        
     printf("\n\nJogador  %d (%c):", jogador, peca);  
       
}//imprimeTab
     
//==============================================================================
//Verifica se a jogada será passada ou não
void jogarOuPassar (int jogador){
     char opcao, peca1, peca2; 
     int i = ESQ, color1 = COLORA, color2 = COLORB; 
     
     imprimeTab(jogador);
      
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
                 
            jogadores (jogador, peca1, peca2);           
            }//else  
}//jogadas

//==============================================================================
//Controla as jogadas do jogador 1 ou 2
void jogadores (int jogador, char peca1, char peca2){
     int linha, coluna, contador, a, cont = 0;
     
     clrscr();
     imprimeTab (jogador);
     printf("\n\n\n");
     textcolor(15);
     printf ("- Coordenadas da jogada (linha, coluna): ");
     scanf ("%d,%d", &linha, &coluna);
     linha = linha-1;
     coluna = coluna-1;
//Foi subtraido 1 para que se possa utilizar o tabuleiro enumerado a partir de 1

//------------------------------------------------------------------------------
//Se as coordenadas estão fora da area do tabuleiro
     if ((linha < 0)||(linha >= tamanho)||(coluna < 0)||(coluna >= tamanho)){
                textcolor(4);
                printf("Jogada invalidaaaaaaaa.");
                sleep(2000);
                return;
                }//if
//------------------------------------------------------------------------------
if (tab [linha][coluna] == mcTab){//Se a lugar onde a peça será colocada está vazia

//Se a vizinhança da casa escolhida estiver sem peças      
if ((tab[linha-1][coluna-1] == mcTab)&&(tab[linha-1][coluna] == mcTab)&&(tab[linha-1][coluna+1] == mcTab)&&(tab[linha][coluna-1] == mcTab)
&&(tab[linha][coluna+1] == mcTab)&&(tab[linha+1][coluna-1] == mcTab)&&(tab[linha+1][coluna] == mcTab)&&(tab[linha+1][coluna+1] == mcTab)
      ||((linha < 0)||(linha >= tamanho)||(coluna < 0)||(coluna >= tamanho))){
                                                                                                                                
                        textcolor(4);
                        printf("\n\nJogada invalidarrrrr.\n");
                        sleep(2000);
                        return;
                        
      }//if

//Analisa as peças que seram convertidas    
      else{

//------------------------------------------------------------------------------
//1 - Verifica diagonal superior esquerda  

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

//------------------------------------------------------------------------------
//2 - Verifica vertical cima  
                                                                                                                                  
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

//------------------------------------------------------------------------------
//3 - Verifica diagonal superior direita 
                                                                                                                       
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

//------------------------------------------------------------------------------
//4 - Verifica horizontal esquerda
                             
            
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

//------------------------------------------------------------------------------
//5 - Verifica horizontal direita
                                                                            
                                                                                                                                                                                 
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

//------------------------------------------------------------------------------
//6 - Verifica diagonal inferior esquerda
                                                            
             
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

//------------------------------------------------------------------------------
//7 - Verifica vertical baixo
                                                                                  
              
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

//------------------------------------------------------------------------------
//8 - Verifica inferior direita 
                                                                                  
             
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

//------------------------------------------------------------------------------
if (cont == 0){
            textcolor(4);   
            printf("\njogada invalidawwwww!\n");
            sleep(2000);
            return;
                         }//if                                                                                                                            
     
}//else   
}//if1

//------------------------------------------------------------------------------
//Se a casa escolhida já estiver ocupada
else{
     textcolor(4);
     printf("\nJogada invalida! A casa escolhida ja esta ocupada.\n");
     sleep(2000);     
     }//else      
     
}//jogador

//==============================================================================
