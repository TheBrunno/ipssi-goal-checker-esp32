from flask import Flask, render_template, request, jsonify
from flask_socketio import SocketIO

app = Flask(__name__, static_url_path="/static")
socketio = SocketIO(app)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/recebedor', methods=['POST'])
def recebedor():
    if request.method == 'POST':
        data = request.form
        status = data.get('status')
        if status:
            print("gol")
            socketio.emit('update_distance')
            return jsonify({"status": "sucesso"})
        else:
            return jsonify({"status": "erro", "mensagem": "Dados inválidos recebidos"}), 400


if __name__ == '__main__':
    socketio.run(app, host='0.0.0.0', port=5000, allow_unsafe_werkzeug=True)