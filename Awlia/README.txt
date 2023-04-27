# OpenGLGrapes
This project is based on Qt5.12 and OpenGL.

---------------Download Qt and Qt Creator-------------------
It is recommanded to run the Qt program in the Qt IDE --  Qt Creator(4.3) above.

Qt Creator Linux: https://www.qt.io/download-qt-installer
Installation tutorial： https://web.stanford.edu/dept/cs_edu/resources/qt/install-linux

Qt Creator Windows: https://download.qt.io/



---------------Open the project----------------------------------------------------------
Click 'Open project' in Qt Creator
Choose the unzip folder and choose the Qt project file, in this project it is 'Opengl.pro'



--------------Introduction to the interface----------------------------------------------------------------------
The program will use a OpenGLWidget to render the model.
A message box to inform the user with the running state of the program.
The user can modify the Grape using the input widgets on the right of the window.
after modify the parameters, users can click 'Generate' botton under the input widget to generate a modified model



--------------Parameters---------------------------------------------------------
Trunk length:         modify the stem's length.
Trunklength ratio:    a ratio used to shrink the length of the stem, less than 1.
Trunk radius:         modify the radius of the stem
TrunkRadius ratio:    a ratio used to shrink the radius of the stem, less than 1.
Berry radius:         change the radius of the grapes, recommand to set above 2.7
Bezier n:             resolution of the stem
dx,dy,dz:             Angle of stem branch out relative to x,y,z-axis.
Cylinder Step:        resolution of the stem
lats and longs:       resolution of the berry
berry color:       two options, one is table grape, another is wine grape

setting for table grape:
Trunk length=5.5
Trunk radius=0.3
berry radius=2
berry color= table grape

setting for wine grape:
Trunk length=4
Trunk radius=0.2
berry radius=1.3
berry color=wine grape


--------------Save the output----------------------------------------------------------------------------------
On the 'Output' tab, user can save the pgm files of the model. (open l_system.cpp and change the parameter " dirName " in line 208 to the address where you want to save files.)

