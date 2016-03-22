package android_mini_projects.mstuttgart.github.com.br.listacompras;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView listaProdutos = (ListView) findViewById(R.id.listaProdutos);
        List<String> opcoes = new ArrayList<String>();

        opcoes.add("Alimentos");
        opcoes.add("Produtos de limpeza");

        ArrayAdapter<String> adaptador = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_list_item_1, opcoes);
        listaProdutos.setAdapter(adaptador);

        listaProdutos.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                Intent intent = null;
                switch (position){
                    case 0:
                        intent = new Intent(MainActivity.this, AlimentoActivity.class);
                        break;
                    case 1:
                        intent = new Intent(MainActivity.this, ProdutoActivity.class);
                        break;
                    default:
                        finish();
                        break;
                }

                if(intent != null)
                    startActivityForResult(intent, 0);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        if (requestCode == 0 && resultCode == Activity.RESULT_OK) {
            AlertDialog.Builder dialogo = new AlertDialog.Builder(MainActivity.this);
            dialogo.setTitle("Lista de Compras");
            dialogo.setMessage("Alimentos" +
                    "\nTomate: " + data.getBooleanExtra("Tomate", false) +
                    "\nMiojo: " + data.getBooleanExtra("Miojo", false) +
                    "\nProdutos: " +
                    "\nDetergente: " + data.getBooleanExtra("Detergente", false) +
                    "\nSabonente: " + data.getBooleanExtra("Sabonente", false)
            );
            dialogo.setNeutralButton("OK", null);
            dialogo.show();
        }
        super.onActivityResult(requestCode, resultCode, data);
    }
}
