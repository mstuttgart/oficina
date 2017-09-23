# -*- coding: utf-8 -*-
from flask import Flask, render_template, request, redirect, url_for, flash
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///app.sqlite'

db = SQLAlchemy(app)


class Book(db.Model):
    """
    Create a comic collection table
    """

    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(60))
    year = db.Column(db.Integer)
    # author_id = db.relationship(db.Integer, db.ForeignKey('authors.id'))
    description = db.Column(db.Text)

    def __init__(self, title, description):
        self.title = title
        self.description = description


# class Author(db.Model):
#     """
#     Create a comic author table
#     """
#
#     id = db.Column(db.Integer, primary_key=True)
#     name = db.Column(db.String(60), unique=True)
#     comic_collections = db.relationship('Comic Collections',
#                                         backref='author_id',
#                                         lazy='dynamic')

@app.route('/')
def index():
    books = Book.query.all()
    return render_template('index.html', books=books)


@app.route('/add', methods=['GET', 'POST'])
def add_book():

    if request.method == 'GET':
        return render_template('add_book.html')
    else:
        title = request.form['title']
        description = request.form['description']

        # if not title or not description:
        #     flash('Please enter all the fields!', 'error')

        comic = Book(title=title, description=description)

        db.session.add(comic)
        db.session.commit()
        # flash('Record was successfully added')
        return redirect(url_for('index'))


if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)
