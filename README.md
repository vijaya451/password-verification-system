# 🔐 UART Password-Based Door Control System (LPC21xx)

## 📌 Project Overview

This project implements a **password-based door access system** using UART communication on an **LPC21xx ARM7 microcontroller**.
The user enters a password through a serial terminal, and the system validates it. Based on the result, it displays whether access is granted or denied.

---

## ⚙️ Features

* UART0 communication (9600 baud rate)
* Interrupt-driven UART reception
* Password validation using `strcmp()`
* Echoes user input in real-time
* Simple and efficient embedded C implementation

---

## 🧰 Technologies Used

* Embedded C
* LPC21xx Microcontroller
* UART Communication
* Interrupt Handling (VIC - Vectored Interrupt Controller)

---

## 📁 Project Structure

```
├── main.c                # Main application logic
├── uart.c                # UART driver functions
├── uart_interrupt.c      # UART interrupt handler
├── UART_header.h         # Function declarations
```

---

## 🔄 Working Principle

1. System initializes UART communication.
2. Enables UART interrupt via VIC.
3. Prompts user to enter password.
4. User input is captured via UART interrupt.
5. When Enter (`\r`) is pressed:

   * Input string is terminated with `\0`
   * Flag is set
6. Main loop checks flag:

   * If password matches → Access granted
   * Else → Access denied

---

## 🔑 Default Password

```
abcde
```

---

## 🚀 How to Run

1. Compile the code using Keil or any ARM compiler.
2. Flash the program into LPC21xx board.
3. Open serial terminal (like PuTTY/Tera Term).
4. Set:

   * Baud Rate: 9600
   * Data Bits: 8
   * Stop Bits: 1
5. Enter password and press Enter.

---

## 🧠 Key Concepts Used

### UART Initialization

* Configures baud rate using `U0DLL` and `U0DLM`
* Enables transmission and reception

### Interrupt Handling

* UART interrupt triggers on data reception
* Uses `U0IIR` to identify interrupt source

### Buffer Handling

* Stores input in `array[6]`
* Ensures no overflow (max 5 characters + null)

---

## ⚠️ Limitations

* Fixed password (hardcoded)
* No encryption/security
* Limited buffer size (5 characters only)

---

## 🔮 Future Improvements

* Add EEPROM/Flash-based password storage
* Implement password masking (`*`)
* Add retry limit and lock mechanism
* Interface with real hardware (relay/door motor)

---

## 👨‍💻 Author

Modem Vijaya

---

## 📜 License

This project is for educational purposes only.
