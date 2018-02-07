# run.py 

from flask import Flask

# Instanciamos nossa aplicacao Flask
app = Flask(__name__)

# Definimos uma rota para a url '/'
@app.route('/')
def hello_world():
    return 'Hello World!'


if __name__ == '__main__':
    app.run(debug=True)