Droplets: A Swarm Robotics Platform
==========

[Click here to get started!](https://github.com/correlllab/cu-droplet/blob/master/getting_started.md)

The platform has been produced by the Correll Robotics Lab at the University of Colorado Boulder. It is envisioned to be a scalable robotics experimentation environment.

<img src="http://correll.cs.colorado.edu/wp-content/uploads/IMG_1087_smaller_cropped.jpg" alt="Two Droplets with U.S. quarter for scale. One is tilted to face the camera and has its shell removed.">

The hardware is comprised of actual robots, and the test bed/floor that experiments are run on. The robots are capable of sensing IR and RGB intensities, actuation using vibration motors, and IR communication. The embedded software layer is what we use to write and compile on-board code for the droplets. Each robot is equipped with an Atmel xmega-128a3u microprocessor capable of running embedded-c.

A simulator has also been developed for this platform. This code has its own repo on <a href="https://github.com/correlllab/cu-droplet-sim">github</a>.

This work is available under a <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/" >Creative Commons Attribution-NonCommercial-ShareAlike License. <img src="http://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png" alt="CC License"></a>


Conducting Research to develop firmware to flash program Droplets wirelessly using Infrared communication. The Droplets are an experimental open-source platform for large-scale swarm research based on ATXmega 128U platform.


Background: 
• The current implementation has a swarm of one hundred Droplets. It is a tedious task to reprogram each and every droplet. To minimize the effort, I am developing firmware to self-program the droplets.

• The entire code is divided into User code and OS code (supports the various functionalities on Droplets) 

• A Master droplet broadcasts the User code wirelessly to the residing Slave droplets and they are programmed directly onto the flash using Self programming: an exclusive feature of ATXmega family.


Working at Correll lab has helped me gaining an in-depth vision on firmware/software development

