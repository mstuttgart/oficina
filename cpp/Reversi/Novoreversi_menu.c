/*Trabalho de técnicas de programação - ECO02/012 - REVERSI - UNIFEI
Aluno: Michell Stuttgart Faria
Matrícula: 16930
Curso: Engenharia da Computação  1º período*/
//==============================================================================
//Bibliotecas usadas durante o jogo
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
//==============================================================================
                              //REVERSI
//==============================================================================
//Aqui estão as funções e variáveis globais utilizadas no jogo
//Inicializa Tabuleiro
void inicializaTab ();
//Imprime tabuleiro
void mostraTab ();
//controla jogadas do jogadas do jogador 1
void jogador1 ();  
//controla jogadas do jogadas do jogador 2         
void jogador2 ();
//controla jogadas do jogadas do computador
void computador ();
//Controla as demais funções do jogo
void jogo (int opcao);
//controla logotipo de inicialização
void logotipo ();
//Encerra o jogo
void final ();
//Controla opções do menu
void options ();
//Controla o menu principal
void menu (int opcao);
//controla score de ppontuação do jogo
void score ();
//==============================================================================
//Variavel global que guarda o tabuleiro
char tab [16][16];
//Variaveis para numero de jogadores e tamanho inicial do tabuleiro...
int opcao, tamanho = 4; /*Variáveis globais*/
//==============================================================================
//Função principal
int main (int argc, char * argv[]){  
    logotipo();             
    system ("pause");    
    return 0; 
                                   }//main
//==============================================================================
//Introdução do jogo
void logotipo(){ 
    int tecla, i, j=14, auxi, auxj; 
    char *palavra = "REVERSI";
    
    gotoxy(35,10);
    
for ( i=0; i<7; i++){       // Usar esta implementação    
    textcolor (10);
    printf ("%c", *(palavra+i));
    sleep(100);
}//for
  
        sleep (2000);                
        gotoxy(35,10);
        textcolor(14);
        printf("NOW LOADING...");
        sleep(2000);
        clrscr();
         
        menu(opcao);
       
}//logotipo
        
//==============================================================================
//Controla o menu do jogo
void menu (int opcao){
    int tecla, i, j=14;
    char sair [ ] = {"siSIye"}; 
    char escolha[10];
    
    clrscr();
    
    for (i = 65; i>=35; i--){
    clrscr();
    textcolor(10);
    gotoxy(28,2);    
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBB");
    gotoxy(28,3);
    printf ("\xBA Escolha o modo de jogo \xBA");
    gotoxy(28,4);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBC");         
    gotoxy(70-i,8);
    textcolor(15);
    printf ("One Player"); 
    gotoxy(i,10);
    printf ("Multiplayer");
    gotoxy(70-i,12);
    printf ("Options"); 
    gotoxy(i,14);   
    printf ("Score");
    gotoxy(70-i,8);          
        sleep(15);        
                           }//for                 
    textcolor(15);
    gotoxy(35,6);
    printf ("Press ENTER");  
    gotoxy(35,8);
    textcolor(10);
    printf ("One Player"); 
    gotoxy(35,10);
    textcolor(15);
    printf ("Multiplayer");
    gotoxy(35,12);
    printf ("Options"); 
    gotoxy(35,14);   
    printf ("Score");
    gotoxy(35,8);     
textcolor(10);
gotoxy(55,25);
printf("<ESC>");
textcolor(15);
printf(" Sair");
gotoxy(67,25);
textcolor(10);
printf("<INS>");
textcolor(15);
printf(" Ajuda"); 
//------------------------------------------------------------------------------
//Aqui se inicia o laço do menu.   
do{  
     tecla = getch();    
     switch (tecla){ 
//------------------------------------------------------------------------------         
           case 72 :                
                if (j-2>7){                           
                            j=j-2;                                                               
                           }//if               
                else{
                         j=14;                                                        
                     }//else
                     
                     ;break;  
//------------------------------------------------------------------------------                     
           case 80 :
                if (j+2<16){
                      j=j+2;                                       
                            }//if
                else{            
                         j=8;                                           
                     }//else
                     ;break; 
//------------------------------------------------------------------------------
           case 82 ://Responsável pela ajuda
            for (i = 0; i<25; i++){
                clrscr();
                textcolor(10);               
                gotoxy(25-i,25-i);
                printf("Ajuda");
                sleep(30);
                                      }//for
//Aqui foi posto um laço para que fosse possível dividir a ajuda em duas páginas.   
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
                printf("\nO jogador que estiver em sua jogada deve buscar encurralar uma ou mais pecas\ndo adversario. ");
                sleep(70);
                printf("\nAo fazer isso as pecas do adversario serao convertidas para as pecas do jogador\nque efetuou a jogada.");
                sleep(70);
                printf("\nE permitido jogar apenas nas casas que nao possuem nenhum dos dois tipos de ");
                sleep(70);
                printf("\npecas, e que possuam ao menos, a possibildade de converter uma peca.");
                sleep(70);
                printf("\nCaso estas condicoes nao forem obedecidas, a jogada sera dada como");
                textcolor(14);
                printf(" invalida.");
                textcolor(15);
                sleep(70);
                printf("\nSe houver ou nao a possibilidade de jogada, o jogador pode passar a vez para");
                sleep(70);
                printf("\no adversario.");
                sleep(70);
                printf("\nO jogo acaba quando todo o tabuleiro estiver preenchido ou se as possibildades");
                sleep(70);
                printf("\nde jogadas se esgotarem para ambos os jogadores em um mesmo turno. Nos dois");
                sleep(70);
                printf("\ncasos, o jogador que possuir a maior quantidade de pecas sera o vencedor ou\nsera ");
                sleep(70);
                printf("declarado impate caso a suas quantidades de pecas forem iguais.");
                sleep(70);
                printf("\n\nPressione "); 
                textcolor(10);
                printf("-> "); 
                textcolor(15);
                printf("para ir a proxima pag.");  
                getch();               
                tecla = getch();               
                clrscr();                
                textcolor(10);
                printf("Sobre o MENU");
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
                sleep(70);
                printf("\nSelecione aqui o tamanho do tabuleiro a ser usado e o nivel de dififculdade\ndo modo One Player.");
                sleep(70);
                printf("\nO tamanho do tabuleiro inicial e 8x8 e o nivel de dififculdade inicial\ne Easy (facil).");
                sleep(70);
                textcolor(10);
                sleep(70);
                printf("\n\nScore");
                textcolor(15);
                sleep(70);
                printf("\nVerifique aqui o seu SCORE e o de outros jogadores.");
                textcolor(15);
                sleep(70);
                printf("\n\nPressione "); 
                textcolor(10);
                printf("ENTER "); 
                textcolor(15);
                printf("duas vezes para voltar ao menu ou");  
                textcolor(10);
                printf(" <- ");  
                textcolor(15);
                printf("para voltar ao menu\nde ajuda.");                   
                getch();            
                tecla = getch();
                
}while (tecla != 13);            
                     ;break;
//------------------------------------------------------------------------------
         case 27 : //comando para sair.    
              for (i = 30; i>10; i--){
                clrscr();
                textcolor(10);               
                gotoxy(i,i);
                printf("Exit");
                sleep(30);
                                      }//for
                                      
                printf("\n\nAre You Sure? (Yes/No)");
                gets(escolha);
                
              if(strstr(sair, escolha)){ 
                sleep(100);            
                exit(0);
                                       }//if
              else{
                   menu(opcao);
                   }//else
                     ;break; //comando para sair.   
                                                   
}//switch

clrscr();
textcolor(10);
gotoxy(55,25);
printf("<ESC>");
textcolor(15);
printf(" Sair");
gotoxy(67,25);
textcolor(10);
printf("<INS>");
textcolor(15);
printf(" Ajuda");    
 textcolor(10);
    gotoxy(28,2);    
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBB");
    gotoxy(28,3);
    printf ("\xBA Escolha o modo de jogo \xBA");
    gotoxy(28,4);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBC");
    textcolor(15); 
    
 if (j == 8){
         gotoxy(35,8);        
         printf ("One Player");                   
         gotoxy(35,10);
         textcolor(10);
         printf ("Multiplayer");
         textcolor(15);
         gotoxy(35,12);
         printf ("Options"); 
         gotoxy(35,14);
         printf ("Score"); 
         gotoxy(35,10);            
          }//if
          
 if (j == 10){         
         gotoxy(35,8);       
         printf ("One Player");        
         gotoxy(35,10);       
         printf ("Multiplayer");         
         gotoxy(35,12);
         textcolor(10);
         printf ("Options"); 
         textcolor(15);
         gotoxy(35,14);
         printf ("Score"); 
         gotoxy(35,12);              
                }//if
                                 
 if (j == 12){       
         gotoxy(35,8);
         textcolor(15);
         printf ("One Player");          
         gotoxy(35,10);        
         printf ("Multiplayer");              
         gotoxy(35,12);
         printf ("Options");         
         gotoxy(35,14);
         textcolor(10);
         printf ("Score");
         textcolor(15);   
         gotoxy(35,14);       
               }//if

if (j == 14){
         textcolor(15);
         gotoxy(35,8);
         textcolor(10);         
         printf ("One Player");  
         textcolor(15);       
         gotoxy(35,10);
         printf ("Multiplayer");
         gotoxy(35,12);        
         printf ("Options");
         textcolor(15); 
         gotoxy(35,14);
         printf ("Score"); 
         textcolor(15); 
         gotoxy(35,8);                  
         }//if
                
} while ((getch() != 13));

