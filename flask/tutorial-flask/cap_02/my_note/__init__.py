from flask import Flask

# Inicializando o app
app = Flask(__name__)


# Carregamos a views aqui para evitar import circular
from my_note import views
