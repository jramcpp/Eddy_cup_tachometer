- Eddy Cup Tachometer
  ## Overview
  The **Eddy Cup Tachometer** is a **non-contact rotational speed sensor** that utilizes **eddy currents** to measure angular velocity. Unlike conventional tachometers, this device operates without physical contact, making it **durable, wear-free, and highly reliable** for measuring high-speed rotating machinery.
  ## Features
  - **Non-contact Measurement**: Eliminates mechanical wear and friction.
  - **High Durability**: Suitable for harsh industrial environments.
  - **Magnetic Eddy Current Sensing**: Detects speed using induced electromagnetic forces.
  - **Real-time Data Acquisition**: Interfaces with **Xiaomi ESP32-C6** for digital speed readout.
  - **OLED Display Support**: Uses **Adafruit SSD1306** for visual output.
  - **Low Maintenance**: No moving parts reduce maintenance needs.
  ## System Components
  - **Eddy Current Cup**: Rotating conductor inducing a magnetic field.
  - **Magnetic Sensor**: Detects variations in eddy currents for speed calculation.
  - **Xiaomi ESP32-C6**: Processes sensor data and transmits output.
  - **Adafruit SSD1306 OLED Display**: Displays real-time RPM readings.
  - **Signal Processing Circuit**: Converts eddy current variations into readable data.
  ## Getting Started
  ### Prerequisites
  Before using the tachometer, ensure you have:
  - A suitable **rotating metallic target**.
  - A **magnetic sensor** (e.g., Hall effect sensor, coil pickup).
  - A **Xiaomi ESP32-C6** (for data processing and display).
  - An **Adafruit SSD1306 OLED Display** (for visual feedback).
  ### Installation
  1. **Mount the Eddy Cup** securely on the rotating shaft.
  2. **Position the Magnetic Sensor** at an optimal distance from the cup.
  3. **Connect the Sensor** to the **Xiaomi ESP32-C6**.
  4. **Connect the Adafruit SSD1306** to the ESP32-C6 via I2C.
  5. **Upload the firmware** to the ESP32-C6 using the Arduino IDE.
  6. **Calibrate the System** by comparing readings with a known reference tachometer.
  ## Usage
  1. **Power the Sensor Circuit**.
  2. **Monitor the OLED Display**, which shows real-time RPM values.
  3. **Process Data** using the ESP32-C6 or transmit via serial communication.
  4. **Adjust Sensor Distance** if signal quality is weak or inconsistent.
  ## Applications
  - **Industrial Machinery Speed Monitoring**
  - **Automotive RPM Sensing**
  - **High-speed Turbine and Motor Testing**
  - **Laboratory Experiments in Electromagnetic Induction**
  ## Troubleshooting
  - **Weak Signal?** Ensure proper alignment and optimal sensor distance.
  - **Inconsistent Readings?** Check for external magnetic interference.
- **No Output?** Verify power supply, sensor connections, and ESP32-C6 firmware.

## Future Improvements

- **Enhanced Sensitivity** using advanced coil designs.
- **Wireless Data Transmission** for remote monitoring.
- **Digital Signal Processing (DSP)** for improved accuracy.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests.

## License

This project is licensed under the **MIT License**.

## Acknowledgments

Thanks to the **electromagnetics and sensor technology community** for insights into eddy current applications.

