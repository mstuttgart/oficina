package flashlight.android_mini_projects.mstuttgart.github.com.br.androidflashlight;

import android.Manifest;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.hardware.Camera;
import android.hardware.Camera.Parameters;
import android.media.MediaPlayer;
import android.os.Build;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageButton;


public class MainActivity extends AppCompatActivity {

    ImageButton btnSwitch;

    private Camera camera;
    private boolean isFlashOn = false;
    Parameters params;
    MediaPlayer mp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnSwitch = (ImageButton) findViewById(R.id.btnSwitch);

        boolean hasFlash = getApplicationContext().getPackageManager().hasSystemFeature(
                PackageManager.FEATURE_CAMERA_FLASH);

        if (!hasFlash) {
            AlertDialog.Builder alert = new AlertDialog.Builder(MainActivity.this);
            alert.setTitle("Erro");
            alert.setMessage("Desculpe, seu dispositivo não possui flash!");
            alert.setNeutralButton("OK", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    finish();
                }
            });
        }

        if(isAndroid6()){
            solicitaPermissao();
        }

        btnSwitch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (isFlashOn) {
                    setFlashOff();
                } else {
                    setFlashOn();
                }
            }
        });
    }

    public boolean solicitaPermissao() {

        // Here, thisActivity is the current activity
        if (ContextCompat.checkSelfPermission(this,  Manifest.permission.CAMERA)
                != PackageManager.PERMISSION_GRANTED) {

            ActivityCompat.requestPermissions(this,  new String[]{Manifest.permission.CAMERA}, 200);
        }

        return true;
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case 200: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

                    // permission was granted, yay! Do the
                    // contacts-related task you need to do.

                } else {

                    // permission denied, boo! Disable the
                    // functionality that depends on this permission.
                }
                return;
            }

            // other 'case' lines to check for other
            // permissions this app might request
        }
    }

    private boolean isAndroid6(){
        return(Build.VERSION.SDK_INT > Build.VERSION_CODES.LOLLIPOP_MR1);
    }

    @Override
    protected void onResume() {
        super.onResume();
        try{
            // Abre a comunicação com a Camera
            camera = Camera.open();
            params = camera.getParameters();
        } catch (RuntimeException e) {
            Log.e("Camera Error. : ", e.getMessage());
        }
    }

    @Override
    protected void onPause() {
        if( camera != null ){
            // Libera o uso da Camera
            camera.release();
            camera = null;
            params = null;
        }
        super.onPause();
    }

    public void setFlashOff(){
        params = camera.getParameters();
        params.setFlashMode(Parameters.FLASH_MODE_OFF);
        camera.setParameters(params);
        isFlashOn = false;
        toggleButtonImage();

    }

    public void setFlashOn(){
        params = camera.getParameters();
        params.setFlashMode(Parameters.FLASH_MODE_TORCH);
        camera.setParameters(params);
        isFlashOn = true;
        toggleButtonImage();
    }

    private void toggleButtonImage(){
        if(isFlashOn){
            btnSwitch.setImageResource(R.drawable.btn_switch_on);
        }else{
            btnSwitch.setImageResource(R.drawable.btn_switch_off);
        }
    }

}