opcao = j;

if (opcao == 10){//Entra na função options para escolher o tamanho do tabuleiro
    for (i = 35; i<75; i++){     
        clrscr();   
         textcolor(15);
         gotoxy(i,8);              
         printf ("One Player");        
         gotoxy(75-i,10);
         printf ("Multiplayer");
         gotoxy(i,12);        
         printf ("Options");       
         gotoxy(75-i,14);
         printf ("Score");             
    sleep(15);        
                           }//for
     options();
          }//if
          
if (opcao == 12){//Entra na função Score. 
        score();  
                }//if
else{
     jogo(opcao);
     }//else

}//menu

//============================================================================== 
//Analisa opções do tabuleiro e nível de dificuldade.                     
void options (){ 
    int i = 11, j = 43, k = 43, tecla, aux;
    
    clrscr();
    textcolor(10);
    gotoxy(35,3);
    printf("\xC9\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBB");
    gotoxy(35,4);
    printf ("\xBA Options \xBA");
    gotoxy(35,5);
    printf("\xC8\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBC"); 
    gotoxy(35,7); 
    textcolor(15);  
    printf("Press ENTER"); 
    textcolor(15);     
    gotoxy(33,9);
    printf("Change The TAB.");      
    gotoxy(34,11);
    textcolor(10);
    printf ("08"); 
    gotoxy(37,11);
    textcolor(15);
    printf ("10");
    gotoxy(40,11);
    printf ("12"); 
    gotoxy(43,11);   
    printf ("14");
    gotoxy(46,11);   
    printf ("16");
    gotoxy(35,13);    
    printf ("Difficulty");
    gotoxy(34,15);
    textcolor(10);   
    printf ("Easy"); 
    textcolor(15);
    gotoxy(43,15);   
    printf ("Hard"); 
textcolor(10);
gotoxy(55,25);
printf("<ESC>");
textcolor(15);
printf(" Sair");
gotoxy(67,25);
textcolor(10);
printf("<INS>");
textcolor(15);
printf(" Ajuda"); 
 
do{  //Aqui se inicia o laço do menu. Terminar o menu opções.
     tecla = getch(); 
     switch (tecla){ 
//------------------------------------------------------------------------------                    
          case 75 : //Seta esquerda, comanda a escolha do tamanho do tabuleiro ou a dificuldade, de acordo com o valor de i.
               if(i == 11){               
                if (j-3>33){                           
                            j=j-3;                                                               
                           }//if              
                else{
                         j=46;                                                        
                     }//else
                            }//if
                if(i == 15){               
                if (k-9>33){      //Verificar onde esta dando erro na hora de escolher a dificuldade.                    
                            k=k-9;                                                               
                           }//if               
                else{
                         k=43;                                                        
                     }//else
                            }//if 
                     ;break; 
//------------------------------------------------------------------------------                      
          case 77 :
               if(i == 11){
                if (j+3<47){
                      j=j+3;                                       
                            }//if
                else{            
                         j=34;                                           
                     }//else
                          }
               if(i == 15){
                if (k+9<44){
                      k=k+9;                                       
                            }//if
                else{            
                         k=34;                                           
                     }//else
                          }//if  
                     ;break; 
//------------------------------------------------------------------------------
          case 72 :       //Manipula o valor de "i". Direção vertical         
                if (i-4>10){                           
                            i=i-4;                                                                                          
                           }//if               
                else{
                         i=15;                                                        
                     }//else 
                     ;break; 
//------------------------------------------------------------------------------                      
          case 80 :
                if (i+4<16){
                      i=i+4;                                       
                            }//if
                else{            
                         i=11;                                           
                     }//else
                     ;break;
//------------------------------------------------------------------------------
          case 82 ://Responsável pela ajuda
           for (aux = 0; aux<25; aux++){
                clrscr();
                textcolor(10);               
                gotoxy(25-aux,25-aux);
                printf("Ajuda");
                sleep(30);
                                      }//for
                                      
                sleep(70);                      
                printf("\n\nChange The TAB.");
                textcolor(15);
                sleep(70);
                printf("\nEspecifica o tamanho do tabuleiro a ser usado durante o jogo.");
                textcolor(10);
                sleep(70);
                printf("\n\nDifficulty");
                textcolor(15);
                sleep(70);
                printf("\nEspecifica o nivel de dificuldade do jogo.");
                textcolor(10);
                sleep(70);
                printf("\n.EasY");
                textcolor(15);
                sleep(70);
                printf("\nJogo facil, o computador escolhe uma jogada arbitraria.");
                textcolor(10);
                sleep(70);
                printf("\n.Hard");
                textcolor(15);
                sleep(70);
                printf("\nJogo dificil, o computador escolhe a melhor jogada."); 
                printf("\n\nPressione "); 
                textcolor(10);
                printf("ENTER "); 
                textcolor(15);
                printf("para voltar ao menu.");                  
                getch();
                 
                     ;break;
//------------------------------------------------------------------------------
         case 27 : break; //comando para sair.                           
                    }
//------------------------------------------------------------------------------ 
clrscr();
textcolor(10);
gotoxy(55,25);
printf("<ESC>");
textcolor(15);
printf(" Sair");
gotoxy(67,25);
textcolor(10);
printf("<INS>");
textcolor(15);
printf(" Ajuda"); 
textcolor(10);   
    gotoxy(35,3);
    printf("\xC9\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBB");
    gotoxy(35,4);
    printf ("\xBA Options \xBA");
    gotoxy(35,5);
    printf("\xC8\xCD\xCD");      
    printf("\xCD\xCD\xCD\xCD");  
    printf("\xCD\xCD\xCD\xBC");    
    textcolor(15);     
    gotoxy(33,9);
    printf("Change The TAB.");   
    gotoxy(35,13);    
    printf ("Difficulty");
    gotoxy(34,15);
    textcolor(10);   
    printf ("Easy"); 
    textcolor(15);
    gotoxy(43,15);   
    printf ("Hard");
    textcolor(15);
    
 if (j == 34){
    gotoxy(34,11);
    textcolor(15);
    printf ("08"); 
    gotoxy(37,11);
    textcolor(10);
    printf ("10");
    gotoxy(40,11);
    textcolor(15);
    printf ("12"); 
    gotoxy(43,11);   
    printf ("14");   
    gotoxy(46,11);   
    printf ("16");
     gotoxy(37,11); 
          }//if

if (j == 37){         
    gotoxy(34,11);
    textcolor(15);
    printf ("08"); 
    gotoxy(37,11);
    printf ("10");
    gotoxy(40,11);
    textcolor(10);
    printf ("12"); 
    gotoxy(43,11); 
    textcolor(15);  
    printf ("14");
    gotoxy(46,11);   
    printf ("16");
    gotoxy(40,11);            
                }//if
                              
if (j == 40){       
    gotoxy(34,11);
    textcolor(15);
    printf ("08"); 
    gotoxy(37,11);    
    printf ("10");
    gotoxy(40,11);
    printf ("12"); 
    gotoxy(43,11); 
    textcolor(10);  
    printf ("14");
    textcolor(15);
    gotoxy(46,11);   
    printf ("16");
    gotoxy(43,11);        
               }//if
              
if (j == 43){
    gotoxy(34,11);
    textcolor(15);
    printf ("08"); 
    gotoxy(37,11);
    textcolor(15);
    printf ("10");
    gotoxy(40,11);
    printf ("12"); 
    gotoxy(43,11);   
    printf ("14");
    gotoxy(46,11);
    textcolor(10);   
    printf ("16");
    gotoxy(34,11);                
               }//if
                
if (j == 46){
    gotoxy(34,11);
    textcolor(10);
    printf ("08"); 
    gotoxy(37,11);
    textcolor(15);
    printf ("10");
    gotoxy(40,11);
    printf ("12"); 
    gotoxy(43,11);   
    printf ("14");
    gotoxy(46,11);   
    printf ("16");
   gotoxy(34,11);                
               }//if
                 
if (k == 34){ 
   textcolor(15);   
   gotoxy(34,15);   
   printf ("Easy"); 
   textcolor(10);
   gotoxy(43,15);   
   printf ("Hard");
               }//if
               
   if (k == 43){ 
   textcolor(10);   
   gotoxy(34,15);   
   printf ("Easy"); 
   textcolor(15);
   gotoxy(43,15);   
   printf ("Hard");
               }//if
                                      
} while (getch() != 27); 
 
printf("Valor de opco final: %d \n", j);

if (j == 34){
      tamanho = 10;
           }//if
if (j == 37){
      tamanho = 12;
           }//if
if (j == 40){
      tamanho = 14;
           }//if
if (j == 43){
      tamanho = 16;
           }//if 
if (j == 46){
      tamanho = 8;
             }//if                 
    clrscr();
    menu(opcao);          
}

