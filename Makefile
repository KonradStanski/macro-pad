make: compile upload

make compile:
	arduino-cli compile -b arduino:avr:micro

make upload:
	arduino-cli upload -p /dev/tty.usbmodem2101 -b arduino:avr:micro

make monitor:
	arduino-cli monitor -p /dev/tty.usbmodem2101

make clean:
	rm -rf build
