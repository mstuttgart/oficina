from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_script import Manager
from flask_migrate import Migrate, MigrateCommand

# Initialize Flask
app = Flask(__name__, instance_relative_config=True)

# api secret_key to use CSRF.
app.secret_key = 'development key'

# Load config file
app.config.from_object('config')

# Initialize db
db = SQLAlchemy(app)

migrate = Migrate(app, db)

manager = Manager(app)
manager.add_command('db', MigrateCommand)

# Import views and models
from app import views, models, forms

db.create_all()
