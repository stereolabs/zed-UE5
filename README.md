<h1 align="center">
ZED UE5 Plugin
  <br>
</h1>

<p align="center">

This repository contains Unreal examples projects that demonstrate how to create advanced Interactive Applications using the ZED SDK and Unreal Engine 5.
**ZEDSamples** is a single project with a variety of small samples, each meant to highlight a single feature of the ZED UE5 plugin. 

</p>

---

## Overview

<div align="center">

| [**Body Tracking**](https://www.stereolabs.com/docs/ue5/body-tracking/) | [**Camera Tracking**](https://www.stereolabs.com/docs/ue5/camera-tracking/) | [**Point Cloud**](https://www.stereolabs.com/docs/ue5/) 
| :-----------: |  :------------: | :--------: |
| ![ue5_bodytracking](https://user-images.githubusercontent.com/60651082/232523450-d3b07499-db8f-40fa-ae97-270ba6e957ad.gif) | ![ue5_cameratracking](https://user-images.githubusercontent.com/60651082/232523068-2bef7427-76cf-419a-9b96-ac8eae213ffc.gif) | ![ue5_pointcloud](https://user-images.githubusercontent.com/60651082/232523878-8aa30875-2d75-4969-857f-987adbc6e119.gif)
| [**Object Detection**](https://www.stereolabs.com/docs/ue5/object-detection/) | [**Background substraction**](https://www.stereolabs.com/docs/ue5/background-subtraction/) | [**Spatial mapping**](https://www.stereolabs.com/docs/ue5/spatial-mapping/)
| ![ue5_od](https://user-images.githubusercontent.com/60651082/232524343-e6e368f2-43ab-44e1-ac10-68e174c9b6dc.gif) | ![ue5_backgroundsub](https://user-images.githubusercontent.com/60651082/232524642-e9e327eb-ccc6-4ee2-b953-574347920188.gif) | ![ue5_spatialmapping](https://user-images.githubusercontent.com/60651082/232524962-e403b50e-622f-4448-b8d2-534a3f9a3183.gif)
| [**Object Placement**](https://www.stereolabs.com/docs/ue5/) | [**Dynamic Crosshair**](https://www.stereolabs.com/docs/ue5/) | [**Hit Test**](https://www.stereolabs.com/docs/ue5/)
| ![ue5_objectplacement](https://user-images.githubusercontent.com/60651082/232526333-76a5ccca-fa04-4f26-a8c6-d011fd25c2f7.gif) | ![ue5_crosshair](https://user-images.githubusercontent.com/60651082/232526872-1317ac5b-f19f-48d8-a538-267db3e91231.gif) | ![ue5_hittest](https://user-images.githubusercontent.com/60651082/232527439-52b3af85-34ae-4ce6-8c2f-a9c1ab6de44b.gif)

</div>

## Getting started

This version of the plugin is compatible with Unreal Engine **5.1**, and requires the [**ZED SDK 4.0**](https://www.stereolabs.com/docs/get-started-with-zed/#download-and-install-the-zed-sdk) and a **Windows setup**, because for now we are only compatible with the DirectX API.

- To see our implementation of Live Link with the ZED, go here : [ZED Live Link Plugin](https://github.com/stereolabs/zed-LiveLink-plugin)

### Installation

- Download this repository..
- Right click on the *ZEDSamples.uproject*, select *switch Unreal Engine version* and choose our ue5 you previously installed in the list.
- Build the solution by pressing **Ctrl + F5**. Once the build is done, it will start the project in the UE5 Editor. 

You can now start the project with a double click on *ZEDSamples.uproject*.

### Documentation

A more detailed documentation is available on our website, see here :  https://www.stereolabs.com/docs/ue5/

## Samples

* [Body Tracking](https://www.stereolabs.com/docs/ue5/body-tracking/) - Use 3D skeleton data to animate one or more avatars based on real time body tracking. Showcases the ZED Body Tracking feature, allowing you to track and "avatarize" people using a highly optimized AI model. 

* [Camera Tracking](https://www.stereolabs.com/docs/ue5/camera-tracking/) - Use the ZED internal trackers to navigate a virtual scene by moving your ZED Camera. Explore the camera repositioning, translation multipliers and all features you can have from the Cine Camera Component.

* [Point Cloud](https://www.stereolabs.com/docs/ue5/) - Generate a realtime colored point cloud of the ZED camera view, using our ultra accurate neural depth detection mode, and Unreal Engine's next-generation VFX system, Niagara.

* [Object Detection](https://www.stereolabs.com/docs/ue5/object-detection/) - Highlight objects detected by our [Object Detection API](https://www.stereolabs.com/docs/api/group__Object__group.html) with either a 2D frame or a 3D box.

* [Background Subtraction](https://www.stereolabs.com/docs/ue5/background-subtraction/) - Remove the background of a ZED videa stream by using either depth occlusion (put a virtual object closer to the camera than the real background, causing a view obstruction) or depth clamping (make the plugin not render any pixel further than a threshold distance).

* [Spatial Mapping](https://www.stereolabs.com/docs/ue5/spatial-mapping/) - Map your environment into a 3D mesh, then shoot balls at real objects that realistically bounce off using Unreal's collision detection and physics. Optionally, save the mesh, mesh texture and .area spatial memory file for later. Use to pre-scan an environment for when you need persistent geometry, such as when collisions with the real-world need to occur even when you can't see them. See our [spatial mapping](https://docs.stereolabs.com/mixed-reality/unreal/spatial-mapping/) documentation to learn how it works. 

* [Object Placement](https://www.stereolabs.com/docs/ue5/) - Click on a flat, upwards-facing surface to spawn a box above it. Demonstrates how to use the ZED's Plane Detection feature to place objects without pre-scanning. See the level Blueprint and the GetFloorPlaneAtScreenPosition function to see how it works. Press F to visualize the floor plane.

* [Dynamic Crosshair](https://www.stereolabs.com/docs/ue5/) - Puts a 3D crosshair as your cursor that moves itself closer or further to be just in front of the real-world object it overlaps. Explore to see how to use the GetDepthAtScreenPosition function, and experiment with the other GetDepth and GetNormal functions included in the plugin. 

* [Hit Test](https://www.stereolabs.com/docs/ue5/) - Left click to shoot virtual balls that will stop when they collide with a real-world object. Demonstrates that you don't need to pre-scan an environment for such interactions thanks to the ZED's real-time depth map. See the BP_HitTestBall blueprint and the HitTestReal function to learn how it works.

## Support

You will find guidance and assistance :
- In the [documentation of the plugin](https://www.stereolabs.com/docs/ue5/)
- On our [Community forums](https://community.stereolabs.com/)

## Bugs and fixes

You found a bug / a flaw in our plugin ? Please check that it is not [already reported](https://github.com/stereolabs/zed-UE5/issues), and open an issue if necessary. You can also reach out to us on the community forums for any question or feedback ! 

*By the way, we also have a special place in our hearts for PR senders.*
