from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_script import Manager
from flask_migrate import Migrate, MigrateCommand
from flask_admin import Admin
from flask_admin.contrib.sqla import ModelView


UPLOAD_FOLDER = 'app/static/img'
ALLOWED_EXTENSIONS = set(['png', 'jpg', 'jpeg', 'gif'])

# Initialize Flask
app = Flask(__name__, instance_relative_config=True)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

# api secret_key to use CSRF.
app.secret_key = 'development key'

# Load config file
app.config.from_object('config')

# Initialize db
db = SQLAlchemy(app)

admin = Admin(app=app, name='crud teste', template_mode='bootstrap3')

migrate = Migrate(app, db)

manager = Manager(app)
manager.add_command('db', MigrateCommand)

# Import views and models
from app import views, models, forms

admin.add_view(ModelView(models.User, db.session))
admin.add_view(ModelView(models.Book, db.session))
admin.add_view(ModelView(models.Author, db.session))

db.create_all()
