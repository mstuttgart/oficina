from flask import Flask

app = Flask(__name__)

# No final para evitar dependencia circular
from app import views
