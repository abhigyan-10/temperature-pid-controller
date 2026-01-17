# Temperature PID Controller

A C implementation of a PID (Proportional-Integral-Derivative) controller for simulating real-world temperature control systems.

## 🎯 Project Overview

This project simulates a physical temperature control system where:
- A heater adds thermal energy at a controlled rate
- Ambient conditions naturally cool the system
- A PID controller intelligently maintains the desired temperature

## ✨ Features

- **Full PID Implementation**: Proportional, Integral, and Derivative control
- **Adaptive Gain Scheduling**: Automatically adjusts control parameters based on error magnitude
- **High Precision**: Achieves ±0.03°C accuracy
- **Realistic Physics**: Models actual thermal dynamics with heating and cooling rates

## 🔬 Physics Model
```
Temperature(t+dt) = Temperature(t) + (Heater_Power - Heat_Loss) × dt
```

**System Parameters:**
- Maximum heating rate: 0.66°C/second
- Ambient cooling rate: 0.2°C/second  
- Simulation time step: 0.1 seconds

## 🎛️ PID Control Strategy

### Proportional (P)
Responds to current temperature error. Uses adaptive gain:
- Large errors (>10°C): Kp = 1.0 (gentle approach)
- Small errors (≤10°C): Kp = 2.0 (aggressive correction)

### Integral (I)
Eliminates steady-state error by accumulating past errors.
- Ki = 0.002 (conservative to prevent windup)

### Derivative (D)
Prevents overshoot by predicting future error.
- Kd = 0.35 (provides damping)

## 📊 Performance Results

**Test Case: 34°C → 45°C**
- ✅ Settling time: ~246 seconds
- ✅ Overshoot: 0.032°C (0.07%)
- ✅ Final accuracy: ±0.03°C
- ✅ No sustained oscillation

## 🚀 Usage

### Compile and Run
```bash
gcc temperature_controller.c -o temp_control
./temp_control
```

### Modify Target Temperature
Change the `desired_temp` variable in the code:
```c
float desired_temp = 45.0;  // Set your target here
```

## 🔧 How It Works

1. **Calculate Error**: `error = target - current_temp`
2. **Compute PID Terms**:
   - P = Kp × error
   - I = Ki × Σ(error × dt)
   - D = Kd × (error_change / dt)
3. **Control Output**: heater_power = P + I + D
4. **Apply Physics**: Update temperature based on heating/cooling
5. **Repeat** every time step

## 🌍 Real-World Applications

This type of control system is used in:
- 🏠 Home thermostats and HVAC systems
- 🏭 Industrial process control
- 🚗 Automotive cruise control
- ✈️ Aircraft autopilot systems
- 🤖 Robotics and automation
- 🔬 Laboratory equipment temperature regulation

## 🎓 Key Learnings

- Understanding how physical systems resist instantaneous change
- The role of each PID component in achieving stable control
- Trade-offs between response speed, overshoot, and stability
- Importance of tuning parameters for different operating conditions
- System limitations (can heat faster than it can cool)

## 🔮 Future Enhancements

- [ ] Anti-windup protection for integral term
- [ ] Bidirectional control (active cooling capability)
- [ ] Real-time visualization/graphing
- [ ] Multiple setpoint tracking
- [ ] Disturbance rejection testing
- [ ] Auto-tuning algorithm

## 📝 License

MIT License - Feel free to use and modify!

## 🤝 Contributing

Suggestions and improvements are welcome! Feel free to open an issue or submit a pull request.


**Made with 🧠 and ☕ while learning control systems**
