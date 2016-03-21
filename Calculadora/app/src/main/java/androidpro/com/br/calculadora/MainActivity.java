package androidpro.com.br.calculadora;

import android.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final EditText ednumero1 = (EditText) findViewById(R.id.ednumero1);
        final EditText ednumero2 = (EditText) findViewById(R.id.ednumero2);
        Button bSomar = (Button) findViewById(R.id.bSomar);
        Button bSubtrair = (Button) findViewById(R.id.bSubtrair);
        Button bMultiplicar = (Button) findViewById(R.id.bMultiplicar);
        Button bDividir = (Button) findViewById(R.id.bDividir);

        bSomar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                double n1 = Double.parseDouble(ednumero1.getText().toString());
                double n2 = Double.parseDouble(ednumero2.getText().toString());
                double soma = n1 + n2;

                AlertDialog.Builder dialogo = new AlertDialog.Builder(MainActivity.this);
                dialogo.setTitle("Resultado da Soma");
                dialogo.setMessage("A soma é: " + soma);
                dialogo.setNeutralButton("OK", null);
                dialogo.show();
            }
        });

        bSubtrair.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                double n1 = Double.parseDouble(ednumero1.getText().toString());
                double n2 = Double.parseDouble(ednumero2.getText().toString());
                double sub = n1 - n2;

                AlertDialog.Builder dialogo = new AlertDialog.Builder(MainActivity.this);
                dialogo.setTitle("Resultado da Subtração");
                dialogo.setMessage("A subtração é: " + sub);
                dialogo.setNeutralButton("OK", null);
                dialogo.show();
            }
        });

        bMultiplicar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                double n1 = Double.parseDouble(ednumero1.getText().toString());
                double n2 = Double.parseDouble(ednumero2.getText().toString());
                double mul = n1 * n2;

                AlertDialog.Builder dialogo = new AlertDialog.Builder(MainActivity.this);
                dialogo.setTitle("Resultado da Multiplicação");
                dialogo.setMessage("A multiplicação é: " + mul);
                dialogo.setNeutralButton("OK", null);
                dialogo.show();
            }
        });

        bDividir.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                double n1 = Double.parseDouble(ednumero1.getText().toString());
                double n2 = Double.parseDouble(ednumero2.getText().toString());
                double div = n1 / n2;

                AlertDialog.Builder dialogo = new AlertDialog.Builder(MainActivity.this);
                dialogo.setTitle("Resultado da Multiplicação");
                dialogo.setMessage("A multiplicação é: " + div);
                dialogo.setNeutralButton("OK", null);
                dialogo.show();
            }
        });
    }
}
