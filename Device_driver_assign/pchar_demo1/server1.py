#import flask class from module
form flask import Flask

#create a server using flask
server = Flask(__name__)

@server.get('/')
def homepage():
    return "this is a homepage"

@server.get('/welcome')
def welcome():
    return "this is a welcome page"    
#run the server
server.run()