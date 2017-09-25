from app import db


class Book(db.Model):
    """
    Create a comic collection table
    """
    __tablename__ = 'books'

    id = db.Column(db.Integer, primary_key=True)
    author_id = db.Column(db.Integer, db.ForeignKey('authors.id'))
    title = db.Column(db.String(60), unique=True)
    year = db.Column(db.Integer)
    description = db.Column(db.Text)

    def __repr__(self):
        return '<Book {}>'.format(self.title)

class Author(db.Model):
    """
    Create a author table
    """
    __tablename__ = 'authors'

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String)
    books = db.relationship('Book', backref='author', lazy='dynamic')

    def __repr__(self):
        return '<Author {}>'.format(self.name)
