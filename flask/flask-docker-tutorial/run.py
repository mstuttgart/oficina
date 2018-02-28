# run.py
import os

from my_note import create_app
    
# Retorna o nome do ambiente que iremos 
# utilizar (Testing, Development ou Production)
environment_name = 'development'

# Criamos a aplicacao
app = create_app(environment_name)

if __name__ == '__main__':
    app.run()
