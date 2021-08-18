# Mechanical Design
The mechanical design part of this project was by far the hardest part. Many of the parts designed has complex geometries that required 11 hour + 3D print jobs per part. Because of this, a lot of analysis was done between part iterations to reduce "downtime" where I could not further refine the design. Although only a few key design iterations will be shown in this document, many smaller iterations took place on each part to enusre that the process ran smoothly and efficiently. 

## Initial Designs
Because I was continuing work on another students' project, there were intial designs available for me to work off of. Right off the bat, I noticed two main areas of Levi's design that I wanted to improve upon and Professor Brown gave me one addition to make to the process as well. These three changes/additions became the backbone of my project and were:

- Overall Structure
- Feeding Mechanism
- Jaw Orientation.

## Design Refinements
### Overall Structure
At the start of the project I identified the structure as one of the main components that both wouldnt hold up to a manufacturing environment and could use some refinement to improve usability. Mainly, the old design was a little too flimsy (it was a prototype so this makes sense). To fix this issue, I came up with a new sheet metal pattern that I was able to cut out of aluminum using a waterjet and bend using a brake. It had relatively similar geometry to Levi's initial prototype, but the wrench would be placed on the inside, rather than the outside and the structure as a whole was bigger than the initial. Below is Levi's initial design, followed by my refinement.

<p float="left">
  <img src="../media/Rig.png" width=48% />
  <img src="../media/SideAngle.PNG" width=48% /> 
</p>

The new structure also has an important addition for usability. There is a middle panel that swings 90 degress from flat to vertical, allowing for easier wrench placement. The user can place the wrench in easily when it's in a horizontal mode and then the whole panel can be lifted up to interface with the jaw placement mechanism. Initially, this could be done using a stepper motor and lead screw, but ultimately it was decided that the user would be perfectly capable of doing this motion by hand so that was removed.

<p float="left">
  <img src="../media/SideAngle3.PNG" width=48% />

</p>

Embedded in this platform is the mechanism that rotates the wrench 60 degrees for each different jaw. This system is geared 2:1 so it has the required torque to rotate the wrench against gravity in its vertical position. 

### Feeding Mechanism
The jaw feeding mechanism was the second design refinement I chose to tackle. Levi's design used an electromagnet to pull jaws one by one through a 3D printed tube, and then cut off power to the electromagnet allowing the jaw to fall into place in the wrench. I ultimately discovered that the electromagnet was too unreliable to continue to be used. It ended up being a passive drive to get the jaws into position so that they could be attracted by the electromagnet as well. 

I tried using the electromagnet in an initial design and found that it wasn't strong enough to reliably pull jaws to the correct positon. I tried different electromagnets as well and even tried building my own to the specs I wanted, but none worked reliably. 

I decided that I wanted a driven mechanism for getting the jaws into position, and that I wanted to rely less on the electromagnet. My inital design for this iteration was a feeder wheel driven by a continuous servo on the top of the jaws that would use friction to push the jaws through, and a "droprod" on the botton that could be pulled back by a second regular servo. The drop rod part of this iteration worked really well, but the feeder wheel had many issues. As the jaws went under the wheel, one edge would tweak up, causing the chute to become jammed and not let any other jaws through. I made a few different iterations of this design with tighter tolerances to try and prevent this behavior, but it just didn't end up working right.

For the final major design iteration on the feeding mechanism I realized that the wrench jaws were almost the same size and shape as a pez. I used a pez dispenser as inspiration and created a magazine style feeding mechanism that used a rod driven by a servo to push evenly on the whole back side of the jaw. This prevented any of the tweaking motion that jammed up the previous design. It also reduced the number of servos required by one. 

<p float="left">
  <img src="../media/FeederAssemV1.PNG" width=30% />
  <img src="../media/FeederAssemV2.PNG" width=30% /> 
  <img src="../media/FeederAssemV3.PNG" width=30% /> 
</p>
Left to Right - Electromagnet Design, Feeder Wheel Design, Magazine Design

## Jaw Orientation
This objective was given to me by Professor Brown, with the goal of being able to dump jaws into a bowl descrambler and have them load directly into the jaw feeder in the correct orientation. A bowl descrambler vibrates enough to drive jaws up a ramp and they get knocked off at different points along the way if they arent in the correct orientation. For this part of the project, I spent a good deal of time getting familiar with the technology by placing cardboard and metal knockoff pieces using tape. 

Eventually I understood enough about what would knock the pieces off to 3D print a design to attempt it. After a few revisions of this part, I was able to get the pieces consitently coming out of the machine in the correct orientation, running along a rail.

The next step was to design a was for them to drop off the rail I had them running along into the vertical "pez dispenser" chute. This also took a few design iterations but eventually I ended up with this part, which interfaces at the end of the path on the bowl descrambler and at the top of the pez dispenser tube.