//==============================================================================
//Função que controla o SCORE do jogo
void score (){
int i;
textcolor(10);  
    
   for (i = 14;i>5; i--){
       clrscr();
       gotoxy(38,2);
       textcolor(10);
       printf("SCORE");
       gotoxy(20,i);       
       printf("Jogador\t\tPts\t\tTAB.");
       sleep(30);
                                        }//for
   textcolor(15);
   gotoxy(20,i+3);
   printf("MAC\t\t\t24\t\t8");
   textcolor(10);
   gotoxy(55,25);
   printf("<ESC>");  
   textcolor(15);
   printf(" Sair"); 
     getch();
     menu(opcao);
     }//score 

//==============================================================================
//Insere a tela de créditos              
void final (){ 
    int i;
    clrscr();
    sleep(500);
    
for (i=20; i>5; i--){
    clrscr();
    gotoxy (35,i);
    textcolor(14);
    printf("CREDITOS");
    gotoxy (23,i+2);
    printf("PROGRAMADO POR: Michell Stuttgart.");
    gotoxy (28,i+4);
    printf("DISCIPLINA: ECO 002/012"); 
    sleep(70);     
                     }//for
    textcolor(15);
    gotoxy(30,14);
    printf("Obrigado por Jogar!\n");
    gotoxy(20,18);
    sleep(2000);
    exit(0);
}//final

//==============================================================================
//Inicializa o tabuleiro
void inicializaTab (){ 
      int i, j;     
        for (i=0; i<18; i++){
             for (j=0; j<18; j++){
                 tab[i][j] = '#';
                                      }//for
                                 }//for
      textcolor(4);                                                       
      tab [(tamanho/2) - 1][(tamanho/2) - 1] = 'O';
      tab [(tamanho/2) - 1][tamanho/2] = 'X';
      tab [tamanho/2][(tamanho/2) - 1] = 'X';
      tab [tamanho/2][tamanho/2] = 'O';                                    
}//inicializaTab

//==============================================================================
//Imprime na tela o tabuleiro                             
void mostraTab (){ 
     int i, j; 
     
     printf ("\n\n\t\t\t   ");
     
     for (i=0; i < tamanho; i++){
         textcolor(15);
         printf ("%2d ", i);
                                }//for
                                
     printf ("\n ");
                      
        for (i=0; i < tamanho; i++){
            textcolor(15);
            printf ("\n\t\t\t%2d ", i);
            
             for (j=0; j < tamanho; j++){
                 
                 if (tab[i][j] == '#'){
                 textcolor(15);                 
                 printf (" %c ", tab[i][j]);               
                                      }//if
                                      
                 if (tab[i][j] == 'O'){
                 textcolor(3);
                 printf (" %c ", tab[i][j]);
                                       }//if
                                       
                 if (tab[i][j] == 'X'){
                 textcolor(14);
                 printf (" %c ", tab[i][j]);
                                      }//if
                                        
                                        }//for
                                   }//for  
}//mostraTab

