import paho.mqtt.client as paho
import time
import random


ACCESS_TOKEN = 'prNJeUaKti8I1cJw3ahK'
broker = "127.0.0.1"
port = 1883
topic = "v1/devices/me/telemetry"


def on_connect(client, userdata, flags, rc):
    if rc == 4:
        print("Connection Refused, bad user name or password - Username is empty.")
    elif rc == 5:
        print(
            "Connection Refused, not authorized - Username contains invalid $ACCESS_TOKEN.")
    else:
        print("Connected with success. Result code:", str(rc))


def on_message(client, userdata, msg):
    print("Message: " + msg.topic, " ", str(msg.payload))


def on_publish(client, userdata, result):
    print("data published \n" + str(result))
    pass


client1 = paho.Client()
client1.username_pw_set(ACCESS_TOKEN)
client1.on_publish = on_publish
client1.on_connect = on_connect
client1.on_message = on_message
client1.subscribe(topic)
client1.connect(broker, port, keepalive=60)
client1.loop_start()


while True:

    payload = "{"
    payload += f"\"Humidity\":{random.random()*100},"
    payload += f"\"Temperature\":{20. + random.random()*10}"
    payload += "}"
    ret = client1.publish(topic, payload, qos=1)
    print("Please check LATEST TELEMETRY field of your device")
    print(ret)
    time.sleep(5)
