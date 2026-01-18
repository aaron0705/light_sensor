import serial
import mysql.connector
import json

uart = serial.Serial()

def main():
    uart_init()
    while True:
        i = []
        try:
            i = uart_recevie(i)
            if i :       
                print(i)
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

def uart_transmit(datas):
    if uart.writable():
        uart.write(data.encode())
    else:
        return False
    return True

def uart_recevie(i):
    if uart.readable():
        while uart.in_waiting > 0:
            i = uart.readline()
            try:
                i = i.decode().strip()
                return i
            except UnicodeDecodeError:
                print("Lỗi: Nhiễu tín hiệu")


def save_data(json_mesage):
    cnx = mysql.connector.connect(
    host="127.0.0.1",
    port=3306,
    user="root",
    password="")
    cur = cnx.cursor()
    # Sử dụng 3 dấu ngoặc kép để tránh lỗi xung đột dấu ngoặc bên trong
    sql_query = """
        INSERT INTO history (`Date and Time`, `Value`, `Device`, `User`)
        VALUES (%s, %s, %s, %s)
    """

    # Gom dữ liệu vào 1 tuple riêng cho dễ nhìn và dễ debug
    data_values = (
        json_message["datetime"], 
        json_message["value"], 
        json_message["device"],   # Đã sửa lỗi chính tả json_mesage
        json_message["user"]      # User là cột thứ 5
    )

    # Thực thi
    cur.execute(sql_query, data_values)  
    cnx.commit()
    cursor.close()
    cnx.close()
    return True

if __name__ == "__main__":
    main()