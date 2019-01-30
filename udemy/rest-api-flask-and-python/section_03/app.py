from flask import Flask, jsonify, request


app = Flask(__name__)

stores = [
    {
        'name': 'My Wonderful Store',
        'items': [
            {
                'name': 'My Item',
                'price': 15.99,
            },
        ],
    },
]


# POST /store data: {name:}
@app.route('/store', methods=['POST'])
def create_store():

    # Retorna dict a partir do json
    request_data = request.get_json()

    # Criamos nova loja
    new_store = {
        'name': request_data['name'],
        'items': [],
    }

    # Armazenamos a nova loja
    stores.append(new_store)

    # Convertemos em json para poder
    # retornar
    return jsonify(new_store)

# GET /store/<string:name>
@app.route('/store/<string:name>')  # http://127.0.0.1:5000/store/some_name
def get_store(name):

    for store in stores:
        if store['name'] == name:
            return jsonify(store)

    return jsonify({'message': 'Store not found'})

# GET /store
@app.route('/store')
def get_stores():
    return jsonify({'stores': stores})

# POST /store/<string:name>/item
@app.route('/store/<string:store_name>/item', methods=['POST'])
def create_item_in_store(store_name):

    request_data = request.get_json()

    for store in stores:

        if store['name'] == store_name:

            new_item = {
                'name': request_data['name'],
                'price': request_data['price'],
            }

            store['items'].append(new_item)

            return jsonify(new_item)

    return jsonify({'message': 'Store not found'})


# GET /store/<string:name>/item/<string:name>
@app.route('/store/<string:store_name>/item')
def get_item_in_store(store_name):

    for store in stores:
        if store['name'] == store_name:
            return jsonify({'items': store['items']})

    return jsonify({'message': 'Store not found'})


app.run(debug=True, port=5000)
