# my_note/auth/__init__.py

from flask import Blueprint

# Instanciamos o Blueprint de auth

auth = Blueprint('auth', __name__)

from . import views
