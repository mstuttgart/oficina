from my_note import db


class User(db.Model):
    """ Create a User table """

    __tablemame__ = 'users'

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(60), index=True, unique=True)
    email = db.Column(db.String(60), index=True, unique=True)
    username = db.Column(db.String(64), index=True, unique=True)
    password_hash = db.Column(db.String(128))
    is_admin = db.Column(db.Boolean, default=False)


class Note(db.Model):
    """Create Note table
    """

    __tablename__ = 'notes'

    id = db.Column(db.Integer, primary_key=True)
    title = db.column(db.String(60), index=True, unique=True)
    # description = db.Column(db.)

