# my_note/home/__init__.py

from flask import Blueprint

# Instanciamos o Blueprint de home
home = Blueprint('home', __name__)

from . import views
