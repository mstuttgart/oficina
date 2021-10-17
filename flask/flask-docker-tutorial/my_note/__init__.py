# my_note/__init__.py

from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

# Importamos as configuracaoes
from config import app_environments

from .admin import admin as admin_blueprint
from .auth import auth as auth_blueprint
from .home import home as home_blueprint

# Instanciamos o banco de dados
db = SQLAlchemy()

# Criamos a nossa aplicacao app aqui
def create_app(environment):

    # Instanciamos nossa aplicacao Flask
    app = Flask(__name__, instance_relative_config=True)
    
    # Finalmente, como nossa configuracoa esta separada em classes,
    # definimos que nossa configuracao deve carregar objetos 
    # dessas classes
    app.config.from_object(app_environments[environment])

    # Aqui definimos o arquivo de configuracao
    app.config.from_pyfile('config.py')

    # Registramos a aplicacao no SQLAlchemy
    db.init_app(app)

    # Registramos cada um dos blueprints
    app.register_blueprint(admin_blueprint, url_prefix='/admin/')
    app.register_blueprint(auth_blueprint)
    app.register_blueprint(home_blueprint)

    migrate = Migrate(app, db)

    from my_note import models
    
    return app
