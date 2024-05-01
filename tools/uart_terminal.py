import argparse
import serial
import time

def uart_coms(port, baud_rate):
    try:
        ser = serial.Serial(
            port=port,
            baudrate=baud_rate,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS,
        )
        print(f"Connected to {port} at {baud_rate} bps.")
        data = ser.readline()
        if data:
            pass
        # Continuously read data from the serial port and print it
        while True:
            user_input = input('>>') + '\r\n' 
            ser.write(user_input.encode())

            data = ser.readline()
            print(f'>{data.decode()}')                
            data = ser.readline()
            if data: 
                print(f'>{data.decode()}')                
    except serial.SerialException as e:
        print(f"Error opening serial port {port}: {e}")
    except KeyboardInterrupt:
        print("Program terminated by user.")

def main():
    parser = argparse.ArgumentParser(description='Simple Python UART communication via pyserial.')
    parser.add_argument('--port', type=str, default="/dev/ttyACM0", help='Serial port to connect to (e.g., COM3 or /dev/ttyUSB0)')
    parser.add_argument('--baud_rate', type=int, default=9600, help='Baud rate for serial communication (default: 9600)')
    
    args = parser.parse_args()
    
    uart_coms(args.port, args.baud_rate)

if __name__ == "__main__":
    main()
