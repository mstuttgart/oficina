from flask import render_template, request, redirect

from app import app, models, db

@app.route('/')
def index():
    books = models.Book.query.all()
    return render_template('index.html', books=books)

@app.route('/add-book', methods=['GET', 'POST'])
def add_book():
    if request.method == 'POST':
        book = models.Book()
        book.title = request.form['title']
        book.year = request.form['year']
        book.description = request.form['description']
        db.session.add(book)
        db.session.commit()
        return redirect('/')
    else:
        return render_template('add-book.html')

@app.route('/<int:book_id>', methods=['GET', 'POST'])
def update_book(book_id):
    book = models.Book.get(book_id)

    if request.method == 'POST':
        book.title = request.form['title']
        book.year = request.form['year']
        book.description = request.form['description']
        db.session.commit()
        return redirect('/')
    else:
        return render_template('update-book.html')
