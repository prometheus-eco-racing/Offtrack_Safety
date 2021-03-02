from influxdb import InfluxDBClient
import time
import serial
c = 1
time.sleep(5)
ar = serial.Serial('COM3',9600,timeout=1)
client = InfluxDBClient(host='localhost', port=8086)
client.create_database('pydb')
client.switch_database('pydb')
T = 5
while(T):
    ar.readline()[:-2]
    T-=1
while 1:
    data = ar.readline()[:-2]
    if(data.decode('utf-8') == 'No finger' or data.decode('utf-8') == ''):
        continue;
    if(c):
        c = 0
        continue
    print("Inserting: ",data.decode('utf-8'),"\n")
    json_body = [
        {
            "measurement": "BPM",
        "tags": {
            "user": "Prometheus",
            "region": "gr"
        },
            "fields": {
            "value": float(data[4:].decode('utf-8'))
        }
        }
    ]
    client.write_points(json_body)
