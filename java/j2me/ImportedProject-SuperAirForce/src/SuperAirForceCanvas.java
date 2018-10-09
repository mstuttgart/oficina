/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Random;
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;
import javax.microedition.media.Manager;
import javax.microedition.media.Player;

public class SuperAirForceCanvas extends GameCanvas implements Runnable{
    
     boolean jogoIniciado = false;
     boolean explosaoRodando = false;
     boolean tiroRodando = false;
     boolean jogoRodando = false;

     //controla musica de findo
     Player backPlayer;     

     Manager manager;

     Image iconeVida, iconeEnergia;

     Image winner;
     Sprite sprWinner = null;     

     // Atributos do teclado
	boolean cima = false;
	boolean baixo = false;
	boolean esquerda = false;
	boolean direita = false;
	boolean tiro = false;

     public int maxX; // Largura da tela
     public int maxY; // Altura da tela

     Random rand = new Random();

     SuperAirForce midlet;

     int novaPosY;
     int novaPosX;

     int deslocamentoInimigo = 2;    
     int deslocamentoTela = 1;
  
     int quantInimigo = 4;
     int quantTiro = 5;
            
     int contadorTiro = 0;
     int contadorExplosao = 0;   
     
     //Variaveis responsaveis pelo jogador
     int score = 0;
     int contadorVida = 3;
     int contadorContinue = 3;

     int posYTela = 0;//Guarda posição x da tela  
  
    Graphics g = getGraphics ();

    LayerManager layerManager = new LayerManager();

    //objeto persomagem
    ClassePersonagem aviao;

    ClassePersonagem energia;   
    
    ClassePersonagem gameOver = null;
    
    ClassePersonagem getReady;

    ClassePersonagem kamikase;

    ClassePersonagem chefe;

    //aloca um vetor para os inimigos
    ClassePersonagem [] inimigo = new ClassePersonagem [quantInimigo];    

    ClassePersonagem [] explosao = new ClassePersonagem [quantInimigo+2];

    ClassePersonagem [] bullet = new ClassePersonagem [quantTiro];
    
    ClassePersonagem [] bulletInimigo = new ClassePersonagem [quantInimigo];

