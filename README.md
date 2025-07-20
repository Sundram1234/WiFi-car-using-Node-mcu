# 🚗 Wi-Fi Controlled Car using NodeMCU

This project is a Wi-Fi-enabled car made using the NodeMCU (ESP8266), L298N motor driver, and controlled using a mobile or browser interface via Wi-Fi.

## 📷 Project Images

![Top View](Images/car_top_view.jpg)
![Side View](Images/car_side_view.jpg)

## 🧰 Components Used

- NodeMCU ESP8266
- L298N Motor Driver Module
- 4 DC Motors
- Power Supply (Battery)
- Chassis
- Jumper Wires

## 🔌 Circuit Diagram

![Circuit Diagram](Circuit_Diagram/wifi_car_circuit.jpg)

## 🔧 How It Works

1. NodeMCU hosts a Wi-Fi server.
2. User connects to Wi-Fi via phone and accesses a web interface.
3. On-screen buttons send commands (like FORWARD, BACKWARD) via HTTP to NodeMCU.
4. NodeMCU sets digital pins HIGH/LOW to move motors.

## 📟 Arduino Code

Code is in the `Code/` folder. Upload using Arduino IDE with the ESP8266 board selected.

## 🛠️ Setup Instructions

1. Open Arduino IDE.
2. Install ESP8266 board from Board Manager.
3. Connect NodeMCU via USB.
4. Open `wifi_car.ino`, enter your Wi-Fi SSID and password.
5. Upload the code.
6. Connect to NodeMCU IP via browser and control the car.

## 👨‍💻 Author

Sundram Sarve

## 📄 License

MIT License
