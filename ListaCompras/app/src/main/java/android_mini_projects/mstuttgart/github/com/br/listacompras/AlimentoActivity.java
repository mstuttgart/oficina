package android_mini_projects.mstuttgart.github.com.br.listacompras;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;

public class AlimentoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_alimento);

        final CheckBox checkTomate = (CheckBox) findViewById(R.id.checkTomate);
        final CheckBox checkMiojo = (CheckBox) findViewById(R.id.checkMiojo);

        Button bEnviar = (Button) findViewById(R.id.bEnviar);
        Button bCancelar = (Button) findViewById(R.id.bCancelar);

        bEnviar.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent resultado = new Intent();
                resultado.putExtra("Tomate", checkTomate.isChecked());
                resultado.putExtra("Miojo", checkMiojo.isChecked());
                setResult(Activity.RESULT_OK, resultado);
                finish();
            }
        });

        bCancelar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setResult(Activity.RESULT_CANCELED);
                finish();
            }
        });
    }
}
