# Stereolabs ZED - UE5 Examples

This repository contains Unreal examples projects that demonstrate how to create advanced Mixed Reality application using the ZED SDK and Unreal.

**UE5_Examples** is a single project with a variety of small samples, each meant to highlight a single feature of the ZED UE5 plugin. 

## Installation

First you need to have our custom engine installed and ready to use. If you don't, see our [installation guide](https://docs.stereolabs.com/mixed-reality/unreal/getting-started/)).

Then follow these steps:
- Download this repository.
- Go to your new root project folder. Create a new folder called **Plugins**.
- Drop the Stereolabs folder within the plugin download into this folder. If you haven’t downloaded the plugin yet, you can get it [here](https://github.com/stereolabs/zed-unreal-plugin).
- Right click on the *ZEDSamples.uproject*, select *switch Unreal Engine version* and choose our ue5 you previously installed in the list.
- Build the solution by pressing **Ctrl + F5**. Once the build is done, it will start the project in the UE5 Editor. 

You can now start the project with a double click on *ZEDSamples.uproject*.

## Inside the Editor

You can find several maps in the Content folder. Each map show you how to use the plugin for a specific use case. Don't hesitate to try them all!

## UE5_Examples

All samples are in the **UE5_Examples** project as a level, found in **Content** -> **Levels**. 


### Passthrough

[![](https://thumbs.gfycat.com/SecondOrangeGlassfrog-size_restricted.gif)](https://gfycat.com/SecondOrangeGlassfrog)

See the real world through an Oculus Rift or HTC Vive, with virtual objects mixed in. Must have a compatible headset plugged in and running when the project is loaded. 

### Dynamic Crosshair

[![](https://thumbs.gfycat.com/PreciousElegantKiskadee-size_restricted.gif)](https://gfycat.com/PreciousElegantKiskadee)

Puts a 3D crosshair in the center of the screen that moves itself closer or further to be just in front of the real-world object it overlaps. Explore to see how to use the GetDepthAtScreenPosition function, and experiment with the other GetDepth and GetNormal functions included in the plugin. 

### HitTest

[![](https://thumbs.gfycat.com/VerifiableAcrobaticDungbeetle-size_restricted.gif)](https://gfycat.com/VerifiableAcrobaticDungbeetle)

Left click to shoot virtual balls that will stop when they collide with a real-world object. Demonstrates that you don't need to pre-scan an environment for such interactions thanks to the ZED's real-time depth map. See the BP_HitTestBall blueprint and the HitTestReal function to learn how it works. 

### Object Placement

[![](https://thumbs.gfycat.com/ColorfulBareFlatfish-size_restricted.gif)](https://gfycat.com/ColorfulBareFlatfish)

Click on a flat, upwards-facing surface to spawn a cyborg standing on top of it. Demonstrates how to use the ZED's Plane Detection feature to place objects without pre-scanning. See the level Blueprint and the GetFloorPlaneAtScreenPosition function to see how it works.

### Spatial Mapping

[![](https://thumbs.gfycat.com/PersonalThankfulGrizzlybear-size_restricted.gif)](https://gfycat.com/PersonalThankfulGrizzlybear)

Map your environment into a 3D mesh, then shoot balls at real objects that realistically bounce off using Unreal's collision detection and physics. Optionally, save the mesh, mesh texture and .area spatial memory file for later. Use to pre-scan an environment for when you need persistent geometry, such as when collisions with the real-world need to occur even when you can't see them. See our [spatial mapping](https://docs.stereolabs.com/mixed-reality/unreal/spatial-mapping/) documentation to learn how it works. 


### Open New Level

[![](https://thumbs.gfycat.com/CaringJoyousHerring-size_restricted.gif)](https://gfycat.com/CaringJoyousHerring)

Initiates the ZED, then properly closes it before opening a new level (in this case, itself). Follow this procedure (visible in the level Blueprint) any time you wish to change levels while the ZED is running. 

## Support
If you need assistance go to our Community site at https://community.stereolabs.com/
