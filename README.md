# Stereolabs ZED - UE5 Examples

This repository contains Unreal examples projects that demonstrate how to create advanced Interactive Applications using the ZED SDK and Unreal Engine 5.

**UE5_Examples** is a single project with a variety of small samples, each meant to highlight a single feature of the ZED UE5 plugin. 

## Getting started

This version of the plugin is compatible with Unreal Engine versions **5.0.3** and **UE 5.1**, and requires the [**ZED SDK 4.0**](https://www.stereolabs.com/docs/get-started-with-zed/#download-and-install-the-zed-sdk).
However, we strongly advise you to use UE 5.1 as we will put all our efforts into this version of Unreal Engine.

- For the UE4 plugin, see here : [UE4.21 Plugin](https://github.com/stereolabs/zed-unreal-plugin)
- To see our implementation of Live Link with the ZED, go here : [ZED Live Link Plugin](https://github.com/stereolabs/zed-LiveLink-plugin)

### Installation

- Download this repository..
- Right click on the *ZEDSamples.uproject*, select *switch Unreal Engine version* and choose our ue5 you previously installed in the list.
- Build the solution by pressing **Ctrl + F5**. Once the build is done, it will start the project in the UE5 Editor. 

You can now start the project with a double click on *ZEDSamples.uproject*.

### Documentation

A more detailed documentation is available on our website, see here :  https://www.stereolabs.com/docs/ue5/

## Interactive applications samples

### Body Tracking

https://user-images.githubusercontent.com/113181784/202238672-b87ec681-a574-454c-ba09-683201d1dcbb.mp4

Use 3D skeleton data to animate one or more avatars based on real time body tracking. Showcases the ZED Body Tracking feature, allowing you to track and "avatarize" people using a highly optimized AI model. 

### Camera Tracking

https://user-images.githubusercontent.com/113181784/202238297-cd069ece-1de4-4ca0-b811-387e182e7c5b.mp4

Use the ZED internal trackers to navigate a virtual scene by moving your ZED Camera. Explore the camera repositioning, translation multipliers and all features you can have from the Cine Camera Component.

### Point Cloud Depth View

https://user-images.githubusercontent.com/113181784/202454461-5ecb0b60-e518-4d50-aba1-7cef4699d124.mp4

Generate a realtime colored point cloud of the ZED camera view, using our ultra accurate neural depth detection mode, and Unreal Engine's next-generation VFX system, Niagara.

## XR & miscellaneous samples

### Object Placement

https://user-images.githubusercontent.com/113181784/202236331-080affd6-bc61-4e31-b9f6-c1539d49b747.mp4

Click on a flat, upwards-facing surface to spawn a box above it. Demonstrates how to use the ZED's Plane Detection feature to place objects without pre-scanning. See the level Blueprint and the GetFloorPlaneAtScreenPosition function to see how it works. Press F to visualize the floor plane.

### Spatial Mapping

https://user-images.githubusercontent.com/113181784/202236500-0c74579f-c084-44b0-b21e-de4f38e775ec.mp4

Map your environment into a 3D mesh, then shoot balls at real objects that realistically bounce off using Unreal's collision detection and physics. Optionally, save the mesh, mesh texture and .area spatial memory file for later. Use to pre-scan an environment for when you need persistent geometry, such as when collisions with the real-world need to occur even when you can't see them. See our [spatial mapping](https://docs.stereolabs.com/mixed-reality/unreal/spatial-mapping/) documentation to learn how it works. 

### Object Detection

https://user-images.githubusercontent.com/113181784/202236582-774baffc-a04c-4b2c-8d76-fea8b03040c7.mp4

Highlight objects detected by our [Object Detection API](https://www.stereolabs.com/docs/api/group__Object__group.html) with either a 2D frame or a 3D box.

### Background Subtraction

https://user-images.githubusercontent.com/113181784/202236725-aa998d9e-b9c6-4635-9286-54073b702a1d.mp4

Remove the background of a ZED videa stream by using either depth occlusion (put a virtual object closer to the camera than the real background, causing a view obstruction) or depth clamping (make the plugin not render any pixel further than a threshold distance).

### Dynamic Crosshair

https://user-images.githubusercontent.com/113181784/202236779-c97a72fd-bb92-486c-83bc-1d2ce660fe55.mp4

Puts a 3D crosshair as your cursor that moves itself closer or further to be just in front of the real-world object it overlaps. Explore to see how to use the GetDepthAtScreenPosition function, and experiment with the other GetDepth and GetNormal functions included in the plugin. 

### Hit Test

https://user-images.githubusercontent.com/113181784/202236855-7c14916e-bbb0-465f-bdbf-23363a6880d8.mp4

Left click to shoot virtual balls that will stop when they collide with a real-world object. Demonstrates that you don't need to pre-scan an environment for such interactions thanks to the ZED's real-time depth map. See the BP_HitTestBall blueprint and the HitTestReal function to learn how it works.

### Open New Level

https://user-images.githubusercontent.com/113181784/202236919-cef85929-5bb2-4c1e-85bf-232ee9dc50c8.mp4

Initiates the ZED, then properly closes it before opening a new level (in this case, itself). Follow this procedure (visible in the level Blueprint) any time you wish to change levels while the ZED is running. 

## Support

You will find guidance and assistance :
- In the [documentation of the plugin](https://www.stereolabs.com/docs/ue5/)
- On our [Community forums](https://community.stereolabs.com/)

## Bugs and fixes

You found a bug / a flaw in our plugin ? Please check that it is not [already reported](https://github.com/stereolabs/zed-UE5/issues), and open an issue if necessary. You can also reach out to us on the community forums for any question or feedback ! 

*By the way, we also have a special place in our hearts for PR senders.*
