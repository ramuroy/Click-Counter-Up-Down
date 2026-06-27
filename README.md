# Click Counter (Up and Down) Project

This project demonstrates a simple **Click Counter** system using an **Arduino board**, two **push buttons**, and a **7-segment display**. The counter can be incremented and decremented based on button presses.

## 🛠️ Components Used:
- **Arduino Uno** board
- **2 Push buttons**
- **1 x 7-Segment Display**
- **Jumper wires**
- **Breadboard**
- **Resistors** (≈220–330 Ω, one per 7-segment segment — the buttons need none; they use the internal pull-ups)

## ⚙️ How It Works:
- Two push buttons are used to control the counting:
  - One button **increments** the count.
  - The other button **decrements** the count.
- The count is displayed in **real-time** on a 7-segment display.
- The counter's value increases or decreases by 1 with each button press, and the display is updated immediately.

## 📺 Demonstration Video:
Watch the **Click Counter (Up and Down)** project in action!

🔗 [Click here to watch the demonstration on LinkedIn](https://www.linkedin.com/posts/ramu-roy-b780382b7_arduino-electronicsfun-embeddedsystems-activity-7300746569916530688-Z9XP?utm_source=social_share_send&utm_medium=android_app&rcm=ACoAAEwAX4wBY70YZ3l58lvkiXtyCZcnWWrfJAA&utm_campaign=copy_link)

## 📝 Code Explanation:
1. **Button Inputs**: The two push buttons are connected to specific pins on the Arduino board.
2. **7-Segment Display**: The counter is shown on a 7-segment display. The code drives the display based on the count value.
3. **Debouncing**: The code handles button debouncing to avoid multiple counts from a single press.
4. **Simple Logic**: Each button press either increments or decrements the counter and updates the display accordingly.

## 🔧 Circuit Diagram:
Below is a basic description of the circuit:
- **7-Segment Display**: A **common-cathode** display; segments A–G connect through current-limiting resistors to Arduino pins **D4–D10**, with the common pin to **GND**.
- **Push Buttons**: The **Up** button on **D2** and the **Down** button on **D3**, each wired from the pin to **GND**. The sketch enables the internal **pull-up** resistors (`INPUT_PULLUP`), so a press reads **LOW** (active-low) — no external button resistors are required.

## 🚀 How to Use:
1. **Set up the hardware**: Connect the push buttons and 7-segment display to the Arduino following the provided circuit diagram.
2. **Upload the code**: Upload the provided Arduino code to your Arduino board using the Arduino IDE.
3. **Press the buttons**: Press the increment button to increase the count and the decrement button to decrease the count.
4. **Observe the display**: The 7-segment display will show the updated count value.

## 📄 License:
This project is open-source and available under the MIT License. Feel free to use, modify, and share it!

## 📞 Contact:
For any questions or feedback, feel free to reach out or leave a comment on the demonstration video!
