/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

/**
 * @author Michell - ADM
 */
public class SuperAirForce extends MIDlet implements CommandListener {
    
        public SuperAirForceCanvas canvas;
        public Display display;

        Command exitCommand = new Command("Exit", Command.ITEM, 1);

        Command pauseCommand = new Command("Pause", Command.ITEM, 1);

        
	public SuperAirForce(){

		canvas = new SuperAirForceCanvas(this);
                display = Display.getDisplay(this);      

	}//construtor

	public void startApp()
        {                
                canvas.iniciaJogo();
                display.setCurrent(canvas);

                canvas.addCommand(pauseCommand);
		canvas.setCommandListener(this);              
	}

	public void pauseApp()
	{
                //canvas.setFullScreenMode(false);
		canvas.pausaJogo();
             
	}//pause

	public void destroyApp(boolean unconditional)
	{
		
                
	}

        protected void hideNotify() {

        canvas.pausaJogo();

        }
        public void exitMidlet (){
            destroyApp(false);
            notifyDestroyed();

        }

        public void commandAction(Command comando, Displayable s)
	{
		if ((comando == pauseCommand)&&(canvas.jogoIniciado))
		{
			//destroyApp(true);
			//notifyDestroyed( );
                        canvas.pausaJogo();
                    
		}//if

                else if((comando == exitCommand)){
                     destroyApp(true);
                     notifyDestroyed();
                    
                }//else if

                else{
                    canvas.iniciaJogo();
                }//else
	}//commandAction


        
}




