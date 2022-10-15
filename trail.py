
import serial
import time

serialcomm = serial.Serial('COM10',9600)
serialcomm.timeout = 1
while True:
	while True:
		i=input("which song do you want to listen:").strip()
		serialcomm.write(i.encode())
		time.sleep(0.5)
		print(serialcomm.readline().decode('ascii'))
		break
	while True:
		n=input("how long do you want to listen:").strip()
		serialcomm.write(n.encode())
		time.sleep(0.5)
		print(serialcomm.readline().decode('ascii'))
		break
	text1=('you choose song '+i+' and you want to listen '+n+'s')
	print(text1)

serialcomm.close()