//==============================================================================
//Controla as demais funções do jogo                                              
void jogo (int opcao){
    char continuar[4];
    char continuarjogo [ ] = {"simSIMYEye"};         
    int i, j, k, a, contador = 1, contadorX = 1, contadorO = 1, contadorJog1,contadorPC; 
    int auxi [tamanho*tamanho];
    
do{ /*Verifica se o usuário deseja continuar o jogo.*/
    clrscr();                                 
    inicializaTab ();
    mostraTab ();     
    contadorJog1 = 1;
    contadorPC = 1;
    
do{ /*Analise das jogadas */
   for (k=0; k<tamanho*tamanho; k++){                          
               auxi[k] = 0;                      
                                    }//for
                                                                                  
    printf ("\n");
    contadorJog1 = 0;
    contadorPC = 0;  
    contador = 0;
    contadorX = 0;
    contadorO = 0;  
    textcolor(15); 
            
//Analise a quantidade de espaços vazios, de peças 'X' e de peças 'O' que existem no tabuleiro.
for (i=0; i<tamanho; i++){
    for (j=0; j<tamanho; j++){
        
                  if (tab[i][j] == '#'){
                             contador = contador + 1;                                                         
                                       }//if
                  if (tab[i][j] == 'X'){
                             contadorX = contadorX + 1;                             
                                       }//if
                  if (tab[i][j] == 'O'){
                             contadorO = contadorO + 1;
                                       }//if
                              }//for
                         }//for
                        
//------------------------------------------------------------------------------
//Analisa se existe possibilidade de jogada pra o jogador 1
for (i=0; i<tamanho; i++){
        for (j=0; j<tamanho; j++){                                          
                           
     if (tab[i][j]=='#'){/*verifica a vizinhança da casa escolhida na jogada do jogador1 ('X').*/                
                                           
           if ((i-1>=0)&&(j-1>=0)&&(tab[i-1][j-1] == 'O')){ /*1 - Verifica diagonal superior esquerda*/                                                                                
                                 a=1;                     
                                 while ((tab[i-a][j-a] == 'O')&&((i-a>=0)&&(j-a>=0))){                                                                                                                                                                
                                                   a = a+1;                             
                                                                                   }
                                 if (tab[i-a][j-a] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                         }                                                                                              
                                                       }                                                                    
           if ((i-1>=0)&&(tab[i-1][j] == 'O')){  /*2 - Verifica vertical cima*/                                                                                                                            
                                                                         
                                 a=1;                     
                                 while ((tab[i-a][j] == 'O')&&(i-a>=0)){                                                                                                                                                                                                                   
                                                    a = a+1;                                                                                                                                                                             
                                                                     } 
                                 if (tab[i-a][j] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                       }                                                                                                                                              
                                            }                                                                                                                                       
           if ((i-1>=0)&&(j+1<tamanho)&&(tab[i-1][j+1] == 'O')){ /*3 - Verifica diagonal superior direita*/                                                                                                                                                                                                                           
                                                             
                                 a=1;                     
                                 while ((tab[i-a][j+a] == 'O')&&((i-a>=0)&&(j+a<tamanho))){                                                                                                                                                                                                                  
                                                    a = a+1;                                        
                                                                                         }  
                                if (tab[i-a][j+a] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                         }                                                           
                                                             }                                                                                                   
           if ((j-1>=0)&&(tab[i][j-1] == 'O')){ /*4 - Verifica horizontal esquerda*/                           
                                                
                                 a=1;                     
                                 while ((tab[i][j-a] == 'O')&&(j-a >= 0)){                                                                                                                   
                                                   a = a+1;                                                                                                                                                                             
                                                                        }                                        
                                 if (tab[i][j-a] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                       }                                                                          
                                            }                                                                                                                                     
           if ((j+1<tamanho)&&(tab[i][j+1] == 'O')){ /*5 - Verifica horizontal direita*/                                                                                                                                                                                                                                   
                                                   
                                 a=1;                     
                                 while ((tab[i][j+a] == 'O')&&(j+a<tamanho)){                                                                                                                                                                           
                                                   a = a+1;                                           
                                                                          }                                          
                                 if (tab[i][j+a] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                        }                                                                 
                                               
                                                 }                                                                                           
           if ((i+1<tamanho)&&(j-1>=0)&&(tab[i+1][j-1] == 'O')){ /*6 - Verifica diagonal inferior esquerda*/                                                              
                                                          
                                 a=1;                     
                                 while ((tab[i+a][j-a] == 'O')&&((i+a<tamanho)&&(j-a>=0))){                                                                                                                                                                  
                                                    a = a+1;
                                                                                         }                                                                                                                                                                                                                                                           
                                   if (tab[i+a][j-a] == 'X'){
                                                        contadorJog1 = contadorJog1 + 1;
                                                          }                                                                                                                          
                                                             }                                                                                                     
           if ((i+1<tamanho)&&(tab[i+1][j] == 'O')){ /*7 - Verifica vertical baixo*/                                                                                   
                                                                 
                                 a = 1;                     
                                 while ((tab[i+a][j] == 'O')&&(i+a<tamanho)){                                                                                                                                                                                                                                            
                                                  a = a+1;                                                                         
                                                                          }                                      
                                   if (tab[i+a][j] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                         }                                                                                                                                 
                                                  }                                                                                                   
           if ((i+1<tamanho)&&(j+1<tamanho)&&(tab[i+1][j+1] == 'O')){ /*8 - Verifica inferior direita*/                                                                                    
                                       
                                 a = 1;                     
                                 while ((tab[i+a][j+a] == 'O')&&((i+a<tamanho)&&(j+a<tamanho))){                                                                                                                                                                                                                 
                                                   a = a+1;                                                                        
                                                                                              }                                      
                                     if (tab[i+a][j+a] == 'X'){
                                                         contadorJog1 = contadorJog1 + 1;
                                                               }                                                                                        
                                                                  }                                                                  
             }/*chave do if*/            
             }}/*chave do for*/           
                                                    
    //============================================================================================================================== 
     //Analisa possibilidade de jogada para o computador   
    for (i=0; i<tamanho; i++){
         for (j=0; j<tamanho; j++){                                          
                           
     if (tab[i][j]=='#'){/*verifica a vizinhança da casa escolhida na jogada do computador ('O').*/                
                                           
           if ((i-1>=0)&&(j-1>=0)&&(tab[i-1][j-1] == 'X')){ /*1 - Verifica diagonal superior esquerda*/ 
                                     
                                 while ((tab[i-a][j-a] == 'X')&&((i-a>=0)&&(j-a>=0))){                                                                                                                                                                
                                                   a = a+1;                             
                                                                                   }
                                 if (tab[i-a][j-a] == 'O'){
                                                         contadorPC = contadorPC + 1;
                                                         }                                                                                              
                                                       }                                                                    
           if ((i-1>=0)&&(tab[i-1][j] == 'X')){  /*2 - Verifica vertical cima*/                                                                                                                                    
                                                                              
                                 a=1;                     
                                 while ((tab[i-a][j] == 'X')&&(i-a>=0)){                                                                                                                                                                                                                   
                                                    a = a+1;                                                                                                                                                                             
                                                                     } 
                                 if (tab[i-a][j] == 'O'){
                                                         contadorPC = contadorPC + 1;
                                                       }                                                                                                                                              
                                            }                                                                                                                                       
           if ((i-1>=0)&&(j+1<tamanho)&&(tab[i-1][j+1] == 'X')){ /*3 - Verifica diagonal superior direita*/                                                                                                                                                                                                                                 
                                                             
                                 a=1;                     
                                 while ((tab[i-a][j+a] == 'X')&&((i-a>=0)&&(j+a<tamanho))){                                                                                                                                                                                                                  
                                                    a = a+1;                                        
                                                                                         }  
                                if (tab[i-a][j+a] == 'O'){
                                                         contadorPC = contadorPC + 1;
                                                         }                                                           
                                                             }                                                                                                   
           if ((j-1>=0)&&(tab[i][j-1] == 'X')){ /*4 - Verifica horizontal esquerda*/                           
                                                 
                                 a=1;                     
                                 while ((tab[i][j-a] == 'X')&&(j-a >= 0)){                                                                                                                   
                                                   a = a+1;                                                                                                                                                                             
                                                                        }                                        
                                 if (tab[i][j-a] == 'O'){
                                                        contadorPC = contadorPC + 1;
                                                       }                                                                          
                                            }                                                                                                                                     
           if ((j+1<tamanho)&&(tab[i][j+1] == 'X')){ /*5 - Verifica horizontal direita*/                                                                                                                                                                                                                                   
                                                  
                                 a=1;                     
                                 while ((tab[i][j+a] == 'X')&&(j+a<tamanho)){                                                                                                                                                                           
                                                   a = a+1;                                           
                                                                          }                                          
                                 if (tab[i][j+a] == 'O'){
                                                        contadorPC = contadorPC + 1;
                                                      }                                                                 
                                               
                                                 }                                                                                           
           if ((i+1<tamanho)&&(j-1>=0)&&(tab[i+1][j-1] == 'X')){ /*6 - Verifica diagonal inferior esquerda*/                                                              
                                                            
                                 a=1;                     
                                 while ((tab[i+a][j-a] == 'X')&&((i+a<tamanho)&&(j-a>=0))){                                                                                                                                                                  
                                                    a = a+1;
                                                                                         }                                                                                                                                                                                                                                                           
                                   if (tab[i+a][j-a] == 'O'){
                                                         contadorPC = contadorPC + 1;
                                                          }                                                                                                                          
                                                             }                                                                                                     
           if ((i+1<tamanho)&&(tab[i+1][j] == 'X')){ /*7 - Verifica vertical baixo*/                                                                                   
                                                              
                                 a = 1;                     
                                 while ((tab[i+a][j] == 'X')&&(i+a<tamanho)){                                                                                                                                                                                                                                            
                                                  a = a+1;                                                                         
                                                                          }                                      
                                   if (tab[i+a][j] == 'O'){
                                                        contadorPC = contadorPC + 1;
                                                         }                                                                                                                                 
                                                  }                                                                                                   
           if ((i+1<tamanho)&&(j+1<tamanho)&&(tab[i+1][j+1] == 'X')){ /*8 - Verifica inferior direita*/                                                                                   
                                                                              
                                 a = 1;                     
                                 while ((tab[i+a][j+a] == 'X')&&((i+a<tamanho)&&(j+a<tamanho))){                                                                                                                                                                                                                 
                                                   a = a+1;                                                                        
                                                                                              }                                      
                                     if (tab[i+a][j+a] == 'O'){
                                                        contadorPC = contadorPC + 1;
                                                               }                                                                                        
                                                                  }                                                                  
             }/*chave do if*/         
             }}/*chave do for*/
               
//==================================================================================================================================
    if ((contadorX != 0)&&(contadorJog1 != 0)){
    jogador1 ();
                        }
    clrscr();
    mostraTab ();
    if ((opcao == 8)&&(contadorO != 0)&&(contadorPC != 0)){ 
              jogador2 ();
              textcolor(15);
                                      }
    if ((opcao == 14)&&(contadorO!= 0)&&(contadorPC != 0)){
              computador ();
              textcolor(15);
              sleep(2000);
                                       }
      
    clrscr();
    mostraTab ();                                                                       
} while ((contador != 0)&&(contadorO != 0)&&(contadorX != 0)&&((contadorJog1 != 0)&&(contadorPC != 0))); 
//Aqui há um contador da quantidade de peças após o termino do jogo
contador = 0;
contadorX = 0;
contadorO = 0; 
for (i=0; i<tamanho; i++){
    for (j=0; j<tamanho; j++){
                  if (tab[i][j] == '#'){
                             contador = contador + 1;                                                           
                                       }
                  if (tab[i][j] == 'X'){
                             contadorX = contadorX + 1;                             
                                       }
                  if (tab[i][j] == 'O'){
                             contadorO = contadorO + 1;
                                       }
                              }
                         }
if (contadorO < contadorX){ /*Analisa a quantidade de peças no tabuleiro e undica o vencedor*/
                textcolor(10);
                printf ("\n\n\nO jogador 1 venceu!!!\n\n");
                          }
if (contadorO == contadorX){
                          textcolor(10);
                          printf ("\n\n Empate!");
                          }  
if (contadorO > contadorX){
         if (opcao == 8){
               textcolor(10);
               printf ("\n\nO jogador 2 venceu!!!\n");
                        }
         if (opcao == 14){
               textcolor(10);
               printf ("\n\nGAMEOVER!\nO computador venceu!!!\n");
                         }
                           }
          textcolor(15);
               printf ("- Quantidade de pecas do jogador 1 ('X'): %d\n", contadorX);
         if (opcao == 8){
               printf ("- Quantidade de pecas do jogador 2 ('O'): %d", contadorO);
                        }
         if (opcao == 14){
               printf ("- Quantidade de pecas do computador ('O'): %d", contadorO);
                        }                                              
/*Analisa se o jogador deseja continuar o jogo*/                 
         printf ("\n\nDeseja continuar o jogo?: ");
         scanf ("%s", &continuar);
} while (strstr(continuarjogo, continuar)); 
menu(opcao);
}
//==================================================================================================================================
//==================================================================================================================================                                             
void jogador1 (){ /*verifica a vizinhança da casa escolhida na jogada do jogador 1 ('X').*/ 
     int i, j, k, a, x=0, contador, cont = 0;
     int auxi[tamanho];
     char escolha[10];
     char passar [ ] = {"siSIye"}; 
     char sair [ ] = {"EXIT"};    
     textcolor(14);
     printf ("\n- Jogador 1");
     textcolor(15);
     printf ("\n\n- Analise sua jogada.");//colocar um submenu aqui, com direito a sair do jogo.
     printf ("\n\n- Passar a jogada? (s/n): ");
     gets (escolha);
     if (strstr(sair, escolha)){ //Opção para retornar ao menu
               menu(opcao);                                           
                                }
     if (strstr(passar, escolha)){ //verifica a opção escolhida pelo jogador 1.
                if (opcao == 14){
                       textcolor(14);
                       printf ("\n\nJogador 1 passou a vez para o computador.");
                       sleep(2000);                                            
                                }
                if (opcao == 8){
                       textcolor(14);
                       printf ("\n\nJogador 1 passou a vez para o jogador 2.");
                       sleep(2000);                       
                                }
                              }
     else{
                       printf ("\nJogador 1('X') (linha, coluna): ");
                       scanf ("%d,%d", &i, &j);               
     
     /*verifica a vizinhança da casa escolhida na jogada do jogador 1 ('X'). Se existem espaços vazios*/        
     if (tab[i][j]=='#'){             
         if ((tab[i-1][j-1]=='#')&&(tab[i-1][j]=='#')&&(tab[i-1][j+1]=='#')&&(tab[i][j-1]=='#')&&(tab[i][j+1]=='#')
             &&(tab[i+1][j-1]=='#')&&(tab[i+1][j]=='#')&&(tab[i+1][j+1]=='#')||((i<0)||(i>=tamanho)||(j<0)||(j>=tamanho))){
                        textcolor(4);
                        printf("\nJogada invalida!\n");
                        sleep(2000);                                                                                     }                                                                                                                
         else{                 
//===============================================================================================================================            
          // if ((i-1>=0)&&(j-1>=0)&&(tab[i-1][j-1]=='O')){ /*1 - Verifica diagonal superior esquerda*/  
                                 
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j-a]=='O')&&((i-a>=0)&&(j-a>=0))){                                                                                                                          
                                                   contador = contador + 1;
                                                   a = a+1;  
                                                                           
                                                                                   }                                                                                                             
                                               if (tab[i-a][j-a] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j-a] = 'X'; 
                                                              cont = cont +1;                                                            
                                                                                     }
                                                                      }
              //                                       }                                                                    
       //    if ((i-1>=0)&&(tab[i-1][j]=='O')){  /*2 - Verifica vertical cima*/                                                                                                                                    
                          
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j] == 'O')&&(i-a>=0)){                                                                                                                                     
                                                   contador = contador + 1;
                                                    a = a+1;  
                                                                                                                                                                                                                               
                                                                      }                                                                                                        
                                               if (tab[i-a][j] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j] = 'X';
                                                              cont = cont +1;                                                              
                                                                                     }
                                                                     }
           //                                 }                                                                           
          // if ((i-1>=0)&&(j+1<tamanho)&&(tab[i-1][j+1]=='O')){ /*3 - Verifica diagonal superior direita*/                                                                                                                                                                                                                                 
              
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j+a] == 'O')&&((i-a>=0)&&(j+a<tamanho))){                                                                                                                                                                             
                                                   contador = contador + 1;
                                                   a = a+1;
                                                                                          
                                                                                         }                                                                                     
                                               if (tab[i-a][j+a] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j+a] = 'X';
                                                              cont = cont +1;                                                             
                                                                                     }
                                                                      }
            //                                                 }                                                                                                   
          // if ((j-1>=0)&&(tab[i][j-1]=='O')){ /*4 - Verifica horizontal esquerda*/                             
            
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i][j-a] == 'O')&&(j-a >= 0)){                                                                                                                    
                                                   contador = contador + 1;
                                                   a = a+1; 
                                                                                                                                                                                                                               
                                                                        }                                                                                                                                                 
                                               if (tab[i][j-a] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i][j-a] = 'X'; 
                                                              cont = cont +1;                                                            
                                                                                     }
                                                                    } 
            //                                                }                                                                                                                                 
         // if ((j+1<tamanho)&&(tab[i][j+1]=='O')){ /*5 - Verifica horizontal direita*/                                                                            
                                                                                                                                                                                 
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i][j+a] == 'O')&&(j+a<tamanho)){                                                                                                                           
                                                   contador = contador + 1;
                                                   a = a+1; 
                                                                                               
                                                                          }                                                                                                                                         
                                               if (tab[i][j+a] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i][j+a] = 'X'; 
                                                              cont = cont + 1;                                                             
                                                                                     }
                                                                    } 
          //                                      }                                                                                              
         // if ((i+1<tamanho)&&(j-1>=0)&&(tab[i+1][j-1]=='O')){ /*6 - Verifica diagonal inferior esquerda*/                                                              
             
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i+a][j-a] == 'O')&&((i+a<tamanho)&&(j-a>=0))){                                                                                                                 
                                                    contador = contador + 1;
                                                    a = a+1;
                                                       
                                                                                         }                                                                                                                                                                                                                                                                                                                                                                           
                                               if (tab[i+a][j-a] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i+a][j-a] = 'X';
                                                              cont = cont +1;                                                              
                                                                                     }
                                                                      }
          //                                                                   }                                                                                                        
          // if ((i+1<tamanho)&&(tab[i+1][j]=='O')){ /*7 - Verifica vertical baixo*/                                                                                   
              
                                 contador = 0;                    
                                 a = 1;                     
                                 while ((tab[i+a][j] == 'O')&&(i+a<tamanho)){                                                                                                                
                                                  contador = contador + 1;                                                                                  
                                                  a = a+1;  
                                                                                                                           
                                                                          }                                                                                                                                                      
                                                     if (tab[i+a][j] == 'X'){
                                                           tab[i][j]='X';
                                                           for (a=1; a<=contador; a++){
                                                               tab[i+a][j] = 'X'; 
                                                               cont = cont +1;                                                             
                                                                                      }
                                                                          }
          //                                     }                                                                                                    
          // if ((i+1<tamanho)&&(j+1<tamanho)&&(tab[i+1][j+1]=='O')){/*8 - Verifica inferior direita*/                                                                                    
             
                                 contador = 0;                    
                                 a = 1;                     
                                 while ((tab[i+a][j+a] == 'O')&&((i+a<tamanho)&&(j+a<tamanho))){                                                                                                                                 
                                                   contador = contador + 1;                               
                                                   a = a+1; 
                                                                                                                 
                                                                                              }                                                                                                                                                     
                                                    if (tab[i+a][j+a] == 'X'){
                                                          tab[i][j]='X';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i+a][j+a] = 'X';
                                                              cont = cont +1;                                                              
                                                                                     }
                                                                            }
            //                                                    }         
           if (cont == 0){
            textcolor(4);   
            printf("\njogada invalida!\n");
            sleep(2000);
                         }                                                                                                                   
            }   
            }      
