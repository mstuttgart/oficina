from flask import Flask

app = Flask(__name__)
app.config.from_object('config')

# No final para evitar dependencia circular
from app import views
