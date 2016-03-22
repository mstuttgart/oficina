package android_mini_projects.mstuttgart.github.com.br.listacompras;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;

public class ProdutoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_produto);

        final CheckBox checkDetergente = (CheckBox) findViewById(R.id.checkDetergente);
        final CheckBox checkSabonete = (CheckBox) findViewById(R.id.checkSabonete);

        Button bEnviar = (Button) findViewById(R.id.bEnviar);
        Button bCancelar = (Button) findViewById(R.id.bCancelar);

        bEnviar.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                Intent resultado = new Intent();
                resultado.putExtra("Detergente", checkDetergente.isChecked());
                resultado.putExtra("Sabonete", checkSabonete.isChecked());
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
