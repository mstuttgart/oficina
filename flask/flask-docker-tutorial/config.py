import os


class BaseConfig(object):
    """Classe Base para a configuracao da aplicacao"""
    DEBUG = False
    TESTING = False


class DevelopmentConfig(BaseConfig):
    """Configuracao utilizada para desenvolvimento"""
    DEBUG = True
    TESTING = True
    basedir = os.path.abspath(os.path.dirname(__file__))

    SQLALCHEMY_DATABASE_URI = 'sqlite:///' + os.path.join(basedir, 'my_note.db')
    SQLALCHEMY_MIGRATE_REPO = os.path.join(basedir, 'db_repository')
    SQLALCHEMY_TRACK_MODIFICATIONS = False


class TestingConfig(BaseConfig):
    """Configuracao utilizada para execucao de testes"""
    DEBUG = False
    TESTING = True
    SQLALCHEMY_TRACK_MODIFICATIONS = True


class ProductionConfig(BaseConfig):
    """Configuracao utilizada para desenvolvimento"""
    DEBUG = False
    TESTING = False


app_environments = {
    'development': DevelopmentConfig,
    'testing': TestingConfig,
    'production': ProductionConfig,
}