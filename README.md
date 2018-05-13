# Pluto
Pluto is just a project to learn low-level programming.
Feel free to contribute :)

## Installation / boot guide
_Requires a bootable flash drive_

 - Run makefile: ```make pluto.iso```, compilation may take some time
 - After the process is finished _pluto.iso_ file will be present is the same folder
 - Let DD restore a hdd from the image created in the first step: ```dd if=pluto.iso of=/dev/sdX && sync```
   - _Note: replace **X** with name of your flash disk drive_  
   - _This name can be easily obtained from the Disks app -> device location_
 - Restart the computer
 - While booting press F8/F9/F12/ESC/DEL and from the boot section select the plugged flash disk as a first option
 - Save the changes and restart
 - Pluto should now boot automatically
 
 ## Splash bug?
 Feel free to open an issue due to Pluto being in dev right now bugs may appear. Our team will resolve the issue asap, keep in mind there are no stable versions so far.
 
 ## License
 GPL 3.0 standard license. In detail [here](https://github.com/Langriklol/pluto/blob/master/LICENSE).
