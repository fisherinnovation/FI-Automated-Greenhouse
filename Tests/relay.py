import time 
import RPi.GPIO as io 
io.setmode(io.BCM) 
 
relay_pin = 23
 
io.setup(relay_pin, io.OUT)
io.output(relay_pin, False)
 
while True:
	print("POWER ON")
	io.output(relay_pin, True)
    time.sleep(10);
	print("POWER OFF")
	io.output(relay_pin, False)
	time.sleep(10)