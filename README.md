# Automatic Wet Food Feeder

![Project External](https://github.com/AlainaWayne/AutomatedWetFoodFeeder/blob/d49c3d3c9f6b8ae83321f5f292f9ef90b6af3bfc/final_assembly_external.jpg)
![Project Internal](https://github.com/AlainaWayne/AutomatedWetFoodFeeder/blob/d7d6da683f5ce718efed6bf6cf8943d7db22a0e8/final_assembly_internal.jpg)


## Overview

The Automatic Wet Food Cat Feeder is an innovative solution to address the challenges of feeding cats on a wet food diet while the owner is away. It ensures precise portioning, maintains food freshness, and automates feeding schedules to provide convenience for pet owners and quality care for their pets.

This project was developed as part of the MECH 495 Senior Design Capstone at Kettering University.

---

## Features

- **Effective Cooling:** Maintains low temperatures to preserve wet food safety and quality
- **Accurate Dispensing:** Ensures precise rotation to dispense one portion of food at a time
- **User-Friendly Design:** Simple operation with easy refills and cleaning
- **Compact & Aesthetic:** Space-efficient and visually appealing design
- **Durable Construction:** Food-safe materials ensure long-term usability
- **Thermal Efficiency:** Isolates hot and cold zones for effective cooling
- **Cost Effective:** Designed to minimize costs
- **Future Expandability:** Designed to accommodate potential smart features

---

## Components & Materials

| Component              | Quantity | Description                         |
|------------------------|----------|-------------------------------------|
| 3.5-in Fans           | 3 pcs    | Cooling airflow                     |
| Peltier Devices        | 4 pcs    | Thermoelectric coolers              |
| Heat Sinks            | 4 pcs    | Heat dissipation                    |
| Arduino Uno Controller| 1 pc     | Microcontroller                     |
| TB6600 Stepper Motor Driver | 1 pc | Motor control                      |
| Stepper Motor         | 1 pc     | Rotational motion                   |

For the complete Bill of Materials, refer to the [BOM File](https://github.com/AlainaWayne/AutomatedWetFoodFeeder/blob/main/Bill%20of%20Materials).

---

## Design Goals

1. **Reliability:** Ensures consistent feeding schedules.
2. **Power Efficiency:** Optimized for minimal power draw.
3. **Safety:** Designed with pet safety in mind.
4. **Ease of Maintenance:** Simple to disassemble for cleaning.
5. **Sustainability:** Incorporates recycled and repurposed components.

![CAD Model](https://github.com/user-attachments/assets/01eda744-975d-44b9-a6e8-176aee6617dc)

---

## Manufacturing Process

The feeder was crafted using a combination of advanced CNC machining, 3D printing, and traditional woodshop techniques. Custom components were fabricated with 3D printing and aluminum sheet metal for the cooling system.

### Lid
![CNC Lid](https://github.com/user-attachments/assets/2fab2322-5877-42a8-9c55-99246a051d7a)
![lid assembly](https://github.com/user-attachments/assets/aa91b375-ef6d-4174-b1af-b0c7ed78a71f)

### Turntable
![Turntable Milling](https://github.com/user-attachments/assets/6c4cd75c-c381-45f2-a757-223fee642585)
![Turntable milling issue](https://github.com/user-attachments/assets/32855f11-e6e7-464f-9249-ebcc226040fb)
![Turntable](https://github.com/user-attachments/assets/504d0fd9-736e-4ade-b650-78bbfeb965f1)

### Main Housing
![gluing housing components](https://github.com/user-attachments/assets/ed31a8fe-3cc4-4bfe-a306-0abec0586cb9)



---
## Software

The plan for the code is relatively simple. Below is an outline of its structure and functionality:

### Overview

- **Constants and Variables:** All constants and variables are declared at the start to avoid confusion later.
- **Setup Routine:** All pin modes are configured in the startup routine.
- **State Machine:** The main logic is controlled by a state machine with four states:

### States

1. **WaitHome:**
   - The feeder is at the “home” position (food is not available).
   - In this state, the machine waits for input (a button in demo mode, or a timed schedule in real operation).
   - When input is received, the state transitions to `MoveFeed`.

2. **MoveFeed:**
   - The feeder moves to the next available can.
   - **Logic:**
     - Tracks which cans have been used.
     - Moves in the rotation that is fastest to reach the next available can.
   - **Tracking:**
     - Uses magnets and 2 hall effect sensors as an encoder to detect direction and position changes.
   - Once the desired can is reached, the state transitions to `WaitFeed`.

3. **WaitFeed:**
   - This state is similar to `WaitHome`.
   - The machine waits for input to indicate feeding is complete.
   - When input is received, the state transitions to `MoveHome`.

4. **MoveHome:**
   - The feeder returns to the “home” position.
   - **Logic:**
     - The current location is compared to the home position.
     - Rotates in the faster direction to return home.
   - **Tracking:**
     - An offset hall effect sensor detects a specific magnet placed at the home position.
     - When the sensor detects this magnet, the machine confirms it is in the “home” position.
   - Once home, the state transitions back to `WaitHome`.

### Summary

This state machine design ensures clear and predictable operation of the automated feeder, handling both user input and positional accuracy through efficient tracking mechanisms.
[Link to Code](https://github.com/AlainaWayne/AutomatedWetFoodFeeder/blob/b0ec120aadc8a26be4aa09604b9c6fafe7771586/feeder_control/feeder_control.ino)

---

## Testing & Validation

### Key Tests
- **Cooling Performance:** Tested cooling rate of Peltier devices in pre-built fridge.
- **Motor Selection:** Torque calculations ensured sufficient rotation force.
- **Usability Testing:** Identified optimal height of 8 inches for maximum cat comfort.

### Results
- Cooling system reduced temperatures by 34°F over 3 hours.
- Stepper motor met torque requirements with a significant safety margin.

---

## Challenges & Solutions

- **Dimensional Adjustments:** CNC panel inaccuracies were resolved with manual corrections
- **3D Printing Challenges:** Due to 3D printer limitations, 3D printed components needed significant post-processing in order to fit properly with design
- **Chain Tensioning:** Improved by modifying motor mounting to allow tension adjustments

---

## Future Improvements

- Enhanced power efficiency
- Increased cooling capacity for prolonged food storage
- Smart integration for remote operation and monitoring
- Improved manufacturing of hardware components

---

## Contributors

- Damera Gebissa
- Christian Pellerito
- Alaina Wayne
- Julia Carroll
- Jacob Morrison

---

## Acknowledgments

Special thanks to Dr. Craig Hoff and the Kettering University IME Lab for guidance and support!
