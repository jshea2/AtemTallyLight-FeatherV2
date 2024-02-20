## Tally Light for ATEM Switchers


https://github.com/jshea2/AtemTallyLight-FeatherV2/assets/70780576/6c430d9f-d948-4d85-9b9a-beb7b0bb8540


### Requirements:
- [FeatherV2](https://www.adafruit.com/product/5400)
- Wireless Router
- Camera with USB port for power (or any alternative USB power source)
- ATEM Switcher
- Computer with [ATEMOSC](https://www.atemosc.com/)
- [3D Printed Case](https://www.thingiverse.com/thing:6387713)

### What Are Tally Lights:
Tally lights are small indicator lights used in video production to indicate which camera is currently active or live. Typically mounted on top of the camera, they are visible to both the camera operator and the subjects being filmed. This feature helps the on-camera talent know which camera to focus on and informs the camera operators about the live feed status.

### What Does It Do:
The tally lights respond to the current state of your ATEM Switcher. When a camera is in preview mode, the tally light will be green, and when it's in program mode, it will be red. Note that unless you have a Blackmagic camera, tally lights are generally not usable with ATEM switchers.

### How Does It Work:
To use this system, connect [ATEMOSC](https://www.atemosc.com/) to your ATEM switcher and set the feedback OSC messages to a broadcast IP address with the last octet as `255`. This configuration allows the messages to be sent to any IP within that subnet. After flashing the FeatherV2, you will need to update the "SSID", "Password", and "CameraIDNum". The FeatherV2 then connects to your router and receives OSC messages, reacting based on its assigned camera number. The primary role of the FeatherV2 in this setup is

## Setup:
- Clone this repository to VSCode
  - Make sure Platformio extension is installed
- Install dependencies
- Modify `main.cpp` line 6,7,8
  - `SSID`, `PASSWORD`, `CameraNumber`
- Flash FeatherV2 with code
- Install [ATEMOSC](https://www.atemosc.com/)
- Connect the router to the same network as the ATEM Switcher and computer with ATEMOSC
- ATEMOSC
    - Set "Send Feedback Messages to:"
    - IP: `X.X.255.255`
       - This can change depending on your subnet
    - Port: `8888`
 
## Support The Project ❤️
### If this helped you, consider helping the project by making a one-time donation via **[PayPal](http://paypal.me/joeshea2)**

#
## Join the Discord Community

<a href="https://discord.gg/FJ79AKPgSk">
        <img src="https://img.shields.io/discord/308323056592486420?logo=discord"
            alt="chat on Discord"></a>

