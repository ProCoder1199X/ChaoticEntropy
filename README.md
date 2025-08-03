# 🔥 ChaoticEntropy - Hybrid Entropy Generator 

 **ChaoticEntropy** is an pseudo-randomness that blends **human unpredictability**, **non-linear math**, and **real-world data inputs** to create **nearly quantum-level entropy** — without any quantum computers or radioactive atoms!

---

## 📦 Versions

### ✅ Python Version: DEG-v1 (terminal based)
- Takes user-entered **temperature**
- Takes a **random number** (1–99) from human input
- Generates **random latitude & longitude**
- Performs math-based entropy mixing
- Produces a random number

### 🛠 C Version: DEG-C-v1 (Terminal based)
- Fully offline, terminal-based entropy generator
- Uses:
  - Manual temperature input
  - Manual human-random input
- Applies **non-linear transformations** (sine, square roots, etc.)
- Generates and prints:
  - Random coordinates
  - Final entropic number (within 0–99999)

-🔧 How to Compile & Run:
```bash
gcc degc_v1.c -o degc
./degc
```

---

### Chaotic Entropy Generator (CEG) 
### CEG v1
#### 🚀 Features (v1.0)
- 📌 Input up to 22-digit numeric seeds
- 🌍 Converts seed into pseudo-random latitude & longitude
- 📅 Fetches temperature from that location from a past random day (1–30 days ago)
- 🧠 Generates a 64-character entropy hash using SHA-512
- ❄️ Dark themed professional UI using customtkinter
- 🔁 Fallback algorithm for synthetic temperature if no weather data available
- ⚡ Packaged as .exe for easy double-click launch on Windows (no terminal needed)


### CEG-v2
## ✨ What's New in v2.0?

- 🎨 **Theme Support**: Choose from multiple visual themes like `Ocean`, `Sunset`, `Cyberpunk`, `Hacker`, and more!
- 🌙 **Dark/Light Mode Toggle**: Switch between dark and light UI dynamically.
- 📅 **Date Input**: Select a custom date for entropy calculation (optional).
- 🔁 **Animated UI Element**: Looping entropy GIF (currently disabled in EXE).
- 📋 **Clipboard & Save Buttons**: Copy entropy to clipboard or save it as `.txt`.
- 📦 **Packaged .exe** for one-click use (no need to install Python).
- 📁 **Cross-platform Ready**: Designed to be compatible with Linux/macOS too.
- ⚡ Improved UI performance and structure (modularized code into files).

---

## 🚀 Features Overview

- 🔢 Input seeds between **1–22 digits**
- 🌎 Converts input into pseudo-random geo coordinates
- 🌡 Pulls real-time or fallback weather from Open-Meteo
- 🔒 Converts combined data into a **64-character entropy string**
- 🖥 Clean, intuitive UI built with `customtkinter`
- 📁 Save and copy results directly from interface
- 🧪 Modular codebase (`main.py`, `ui.py`, `logic.py`, `themes.py`) for easier expansion
## 🔐 Why This Matters

Unlike traditional pseudorandom number generators (PRNGs), ChaoticEntropy includes:

- 🎯 **Human unpredictability**
- 🌡️ Optional real-world sensor data
- 🌐 Possibility of internet-based data fusion (e.g., temperature, population)
- 🧠 Mental randomness (your thoughts)
- 🧮 Heavy non-linear math

These features make reverse-engineering or brute-forcing the seed extremely difficult — even for **quantum computers**.

---

## 💡 Real-World Use Cases

- Cryptographic entropy injection
- Highly randomized token generation
- Offline secure key creation
- Blockchain randomness oracle (future)
- Educational randomness demonstrator

---

## 🧠 Vision for Future

- Plug in real-time temperature APIs
- Fetch population data based on coordinates
- Add GPIO sensor support
- Mix inputs from multiple humans
- Web version, GUI, and real-world RNG devices

---

## 📜 License
MIT License 
---

## 👑 Creator
**Dheeraj Kumar **
- Developer 
- x.com/DheerajKumar76x
