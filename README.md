# Smart Room Automation System with Entry-Exit Detection & Memory Recall

## Overview
A smart room automation system that controls lights and fans based on occupancy. Using sensors, it detects entry and exit, automatically turning devices on when people enter and off when the room is empty. The system keeps a count of occupants to ensure lights and fans remain on if people are still inside.

## Features
- **Automated Control**: Lights and fans turn on/off based on entry-exit detection.  
- **Occupancy Counting**: Ensures devices remain on if someone is still inside.  
- **Manual Override**: Physical switches for manual control.  
- **Status Indication**: Two-color LED shows entry/exit status.  
- **Reset Function**: Resets occupancy count in case of sensor misreads.  
- **EEPROM Memory**: Remembers switch states after power loss.  

## How It Works
1. Sensors detect when a person enters or exits the room.
2. The system keeps track of the number of people inside.
3. Lights and fans turn on when the first person enters and turn off only when the room is empty.
4. Manual switches allow users to override the automation.
5. LED indicators show entry/exit status.
6. A reset button corrects sensor misreads by resetting the occupancy count.
7. EEPROM memory stores the last switch state to retain settings after power failure.

## Benefits
- Reduces energy consumption by automating light and fan usage.
- Ensures convenience by automatically controlling room appliances.
- Provides a reliable backup system with EEPROM memory.

## Installation & Setup
1. Connect the sensors to detect entry and exit.
2. Install manual override switches for added control.
3. Ensure the EEPROM memory is configured to store switch states.
4. Test the system by entering and exiting the room.
5. Use the reset function if the occupancy count becomes inaccurate.

## Applications
- **Smart Homes**: Automate room lighting and fans for energy efficiency.
- **Offices**: Enhance workplace automation and energy savings.
- **Smart Buildings**: Implement intelligent room control systems.

## Contribution
Feel free to contribute by submitting pull requests or reporting issues!

## License
This project is licensed under the MIT License.

