# Pluto
Pluto is just a project to learn low-level programming.
Feel free to contribute :)

# How to install/boot it?
Well, run makefile ("make pluto.iso") and let it compile. After that, you will see pluto.iso file in the folder. Open terminal and type: "dd if=pluto.iso of=/dev/sdX && sync" where X is your flash drive. For example, it's /dev/sdb, so you type /dev/sdb instead of /dev/sdX. If you don't know what is your flash drive location, open Disks app and you will see your flash drive here. Click on it, and you will see device location.
After the command finishes, unplug flash drive, plug it into computer you want to boot Pluto on, (unless you want to try it on computer you're currently reading this on.) restart/start your computer, and press F8, F9, F12, ESC or DEL button. Go to Boot section and select that removable devices boot first. Save changes and restart computer (Press F10 or in Exit section, hit "Save changes & Exit"). Pluto will automatically start.

# It cannot boot! What I have to do?
Actually, Pluto is currently in develoing stage, so it has a lot of bugs. Just wait until new version appears here :)

# What can I do with source code?
Pluto is using GPPL 3.0 License, so read LICENSE file.
