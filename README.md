# WiFiSpider 🕷️🕸️ #TURNING THE 2.2" CYD DISPLAY INTO A WEARABLE                                                              
**A stealthy captive portal framework for ESP32-2432S022 (2.2" CYD display)**                             
*Harvest credentials through deceptive WiFi portals - For educational/pen-testing purposes only*        
                                                                                                           
![preview](https://github.com/user-attachments/assets/7e0266f6-19cd-4986-a272-ae244302ce69)               

---                                                                                                       
                                                                                                          
## 🔍 Description
WiFiSpider is an ESP32-based rogue access point framework designed for security researchers to demonstrate phishing risks in public WiFi networks. Built specifically for the **2.2" CYD ESP32-2432S022** touch display, it combines:
- Captive portal interception
- Credential harvesting
- On-device display logging

 ##BURLEYSHIRLEYSQUIRRELY- THROUGH A COMBINATION OF 3D PRINTING, HARDWARE REDESIGN, APPROPIATING MATERIAL F
                           OTHER PROJECTS, AND HOPEFULLY A UI UPGRADE IF NOT BY ME THEN SOMEONE TO TURN THE
                           QUITE PETITE CYD 2.2 INTO A SEXY, SLEEK WEARABLE RUNNING AN AMMENDED WIFISPIDER.
                           THIS IS MY FIRST TIME FORKING ANYTHING OR TRYING ANYTHING OF THIS SORT SO I 
                           REALLY HAVE NO IDEA WHAT IM DOING.******************

---

## ⚡ Features
### Core Functionality
- **Evil Portal Engine**  
  - Auto-redirect all HTTP requests to spoofed login pages
  - DNS hijacking for persistent captive portal behavior
  - Customizable HTML templates (Google, Facebook, etc.)

### Display Integration
- **2.2" CYD Touchscreen UI**  
  - Real-time victim connection monitoring
  - Credential display scrolling
  - Basic touch controls for operation

---

## 📦 Hardware Requirements
**Tested ONLY on:**  
`ESP32-2432S022 (2.2" CYD display)`  
**Required Components:**
- MicroSD card module (later on)
- External Antenna (optional, needs soldering)

---

## 🕹️ Usage
1. **Hardware Setup**  
   ```
   CYD Display -> ESP32
   ```

2. **Upload Sketch**  
   - Select `ESP32 Dev Module` in Arduino IDE

3. **Operation**  
   - Power on device
   - View credentials on display

---

## 📝 TODO
- [ ] Add multi-portal template support
- [ ] Implement SD Card File Selection
- [ ] Touchscreen calibration utility
- [x] Basic captive portal (current)
- [ ] OTA firmware updates

---

## ⚠️ Disclaimer
> This tool is intended for **legal security research only**. Usage for attacking targets without prior mutual consent is illegal. Developers assume no liability for misuse.

---

## 🤝 Contributing
Open to PRs for:
- SD Card Support
- Better UI/UX

## 👥 Authors & Contributors
**Evil Portal Code**  
- [Atomic by Axion Security](https://github.com/Axion-Security)  
  *Core Logic for Evil Portal*

**Special Thanks**  
- [Zynth9999](https://github.com/Zynth9999): Recommend me the UI library.

## 📜 License
GNU GPLv3 - See [LICENSE](LICENSE) for details
