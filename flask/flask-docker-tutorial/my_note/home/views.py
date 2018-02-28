from flask import render_template
from flask_login import login_required

from . import home

@home.route('/')
def index():
    """Rota para a nossa pagna Home"""
    return render_template('home/index.html')

@home.route('/about/')
def about():
    """Rota para a nossa pagna Home"""
    return render_template('home/about.html')