else{
     textcolor(4);
     printf("\nJogada invalida! A casa escolhida ja esta ocupada.\n");
     sleep(2000);     
     }                     
                                          }                                                
                                          }
//==================================================================================================================================
//==================================================================================================================================                                                                                     
void jogador2 ( ){ //Verifica a vizinhança da casa escolhida na jogada do jogador 2 ('O').
     int i, j, a, contador, cont = 0;
     char escolha[10];
     char passar [ ] = {"siSIye"};
     char sair [ ] = {"sair"};    
     textcolor(3);
     printf ("\n- Jogador 2.");
     textcolor(15);
     printf ("\n\n- Analise sua jogada.");
     printf ("\n\n- Passar a jogada? (s/n): ");
     scanf ("%s", &escolha);
     if (strstr(sair, escolha)){ //Opção para retornar ao menu
               menu(opcao);                                           
                                }     
     if (strstr(passar, escolha)){ //verifica a opção escolhida pelo jogador 2.
                       textcolor(3);
                       printf ("\n\nJogador 2 passou a vez para o jogador 1.");
                       sleep(2000);
                                }
     else{
                       printf ("\n\nJogador 2('O') (linha, coluna): ");
                       scanf ("%d,%d", &i, &j);    
            
     /*verifica a vizinhança da casa escolhida na jogada do jogador 2 ('O'). Se existem espaços vazios*/     
     if (tab[i][j]=='#'){               
         if ((tab[i-1][j-1]=='#')&&(tab[i-1][j]=='#')&&(tab[i-1][j+1]=='#')&&(tab[i][j-1]=='#')&&(tab[i][j+1]=='#')
              &&(tab[i+1][j-1]=='#')&&(tab[i+1][j]=='#')&&(tab[i+1][j+1]=='#')||((i<0)||(i>=tamanho)||(j<0)||(j>=tamanho))){
                        textcolor(4);
                        printf("\nJogada invalida!\n");
                        sleep(2000);                                                                                        }                        
                                                                              
         else{ 
           
            if ((tab[i-1][j-1]=='X')&&(i-1>=0)&&(j-1>=0)){ /*1 - Verifica diagonal superior esquerda*/ 
              
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j-a] == 'X')&&((i-a>=0)&&(j-a>=0))){                                                                                                                          
                                                   contador = contador + 1;
                                                   a = a+1;                              
                                                                                   }                                                                                                                     
                                               if (tab[i-a][j-a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j-a] = 'O'; 
                                                              cont = cont +1;                                                            
                                                                                     }
                                                                      }
                                                        }                                                                    
            if ((tab[i-1][j]=='X')&&(i-1>=0)){ /*2 - Verifica vertical cima*/                                                                                      
                                                                       
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j] == 'X')&&(i-a>=0)){                                                                                                                                     
                                                   contador = contador + 1;
                                                    a = a+1;                                                                                                                                                                             
                                                                      }                                                           
                                               if (tab[i-a][j] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j] = 'O';
                                                              cont = cont +1;                                                              
                                                                                     }
                                                                     }
                                          }                                                                     
            if ((tab[i-1][j+1]=='X')&&(i-1>=0)&&(j+1<tamanho)){ /*3 - Verifica diagonal superior direita*/                                                                                                 
              
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j+a] == 'X')&&((i-a>=0)&&(j+a<tamanho))){                                                                                                                                                                             
                                                   contador = contador + 1;
                                                   a = a+1;                                        
                                                                                         }                                                                                                    
                                               if (tab[i-a][j+a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j+a] = 'O';
                                                              cont = cont +1;                                                             
                                                                                     }
                                                                      }
                                                              }                                                                                                   
            if ((tab[i][j-1]=='X')&&(j-1>=0)){ /*4 - Verifica horizontal esquerda*/                           
             
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i][j-a] == 'X')&&(j-a >= 0)){                                                                                                                    
                                                   contador = contador + 1;
                                                   a = a+1;                                                                                                                                                                             
                                                                        }                                                                                                                                              
                                               if (tab[i][j-a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i][j-a] = 'O'; 
                                                              cont = cont +1;                                                            
                                                                                     }
                                                                    }
                                            }                                                                     
            if ((tab[i][j+1]=='X')&&(j+1<tamanho)){  /*5 - Verifica horizontal direita*/                                                                              
                                                                                                   
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i][j+a] == 'X')&&(j+a<tamanho)){                                                                                                                           
                                                   contador = contador + 1;
                                                   a = a+1;                                           
                                                                          }                                                                                       
                                               if (tab[i][j+a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i][j+a] = 'O'; 
                                                              cont = cont + 1;                                                             
                                                                                     }
                                                                    } 
                                                 }                                                                                               
            if ((tab[i+1][j-1]=='X')&&(i+1<tamanho)&&(j-1>=0)){ /*6 - Verifica diagonal inferior esquerda*/                                                              
              
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i+a][j-a] == 'X')&&((i+a<tamanho)&&(j-a>=0))){                                                                                                                 
                                                    contador = contador + 1;
                                                    a = a+1;
                                                                                         }                                                                                                                                                                                                                                                                                                                                                                           
                                               if (tab[i+a][j-a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i+a][j-a] = 'O';
                                                              cont = cont +1;                                                              
                                                                                     }
                                                                      }
                                                            }                                                                                                            
            if ((tab[i+1][j]=='X')&&(i+1<tamanho)){ /*7 - Verifica vertical baixo*/                                                                                    
             
                                 contador = 0;                    
                                 a = 1;                     
                                 while ((tab[i+a][j] == 'X')&&(i+a<tamanho)){                                                                                                                
                                                  contador = contador + 1;                                                                                  
                                                  a = a+1;                                                                         
                                                                          }                                                                                                                                                        
                                                     if (tab[i+a][j] == 'O'){
                                                           tab[i][j]='O';
                                                           for (a=1; a<=contador; a++){
                                                               tab[i+a][j] = 'O'; 
                                                               cont = cont +1;                                                             
                                                                                      }
                                                                          }
                                                 }                                                                                                        
            if ((tab[i+1][j+1]=='X')&&(i+1<tamanho)&&(j+1<tamanho)){ /*8 - Verifica inferior direita*/                                                                                  
              
                                 contador = 0;                    
                                 a = 1;                     
                                 while ((tab[i+a][j+a] == 'X')&&((i+a<tamanho)&&(j+a<tamanho))){                                                                                                                                 
                                                   contador = contador + 1;                               
                                                   a = a+1;                                                                        
                                                                                              }                                                                                                                                                    
                                                    if (tab[i+a][j+a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i+a][j+a] = 'O';
                                                              cont = cont +1;                                                              
                                                                                     }
                                                                            }
                                                                   }                     
            if(cont == 0){
            textcolor(4);   
            printf("\njogada invalida!\n");
            sleep(2000);
                         }                                                                                                                        
            }   
            }      
