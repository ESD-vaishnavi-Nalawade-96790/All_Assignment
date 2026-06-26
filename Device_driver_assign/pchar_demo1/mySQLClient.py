# import mysql connector
import mysql.connector

# create connection with mysql server
connection = mysql.connector.connect(
    host='127.0.0.1',
    port=3306,
    database='iotfeb26',
    user='root',
    password='Vaish@123'
)

def get_student():
    # create a query
    query = "select * from studinfo;"
    # create a cursor to execute query
    cursor = connection.cursor()
    # execute and pass the cursor from mysql
    cursor.execute(query) 
    # get data/result from cursor
    data = cursor.fetchall()  
    # print data
    print(data)
    # close the cursor
    cursor.close()

def insert_student(rollno, name, course, marks):
    # create a query
    query = f"insert into studinfo values({rollno},'{name}','{course}',{marks});"
    # create a cursor to execute query
    cursor = connection.cursor()
    # excute or pass query to the mysql server
    cursor.execute(query)
    # commit your changes to database server
    connection.commit()
    # close the cursor
    cursor.close()

def update_student(rollno, marks):
    # create a query
    query = f"update studinfo set marks={marks} where rollno={rollno};"
    # create a cursor to execute query
    cursor = connection.cursor()
    # execute or pass query to the mysql server
    cursor.execute(query)
    # commit your changes to database server
    connection.commit()
    # close the cursor
    cursor.close()

def delete_student(rollno):
    # create a query
    query = f"delete from studinfo where rollno={rollno};"
    # create a cursor to execute query
    cursor = connection.cursor()
    # execute or pass query to the mysql server
    cursor.execute(query)
    # commit your changes to database server
    connection.commit()
    # close the cursor
    cursor.close()

# Execute functions
insert_student(56, "siddhesh", "esd", 119)
#update_student(11, 98.1)
#delete_student(25)
get_student()

# close the connection
connection.close()
