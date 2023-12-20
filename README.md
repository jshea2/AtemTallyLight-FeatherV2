## Tally Light for ATEM Switchers

Requirements:
- [FeatherV2]([url](https://www.adafruit.com/product/5400))
- Wirless Router
- Camera to have USB port for power (or any USB power
- ATEM Switcher
- Computer with [ATEMOSC]([url](https://www.atemosc.com/)https://www.atemosc.com/)
- [3D Printed Case]([url](https://www.thingiverse.com/thing:6387713)https://www.thingiverse.com/thing:6387713)

### What Are Tally Lights:
Tally lights are small indicator lights used in video production to show which camera is currently active or live. They are typically mounted on top of the camera, visible to both the camera operator and the subjects being filmed. This helps the on-camera talent know which camera to look at and informs the camera operators which camera is being used for the live feed.

### What Does It Do:
Tally lights will react to your ATEM Switcher current state. When a camera is in preview the Tally will be green or if in program it will be red. Unless you have a BM camera you can't really use tally lights with ATEM switchers

### How Does it Work:
When you connect [ATEMOSC]([url](https://www.atemosc.com/)https://www.atemosc.com/) to your ATEM switcher and set the feedback OSC messages to a broadcast IP. This broadcast IP will have the last octet be `255` which allows it to be sent to any IP in that octet. Once you flash the FeatherV2 you will update the "SSID", "Password", and "CameraIDNum". The FeatherV2 will connect to your router and recieve OSC messages and react based on it's Camera number. The main use for the FeatherV2 is to utilize its on board LED to recieve messages and change colors.