else{
     textcolor(4);
     printf("\nJogada invalida! A casa escolhida ja esta ocupada.\n");
     sleep(2000);
     
     }                     
                                          }                                                
                                          }        
//===================================================================================================================================
//===================================================================================================================================      
void computador (){/*verifica a vizinhança da casa escolhida na jogada do computador ('O').*/
     int i, j, a, b, k, l, auxi[tamanho*tamanho], x = 0, quant = 0, contador = 0;    
     textcolor(3);
     printf ("\n- Computador.");
     printf ("\n\nComputador ('O') (linha, coluna): ");
     textcolor(15); 
      for (k=0; k<tamanho*tamanho; k++){         
             auxi[k] = 0;               
                           }
     /*verifica cada casa da tabela buscando a casa que possibilitar adquirir mais peças do adversário.*/ 
     for (i=0; i<tamanho; i++){
         for (j=0; j<tamanho; j++){                                          
                           
     if (tab[i][j]=='#'){/*verifica a vizinhança da casa escolhida na jogada do computador ('O').*/                
                                           
           if ((i-1>=0)&&(j-1>=0)&&(tab[i-1][j-1] == 'X')){ /*1 - Verifica diagonal superior esquerda*/ 
                                     
                                 while ((tab[i-a][j-a] == 'X')&&((i-a>=0)&&(j-a>=0))){                                                                                                                                                                
                                                   a = a+1;                             
                                                                                   }
                                 if (tab[i-a][j-a] == 'O'){
                                                         auxi[x] = a - 1;
                                                         }                                                                                              
                                                       }                                                                    
           if ((i-1>=0)&&(tab[i-1][j] == 'X')){  /*2 - Verifica vertical cima*/                                                                                                                                    
                                                                              
                                 a=1;                     
                                 while ((tab[i-a][j] == 'X')&&(i-a>=0)){                                                                                                                                                                                                                   
                                                    a = a+1;                                                                                                                                                                             
                                                                     } 
                                 if (tab[i-a][j] == 'O'){
                                                         auxi[x] = a - 1;
                                                       }                                                                                                                                              
                                            }                                                                                                                                       
           if ((i-1>=0)&&(j+1<tamanho)&&(tab[i-1][j+1] == 'X')){ /*3 - Verifica diagonal superior direita*/                                                                                                                                                                                                                                 
                                                             
                                 a=1;                     
                                 while ((tab[i-a][j+a] == 'X')&&((i-a>=0)&&(j+a<tamanho))){                                                                                                                                                                                                                  
                                                    a = a+1;                                        
                                                                                         }  
                                if (tab[i-a][j+a] == 'O'){
                                                         auxi[x] = a - 1;
                                                         }                                                           
                                                             }                                                                                                   
           if ((j-1>=0)&&(tab[i][j-1] == 'X')){ /*4 - Verifica horizontal esquerda*/                           
                                                 
                                 a=1;                     
                                 while ((tab[i][j-a] == 'X')&&(j-a >= 0)){                                                                                                                   
                                                   a = a+1;                                                                                                                                                                             
                                                                        }                                        
                                 if (tab[i][j-a] == 'O'){
                                                         auxi[x] = a - 1;
                                                       }                                                                          
                                            }                                                                                                                                     
           if ((j+1<tamanho)&&(tab[i][j+1] == 'X')){ /*5 - Verifica horizontal direita*/                                                                                                                                                                                                                                   
                                                  
                                 a=1;                     
                                 while ((tab[i][j+a] == 'X')&&(j+a<tamanho)){                                                                                                                                                                           
                                                   a = a+1;                                           
                                                                          }                                          
                                 if (tab[i][j+a] == 'O'){
                                                         auxi[x] = a - 1;
                                                      }                                                                 
                                               
                                                 }                                                                                           
           if ((i+1<tamanho)&&(j-1>=0)&&(tab[i+1][j-1] == 'X')){ /*6 - Verifica diagonal inferior esquerda*/                                                              
                                                            
                                 a=1;                     
                                 while ((tab[i+a][j-a] == 'X')&&((i+a<tamanho)&&(j-a>=0))){                                                                                                                                                                  
                                                    a = a+1;
                                                                                         }                                                                                                                                                                                                                                                           
                                   if (tab[i+a][j-a] == 'O'){
                                                         auxi[x] = a - 1;
                                                          }                                                                                                                          
                                                             }                                                                                                     
           if ((i+1<tamanho)&&(tab[i+1][j] == 'X')){ /*7 - Verifica vertical baixo*/                                                                                   
                                                              
                                 a = 1;                     
                                 while ((tab[i+a][j] == 'X')&&(i+a<tamanho)){                                                                                                                                                                                                                                            
                                                  a = a+1;                                                                         
                                                                          }                                      
                                   if (tab[i+a][j] == 'O'){
                                                         auxi[x] = a - 1;
                                                         }                                                                                                                                 
                                                  }                                                                                                   
           if ((i+1<tamanho)&&(j+1<tamanho)&&(tab[i+1][j+1] == 'X')){ /*8 - Verifica inferior direita*/                                                                                    
                                 
                                              
                                 a = 1;                     
                                 while ((tab[i+a][j+a] == 'X')&&((i+a<tamanho)&&(j+a<tamanho))){                                                                                                                                                                                                                 
                                                   a = a+1;                                                                        
                                                                                              }                                      
                                     if (tab[i+a][j+a] == 'O'){
                                                         auxi[x] = a - 1;
                                                               }                                                                                        
                                                                  }                                                                  
             }/*chave do if*/
            x = x + 1;
             }}/*chave do for*/
             
           for (k=0; k<tamanho*tamanho; k++){
               quant = 0;  
             for (x=0; x<tamanho*tamanho; x++){ /*Verifica qual o indice do contador auxi[] que possui o maior valor.*/        
                if (auxi[k] >= auxi[x]){                         
                       quant = quant + 1;                        
                                       }           
                if (quant == tamanho*tamanho){
                      l = k;/*Guarda o indice que esta contido o maior valor coletado anteriormente*/
                                            }             
                                  }                                 
                                  }                  
                  x = 0;               
             for (a=0; a<tamanho; a++){ /*Analisa as coordenadas do local onde é possivel capturar mais peças*/
                  for (b=0; b<tamanho; b++){                      
                        if (x == l){                                
                                i = a;
                                j = b;                                
                                   }  
                                x = x + 1; 
                                     }
                                }
            textcolor(3);
            printf ("%d, %d\n", i, j);
            /*Semelhante ao usado nas outras funções, Analisa a vizinhança da casa escolhida e realiza as capturas possiveis*/
            
  /*Condição é analisada novamente para não ocorrer de o computador jogar em uma casa ocupada, quando o tabuleiro estiver completo*/ 
   if(tab[i][j] == '#'){ 
           if ((i-1>=0)&&(j-1>=0)&&(tab[i-1][j-1]=='X')){ /*1 - Verifica diagonal superior esquerda*/  
                                  
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j-a] == 'X')&&((i-a>=0)&&(j-a>=0))){                                                                                                                          
                                                   contador = contador + 1;
                                                   a = a+1;                              
                                                                                   }                                                                                                                                                             
                                               if (tab[i-a][j-a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j-a] = 'O';                                                                                                                        
                                                                                   }
                                                                      }
                                                       }                                                                    
           if ((i-1>=0)&&(tab[i-1][j]=='X')){  /*2 - Verifica vertical cima*/                                                                                                                                    
                           
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j] == 'X')&&(i-a>=0)){                                                                                                                                     
                                                   contador = contador + 1;
                                                    a = a+1;                                                                                                                                                                             
                                                                      }                                                                                                         
                                               if (tab[i-a][j] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j] = 'O';                                                                                                                           
                                                                                  }
                                                                     }
                                            }                                                                                                                               
           if ((i-1>=0)&&(j+1<tamanho)&&(tab[i-1][j+1] == 'X')){ /*3 - Verifica diagonal superior direita*/                                                                                                                                                                                                                                 
               
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i-a][j+a] == 'X')&&((i-a>=0)&&(j+a<tamanho))){                                                                                                                                                                             
                                                   contador = contador + 1;
                                                   a = a+1;                                        
                                                                                        }                                                                                                                                   
                                               if (tab[i-a][j+a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i-a][j+a] = 'O';                                                                                                                        
                                                                                   }
                                                                      }
                                                           }                                                                                                   
           if ((j-1>=0)&&(tab[i][j-1] == 'X')){ /*4 - Verifica horizontal esquerda*/                             
            
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i][j-a] == 'X')&&(j-a >= 0)){                                                                                                                    
                                                   contador = contador + 1;
                                                   a = a+1;                                                                                                                                                                             
                                                                        }                                                                                                                                                
                                               if (tab[i][j-a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i][j-a] = 'O';                                                                                                                          
                                                                                 }
                                                                    } 
                                           }                                                                                                                                    
           if ((j+1<tamanho)&&(tab[i][j+1] == 'X')){ /*5 - Verifica horizontal direita*/                                                                            
                                                                                                                                                                               
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i][j+a] == 'X')&&(j+a<tamanho)){                                                                                                                           
                                                   contador = contador + 1;
                                                   a = a+1;                                           
                                                                          }                                                                                                                                          
                                               if (tab[i][j+a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i][j+a] = 'O';                                                                                                                          
                                                                                    }
                                                                    } 
                                                }                                                                                                 
           if ((i+1<tamanho)&&(j-1>=0)&&(tab[i+1][j-1] == 'X')){ /*6 - Verifica diagonal inferior esquerda*/                                                              
              
                                 contador = 0;                    
                                 a=1;                     
                                 while ((tab[i+a][j-a] == 'X')&&((i+a<tamanho)&&(j-a>=0))){                                                                                                                 
                                                    contador = contador + 1;
                                                    a = a+1;
                                                                                         }                                                                                                                                                                                                                                                                                                                                                                          
                                               if (tab[i+a][j-a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i+a][j-a] = 'O';                                                                                                                            
                                                                                    }
                                                                      }
                                                            }                                                                                                           
           if ((i+1<tamanho)&&(tab[i+1][j] == 'X')){ /*7 - Verifica vertical baixo*/                                                                                   
               
                                 contador = 0;                    
                                 a = 1;                     
                                 while ((tab[i+a][j] == 'X')&&(i+a<tamanho)){                                                                                                                
                                                  contador = contador + 1;                                                                                  
                                                  a = a+1;                                                                         
                                                                          }                                                                                                                                                     
                                                     if (tab[i+a][j] == 'O'){
                                                           tab[i][j]='O';
                                                           for (a=1; a<=contador; a++){
                                                               tab[i+a][j] = 'O';                                                                                                                          
                                                                                      }
                                                                          }
                                                 }                                                                                         
           if ((i+1<tamanho)&&(j+1<tamanho)&&(tab[i+1][j+1] == 'X')){ /*8 - Verifica inferior direita*/                                                                                    
             
                                 contador = 0;                    
                                 a = 1;                     
                                 while ((tab[i+a][j+a] == 'X')&&((i+a<tamanho)&&(j+a<tamanho))){                                                                                                                                 
                                                   contador = contador + 1;                               
                                                   a = a+1;                                                                        
                                                                                              }                                                                                                                                                    
                                                    if (tab[i+a][j+a] == 'O'){
                                                          tab[i][j]='O';
                                                          for (a=1; a<=contador; a++){                                                              
                                                              tab[i+a][j+a] = 'O';                                                                                                                          
                                                                                      }
                                                                            }
                                                               }                               
           }  
                                                         
          } /*chave da função*/         
       
