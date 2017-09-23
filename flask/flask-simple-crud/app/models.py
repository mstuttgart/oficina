from app import db


class Book(db.Model):
    """
    Create a comic collection table
    """
    __tablename__ = "books"

    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(60), unique=True)
    year = db.Column(db.Integer)
    description = db.Column(db.Text)

    def __repr__(self):
        return '<Book %r>' % (self.title)
