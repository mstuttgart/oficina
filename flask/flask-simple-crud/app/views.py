from flask import render_template, redirect, flash, url_for, request, send_from_directory
from werkzeug.utils import secure_filename
import os

from app import app, models, forms, db

MEDIA_FOLDER = 'app/static/'


@app.route('/')
def index():
    books = models.Book.query.all()
    return render_template('index.html', books=books)


@app.route('/add/book', methods=['GET', 'POST'])
def add_book():
    form = forms.BookForm()

    if form.validate_on_submit():

        cover = form.cover.data
        filename = secure_filename(cover.filename)
        path = os.path.abspath(MEDIA_FOLDER)
        path = os.path.join(path, filename)
        cover.save(path)

        book = models.Book()
        book.title = form.title.data
        book.author = form.author.data
        book.year = form.year.data
        book.description = form.description.data
        book.cover_path = filename

        if not form.validate():
            flash('Title field is required', 'error')
            return render_template('book.html', form=form, add_book=True)

        try:
            db.session.add(book)
            db.session.commit()
            flash('You have successfully added a new book.')
        except:
            # in case book name already exists
            flash('Error: Book name already exists.')

        return redirect(url_for('index'))

    else:
        return render_template('book.html', form=form, add_book=True)


@app.route('/edit/book/<int:book_id>', methods=['GET', 'POST'])
def edit_book(book_id):
    book = models.Book.query.get_or_404(book_id)
    form = forms.BookForm(obj=book)

    if form.validate_on_submit():

        if form.cover.data.filename:
            cover = form.cover.data
            filename = secure_filename(cover.filename)
            path = os.path.abspath(MEDIA_FOLDER)
            path = os.path.join(path, filename)
            cover.save(path)
            book.cover_path = filename

        book.title = form.title.data
        book.author = form.author.data
        book.year = form.year.data
        book.description = form.description.data

        try:
            db.session.commit()
            flash('You have successfully edited the book.')
        except:
            # in case book name already exists
            flash('Error: Book name already exists.')

        return redirect(url_for('index'))

    else:
        return render_template('book.html', form=form, add_book=False)


@app.route('/delete/book/<int:book_id>', methods=['GET', 'POST'])
def delete_book(book_id):
    book = models.Book.query.get_or_404(book_id)
    db.session.delete(book)
    db.session.commit()
    flash('You have successfully deleted the book.')
    return redirect(url_for('index'))


@app.route('/img/<path:filename>')
def download_file(filename):
    return send_from_directory(MEDIA_FOLDER, filename)


@app.route('/add/author', methods=['GET', 'POST'])
def add_author():

    form = forms.AuthorForm()

    if form.validate_on_submit():

        author = models.Author()
        author.name = form.name.data
        db.session.add(author)
        db.session.commit()

        if not form.validate():
            flash('Name field is required', 'error')
            return render_template('author.html', form=form, add_author=True)

        try:
            db.session.add(author)
            db.session.commit()
            flash('You have successfully added a new author.')
        except:
            # in case author name already exists
            flash('Error: Author name already exists.')

        return redirect(url_for('index'))
    else:
        return render_template('author.html', form=form, add_author=True)


