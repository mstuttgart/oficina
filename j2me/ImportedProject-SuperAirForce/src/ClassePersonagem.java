/*
 Classe responsavel por in icializar os parametros de cada personagem
 */
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;
/**
 *
 * @author Michell - ADM  - super air force
 */
public final class ClassePersonagem{
    
    //Atributos da classe
    protected Image imagem;
    protected int posX, posY;
    protected int contadorDano;
    protected Sprite sprImagem;
    protected boolean estado;
    public int tipoFigura;

//==============================================================================
    public ClassePersonagem (String str){

        
        estado = false;
        tipoFigura = 1;
        contadorDano = 100;

        try
        {
            imagem = Image.createImage(str);
            sprImagem = new Sprite (imagem);
            imagem = null;

        }//try
        catch(java.io.IOException exception){
        System.err.println(exception+"erro construtor:"+str);
        }


    }//construtor

//==============================================================================
    public ClassePersonagem (String str, int quantFrameHor,int quantFrameVert)
    {

        contadorDano = 100;
        estado = false;      
        tipoFigura = 1;
        
        try
        {
            imagem = Image.createImage(str);
            sprImagem = new Sprite (imagem, imagem.getWidth()/quantFrameHor, imagem.getHeight()/quantFrameVert);
            imagem = null;
               
            inicializaSeq();           

        }//try
        catch(java.io.IOException e){
            System.err.println(e+"erro construtor:"+str);
        }

        posX = 0;
        posY = 0;

    
    }//construtor
//==============================================================================
    //Inicializa sequncia de frames
    public void inicializaSeq (){

        int [] sequencia = new int [sprImagem.getRawFrameCount()];

        for (int i=0; i<sequencia.length; i++){
            sequencia [i] = i;
        }//for

        sprImagem.setFrameSequence(sequencia);

    }//inicializaSeq

   //==============================================================================
   public boolean getEstado (){
       return estado;
   }
  //==============================================================================
   public void setEstado (boolean status){
       estado = status;
   }

//==============================================================================

 //==============================================================================
   public int getPosX (){
       return posX;
   }
//==============================================================================
    public int getPosY (){
       return posY;
   }
//==============================================================================
     public int LargSprite (){
       return sprImagem.getWidth();
   }
//==============================================================================
     public int AltSprite (){
       return sprImagem.getHeight();
   }
//==============================================================================
     public void setPosX (int x){

         posX = x;
       
   }
//==============================================================================
     public void setPosY (int y){

         posY = y;

   }
//==============================================================================
     public void ajustaPosicao (int x, int y){

         sprImagem.setPosition(x, y);

   }
 //==============================================================================
     public void configFrame (int indice){

         sprImagem.setFrame(indice);

   }
//==============================================================================

}//ClassePersonagem
