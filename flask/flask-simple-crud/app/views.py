from flask import render_template, request, redirect, flash

from app import app, models, forms, db

@app.route('/')
def index():
    books = models.Book.query.all()
    return render_template('index.html', books=books)

@app.route('/add-book', methods=['GET', 'POST'])
def add_book():
    form = forms.BookForm()

    if request.method == 'POST':
        if form.validate():
            book = models.Book()
            book.title = request.form['title']
            book.year = request.form['year']
            book.description = request.form['description']
            db.session.add(book)
            db.session.commit()
            return redirect('/')
        else:
            flash('Title field is required', 'error')
            return render_template('book.html', form=form, add_book=True)
    else:
        return render_template('book.html', form=form, add_book=True)

@app.route('/edit/book/<int:book_id>', methods=['GET', 'POST'])
def edit_book(book_id):
    book = models.Book.query.get_or_404(book_id)
    form = forms.BookForm(request.form)

    if form.validate_on_submit():
        book.title = form.title.data
        book.year = form.year.data
        book.description = form.description.data
        db.session.commit()
        flash('You have successfully edited the book.')
        return redirect('/')
    else:
        form.title.data = book.title
        form.year.data = book.year
        form.description.data = book.description
        return render_template('book.html', form=form, add_book=False)
