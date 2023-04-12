# Stereolabs ZED - UE5 Examples

This repository contains Unreal examples projects that demonstrate how to create advanced Interactive Applications using the ZED SDK and Unreal Engine 5.

**UE5_Examples** is a single project with a variety of small samples, each meant to highlight a single feature of the ZED UE5 plugin. 

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

## Overview

| Body Tracking | Camera Tracking | Point Cloud 
| :-----------: |  :------------: | :--------: |
| [<video src="https://user-images.githubusercontent.com/113181784/202238672-b87ec681-a574-454c-ba09-683201d1dcbb.mp4" controls="controls" style="max-width: 100;"></video>](https://www.stereolabs.com/docs/ue5/body-tracking/) | [<video src="https://user-images.githubusercontent.com/113181784/202238297-cd069ece-1de4-4ca0-b811-387e182e7c5b.mp4"></video>](https://www.stereolabs.com/docs/ue5/camera-tracking/) | <video src="https://user-images.githubusercontent.com/113181784/202454461-5ecb0b60-e518-4d50-aba1-7cef4699d124.mp4"></video>
| Object Detection | Background substraction | Spatial mapping
| [<video src="https://user-images.githubusercontent.com/113181784/202236582-774baffc-a04c-4b2c-8d76-fea8b03040c7.mp4" ></video>](https://www.stereolabs.com/docs/ue5/object-detection/) | [<video src="https://user-images.githubusercontent.com/113181784/202236725-aa998d9e-b9c6-4635-9286-54073b702a1d.mp4"></video>](https://www.stereolabs.com/docs/ue5/background-subtraction/) | [<video src="https://user-images.githubusercontent.com/113181784/202236500-0c74579f-c084-44b0-b21e-de4f38e775ec.mp4"></video>](https://www.stereolabs.com/docs/ue5/spatial-mapping/)

## Samples

* [Body Tracking](https://www.stereolabs.com/docs/ue5/body-tracking/) - Use 3D skeleton data to animate one or more avatars based on real time body tracking. Showcases the ZED Body Tracking feature, allowing you to track and "avatarize" people using a highly optimized AI model. 

* [Camera Tracking](https://www.stereolabs.com/docs/ue5/camera-tracking/) - Use the ZED internal trackers to navigate a virtual scene by moving your ZED Camera. Explore the camera repositioning, translation multipliers and all features you can have from the Cine Camera Component.

* [Point Cloud](https://www.stereolabs.com/docs/ue5/) - Generate a realtime colored point cloud of the ZED camera view, using our ultra accurate neural depth detection mode, and Unreal Engine's next-generation VFX system, Niagara.

* [Object Detection](https://www.stereolabs.com/docs/ue5/object-detection/) - Highlight objects detected by our [Object Detection API](https://www.stereolabs.com/docs/api/group__Object__group.html) with either a 2D frame or a 3D box.

* [Background Subtraction](https://www.stereolabs.com/docs/ue5/background-subtraction/) - Remove the background of a ZED videa stream by using either depth occlusion (put a virtual object closer to the camera than the real background, causing a view obstruction) or depth clamping (make the plugin not render any pixel further than a threshold distance).

* [Spatial Mapping](https://www.stereolabs.com/docs/ue5/spatial-mapping/) - Map your environment into a 3D mesh, then shoot balls at real objects that realistically bounce off using Unreal's collision detection and physics. Optionally, save the mesh, mesh texture and .area spatial memory file for later. Use to pre-scan an environment for when you need persistent geometry, such as when collisions with the real-world need to occur even when you can't see them. See our [spatial mapping](https://docs.stereolabs.com/mixed-reality/unreal/spatial-mapping/) documentation to learn how it works. 


## Support

You will find guidance and assistance :
- In the [documentation of the plugin](https://www.stereolabs.com/docs/ue5/)
- On our [Community forums](https://community.stereolabs.com/)

## Bugs and fixes

You found a bug / a flaw in our plugin ? Please check that it is not [already reported](https://github.com/stereolabs/zed-UE5/issues), and open an issue if necessary. You can also reach out to us on the community forums for any question or feedback ! 

*By the way, we also have a special place in our hearts for PR senders.*
