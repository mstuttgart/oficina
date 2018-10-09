# my_note/admin/__init__.py

from flask import Blueprint

# Instanciamos o Blueprint de admin
admin = Blueprint('admin', __name__)

from . import views