    //objeto cenario
    ClasseCenario Cenario;



//==============================================================================
   

//==============================================================================
    public SuperAirForceCanvas(SuperAirForce midlet){
        super (true);

        this.midlet = midlet;

        maxX = getWidth();
	maxY = getHeight();

         //toca musica de fundo
           try {
               backPlayer = Manager.createPlayer(getClass().getResourceAsStream("/Demov5.mid"), "audio/mid");
                    
                  } catch (Exception e) {
                System.err.println(e+"erro construtor canvas musica");
                }

        try{
         
            iconeVida = Image.createImage("/vida.png");            
            iconeEnergia = Image.createImage("/energiaicon.png");
           
        }//try
        catch (java.io.IOException exception){
        System.err.println(exception+"erro construtor canvas 2");
        }

        //inicializa aviao do jogador
        aviao = new ClassePersonagem("/jato.png", 2, 1);

        aviao.contadorDano = 100;

        aviao.tipoFigura = 1;

        //Cria elemento energia
        energia = new ClassePersonagem ("/energia2.png", 1, 6);        

        //inicializa aviao do inimigo
        for (int i=0; i < inimigo.length; i++){

            if (i%2 == 0){

                inimigo [i] = new ClassePersonagem("/inimigo.png", 3, 1);
                inimigo [i].tipoFigura = 1;
            }
             else{

                inimigo [i] = new ClassePersonagem("/inimigolaranja.png", 3, 1);
                inimigo [i].tipoFigura = 2;

            }

        }//for inimigo

        //Inicializa  kamikase
         kamikase = new ClassePersonagem ("/kamikase.png");
         kamikase.tipoFigura = 2;

        for (int i=0; i < explosao.length; i++){

            explosao [i] = new ClassePersonagem("/explosao.png", 6, 1);

        }//for

        //inicializa tiro
        for (int i=0; i < bullet.length; i++){

            bullet [i] = new ClassePersonagem("/tiro.png");

        }//for

         //fiz uma mudança aki
         chefe = new ClassePersonagem("/chefe1.png", 3, 1);

        //inicializa tiro
        for (int i=0; i < bulletInimigo.length; i++){

            bulletInimigo [i] = new ClassePersonagem("/tiroinimigo.png");
            bulletInimigo [i].setEstado(false);

        }//for

        //inicializa cenario
        Cenario = new ClasseCenario ("/cenario.png", 10, 100, 32, 32);

        //inicializa elementos de fim e inicio do jogo
        gameOver = new ClassePersonagem ("/gameover.png", 1, 2);
        getReady = new ClassePersonagem ("/getready.png", 1, 2);

        //ajusta posição inicial da tela
        posYTela = Cenario.AltMapa() - maxY;    
         
        
 //------------------------------------------------------------------------------

        aviao.setPosX(maxX/2-aviao.LargSprite()/2);
        aviao.setPosY(posYTela + maxY);
        aviao.ajustaPosicao(aviao.posX, aviao.posY);
        layerManager.append(aviao.sprImagem);

        Cenario.criaMascara();
        
         //insere Cenario
        layerManager.append(Cenario.mapa);
        
       layerManager.setViewWindow(posYTela, Cenario.getPosY(),maxX, maxY);       

    }//construtor
   
//==============================================================================
    public void iniciaJogo ()
    {

          jogoIniciado = true;

          Thread t = new Thread (this);

          t.start ();

          this.setFullScreenMode(true); //Coloca a tela em modo fullScreen

           try {
                   if (backPlayer != null) {
                           backPlayer.start();
                           //numero de repetições
                           backPlayer.setLoopCount(2);
                                             }//if

                        } catch (Exception e) {
                              System.err.println(e+"erro inicia jogo");

                        }//catch
        

}
//==============================================================================
    public void pausaJogo ()
    {
        jogoIniciado = false;

    }//if

//==============================================================================
    public void monitorTeclas(){
        
		int teclas = getKeyStates();

		//Verifica se cada tecla foi pressionada
		if((teclas & LEFT_PRESSED)!=0){
			esquerda = true;
                        
            }//if
		else{
			esquerda = false;
        }//else
               

		if((teclas & RIGHT_PRESSED)!=0){
			direita = true;
                        
            }//if
		else {
                        direita = false;
                       
            }
 

		if((teclas & UP_PRESSED)!=0){
			cima = true;
                                           
                        
            }//if
		else{
			cima = false;
                        
            }

		if((teclas & DOWN_PRESSED)!=0){
			baixo = true;
                        
            }//if
		else{
			baixo = false;
            }
                


                if((teclas & FIRE_PRESSED)!=0){
			tiro = true;
                        
                }//if
		else{
			tiro = false;
                        
            }
		
}//monitorTeclas

//==============================================================================
    public void run (){

        int contadorGameOver = 0;
        int contadorWinner = 0;

                 while (jogoIniciado){

                      monitorPlacar();                    
//------------------------------------------------------------------------------
                     //Se o jogo ainda não hover começado
                     if (!jogoRodando){
                         jogoRodando = monitorInicio ();
                     }//if
//------------------------------------------------------------------------------
                    else if (aviao.getEstado()){

                         //apenas se o jogador estiver true

                        monitorTeclas();

                        monitorDeslocPrincipal (); 
                      
                        monitorDeslocInimigo();                      

 //------------------------------------------------------------------------------

                 //cuida do deslocamento do tiro e desaloca-lo
                     if ((tiroRodando)){

                         monitorTiroPrincipal();

                     }//if - tiroRodando
//------------------------------------------------------------------------------
                     if(explosaoRodando){

                         monitorExplosao();

                     }//if
//------------------------------------------------------------------------------
                        //analisa posição que o chefe aparece na tela
                        if (posYTela <= 6*maxY+maxY/2){

                            monitorChefe();
                            
                        }//if
                            //se o jogador não derrotar o chefe a tempo
                            //GameOver
                       if ((posYTela <= 0)&&(chefe.contadorDano > 0)){

                            monitorFim (false);

                            }//if
//------------------------------------------------------------------------------
                        //Se ocorrer game over
                       if(gameOver.getEstado()){

                             gameOver.sprImagem.nextFrame();
                             gameOver.ajustaPosicao(maxX/2 - gameOver.LargSprite()/2, posYTela+maxY/2);
                             contadorGameOver++;

                             if (contadorGameOver == 45){

                                 tiroRodando = false;                                 
                                
                                 midlet.exitMidlet();
                               
                             }//if
                             
                            }///if
//------------------------------------------------------------------------------
                        //Se o jogador vencer
                        if (sprWinner != null){                            
                            
                            contadorWinner++;

                            aviao.posY -= 10;
                            
                            
                            if (contadorWinner >= 45){
                                layerManager.remove(chefe.sprImagem);
                                chefe.estado = false;

                                //tiro = false;

                                if (aviao.posY <= posYTela - aviao.AltSprite()){
                                    midlet.exitMidlet();
                                }//if

                            }//if contadorWinner

                        }//if sprWinner != null
//------------------------------------------------------------------------------
                        //Realiza deslocamento vertical da tela
                        if (posYTela >= 0){

                            posYTela -= deslocamentoTela;

                          //Ajusta a tela com as novas coordenadas
                           layerManager.setViewWindow(Cenario.posX, posYTela, maxX, maxY);

                         }//if
                        else{



                           layerManager.setViewWindow(Cenario.posX, posYTela, maxX, maxY);

                        }//if
//------------------------------------------------------------------------------

                    }//else                    
                     
                     //Coloca o cenario e todos os elementos na tela
                     layerManager.paint(g, 0, 15);

                     //repinta a tela
                     flushGraphics ();
//------------------------------------------------------------------------------                    //pausa a thread
                     try {

                     Thread.sleep (60);
                     Runtime.getRuntime().freeMemory();
                     Runtime.getRuntime().gc() ;

                     }//try
                     catch (InterruptedException e) {
                      System.err.println(e+"erro run");
                     }

}//while

}//run

//==============================================================================
    public void monitorDeslocPrincipal (){

        int deslocamento = 10;
        
        novaPosY = aviao.getPosY();
             
        novaPosX = aviao.getPosX();

        //para o aviao não sair da tela
        if ((aviao.getPosY() >= (posYTela + maxY - aviao.AltSprite()))){
            novaPosY--;
        }//if 
        
                       
                        if(cima)
			{
                            if (novaPosY > posYTela){
                               novaPosY -= deslocamento;
                            }//if

			}//if

			if(baixo)
			{
                            if ((novaPosY + aviao.AltSprite()) < posYTela + maxY){
                                novaPosY += deslocamento;
                            }//if

			}//if


                         //se cima e baixo não forem pressionados, mantem a pos Y na tela
                         //assim não e preciso ficar subindo o aviao com o movimento do cenario
                        if ((!cima)&&(!baixo)){
                                 novaPosY -= deslocamentoTela;
                        }//if

			if(esquerda)
			{
				if (novaPosX > Cenario.getPosX()){
				novaPosX -= deslocamento;
                                                            }//if
                                
                                
			}//if

			if(direita)
			{
				if ((novaPosX + aviao.LargSprite()) < maxX){
				novaPosX += deslocamento;
                                  }//if

			}//if 
        
                       if((tiro)&&(contadorTiro < bullet.length)){

                           tiroRodando = true;
                           tiro = false;

                           int i = 0;

                           //Verifica se existe algum tiro disponivel
                           while ((bullet[i].getEstado())&&(i < contadorTiro)){

                               i++;

                           }//while

                           //Cria tiro principal
                           bullet[i].setPosX(aviao.getPosX() - (bullet[i].LargSprite()/2) + aviao.LargSprite()/2);
                           bullet[i].setPosY(aviao.getPosY());

                           bullet[i].ajustaPosicao(bullet[i].getPosX(), bullet[i].getPosY());

                           bullet[i].setEstado(true);
                           
                           layerManager.insert(bullet[i].sprImagem, 1);
                           contadorTiro++;


                        }//if

            if (contadorTiro == 0){
                                tiroRodando = false;
        }//if

        
        //Pega coordenadas do aviao

                              //Atualiza posição e frame do avião
                               aviao.setPosY(novaPosY);
                               aviao.setPosX(novaPosX);
                               aviao.ajustaPosicao(aviao.getPosX(), aviao.getPosY());                               
                               aviao.sprImagem.nextFrame();
                               
                               //layerManager.remove(sprJatoDano);
                               
                       
    }//monitorDeslocPrincipal

//==============================================================================
//Desloca aviao inimigo
   public void monitorDeslocInimigo(){

        if ((!chefe.estado)&&(sprWinner == null)){

            for (int i=0; i<inimigo.length;i++){

                 if (!inimigo[i].getEstado()){

                     if (posYTela >= maxY*7){

                  inimigo[i].posX = rand.nextInt(maxX-inimigo[i].LargSprite());
                  inimigo[i].posY = (posYTela - inimigo [i].AltSprite());

                  inimigo[i].ajustaPosicao(inimigo[i].posX, inimigo[i].posY);
                  inimigo[i].setEstado(true);

                  inimigo [i].contadorDano = 100;                //contadorInimigo++;
                  layerManager.insert(inimigo[i].sprImagem, 1);


                     }//if pos YTela

             }//if

             //Se o inimigo estiver true, gera deslocamento

             else if((inimigo[i].posY > (posYTela + maxY)))
             {
                 //aqui o inimigo saiu da tela, fica false

                 layerManager.remove(inimigo[i].sprImagem);
                 inimigo[i].setEstado(false);

             }//if

             else
             {

                      //se sair da tela pelo lado direito
          if ((inimigo [i].posX+inimigo [i].LargSprite()) >= (maxX)){

               deslocamentoInimigo = -7;

           }//if

           //se sair da tela pelo lado esquerdo
           if (inimigo [i].posX <= 0){

               deslocamentoInimigo = 7;

           }//if

              if (inimigo[i].tipoFigura == 1){
                  inimigo [i].posX += deslocamentoInimigo;
              }

                 //Desloca inimigo no eixo Y

                   inimigo[i].posY = (inimigo[i].posY+10);
                   inimigo[i].sprImagem.nextFrame();
                   inimigo[i].ajustaPosicao(inimigo[i].posX, inimigo[i].posY);

               }//else

              }//for k

            monitoTiroInimigo();
                       }//if ((!chefe.estado)&&(sprWinner == null)){
 
         
        
//------------------------------------------------------------------------------

       //Coloca kamikase na tela
       if ((!kamikase.estado)){

           if ((posYTela%30 == 0)){

           kamikase.estado = true;
           kamikase.posX = aviao.posX;
           kamikase.posY = posYTela - kamikase.AltSprite();
           kamikase.ajustaPosicao(kamikase.posX, kamikase.posY);
           layerManager.insert(kamikase.sprImagem, 1);
           kamikase.contadorDano = 100;

           }//if resto de 30

       }//if
       
       else if (kamikase.posY > posYTela + maxY){

           kamikase.estado = false;
           layerManager.remove(kamikase.sprImagem);
           
       }//else if

       else if(kamikase.sprImagem.collidesWith(aviao.sprImagem, true))
       {

           aviao.contadorDano -= 10;
           kamikase.estado = false;
           produzExplosao (kamikase.posX, kamikase.posY);
           layerManager.remove(kamikase.sprImagem);


       }//else if
         
       else{

           kamikase.posY += 10;

           //Assim o jogador pode desciar do kamikase
           if (kamikase.posY <= posYTela + maxY/2){
               
               kamikase.posX = aviao.posX;
           }
           
           kamikase.ajustaPosicao(kamikase.posX, kamikase.posY);
             
       }//else
//------------------------------------------------------------------------------
        //monitora tiro Inimigo
       
   }//monitorDeslocInimigo
//==============================================================================
   public void monitorChefe (){
       
        //Coloca chefe na tela
       if ((!chefe.estado)&&(sprWinner == null)){

           chefe.posX = rand.nextInt(maxX - chefe.LargSprite());
           chefe.posY = posYTela - chefe.AltSprite();
           chefe.ajustaPosicao(chefe.posX, chefe.posY);

           layerManager.insert(chefe.sprImagem, 1);
           chefe.contadorDano = 10000;
           chefe.estado = true;

           deslocamentoTela = 2;

           bulletInimigo [bulletInimigo.length-1] = null;
           bulletInimigo [bulletInimigo.length-1] = new ClassePersonagem ("/tirochefe.png");

           //desaloca kamikase e inimigo
          
          inimigo = null;
          energia = null;

                try {
               if (backPlayer != null) {

               backPlayer.stop();
                                    }//if

               backPlayer = null;

               backPlayer = Manager.createPlayer(getClass().getResourceAsStream("/musicachefe.mid"), "audio/mid");


               backPlayer.start();
               backPlayer.setLoopCount(2);

                  } catch (Exception e) {
                System.err.println(e+"erro construtor canvas musica");
                }//catch
       
          
       }//if

       else{
           //chefe.posX -= 5;
           //A|justar o movimento horizontal do chefe
           
           //se sair da tela pelo lado direito
          if ((chefe.posX+chefe.LargSprite()) >= (maxX)){

               deslocamentoInimigo = -5;

           }//if
          
           //se sair da tela pelo lado esquerdo
           if (chefe.posX <= 0){

               deslocamentoInimigo = 5;

           }//if

           chefe.posX += deslocamentoInimigo;
          
           if ((chefe.posY + chefe.AltSprite()) >= (posYTela + maxY/2)){

               chefe.posY -= deslocamentoTela;

           }//if

            monitorTiroChefe ();

       //se o chefe colider com o aviao. o jogador leva dano
       if (chefe.sprImagem.collidesWith(aviao.sprImagem, true)){

           aviao.contadorDano -= 5;
           produzExplosao (aviao.posX, aviao.posY);

       }//if

       chefe.sprImagem.nextFrame();
       chefe.ajustaPosicao(chefe.posX, chefe.posY);


//Se acabar a energia do chefe
       if (chefe.contadorDano <= 0){

           produzExplosao(chefe.getPosX()+chefe.LargSprite()/2, chefe.getPosY()+chefe.AltSprite()/2);

           tiro = false;

           deslocamentoInimigo = 0;

               //layerManager.remove(chefe.sprImagem);
           monitorFim (true);//o jogador venceu

       }//if contador dano
          
       }//else

   
   }//monitor chefe

//==============================================================================
public void monitorTiroChefe (){

     //int k;

    //Ajustar o tiro do chefe

     for (int k=0; k < bulletInimigo.length; k++){

           //Se tiro inimigo estiver true gera deslocamento
        if ((!bulletInimigo[k].getEstado())&&(sprWinner == null)){

                    bulletInimigo[k].setEstado(true);
                    bulletInimigo[k].setPosX(chefe.posX + (chefe.LargSprite()/2)-(bulletInimigo[k].LargSprite()/2));
                    bulletInimigo[k].setPosY(chefe.posY + bulletInimigo[k].AltSprite()/2);
                    bulletInimigo[k].ajustaPosicao(bulletInimigo[k].posX, bulletInimigo[k].posX + bulletInimigo[k].AltSprite());
                    layerManager.insert(bulletInimigo[k].sprImagem, 1);

                   }//if
        else{

            //tiro do chefe
            //ajusta posições do tiro do chefe
            bulletInimigo[0].setPosX(bulletInimigo[0].getPosX()-2);
            bulletInimigo[1].setPosX(bulletInimigo[1].getPosX());
            bulletInimigo[2].setPosX(bulletInimigo[2].getPosX()+2);
            
              bulletInimigo[k].setPosY(bulletInimigo[k].getPosY() + bulletInimigo[k].AltSprite());
              //bulletInimigo[k].setPosX(bulletInimigo[k].getPosX());
              bulletInimigo[k].ajustaPosicao(bulletInimigo[k].posX, bulletInimigo[k].posY);

                  //Se o tiro inimigo sair da tela, fica false.
                   if (bulletInimigo[k].posY > (posYTela + maxY)){

                              layerManager.remove(bulletInimigo[k].sprImagem);
                              bulletInimigo[k].setEstado(false);

                          }//if sai da tela

                  //Se o tiro inimigo colidir com o aviao
                   if ((bulletInimigo[k].sprImagem.collidesWith(aviao.sprImagem, true))){

                       bulletInimigo[k].estado = false;

                       layerManager.remove(bulletInimigo[k].sprImagem);

                       //se For o tiro grande
                       if (k == bulletInimigo.length-1){
                           aviao.contadorDano -= 25;
                       }//if
                     else{
                           aviao.contadorDano -= 10;
                         }//else
                       

                       produzExplosao(aviao.posX, aviao.posY);

                 }//if

        }//else  

             }//for k
    
}//monitorTiroChefe
//==============================================================================
   public void produzExplosao (int x, int y){

       if (contadorExplosao < explosao.length){
           int j = 0;

           while ((explosao[j].getEstado())&&(j < explosao.length)){
                           j++;
                                                }//while

                     explosao[j].posX = x;
                     explosao[j].posY = y;
                     explosao[j].ajustaPosicao(x, y);
                     explosao[j].setEstado(true);                     
                     explosao [j].sprImagem.nextFrame();
                     layerManager.insert(explosao[j].sprImagem, 1);
                     contadorExplosao++;
                     explosaoRodando = true;

       }//if
       
   }//produzExplosao

//==============================================================================
public void monitorExplosao (){

    for (int i=0; i<explosao.length; i++){

                  if (explosao[i].getEstado()){

                     if (explosao [i].sprImagem.getFrame() < 5){
                         
                                explosao[i].sprImagem.nextFrame();

                             }//if
                      else{
                          explosao[i].setEstado(false);
                          contadorExplosao--;
                          layerManager.remove(explosao[i].sprImagem);
                      }//else
                                            }//if

                         }//for

                    if (contadorExplosao == 0){
                         explosaoRodando = false;
                     }//if

}//monitorExplosao
      
//==============================================================================
//==============================================================================
public void monitorTiroPrincipal (){


    //Verifica colisão do tiro principal com inimigo
    for (int i=0; i<bullet.length; i++){

        if (bullet[i].getEstado()){
            
             bullet[i].posY = (bullet[i].getPosY()-5*bullet[i].AltSprite()/2);
             bullet[i].ajustaPosicao(bullet[i].posX, bullet[i].posY);        

         //Se o tiro sair da tela
         if ((bullet[i].posY + bullet[i].AltSprite() < posYTela)){

                                contadorTiro--;
                                bullet[i].setEstado(false);
                                layerManager.remove(bullet[i].sprImagem);

                            }//if

//------------------------------------------------------------------------------
             //Se o tiro acertar kamikase

            if ((kamikase.estado)&&(kamikase.sprImagem.collidesWith(bullet[i].sprImagem, true))){

            //kamikase.estado = (false);
            kamikase.contadorDano -= 50;

            layerManager.remove(bullet[i].sprImagem);
            bullet[i].setEstado(false);

            contadorTiro--;

            score += 20;

            if (kamikase.contadorDano <= 0){

                kamikase.estado = false;
                produzExplosao (kamikase.posX, kamikase.posY);
                layerManager.remove(kamikase.sprImagem);

            }//if


        }//if

//------------------------------------------------------------------------------
//Se o chefe estiver false, aumenta o procerssamento dod jog
        if ((!chefe.estado)&&(sprWinner == null)){

            //Verifica colisão do tiro com o avião inimigo
                  for (int k=0; k<inimigo.length; k++){

                     if ((bullet[i].getEstado())&&(inimigo[k].getEstado())){


                         if(bullet [i].sprImagem.collidesWith(inimigo[k].sprImagem, true)){
                                 contadorTiro--;                                

                                 //aumenta o score de acordo com o inimigo
                                 score += 10;

                                 inimigo [k].contadorDano -= 100;

                                 bullet[i].setEstado(false);
                                 
                                 layerManager.remove(bullet[i].sprImagem);

                           //se a energia do inimigo acaba, explode o inimigo
                            if (inimigo [k].contadorDano == 0){

                                 inimigo[k].setEstado(false);
                                 produzExplosao (inimigo[k].posX, inimigo[k].posY);
                                 layerManager.remove(inimigo[k].sprImagem);

                                 }//if

                                                                          }//if collides

                                                                     }//if 1
                                                              }//for k

        }//if chefe.estado

        else{//verifica se houve colisão do tiro do jogador com o chefe

            if (bullet[i].sprImagem.collidesWith(chefe.sprImagem, true)){

               chefe.contadorDano -= 50;
               produzExplosao (bullet[i].posX, bullet[i].posY);

               bullet[i].estado = false;
               contadorTiro--;

               score += 25;
               
               layerManager.remove(bullet[i].sprImagem);

           }//if

        }//else

              }//if bullet.estado

                                                         }//for i
       
//------------------------------------------------------------------------------

}//deslocaTiro

//==============================================================================
public void monitoTiroInimigo(){
    
    //insere tiro para inimigo

    for (int k=0; k < inimigo.length; k++){

           //Se tiro inimigo estiver true gera deslocamento
        if ((inimigo[k].getEstado())&&(!bulletInimigo[k].getEstado())){

                    bulletInimigo[k].setEstado(true);
                    bulletInimigo[k].setPosX(inimigo[k].getPosX()+(inimigo[k].LargSprite()/2)-(bulletInimigo[k].LargSprite()/2));
                    bulletInimigo[k].setPosY(inimigo[k].getPosY()+bulletInimigo[k].AltSprite());
                    bulletInimigo[k].ajustaPosicao(bulletInimigo[k].getPosX(), bulletInimigo[k].getPosY()+bulletInimigo[k].AltSprite());
                    layerManager.insert(bulletInimigo[k].sprImagem, 1);

                   }//if

               //   if (bulletInimigo[k].getEstado()){
                       
                       bulletInimigo[k].setPosY(bulletInimigo[k].getPosY() + 10);
                       bulletInimigo[k].ajustaPosicao(bulletInimigo[k].posX, bulletInimigo[k].posY);

                //  }//if

                  //Se o tiro inimigo sair da tela, fica false.
                   if (bulletInimigo[k].posY > (posYTela + maxY)){

                              layerManager.remove(bulletInimigo[k].sprImagem);
                              bulletInimigo[k].setEstado(false);

                          }//if sai da tela

                  //Se o tiro inimigo colidir com o aviao
                   if ((bulletInimigo[k].getEstado())&&(bulletInimigo[k].sprImagem.collidesWith(aviao.sprImagem, true))){

                       bulletInimigo[k].estado = false;

                       layerManager.remove(bulletInimigo[k].sprImagem);
                       
                       aviao.contadorDano -= 2;

                       produzExplosao(aviao.posX, aviao.posY);


                       //sprJatoDano.setPosition(aviao.posX, aviao.posY);
                       //layerManager.insert(sprJatoDano, 1);
                       
                 }//if

             }//for k
    
}//monitoTiroInimigo

//==============================================================================
//==============================================================================
public void monitorPlacar (){

    //desenha placar do jogo
    
    // Cria o buffer de texto
	    StringBuffer texto = new StringBuffer();

            //aviao.contadorDano = 100;

            texto.setLength(0);
	    texto.append(" " + aviao.contadorDano + "%  " + "Score: " + score);

            g.setColor(0, 0, 0);
            g.fillRect(0, 0, maxX, 15);
            g.setColor(255, 255, 255); 

            g.drawImage(iconeEnergia, 3, 3, Graphics.TOP | Graphics.LEFT);

            g.setFont(Font.getFont(Font.FACE_PROPORTIONAL, Font.STYLE_ITALIC, Font.SIZE_MEDIUM));


            g.drawString(texto.toString(), iconeEnergia.getWidth(), 0,Graphics.TOP | Graphics.LEFT);

            texto.setLength(0);

            texto.append(contadorVida);            
            
            g.drawImage(iconeVida, maxX - iconeVida.getWidth(), 0, Graphics.TOP | Graphics.LEFT);
            g.setFont(Font.getFont(Font.FACE_SYSTEM, Font.FONT_STATIC_TEXT, Font.SIZE_SMALL));
            g.drawString(texto.toString(), maxX - iconeVida.getWidth()/2-5, 0,Graphics.TOP | Graphics.LEFT);

            texto.setLength(0);

            texto = null;

         

            if ((!chefe.estado)&&(sprWinner == null)){
               monitorItens ();
            }
          
            if ((aviao.contadorDano <= 0)&&(aviao.estado)){
                
                contadorVida--;
                
                aviao.contadorDano = 100;
                
                if (contadorVida <= 0){
                    monitorFim (false);
                }//if

            }//if


}//MonitorPlacar

//------------------------------------------------------------------------------
public void monitorItens (){

    //Coloca energia na tela se o dano do aviao for multiplo de 20
        if (!energia.estado){

            if ((aviao.contadorDano%30 == 0)&&(aviao.contadorDano != 100)){

                energia.posX = (rand.nextInt(maxX-energia.LargSprite()));
                //energia.posX = (rand.nextInt());
                energia.posY = (posYTela-energia.LargSprite());
                energia.ajustaPosicao(energia.posX, energia.posY);
                layerManager.insert(energia.sprImagem, 1);
                energia.setEstado(true);

            }//if

                                       }//if energia estado

            //se o aviao colidir com a energia
            else if((energia.sprImagem.collidesWith(aviao.sprImagem, true)))
            {
                aviao.contadorDano+=10;
                energia.setEstado(false);
                layerManager.remove(energia.sprImagem);

            }//if                                                                           }//if

            //se a energia estiver false
            else if(energia.posY > posYTela + maxY)
           {

                energia.estado = false;
                layerManager.remove(energia.sprImagem);

                //layerManager.insert(energia.sprImagem, 1);

            }//if

        else{
                energia.sprImagem.nextFrame();
                energia.posY += 5;
                energia.ajustaPosicao(energia.posX, energia.posY);

        }//else


}//monitorItens
//------------------------------------------------------------------------------
public boolean monitorInicio (){

    cima = true;
    boolean retorno = false;
    aviao.setEstado(false);

    if (!getReady.estado){
        getReady.setPosX((maxX/2) - (getReady.LargSprite()/2));
        getReady.setPosY(Cenario.AltMapa() - maxY/2);
        getReady.ajustaPosicao(getReady.posX, getReady.posY);
        layerManager.insert(getReady.sprImagem, 1);
        getReady.estado = true;
    }//if

       layerManager.setViewWindow(Cenario.posX, posYTela, maxX, maxY);

        monitorDeslocPrincipal ();

        getReady.sprImagem.nextFrame();

        //Quando o aviao entrar na tela retorna true;
     if (aviao.getPosY() < Cenario.AltMapa()-maxY/2){
         retorno = true;
         aviao.setEstado(true);
         layerManager.remove(getReady.sprImagem);

         getReady = null;
     }//if

        cima = false;
        return retorno;        

}//monitorInicio
//==============================================================================
//monitora fim do jogo
public void monitorFim(boolean statusJog){    

    //se status é false, jogador morreu
if (!statusJog){

    produzExplosao(aviao.posX, aviao.posY);
    layerManager.remove(aviao.sprImagem);
    gameOver.estado = true;

    //gameOver = new ClassePersonagem ("/gameover.png", 1, 2);
    
    gameOver.ajustaPosicao(maxX/2 - gameOver.LargSprite()/2, posYTela+maxY/2);
    layerManager.insert(gameOver.sprImagem, 1);
    gameOver.sprImagem.nextFrame();   
           

}//if
// o erro ta aki ?:
//o jogador venceu
 else{

    if (sprWinner == null){
        try{

        winner = Image.createImage("/winner.png");
        sprWinner = new Sprite (winner, winner.getWidth(), winner.getHeight());

        sprWinner.setPosition(maxX/2 - sprWinner.getWidth()/2, posYTela+maxY/2 - sprWinner.getWidth()/2);
        layerManager.insert(sprWinner, 1);

    } catch (java.io.IOException exception){
        System.err.println(exception+"erro construtor winner ");
        }//catch

     winner = null;
    }//if
    else{
        sprWinner.setPosition(maxX/2 - sprWinner.getWidth()/2, posYTela+maxY/2);
    }//else

   
 }//else    
 
}//gameOver
//==============================================================================
}//segundaGuerra canvas
