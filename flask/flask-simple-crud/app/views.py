from flask import render_template, request, redirect

from app import app, models, db

@app.route('/')
def index():
    books = models.Book.query.all()
    return render_template('index.html', books=books)

@app.route('/add', methods=['GET', 'POST'])
def add_book():

    if request.method == 'POST':
        book = models.Book()
        book.title = request.form['title']
        db.session.add(book)
        db.session.commit()
        return redirect('/')
    else:
        return render_template('add-book.html')
