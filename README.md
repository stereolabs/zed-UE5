# Stereolabs ZED - UE5 Examples

This repository contains Unreal examples projects that demonstrate how to create advanced Interactive Applications using the ZED SDK and Unreal Engine 5.

**UE5_Examples** is a single project with a variety of small samples, each meant to highlight a single feature of the ZED UE5 plugin. 

## Getting started

This version of the plugin is ***NOT*** compatible with UE 5.1, and was made using and for UE 5.0.3.
- For the UE4 plugin, see here : [UE4.21 Plugin](https://github.com/stereolabs/zed-unreal-plugin)
- To see our implementation of Live Link with the ZED, go here : [ZED Live Link Plugin](https://github.com/stereolabs/zed-LiveLink-plugin)

**UE5_Examples** is a single project with a variety of small samples, each meant to highlight a single feature of the ZED UE5 plugin. 

### Installation

- Download this repository..
- Right click on the *ZEDSamples.uproject*, select *switch Unreal Engine version* and choose our ue5 you previously installed in the list.
- Build the solution by pressing **Ctrl + F5**. Once the build is done, it will start the project in the UE5 Editor. 

You can now start the project with a double click on *ZEDSamples.uproject*.

## Features

All samples are in the **UE5_Examples** project as a level, found in **Content** -> **ZED** -> **Levels**. 

### Object Placement

https://user-images.githubusercontent.com/113181784/202185807-4532eaec-f7cc-4ae3-b345-9353eb492938.mp4

Click on a flat, upwards-facing surface to spawn a box above it. Demonstrates how to use the ZED's Plane Detection feature to place objects without pre-scanning. See the level Blueprint and the GetFloorPlaneAtScreenPosition function to see how it works. Press F to visualize the floor plane.

### Spatial Mapping

https://user-images.githubusercontent.com/113181784/202185840-d2083f31-bb6d-4075-96aa-83848dbd7bb4.mp4

Map your environment into a 3D mesh, then shoot balls at real objects that realistically bounce off using Unreal's collision detection and physics. Optionally, save the mesh, mesh texture and .area spatial memory file for later. Use to pre-scan an environment for when you need persistent geometry, such as when collisions with the real-world need to occur even when you can't see them. See our [spatial mapping](https://docs.stereolabs.com/mixed-reality/unreal/spatial-mapping/) documentation to learn how it works. 

### Object Detection

https://user-images.githubusercontent.com/113181784/202185925-a212b91d-34a8-4b19-a127-f44ec6fd4f64.mp4

Highlight objects detected by our [Object Detection API](https://www.stereolabs.com/docs/api/group__Object__group.html) with either a 2D frame or a 3D box.

### Background Subtraction

https://user-images.githubusercontent.com/113181784/202185962-69cfb852-da21-4a57-bd40-6b3675b20e13.mp4

Remove the background of a ZED videa stream by using either depth occlusion (put a virtual object closer to the camera than the real background, causing a view obstruction) or depth clamping (make the plugin not render any pixel further than a threshold distance).

### Dynamic Crosshair

https://user-images.githubusercontent.com/113181784/202185991-8658dbc0-441b-4c5f-86af-595ec48e97f1.mp4

Puts a 3D crosshair as your cursor that moves itself closer or further to be just in front of the real-world object it overlaps. Explore to see how to use the GetDepthAtScreenPosition function, and experiment with the other GetDepth and GetNormal functions included in the plugin. 

### Hit Test

https://user-images.githubusercontent.com/113181784/202186093-f85b0c5e-8580-4a10-a3c2-43ef2ab79918.mp4

Left click to shoot virtual balls that will stop when they collide with a real-world object. Demonstrates that you don't need to pre-scan an environment for such interactions thanks to the ZED's real-time depth map. See the BP_HitTestBall blueprint and the HitTestReal function to learn how it works.

### Open New Level

https://user-images.githubusercontent.com/113181784/202186131-c54335f5-11b5-480b-8fec-1a1da891bf58.mp4

Initiates the ZED, then properly closes it before opening a new level (in this case, itself). Follow this procedure (visible in the level Blueprint) any time you wish to change levels while the ZED is running. 

## Support

You will find guidance and assistance :
- In the [documentation of the plugin](https://www.stereolabs.com/docs/ue5/)
- On our [Community forums](https://community.stereolabs.com/)

## Bugs and fixes

You found a bug / a flaw in our plugin ? Please check that it is not [already reported](https://github.com/stereolabs/zed-UE5/issues), and open an issue if necessary. You can also reach out to us on the community forums for any question or feedback ! 

*By the way, we also have a special place in our hearts for PR senders.*
