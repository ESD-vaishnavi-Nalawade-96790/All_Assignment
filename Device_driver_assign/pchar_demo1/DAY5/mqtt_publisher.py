#import paho mqtt client
import paho.mqtt.client as mqtt
#create a client for publishing
publisher = mqtt.client(mqtt.CallbackAPIVERSION.VERSION2)

#connect with broker
publisher.connect(host='localhost')

#publish msg on topic
publisher.publish(topic = 'sensor/ldr',payload = '4094')

#disconnect from broker
publisher.disconnect