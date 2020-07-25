# Low cost Passive (camera) and Active (LIDAR) Vision for Obstacle Depth

Example of disparity map created by stereo correspondence through two images and a point cloud map created by LIDAR data values (distances measures).

 ## Citation:
 ```
@article{chirella:2020,
  author = {Vito F. Chiarella, Thiago Rateke, Karla A. Justen, Antonio C Sobieranski, Sylvio L Mantelli, Eros Comunello, Aldo von Wangenheim},
  title = {Comparison between low-cost passive and active vision for obstacle depth},
  journal = {Revista de Ciência e Tecnologia (RCT)},
   volume = {6},
  year = {2020},
}
```

 - [Original Paper](https://www.researchgate.net/publication/342666208_Comparison_between_low-cost_passive_and_active_vision_for_obstacle_depth)
 - [Step-by-step](https://medium.com/analytics-vidhya/visual-depth-estimation-by-two-different-sensors-36f756d1575a?source=friends_link&sk=c3869820f7fffda3053a6e5993f5f6eb)

## Sensors used
- Two HP Webcam HD-4110
- One LIDAR Lite V2
- Two Micro Servo SG90 (to makes LIDAR rotations)

![Sensores](https://i.imgur.com/eUn2wfL.jpg)

## Comparisson
(a) Original Image, (b) Stereo Disparity Map (camera), (c) Point Cloud Map (LIDAR)
![Results](https://i.imgur.com/5MeLh4X.jpg)

Must have OpenCV 3.1 or later installed with extra modules.
Also Arduino IDE (https://www.arduino.cc/en/Guide/HomePage).
And Processing (https://processing.org/) as well.

## Stereo Disparity Map (from camera)
- To compile: g++ filteredDisparityMap.cpp -lopencv_core -lopencv_videoio -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_calib3d -lopencv_features2d -lopencv_ximgproc -o veRun

## Point Cloud Map (from LIDAR)
- Control the servos with: lidarControl.ino
- Build the Point Cloud with: lidarPointCloud.pde
