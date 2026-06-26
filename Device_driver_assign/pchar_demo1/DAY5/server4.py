#import flask
from flask import Flask
#create server
server = Flask(__name__)

@server
def homepage():
    return "student management  system"