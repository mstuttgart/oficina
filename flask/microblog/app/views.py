from flask import render_template
from app import app

@app.route('/')
@app.route('/index.html')
def index():
    title = 'Testando microblog'
    user = {'nickname': 'Michell'}

    return render_template('index.html', title=title, user=user)
