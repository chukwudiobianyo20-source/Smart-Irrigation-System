# Smart Irrigation System

An automated smart irrigation system that optimizes water usage using soil moisture and humidity sensors to provide precise, real-time irrigation.

## Overview

This Smart Irrigation System addresses the technical challenge of inefficient water management in traditional irrigation practices by using:
- **Soil Moisture Sensors** - Measure volumetric water content in soil
- **Humidity Sensors** - Gauge atmospheric conditions for fine-tuning irrigation
- **Arduino Uno** - Central processing unit that makes real-time decisions
- **Relay & Water Pump** - Automated water distribution system
- **LCD Display** - Real-time sensor data visualization

The system employs **closed-loop adaptive control**, adjusting irrigation schedules based on environmental feedback to optimize water usage.

## Features

- **Automated Irrigation** - Triggers watering based on sensor thresholds
- **Real-time Monitoring** - LCD displays live humidity and moisture readings
- **Emergency Protocol** - Activates irrigation at critical moisture levels regardless of humidity
- **Dual-Sensor Integration** - Uses both soil moisture and air humidity for accurate decision making
- **Compact Design** - All components housed in a portable, weather-resistant box
- **Energy Efficient** - Low power consumption, expandable to solar power

## Hardware Components

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | ATmega328P microcontroller board |
| Soil Moisture Sensor | 1 | Capacitive/Resistive soil moisture probe |
| DHT11 Sensor | 1 | Digital temperature and humidity sensor |
| SPDT Relay | 1 | 5V 2-channel relay module |
| Water Pump | 1 | Submersible/Inline water pump |
| I2C LCD | 1 | 16x2 LCD with I2C interface |
| Power Supply | 1 | 9V-12V DC power adapter |
| Jumper Wires | - | Various for connections |

## Pin Configuration

| Component | Pin | Arduino Pin |
|-----------|-----|-------------|
| Soil Moisture Sensor | Signal | A0 |
| DHT11 | Signal | D8 |
| Relay | Signal | D13 |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |

## Installation

### Prerequisites
1. **Arduino IDE** - Download from [arduino.cc](https://www.arduino.cc/en/software)
2. **Required Libraries**:
   - `DHT` library
   - `LiquidCrystal_I2C` library
   - `Wire` library (built-in)

## Threshold Settings

Based on extensive testing, the following thresholds were established:

| Parameter | Threshold | Description |
|-----------|-----------|-------------|
| **Soil Moisture** | ≤ 30% (225 analog) | Water if below this value |
| **Air Humidity** | ≤ 70% | Water if below this value |
| **Emergency** | ≤ 20% (150 analog) | **Water regardless of humidity** |

### Sensor Value Ranges (After Calibration)
- **Soil Moisture (0-750 raw)**
  - Dry: ~6% (45 raw)
  - Normal: ~42% (315 raw)
  - Wet: ~92% (690 raw)

- **Air Humidity (0-100%)**
  - Dry: ~18%
  - Normal: ~50%
  - Moist: ~95%

## Testing

### Individual Component Testing
1. **Soil Moisture Sensor** - Tested with dry, normal, and wet soil samples
2. **DHT11 Sensor** - Tested with hair dryer (dry) and humidifier (moist)
3. **System Integration** - Full system test with relay and pump

### Test Results

| Test Condition | Moisture Reading | Humidity Reading | Relay State |
|----------------|------------------|------------------|-------------|
| Normal Soil | 42.53% | 50% | OFF |
| Dry Soil | 6.13% | 18% | ON |
| Wet Soil | 92.53% | 95% | OFF |
| Emergency | 1.07% | 50% | ON |

## Results

- **Accurate Threshold Detection** - System activates at 30% moisture, 70% humidity
- **Emergency Protocol Working** - Activates at 20% moisture regardless of humidity
- **Real-time Display** - LCD shows live sensor readings
- **Reliable Automation** - Consistent pump activation and deactivation

## Future Improvements

1. **Scalability** - Connect multiple sensor-pump modules for larger areas
2. **Weather Integration** - Connect to Met Éireann for predictive scheduling
3. **Soil NPK Sensors** - Monitor soil nutrients for complete plant health
4. **Solar Power** - Implement renewable energy sources
5. **User Interface** - Develop mobile/desktop app for remote control
6. **Data Logging** - Store historical data for analytics

## Contributors

- **Chukwudi Obianyo** 
- **Kamsi Nkem** 
- **Farouq Adio** 

*Department of Electronic Engineering, Maynooth University*
