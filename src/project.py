import serial
import mysql.connector
import json
import datetime

uart = serial.Serial()
user_id = None
device_id = None

def main():
    uart_init()
    print('Start receive')
    while True:
        i = []
        try:
            i = uart_recevie()
            if i:       
                print(f'Dữ liệu nhận được: {i}')
                normalize(i)
                if save_data(i):
                    print('Lưu thành công')
        except json.JSONDecodeError:
            pass


def uart_init(baudrate = 115200, timeout = 1):
    # TX 14 RX 15
    uart.port = '/dev/serial0'
    uart.timeout = timeout
    uart.baudrate = baudrate
    if not uart.is_open:
        uart.open()

    uart.reset_input_buffer()
    uart.reset_output_buffer()
    return True 

def uart_transmit(data):
    if uart.writable():
        uart.write(data.encode())
    else:
        return False
    return True

def uart_recevie():
    adc_datas = []
    if uart.readable() and uart.in_waiting > 0:
        data = uart.read(1)
        try:
            adc_datas.append(int(data.decode().strip()))
            if len(datas) == 8:
                return adc_datas 
        except UnicodeDecodeError:
            pass

def normalize(data):
    now = datetime.datetime.now()
    data = {
        "user_id": user_id,
        "data": data,
        "device_id": device_id,
        "datetime": now
    }

def save_data(data):
    cnx = mysql.connector.connect(
    host="127.0.0.1",
    port=3306,
    user="root",
    password="")
    cur = cnx.cursor()
    
    sql_query = """
        INSERT INTO history (`Date and Time`, `Data`, `Device_id`, `User_id`)
        VALUES (%s, %s, %s, %s)
    """

    data_values = (
        data["datetime"], 
        data["data"], 
        data["device_id"],   
        data["user_id"]    
    )

    # Thực thi
    cur.execute(sql_query, data_values)  
    cnx.commit()
    cursor.close()
    cnx.close()
    return True

if __name__ == "__main__":
    main()