<p float="left">
  <img src="../media/RampSort.PNG" width=48% />
</p>

The angled wall knocks off all pieces that arent in a vertical orientation, and the sloped rail forces pieces that arent in the correct vertical orientation into a horizontal one, which causes them to get knocked off by the angled wall. The second longer wall with a slope at the end directs the pieces into the correct position to get picked up by the sloped rail. At the end, the box looking section is a funnel that funnels the pieces into a vertical magazine tube.

## Final Designs - Gravity is my Friend!

### Inner Jig
The final design idea is to have the jaws being fed laterally into the inner jig. Once in the inner jig, these jaws can then fall into the wrench if the outerjig holds the wrench in the correct spot. Below is the design for the inner jig, along with a feeding tube used to get the jaws into the jig<span>&#58;</span>

[![Feed_from_bottom](../media/Assembly_feeder&inner.png)](Current/3D_Prints/feeder_plus_inner.stl)

With this design, some key objectives in order to make it useful are to propel the jaws along the feeding tube into the inner jig, control how and when the jaws are dropped into the wrench and to keep the jaws in the correct orientation so that they can fall into place. A simple solution to solve all three of these objectives is to use an electromagnet placed at the head of the inner jig as well as a steel bar placed above the head of the inner jig that extends to the feeding tube. This bar will act as a magnet when the electromagnet is on and as such will keep the jaws oriented correctly. The recess for this steel bar can be seen in the image above. The placement of the electromagnet can be seen in the full assemnbly of the final design. 

### Rig
In order to have this design held at 90 degrees, a rig was designed. This rig was designed with two main objectives, it had to be able to support the weight of all the necessary components of the design and it had to allow for the movement necessary for the design. It can be seen below<span>&#58;</span>

[![Feed_from_bottom](../media/Rig.png)](Current/Laser_Cut_Pieces/Rig.stl)

This rig is made from 3mm thick acryllic sheets and was laser cut and assembled from 6 parts. The drawings of these cuts can be found in `.dxf` format in the `/Current/Laser_Cut_Pieces` directory. The rig has holes in the front piece, these holes are there to allow for the necessary components of the design to be screwed into the correct location.

### Gears

With the rig and inner jig in place, in order to rotate the outer jig holding the wrench around the inner jig - in order to place 6 jaws, it became clear that a gear system driven by a motor would be necessary. The gears were designed such that the driver gear could be controlled by a stepper motor and the driven gear can hold and rotate the outer jig. The gears were designed with a teetch ratio of 35/15. This was chosen to allow for easy rotation in minimal space, allowing the driver gear to be small but not require a very strong motor.

The driven gear was 3D printed so as to allow for it to be connected to the stepper motor using a sprocket with a set screw. This design is shown below, including the sprocket used<span>&#58;</span>

[![Feed_from_bottom](../media/gear_driver.png)](Current/3D_Prints/gear_driver.stl)

The driven gear was laser cut and designed with a hole in the middle of it, in the shape of the outer jig. The outer jig was then joined to the gear making it one part capable of rotating around the inner jig while holding onto the wrench. The driven gear with the outer jig holding a wrench can be seen below<span>&#58;</span>
[![Feed_from_bottom](../media/jig_gear.png)](Current/Laser_Cut_Pieces/jig_gear.stl)


### Clamps

Since the driven gear has to hold the wrench, this part, with the wrench in place, is heavy and could easily fall of the front of the rig. With this in mind, magnetic clamps were designed to hold the driven gear flush to the face of the rig while still allowing for full rotation of the gear. 

These are design to hold magnets on either side of the rig. This allows for the driven gear and the wrench to be easily removed for a new wrench to be placed into the system, yet it allows for the gear to rotate freely and mesh properly with the driver gear. The design is shown below, the cylindrical holes are dimensioned to hold magnets firmly in place.<span>&#58;</span>
[![Feed_from_bottom](../media/clamp.png)](Current/3D_Prints/clamp.stl) 

### Actuators

In order to actuate the design as described, the electromagnet and stepper motor being used will need to be held in place.

The motor was held in place, with its shaft, at the necessary distance using a spacer screwed into both the front of the rig as well as the actual motor. This [spacer](Current/3D_Prints/motor_spacer.stl) was 3D printed.  

Further, the electromagnet needs to be held at the head of the inner jig. This holder was made of two 3D printed parts, [elecmag_holder1](Current/3D_Prints/elecmag_holder1.stl) and [elecmag_holder2](Current/3D_Prints/elecmag_holder2.stl). This was designed to be ble to hold the heavy electromagnet in place while allowing for the full rotation of the wrench. 



