# Level_US_GRO400_H21
This is an opensource project made by a team of undergratuate students from Sherbrooke University. This project is basically a self-leveling platform controled with an embedded system. Our purpose is to create a platform that will automatically balance itself according to the acceleration applied. For example, this project could be applied on boat's tables that could have to follow big waves movements. The table could then automatically balance so nothing would be spilled. We are also working on a manual mode that could allow full user control. This feature is still in progress.

## READMEs
We chose to create a README for every major section. This way, information is separated and easier to find. You can always click the next few links to get directly there :
  - [Code README](Code/README.md)
  - [Electronics README](Electronics/README.md)
  - [Mechanics README](Mechanics/README.md)

## Final prototype
<img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/Platform_top.jpg" width="320" height="240"> <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/platform_bottom.jpg" width="320" height="240">

## How to install the Python virtual environment (on Windows)

1. If not already installed, install Python 3 from the [Python website](https://www.python.org/downloads/).
2. Add the root directory of your Python installation (i.g. Python38) and the sub-directory *Scripts* to your system's environment variables [Settings > System > About > System info > Advanced system settings > Environment variables > Path (under user variables)].
3. Open a command prompt and navigate to the project folder. *You can run `python --version` and `pip --version` to make sure Python and pip are installed correctly*.
4. When in the project's directory you can create a new virtual environment using `python -m venv name_venv`.
5. Like for your system installation of Python, add your venv folder and it's *Scripts* sub-directory to your system's environment variables (like step 2).
6. To be able to use your different Python installation, you can create a .bat file with a different name i.g. python_myproject.bat.
7. Open this .bat file using a text editor and write `%~dp0python %*`.
8. In your command prompt you can now use python_myproject to refer to this specific installation.
9. To activate the venv, while in the project directory run `my_venv\Scripts\activate`.
10. Install the required module by running `pip install -r /path/to/requirements_win.txt`. *The requirements_win.txt file should be downloaded with the repository in the main project folder*.

## How to install the Python environment (on Linux)

1. If not already installed, download and install the latest Python 3 version from the [Python website](https://www.python.org/downloads/source/) following [this guide](https://www.dummies.com/programming/python/how-to-install-python-on-a-linux-system/).
2. Install pip using `sudo apt install python3-pip`
3. Install venv using `sudo appt install python3-venv`
4. Open a command prompt and navigate to the project folder. *You can run `python3 --version` and `pip --version` to make sure Python and pip are installed correctly on Linux python*.
6. When in the project's directory you can create a new virtual environment using `python3 -m venv name_venv`.
7. Go to the newly environment folder using `cd name_venv\bin` and run `source activate` to activate the venv.
8. Run `pip install -r /path/to/requirements_linux.txt` to install the required modules. *The requirements_linux.txt file should be downloaded with the repository in the main project folder*.

### Add the venv to .gitignore

We do not want the venv to be pushed to Github in case of a push.

1. Open a git bash and navigate to your project directory linked with Github.
2. Run `echo 'my_venv' >> .gitignore` to add the venv to .gitignore. 

This way, the next you commit a change, the files in .gitignore will not be commited.

## CFFI library build

The CFFI module needs to be rebuilt for every computer so you will have to update the values of your dynamic model and rebuild the library.
1. In [anglePlaqueToAngleMoteur.c](https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Code/Python/modules/anglePlaqueToAngleMoteur_c/anglePlaqueToAngleMoteur.c), from line 770 you will have the different dimensions to modify for your model, the length of the first arm is longueurBras1.contents on line 774, length of arm 2 is longueurBras2.contents on line 777 and the radius from the center of the platform to the second arm is rayonDistanceAncrageEtPivot.contents on line 780. All these values are in milimeters.
2. Once the values are updated you will need to install Microsoft [Visual C++ 14.0](https://visualstudio.microsoft.com/visual-cpp-build-tools/) or higher to rebuild the library.
3. Once it is installed, you can run `python_myproject angleLibBuild.py`in your command line to rebuild the library.
4. The program should now be able to run.

## Contact us

To contafct us leave a message below and one of us will try to get back to you.
