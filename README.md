# Smart Parking System 

The **Smart Parking System** is an IoT-based solution designed to efficiently monitor parking lot availability. It keeps track of the number of available parking slots, notifies users when the parking lot is full, and provides real-time updates on parking status.

---

##  Features
- **Slot Monitoring**: Tracks the number of available and occupied parking slots.
- **Full Parking Alert**: Sounds an alarm when the parking lot is full.
- **Real-Time Display**: Continuously updates and displays the number of free slots.

---

## Components Used
### Sensors:
- **Infrared (IR) sensors**: Detect whether a parking slot is occupied or vacant.

### Indicators:
- **LEDs**:
  - **Green LED**: Indicates slots are available.
  - **Red LED**: Indicates the parking lot is full.
- **Buzzer**: Sounds an alarm when all slots are occupied.

### Microcontroller:
- **Arduino-based system**: Controls the parking slot logic and updates.

### Display:
- **16x2 I2C LCD**: Shows the real-time number of available slots.

---

## How It Works
1. Each parking slot is monitored using sensors that detect whether it is occupied.
2. The total number of available slots is calculated and displayed on the LCD screen.
3. If the parking lot is full:
   - The **red LED** is activated.
   - The **buzzer** sounds an alarm to notify users.
4. The system resets as slots become available.

---
