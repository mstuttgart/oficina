from app import db


class User(db.Model):

    __tablemame__ = 'users'

    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64))


class Book(db.Model):
    """
    Create a comic collection table
    """
    __tablename__ = 'books'

    id = db.Column('id', db.Integer, primary_key=True)
    author_id = db.Column('author_id', db.Integer, db.ForeignKey('authors.id'))
    title = db.Column('title', db.String(60), unique=True)
    year = db.Column('year', db.Integer)
    description = db.Column(db.Text)
    cover_path = db.Column(db.String)

    author = db.relationship('Author', foreign_keys=author_id)

    def __repr__(self):
        return '<Book {}>'.format(self.title)


class Author(db.Model):
    """
    Create a author table
    """
    __tablename__ = 'authors'

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String)
    # books = db.relationship('Book', backref='author', lazy='dynamic')

    def __repr__(self):
        return '<Author {}>'.format(self.name)
