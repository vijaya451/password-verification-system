# 🔐 UART Password-Based Door Control System (LPC21xx)

## 📌 Project Overview

This project implements a **password-based door access system** using UART communication on an **LPC21xx ARM7 microcontroller**.

The system validates a user-entered password via serial terminal and controls access. It also includes a **security lock mechanism with delay-based timeout** after multiple failed attempts.

---

## ⚙️ Features

* UART0 communication (9600 baud rate)
* Interrupt-driven UART reception
* Password validation using `strcmp()`
* Real-time user input echo
* Retry limit with automatic lock system
* **Delay-based countdown timer after 3 failed attempts**

---

## 🧰 Technologies Used

* Embedded C
* LPC21xx Microcontroller (ARM7)
* UART Communication
* Interrupt Handling (VIC - Vectored Interrupt Controller)

---

## 📁 Project Structure

```
├── main.c                # Main application logic
├── uart.c                # UART driver functions
├── uart_interrupt.c      # UART interrupt handler
├── delay.c               # Delay functions (software timing)
├── UART_header.h         # Function declarations
```

---

## 🔄 Working Principle

1. System initializes UART communication.
2. Enables UART interrupt via VIC.
3. Prompts user to enter password.
4. User input is received via UART interrupt.
5. When Enter (`\r`) is pressed:

   * Input is terminated with `\0`
   * Flag is set
6. Main loop checks the flag:

   * If password matches → Access granted
   * If incorrect:

     * Displays error message
     * Increments attempt counter
     * After 3 failed attempts:

       * System enters lock state
       * Displays countdown timer
       * Uses delay function to enforce wait time
       * Resets attempt counter

---

## 🔑 Default Password

```
abcde
```

---

## 🔒 Security Behavior

* Maximum 3 incorrect attempts allowed
* After 3 failures:

  * System locks temporarily
  * Displays countdown (3 seconds)
  * Uses `delay_sec()` for timing control
  * Blocks user input during delay

---

## ⏱️ Delay Implementation

* Delay is implemented using a **software-based delay function (`delay_sec()`)**
* Used to create a countdown timer during lock state
* Provides simple timing control without hardware timers

---

## 🚀 How to Run

1. Compile using Keil or ARM compiler.
2. Flash to LPC21xx board.
3. Open serial terminal (PuTTY / Tera Term).
4. Configure:

   * Baud Rate: 9600
   * Data Bits: 8
   * Stop Bits: 1
5. Enter password and press Enter.

---

## 🧠 Key Concepts Used

### UART Initialization

* Baud rate setup using `U0DLL`, `U0DLM`
* Enables TX and RX

### Interrupt Handling

* UART interrupt on data receive
* Uses `U0IIR` for interrupt identification

### Buffer Handling

* Input stored in `array[6]`
* Prevents overflow (5 chars + null)

### Security & Timing

* Failed attempt tracking
* Lock mechanism using delay
* Countdown display using UART

---

## ⚠️ Limitations

* Fixed password (hardcoded)
* No encryption
* Delay is not precise (software-based)
* Blocks CPU during delay

---

## 🔮 Future Improvements

* Use hardware timers instead of delay
* Store password in EEPROM
* Add password masking (`*`)
* Add buzzer/LED alerts
* Interface with relay for real door lock

---

## 👨‍💻 Author

Modem Vijaya

---

## 📜 License

For educational purposes only.
