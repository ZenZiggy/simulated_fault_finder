**- PROJECT OVERVIEW -**

This hardware project serves as a simulation of a utility electrical transmission line using a lumped-element resistor
ladder to calculate fault locations. Utilizing an Arduino Uno R3 microcontroller, the system samples line voltages via an Analog-to-Digital Converter (ADC). When a fault to ground is detected, the system dynamically calculates the fault zone distance using impedance estimation
principles.

**- TECHNICAL SPECIFICATIONS -**

Microcontroller: Arduino Uno R3

Rref and R1-R4: 1 ohm

Wires:
  - Red: +5VDC
  - Black: GRND
  - Yellow: Data Transfer

**- SINGLE LINE DIAGRAM -**

[ 5V DC Source ]
        │
        ▼
    [ R_ref ]
        │
        ├───→ Telemetry Line (Yellow Wire) ───→ [ Arduino Analog Pin A0 ]
        │
        ├─── ( Node 1: Substation Fault Boundary )
        │         │
        │     [ Fault Jumper 1 ] ───→ [ DC GND ]
        │
        ▼
    [ R1 (Zone 2 Resistor) ]
        │
        ├─── ( Node 2: Zone 2 Fault Boundary )
        │         │
        │     [ Fault Jumper 2 ] ───→ [ DC GND ]
        │
        ▼
    [ R2 (Zone 3 Resistor) ]
        │
        ├─── ( Node 3: Zone 3 Fault Boundary )
        │         │
        │     [ Fault Jumper 3 ] ───→ [ DC GND ]
        │
        ▼
    [ R3 (Zone 4 Resistor) ]
        │
        ├─── ( Node 4: Zone 4 Fault Boundary )
        │         │
        │     [ Fault Jumper 4 ] ───→ [ DC GND ]
        │
        ▼
    [ R4 (Zone 5 Resistor) ]
        │
        └─── ( Node 5: Zone 5 / End of Line Fault Boundary )
                  │
              [ Fault Jumper 5 ] ───→ [ DC GND ]

**- MATHEMATICAL PROCEDURE -**

The mathematical model used for this project is directly derived from the standard Ohm's Law voltage divider ratio:
  R_{line} = R_{ref} * ((V_A0)/(5V - V_A0))

The system calculates this value every 1 second. It is used directly to determine if there is a fault at any given zone and where it is located.

**- KEY TAKEAWAYS -**
